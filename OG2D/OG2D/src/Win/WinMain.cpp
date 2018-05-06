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
//#include "ft2build.h"
//#include FT_FREETYPE_H
//メモリリーク検知
#if (_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

//class Font
//{
//public:
//	Font();
//	~Font();
//	FT_Library library;
//	FT_Face face;
//	FT_GlyphSlot slot;
//	void Draw(char*, Box2D, Color = { 1,1,1,1 });
//};
//Font::Font()
//{
//	FT_Init_FreeType(&this->library);
//	FT_New_Face(this->library, "./data/font/msgothic.ttc", 0, &this->face);
//	this->slot = this->face->glyph;
//	FT_Set_Char_Size(face, 0, 16 * 64, 300, 300);
//	//画像データをOpenGLへ送る
//	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
//	//表示用設定
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//}
//Font::~Font()
//{
//	FT_Done_Face(this->face);
//	FT_Done_FreeType(this->library);
//}
//void Font::Draw(char* text, Box2D draw, Color color_)
//{
//	GLuint id;
//	glGenTextures(1, &id);
//	for (int i = 0; text[i] != '\0'; ++i)
//	{
//		draw.x = i * 128;
//		draw.OffsetSize();
//		FT_Load_Glyph(this->face, FT_Get_Char_Index(this->face, text[i]), FT_LOAD_RENDER);
//		const FT_Bitmap &bitmap = this->face->glyph->bitmap;
//
//		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bitmap.width, bitmap.rows, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap.buffer);
//		//座標
//		GLfloat vtx[] = {
//			draw.x,draw.h,
//			draw.w,draw.h,
//			draw.w,draw.y,
//			draw.x,draw.y,
//		};
//		//_Rotate(angle, &vtx[0]);
//		glVertexPointer(2, GL_FLOAT, 0, vtx);
//		//画像座標
//		const GLfloat texuv[] = {
//			0.f,1.f,
//			1.f,1.f,
//			1.f,0.f,
//			0.f,0.f,
//		};
//		//0.1以下のカラーを表示しない、これで透過されてる部分を切り抜くことで透過された画像になる
//		glAlphaFunc(GL_GREATER, (GLclampf)0.0);
//		glTexCoordPointer(2, GL_FLOAT, 0, texuv);
//		//OpenGLに登録されているテクスチャを紐づけ
//		glBindTexture(GL_TEXTURE_2D, id);
//		glColor4f(color_.red, color_.green, color_.blue, color_.alpha);
//		//描画
//		//glMatrixMode(GL_TEXTURE);
//		glEnable(GL_ALPHA_TEST);
//		glEnable(GL_TEXTURE_2D);
//		glEnableClientState(GL_VERTEX_ARRAY);
//		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//		glDrawArrays(GL_QUADS, 0, 4);
//		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//		glDisableClientState(GL_VERTEX_ARRAY);
//		glDisable(GL_TEXTURE_2D);
//		glDisable(GL_ALPHA_TEST);
//		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
//
//	}
//	glDeleteTextures(1, &id);
//}
//------------------
//class定義
//------------------
_OGTK* OGTK;
//Font font;
//------------------
//タスクシステム
//------------------
void TaskSystem()
{
	OGge->TaskGameUpDate();
}
void TaskRender()
{
	//font.Draw("Aa", Box2D(0, 128, 128, 128));
}
void TaskFinalize()
{
	//解放処理
	OGge->SetDeleteEngine(true);
}
//------------------
//初期化
//------------------
void Initialize() 
{
	random::Init();
	OGTK->StartTaskObject();
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
	OGTK = new _OGTK();
	//タスクの初期化処理
	OGTK->_myGameInitialize();
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
	delete OGTK;
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