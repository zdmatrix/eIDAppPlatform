#pragma once

#include "ReaderInterface.h"

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Threading;

	using namespace System::Security::Permissions;

	using namespace FunctionModule;

	/// <summary>
	/// MainForm 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:

		const static Int32 HEX = 0x10;
		const static Int32 DECIMAL = 0x0A;

		const static bool ENABLE_ALL_BUTTON = true;
		const static bool DISABLE_ALL_BUTTON = false;
		const static bool OPEN_READER = true;
		const static bool CLOSE_READER = false;

		const static String^ OPEN_READER_ERROR_STR = gcnew String("Open Reader Failed!");
		const static String^ CLOSE_READER_ERROR_STR = gcnew String("Close Reader Failed!");

		Guid^ USBGUID;

		array<byte>^ byGetRandom;

		bool bPlugIn;
		bool bPlugOut;
		bool bGetReaderList;
		bool bDeviceEnabled;

		long lRet;

		String^ strSelectedReader;

	public: 

		ReaderInterface^ ri;

		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//

			bPlugIn = false;
			bPlugOut = false;
			bGetReaderList = false;
			bDeviceEnabled = false;

			strSelectedReader = nullptr;

			byGetRandom = gcnew array<byte>{0x00, (byte)0x84, 0x00, 0x00, 0x08};

			USBGUID = gcnew Guid("A5DCBF10-6530-11D2-901F-00C04FB951ED");

			ri = gcnew ReaderInterface();
						
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnOpenDevice;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  btnCloseDevice;


	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPageTest;
	private: System::Windows::Forms::TabPage^  tabPageeCash;
	private: System::Windows::Forms::TabPage^  tabPageNewKey;
	private: System::Windows::Forms::TabPage^  tabPageOTP;
	private: System::Windows::Forms::TabPage^  tabPageeID;
	private: System::Windows::Forms::TextBox^  textBoxShow;



	private: System::Windows::Forms::TextBox^  textBoxExpense;

	private: System::Windows::Forms::TextBox^  textBoxRecharge;
	private: System::Windows::Forms::Button^  btnExpense;


	private: System::Windows::Forms::Button^  btnRecharge;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBoxSrcAccount;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBoxTransform;
	private: System::Windows::Forms::TextBox^  textBoxDstAccount;


	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::PictureBox^  pictureBoxSrcAccount;
	private: System::Windows::Forms::PictureBox^  pictureBoxAuthCode;

	private: System::Windows::Forms::PictureBox^  pictureBoxTransform;

	private: System::Windows::Forms::PictureBox^  pictureBoxDstAccount;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  textBoxChallengeCode;

	private: System::Windows::Forms::Button^  btnChallengeCode;
	private: System::Windows::Forms::TextBox^  textBoxResponCode;

	private: System::Windows::Forms::Button^  btnLogIn;
	private: System::Windows::Forms::PictureBox^  pictureBoxOTP;
	private: System::Windows::Forms::Button^  btnDisOnCard;
	private: System::Windows::Forms::Button^  btnGetRandom;
	private: System::Windows::Forms::Button^  btnBeAuthData;
	private: System::Windows::Forms::Button^  btnAuth;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  textBox2;

	private: System::Windows::Forms::Label^  label13;

	private: System::Windows::Forms::TextBox^  textBoxBanlance;

	private: System::Windows::Forms::Button^  btnBanlance;

	protected: 

		[SecurityPermission(SecurityAction::Demand, Flags=SecurityPermissionFlag::UnmanagedCode)]
		virtual void WndProc( Message% m ) override
		{

			// Listen for operating system messages.
			switch ( m.Msg )
			{
			case WM_DEVICECHANGE:

				switch (safe_cast<int>(m.WParam)){
					case DBT_DEVICEARRIVAL:
						bPlugIn = true;
						bPlugOut = false;
						break;
					case DBT_DEVICEREMOVECOMPLETE:
						bPlugIn = false;
						bPlugOut = true;
						break;
					default:
						break;
				}
				
				// The WParam value identifies what is occurring.

				// Invalidate to get new text painted.
				this->Invalidate();
				break;
			}
			Form::WndProc( m );
		}
