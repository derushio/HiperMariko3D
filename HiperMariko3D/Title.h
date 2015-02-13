#pragma once
#include "Stage.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace HiperMariko3D {

	/// <summary>
	/// Title の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class Title : public System::Windows::Forms::Form
	{
	public:
		Title(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクタ コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~Title()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected: 
	private: System::Windows::Forms::Button^  button1;

	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// 必要なデザイナ変数です。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナ サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディタで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(92, 70);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(365, 65);
			this->label1->TabIndex = 0;
			this->label1->Text = L"HiperMariko3D";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 36, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(160, 215);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(267, 101);
			this->button1->TabIndex = 1;
			this->button1->Text = L"スタート";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Title::button1_Click);
			// 
			// Title
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 362);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Title";
			this->Text = L"Title";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 Stage^ stage = gcnew Stage();
				 stage->ShowDialog();
			 }
	};
}
