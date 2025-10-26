#pragma once

namespace SheriffBotGUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de ControlRobotForm
	/// </summary>
	public ref class ControlRobotForm : public System::Windows::Forms::Form
	{
	public:
		ControlRobotForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~ControlRobotForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ giroIzquierda;
	protected:

	private: System::Windows::Forms::PictureBox^ giroDerecha;
	protected:

	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ btnLeft;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtRobot;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ControlRobotForm::typeid));
			this->giroIzquierda = (gcnew System::Windows::Forms::PictureBox());
			this->giroDerecha = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->btnLeft = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtRobot = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->giroIzquierda))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->giroDerecha))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnLeft))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// giroIzquierda
			// 
			this->giroIzquierda->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"giroIzquierda.Image")));
			this->giroIzquierda->Location = System::Drawing::Point(12, 411);
			this->giroIzquierda->Name = L"giroIzquierda";
			this->giroIzquierda->Size = System::Drawing::Size(182, 155);
			this->giroIzquierda->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->giroIzquierda->TabIndex = 21;
			this->giroIzquierda->TabStop = false;
			this->giroIzquierda->Click += gcnew System::EventHandler(this, &ControlRobotForm::giroIzquierda_Click);
			// 
			// giroDerecha
			// 
			this->giroDerecha->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"giroDerecha.Image")));
			this->giroDerecha->Location = System::Drawing::Point(543, 411);
			this->giroDerecha->Name = L"giroDerecha";
			this->giroDerecha->Size = System::Drawing::Size(182, 155);
			this->giroDerecha->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->giroDerecha->TabIndex = 20;
			this->giroDerecha->TabStop = false;
			this->giroDerecha->Click += gcnew System::EventHandler(this, &ControlRobotForm::giroDerecha_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(308, 531);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(107, 95);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox5->TabIndex = 19;
			this->pictureBox5->TabStop = false;
			this->pictureBox5->Click += gcnew System::EventHandler(this, &ControlRobotForm::pictureBox5_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(308, 354);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(107, 95);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox4->TabIndex = 18;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &ControlRobotForm::pictureBox4_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(406, 443);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(107, 95);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 17;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &ControlRobotForm::pictureBox3_Click);
			// 
			// btnLeft
			// 
			this->btnLeft->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnLeft.Image")));
			this->btnLeft->Location = System::Drawing::Point(211, 443);
			this->btnLeft->Name = L"btnLeft";
			this->btnLeft->Size = System::Drawing::Size(107, 95);
			this->btnLeft->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnLeft->TabIndex = 16;
			this->btnLeft->TabStop = false;
			this->btnLeft->Click += gcnew System::EventHandler(this, &ControlRobotForm::btnLeft_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label3->Location = System::Drawing::Point(11, 79);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(205, 29);
			this->label3->TabIndex = 15;
			this->label3->Text = L"Cámara del robot:";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(417, 122);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(291, 197);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 14;
			this->pictureBox2->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label2->Location = System::Drawing::Point(412, 79);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(214, 29);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Posición del robot:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(16, 122);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(294, 198);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 12;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(171, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(183, 29);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Controlar Robot";
			// 
			// txtRobot
			// 
			this->txtRobot->Location = System::Drawing::Point(360, 29);
			this->txtRobot->Multiline = true;
			this->txtRobot->Name = L"txtRobot";
			this->txtRobot->Size = System::Drawing::Size(138, 29);
			this->txtRobot->TabIndex = 22;
			// 
			// ControlRobotForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(741, 639);
			this->Controls->Add(this->txtRobot);
			this->Controls->Add(this->giroIzquierda);
			this->Controls->Add(this->giroDerecha);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->btnLeft);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Name = L"ControlRobotForm";
			this->Text = L"ControlRobotForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->giroIzquierda))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->giroDerecha))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnLeft))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
		private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show("Avanzo", "Exito", MessageBoxButtons::OK);
		}
		private: System::Void pictureBox5_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show("Retrocedo", "Exito", MessageBoxButtons::OK);
		}
		private: System::Void btnLeft_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show("Avanzo hacia la izquierda", "Exito", MessageBoxButtons::OK);
		}
		private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show("Avanzo hacia la derecha", "Exito", MessageBoxButtons::OK);
		}
		private: System::Void giroDerecha_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show("Giro hacia la derecha", "Exito", MessageBoxButtons::OK);
		}
		private: System::Void giroIzquierda_Click(System::Object^ sender, System::EventArgs^ e) {
			MessageBox::Show("Giro hacia la izquierda", "Exito", MessageBoxButtons::OK);
		}
	};
}