private: System::ComponentModel::IContainer^  components;
protected: 






	protected: 

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->btnCloseDevice = (gcnew System::Windows::Forms::Button());
			this->btnOpenDevice = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->textBoxBanlance = (gcnew System::Windows::Forms::TextBox());
			this->btnBanlance = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPageTest = (gcnew System::Windows::Forms::TabPage());
			this->btnDisOnCard = (gcnew System::Windows::Forms::Button());
			this->btnGetRandom = (gcnew System::Windows::Forms::Button());
			this->tabPageeCash = (gcnew System::Windows::Forms::TabPage());
			this->textBoxExpense = (gcnew System::Windows::Forms::TextBox());
			this->textBoxRecharge = (gcnew System::Windows::Forms::TextBox());
			this->btnExpense = (gcnew System::Windows::Forms::Button());
			this->btnRecharge = (gcnew System::Windows::Forms::Button());
			this->tabPageNewKey = (gcnew System::Windows::Forms::TabPage());
			this->pictureBoxAuthCode = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxTransform = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDstAccount = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxSrcAccount = (gcnew System::Windows::Forms::PictureBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBoxTransform = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDstAccount = (gcnew System::Windows::Forms::TextBox());
			this->textBoxSrcAccount = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabPageOTP = (gcnew System::Windows::Forms::TabPage());
			this->pictureBoxOTP = (gcnew System::Windows::Forms::PictureBox());
			this->btnLogIn = (gcnew System::Windows::Forms::Button());
			this->textBoxResponCode = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBoxChallengeCode = (gcnew System::Windows::Forms::TextBox());
			this->btnChallengeCode = (gcnew System::Windows::Forms::Button());
			this->tabPageeID = (gcnew System::Windows::Forms::TabPage());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->btnAuth = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btnBeAuthData = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBoxShow = (gcnew System::Windows::Forms::TextBox());
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPageTest->SuspendLayout();
			this->tabPageeCash->SuspendLayout();
			this->tabPageNewKey->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxAuthCode))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxTransform))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxDstAccount))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxSrcAccount))->BeginInit();
			this->tabPageOTP->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxOTP))->BeginInit();
			this->tabPageeID->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->btnCloseDevice);
			this->splitContainer1->Panel1->Controls->Add(this->btnOpenDevice);
			this->splitContainer1->Panel1->Controls->Add(this->comboBox1);
			this->splitContainer1->Panel1->Controls->Add(this->label1);
			this->splitContainer1->Panel1->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->splitContainer2);
			this->splitContainer1->Panel2->Font = (gcnew System::Drawing::Font(L"宋体", 10.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->splitContainer1->Size = System::Drawing::Size(711, 484);
			this->splitContainer1->SplitterDistance = 40;
			this->splitContainer1->TabIndex = 0;
			// 
			// btnCloseDevice
			// 
			this->btnCloseDevice->Location = System::Drawing::Point(624, 8);
			this->btnCloseDevice->Name = L"btnCloseDevice";
			this->btnCloseDevice->Size = System::Drawing::Size(75, 23);
			this->btnCloseDevice->TabIndex = 3;
			this->btnCloseDevice->Text = L"关闭设备";
			this->btnCloseDevice->UseVisualStyleBackColor = true;
			this->btnCloseDevice->Click += gcnew System::EventHandler(this, &MainForm::btnCloseDevice_Click);
			// 
			// btnOpenDevice
			// 
			this->btnOpenDevice->Location = System::Drawing::Point(543, 8);
			this->btnOpenDevice->Name = L"btnOpenDevice";
			this->btnOpenDevice->Size = System::Drawing::Size(75, 23);
			this->btnOpenDevice->TabIndex = 2;
			this->btnOpenDevice->Text = L"打开设备";
			this->btnOpenDevice->UseVisualStyleBackColor = true;
			this->btnOpenDevice->Click += gcnew System::EventHandler(this, &MainForm::btnOpenDevice_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(76, 9);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(437, 22);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::comboBox1_SelectedIndexChanged);
			this->comboBox1->DropDown += gcnew System::EventHandler(this, &MainForm::comboBox1_DropDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 14);
			this->label1->TabIndex = 0;
			this->label1->Text = L"选择设备";
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->textBoxBanlance);
			this->splitContainer2->Panel1->Controls->Add(this->btnBanlance);
			this->splitContainer2->Panel1->Controls->Add(this->tabControl1);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->label13);
			this->splitContainer2->Panel2->Controls->Add(this->textBoxShow);
			this->splitContainer2->Panel2->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->splitContainer2->Size = System::Drawing::Size(711, 440);
			this->splitContainer2->SplitterDistance = 440;
			this->splitContainer2->TabIndex = 0;
			// 
			// textBoxBanlance
			// 
			this->textBoxBanlance->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxBanlance->Location = System::Drawing::Point(210, 402);
			this->textBoxBanlance->Name = L"textBoxBanlance";
			this->textBoxBanlance->ReadOnly = true;
			this->textBoxBanlance->Size = System::Drawing::Size(101, 23);
			this->textBoxBanlance->TabIndex = 7;
			// 
			// btnBanlance
			// 
			this->btnBanlance->Location = System::Drawing::Point(110, 402);
			this->btnBanlance->Name = L"btnBanlance";
			this->btnBanlance->Size = System::Drawing::Size(75, 23);
			this->btnBanlance->TabIndex = 6;
			this->btnBanlance->Text = L"卡余额";
			this->btnBanlance->UseVisualStyleBackColor = true;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPageTest);
			this->tabControl1->Controls->Add(this->tabPageeCash);
			this->tabControl1->Controls->Add(this->tabPageNewKey);
			this->tabControl1->Controls->Add(this->tabPageOTP);
			this->tabControl1->Controls->Add(this->tabPageeID);
			this->tabControl1->ItemSize = System::Drawing::Size(86, 30);
			this->tabControl1->Location = System::Drawing::Point(3, 3);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(434, 379);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->tabControl1->TabIndex = 0;
			// 
			// tabPageTest
			// 
			this->tabPageTest->Controls->Add(this->btnDisOnCard);
			this->tabPageTest->Controls->Add(this->btnGetRandom);
			this->tabPageTest->Location = System::Drawing::Point(4, 34);
			this->tabPageTest->Name = L"tabPageTest";
			this->tabPageTest->Padding = System::Windows::Forms::Padding(3);
			this->tabPageTest->Size = System::Drawing::Size(426, 341);
			this->tabPageTest->TabIndex = 0;
			this->tabPageTest->Text = L"卡测试";
			this->tabPageTest->UseVisualStyleBackColor = true;
			// 
			// btnDisOnCard
			// 
			this->btnDisOnCard->Location = System::Drawing::Point(234, 122);
			this->btnDisOnCard->Name = L"btnDisOnCard";
			this->btnDisOnCard->Size = System::Drawing::Size(119, 154);
			this->btnDisOnCard->TabIndex = 5;
			this->btnDisOnCard->Text = L"写数据并显示";
			this->btnDisOnCard->UseVisualStyleBackColor = true;
			// 
			// btnGetRandom
			// 
			this->btnGetRandom->Location = System::Drawing::Point(73, 122);
			this->btnGetRandom->Name = L"btnGetRandom";
			this->btnGetRandom->Size = System::Drawing::Size(119, 154);
			this->btnGetRandom->TabIndex = 4;
			this->btnGetRandom->Text = L"读随机数";
			this->btnGetRandom->UseVisualStyleBackColor = true;
			this->btnGetRandom->Click += gcnew System::EventHandler(this, &MainForm::btnGetRandom_Click);
			// 
			// tabPageeCash
			// 
			this->tabPageeCash->Controls->Add(this->textBoxExpense);
			this->tabPageeCash->Controls->Add(this->textBoxRecharge);
			this->tabPageeCash->Controls->Add(this->btnExpense);
			this->tabPageeCash->Controls->Add(this->btnRecharge);
			this->tabPageeCash->Location = System::Drawing::Point(4, 34);
			this->tabPageeCash->Name = L"tabPageeCash";
			this->tabPageeCash->Padding = System::Windows::Forms::Padding(3);
			this->tabPageeCash->Size = System::Drawing::Size(426, 341);
			this->tabPageeCash->TabIndex = 1;
			this->tabPageeCash->Text = L"eCash";
			this->tabPageeCash->UseVisualStyleBackColor = true;
			// 
			// textBoxExpense
			// 
			this->textBoxExpense->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxExpense->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBoxExpense->Location = System::Drawing::Point(241, 234);
			this->textBoxExpense->Name = L"textBoxExpense";
			this->textBoxExpense->Size = System::Drawing::Size(68, 30);
			this->textBoxExpense->TabIndex = 8;
			this->textBoxExpense->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxRecharge
			// 
			this->textBoxRecharge->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxRecharge->Font = (gcnew System::Drawing::Font(L"宋体", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBoxRecharge->Location = System::Drawing::Point(241, 133);
			this->textBoxRecharge->Name = L"textBoxRecharge";
			this->textBoxRecharge->Size = System::Drawing::Size(68, 30);
			this->textBoxRecharge->TabIndex = 7;
			this->textBoxRecharge->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btnExpense
			// 
			this->btnExpense->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btnExpense->Location = System::Drawing::Point(117, 232);
			this->btnExpense->Name = L"btnExpense";
			this->btnExpense->Size = System::Drawing::Size(75, 35);
			this->btnExpense->TabIndex = 6;
			this->btnExpense->Text = L"消费";
			this->btnExpense->UseVisualStyleBackColor = true;
			// 
			// btnRecharge
			// 
			this->btnRecharge->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->btnRecharge->Location = System::Drawing::Point(117, 131);
			this->btnRecharge->Name = L"btnRecharge";
			this->btnRecharge->Size = System::Drawing::Size(75, 35);
			this->btnRecharge->TabIndex = 5;
			this->btnRecharge->Text = L"充值";
			this->btnRecharge->UseVisualStyleBackColor = true;
			// 
			// tabPageNewKey
			// 
			this->tabPageNewKey->Controls->Add(this->pictureBoxAuthCode);
			this->tabPageNewKey->Controls->Add(this->pictureBoxTransform);
			this->tabPageNewKey->Controls->Add(this->pictureBoxDstAccount);
			this->tabPageNewKey->Controls->Add(this->pictureBoxSrcAccount);
			this->tabPageNewKey->Controls->Add(this->label10);
			this->tabPageNewKey->Controls->Add(this->label7);
			this->tabPageNewKey->Controls->Add(this->label8);
			this->tabPageNewKey->Controls->Add(this->label9);
			this->tabPageNewKey->Controls->Add(this->label6);
			this->tabPageNewKey->Controls->Add(this->textBoxTransform);
			this->tabPageNewKey->Controls->Add(this->textBoxDstAccount);
			this->tabPageNewKey->Controls->Add(this->textBoxSrcAccount);
			this->tabPageNewKey->Controls->Add(this->label5);
			this->tabPageNewKey->Controls->Add(this->label4);
			this->tabPageNewKey->Controls->Add(this->label3);
			this->tabPageNewKey->Controls->Add(this->label2);
			this->tabPageNewKey->Location = System::Drawing::Point(4, 34);
			this->tabPageNewKey->Name = L"tabPageNewKey";
			this->tabPageNewKey->Padding = System::Windows::Forms::Padding(3);
			this->tabPageNewKey->Size = System::Drawing::Size(426, 341);
			this->tabPageNewKey->TabIndex = 2;
			this->tabPageNewKey->Text = L"二代Key";
			this->tabPageNewKey->UseVisualStyleBackColor = true;
			// 
			// pictureBoxAuthCode
			// 
			this->pictureBoxAuthCode->Location = System::Drawing::Point(172, 310);
			this->pictureBoxAuthCode->Name = L"pictureBoxAuthCode";
			this->pictureBoxAuthCode->Size = System::Drawing::Size(176, 31);
			this->pictureBoxAuthCode->TabIndex = 19;
			this->pictureBoxAuthCode->TabStop = false;
			// 
			// pictureBoxTransform
			// 
			this->pictureBoxTransform->Location = System::Drawing::Point(172, 279);
			this->pictureBoxTransform->Name = L"pictureBoxTransform";
			this->pictureBoxTransform->Size = System::Drawing::Size(176, 31);
			this->pictureBoxTransform->TabIndex = 18;
			this->pictureBoxTransform->TabStop = false;
			// 
			// pictureBoxDstAccount
			// 
			this->pictureBoxDstAccount->Location = System::Drawing::Point(172, 248);
			this->pictureBoxDstAccount->Name = L"pictureBoxDstAccount";
			this->pictureBoxDstAccount->Size = System::Drawing::Size(176, 31);
			this->pictureBoxDstAccount->TabIndex = 17;
			this->pictureBoxDstAccount->TabStop = false;
			// 
			// pictureBoxSrcAccount
			// 
			this->pictureBoxSrcAccount->Location = System::Drawing::Point(172, 217);
			this->pictureBoxSrcAccount->Name = L"pictureBoxSrcAccount";
			this->pictureBoxSrcAccount->Size = System::Drawing::Size(176, 31);
			this->pictureBoxSrcAccount->TabIndex = 16;
			this->pictureBoxSrcAccount->TabStop = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(79, 318);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(49, 14);
			this->label10->TabIndex = 15;
			this->label10->Text = L"认证码";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(79, 287);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(63, 14);
			this->label7->TabIndex = 14;
			this->label7->Text = L"转账金额";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(79, 256);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(63, 14);
			this->label8->TabIndex = 13;
			this->label8->Text = L"目地账户";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(79, 225);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(49, 14);
			this->label9->TabIndex = 12;
			this->label9->Text = L"源账户";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label6->Location = System::Drawing::Point(169, 186);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(104, 16);
			this->label6->TabIndex = 11;
			this->label6->Text = L"确认转账信息";
			// 
			// textBoxTransform
			// 
			this->textBoxTransform->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxTransform->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBoxTransform->Location = System::Drawing::Point(172, 130);
			this->textBoxTransform->Name = L"textBoxTransform";
			this->textBoxTransform->Size = System::Drawing::Size(176, 21);
			this->textBoxTransform->TabIndex = 10;
			this->textBoxTransform->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxDstAccount
			// 
			this->textBoxDstAccount->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxDstAccount->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBoxDstAccount->Location = System::Drawing::Point(172, 92);
			this->textBoxDstAccount->Name = L"textBoxDstAccount";
			this->textBoxDstAccount->ReadOnly = true;
			this->textBoxDstAccount->Size = System::Drawing::Size(176, 21);
			this->textBoxDstAccount->TabIndex = 9;
			this->textBoxDstAccount->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBoxSrcAccount
			// 
			this->textBoxSrcAccount->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxSrcAccount->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBoxSrcAccount->Location = System::Drawing::Point(172, 55);
			this->textBoxSrcAccount->Name = L"textBoxSrcAccount";
			this->textBoxSrcAccount->ReadOnly = true;
			this->textBoxSrcAccount->Size = System::Drawing::Size(176, 21);
			this->textBoxSrcAccount->TabIndex = 8;
			this->textBoxSrcAccount->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(79, 133);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 14);
			this->label5->TabIndex = 4;
			this->label5->Text = L"转账金额";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(79, 95);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 14);
			this->label4->TabIndex = 3;
			this->label4->Text = L"目地账户";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(79, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 14);
			this->label3->TabIndex = 2;
			this->label3->Text = L"源账户";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label2->Location = System::Drawing::Point(169, 23);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"输入转账信息";
			// 
			// tabPageOTP
			// 
			this->tabPageOTP->Controls->Add(this->pictureBoxOTP);
			this->tabPageOTP->Controls->Add(this->btnLogIn);
			this->tabPageOTP->Controls->Add(this->textBoxResponCode);
			this->tabPageOTP->Controls->Add(this->label11);
			this->tabPageOTP->Controls->Add(this->textBoxChallengeCode);
			this->tabPageOTP->Controls->Add(this->btnChallengeCode);
			this->tabPageOTP->Location = System::Drawing::Point(4, 34);
			this->tabPageOTP->Name = L"tabPageOTP";
			this->tabPageOTP->Padding = System::Windows::Forms::Padding(3);
			this->tabPageOTP->Size = System::Drawing::Size(426, 341);
			this->tabPageOTP->TabIndex = 3;
			this->tabPageOTP->Text = L"OTP";
			this->tabPageOTP->UseVisualStyleBackColor = true;
			// 
			// pictureBoxOTP
			// 
			this->pictureBoxOTP->Location = System::Drawing::Point(6, 175);
			this->pictureBoxOTP->Name = L"pictureBoxOTP";
			this->pictureBoxOTP->Size = System::Drawing::Size(414, 218);
			this->pictureBoxOTP->TabIndex = 15;
			this->pictureBoxOTP->TabStop = false;
			// 
			// btnLogIn
			// 
			this->btnLogIn->Location = System::Drawing::Point(154, 132);
			this->btnLogIn->Name = L"btnLogIn";
			this->btnLogIn->Size = System::Drawing::Size(85, 31);
			this->btnLogIn->TabIndex = 14;
			this->btnLogIn->Text = L"登录";
			this->btnLogIn->UseVisualStyleBackColor = true;
			// 
			// textBoxResponCode
			// 
			this->textBoxResponCode->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxResponCode->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBoxResponCode->Location = System::Drawing::Point(173, 70);
			this->textBoxResponCode->Name = L"textBoxResponCode";
			this->textBoxResponCode->ReadOnly = true;
			this->textBoxResponCode->Size = System::Drawing::Size(136, 26);
			this->textBoxResponCode->TabIndex = 13;
			this->textBoxResponCode->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label11
			// 
			this->label11->Location = System::Drawing::Point(69, 68);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(85, 31);
			this->label11->TabIndex = 12;
			this->label11->Text = L"应答码";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBoxChallengeCode
			// 
			this->textBoxChallengeCode->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxChallengeCode->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBoxChallengeCode->Location = System::Drawing::Point(173, 20);
			this->textBoxChallengeCode->Name = L"textBoxChallengeCode";
			this->textBoxChallengeCode->ReadOnly = true;
			this->textBoxChallengeCode->Size = System::Drawing::Size(136, 26);
			this->textBoxChallengeCode->TabIndex = 11;
			this->textBoxChallengeCode->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btnChallengeCode
			// 
			this->btnChallengeCode->Location = System::Drawing::Point(69, 18);
			this->btnChallengeCode->Name = L"btnChallengeCode";
			this->btnChallengeCode->Size = System::Drawing::Size(85, 31);
			this->btnChallengeCode->TabIndex = 5;
			this->btnChallengeCode->Text = L"生成挑战码";
			this->btnChallengeCode->UseVisualStyleBackColor = true;
			// 
			// tabPageeID
			// 
			this->tabPageeID->Controls->Add(this->label12);
			this->tabPageeID->Controls->Add(this->textBox2);
			this->tabPageeID->Controls->Add(this->btnAuth);
			this->tabPageeID->Controls->Add(this->textBox1);
			this->tabPageeID->Controls->Add(this->btnBeAuthData);
			this->tabPageeID->Location = System::Drawing::Point(4, 34);
			this->tabPageeID->Name = L"tabPageeID";
			this->tabPageeID->Padding = System::Windows::Forms::Padding(3);
			this->tabPageeID->Size = System::Drawing::Size(426, 341);
			this->tabPageeID->TabIndex = 4;
			this->tabPageeID->Text = L"eID认证";
			this->tabPageeID->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->Location = System::Drawing::Point(40, 193);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(128, 31);
			this->label12->TabIndex = 16;
			this->label12->Text = L"认证数据";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox2
			// 
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox2->Location = System::Drawing::Point(185, 195);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(201, 26);
			this->textBox2->TabIndex = 15;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btnAuth
			// 
			this->btnAuth->Location = System::Drawing::Point(153, 111);
			this->btnAuth->Name = L"btnAuth";
			this->btnAuth->Size = System::Drawing::Size(125, 31);
			this->btnAuth->TabIndex = 13;
			this->btnAuth->Text = L"开始认证";
			this->btnAuth->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->textBox1->Location = System::Drawing::Point(185, 52);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(201, 26);
			this->textBox1->TabIndex = 12;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btnBeAuthData
			// 
			this->btnBeAuthData->Location = System::Drawing::Point(43, 50);
			this->btnBeAuthData->Name = L"btnBeAuthData";
			this->btnBeAuthData->Size = System::Drawing::Size(125, 31);
			this->btnBeAuthData->TabIndex = 6;
			this->btnBeAuthData->Text = L"生成待认证数据";
			this->btnBeAuthData->UseVisualStyleBackColor = true;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"宋体", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->label13->Location = System::Drawing::Point(96, 11);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(72, 16);
			this->label13->TabIndex = 6;
			this->label13->Text = L"状态输出";
			// 
			// textBoxShow
			// 
			this->textBoxShow->Location = System::Drawing::Point(4, 37);
			this->textBoxShow->Multiline = true;
			this->textBoxShow->Name = L"textBoxShow";
			this->textBoxShow->ReadOnly = true;
			this->textBoxShow->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxShow->Size = System::Drawing::Size(260, 400);
			this->textBoxShow->TabIndex = 0;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(711, 484);
			this->Controls->Add(this->splitContainer1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"eID应用平台";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel1->PerformLayout();
			this->splitContainer2->Panel2->ResumeLayout(false);
			this->splitContainer2->Panel2->PerformLayout();
			this->splitContainer2->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPageTest->ResumeLayout(false);
			this->tabPageeCash->ResumeLayout(false);
			this->tabPageeCash->PerformLayout();
			this->tabPageNewKey->ResumeLayout(false);
			this->tabPageNewKey->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxAuthCode))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxTransform))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxDstAccount))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxSrcAccount))->EndInit();
			this->tabPageOTP->ResumeLayout(false);
			this->tabPageOTP->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxOTP))->EndInit();
			this->tabPageeID->ResumeLayout(false);
			this->tabPageeID->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {

			 HWND hWnd;
			 HDEVNOTIFY hDevNotify;

			 DEV_BROADCAST_DEVICEINTERFACE NotificationFilter;
			 
			 bGetReaderList = false;
			 bDeviceEnabled = false;
			 strSelectedReader = nullptr;

			 array<Byte>^ guid = USBGUID->ToByteArray();
			 cli::pin_ptr<Byte> byGuid = &guid[0];
			 hWnd = (HWND)this->MainForm::Handle.ToPointer();

			 NotificationFilter.dbcc_size = sizeof(DEV_BROADCAST_DEVICEINTERFACE);
			 NotificationFilter.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
			 NotificationFilter.dbcc_classguid = *(GUID*)byGuid;
			 

			 cli::pin_ptr<DEV_BROADCAST_DEVICEINTERFACE> pNotificationFilter = &NotificationFilter;
			 hDevNotify = RegisterDeviceNotification(hWnd, pNotificationFilter, DEVICE_NOTIFY_WINDOW_HANDLE);

			 Button_Control(DISABLE_ALL_BUTTON);

		}


