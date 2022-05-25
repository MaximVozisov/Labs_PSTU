#pragma once

#include <cmath>

namespace Сalculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Calculator : public System::Windows::Forms::Form
	{
	public:
		Calculator(void)
		{
			TopMost = true;
			InitializeComponent();
			textBox9->ReadOnly = true;
			textBox8->ReadOnly = true;
			textBox7->ReadOnly = true;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Text = "+";
		}

	protected:
		~Calculator()
		{
			if (components)
			{
				delete components;
			}
		}

	public:
		int NOD(int a, int b)
		{
			while (b != 0)
			{
				int temp = b;
				b = a % b;
				a = temp;
			}
			return a;
		}
	public:
		int NOK(int n1, int n2)
		{
			return n1 * n2 / NOD(n1, n2);
		}
	public:
		int sokr(int a, int b) {
			a = abs(a), b = abs(b);
			if (b == 0)return a;
			else return sokr(b, a % b);
		}
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Button^ n7;
	private: System::Windows::Forms::Button^ n8;
	private: System::Windows::Forms::Button^ n9;
	private: System::Windows::Forms::Button^ n6;
	private: System::Windows::Forms::Button^ n5;
	private: System::Windows::Forms::Button^ n4;
	private: System::Windows::Forms::Button^ n3;
	private: System::Windows::Forms::Button^ n2;
	private: System::Windows::Forms::Button^ n1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Button^ clear;
	private: System::Windows::Forms::Button^ n0;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;



	private: System::Windows::Forms::Label^ labelError;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Calculator::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->n7 = (gcnew System::Windows::Forms::Button());
			this->n8 = (gcnew System::Windows::Forms::Button());
			this->n9 = (gcnew System::Windows::Forms::Button());
			this->n6 = (gcnew System::Windows::Forms::Button());
			this->n5 = (gcnew System::Windows::Forms::Button());
			this->n4 = (gcnew System::Windows::Forms::Button());
			this->n3 = (gcnew System::Windows::Forms::Button());
			this->n2 = (gcnew System::Windows::Forms::Button());
			this->n1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->n0 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->labelError = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(77, 53);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(36, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Click += gcnew System::EventHandler(this, &Calculator::textBox1_Click);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Calculator::textBox1_KeyPress);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(232, 53);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(36, 20);
			this->textBox4->TabIndex = 7;
			this->textBox4->Click += gcnew System::EventHandler(this, &Calculator::textBox4_Click);
			this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Calculator::textBox4_KeyPress);
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(232, 28);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(36, 20);
			this->textBox5->TabIndex = 6;
			this->textBox5->Click += gcnew System::EventHandler(this, &Calculator::textBox5_Click);
			this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Calculator::textBox5_KeyPress);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(193, 40);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(24, 20);
			this->textBox6->TabIndex = 5;
			this->textBox6->Click += gcnew System::EventHandler(this, &Calculator::textBox6_Click);
			this->textBox6->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Calculator::textBox6_KeyPress);
			// 
			// n7
			// 
			this->n7->BackColor = System::Drawing::Color::SeaShell;
			this->n7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->n7->Location = System::Drawing::Point(128, 79);
			this->n7->Name = L"n7";
			this->n7->Size = System::Drawing::Size(30, 30);
			this->n7->TabIndex = 10;
			this->n7->Text = L"7";
			this->n7->UseVisualStyleBackColor = false;
			this->n7->Click += gcnew System::EventHandler(this, &Calculator::n7_Click);
			// 
			// n8
			// 
			this->n8->BackColor = System::Drawing::Color::SeaShell;
			this->n8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->n8->Location = System::Drawing::Point(157, 79);
			this->n8->Name = L"n8";
			this->n8->Size = System::Drawing::Size(30, 30);
			this->n8->TabIndex = 9;
			this->n8->Text = L"8";
			this->n8->UseVisualStyleBackColor = false;
			this->n8->Click += gcnew System::EventHandler(this, &Calculator::n8_Click);
			// 
			// n9
			// 
			this->n9->BackColor = System::Drawing::Color::SeaShell;
			this->n9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->n9->Location = System::Drawing::Point(186, 79);
			this->n9->Name = L"n9";
			this->n9->Size = System::Drawing::Size(30, 30);
			this->n9->TabIndex = 8;
			this->n9->Text = L"9";
			this->n9->UseVisualStyleBackColor = false;
			this->n9->Click += gcnew System::EventHandler(this, &Calculator::n9_Click);
			// 
			// n6
			// 
			this->n6->BackColor = System::Drawing::Color::SeaShell;
			this->n6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->n6->Location = System::Drawing::Point(186, 108);
			this->n6->Name = L"n6";
			this->n6->Size = System::Drawing::Size(30, 30);
			this->n6->TabIndex = 11;
			this->n6->Text = L"6";
			this->n6->UseVisualStyleBackColor = false;
			this->n6->Click += gcnew System::EventHandler(this, &Calculator::n6_Click);
			// 
			// n5
			// 
			this->n5->BackColor = System::Drawing::Color::SeaShell;
			this->n5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->n5->Location = System::Drawing::Point(157, 108);
			this->n5->Name = L"n5";
			this->n5->Size = System::Drawing::Size(30, 30);
			this->n5->TabIndex = 12;
			this->n5->Text = L"5";
			this->n5->UseVisualStyleBackColor = false;
			this->n5->Click += gcnew System::EventHandler(this, &Calculator::n5_Click);
			// 
			// n4
			// 
			this->n4->BackColor = System::Drawing::Color::SeaShell;
			this->n4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->n4->Location = System::Drawing::Point(128, 108);
			this->n4->Name = L"n4";
			this->n4->Size = System::Drawing::Size(30, 30);
			this->n4->TabIndex = 13;
			this->n4->Text = L"4";
			this->n4->UseVisualStyleBackColor = false;
			this->n4->Click += gcnew System::EventHandler(this, &Calculator::n4_Click);
			// 
			// n3
			// 
			this->n3->BackColor = System::Drawing::Color::SeaShell;
			this->n3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->n3->Location = System::Drawing::Point(186, 137);
			this->n3->Name = L"n3";
			this->n3->Size = System::Drawing::Size(30, 30);
			this->n3->TabIndex = 14;
			this->n3->Text = L"3";
			this->n3->UseVisualStyleBackColor = false;
			this->n3->Click += gcnew System::EventHandler(this, &Calculator::n3_Click);
			// 
			// n2
			// 
			this->n2->BackColor = System::Drawing::Color::SeaShell;
			this->n2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->n2->Location = System::Drawing::Point(157, 137);
			this->n2->Name = L"n2";
			this->n2->Size = System::Drawing::Size(30, 30);
			this->n2->TabIndex = 15;
			this->n2->Text = L"2";
			this->n2->UseVisualStyleBackColor = false;
			this->n2->Click += gcnew System::EventHandler(this, &Calculator::n2_Click);
			// 
			// n1
			// 
			this->n1->BackColor = System::Drawing::Color::SeaShell;
			this->n1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->n1->Location = System::Drawing::Point(128, 137);
			this->n1->Name = L"n1";
			this->n1->Size = System::Drawing::Size(30, 30);
			this->n1->TabIndex = 16;
			this->n1->Text = L"1";
			this->n1->UseVisualStyleBackColor = false;
			this->n1->Click += gcnew System::EventHandler(this, &Calculator::n1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"+", L"-", L"*", L"/" });
			this->comboBox1->Location = System::Drawing::Point(139, 40);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(33, 21);
			this->comboBox1->TabIndex = 4;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(77, 28);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(36, 20);
			this->textBox2->TabIndex = 2;
			this->textBox2->Click += gcnew System::EventHandler(this, &Calculator::textBox2_Click);
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Calculator::textBox2_KeyPress);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(38, 40);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(24, 20);
			this->textBox3->TabIndex = 1;
			this->textBox3->Click += gcnew System::EventHandler(this, &Calculator::textBox3_Click);
			this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Calculator::textBox3_KeyPress);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(353, 53);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(36, 20);
			this->textBox7->TabIndex = 24;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(353, 28);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(36, 20);
			this->textBox8->TabIndex = 23;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(314, 40);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(24, 20);
			this->textBox9->TabIndex = 22;
			// 
			// clear
			// 
			this->clear->BackColor = System::Drawing::Color::SeaShell;
			this->clear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->clear->Location = System::Drawing::Point(302, 120);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(102, 29);
			this->clear->TabIndex = 21;
			this->clear->Text = L"Очистить";
			this->clear->UseVisualStyleBackColor = false;
			this->clear->Click += gcnew System::EventHandler(this, &Calculator::clear_Click);
			// 
			// n0
			// 
			this->n0->BackColor = System::Drawing::Color::SeaShell;
			this->n0->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->n0->Location = System::Drawing::Point(128, 165);
			this->n0->Name = L"n0";
			this->n0->Size = System::Drawing::Size(30, 30);
			this->n0->TabIndex = 17;
			this->n0->Text = L"0";
			this->n0->UseVisualStyleBackColor = false;
			this->n0->Click += gcnew System::EventHandler(this, &Calculator::n0_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel1->Location = System::Drawing::Point(223, 50);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(54, 1);
			this->panel1->TabIndex = 30;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel2->Location = System::Drawing::Point(68, 50);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(54, 1);
			this->panel2->TabIndex = 31;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel3->Location = System::Drawing::Point(344, 50);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(54, 1);
			this->panel3->TabIndex = 32;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::SeaShell;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(302, 86);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 29);
			this->button2->TabIndex = 20;
			this->button2->Text = L"Вычислить";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Calculator::button2_Enter);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(288, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(13, 13);
			this->label1->TabIndex = 34;
			this->label1->Text = L"=";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::SeaShell;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(232, 79);
			this->button3->Name = L"button3";
			this->button3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button3->Size = System::Drawing::Size(36, 23);
			this->button3->TabIndex = 35;
			this->button3->Text = L"-/+";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Calculator::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::SeaShell;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Location = System::Drawing::Point(77, 79);
			this->button4->Name = L"button4";
			this->button4->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->button4->Size = System::Drawing::Size(36, 23);
			this->button4->TabIndex = 36;
			this->button4->Text = L"-/+";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Calculator::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::SeaShell;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Location = System::Drawing::Point(11, 120);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(102, 30);
			this->button5->TabIndex = 37;
			this->button5->Text = L"Ввод мышью";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Calculator::button5_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::SeaShell;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Location = System::Drawing::Point(157, 165);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(59, 30);
			this->button6->TabIndex = 38;
			this->button6->Text = L"Меньше";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Calculator::button6_Click);
			// 
			// labelError
			// 
			this->labelError->AutoSize = true;
			this->labelError->BackColor = System::Drawing::Color::Transparent;
			this->labelError->Location = System::Drawing::Point(115, 9);
			this->labelError->Name = L"labelError";
			this->labelError->Size = System::Drawing::Size(181, 13);
			this->labelError->TabIndex = 42;
			this->labelError->Text = L"Ошибка: поля заполнены неверно";
			// 
			// Calculator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(416, 203);
			this->Controls->Add(this->labelError);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->n0);
			this->Controls->Add(this->n3);
			this->Controls->Add(this->n2);
			this->Controls->Add(this->n1);
			this->Controls->Add(this->n6);
			this->Controls->Add(this->n5);
			this->Controls->Add(this->n4);
			this->Controls->Add(this->n9);
			this->Controls->Add(this->n8);
			this->Controls->Add(this->n7);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox1);
			this->DoubleBuffered = true;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(432, 242);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(432, 196);
			this->Name = L"Calculator";
			this->Text = L"Fraction calculator";
			this->Load += gcnew System::EventHandler(this, &Calculator::Calculator_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
int enter = 0;
bool l2 = false;
bool l3 = false;
private: System::Void Calculator_Load(System::Object^ sender, System::EventArgs^ e) {
	Size = System::Drawing::Size(432, 196);
	labelError->Visible = false;
	n0->Visible = false;
	n1->Visible = false;
	n2->Visible = false;
	n3->Visible = false;
	n4->Visible = false;
	n5->Visible = false;
	n6->Visible = false;
	n7->Visible = false;
	n8->Visible = false;
	n9->Visible = false;
	button6->Visible = false;
}
private: System::Void n0_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (enter)
	{
	case 0: textBox3->Text += 0; break;
	case 1: textBox2->Text += 0; break;
	case 2: textBox1->Text += 0; break;
	case 3: textBox6->Text += 0; break;
	case 4: textBox5->Text += 0; break;
	case 5: textBox4->Text += 0; break;
	}
}
private: System::Void n1_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (enter)
	{
	case 0: textBox3->Text += 1; break;
	case 1: textBox2->Text += 1; break;
	case 2: textBox1->Text += 1; break;
	case 3: textBox6->Text += 1; break;
	case 4: textBox5->Text += 1; break;
	case 5: textBox4->Text += 1; break;
	}
}
private: System::Void n2_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (enter)
	{
	case 0: textBox3->Text += 2; break;
	case 1: textBox2->Text += 2; break;
	case 2: textBox1->Text += 2; break;
	case 3: textBox6->Text += 2; break;
	case 4: textBox5->Text += 2; break;
	case 5: textBox4->Text += 2; break;
	}
}
private: System::Void n3_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (enter)
	{
	case 0: textBox3->Text += 3; break;
	case 1: textBox2->Text += 3; break;
	case 2: textBox1->Text += 3; break;
	case 3: textBox6->Text += 3; break;
	case 4: textBox5->Text += 3; break;
	case 5: textBox4->Text += 3; break;
	}
}
private: System::Void n4_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (enter)
	{
	case 0: textBox3->Text += 4; break;
	case 1: textBox2->Text += 4; break;
	case 2: textBox1->Text += 4; break;
	case 3: textBox6->Text += 4; break;
	case 4: textBox5->Text += 4; break;
	case 5: textBox4->Text += 4; break;
	}
}
private: System::Void n5_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (enter)
	{
	case 0: textBox3->Text += 5; break;
	case 1: textBox2->Text += 5; break;
	case 2: textBox1->Text += 5; break;
	case 3: textBox6->Text += 5; break;
	case 4: textBox5->Text += 5; break;
	case 5: textBox4->Text += 5; break;
	}
}
private: System::Void n6_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (enter)
	{
	case 0: textBox3->Text += 6; break;
	case 1: textBox2->Text += 6; break;
	case 2: textBox1->Text += 6; break;
	case 3: textBox6->Text += 6; break;
	case 4: textBox5->Text += 6; break;
	case 5: textBox4->Text += 6; break;
	}
}
private: System::Void n7_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (enter)
	{
	case 0: textBox3->Text += 7; break;
	case 1: textBox2->Text += 7; break;
	case 2: textBox1->Text += 7; break;
	case 3: textBox6->Text += 7; break;
	case 4: textBox5->Text += 7; break;
	case 5: textBox4->Text += 7; break;
	}
}
private: System::Void n8_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (enter)
	{
	case 0: textBox3->Text += 8; break;
	case 1: textBox2->Text += 8; break;
	case 2: textBox1->Text += 8; break;
	case 3: textBox6->Text += 8; break;
	case 4: textBox5->Text += 8; break;
	case 5: textBox4->Text += 8; break;
	}
}
private: System::Void n9_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (enter)
	{
	case 0: textBox3->Text += 9; break;
	case 1: textBox2->Text += 9; break;
	case 2: textBox1->Text += 9; break;
	case 3: textBox6->Text += 9; break;
	case 4: textBox5->Text += 9; break;
	case 5: textBox4->Text += 9; break;
	}
}
private: System::Void button2_Enter(System::Object^ sender, System::EventArgs^ e) {
	labelError->Visible = false;
	textBox9->Text = "";
	textBox8->Text = "";
	textBox7->Text = "";
	if ((textBox1->Text == "") && (textBox4->Text == "") && (textBox2->Text == "") && (textBox5->Text == "") && (textBox3->Text != "") && (textBox6->Text != ""))
	{
		int n3 = Int32::Parse(textBox3->Text);
		int n6 = Int32::Parse(textBox6->Text);
		char znak = comboBox1->Text[0];
		switch (znak)
		{
		case '+':
			if (n6 + n3 < 0)
			{
				textBox9->Text = System::Convert::ToString(-(n6 + n3));
			}
			else textBox9->Text = System::Convert::ToString(n6 + n3);
			break;
		case '-':
			if (n6 - n3 < 0)
			{
				textBox9->Text = System::Convert::ToString(-(n6 - n3));
			}
			else textBox9->Text = System::Convert::ToString(n6 + n3);
			break;
		case '*':
			if (n6 * n3 < 0)
			{
				textBox9->Text = System::Convert::ToString(-(n6 * n3));
			}
			else textBox9->Text = System::Convert::ToString(n6 * n3);
			break;
		case '/':
			int chis = n3;
			int znam = n6;
			int x = sokr(chis, znam);
			chis /= x;
			znam /= x;
			if (chis % znam == 0)
				textBox9->Text = System::Convert::ToString(chis / znam);
			else
			{
				int cel = chis / znam;
				if (!cel)
				{
					int x = sokr(chis, znam);
					textBox8->Text = System::Convert::ToString(chis);
					textBox7->Text = System::Convert::ToString(znam);
				}
				else
				{
					textBox9->Text = System::Convert::ToString(chis / znam);
					if (znam % (chis - cel * znam) == 0)
					{
						textBox8->Text = System::Convert::ToString(1);
						textBox7->Text = System::Convert::ToString(znam/(chis - cel * znam));
					}
					else
					{
						textBox8->Text = System::Convert::ToString(chis - cel*znam);
						textBox7->Text = System::Convert::ToString(znam);
					}
					
				}
			}
			break;
		}
		return;
	}
	if ((textBox1->Text == "") || (textBox4->Text == "") || (textBox2->Text == "") || (textBox5->Text == ""))
	{
		labelError->Visible = true;
		return;
	}
	int n3 = 0;
	int n6 = 0;
	int n2 = Int32::Parse(textBox2->Text);
	int n1 = Int32::Parse(textBox1->Text);
	int n5 = Int32::Parse(textBox5->Text);
	int n4 = Int32::Parse(textBox4->Text);
	if ((n1 == 0) || (n4 == 0))
	{
		labelError->Visible = true;
		return;
	}
	char znak = comboBox1->Text[0];
	int nok = NOK(n1, n4);

	//Перевод в неправильную дробь
	if ((textBox3->Text != "") && (textBox3->Text != "0"))
	{
		n3 = Int32::Parse(textBox3->Text);
		n2 = n2 + n1 * n3;
	}
	if ((textBox6->Text != "") && (textBox3->Text != "0"))
	{
		n6 = Int32::Parse(textBox6->Text);
		n5 = n5 + n4 * n6;
	}
	int chis1 = (n2 * (nok / n1));
	int chis2 = (n5 * (nok / n4));
	int chisPlus = chis1 + chis2;
	int nokHelp = nok;
	int x = sokr(chisPlus, nokHelp);
	chisPlus /= x;
	nokHelp /= x;
	switch (znak)
	{
	case '+':
		if (chisPlus < nok)
		{
			int x = sokr(chisPlus, nok);
			textBox8->Text = System::Convert::ToString(chisPlus);
			textBox7->Text = System::Convert::ToString(nokHelp);
		}
		if (chisPlus > nok)
		{
			textBox9->Text = System::Convert::ToString(chisPlus / nok);
			textBox8->Text = System::Convert::ToString(chisPlus - nok * (chisPlus / nok));
			textBox7->Text = System::Convert::ToString(nok);
		}
		if ((chisPlus = nok) && (textBox3->Text != "") && (textBox6->Text != ""))
			textBox9->Text = System::Convert::ToString(n3 + n6 + 1);
		break;
	case '-':
		textBox8->Text = System::Convert::ToString(nok);
		textBox7->Text = System::Convert::ToString(nok);
		break;
	case '*':
		textBox8->Text = System::Convert::ToString(n2 * n5);
		textBox7->Text = System::Convert::ToString(n1 * n4);
		break;
	case '/':
		textBox8->Text = System::Convert::ToString(n2 * n4);
		textBox7->Text = System::Convert::ToString(n1 * n5);
		break;
	default:
		break;
	}
}
private: System::Void clear_Click(System::Object^ sender, System::EventArgs^ e) {
	labelError->Visible = false;
	textBox1->Text = "";
	textBox2->Text = "";
	textBox3->Text = "";
	textBox4->Text = "";
	textBox5->Text = "";
	textBox6->Text = "";
	textBox7->Text = "";
	textBox8->Text = "";
	textBox9->Text = "";
	comboBox1->Text = "";
	enter = 0;
	l2 = false;
	l3 = false;
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	Size = System::Drawing::Size(432, 242);
	button5->Visible = false;
	n0->Visible = true;
	n1->Visible = true;
	n2->Visible = true;
	n3->Visible = true;
	n4->Visible = true;
	n5->Visible = true;
	n6->Visible = true;
	n7->Visible = true;
	n8->Visible = true;
	n9->Visible = true;
	button6->Visible = true;
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	Size = System::Drawing::Size(432, 180);
	button5->Visible = true;
	n0->Visible = false;
	n1->Visible = false;
	n2->Visible = false;
	n3->Visible = false;
	n4->Visible = false;
	n5->Visible = false;
	n6->Visible = false;
	n7->Visible = false;
	n8->Visible = false;
	n9->Visible = false;
	button6->Visible = false;
}
private: System::Void textBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	enter = 0;
}
private: System::Void textBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	enter = 1;
}
private: System::Void textBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	enter = 2;
}
private: System::Void textBox5_Click(System::Object^ sender, System::EventArgs^ e) {
	enter = 4;
}
private: System::Void textBox4_Click(System::Object^ sender, System::EventArgs^ e) {
	enter = 5;
}
private: System::Void textBox6_Click(System::Object^ sender, System::EventArgs^ e) {
	enter = 3;
}
private: System::Void textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	char number = e->KeyChar;
	if (!Char::IsDigit(number) && number != 8)
		e->Handled = true;
}
private: System::Void textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	char number = e->KeyChar;
	if (!Char::IsDigit(number) && number != 8)
		e->Handled = true;
}
private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	char number = e->KeyChar;
	if (!Char::IsDigit(number) && number != 8)
		e->Handled = true;
}
private: System::Void textBox6_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	char number = e->KeyChar;
	if (!Char::IsDigit(number) && number != 8)
		e->Handled = true;
}
private: System::Void textBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	char number = e->KeyChar;
	if (!Char::IsDigit(number) && number != 8)
		e->Handled = true;
}
private: System::Void textBox4_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	char number = e->KeyChar;
	if (!Char::IsDigit(number) && number != 8)
		e->Handled = true;
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (l2)
	{
		l2 = false;
	}
	else
	{
		l2= true;
	}
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (l3)
	{
		l3 = false;
	}
	else
	{
		l3 = true;
	}
}
};
}