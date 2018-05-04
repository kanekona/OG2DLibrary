//_____________________________
//|メインシステム               
//|履歴：2018/03/20       
//|履歴：2018/03/23
//|履歴：2018/04/26
//|____________________________
//数値演算定数
#define _USE_MATH_DEFINES
//小数点誤差修正
#define _OX_EPSILON_ 0.0000001f
#include "OGSystem\OGTask.h"
//メモリリーク検知
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
//------------------
//class定義
//------------------
_OGTK OGTK;
//------------------
//タスクシステム
//------------------
void TaskSystem()
{
	OGge->TaskGameUpDate();
	//更新処理
	//OGTK._myGameUpdate();
}
void TaskRender()
{
	//描画処理
	//OGTK._myGameRender2D();
	//OGTK._myGameRender3D();
}
void TaskFinalize()
{
	OGge->SetDeleteEngine(true);
	//解放処理
	//OGTK._myGameFinalize();
}
//------------------
//初期化
//------------------
void Initialize() 
{
	random::Init();
	OGTK.StartTaskObject();
}
//------------------
//解放
//------------------
void Finalize()
{
	
}
//------------------
//更新
//------------------
bool Update() {
	if (OGge->in.key.down(In::ESCAPE) || OGge->GetEnd())
	{
		TaskFinalize();
		//ウィンドウの破棄
		glfwDestroyWindow(OGge->window->window);
		return true;
	}
	return false;
}
//------------------
//メイン
//------------------
int main() {
	//メモリリーク検知
#if(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	//FWの初期化
	if (!glfwInit()) {
		return -1;
	}
	//ゲームエンジンの生成
	OGge = new EngineSystem();
	//タスクの初期化処理
	OGTK._myGameInitialize();
	//ゲームエンジンの初期化
	OGge->Initialize();
	//使用OpenGLのVersion指定
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	//使用するウィンドウを設定する
	glfwMakeContextCurrent(OGge->window->window);
	//同期(ダブルバッファの入れ替えタイミングの指定)
	glfwSwapInterval(1);
#if defined(_MSC_VER)
	//GLEW初期化
	if (glewInit() != GLEW_OK) {
		//ウィンドウとカーソルをすべて破棄しリソースを解放します。
		glfwTerminate();
		return -1;
	}
#endif
	// 透視変換行列を設定
	glMatrixMode(GL_PROJECTION);
	//描画範囲の指定
	glViewport(0, 0, OGge->window->_widht, OGge->window->_height);
	//行列の初期化
	glLoadIdentity();
	// 操作対象の行列をモデリングビュー行列に切り替えておく
	glMatrixMode(GL_MODELVIEW);
	//行列の初期化
	glLoadIdentity();
	//ウインドウの座標の巻線に基づいてポリゴンをカリングする
	glEnable(GL_CULL_FACE);
	//深さの比較を行い、深度バッファを更新する(3D用)
	//glEnable(GL_DEPTH_TEST);
	//法線ベクトルの設定、正規化
	glEnable(GL_NORMALIZE);
	//背景color
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//初期化処理
	Initialize();
	//ウィンドウの生成位置の指定
	//ウィンドウが存在する場合ループ
	while (!glfwWindowShouldClose(OGge->window->window)) {
		//エンジン内の更新処理
		OGge->Update();
		//捜査対象の行列をモデルビュー行列に変更
		glMatrixMode(GL_MODELVIEW);
		//バッファをクリアして値を設定する
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//有効になっている場合、計算されたフラグメントカラー値をカラーバッファの値とブレンドします。
		glEnable(GL_BLEND);
		//ピクセル演算を指定する
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		//更新処理
		if (Update()) { break; }
		TaskSystem();
		//描画処理
		TaskRender();
		//指定したウィンドウのダブルバッファを行う
		glfwSwapBuffers(OGge->window->window);
		//ウィンドウ、マウス、キーボードの入力の状態をアップデートする
		glfwPollEvents();
	}
	//解放
	Finalize();
	//ゲームエンジンの内容を解放
	delete OGge;
	//GLFWのライブラリを終了する
	glfwTerminate();
}