private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			
			 if(this->comboBox1->SelectedItem->ToString() != nullptr){
				 strSelectedReader = this->comboBox1->SelectedItem->ToString();
				 this->btnOpenDevice->Enabled = true;
			 }
			 

		 }

private: System::Void btnOpenDevice_Click(System::Object^  sender, System::EventArgs^  e) {

			 lRet = ri->ReaderControl(strSelectedReader, OPEN_READER);
			 if(lRet != SCARD_S_SUCCESS){
				 ShowErrorDescription(lRet);
				 bDeviceEnabled = false;
			 }else{
				 bDeviceEnabled = true;
				 Button_Control(ENABLE_ALL_BUTTON);
				 this->btnOpenDevice->Enabled = false;
			 }

		 }

private: System::Void Button_Control(bool status){
			  if(status){
				  this->btnAuth->Enabled = true;
				  
				  this->btnBanlance->Enabled = true;
				  this->btnBeAuthData->Enabled = true;
				  
				  this->btnChallengeCode->Enabled =true;
				  this->btnCloseDevice->Enabled =true;
				  this->btnDisOnCard->Enabled = true;
				  this->btnExpense->Enabled =true;
				  this->btnGetRandom->Enabled =true;
				  this->btnLogIn->Enabled =true;
				  
				  this->btnOpenDevice->Enabled =true;
				  this->btnRecharge->Enabled =true;
				 
				  
			  }else{
				  this->btnAuth->Enabled = false;
				  
				  this->btnBanlance->Enabled = false;
				  this->btnBeAuthData->Enabled = false;
				  
				  this->btnChallengeCode->Enabled =false;
				  this->btnCloseDevice->Enabled =false;
				  this->btnDisOnCard->Enabled = false;
				  this->btnExpense->Enabled =false;
				  this->btnGetRandom->Enabled =false;
				  this->btnLogIn->Enabled =false;
				  
				  this->btnOpenDevice->Enabled =false;
				  this->btnRecharge->Enabled =false;
				  
				  
			  }

		  }
