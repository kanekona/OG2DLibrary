///Windowの生成、管理を行うclass
#pragma once
#include "OGSystem\_OGsystem.h"

class Window {
private:
	GLFWimage image[1];				//アイコン情報
	GLuint id_;						//アイコン画像のID
	bool isIcon;					//ウィンドウのアイコン化状況
	bool isVisualization;			//可視化状況
	int _widht;						//幅
	int _height;					//高さ
	char* _Name;					//Windowの名
	bool _Screen;					//フルスク
	Vec2 position;					//Windowの位置
	GLFWwindow *window;				//Window情報
public:
	Window();						//コンストラクタ
	Window(							//情報有コンストラクタ
		const int,
		const int,
		char*,
		const bool,
		const Vec2&);
	~Window();						//デストラクタ
	bool createWindow(				//Windowを生成する
		const int,
		const int,
		char*,
		const bool,
		const Vec2&);
	void setIcon(const std::string&);		//アイコンを設定する
	void LimitsWindow();			//Windowのサイズとアスペクト比を固定する
	void WindowIcon();				//Windowをアイコン化、アイコン化から解除する
	void Visualization();			//Windowを可視化、可視化から解除する
	void InMouseMode(const bool);	//マウスを表示させるかを決める
	Vec2 GetSize() const;			//Windowのサイズを返す
	Vec2 GetPos() const;			//Windowの位置を返す
	void SetWindowPos(const Vec2&);		//生成するWindowの位置を設定する
	GLFWwindow* GetWindow() const;	//Window情報を返す
};