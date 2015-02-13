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
	/// Title �̊T�v
	///
	/// �x��: ���̃N���X�̖��O��ύX����ꍇ�A���̃N���X���ˑ����邷�ׂĂ� .resx �t�@�C���Ɋ֘A�t����ꂽ
	///          �}�l�[�W ���\�[�X �R���p�C�� �c�[���ɑ΂��� 'Resource File Name' �v���p�e�B��
	///          �ύX����K�v������܂��B���̕ύX���s��Ȃ��ƁA
	///          �f�U�C�i�ƁA���̃t�H�[���Ɋ֘A�t����ꂽ���[�J���C�Y�ς݃��\�[�X�Ƃ��A
	///          ���������݂ɗ��p�ł��Ȃ��Ȃ�܂��B
	/// </summary>
	public ref class Title : public System::Windows::Forms::Form
	{
	public:
		Title(void)
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
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::ComponentModel::IContainer^  components;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
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
			this->button1->Text = L"�X�^�[�g";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Title::button1_Click);
			// 
			// serialPort1
			// 
			this->serialPort1->BaudRate = 19200;
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &Title::serialPort1_DataReceived);
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
			this->Load += gcnew System::EventHandler(this, &Title::Title_Load);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Title::Title_FormClosed);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		delegate void SerialDataReceivedDelegate(String^ receiveData);
	private: void SerialDataReceived(String^ receiveData){
				 if(0 < receiveData->IndexOf("3_ON")){
					 Stage^ stage = gcnew Stage();
					 serialPort1->Close();
					 stage->ShowDialog();
					 serialPort1->Open();
				 }else if(0 < receiveData->IndexOf("3_OFF")){
				 }
			 }

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 Stage^ stage = gcnew Stage();
				 try{
					 serialPort1->Close();
					 stage->ShowDialog();
					 serialPort1->Open();
				 }catch(Exception^ e){
				 }
			 }

	private: System::Void serialPort1_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) {
				 SerialDataReceivedDelegate^ receiveDelegate = gcnew SerialDataReceivedDelegate(this, &HiperMariko3D::Title::SerialDataReceived);
				 String^ receiveData = serialPort1->ReadExisting();
				 this->Invoke(receiveDelegate, receiveData);
			 }
	private: System::Void Title_Load(System::Object^  sender, System::EventArgs^  e) {
				 serialPort1->Open();
			 }
	private: System::Void Title_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
				 serialPort1->Close();
			 }
	};
}
