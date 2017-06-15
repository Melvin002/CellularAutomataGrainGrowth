#pragma once
#include <vector>
#include <cmath>
#include <algorithm>
#include "Point2d.h"
#include <chrono>

namespace naiwnyRozrostZiaren {

	using namespace System;
	using namespace System::Threading;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	enum NeighborhoodType {
		VonNeumann,
		Moore,
		HexagonalLeft,
		HexagonalRight,
		HexagonalRandom,
		PentagonalRandom
	};
	enum NucleiGenerationType {
		RandomSpaced,
		Evenly,
		RadiusSpaced
	};
	const double CRITICAL_DENSITY_OF_DISLOCATIONS = 4.21584e12;
	const double A = 8.6711e13;
	const double B = 9.41;
	const double TIME_STEP = 0.001;
	
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		delegate void FormDelegate();

		static Random^ rnd = gcnew Random();
		NeighborhoodType neighType = Moore;
		NucleiGenerationType generationType = RandomSpaced;

		bool matrixChoice = true;

		Bitmap^ pBmp;
		Graphics^ g;

		Pen^ penBk;
		
		int k = 100;

		double currentTimeStep = 0.0;

		int delayCoefficient = 5;

		bool breakLoop = false;

		bool wrapEdges = false;
		array<array<Point2d^>^>^ matrixA;
		array<array<Point2d^>^>^ matrixB;

		int height, width;
		private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;
		private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::GroupBox^  groupBox7;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::TextBox^  textBox6;
			 double criticalDensity;

