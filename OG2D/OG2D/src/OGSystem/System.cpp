#include "System.h"
OGSystem::OGSystem()
{
	OGge = new EngineSystem();
	rm = new ResourceManager();
}

OGSystem::~OGSystem()
{
	//ゲームエンジンの内容を解放
	delete OGge;
	delete rm;
	//GLFWのライブラリを終了する
	glfwTerminate();
}

bool OGSystem::Create()
{
	//FWの初期化
	if (!glfwInit()) {
		return false;
	}
	//ゲームエンジンの初期化
	OGge->Initialize();
	//使用OpenGLのVersion指定
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	//使用するウィンドウを設定する
	glfwMakeContextCurrent(OGge->window->GetWindow());
	//同期(ダブルバッファの入れ替えタイミングの指定)
	glfwSwapInterval(1);
#if defined(_MSC_VER)
	//GLEW初期化
	if (glewInit() != GLEW_OK) {
		//ウィンドウとカーソルをすべて破棄しリソースを解放します。
		glfwTerminate();
		return false;
	}
#endif
	// 透視変換行列を設定
	glMatrixMode(GL_PROJECTION);
	//描画範囲の指定
	glViewport(0, 0, (GLsizei)OGge->window->GetSize().x, (GLsizei)OGge->window->GetSize().y);
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
	random::Init();
	return true;
}

bool OGSystem::LibConfirmation()
{
	//ダブルバッファ
	glfwSwapBuffers(OGge->window->GetWindow());
	//ウィンドウ、マウス、キーボードの入力の状態をアップデートする
	glfwPollEvents();
	//GameEngineの更新処理
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
	if (OGge->in->key.down(In::ESCAPE) || OGge->GetEnd())
	{
		OGge->SetDeleteEngine(true);
		//ウィンドウの破棄
		glfwDestroyWindow(OGge->window->GetWindow());
		return false;
	}
	//各タスクの更新処理
	OGge->TaskGameUpDate();
	return !glfwWindowShouldClose(OGge->window->GetWindow());
}