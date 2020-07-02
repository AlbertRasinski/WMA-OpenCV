#pragma once
#include "OpenCVClass.h"
#include <msclr\marshal_cppstd.h>

OpenCVClass OpenCV;

int Tryb = 1;
bool WlaczeniePrzetwarzania = false;
int WyswietlaneKarty = 0;


namespace WidzenieMaszynoweProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
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

	private: System::Windows::Forms::Button^ sciezka;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBoxSciezka;

	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::GroupBox^ groupBox1;


	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::TrackBar^ trackBar1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TrackBar^ trackBar2;
	private: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->sciezka = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBoxSciezka = (gcnew System::Windows::Forms::TextBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->trackBar2 = (gcnew System::Windows::Forms::TrackBar());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// sciezka
			// 
			this->sciezka->BackColor = System::Drawing::SystemColors::Control;
			this->sciezka->Cursor = System::Windows::Forms::Cursors::Hand;
			this->sciezka->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->sciezka->Location = System::Drawing::Point(462, 62);
			this->sciezka->Name = L"sciezka";
			this->sciezka->Size = System::Drawing::Size(26, 26);
			this->sciezka->TabIndex = 1;
			this->sciezka->Text = L"...";
			this->sciezka->UseVisualStyleBackColor = false;
			this->sciezka->Click += gcnew System::EventHandler(this, &MyForm::sciezka_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBoxSciezka
			// 
			this->textBoxSciezka->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxSciezka->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->textBoxSciezka->Location = System::Drawing::Point(20, 62);
			this->textBoxSciezka->Name = L"textBoxSciezka";
			this->textBoxSciezka->ReadOnly = true;
			this->textBoxSciezka->Size = System::Drawing::Size(436, 26);
			this->textBoxSciezka->TabIndex = 3;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->BackColor = System::Drawing::Color::Transparent;
			this->radioButton2->Checked = true;
			this->radioButton2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton2->Location = System::Drawing::Point(95, 25);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(124, 24);
			this->radioButton2->TabIndex = 5;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"filmik z pliku";
			this->radioButton2->UseVisualStyleBackColor = false;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton2_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->textBoxSciezka);
			this->groupBox1->Controls->Add(this->sciezka);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->groupBox1->Location = System::Drawing::Point(20, 20);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(516, 101);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Opcje wyboru";
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->BackColor = System::Drawing::Color::Transparent;
			this->radioButton3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->radioButton3->Location = System::Drawing::Point(326, 25);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(83, 24);
			this->radioButton3->TabIndex = 10;
			this->radioButton3->Text = L"zdjecie";
			this->radioButton3->UseVisualStyleBackColor = false;
			this->radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton3_CheckedChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->Location = System::Drawing::Point(1097, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 100);
			this->button1->TabIndex = 7;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::White;
			this->pictureBox2->Location = System::Drawing::Point(38, 404);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(480, 270);
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			// 
			// trackBar1
			// 
			this->trackBar1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar1->LargeChange = 10;
			this->trackBar1->Location = System::Drawing::Point(6, 40);
			this->trackBar1->Maximum = 255;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(249, 45);
			this->trackBar1->SmallChange = 5;
			this->trackBar1->TabIndex = 7;
			this->trackBar1->Tag = L"";
			this->trackBar1->TickFrequency = 5;
			this->trackBar1->Value = 100;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar1_Scroll);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::Transparent;
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->trackBar2);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->trackBar1);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->groupBox2->Location = System::Drawing::Point(553, 20);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(515, 101);
			this->groupBox2->TabIndex = 8;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Opcje wykrywania";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label5->Location = System::Drawing::Point(481, 70);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 20);
			this->label5->TabIndex = 14;
			this->label5->Text = L"25";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label6->Location = System::Drawing::Point(261, 71);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(19, 20);
			this->label6->TabIndex = 13;
			this->label6->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(271, 16);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(230, 20);
			this->label7->TabIndex = 12;
			this->label7->Text = L"oczekiwane pole karty: 10%";
			// 
			// trackBar2
			// 
			this->trackBar2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->trackBar2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->trackBar2->LargeChange = 10;
			this->trackBar2->Location = System::Drawing::Point(261, 40);
			this->trackBar2->Maximum = 25;
			this->trackBar2->Name = L"trackBar2";
			this->trackBar2->Size = System::Drawing::Size(249, 45);
			this->trackBar2->TabIndex = 11;
			this->trackBar2->Tag = L"";
			this->trackBar2->Value = 10;
			this->trackBar2->Scroll += gcnew System::EventHandler(this, &MyForm::trackBar2_Scroll);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label4->Location = System::Drawing::Point(216, 71);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 20);
			this->label4->TabIndex = 10;
			this->label4->Text = L"255";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->label3->Location = System::Drawing::Point(6, 71);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 20);
			this->label3->TabIndex = 9;
			this->label3->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 20);
			this->label2->TabIndex = 8;
			this->label2->Text = L"progowanie: 100";
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::White;
			this->pictureBox3->Location = System::Drawing::Point(573, 195);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(310, 435);
			this->pictureBox3->TabIndex = 9;
			this->pictureBox3->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackColor = System::Drawing::Color::White;
			this->pictureBox4->Location = System::Drawing::Point(902, 195);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(310, 435);
			this->pictureBox4->TabIndex = 10;
			this->pictureBox4->TabStop = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(570, 169);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 20);
			this->label8->TabIndex = 11;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(898, 169);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 20);
			this->label9->TabIndex = 12;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button2->Location = System::Drawing::Point(1218, 354);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(34, 97);
			this->button2->TabIndex = 13;
			this->button2->Text = L">";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button3->Location = System::Drawing::Point(533, 354);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(34, 97);
			this->button3->TabIndex = 14;
			this->button3->Text = L"<";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(38, 126);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(480, 270);
			this->pictureBox1->TabIndex = 15;
			this->pictureBox1->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Rasiñski Albert- Widzenie Maszynowe- Projekt";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void sciezka_Click(System::Object^ sender, System::EventArgs^ e) {
		IO::Stream^ myStream;
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if ((myStream = openFileDialog1->OpenFile()) != nullptr) {
				String^ strfilename = openFileDialog1->InitialDirectory + openFileDialog1->FileName;
				OpenCV.SciezkaDoFilmu = msclr::interop::marshal_as<std::string>(strfilename);
					this->textBoxSciezka->Text = strfilename;
					myStream->Close();
					std::string tmp = "";
					for (int i = 0; i < OpenCV.SciezkaDoFilmu.length(); ++i) {
						if (OpenCV.SciezkaDoFilmu[i] == '\\') {
							tmp += "\\\\";
						}
						else {
							tmp += OpenCV.SciezkaDoFilmu[i];
						}
					}
					OpenCV.SciezkaDoFilmu = tmp;
			}
		}

		
	}

