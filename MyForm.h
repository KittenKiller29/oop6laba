#pragma once
#include"figure.h"
MVC mvc;
namespace oop6laba {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::RadioButton^ radioButton4;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label5;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(9, 53);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 44);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Квадрат";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(153, 53);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(120, 44);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Круг";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(297, 53);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(120, 44);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Треугольник";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(9, 26);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(88, 21);
			this->radioButton1->TabIndex = 3;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Зеленый";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->Visible = false;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			this->radioButton1->Click += gcnew System::EventHandler(this, &MyForm::radioButton1_Click);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(116, 26);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(87, 21);
			this->radioButton2->TabIndex = 4;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Красный";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->Visible = false;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			this->radioButton2->Click += gcnew System::EventHandler(this, &MyForm::radioButton2_Click);
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(223, 26);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(70, 21);
			this->radioButton3->TabIndex = 5;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Синий";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->Visible = false;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			this->radioButton3->Click += gcnew System::EventHandler(this, &MyForm::radioButton3_Click);
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(307, 26);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(110, 21);
			this->radioButton4->TabIndex = 6;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Без заливки";
			this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->Visible = false;
			this->radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton4_CheckedChanged);
			this->radioButton4->Click += gcnew System::EventHandler(this, &MyForm::radioButton4_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(561, 53);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(120, 44);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Очистить форму";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::White;
			this->button5->Location = System::Drawing::Point(435, 53);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(120, 44);
			this->button5->TabIndex = 8;
			this->button5->Text = L"Открыть ColorPanel";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(463, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(181, 17);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Клавиша CTRL не зажата!";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Green;
			this->label2->Location = System::Drawing::Point(59, 6);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(307, 17);
			this->label2->TabIndex = 10;
			this->label2->Text = L"ColorPanel, редактирование цвета включено!";
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Green;
			this->label3->Location = System::Drawing::Point(489, 328);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 17);
			this->label3->TabIndex = 11;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Green;
			this->label4->Location = System::Drawing::Point(483, 6);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(161, 17);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Клавиша CTRL зажата!";
			this->label4->Visible = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::NavajoWhite;
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->radioButton4);
			this->panel1->Controls->Add(this->radioButton3);
			this->panel1->Controls->Add(this->radioButton2);
			this->panel1->Controls->Add(this->radioButton1);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(0, 340);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(696, 109);
			this->panel1->TabIndex = 13;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::Red;
			this->label5->Location = System::Drawing::Point(136, 26);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(157, 17);
			this->label5->TabIndex = 14;
			this->label5->Text = L"ColorPanel не активна!";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->ClientSize = System::Drawing::Size(696, 449);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label3);
			this->KeyPreview = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDoubleClick);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		button1->BackColor = Color::CornflowerBlue;
		button2->BackColor = Color::White;
		button3->BackColor = Color::White;
		mvc.b1Set(1);
		mvc.b2Set(0);
		mvc.b3Set(0);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		button2->BackColor = Color::CornflowerBlue;
		button1->BackColor = Color::White;
		button3->BackColor = Color::White;
		mvc.b1Set(0);
		mvc.b2Set(1);
		mvc.b3Set(0);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		button3->BackColor = Color::CornflowerBlue;
		button1->BackColor = Color::White;
		button2->BackColor = Color::White;
		mvc.b1Set(0);
		mvc.b2Set(0);
		mvc.b3Set(1);
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		switch (e->Button) {
		case System::Windows::Forms::MouseButtons::Left:
			mvc.makeunCheck();
			if (!mvc.ctrlGet())
				mvc.pushObject(mvc.getSize(), e);
			else {
				mvc.checker->createChecker(e);
				mvc.inChecker();
			}
			break;
		case System::Windows::Forms::MouseButtons::Right:
			mvc.makeunCheck();
			mvc.makeCheck(e);
			mvc.checker->deleteChecker();
			break;
		}
		Invalidate();
	}
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		mvc.drawFigures(e);
	}
	private: System::Void MyForm_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		
	}
	private: System::Void radioButton4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		switch (radioButton1->Visible)
		{
		case true:
			radioButton1->Visible = false;
			radioButton2->Visible = false;
			radioButton3->Visible = false;
			radioButton4->Visible = false;
			radioButton1->Checked = false;
			radioButton2->Checked = false;
			radioButton3->Checked = false;
			radioButton4->Checked = false;
			label2->Visible = false;
			button5->Text = "Открыть ColorPanel";
			label5->Visible = true;
			mvc.colorSet("Empty");
			break;
		case false:
			radioButton1->Visible = true;
			radioButton2->Visible = true;
			radioButton3->Visible = true;
			radioButton4->Visible = true;
			label2->Visible = true;
			label5->Visible = false;
			button5->Text = "Закрыть ColorPanel";
			break;
		}
	}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}
private: System::Void radioButton1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (radioButton1->Checked) {
		mvc.colorSet("Green");
		mvc.createColor();
	}
	Invalidate();
}
private: System::Void radioButton2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (radioButton2->Checked) {
		mvc.colorSet("Red");
		mvc.createColor();
	}
	Invalidate();
}
private: System::Void radioButton3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (radioButton3->Checked) {
		mvc.colorSet("Blue");
		mvc.createColor();
	}
	Invalidate();
}
private: System::Void radioButton4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (radioButton4->Checked) {
		mvc.colorSet("Empty");
		mvc.createColor();
	}
	Invalidate();
}

private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	switch (e->KeyCode){
	case Keys::ControlKey:
		mvc.makeunCheck();
		mvc.ctrlSet(!mvc.ctrlGet());
		label4->Visible = !label4->Visible;
		switch (mvc.ctrlGet()) {
		case true:
			mvc.checker->deleteChecker();
			label1->ForeColor = Color::Green;
			label1->Text = L"Выделение на ЛКМ включено!";
			break;
		case false:
			label1->ForeColor = Color::Red;
			label1->Text = L"Клавиша CTRL не зажата!";
			mvc.checker->deleteChecker();
			break;
		}
		break;
	/*case Keys::S:
		mvc.changePosition(0, 1);
		break;
	case Keys::W:
		mvc.changePosition(0, -1);
		break;
	case Keys::A:
		mvc.changePosition(-1, 0);
		break;
	case Keys::D:
		mvc.changePosition(1, 0);
		break;*/
	}
	Invalidate();
}
private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	switch (e->KeyCode) {
	case Keys::S:
		mvc.changePosition(0, 1,MyForm::Size.Width, MyForm::Size.Height-panel1->Height);
		break;
	case Keys::W:
		mvc.changePosition(0, -1, MyForm::Size.Width, MyForm::Size.Height - panel1->Height);
		break;
	case Keys::A:
		mvc.changePosition(-1, 0, MyForm::Size.Width, MyForm::Size.Height - panel1->Height);
		break;
	case Keys::D:
		mvc.changePosition(1, 0, MyForm::Size.Width, MyForm::Size.Height - panel1->Height);
		break;
	}
	Invalidate();
}
private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	mvc.deleteObjects();
	mvc.checker->deleteChecker();
	Invalidate();
}
};
}