	public:
		MyForm(void)
		{
			InitializeComponent();
			penBk = gcnew Pen(Color::FromArgb(122,0,0,0), 1);
			pBmp = gcnew Bitmap(603, 603);
			g = Graphics::FromImage(pBmp);
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:

	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::RadioButton^  radioButton5;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TrackBar^  trackBar2;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::GroupBox^  groupBox6;




	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  groupBox4;

	private: System::Windows::Forms::RadioButton^  radioButton14;
	private: System::Windows::Forms::RadioButton^  radioButton13;
	private: System::Windows::Forms::RadioButton^  radioButton12;
	private: System::Windows::Forms::RadioButton^  radioButton11;
	private: System::Windows::Forms::RadioButton^  radioButton10;
	private: System::Windows::Forms::RadioButton^  radioButton9;
	private: System::Windows::Forms::RadioButton^  radioButton8;
	private: System::Windows::Forms::RadioButton^  radioButton7;
	private: System::Windows::Forms::RadioButton^  radioButton6;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;












	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton12 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton14 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton13 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton11 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton10 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton9 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton8 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton7 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->button15 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			this->groupBox6->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Enabled = false;
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(603, 603);
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->button9);
			this->groupBox1->Controls->Add(this->button8);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Location = System::Drawing::Point(621, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 77);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"GridSize";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(26, 47);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(84, 17);
			this->checkBox1->TabIndex = 13;
			this->checkBox1->Text = L"Wrap edges";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(26, 19);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(30, 22);
			this->button9->TabIndex = 5;
			this->button9->Text = L"<";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(148, 19);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(30, 22);
			this->button8->TabIndex = 4;
			this->button8->Text = L">";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(55, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(94, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"100";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->radioButton5);
			this->groupBox3->Controls->Add(this->radioButton4);
			this->groupBox3->Controls->Add(this->radioButton3);
			this->groupBox3->Controls->Add(this->radioButton2);
			this->groupBox3->Controls->Add(this->radioButton1);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Controls->Add(this->button2);
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Location = System::Drawing::Point(621, 95);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(200, 72);
			this->groupBox3->TabIndex = 15;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Number Of Iterations";
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(102, 19);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(83, 17);
			this->radioButton5->TabIndex = 8;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Infinite Loop";
			this->radioButton5->UseVisualStyleBackColor = true;
			this->radioButton5->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton5_CheckedChanged);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(151, 47);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(43, 17);
			this->radioButton4->TabIndex = 7;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"100";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton4_CheckedChanged);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(92, 47);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(37, 17);
			this->radioButton3->TabIndex = 6;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"10";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(43, 47);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(31, 17);
			this->radioButton2->TabIndex = 5;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"2";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(6, 47);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(31, 17);
			this->radioButton1->TabIndex = 4;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"1";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(65, 19);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(20, 22);
			this->button3->TabIndex = 2;
			this->button3->Text = L">";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 19);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(20, 22);
			this->button2->TabIndex = 1;
			this->button2->Text = L"<";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(26, 20);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(39, 20);
			this->textBox2->TabIndex = 0;
			this->textBox2->Text = L"50";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->trackBar2);
			this->groupBox2->Location = System::Drawing::Point(827, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(105, 155);
			this->groupBox2->TabIndex = 16;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Speed";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(60, 19);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"slow";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(60, 130);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(24, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"fast";
			// 
			// trackBar2
			// 
			this->trackBar2->Location = System::Drawing::Point(11, 15);
			this->trackBar2->Maximum = 70;
			this->trackBar2->Minimum = 5;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Orientation = System::Windows::Forms::Orientation::Vertical;
			this->trackBar2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->trackBar2->Size = System::Drawing::Size(45, 128);
			this->trackBar2->SmallChange = 5;
			this->trackBar2->TabIndex = 5;
			this->trackBar2->TickFrequency = 5;
			this->trackBar2->Value = 5;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// button6
			// 
			this->button6->Enabled = false;
			this->button6->Location = System::Drawing::Point(635, 498);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(90, 51);
			this->button6->TabIndex = 19;
			this->button6->Text = L"Clear";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(827, 498);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(90, 51);
			this->button5->TabIndex = 18;
			this->button5->Text = L"Stop";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(119)), static_cast<System::Int32>(static_cast<System::Byte>(221)),
				static_cast<System::Int32>(static_cast<System::Byte>(119)));
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(731, 498);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(90, 51);
			this->button4->TabIndex = 17;
			this->button4->Text = L"Start";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->groupBox7);
			this->groupBox6->Controls->Add(this->panel3);
			this->groupBox6->Controls->Add(this->panel2);
			this->groupBox6->Controls->Add(this->panel1);
			this->groupBox6->Controls->Add(this->groupBox5);
			this->groupBox6->Controls->Add(this->button1);
			this->groupBox6->Location = System::Drawing::Point(623, 266);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(311, 208);
			this->groupBox6->TabIndex = 20;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Nuclei generation";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->button16);
			this->groupBox7->Controls->Add(this->button17);
			this->groupBox7->Controls->Add(this->textBox6);
			this->groupBox7->Location = System::Drawing::Point(6, 76);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(87, 66);
			this->groupBox7->TabIndex = 8;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"k coefficent";
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(66, 32);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(20, 22);
			this->button16->TabIndex = 5;
			this->button16->Text = L">";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(7, 32);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(20, 22);
			this->button17->TabIndex = 4;
			this->button17->Text = L"<";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(27, 33);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(39, 20);
			this->textBox6->TabIndex = 3;
			this->textBox6->Text = L"100";
			this->textBox6->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::Control;
			this->panel3->Controls->Add(this->button13);
			this->panel3->Controls->Add(this->button14);
			this->panel3->Controls->Add(this->textBox5);
			this->panel3->Controls->Add(this->label5);
			this->panel3->Location = System::Drawing::Point(104, 76);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(200, 66);
			this->panel3->TabIndex = 7;
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(61, 33);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(20, 22);
			this->button13->TabIndex = 5;
			this->button13->Text = L"<";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(128, 33);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(20, 22);
			this->button14->TabIndex = 4;
			this->button14->Text = L">";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// textBox5
			// 
			this->textBox5->Enabled = false;
			this->textBox5->Location = System::Drawing::Point(79, 34);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(52, 20);
			this->textBox5->TabIndex = 3;
			this->textBox5->Text = L"0";
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(35, 18);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(134, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Nucleis density as  percent";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::Control;
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->button10);
			this->panel2->Controls->Add(this->button7);
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Location = System::Drawing::Point(104, 76);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 66);
			this->panel2->TabIndex = 7;
			this->panel2->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(40, 18);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(132, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Number of nucleis in a row";
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(61, 33);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(20, 22);
			this->button10->TabIndex = 2;
			this->button10->Text = L"<";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(128, 33);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(20, 22);
			this->button7->TabIndex = 1;
			this->button7->Text = L">";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// textBox4
			// 
			this->textBox4->Enabled = false;
			this->textBox4->Location = System::Drawing::Point(79, 34);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(52, 20);
			this->textBox4->TabIndex = 0;
			this->textBox4->Text = L"0";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Control;
			this->panel1->Controls->Add(this->button11);
			this->panel1->Controls->Add(this->button12);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(104, 76);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 66);
			this->panel1->TabIndex = 6;
			this->panel1->Visible = false;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(59, 34);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(20, 22);
			this->button11->TabIndex = 6;
			this->button11->Text = L"<";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(126, 34);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(20, 22);
			this->button12->TabIndex = 5;
			this->button12->Text = L">";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// textBox3
			// 
			this->textBox3->Enabled = false;
			this->textBox3->Location = System::Drawing::Point(77, 35);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(52, 20);
			this->textBox3->TabIndex = 3;
			this->textBox3->Text = L"0";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 6);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(129, 26);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Minimum distance \r\nbetween nucleis as radius";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->radioButton12);
			this->groupBox5->Controls->Add(this->radioButton14);
			this->groupBox5->Controls->Add(this->radioButton13);
			this->groupBox5->Location = System::Drawing::Point(105, 19);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(200, 51);
			this->groupBox5->TabIndex = 5;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Type";
			// 
			// radioButton12
			// 
			this->radioButton12->AutoSize = true;
			this->radioButton12->Checked = true;
			this->radioButton12->Location = System::Drawing::Point(6, 19);
			this->radioButton12->Name = L"radioButton12";
			this->radioButton12->Size = System::Drawing::Size(65, 17);
			this->radioButton12->TabIndex = 2;
			this->radioButton12->TabStop = true;
			this->radioButton12->Text = L"Random";
			this->radioButton12->UseVisualStyleBackColor = true;
			this->radioButton12->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton12_CheckedChanged);
			// 
			// radioButton14
			// 
			this->radioButton14->AutoSize = true;
			this->radioButton14->Location = System::Drawing::Point(136, 19);
			this->radioButton14->Name = L"radioButton14";
			this->radioButton14->Size = System::Drawing::Size(58, 17);
			this->radioButton14->TabIndex = 4;
			this->radioButton14->Text = L"Radius";
			this->radioButton14->UseVisualStyleBackColor = true;
			this->radioButton14->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton14_CheckedChanged);
			// 
			// radioButton13
			// 
			this->radioButton13->AutoSize = true;
			this->radioButton13->Location = System::Drawing::Point(73, 19);
			this->radioButton13->Name = L"radioButton13";
			this->radioButton13->Size = System::Drawing::Size(57, 17);
			this->radioButton13->TabIndex = 3;
			this->radioButton13->Text = L"Evenly";
			this->radioButton13->UseVisualStyleBackColor = true;
			this->radioButton13->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton13_CheckedChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 19);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(90, 51);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Generate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->radioButton11);
			this->groupBox4->Controls->Add(this->radioButton10);
			this->groupBox4->Controls->Add(this->radioButton9);
			this->groupBox4->Controls->Add(this->radioButton8);
			this->groupBox4->Controls->Add(this->radioButton7);
			this->groupBox4->Controls->Add(this->radioButton6);
			this->groupBox4->Location = System::Drawing::Point(623, 173);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(309, 87);
			this->groupBox4->TabIndex = 21;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Neighborhood type";
			// 
			// radioButton11
			// 
			this->radioButton11->AutoSize = true;
			this->radioButton11->Location = System::Drawing::Point(137, 64);
			this->radioButton11->Name = L"radioButton11";
			this->radioButton11->Size = System::Drawing::Size(122, 17);
			this->radioButton11->TabIndex = 11;
			this->radioButton11->Text = L"Pentagonal Random";
			this->radioButton11->UseVisualStyleBackColor = true;
			this->radioButton11->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton11_CheckedChanged);
			// 
			// radioButton10
			// 
			this->radioButton10->AutoSize = true;
			this->radioButton10->Location = System::Drawing::Point(137, 41);
			this->radioButton10->Name = L"radioButton10";
			this->radioButton10->Size = System::Drawing::Size(97, 17);
			this->radioButton10->TabIndex = 10;
			this->radioButton10->Text = L"Hexagonal Left";
			this->radioButton10->UseVisualStyleBackColor = true;
			this->radioButton10->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton10_CheckedChanged);
			// 
			// radioButton9
			// 
			this->radioButton9->AutoSize = true;
			this->radioButton9->Location = System::Drawing::Point(137, 17);
			this->radioButton9->Name = L"radioButton9";
			this->radioButton9->Size = System::Drawing::Size(104, 17);
			this->radioButton9->TabIndex = 9;
			this->radioButton9->Text = L"Hexagonal Right";
			this->radioButton9->UseVisualStyleBackColor = true;
			this->radioButton9->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton9_CheckedChanged);
			// 
			// radioButton8
			// 
			this->radioButton8->AutoSize = true;
			this->radioButton8->Location = System::Drawing::Point(6, 64);
			this->radioButton8->Name = L"radioButton8";
			this->radioButton8->Size = System::Drawing::Size(119, 17);
			this->radioButton8->TabIndex = 8;
			this->radioButton8->Text = L"Hexagonal Random\r\n";
			this->radioButton8->UseVisualStyleBackColor = true;
			this->radioButton8->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton8_CheckedChanged);
			// 
			// radioButton7
			// 
			this->radioButton7->AutoSize = true;
			this->radioButton7->Checked = true;
			this->radioButton7->Location = System::Drawing::Point(6, 41);
			this->radioButton7->Name = L"radioButton7";
			this->radioButton7->Size = System::Drawing::Size(55, 17);
			this->radioButton7->TabIndex = 7;
			this->radioButton7->TabStop = true;
			this->radioButton7->Text = L"Moore";
			this->radioButton7->UseVisualStyleBackColor = true;
			this->radioButton7->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton7_CheckedChanged);
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(6, 17);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(87, 17);
			this->radioButton6->TabIndex = 6;
			this->radioButton6->Text = L"Von Neuman";
			this->radioButton6->UseVisualStyleBackColor = true;
			this->radioButton6->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton6_CheckedChanged);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker2_DoWork);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(635, 555);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(90, 51);
			this->button15->TabIndex = 22;
			this->button15->Text = L"Recrystalization";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(939, 620);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox6);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			this->groupBox6->ResumeLayout(false);
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		private:
			void stopButton() {
				if (this->button5->InvokeRequired) {
					FormDelegate^ d = gcnew FormDelegate(this, &MyForm::stopButton);
					this->Invoke(d, gcnew array<Object^> {});
				}
				else {
					button4->Enabled = true;
					button5->Enabled = false;
					groupBox1->Enabled = true;
					groupBox3->Enabled = true;
					groupBox4->Enabled = true;
					groupBox5->Enabled = true;
					groupBox6->Enabled = true;
					pictureBox1->Enabled = true;
					button6->Enabled = true;
					button15->Enabled = true;
				}
			}
			void stopRecrystallization() {
				if (this->button4->InvokeRequired) {
					FormDelegate^ d = gcnew FormDelegate(this, &MyForm::stopButton);
					this->Invoke(d, gcnew array<Object^> {});
				}
				else {
					button4->Enabled = true;
					button6->Enabled = true;
					groupBox1->Enabled = true;
					groupBox3->Enabled = true;
					groupBox4->Enabled = true;
					groupBox5->Enabled = true;
					groupBox6->Enabled = true;
					pictureBox1->Enabled = true;
					button15->Enabled = true;
				}
			}
			
		static int myrandom(int i) {
			return rnd->Next(i);
		}
		int getMostCommonNeighbor(array<array<Point2d^>^>^ matrix, int y, int x, NeighborhoodType neighborhoodType) {
			std::vector<unsigned int> neighborsIds;
			neighborsIds.reserve(8);

			switch (neighborhoodType) {
			case Moore:
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (j != 0 || 0 != i) {
							if (matrix[y + i][x + j]->color != 0) {
								unsigned int colorIntValue = matrix[y + i][x + j]->color;
								neighborsIds.push_back(colorIntValue);
							}
						}

					}
				}
				break;
			case VonNeumann:
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (!(j != 0 && 0 != i) && (j != 0 || 0 != i)) {
							if (matrix[y + i][x + j]->color != 0) {
								unsigned int colorIntValue = matrix[y + i][x + j]->color;
								neighborsIds.push_back(colorIntValue);
							}
						}

					}
				}
				break;
			case HexagonalLeft:
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (!(i + j) == 0) {
							if (matrix[y + i][x + j]->color != 0) {
								unsigned int colorIntValue = matrix[y + i][x + j]->color;
								neighborsIds.push_back(colorIntValue);
							}
						}
					}
				}
				break;
			case HexagonalRight:
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (i != j) {
							if (matrix[y + i][x + j]->color != 0) {
								unsigned int colorIntValue = matrix[y + i][x + j]->color;
								neighborsIds.push_back(colorIntValue);
							}
						}
					}
				}
				break;
			case HexagonalRandom:
			{
				bool randomArrayHexagonal[8] = {true, true, true, true, true, false, false, false};
				std::random_shuffle(&randomArrayHexagonal[0], &randomArrayHexagonal[8], myrandom);
				int counter = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (j != 0 || 0 != i) {
							if ((matrix[y + i][x + j]->color != 0) && randomArrayHexagonal[counter]) {
								unsigned int colorIntValue = matrix[y + i][x + j]->color;
								neighborsIds.push_back(colorIntValue);
							}
							counter++;
						}
					}
				}
			}
				break;
			case PentagonalRandom:
			{
				bool randomArrayPentagonal[8] = { true, true, true, true, false, false, false, false };
				std::random_shuffle(&randomArrayPentagonal[0], &randomArrayPentagonal[8], myrandom);
				int counter = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (j != 0 || 0 != i) {
							if ((matrix[y + i][x + j]->color != 0) && randomArrayPentagonal[counter]) {
								unsigned int colorIntValue = matrix[y + i][x + j]->color;
								neighborsIds.push_back(colorIntValue);
							}
							counter++;
						}
					}
				}
			}
				break;
			}
			int mostCommonNeighbor = 0;
			if (neighborsIds.size() > 0) {
				int highestCounter = 0, currentCounter = 0;
				unsigned int previousVal;
				int size = neighborsIds.size();
				std::sort(neighborsIds.begin(), neighborsIds.end());
				mostCommonNeighbor = previousVal = neighborsIds[0];

				for (int i = 1; i < size - 1; i++) {
					if (previousVal == (neighborsIds[i])) {
						currentCounter++;
					}
					else {
						currentCounter = 0;
					}
					if (currentCounter > highestCounter) {
						highestCounter = currentCounter;
						mostCommonNeighbor = neighborsIds[i];
					}

				}
			}
			
			return mostCommonNeighbor;
		}
		PointSimple didNeighborRecrystalized(array<array<Point2d^>^>^ matrix, int y, int x, NeighborhoodType neighborhoodType) {

			switch (neighborhoodType) {
			case Moore:
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (j != 0 || 0 != i) {
							if (matrix[y + i][x + j]->isRecrystalized)
								return PointSimple(y + i, x + j);
						}
					}
				}
				break;
			case VonNeumann:
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (!(j != 0 && 0 != i) && (j != 0 || 0 != i)) {
							if (matrix[y + i][x + j]->isRecrystalized) {
								return PointSimple(y + i, x + j);
							}
						}

					}
				}
				break;
			case HexagonalLeft:
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (!(i + j) == 0) {
							if (matrix[y + i][x + j]->isRecrystalized)
								return PointSimple(y + i, x + j);
						}
					}
				}
				break;
			case HexagonalRight:
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (i != j) {
							if (matrix[y + i][x + j]->isRecrystalized)
								return PointSimple(y + i, x + j);
						}
					}
				}
				break;
			case HexagonalRandom:
			{
				bool randomArrayHexagonal[8] = { true, true, true, true, true, false, false, false };
				std::random_shuffle(&randomArrayHexagonal[0], &randomArrayHexagonal[8], myrandom);
				int counter = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (j != 0 || 0 != i) {
							if (randomArrayHexagonal[counter]) {
								if (matrix[y + i][x + j]->isRecrystalized)
									return PointSimple(y + i, x + j);
							}
							counter++;
						}
					}
				}
			}
			break;
			case PentagonalRandom:
			{
				bool randomArrayPentagonal[8] = { true, true, true, true, false, false, false, false };
				std::random_shuffle(&randomArrayPentagonal[0], &randomArrayPentagonal[8], myrandom);
				int counter = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (j != 0 || 0 != i) {
							if (randomArrayPentagonal[counter]) {
								if (matrix[y + i][x + j]->isRecrystalized)
									return PointSimple(y + i, x + j);
							}
							counter++;
						}
					}
				}
			}
			break;
			}
			return PointSimple(false);
		}
		unsigned int getRandomColorAsInt() {
			unsigned int randomIntColor = 4278190080 + rnd->Next(16777215); //full opaque + random first 24 bytes
			return randomIntColor;
		}
		double getDensity(double t) {
			return A / B + (1 - A / B) * exp(-B*t);
		}
		void nucleiRandomGeneration(array<array<Point2d^>^>^ % matrix, NucleiGenerationType type) {
			switch (type) {
			case RandomSpaced:
			{
				double percent = Convert::ToDouble(textBox5->Text);
				int numberOfCells = (width - 2) * (width - 2) * percent / 100;
				while (numberOfCells > 0) {
					int x, y;
					do {
						y = rnd->Next(1, width - 1);
						x = rnd->Next(1, width - 1);
					} while (matrix[y][x]->color != 0);
					matrix[y][x]->color = getRandomColorAsInt();
					numberOfCells--;
				}
			}
				break;
			case Evenly:
			{
				int boardWidth = width - 2;
				int numberOfNucleisInRow = Convert::ToInt32(textBox4->Text);
				int spaceLength = boardWidth / numberOfNucleisInRow;
				int offset = (boardWidth - (numberOfNucleisInRow - 1) * spaceLength) / 2;
				for (int i = 0; i < numberOfNucleisInRow; i++) {
					for (int j = 0; j < numberOfNucleisInRow; j++) {
						matrix[1 + offset + i * spaceLength][1 + offset + j * spaceLength]->color = getRandomColorAsInt();
					}
				}
				
			}
				break;
			case RadiusSpaced:
			{
				int radius = Convert::ToInt32(textBox3->Text) + 1;
				int numberOfCells = (width - 2) * (width - 2) * 5 / 100;
				while (numberOfCells > 0) {
					int x, y, breakCounter;
					y = rnd->Next(radius, width - 1 - radius);
					x = rnd->Next(radius, width - 1 - radius);
					matrix[y][x]->color = getRandomColorAsInt();
					numberOfCells--;

					for (int i = -radius; i <= radius; i++) {
						for (int j = -radius; j <= radius; j++) {
							if (j != 0 || 0 != i) {
								int d = round(sqrt((i)*(i)+(j)*(j)));
								if (d < radius)
									if((i + y) > 0 && (i + y) < (width - 1) && (j + x) > 0 && (j + x) < (width - 1))
										matrix[i + y][j + x]->color = 1;
							}
						}
					}
					for (int i = 1; i < (height - 1); i++) {
						for (int j = 1; j < (width - 1); j++) {
							if (matrix[i][j]->color == 1) {
								matrix[i][j]->color = 0;
							}
						}
					}
				}
			}
				break;
			}
		}
		void drawMatrix(array<array<Point2d^>^>^ % matrix) {
			g->Clear(Color::White);

			//panel is 600x600px
			int squareSideLength = 600 / (width - 2);
			
			SolidBrush^ brush = gcnew SolidBrush(Color::Black);
			for (int i = 1; i < (height - 1); i++) {
				for (int j = 1; j < (width - 1); j++) {
					if (matrix[i][j]->color != 0) {
						brush->Color = Color::FromArgb(matrix[i][j]->color);
						g->FillRectangle(brush, Rectangle((j - 1) * squareSideLength, (i - 1) * squareSideLength, squareSideLength, squareSideLength));
					}
				}
			}
			for (int y = 0; y < (height - 1); ++y)
			{
				g->DrawLine(penBk, 0, y * squareSideLength, (height - 2) * squareSideLength, y * squareSideLength);
			}

			for (int x = 0; x < (width - 1); ++x)
			{
				g->DrawLine(penBk, x * squareSideLength, 0, x * squareSideLength, (width - 2) * squareSideLength);
			}
			pictureBox1->Image = pBmp;
		}
		void wrapEdgesOnMatrix(array<array<Point2d^>^>^% matrix) {
			//top
			for (int j = 1; j < (width - 1); j++) {
				matrix[0][j] = matrix[height - 2][j];
			}
			//bottom
			for (int j = 1; j < (width - 1); j++) {
				matrix[height - 1][j] = matrix[1][j];
			}
			//left
			for (int i = 1; i < (height - 1); i++) {
				matrix[i][0] = matrix[i][width - 2];
			}
			//right
			for (int i = 1; i < (height - 1); i++) {
				matrix[i][width - 1] = matrix[i][1];
			}
			//corners

			//left top
			matrix[0][0] = matrix[height - 2][width - 2];
			//left bottom
			matrix[height - 1][0] = matrix[1][width - 2];
			//right top
			matrix[0][width - 1] = matrix[height - 2][1];
			//right bottom
			matrix[height - 1][width - 1] = matrix[1][1];
		}
		bool isCellOnBorder(array<array<Point2d^>^>^% matrix, int y, int x, NeighborhoodType neighborhoodType) {

			switch (neighborhoodType) {
			case Moore:
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (j != 0 || 0 != i) {
							if (matrix[y][x]->color != matrix[y + i][x + j]->color && matrix[y + i][x + j]->color != 0)
								return true;
						}
					}
				}
				break;
			case VonNeumann:
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (!(j != 0 && 0 != i) && (j != 0 || 0 != i)) {
							if (matrix[y][x]->color != matrix[y + i][x + j]->color && matrix[y + i][x + j]->color != 0)
								return true;
						}

					}
				}
				break;
			case HexagonalLeft:
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (!(i + j) == 0) {
							if (matrix[y][x]->color != matrix[y + i][x + j]->color && matrix[y + i][x + j]->color != 0)
								return true;
						}
					}
				}
				break;
			case HexagonalRight:
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (i != j) {
							if (matrix[y][x]->color != matrix[y + i][x + j]->color && matrix[y + i][x + j]->color != 0)
								return true;
						}
					}
				}
				break;
			case HexagonalRandom:
			{
				bool randomArrayHexagonal[8] = { true, true, true, true, true, false, false, false };
				std::random_shuffle(&randomArrayHexagonal[0], &randomArrayHexagonal[8], myrandom);
				int counter = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (j != 0 || 0 != i) {
							if (randomArrayHexagonal[counter]) {
								if (matrix[y][x]->color != matrix[y + i][x + j]->color && matrix[y + i][x + j]->color != 0)
									return true;
							}
							counter++;
						}
					}
				}
			}
			break;
			case PentagonalRandom:
			{
				bool randomArrayPentagonal[8] = { true, true, true, true, false, false, false, false };
				std::random_shuffle(&randomArrayPentagonal[0], &randomArrayPentagonal[8], myrandom);
				int counter = 0;
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (j != 0 || 0 != i) {
							if (randomArrayPentagonal[counter]) {
								if (matrix[y][x]->color != matrix[y + i][x + j]->color && matrix[y + i][x + j]->color != 0)
									return true;
							}
							counter++;
						}
					}
				}
			}
			break;
			}
			return false;
		}
		void dislocationCannon(array<array<Point2d^>^>^% matrix, double dislocationPool, double dislocationCell) {
			Random^ rnd = gcnew Random();
			int x, y;
			double remainder = 0;
			for (int i = 0; i < ((height - 1)*(width - 1)); i++) {
				x = rnd->Next(1, height - 1);
				y = rnd->Next(1, height - 1);
				if (isCellOnBorder(matrix, y, x, neighType)) {
					matrix[y][x]->dislocationDensity += 0.8 * dislocationCell;
					remainder += 0.2 * dislocationCell;
				}
				else {
					matrix[y][x]->dislocationDensity += 0.2 * dislocationCell;
					remainder += 0.8 * dislocationCell;
				}
			}
			for (int j = 0; j < k; j++) {
				do {
					x = rnd->Next(1, height - 1);
					y = rnd->Next(1, height - 1);
				} while (!isCellOnBorder(matrix, y, x, neighType));
				matrix[y][x]->dislocationDensity += remainder / k;
			}
		}
		void applyRules(array<array<Point2d^>^>^% matrixFrom, array<array<Point2d^>^>^% matrixTo) {
			int counter = 0;
			for (int i = 1; i < (height - 1); i++) {
				for (int j = 1; j < (width - 1); j++) {
					if (matrixFrom[i][j]->color == 0) {
						int temp = getMostCommonNeighbor(matrixFrom, i, j, neighType);
						matrixTo[i][j]->color = temp;
						counter++;
					}
					else {
						matrixTo[i][j]->color = matrixFrom[i][j]->color;
					}
				}
			}
			if (counter == 0)
				breakLoop = true;
		}
		void fillWithZeroes(array<array<Point2d^>^>^% matrix) {
			for (int i = 1; i < (height - 1); i++) {
				for (int j = 1; j < (width - 1); j++) {
					matrix[i][j]->Clear();
				}
			}
		}
		void recrystallizationRules(array<array<Point2d^>^>^% matrixFrom, array<array<Point2d^>^>^% matrixTo, double criticalDensity) {
			int counter = 0;
			for (int i = 1; i < (height - 1); i++) {
				for (int j = 1; j < (width - 1); j++) {
					if (matrixFrom[i][j]->isRecrystalized == false) {
						counter++;
					}
					PointSimple p = PointSimple(didNeighborRecrystalized(matrixFrom, i, j, neighType));
					if (p.didRecrystallized && matrixFrom[i][j]->isRecrystalized == false) { 
						matrixTo[i][j]->color = matrixFrom[p.y][p.x]->color;
						matrixTo[i][j]->isRecrystalized = true;
						matrixTo[i][j]->dislocationDensity = 0;
					}
					else if (matrixFrom[i][j]->dislocationDensity >= criticalDensity && matrixFrom[i][j]->isRecrystalized == false) {
						matrixTo[i][j]->color = getRandomColorAsInt();
						matrixTo[i][j]->isRecrystalized = true;
						matrixTo[i][j]->dislocationDensity = 0;
					}
					else if(matrixFrom[i][j]->isRecrystalized == true){
						matrixTo[i][j] = matrixFrom[i][j];
					}
				}
			}
			if (counter == 0)
				breakLoop = true;
		}