private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->textBoxSciezka->Visible = true;
	this->sciezka->Visible = true;
	Tryb = 1;
}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->textBoxSciezka->Visible = false;
	this->sciezka->Visible = false;
	Tryb = 2;
	}

private: 
	System::Drawing::Bitmap^ konwertuj(cv::Mat inputimg, int x, int y) {
		cv::resize(inputimg, inputimg, cv::Size(x, y));
		cv::cvtColor(inputimg, inputimg, cv::COLOR_RGB2RGBA);
		auto hBitmap = CreateBitmap(inputimg.cols, inputimg.rows, 1, 32, inputimg.data);
		auto a = System::Drawing::Bitmap::FromHbitmap((System::IntPtr)hBitmap);
		return a;
	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->pictureBox2->Image = konwertuj(OpenCV.CardTemplate[19], 310, 435);
	this->pictureBox3->Image = konwertuj(OpenCV.CardTemplate[19], 480, 270);
	this->pictureBox4->Image = konwertuj(OpenCV.CardTemplate[19], 480, 270);
	WyswietlaneKarty = 0;
	cv::Mat Image;
	int przeliczone = 0;
	if (Tryb == 3) {
		Image = cv::imread(OpenCV.SciezkaDoFilmu);
		OpenCV.Wykrywanie(Image, WlaczeniePrzetwarzania);
		this->pictureBox1->Image = konwertuj(Image,480,270);
		this->pictureBox2->Image = konwertuj(OpenCV.ObrazKoncowy, 480, 270);
		if (OpenCV.Card.size() > 0) {
			this->pictureBox3->Image = konwertuj(OpenCV.Card[WyswietlaneKarty].Karta, 310, 435);
			std::string nazwa1 = "";
			nazwa1 += OpenCV.Card[WyswietlaneKarty].znak;
			nazwa1 += OpenCV.Card[WyswietlaneKarty].symbol;
			nazwa1 += OpenCV.Card[WyswietlaneKarty].kolor;
			this->label8->Text = gcnew String(nazwa1.c_str());
			if (OpenCV.Card.size() > 1) {
				this->pictureBox4->Image = konwertuj(OpenCV.Card[WyswietlaneKarty + 1].Karta, 310, 435);
				std::string nazwa2 = "";
				nazwa2 += OpenCV.Card[WyswietlaneKarty + 1].znak;
				nazwa2 += OpenCV.Card[WyswietlaneKarty + 1].symbol;
				nazwa2 += OpenCV.Card[WyswietlaneKarty + 1].kolor;
				this->label9->Text = gcnew String(nazwa2.c_str());
			}
		}
	}
	else if (Tryb == 1) {
		cv::Mat Frame;
		cv::VideoCapture cap(OpenCV.SciezkaDoFilmu);
		cap.read(Frame);
		while (cap.read(Frame)) {
			this->pictureBox1->Image = konwertuj(Frame, 480, 270);
			if (OpenCV.Skora(Frame)) {
				WlaczeniePrzetwarzania = false;
			}
			else {
				if (WlaczeniePrzetwarzania == false) {
					WyswietlaneKarty = 0;
					OpenCV.Wykrywanie(Frame, WlaczeniePrzetwarzania);
					this->pictureBox2->Image = konwertuj(OpenCV.ObrazKoncowy, 480, 270);
					if (OpenCV.Card.size() > 0) {
						this->pictureBox3->Image = konwertuj(OpenCV.Card[WyswietlaneKarty].Karta, 310, 435);
						std::string nazwa1 = "";
						nazwa1 += OpenCV.Card[WyswietlaneKarty].znak;
						nazwa1 += OpenCV.Card[WyswietlaneKarty].symbol;
						nazwa1 += OpenCV.Card[WyswietlaneKarty].kolor;
						this->label8->Text = gcnew String(nazwa1.c_str());
						if (OpenCV.Card.size() > 1) {
							this->pictureBox4->Image = konwertuj(OpenCV.Card[WyswietlaneKarty + 1].Karta, 310, 435);
							std::string nazwa2 = "";
							nazwa2 += OpenCV.Card[WyswietlaneKarty + 1].znak;
							nazwa2 += OpenCV.Card[WyswietlaneKarty + 1].symbol;
							nazwa2 += OpenCV.Card[WyswietlaneKarty + 1].kolor;
							this->label9->Text = gcnew String(nazwa2.c_str());
						}
					}
				}
			}
			if (cv::waitKey(10) == 27) {
				break;
			}
		}
	}
}