private: System::Void btnGetRandom_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(bDeviceEnabled){
				lRet = ri->DateTransformer(byGetRandom);
				
			 }
		 }
private: System::Void btnCloseDevice_Click(System::Object^  sender, System::EventArgs^  e) {

			 lRet = ri->ReaderControl(strSelectedReader, CLOSE_READER);
			 if(lRet != SCARD_S_SUCCESS){
				 MessageBox::Show(CLOSE_READER_ERROR_STR + System::Environment::NewLine
					 + "Error Code: 0x" + Convert::ToString(lRet, HEX));
				 bDeviceEnabled = true;
			 }else{
				 bDeviceEnabled = false;
				 Button_Control(DISABLE_ALL_BUTTON);
				 this->btnOpenDevice->Enabled = true;
			 }
		 }

private: System::Void comboBox1_DropDown(System::Object^  sender, System::EventArgs^  e) {

			 if(!bGetReaderList){
				lRet = ri->GetReaderList();
				if(lRet != SCARD_S_SUCCESS){
					ShowErrorDescription(lRet);
					return;
				}else{
					for(int i = 0; i < ri->nReaderCounter; i ++){
						int n = this->comboBox1->FindString(ri->strReaderList[i]);
						if(n == -1){
							this->comboBox1->Items->Add(ri->strReaderList[i]);
						}
					}
				}
				bGetReaderList = true;
			 }else{
				 if(bPlugOut){
					this->comboBox1->Items->Clear();
					bPlugOut = false;
					bGetReaderList = false;
				 }
			 }

		 }



 private: System::Void ShowErrorDescription(LONG ret){
			  LPVOID lpMsgBuf = NULL;
			  DWORD retval = 0;
			  String^ ErrorDescription = gcnew String("");

			  retval = FormatMessage(
				  FORMAT_MESSAGE_ALLOCATE_BUFFER | 
				  FORMAT_MESSAGE_FROM_SYSTEM |
				  FORMAT_MESSAGE_IGNORE_INSERTS,
				  NULL,
				  (DWORD)ret,
				  MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
				  (LPTSTR) &lpMsgBuf,
				  0, NULL );

			  if(!retval){
				  switch (ret){
					case 0x6A82: ErrorDescription = "操作失败";
						break;
					default: 
						break;
				  }
			  }else{
				  ErrorDescription = String((LPTSTR)lpMsgBuf).ToString();
			  }

			  String^ str = String::Format("错误代码： 0x{0, 8:X8}", ret);
			  str += ("\n错误原因： " + ErrorDescription);
			  MessageBox::Show(str);

		  }
};

}

