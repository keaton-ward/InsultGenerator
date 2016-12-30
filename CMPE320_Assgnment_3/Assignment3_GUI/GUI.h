#pragma once
#include "fraction_12kw32.h"

namespace Assignment3_GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GUI
	/// </summary>
	public ref class GUI : public System::Windows::Forms::Form
	{
	public:
		GUI(void)
		{
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//
		}

		void DrawLinePoint(PaintEventArgs^ e)
		{
			// Create pen.
			Pen^ blackPen = gcnew Pen(Color::Black, 3.0f);

			// Create points that define line.
			Point point1 = Point(8, 100);
			Point point2 = Point(500, 100);

			// Draw line to screen.
			e->Graphics->DrawLine(blackPen, point1, point2);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GUI()
		{
			if (components)
			{
				delete components;
			}
		}




	protected:

	protected:



	private: System::Windows::Forms::Label^  lblChoose;











	private: System::Windows::Forms::Label^  lblResult;
	private: System::Windows::Forms::TextBox^  txtDenomOut;


	private: System::Windows::Forms::TextBox^  txtNumOut;

	private: System::Windows::Forms::Button^  btnCalc;






	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  txtDenom2;

	private: System::Windows::Forms::TextBox^  txtNum2;
	private: System::Windows::Forms::Label^  lblLine3;

	private: System::Windows::Forms::Label^  lblError1;








	private: System::Windows::Forms::TextBox^  txtNum1;
	private: System::Windows::Forms::TextBox^  txtDenom1;
	private: System::Windows::Forms::Label^  lblLine1;
	private: System::Windows::Forms::ListBox^  listBoxOperations;
	private: System::Windows::Forms::Button^  btnClear;
	private: System::Windows::Forms::Label^  label1;














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
			this->lblChoose = (gcnew System::Windows::Forms::Label());
			this->lblResult = (gcnew System::Windows::Forms::Label());
			this->txtDenomOut = (gcnew System::Windows::Forms::TextBox());
			this->txtNumOut = (gcnew System::Windows::Forms::TextBox());
			this->btnCalc = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtDenom2 = (gcnew System::Windows::Forms::TextBox());
			this->txtNum2 = (gcnew System::Windows::Forms::TextBox());
			this->lblLine3 = (gcnew System::Windows::Forms::Label());
			this->lblError1 = (gcnew System::Windows::Forms::Label());
			this->txtNum1 = (gcnew System::Windows::Forms::TextBox());
			this->txtDenom1 = (gcnew System::Windows::Forms::TextBox());
			this->lblLine1 = (gcnew System::Windows::Forms::Label());
			this->listBoxOperations = (gcnew System::Windows::Forms::ListBox());
			this->btnClear = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblChoose
			// 
			this->lblChoose->AutoSize = true;
			this->lblChoose->Location = System::Drawing::Point(116, 19);
			this->lblChoose->Name = L"lblChoose";
			this->lblChoose->Size = System::Drawing::Size(144, 17);
			this->lblChoose->TabIndex = 4;
			this->lblChoose->Text = L"Choose an operation:";
			this->lblChoose->Click += gcnew System::EventHandler(this, &GUI::label1_Click);
			// 
			// lblResult
			// 
			this->lblResult->AutoSize = true;
			this->lblResult->Location = System::Drawing::Point(133, 172);
			this->lblResult->Name = L"lblResult";
			this->lblResult->Size = System::Drawing::Size(90, 17);
			this->lblResult->TabIndex = 10;
			this->lblResult->Text = L"The result is:";
			// 
			// txtDenomOut
			// 
			this->txtDenomOut->Location = System::Drawing::Point(135, 222);
			this->txtDenomOut->Name = L"txtDenomOut";
			this->txtDenomOut->Size = System::Drawing::Size(88, 22);
			this->txtDenomOut->TabIndex = 10;
			// 
			// txtNumOut
			// 
			this->txtNumOut->Location = System::Drawing::Point(135, 192);
			this->txtNumOut->Name = L"txtNumOut";
			this->txtNumOut->Size = System::Drawing::Size(88, 22);
			this->txtNumOut->TabIndex = 9;
			// 
			// btnCalc
			// 
			this->btnCalc->Location = System::Drawing::Point(81, 132);
			this->btnCalc->Name = L"btnCalc";
			this->btnCalc->Size = System::Drawing::Size(88, 32);
			this->btnCalc->TabIndex = 8;
			this->btnCalc->Text = L"Calculate:";
			this->btnCalc->UseVisualStyleBackColor = true;
			this->btnCalc->Click += gcnew System::EventHandler(this, &GUI::btnCalc_Click);
			// 
			// label2
			// 
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Location = System::Drawing::Point(258, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 2);
			this->label2->TabIndex = 18;
			// 
			// txtDenom2
			// 
			this->txtDenom2->Location = System::Drawing::Point(258, 86);
			this->txtDenom2->Name = L"txtDenom2";
			this->txtDenom2->Size = System::Drawing::Size(88, 22);
			this->txtDenom2->TabIndex = 7;
			// 
			// txtNum2
			// 
			this->txtNum2->Location = System::Drawing::Point(258, 56);
			this->txtNum2->Name = L"txtNum2";
			this->txtNum2->Size = System::Drawing::Size(88, 22);
			this->txtNum2->TabIndex = 6;
			// 
			// lblLine3
			// 
			this->lblLine3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblLine3->Location = System::Drawing::Point(135, 217);
			this->lblLine3->Name = L"lblLine3";
			this->lblLine3->Size = System::Drawing::Size(87, 2);
			this->lblLine3->TabIndex = 19;
			// 
			// lblError1
			// 
			this->lblError1->BackColor = System::Drawing::SystemColors::Window;
			this->lblError1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblError1->Location = System::Drawing::Point(276, 192);
			this->lblError1->Name = L"lblError1";
			this->lblError1->Size = System::Drawing::Size(180, 80);
			this->lblError1->TabIndex = 21;
			// 
			// txtNum1
			// 
			this->txtNum1->Location = System::Drawing::Point(17, 56);
			this->txtNum1->Name = L"txtNum1";
			this->txtNum1->Size = System::Drawing::Size(88, 22);
			this->txtNum1->TabIndex = 0;
			this->txtNum1->TextChanged += gcnew System::EventHandler(this, &GUI::txtNum1_TextChanged);
			// 
			// txtDenom1
			// 
			this->txtDenom1->Location = System::Drawing::Point(17, 86);
			this->txtDenom1->Name = L"txtDenom1";
			this->txtDenom1->Size = System::Drawing::Size(88, 22);
			this->txtDenom1->TabIndex = 1;
			// 
			// lblLine1
			// 
			this->lblLine1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblLine1->Location = System::Drawing::Point(17, 81);
			this->lblLine1->Name = L"lblLine1";
			this->lblLine1->Size = System::Drawing::Size(88, 2);
			this->lblLine1->TabIndex = 18;
			this->lblLine1->Click += gcnew System::EventHandler(this, &GUI::lblLine1_Click);
			// 
			// listBoxOperations
			// 
			this->listBoxOperations->BackColor = System::Drawing::SystemColors::Menu;
			this->listBoxOperations->FormattingEnabled = true;
			this->listBoxOperations->ItemHeight = 16;
			this->listBoxOperations->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"+", L"-", L"*", L"/" });
			this->listBoxOperations->Location = System::Drawing::Point(163, 58);
			this->listBoxOperations->Name = L"listBoxOperations";
			this->listBoxOperations->Size = System::Drawing::Size(32, 68);
			this->listBoxOperations->TabIndex = 23;
			this->listBoxOperations->SelectedIndexChanged += gcnew System::EventHandler(this, &GUI::listBox1_SelectedIndexChanged);
			// 
			// btnClear
			// 
			this->btnClear->Location = System::Drawing::Point(191, 132);
			this->btnClear->Name = L"btnClear";
			this->btnClear->Size = System::Drawing::Size(88, 32);
			this->btnClear->TabIndex = 24;
			this->btnClear->Text = L"Clear:";
			this->btnClear->UseVisualStyleBackColor = true;
			this->btnClear->Click += gcnew System::EventHandler(this, &GUI::btnClear_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(346, 172);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 17);
			this->label1->TabIndex = 25;
			this->label1->Text = L"Errors:";
			this->label1->Click += gcnew System::EventHandler(this, &GUI::label1_Click_1);
			// 
			// GUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(459, 281);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnClear);
			this->Controls->Add(this->listBoxOperations);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblLine1);
			this->Controls->Add(this->txtDenom2);
			this->Controls->Add(this->txtNum2);
			this->Controls->Add(this->txtDenom1);
			this->Controls->Add(this->txtNum1);
			this->Controls->Add(this->lblError1);
			this->Controls->Add(this->lblLine3);
			this->Controls->Add(this->btnCalc);
			this->Controls->Add(this->txtDenomOut);
			this->Controls->Add(this->txtNumOut);
			this->Controls->Add(this->lblResult);
			this->Controls->Add(this->lblChoose);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"GUI";
			this->Text = L"Fraction Calculator by Keaton Ward";
			this->Load += gcnew System::EventHandler(this, &GUI::GUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void GUI_Load(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void txtNum1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void lblLine_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void btnCalc_Click(System::Object^  sender, System::EventArgs^  e) {	
	if (listBoxOperations->SelectedIndex >= 0) {
		if (txtNum1->Text == "" || txtDenom1->Text == "" || txtNum2->Text == "" || txtDenom2->Text == "")
			lblError1->Text = "Please enter numbers in the numerator and denominator on both sides of the operators";
		else {
			lblError1->Text = "";
			if ((this->txtNum1->Text->Contains("-") && this->txtNum1->Text[0] != '-') || 
				(this->txtDenom1->Text->Contains("-") && this->txtDenom1->Text[0] != '-') || 
				(this->txtNum2->Text->Contains("-") && this->txtNum2->Text[0] != '-') || 
				(this->txtDenom2->Text->Contains("-") && this->txtDenom1->Text[0] != '-'))
				lblError1->Text = "Please place negation symbol at the beginning of the number";
			else {
				int num1 = int::Parse(txtNum1->Text);
				int den1 = int::Parse(txtDenom1->Text);
				int num2 = int::Parse(txtNum2->Text);
				int den2 = int::Parse(txtDenom2->Text);
				if (den1 == 0 || den2 == 0)
					lblError1->Text = "Denominator cannnot be zero";
				else {

					int* result;

					if (listBoxOperations->SelectedItem->ToString() == "+") {
						result = addition(num1, den1, num2, den2);
						txtNumOut->Text = "" + result[0];
						txtDenomOut->Text = "" + result[1];
					}
					else if (listBoxOperations->SelectedItem->ToString() == "-") {
						result = subtraction(num1, den1, num2, den2);
						txtNumOut->Text = "" + result[0];
						txtDenomOut->Text = "" + result[1];
					}
					else if (listBoxOperations->SelectedItem->ToString() == "*") {
						result = multiplication(num1, den1, num2, den2);
						txtNumOut->Text = "" + result[0];
						txtDenomOut->Text = "" + result[1];
					}
					else if (listBoxOperations->SelectedItem->ToString() == "/") {
						result = division(num1, den1, num2, den2);
						txtNumOut->Text = "" + result[0];
						txtDenomOut->Text = "" + result[1];
					}
					if (result[1] != 1) {
						txtNumOut->Text = "" + result[0];
						txtDenomOut->Text = "" + result[1];
					}
					else {
						txtNumOut->Text = "" + result[0];
						txtDenomOut->Text = "";
					}
				}
			}
		}
	}
	else
		lblError1->Text = "Choose an operator";
}
private: System::Void lblLine1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void rbtnAdd_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	lblError1->Text = "";
}
private: System::Void btnClear_Click(System::Object^  sender, System::EventArgs^  e) {
	lblError1->Text = "";
	txtNum1->Text = "";
	txtDenom1->Text = "";
	txtNum2->Text = "";
	txtDenom2->Text = "";
	txtNumOut->Text = "";
	txtDenomOut->Text = "";
}
private: System::Void label1_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
};
}
