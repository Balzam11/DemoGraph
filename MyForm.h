#pragma once
#include <cstdlib>
#include <fstream>


namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			// TODO
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ generateBtn;
	private: System::Windows::Forms::TextBox^ textBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox;




	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->generateBtn = (gcnew System::Windows::Forms::Button());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			this->SuspendLayout();
			// 
			// generateBtn
			// 
			this->generateBtn->AutoSize = true;
			this->generateBtn->Enabled = false;
			this->generateBtn->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->generateBtn->Location = System::Drawing::Point(529, 41);
			this->generateBtn->Name = L"generateBtn";
			this->generateBtn->Size = System::Drawing::Size(108, 25);
			this->generateBtn->TabIndex = 0;
			this->generateBtn->Text = L"�������������";
			this->generateBtn->UseVisualStyleBackColor = true;
			this->generateBtn->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox
			// 
			this->textBox->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox->Location = System::Drawing::Point(529, 15);
			this->textBox->MaxLength = 4;
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(108, 23);
			this->textBox->TabIndex = 1;
			this->textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(495, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(28, 15);
			this->label1->TabIndex = 2;
			this->label1->Text = L"N =";
			// 
			// pictureBox
			// 
			this->pictureBox->BackColor = System::Drawing::SystemColors::Control;
			this->pictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox->Location = System::Drawing::Point(12, 88);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(1142, 448);
			this->pictureBox->TabIndex = 3;
			this->pictureBox->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1166, 548);
			this->Controls->Add(this->pictureBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->generateBtn);
			this->Name = L"MyForm";
			this->Text = L"�����";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		// ��� ����� �� �������� �������� ���� �� �������������� � ���� ������� ������
	private: System::Void textBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (!Char::IsDigit(e->KeyChar))
			e->Handled = true; // Handled - ���������� ��������� � ���, ���� �� ���������� �������
		else
			generateBtn->Enabled = true;
	}


		   // ��� ������� ������ "�������������" ����������� ������� ��������� ����� �� ���������
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int N;												// ���������� N ����� ������� ����� �����, ��������� �������������
		if (String::IsNullOrEmpty(textBox->Text) || Convert::ToInt16(textBox->Text) == 0)
			exit(-1);										// ���� ������ ��������� ������ ��� ����� ����� ����, �� ��������� ����������
		else
			N = System::Convert::ToInt16(textBox->Text);    // ����� �������� ����� N ������������� �� ��������� ���� � �������������


		Bitmap^ bmp = gcnew Bitmap(pictureBox->Width, pictureBox->Height); // ����������, �������� ��������� �����������
		Graphics^ g = Graphics::FromImage(bmp);							   // ����������� ������������ ���������� � ���������� �����������


		g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias; // ����� ����������� ��� ���������
		g->Clear(Color::Navy);									// ������� ����������� � ���������� ������ (����-�����)


		const float pointSize = 5;					 // ������� ����� �� ���������
		const int indent = 10;						 // ������ �� ������� ��������� ��������� ��� ���� ����� ����� �� �������� �� � �����
		float* X = new float[N], * Y = new float[N]; // �������� ��������� �����
		float massX = 0, massY = 0;					 // ���������� ������ ���� ���������� ������� �����
		srand(time(nullptr));						 // ����������� ���������� ����� ��� ��������� ��������� �����


		for (int count = 0; count < N; ++count)
		{
			// ������� rand()/RAND_MAX ������ ��������� ����� �� 0 �� 1
			// ���������� ����� ����� �� ������/������ ����������� ��������� ������ ����� � �������� �� 0 �� ������/������
			X[count] = static_cast<float>(rand()) * (pictureBox->Size.Width - indent) / RAND_MAX;
			Y[count] = static_cast<float>(rand()) * (pictureBox->Size.Height - indent) / RAND_MAX;


			// ��������� ����� � ������������ �,� �������� pointSize 
			g->FillEllipse(Brushes::White, X[count], Y[count], pointSize, pointSize);


			// ���������� ��������� ������ ������� ��� �������� ���������������
			massX += X[count] / N;
			massY += Y[count] / N;
		}


		// ��������� ����� � ������������ ������ �������
		g->FillEllipse(Brushes::Red, massX, massY, pointSize + 5, pointSize + 5);


		// ������ � ���� ���������� �� ������ ����� �� ������ ����
		// ���������� ������������ �� �. ��������
		std::ofstream fout("Distance.txt");
		fout << "���������� ����� �� ������ ���� (" << massX << ", " << massY << ")\n";
		for (int count = 0; count < N; ++count)
		{
			fout << count + 1 << ". ��� ����� (" << X[count] << ", " << Y[count] << ") = ";
			fout << sqrt(pow(abs(X[count] - massX), 2) + pow(abs(Y[count] - massY), 2)) << '\n';
		}


		// ������������ ������
		delete[] X;
		delete[] Y;


		// ������� ���������� ����������� � ������� ����������
		pictureBox->Image = bmp;
	}
	};
}