private: System::Void radioButton12_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	generationType = RandomSpaced;
	if (panel3->Visible)
		panel3->Visible = false;
	else
		panel3->Visible = true;
}
private: System::Void radioButton13_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	generationType = Evenly;
	if (panel2->Visible)
		panel2->Visible = false;
	else
		panel2->Visible = true;
}
private: System::Void radioButton14_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	generationType = RadiusSpaced;
	if (panel1->Visible)
		panel1->Visible = false;
	else
		panel1->Visible = true;
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	//distance
	width = height = Convert::ToInt32(textBox1->Text) + 2;
	criticalDensity = CRITICAL_DENSITY_OF_DISLOCATIONS / static_cast<double>((height - 1)*(width - 1));
	int value = Convert::ToInt32(textBox4->Text);
	int widthForGeneration = Convert::ToInt32(textBox1->Text);
	do {
		if (value > 1)
			value--;
	} while (widthForGeneration % value != 0);
	textBox4->Text = value.ToString();
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	width = height = Convert::ToInt32(textBox1->Text) + 2;
	criticalDensity = CRITICAL_DENSITY_OF_DISLOCATIONS / static_cast<double>((height - 1)*(width - 1));
	int value = Convert::ToInt32(textBox4->Text);
	int widthForGeneration = Convert::ToInt32(textBox1->Text);
	do {
		if (value < widthForGeneration)
			value++;
	} while (widthForGeneration % value != 0);
	textBox4->Text = value.ToString();
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	//radius
	int value = Convert::ToInt32(textBox3->Text);
	if (value > 0)
		value--;
	textBox3->Text = value.ToString();
}
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
	int value = Convert::ToInt32(textBox3->Text);
		value++;
		textBox3->Text = value.ToString();
}
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
	//density percent
	double value = Convert::ToDouble(textBox5->Text);
	if (value > 0)
		value -= 0.5;
	textBox5->Text = value.ToString();
}
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
	double value = Convert::ToDouble(textBox5->Text);
	value += 0.5;
	textBox5->Text = value.ToString();
}
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	int loopLimit = Convert::ToInt32(textBox2->Text);
	for (int i = 0; i < loopLimit; i++) {

		auto start = std::chrono::system_clock::now();

		if (breakLoop) {
			breakLoop = !breakLoop;
			break;
		}

		if (matrixChoice) {
			if (wrapEdges)
				wrapEdgesOnMatrix(matrixA);
			applyRules(matrixA, matrixB);
			drawMatrix(matrixB);
			matrixChoice = !matrixChoice;
		}
		else {
			if (wrapEdges)
				wrapEdgesOnMatrix(matrixB);
			applyRules(matrixB, matrixA);
			drawMatrix(matrixA);
			matrixChoice = !matrixChoice;
		}
		auto elapsed = std::chrono::system_clock::now() - start;
		int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
		if ((delayCoefficient * 5) - milliseconds > 0) {
			Thread::Sleep((delayCoefficient * 5) - milliseconds);
		}
		else {
			Thread::Sleep((delayCoefficient * 5));
		}
	}
	stopButton();
}
	double map(double x, double in_min, double in_max, double out_min, double out_max)
		 {
			 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
		 }
