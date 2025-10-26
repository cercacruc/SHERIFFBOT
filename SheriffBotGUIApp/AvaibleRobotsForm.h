#pragma once

namespace SheriffBotGUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->cmbRobots = (gcnew System::Windows::Forms::ComboBox());
			this->pbPhoto = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtCaracteristicas = (gcnew System::Windows::Forms::TextBox());
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
			// 
			// pbPhoto
			// 
			this->pbPhoto->Location = System::Drawing::Point(17, 59);
			this->pbPhoto->Name = L"pbPhoto";
			this->pbPhoto->Size = System::Drawing::Size(216, 175);
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
			// AvaibleRobotsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(468, 252);
			this->Controls->Add(this->txtCaracteristicas);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pbPhoto);
			this->Controls->Add(this->cmbRobots);
			this->Controls->Add(this->label1);
			this->Name = L"AvaibleRobotsForm";
			this->Text = L"AvaibleRobotsForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhoto))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
