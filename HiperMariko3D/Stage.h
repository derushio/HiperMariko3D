#pragma once

namespace HiperMariko3D {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Stage の概要
	///
	/// 警告: このクラスの名前を変更する場合、このクラスが依存するすべての .resx ファイルに関連付けられた
	///          マネージ リソース コンパイラ ツールに対して 'Resource File Name' プロパティを
	///          変更する必要があります。この変更を行わないと、
	///          デザイナと、このフォームに関連付けられたローカライズ済みリソースとが、
	///          正しく相互に利用できなくなります。
	/// </summary>
	public ref class Stage : public System::Windows::Forms::Form
	{
	public:
		Stage(void)
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
		~Stage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  backGround;
	protected: 

	private: System::Windows::Forms::PictureBox^  actor;
	private: System::Windows::Forms::Timer^  timerMotion;
	private: System::ComponentModel::IContainer^  components;

	protected: 

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
			this->components = (gcnew System::ComponentModel::Container());
			this->backGround = (gcnew System::Windows::Forms::PictureBox());
			this->actor = (gcnew System::Windows::Forms::PictureBox());
			this->timerMotion = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->backGround))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->actor))->BeginInit();
			this->SuspendLayout();
			// 
			// backGround
			// 
			this->backGround->Location = System::Drawing::Point(12, 12);
			this->backGround->Name = L"backGround";
			this->backGround->Size = System::Drawing::Size(560, 338);
			this->backGround->TabIndex = 0;
			this->backGround->TabStop = false;
			// 
			// actor
			// 
			this->actor->BackColor = System::Drawing::Color::Black;
			this->actor->Location = System::Drawing::Point(12, 310);
			this->actor->Name = L"actor";
			this->actor->Size = System::Drawing::Size(30, 40);
			this->actor->TabIndex = 1;
			this->actor->TabStop = false;
			// 
			// timerMotion
			// 
			this->timerMotion->Enabled = true;
			this->timerMotion->Interval = 10;
			this->timerMotion->Tick += gcnew System::EventHandler(this, &Stage::timerMotion_Tick);
			// 
			// Stage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(584, 362);
			this->Controls->Add(this->actor);
			this->Controls->Add(this->backGround);
			this->Name = L"Stage";
			this->Text = L"Stage";
			this->Load += gcnew System::EventHandler(this, &Stage::Stage_Load);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Stage::Stage_KeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Stage::Stage_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->backGround))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->actor))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: char motionFlag; // MotionBitField

			 // Motion Flags
	private: char stopFlag;
	private: char rightMoveFlag;
	private: char leftMoveFlag;
	private: char jumpFlag;
			 // Motion Flags

	private: bool isJumping;
	private: int jumpBeginHeight;
	private: int theta;

	private: System::Void Stage_Load(System::Object^  sender, System::EventArgs^  e) {
				 stopFlag = 0x00;
				 rightMoveFlag = 0x01;
				 leftMoveFlag = 0x02;
				 jumpFlag = 0x04;

				 motionFlag = stopFlag;
				 isJumping = false;
				 jumpBeginHeight = 0;
				 theta = 0;
			 }

	private: System::Void Stage_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 Keys keyCode = e->KeyCode;
				 String^ keyString = keyCode.ToString();
				 this->Text = keyString;

				 if(keyString == "Right"){
					 motionFlag |= rightMoveFlag;
				 } else if(keyString == "Left"){
					 motionFlag |= leftMoveFlag;
				 } else if(keyString == "Up"){
					 motionFlag |= jumpFlag;
				 }
			 }

	private: System::Void Stage_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 Keys keyCode = e->KeyCode;
				 String^ keyString = keyCode.ToString();
				 this->Text = "";

				 if(keyString == "Right"){
					 motionFlag &= ~rightMoveFlag;
				 } else if(keyString == "Left"){
					 motionFlag &= ~leftMoveFlag;
				 } else if(keyString == "Up"){
					 motionFlag &= ~jumpFlag;
				 }
			 }

	private: System::Void timerMotion_Tick(System::Object^  sender, System::EventArgs^  e) {
				 if(isJumping){
					 motionFlag &= ~jumpFlag;
				 }

				 if((motionFlag & rightMoveFlag) == rightMoveFlag){
					 actor->Left += 2;
				 } 

				 if((motionFlag & leftMoveFlag) == leftMoveFlag){
					 actor->Left -= 2;
				 } 

				 if((motionFlag & jumpFlag) == jumpFlag){
					 jumpBeginHeight = actor->Top;
					 isJumping = true;
					 theta = 0;
				 }

				 if(theta >= 90){
					 jumpBeginHeight = 0;
					 isJumping = false;
					 theta = 0;
				 }else if(isJumping == true){
					 actor->Top = jumpBeginHeight - Math::Sin(theta*3.14159 / 180) * 100;
					 theta += 5;
				 }

				 if(isJumping == false){
					 actor->Top += 2;
				 }

				 if(actor->Bottom > backGround->Bottom){
					 actor->Top = backGround->Bottom - actor->Height;
				 }
			 }
	};
}