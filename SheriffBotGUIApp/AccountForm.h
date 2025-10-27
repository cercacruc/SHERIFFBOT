#pragma once

namespace SheriffBotGUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace BotModel;
	using namespace BotService;

	/// <summary>
	/// Resumen de AccountForm
	/// </summary>
	public ref class AccountForm : public System::Windows::Forms::Form
	{
	public:
		DatosUsuario^ Usuario;

		AccountForm(DatosUsuario^ usuario)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			Usuario = usuario;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~AccountForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnReturnPassword;
	protected:



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::TextBox^ textUsuario;
	private: System::Windows::Forms::TextBox^ textID;
	private: System::Windows::Forms::TextBox^ textCargo;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AccountForm::typeid));
			this->btnReturnPassword = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textUsuario = (gcnew System::Windows::Forms::TextBox());
			this->textID = (gcnew System::Windows::Forms::TextBox());
			this->textCargo = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnReturnPassword
			// 
			this->btnReturnPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnReturnPassword->Location = System::Drawing::Point(37, 437);
			this->btnReturnPassword->Name = L"btnReturnPassword";
			this->btnReturnPassword->Size = System::Drawing::Size(193, 47);
			this->btnReturnPassword->TabIndex = 30;
			this->btnReturnPassword->Text = L"Volver";
			this->btnReturnPassword->UseVisualStyleBackColor = true;
			this->btnReturnPassword->Click += gcnew System::EventHandler(this, &AccountForm::btnReturnPassword_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->label1->Location = System::Drawing::Point(82, 168);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 31);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Usuario";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(79, 42);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(111, 114);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 25;
			this->pictureBox1->TabStop = false;
			// 
			// textUsuario
			// 
			this->textUsuario->Location = System::Drawing::Point(53, 238);
			this->textUsuario->Name = L"textUsuario";
			this->textUsuario->Size = System::Drawing::Size(167, 22);
			this->textUsuario->TabIndex = 32;
			// 
			// textID
			// 
			this->textID->Location = System::Drawing::Point(53, 303);
			this->textID->Name = L"textID";
			this->textID->Size = System::Drawing::Size(167, 22);
			this->textID->TabIndex = 33;
			// 
			// textCargo
			// 
			this->textCargo->Location = System::Drawing::Point(53, 368);
			this->textCargo->Name = L"textCargo";
			this->textCargo->Size = System::Drawing::Size(167, 22);
			this->textCargo->TabIndex = 34;
			// 
			// AccountForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(275, 518);
			this->Controls->Add(this->textCargo);
			this->Controls->Add(this->textID);
			this->Controls->Add(this->textUsuario);
			this->Controls->Add(this->btnReturnPassword);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"AccountForm";
			this->Text = L"AccountForm";
			this->Load += gcnew System::EventHandler(this, &AccountForm::AccountForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
		private: System::Void AccountForm_Load(System::Object^ sender, System::EventArgs^ e) {
			CargarDatosUsuario(Usuario->Nombre);
		}
		private: void CargarDatosUsuario(String^ username) {
			DatosUsuario^ encontrado = Service::buscarUsuarioNombre(username);
			textUsuario->Text = username;
			textID->Text = Convert::ToString(encontrado->ID);
			textCargo->Text = encontrado->Cargo;
		}
		private: System::Void btnReturnPassword_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
	};
}