private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	int loopLimit = Convert::ToInt32(textBox2->Text);

	double densityPool = getDensity(currentTimeStep + TIME_STEP) - getDensity(currentTimeStep);
	double densityCell = densityPool / ((height - 1)*(width - 1));

	for (int i = 0; i < loopLimit; i++) {
		auto start = std::chrono::system_clock::now();

		if (breakLoop) {
			breakLoop = !breakLoop;
			break;
		}
		
		if (matrixChoice) {
			if (wrapEdges)
				wrapEdgesOnMatrix(matrixA);
			dislocationCannon(matrixA, densityPool, densityCell);
			recrystallizationRules(matrixA, matrixB, criticalDensity);
			drawMatrix(matrixB);
			matrixChoice = !matrixChoice;
		}
		else {
			if (wrapEdges)
				wrapEdgesOnMatrix(matrixB);
			dislocationCannon(matrixA, densityPool, densityCell);
			recrystallizationRules(matrixB, matrixA, criticalDensity);
			drawMatrix(matrixA);
			matrixChoice = !matrixChoice;
		}
		auto elapsed = std::chrono::system_clock::now() - start;
		int milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
		if ((delayCoefficient * 5) - milliseconds > 0) {
			Thread::Sleep((delayCoefficient * 5) - milliseconds);
		}
		else {
			Thread::Sleep((delayCoefficient * 5));
		}
		currentTimeStep += TIME_STEP;
	}
	stopRecrystallization();
}
private: System::Void radioButton6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	neighType = VonNeumann;
}
private: System::Void radioButton7_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	neighType = Moore;
}
private: System::Void radioButton8_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	neighType = HexagonalRandom;
}
private: System::Void radioButton9_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	neighType = HexagonalRight;
}
private: System::Void radioButton10_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	neighType = HexagonalLeft;
}
private: System::Void radioButton11_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	neighType = PentagonalRandom;
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {//generate button
	button4->Enabled = true;
	button6->Enabled = true;
	if (checkBox1->Checked)
		wrapEdges = true;
	else
		wrapEdges = false;

	width = height = Convert::ToInt32(textBox1->Text) + 2;
	criticalDensity = CRITICAL_DENSITY_OF_DISLOCATIONS / static_cast<double>((height - 1)*(width - 1));
	matrixA = gcnew array<array<Point2d^>^>(height);

	for (int i = 0; i < height; i++)
	{
		matrixA[i] = gcnew array<Point2d^>(width);
		for (int j = 0; j < height; j++) {
			matrixA[i][j] = gcnew Point2d;
		}
	}
	matrixB = gcnew array<array<Point2d^>^>(height);

	for (int i = 0; i < height; i++)
	{
		matrixB[i] = gcnew array<Point2d^>(width);
		for (int j = 0; j < height; j++) {
			matrixB[i][j] = gcnew Point2d;
		}
	}
	if (matrixChoice) {
		nucleiRandomGeneration(matrixA, generationType);
		drawMatrix(matrixA);
	}
	else {
		nucleiRandomGeneration(matrixB, generationType);
		drawMatrix(matrixB);
	}
	pictureBox1->Enabled = true;
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	MouseEventArgs^ me = (MouseEventArgs^) e;
	Point coordinates = me->Location;
	//603px - width and heigth of picturebox
	int divisionFactor = 603 / (height - 2);
	if (matrixChoice) {
		matrixA[(coordinates.Y / divisionFactor) + 1][(coordinates.X / divisionFactor) + 1]->color = getRandomColorAsInt();
		//matrixA[(coordinates.Y / divisionFactor) + 1][(coordinates.X / divisionFactor) + 1]->isRecrystalized = true;
		drawMatrix(matrixA);
	}
	else {
		matrixB[(coordinates.Y / divisionFactor) + 1][(coordinates.X / divisionFactor) + 1]->color = getRandomColorAsInt();
		//matrixB[(coordinates.Y / divisionFactor) + 1][(coordinates.X / divisionFactor) + 1]->isRecrystalized = true;
		drawMatrix(matrixB);
	}
	
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	int value = Convert::ToInt32(textBox1->Text);
	do {
		if (value > 3)
			value--;
	} while (600 % value != 0);
	textBox1->Text = value.ToString();
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	int value = Convert::ToInt32(textBox1->Text);
	do {
		if (value < 300)
			value++;
	} while (600 % value != 0);
	textBox1->Text = value.ToString();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	button4->Enabled = false;
	button6->Enabled = false;
	button5->Enabled = true;
	groupBox1->Enabled = false;
	groupBox3->Enabled = false;
	groupBox4->Enabled = false;
	groupBox5->Enabled = false;
	groupBox6->Enabled = false;
	pictureBox1->Enabled = false;
	button15->Enabled = false;
	backgroundWorker1->RunWorkerAsync();
	
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	button4->Enabled = true;
	button5->Enabled = false; 
	button6->Enabled = true;
	groupBox1->Enabled = true;
	groupBox3->Enabled = true;
	groupBox4->Enabled = true;
	groupBox5->Enabled = true;
	groupBox6->Enabled = true;
	pictureBox1->Enabled = true;
	button15->Enabled = true;
	breakLoop = true;
	backgroundWorker1->CancelAsync();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	int value = Convert::ToInt32(textBox2->Text);
	value++;
	textBox2->Text = value.ToString();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	int value = Convert::ToInt32(textBox2->Text);
	if (value > 0)
		value--;
	textBox2->Text = value.ToString();
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	g->Clear(Color::White);
	if (matrixChoice) {
		fillWithZeroes(matrixA);
		fillWithZeroes(matrixB);
		drawMatrix(matrixA);
	}
	else {
		fillWithZeroes(matrixB);
		fillWithZeroes(matrixA);
		drawMatrix(matrixB);
	}
	pictureBox1->Image = pBmp;
}
private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	textBox2->Text = "1";
}
private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	textBox2->Text = "2";
}
private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	textBox2->Text = "10";
}
private: System::Void radioButton4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	textBox2->Text = "100";
}
private: System::Void radioButton5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	textBox2->Text = "2147483647";
}
private: System::Void trackBar2_Scroll(System::Object^  sender, System::EventArgs^  e) {
	delayCoefficient = trackBar2->Value;
}
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
	k = Convert::ToInt32(textBox6->Text);
	backgroundWorker2->RunWorkerAsync();
	button4->Enabled = false;
	button6->Enabled = false;
	groupBox1->Enabled = false;
	groupBox3->Enabled = false;
	groupBox4->Enabled = false;
	groupBox5->Enabled = false;
	groupBox6->Enabled = false;
	pictureBox1->Enabled = false;
	button15->Enabled = false;
}
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
	int value = Convert::ToInt32(textBox6->Text);
	if (value > 0)
		value--;
	textBox6->Text = value.ToString();
}
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
	int value = Convert::ToInt32(textBox6->Text);
	value++;
	textBox6->Text = value.ToString();
}
};
}
