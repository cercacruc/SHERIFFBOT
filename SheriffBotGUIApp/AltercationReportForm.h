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
	using namespace System::Collections::Generic;

	/// <summary>
	/// Resumen de AltercationReportForm
	/// </summary>
	public ref class AltercationReportForm : public System::Windows::Forms::Form
	{
	public:
		DatosUsuario^ Usuario;

		AltercationReportForm(DatosUsuario^ usuario)
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
		~AltercationReportForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnEnviar;
	private: System::Windows::Forms::Button^ btnVolver;
	protected:

	protected:


	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtDescription;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnCargarImagen;
	private: System::Windows::Forms::PictureBox^ pbPhoto;

	private: System::Windows::Forms::TextBox^ txtLugar;
	private: System::Windows::Forms::DateTimePicker^ dtpFecha;




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
			this->btnEnviar = (gcnew System::Windows::Forms::Button());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtDescription = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnCargarImagen = (gcnew System::Windows::Forms::Button());
			this->pbPhoto = (gcnew System::Windows::Forms::PictureBox());
			this->txtLugar = (gcnew System::Windows::Forms::TextBox());
			this->dtpFecha = (gcnew System::Windows::Forms::DateTimePicker());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhoto))->BeginInit();
			this->SuspendLayout();
			// 
			// btnEnviar
			// 
			this->btnEnviar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnEnviar->Location = System::Drawing::Point(51, 322);
			this->btnEnviar->Name = L"btnEnviar";
			this->btnEnviar->Size = System::Drawing::Size(193, 47);
			this->btnEnviar->TabIndex = 17;
			this->btnEnviar->Text = L"Enviar";
			this->btnEnviar->UseVisualStyleBackColor = true;
			this->btnEnviar->Click += gcnew System::EventHandler(this, &AltercationReportForm::btnEnviar_Click);
			// 
			// btnVolver
			// 
			this->btnVolver->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnVolver->Location = System::Drawing::Point(250, 322);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(193, 47);
			this->btnVolver->TabIndex = 16;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &AltercationReportForm::btnVolver_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(23, 259);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 20);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Fecha y lugar:";
			// 
			// txtDescription
			// 
			this->txtDescription->Location = System::Drawing::Point(18, 90);
			this->txtDescription->Multiline = true;
			this->txtDescription->Name = L"txtDescription";
			this->txtDescription->Size = System::Drawing::Size(227, 166);
			this->txtDescription->TabIndex = 11;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(23, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 20);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Descripción:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(48, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(395, 48);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Reporte de altercado";
			// 
			// btnCargarImagen
			// 
			this->btnCargarImagen->Location = System::Drawing::Point(255, 232);
			this->btnCargarImagen->Margin = System::Windows::Forms::Padding(2);
			this->btnCargarImagen->Name = L"btnCargarImagen";
			this->btnCargarImagen->Size = System::Drawing::Size(207, 24);
			this->btnCargarImagen->TabIndex = 43;
			this->btnCargarImagen->Text = L"Cargar imagen";
			this->btnCargarImagen->UseVisualStyleBackColor = true;
			this->btnCargarImagen->Click += gcnew System::EventHandler(this, &AltercationReportForm::btnCargarImagen_Click);
			// 
			// pbPhoto
			// 
			this->pbPhoto->Location = System::Drawing::Point(256, 90);
			this->pbPhoto->Name = L"pbPhoto";
			this->pbPhoto->Size = System::Drawing::Size(207, 137);
			this->pbPhoto->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbPhoto->TabIndex = 42;
			this->pbPhoto->TabStop = false;
			this->pbPhoto->Click += gcnew System::EventHandler(this, &AltercationReportForm::pbPhoto_Click);
			// 
			// txtLugar
			// 
			this->txtLugar->Location = System::Drawing::Point(255, 282);
			this->txtLugar->Name = L"txtLugar";
			this->txtLugar->Size = System::Drawing::Size(163, 22);
			this->txtLugar->TabIndex = 45;
			// 
			// dtpFecha
			// 
			this->dtpFecha->Location = System::Drawing::Point(27, 282);
			this->dtpFecha->Name = L"dtpFecha";
			this->dtpFecha->Size = System::Drawing::Size(200, 22);
			this->dtpFecha->TabIndex = 44;
			// 
			// AltercationReportForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(484, 385);
			this->Controls->Add(this->txtLugar);
			this->Controls->Add(this->dtpFecha);
			this->Controls->Add(this->btnCargarImagen);
			this->Controls->Add(this->pbPhoto);
			this->Controls->Add(this->btnEnviar);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtDescription);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"AltercationReportForm";
			this->Text = L"AltercationReportForm";
			this->Load += gcnew System::EventHandler(this, &AltercationReportForm::AltercationReportForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhoto))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		private: System::Void btnEnviar_Click(System::Object^ sender, System::EventArgs^ e) {
			Altercado^ alerta = gcnew Altercado();
			alerta->Description = txtDescription->Text;
			alerta->Lugar = txtLugar->Text;

			if (pbPhoto != nullptr && pbPhoto->Image != nullptr) {
				System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream();
				pbPhoto->Image->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
				alerta->Photo = ms->ToArray();
			}

			alerta->Fecha = dtpFecha->Value;

			alerta->Solucionado = false;

			Service::registrarAlerta(alerta);
			MessageBox::Show("Alerta enviada exitosamente", "Exito", MessageBoxButtons::OK);
			ClearFields();
		}
		private: System::Void pbPhoto_Click(System::Object^ sender, System::EventArgs^ e) {
			SearchAndPutImagenOn(pbPhoto);
			MessageBox::Show("Imagen agregada exitosamente", "Exito", MessageBoxButtons::OK);
		}
		private: System::Void btnCargarImagen_Click(System::Object^ sender, System::EventArgs^ e) {
			SearchAndPutImagenOn(pbPhoto);
			MessageBox::Show("Imagen agregada exitosamente", "Exito", MessageBoxButtons::OK);
		}
		private: void SearchAndPutImagenOn(PictureBox^ pb) {//se encarga de poder añadir la foto
			OpenFileDialog^ opfd = gcnew OpenFileDialog();
			opfd->Filter = "Image Files (*.jpg;*.jpeg;)|*.jpg;*.jpeg;";
			if (opfd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				pb->Image = gcnew Bitmap(opfd->FileName);
			}
		}
		private: void ClearFields() {
			if (pbPhoto != nullptr) {
				pbPhoto->Image = nullptr;
				pbPhoto->Invalidate();
			}
			txtDescription->Text = "";
			txtLugar->Text = "";
		}
		private: System::Void AltercationReportForm_Load(System::Object^ sender, System::EventArgs^ e) {
			ClearFields();
		}
	};
}
