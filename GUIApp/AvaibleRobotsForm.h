#pragma once
#include "ComboBoxItem.h"

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Collections::Generic;
	using namespace BotModel;
	using namespace BotService;

	/// <summary>
	/// Resumen de AvaibleRobotsForm
	/// </summary>
	public ref class AvaibleRobotsForm : public System::Windows::Forms::Form
	{
	public:
		AvaibleRobotsForm(void)
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
		~AvaibleRobotsForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ cmbRobots;
	private: System::Windows::Forms::PictureBox^ pbPhoto;




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtCaracteristicas;
	private: System::Windows::Forms::Button^ btnVolver;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cmbRobots = (gcnew System::Windows::Forms::ComboBox());
			this->pbPhoto = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtCaracteristicas = (gcnew System::Windows::Forms::TextBox());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhoto))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(221, 29);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Robots disponibles";
			// 
			// cmbRobots
			// 
			this->cmbRobots->FormattingEnabled = true;
			this->cmbRobots->Location = System::Drawing::Point(239, 16);
			this->cmbRobots->Name = L"cmbRobots";
			this->cmbRobots->Size = System::Drawing::Size(215, 24);
			this->cmbRobots->TabIndex = 3;
			this->cmbRobots->SelectedIndexChanged += gcnew System::EventHandler(this, &AvaibleRobotsForm::cmbRobots_SelectedIndexChanged);
			// 
			// pbPhoto
			// 
			this->pbPhoto->Location = System::Drawing::Point(17, 59);
			this->pbPhoto->Name = L"pbPhoto";
			this->pbPhoto->Size = System::Drawing::Size(216, 175);
			this->pbPhoto->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbPhoto->TabIndex = 4;
			this->pbPhoto->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(249, 59);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 16);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Características";
			// 
			// txtCaracteristicas
			// 
			this->txtCaracteristicas->Location = System::Drawing::Point(252, 78);
			this->txtCaracteristicas->Multiline = true;
			this->txtCaracteristicas->Name = L"txtCaracteristicas";
			this->txtCaracteristicas->Size = System::Drawing::Size(202, 156);
			this->txtCaracteristicas->TabIndex = 7;
			// 
			// btnVolver
			// 
			this->btnVolver->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnVolver->Location = System::Drawing::Point(136, 258);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(193, 47);
			this->btnVolver->TabIndex = 25;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &AvaibleRobotsForm::btnVolver_Click);
			// 
			// AvaibleRobotsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(468, 317);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->txtCaracteristicas);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pbPhoto);
			this->Controls->Add(this->cmbRobots);
			this->Controls->Add(this->label1);
			this->Name = L"AvaibleRobotsForm";
			this->Text = L"AvaibleRobotsForm";
			this->Load += gcnew System::EventHandler(this, &AvaibleRobotsForm::AvaibleRobotsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhoto))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AvaibleRobotsForm_Load(System::Object^ sender, System::EventArgs^ e) {
		CargarRobotsDisponibles();
		txtCaracteristicas->Enabled = false;
	}
	private: void CargarRobotsDisponibles() {
		List<Robot^>^ robots = Service::listaRobotsDisponibles();
		cmbRobots->Visible = true;
		cmbRobots->Enabled = true;
		cmbRobots->Items->Clear();

		for each (Robot ^ robot in robots) {
			cmbRobots->Items->Add(robot->Nombre);
		}
	}
	private: System::Void cmbRobots_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		Robot^ robotElegido = Service::buscarRobotNombre(cmbRobots->Text);
		txtCaracteristicas->Text = robotElegido->Caracteristicas;
		ActualizarFotoRobot(robotElegido);
	}
	private: void ActualizarFotoRobot(Robot^ robot) {
		if (robot->Photo != nullptr) {
			System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(robot->Photo);
			pbPhoto->Image = Image::FromStream(ms);
		}
		else {
			pbPhoto->Image = nullptr;
			pbPhoto->Invalidate();
		}
	}
	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
