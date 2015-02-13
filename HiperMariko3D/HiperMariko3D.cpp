// HiperMariko3D.cpp : メイン プロジェクト ファイルです。

#include "stdafx.h"
#include "Title.h"

using namespace HiperMariko3D;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// コントロールが作成される前に、Windows XP ビジュアル効果を有効にします
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// メイン ウィンドウを作成して、実行します
	Application::Run(gcnew Title());
	return 0;
}