private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	OpenCV.ThreshholdValue = Decimal::ToInt32(this->trackBar1->Value);
	std::string TekstDoLabel = "progowanie: ";
	TekstDoLabel += std::to_string(OpenCV.ThreshholdValue);
	this->label2->Text = gcnew String(TekstDoLabel.c_str());
}

private: System::Void trackBar2_Scroll(System::Object^ sender, System::EventArgs^ e) {
	OpenCV.AreaCard = Decimal::ToInt32(this->trackBar2->Value);
	std::string TekstDoLabel = "oczekiwane pole karty : ";
	TekstDoLabel += std::to_string(OpenCV.AreaCard);
	TekstDoLabel += "%";
	this->label7->Text = gcnew String(TekstDoLabel.c_str());
}

private: System::Void radioButton3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	this->textBoxSciezka->Visible = true;
	this->sciezka->Visible = true;
	Tryb = 3;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (OpenCV.Card.size() != 0) {
		if (OpenCV.Card.size() != 1) {
			if (WyswietlaneKarty < (OpenCV.Card.size() - 2)) {
				++WyswietlaneKarty;
				this->pictureBox3->Image = konwertuj(OpenCV.Card[WyswietlaneKarty].Karta, 310, 435);
				this->pictureBox4->Image = konwertuj(OpenCV.Card[WyswietlaneKarty + 1].Karta, 310, 435);
				std::string nazwa1 = "";
				nazwa1 += OpenCV.Card[WyswietlaneKarty].znak;
				nazwa1 += OpenCV.Card[WyswietlaneKarty].symbol;
				nazwa1 += OpenCV.Card[WyswietlaneKarty].kolor;
				this->label8->Text = gcnew String(nazwa1.c_str());
				std::string nazwa2 = "";
				nazwa2 += OpenCV.Card[WyswietlaneKarty + 1].znak;
				nazwa2 += OpenCV.Card[WyswietlaneKarty + 1].symbol;
				nazwa2 += OpenCV.Card[WyswietlaneKarty + 1].kolor;
				this->label9->Text = gcnew String(nazwa2.c_str());
			}
		}
	}
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (WyswietlaneKarty > 0) {
		--WyswietlaneKarty;
		this->pictureBox3->Image = konwertuj(OpenCV.Card[WyswietlaneKarty].Karta, 310, 435);
		this->pictureBox4->Image = konwertuj(OpenCV.Card[WyswietlaneKarty + 1].Karta, 310, 435);
		std::string nazwa1 = "";
		nazwa1 += OpenCV.Card[WyswietlaneKarty].znak;
		nazwa1 += OpenCV.Card[WyswietlaneKarty].symbol;
		nazwa1 += OpenCV.Card[WyswietlaneKarty].kolor;
		this->label8->Text = gcnew String(nazwa1.c_str());
		std::string nazwa2 = "";
		nazwa2 += OpenCV.Card[WyswietlaneKarty + 1].znak;
		nazwa2 += OpenCV.Card[WyswietlaneKarty + 1].symbol;
		nazwa2 += OpenCV.Card[WyswietlaneKarty + 1].kolor;
		this->label9->Text = gcnew String(nazwa2.c_str());
	}
}

};
}
