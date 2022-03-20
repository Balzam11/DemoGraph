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
	/// Сводка для MyForm
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
		/// Освободить все используемые ресурсы.
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
			this->generateBtn->Text = L"Сгенерировать";
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
			this->Text = L"Точки";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		// при вводе не числовых символов ввод не обрабатывается и поле остаётся пустым
	private: System::Void textBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		if (!Char::IsDigit(e->KeyChar))
			e->Handled = true; // Handled - возвращает сообщение о том, было ли обработано событие
		else
			generateBtn->Enabled = true;
	}


		   // при нажатии кнопки "Сгенерировать" запускается процесс отрисовки точек на плоскости
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int N;												// переменная N будет хранить число точек, введенное пользователем
		if (String::IsNullOrEmpty(textBox->Text) || Convert::ToInt16(textBox->Text) == 0)
			exit(-1);										// если строка останется пустой или будет введён ноль, то программа завершится
		else
			N = System::Convert::ToInt16(textBox->Text);    // иначе введённое число N преобразуется из строчного типа в целочисленный


		Bitmap^ bmp = gcnew Bitmap(pictureBox->Width, pictureBox->Height); // переменная, задающее растровое изображение
		Graphics^ g = Graphics::FromImage(bmp);							   // подключение графического интерфейса к созданному изображению


		g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias; // режим сглаживания для отрисовки
		g->Clear(Color::Navy);									// очистка поверхности и заполнение цветом (тёмно-синий)


		const float pointSize = 5;					 // диаметр точек на плоскости
		const int indent = 10;						 // отступ от границы плоскости рисования для того чтобы точки не выходили за её рамки
		float* X = new float[N], * Y = new float[N]; // хранение координат точек
		float massX = 0, massY = 0;					 // координаты центра масс полученной системы точек
		srand(time(nullptr));						 // определение начального числа для генерации случайных чисел


		for (int count = 0; count < N; ++count)
		{
			// частное rand()/RAND_MAX задаст случайное число от 0 до 1
			// домножение этого числа на ширину/высоту поверхности рисования задаст число в пределах от 0 до ширина/высота
			X[count] = static_cast<float>(rand()) * (pictureBox->Size.Width - indent) / RAND_MAX;
			Y[count] = static_cast<float>(rand()) * (pictureBox->Size.Height - indent) / RAND_MAX;


			// рисование круга с координатами х,у диаметра pointSize 
			g->FillEllipse(Brushes::White, X[count], Y[count], pointSize, pointSize);


			// вычисление координат центра массива как среднего арифмитического
			massX += X[count] / N;
			massY += Y[count] / N;
		}


		// рисование круга с координатами центра массива
		g->FillEllipse(Brushes::Red, massX, massY, pointSize + 5, pointSize + 5);


		// запись в файл расстояний от каждой точки до центра масс
		// расстояние определяется по т. Пифагора
		std::ofstream fout("Distance.txt");
		fout << "Расстояния точек до центра масс (" << massX << ", " << massY << ")\n";
		for (int count = 0; count < N; ++count)
		{
			fout << count + 1 << ". для точки (" << X[count] << ", " << Y[count] << ") = ";
			fout << sqrt(pow(abs(X[count] - massX), 2) + pow(abs(Y[count] - massY), 2)) << '\n';
		}


		// освобождение памяти
		delete[] X;
		delete[] Y;


		// перенос растрового изображения в элемент управления
		pictureBox->Image = bmp;
	}
	};
}