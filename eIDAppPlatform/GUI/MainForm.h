#pragma once


namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
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
	private: System::Windows::Forms::Button^  btnBanlance;
	private: System::Windows::Forms::TextBox^  textBoxBanlance;
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










	protected: 

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->btnOpenDevice = (gcnew System::Windows::Forms::Button());
			this->btnCloseDevice = (gcnew System::Windows::Forms::Button());
			this->btnBanlance = (gcnew System::Windows::Forms::Button());
			this->textBoxBanlance = (gcnew System::Windows::Forms::TextBox());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPageTest = (gcnew System::Windows::Forms::TabPage());
			this->tabPageeCash = (gcnew System::Windows::Forms::TabPage());
			this->tabPageNewKey = (gcnew System::Windows::Forms::TabPage());
			this->tabPageOTP = (gcnew System::Windows::Forms::TabPage());
			this->tabPageeID = (gcnew System::Windows::Forms::TabPage());
			this->textBoxShow = (gcnew System::Windows::Forms::TextBox());
			this->btnRecharge = (gcnew System::Windows::Forms::Button());
			this->btnExpense = (gcnew System::Windows::Forms::Button());
			this->textBoxRecharge = (gcnew System::Windows::Forms::TextBox());
			this->textBoxExpense = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBoxSrcAccount = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDstAccount = (gcnew System::Windows::Forms::TextBox());
			this->textBoxTransform = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->pictureBoxSrcAccount = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxDstAccount = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxTransform = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBoxAuthCode = (gcnew System::Windows::Forms::PictureBox());
			this->btnChallengeCode = (gcnew System::Windows::Forms::Button());
			this->textBoxChallengeCode = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBoxResponCode = (gcnew System::Windows::Forms::TextBox());
			this->btnLogIn = (gcnew System::Windows::Forms::Button());
			this->pictureBoxOTP = (gcnew System::Windows::Forms::PictureBox());
			this->btnGetRandom = (gcnew System::Windows::Forms::Button());
			this->btnDisOnCard = (gcnew System::Windows::Forms::Button());
			this->btnBeAuthData = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btnAuth = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
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
			this->tabPageOTP->SuspendLayout();
			this->tabPageeID->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxSrcAccount))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxDstAccount))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxTransform))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxAuthCode))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxOTP))->BeginInit();
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
			this->splitContainer1->Panel1->Controls->Add(this->textBoxBanlance);
			this->splitContainer1->Panel1->Controls->Add(this->btnBanlance);
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
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(63, 14);
			this->label1->TabIndex = 0;
			this->label1->Text = L"选择设备";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(76, 9);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(280, 22);
			this->comboBox1->TabIndex = 1;
			// 
			// btnOpenDevice
			// 
			this->btnOpenDevice->Location = System::Drawing::Point(362, 9);
			this->btnOpenDevice->Name = L"btnOpenDevice";
			this->btnOpenDevice->Size = System::Drawing::Size(75, 23);
			this->btnOpenDevice->TabIndex = 2;
			this->btnOpenDevice->Text = L"打开设备";
			this->btnOpenDevice->UseVisualStyleBackColor = true;
			// 
			// btnCloseDevice
			// 
			this->btnCloseDevice->Location = System::Drawing::Point(443, 9);
			this->btnCloseDevice->Name = L"btnCloseDevice";
			this->btnCloseDevice->Size = System::Drawing::Size(75, 23);
			this->btnCloseDevice->TabIndex = 3;
			this->btnCloseDevice->Text = L"关闭设备";
			this->btnCloseDevice->UseVisualStyleBackColor = true;
			// 
			// btnBanlance
			// 
			this->btnBanlance->Location = System::Drawing::Point(554, 9);
			this->btnBanlance->Name = L"btnBanlance";
			this->btnBanlance->Size = System::Drawing::Size(75, 23);
			this->btnBanlance->TabIndex = 4;
			this->btnBanlance->Text = L"卡余额";
			this->btnBanlance->UseVisualStyleBackColor = true;
			// 
			// textBoxBanlance
			// 
			this->textBoxBanlance->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxBanlance->Location = System::Drawing::Point(635, 9);
			this->textBoxBanlance->Name = L"textBoxBanlance";
			this->textBoxBanlance->ReadOnly = true;
			this->textBoxBanlance->Size = System::Drawing::Size(68, 23);
			this->textBoxBanlance->TabIndex = 5;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->tabControl1);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->textBoxShow);
			this->splitContainer2->Panel2->Font = (gcnew System::Drawing::Font(L"宋体", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(134)));
			this->splitContainer2->Size = System::Drawing::Size(711, 440);
			this->splitContainer2->SplitterDistance = 440;
			this->splitContainer2->TabIndex = 0;
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
			this->tabControl1->Size = System::Drawing::Size(434, 437);
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
			this->tabPageTest->Size = System::Drawing::Size(426, 399);
			this->tabPageTest->TabIndex = 0;
			this->tabPageTest->Text = L"卡测试";
			this->tabPageTest->UseVisualStyleBackColor = true;
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
			this->tabPageeCash->Size = System::Drawing::Size(426, 399);
			this->tabPageeCash->TabIndex = 1;
			this->tabPageeCash->Text = L"eCash";
			this->tabPageeCash->UseVisualStyleBackColor = true;
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
			this->tabPageNewKey->Size = System::Drawing::Size(426, 399);
			this->tabPageNewKey->TabIndex = 2;
			this->tabPageNewKey->Text = L"二代Key";
			this->tabPageNewKey->UseVisualStyleBackColor = true;
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
			this->tabPageOTP->Size = System::Drawing::Size(426, 399);
			this->tabPageOTP->TabIndex = 3;
			this->tabPageOTP->Text = L"OTP";
			this->tabPageOTP->UseVisualStyleBackColor = true;
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
			this->tabPageeID->Size = System::Drawing::Size(426, 399);
			this->tabPageeID->TabIndex = 4;
			this->tabPageeID->Text = L"eID认证";
			this->tabPageeID->UseVisualStyleBackColor = true;
			// 
			// textBoxShow
			// 
			this->textBoxShow->Location = System::Drawing::Point(4, 4);
			this->textBoxShow->Multiline = true;
			this->textBoxShow->Name = L"textBoxShow";
			this->textBoxShow->ReadOnly = true;
			this->textBoxShow->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBoxShow->Size = System::Drawing::Size(260, 432);
			this->textBoxShow->TabIndex = 0;
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
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(79, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(49, 14);
			this->label3->TabIndex = 2;
			this->label3->Text = L"源账户";
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
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(79, 133);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 14);
			this->label5->TabIndex = 4;
			this->label5->Text = L"转账金额";
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
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(79, 318);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(49, 14);
			this->label10->TabIndex = 15;
			this->label10->Text = L"认证码";
			// 
			// pictureBoxSrcAccount
			// 
			this->pictureBoxSrcAccount->Location = System::Drawing::Point(172, 217);
			this->pictureBoxSrcAccount->Name = L"pictureBoxSrcAccount";
			this->pictureBoxSrcAccount->Size = System::Drawing::Size(176, 31);
			this->pictureBoxSrcAccount->TabIndex = 16;
			this->pictureBoxSrcAccount->TabStop = false;
			// 
			// pictureBoxDstAccount
			// 
			this->pictureBoxDstAccount->Location = System::Drawing::Point(172, 248);
			this->pictureBoxDstAccount->Name = L"pictureBoxDstAccount";
			this->pictureBoxDstAccount->Size = System::Drawing::Size(176, 31);
			this->pictureBoxDstAccount->TabIndex = 17;
			this->pictureBoxDstAccount->TabStop = false;
			// 
			// pictureBoxTransform
			// 
			this->pictureBoxTransform->Location = System::Drawing::Point(172, 279);
			this->pictureBoxTransform->Name = L"pictureBoxTransform";
			this->pictureBoxTransform->Size = System::Drawing::Size(176, 31);
			this->pictureBoxTransform->TabIndex = 18;
			this->pictureBoxTransform->TabStop = false;
			// 
			// pictureBoxAuthCode
			// 
			this->pictureBoxAuthCode->Location = System::Drawing::Point(172, 310);
			this->pictureBoxAuthCode->Name = L"pictureBoxAuthCode";
			this->pictureBoxAuthCode->Size = System::Drawing::Size(176, 31);
			this->pictureBoxAuthCode->TabIndex = 19;
			this->pictureBoxAuthCode->TabStop = false;
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
			// label11
			// 
			this->label11->Location = System::Drawing::Point(69, 68);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(85, 31);
			this->label11->TabIndex = 12;
			this->label11->Text = L"应答码";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			// btnLogIn
			// 
			this->btnLogIn->Location = System::Drawing::Point(154, 132);
			this->btnLogIn->Name = L"btnLogIn";
			this->btnLogIn->Size = System::Drawing::Size(85, 31);
			this->btnLogIn->TabIndex = 14;
			this->btnLogIn->Text = L"登录";
			this->btnLogIn->UseVisualStyleBackColor = true;
			// 
			// pictureBoxOTP
			// 
			this->pictureBoxOTP->Location = System::Drawing::Point(6, 175);
			this->pictureBoxOTP->Name = L"pictureBoxOTP";
			this->pictureBoxOTP->Size = System::Drawing::Size(414, 218);
			this->pictureBoxOTP->TabIndex = 15;
			this->pictureBoxOTP->TabStop = false;
			// 
			// btnGetRandom
			// 
			this->btnGetRandom->Location = System::Drawing::Point(73, 122);
			this->btnGetRandom->Name = L"btnGetRandom";
			this->btnGetRandom->Size = System::Drawing::Size(119, 154);
			this->btnGetRandom->TabIndex = 4;
			this->btnGetRandom->Text = L"读随机数";
			this->btnGetRandom->UseVisualStyleBackColor = true;
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
			// btnBeAuthData
			// 
			this->btnBeAuthData->Location = System::Drawing::Point(43, 50);
			this->btnBeAuthData->Name = L"btnBeAuthData";
			this->btnBeAuthData->Size = System::Drawing::Size(125, 31);
			this->btnBeAuthData->TabIndex = 6;
			this->btnBeAuthData->Text = L"生成待认证数据";
			this->btnBeAuthData->UseVisualStyleBackColor = true;
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
			// btnAuth
			// 
			this->btnAuth->Location = System::Drawing::Point(153, 111);
			this->btnAuth->Name = L"btnAuth";
			this->btnAuth->Size = System::Drawing::Size(125, 31);
			this->btnAuth->TabIndex = 13;
			this->btnAuth->Text = L"开始认证";
			this->btnAuth->UseVisualStyleBackColor = true;
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
			// label12
			// 
			this->label12->Location = System::Drawing::Point(40, 193);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(128, 31);
			this->label12->TabIndex = 16;
			this->label12->Text = L"认证数据";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
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
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			this->splitContainer2->Panel2->PerformLayout();
			this->splitContainer2->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->tabPageTest->ResumeLayout(false);
			this->tabPageeCash->ResumeLayout(false);
			this->tabPageeCash->PerformLayout();
			this->tabPageNewKey->ResumeLayout(false);
			this->tabPageNewKey->PerformLayout();
			this->tabPageOTP->ResumeLayout(false);
			this->tabPageOTP->PerformLayout();
			this->tabPageeID->ResumeLayout(false);
			this->tabPageeID->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxSrcAccount))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxDstAccount))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxTransform))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxAuthCode))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBoxOTP))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}

