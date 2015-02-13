#pragma once

namespace HiperMariko3D {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Stage �̊T�v
	///
	/// �x��: ���̃N���X�̖��O��ύX����ꍇ�A���̃N���X���ˑ����邷�ׂĂ� .resx �t�@�C���Ɋ֘A�t����ꂽ
	///          �}�l�[�W ���\�[�X �R���p�C�� �c�[���ɑ΂��� 'Resource File Name' �v���p�e�B��
	///          �ύX����K�v������܂��B���̕ύX���s��Ȃ��ƁA
	///          �f�U�C�i�ƁA���̃t�H�[���Ɋ֘A�t����ꂽ���[�J���C�Y�ς݃��\�[�X�Ƃ��A
	///          ���������݂ɗ��p�ł��Ȃ��Ȃ�܂��B
	/// </summary>
	public ref class Stage : public System::Windows::Forms::Form
	{
	public:
		Stage(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
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



	private: System::ComponentModel::IContainer^  components;

	protected: 

	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�ϐ��ł��B
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�ŕύX���Ȃ��ł��������B
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
			this->bottomBlock->Location = System::Drawing::Point(542, 250);
			this->bottomBlock->Name = L"bottomBlock";
			this->bottomBlock->Size = System::Drawing::Size(30, 200);
			this->bottomBlock->TabIndex = 2;
			this->bottomBlock->TabStop = false;
			// 
			// topBlock
			// 
			this->topBlock->BackColor = System::Drawing::Color::Black;
			this->topBlock->Location = System::Drawing::Point(542, -100);
			this->topBlock->Name = L"topBlock";
			this->topBlock->Size = System::Drawing::Size(30, 200);
			this->topBlock->TabIndex = 3;
			this->topBlock->TabStop = false;
			// 
			// Stage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(584, 362);
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
				 }
			 }
	private: void collisionCheck(){
				 if(topBlock->Left < actor->Right && topBlock->Right > actor->Left){
					 if(topBlock->Bottom > actor->Top || bottomBlock->Top < actor->Bottom){
						 this->Close();
					 }
				 }
			 }

	private: System::Void timerMotion_Tick(System::Object^  sender, System::EventArgs^  e) {
				 charMove();
				 blockMove();
				 collisionCheck();
			 }
	};
}