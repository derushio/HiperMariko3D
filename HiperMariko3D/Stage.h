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
	private: System::Windows::Forms::PictureBox^  bottomBlock;
	private: System::Windows::Forms::PictureBox^  topBlock;
	private: System::Windows::Forms::Label^  scoreCountLabel;




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Stage::typeid));
			this->backGround = (gcnew System::Windows::Forms::PictureBox());
			this->actor = (gcnew System::Windows::Forms::PictureBox());
			this->timerMotion = (gcnew System::Windows::Forms::Timer(this->components));
			this->bottomBlock = (gcnew System::Windows::Forms::PictureBox());
			this->topBlock = (gcnew System::Windows::Forms::PictureBox());
			this->scoreCountLabel = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->backGround))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->actor))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bottomBlock))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->topBlock))->BeginInit();
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
			this->actor->BackColor = System::Drawing::Color::Transparent;
			this->actor->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"actor.BackgroundImage")));
			this->actor->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->actor->Location = System::Drawing::Point(12, 300);
			this->actor->Name = L"actor";
			this->actor->Size = System::Drawing::Size(50, 50);
			this->actor->TabIndex = 1;
			this->actor->TabStop = false;
			// 
			// timerMotion
			// 
			this->timerMotion->Enabled = true;
			this->timerMotion->Interval = 10;
			this->timerMotion->Tick += gcnew System::EventHandler(this, &Stage::timerMotion_Tick);
			// 
			// bottomBlock
			// 
			this->bottomBlock->BackColor = System::Drawing::Color::Black;
			this->bottomBlock->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"bottomBlock.BackgroundImage")));
			this->bottomBlock->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->bottomBlock->Location = System::Drawing::Point(542, 250);
			this->bottomBlock->Name = L"bottomBlock";
			this->bottomBlock->Size = System::Drawing::Size(30, 200);
			this->bottomBlock->TabIndex = 2;
			this->bottomBlock->TabStop = false;
			// 
			// topBlock
			// 
			this->topBlock->BackColor = System::Drawing::Color::Black;
			this->topBlock->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"topBlock.BackgroundImage")));
			this->topBlock->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->topBlock->Location = System::Drawing::Point(542, -100);
			this->topBlock->Name = L"topBlock";
			this->topBlock->Size = System::Drawing::Size(30, 200);
			this->topBlock->TabIndex = 3;
			this->topBlock->TabStop = false;
			// 
			// scoreCountLabel
			// 
			this->scoreCountLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->scoreCountLabel->AutoSize = true;
			this->scoreCountLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->scoreCountLabel->Location = System::Drawing::Point(491, 12);
			this->scoreCountLabel->Name = L"scoreCountLabel";
			this->scoreCountLabel->Size = System::Drawing::Size(81, 25);
			this->scoreCountLabel->TabIndex = 4;
			this->scoreCountLabel->Text = L"スコア：0";
			this->scoreCountLabel->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// Stage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(584, 362);
			this->Controls->Add(this->scoreCountLabel);
			this->Controls->Add(this->topBlock);
			this->Controls->Add(this->bottomBlock);
			this->Controls->Add(this->actor);
			this->Controls->Add(this->backGround);
			this->Name = L"Stage";
			this->Text = L"Stage";
			this->Load += gcnew System::EventHandler(this, &Stage::Stage_Load);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Stage::Stage_KeyUp);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Stage::Stage_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->backGround))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->actor))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->bottomBlock))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->topBlock))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

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
	private: int scoreCount;

	private: Random^ random;

	private: System::Void Stage_Load(System::Object^  sender, System::EventArgs^  e) {
				 stopFlag = 0x00;
				 rightMoveFlag = 0x01;
				 leftMoveFlag = 0x02;
				 jumpFlag = 0x04;

				 motionFlag = stopFlag;
				 isJumping = false;
				 jumpBeginHeight = 0;
				 theta = 0;
				 random = gcnew Random();
				 scoreCount = 0;
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

	private: void charMove(){
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

	private: void blockMove(){
				 topBlock->Left -= 4;
				 bottomBlock->Left -= 4;

				 if(topBlock->Right < backGround->Left){
					 topBlock->Left += backGround->Right;
					 bottomBlock->Left += backGround->Right;

					 topBlock->Top = backGround->Top + random->Next(backGround->Height - 150) - topBlock->Height;
					 bottomBlock->Top = topBlock->Bottom + 150;

					 scoreCount++;
					 scoreCountLabel->Text = "スコア:" + scoreCount.ToString();
					 scoreCountLabel->Left = backGround->Right - scoreCountLabel->Width;
				 }
			 }
	private: bool collisionCheck(){
				 if(topBlock->Left < actor->Right && topBlock->Right > actor->Left){
					 if(topBlock->Bottom > actor->Top || bottomBlock->Top < actor->Bottom){
						 return true;
					 }
				 }

				 return false;
			 }

	private: System::Void timerMotion_Tick(System::Object^  sender, System::EventArgs^  e) {
				 charMove();
				 blockMove();
				 if(collisionCheck()){
					 scoreCountLabel->Text = "game over";
					 scoreCountLabel->Left = backGround->Right - scoreCountLabel->Width;
					
					 timerMotion->Stop();
				 }
			 }
	};
}