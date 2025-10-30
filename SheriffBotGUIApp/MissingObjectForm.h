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
	/// Resumen de MissingObjectForm
	/// </summary>
	public ref class MissingObjectForm : public System::Windows::Forms::Form
	{
	public:
		DatosUsuario^ Usuario;
		MissingObjectForm(DatosUsuario^ usuario)
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
		~MissingObjectForm()
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





	private: System::Windows::Forms::TextBox^ txtDescripcion;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pbPhoto;

	private: System::Windows::Forms::Button^ btnCargarImagen;
	private: System::Windows::Forms::DateTimePicker^ dtpFecha;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtLugar;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtObjeto;


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
			this->txtDescripcion = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pbPhoto = (gcnew System::Windows::Forms::PictureBox());
			this->btnCargarImagen = (gcnew System::Windows::Forms::Button());
			this->dtpFecha = (gcnew System::Windows::Forms::DateTimePicker());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtLugar = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtObjeto = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhoto))->BeginInit();
			this->SuspendLayout();
			// 
			// btnEnviar
			// 
			this->btnEnviar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnEnviar->Location = System::Drawing::Point(34, 387);
			this->btnEnviar->Name = L"btnEnviar";
			this->btnEnviar->Size = System::Drawing::Size(193, 47);
			this->btnEnviar->TabIndex = 26;
			this->btnEnviar->Text = L"Enviar";
			this->btnEnviar->UseVisualStyleBackColor = true;
			this->btnEnviar->Click += gcnew System::EventHandler(this, &MissingObjectForm::btnEnviar_Click);
			// 
			// btnVolver
			// 
			this->btnVolver->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnVolver->Location = System::Drawing::Point(244, 387);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(193, 47);
			this->btnVolver->TabIndex = 25;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &MissingObjectForm::btnVolver_Click);
			// 
			// txtDescripcion
			// 
			this->txtDescripcion->Location = System::Drawing::Point(10, 89);
			this->txtDescripcion->Multiline = true;
			this->txtDescripcion->Name = L"txtDescripcion";
			this->txtDescripcion->Size = System::Drawing::Size(241, 166);
			this->txtDescripcion->TabIndex = 20;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(15, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(181, 20);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Descripción del objeto:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 22.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(90, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(295, 48);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Objeto perdido";
			// 
			// pbPhoto
			// 
			this->pbPhoto->Location = System::Drawing::Point(257, 89);
			this->pbPhoto->Name = L"pbPhoto";
			this->pbPhoto->Size = System::Drawing::Size(207, 137);
			this->pbPhoto->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbPhoto->TabIndex = 27;
			this->pbPhoto->TabStop = false;
			this->pbPhoto->Click += gcnew System::EventHandler(this, &MissingObjectForm::pbPhoto_Click);
			// 
			// btnCargarImagen
			// 
			this->btnCargarImagen->Location = System::Drawing::Point(256, 231);
			this->btnCargarImagen->Margin = System::Windows::Forms::Padding(2);
			this->btnCargarImagen->Name = L"btnCargarImagen";
			this->btnCargarImagen->Size = System::Drawing::Size(207, 24);
			this->btnCargarImagen->TabIndex = 41;
			this->btnCargarImagen->Text = L"Cargar imagen";
			this->btnCargarImagen->UseVisualStyleBackColor = true;
			this->btnCargarImagen->Click += gcnew System::EventHandler(this, &MissingObjectForm::btnCargarImagen_Click);
			// 
			// dtpFecha
			// 
			this->dtpFecha->Location = System::Drawing::Point(42, 346);
			this->dtpFecha->Name = L"dtpFecha";
			this->dtpFecha->Size = System::Drawing::Size(200, 22);
			this->dtpFecha->TabIndex = 42;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(18, 313);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(251, 20);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Fecha, hora y lugar del hallazgo:";
			// 
			// txtLugar
			// 
			this->txtLugar->Location = System::Drawing::Point(274, 346);
			this->txtLugar->Name = L"txtLugar";
			this->txtLugar->Size = System::Drawing::Size(163, 22);
			this->txtLugar->TabIndex = 43;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(18, 282);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 20);
			this->label3->TabIndex = 44;
			this->label3->Text = L"Objeto Encontrado:";
			// 
			// txtObjeto
			// 
			this->txtObjeto->Location = System::Drawing::Point(274, 282);
			this->txtObjeto->Name = L"txtObjeto";
			this->txtObjeto->Size = System::Drawing::Size(163, 22);
			this->txtObjeto->TabIndex = 45;
			// 
			// MissingObjectForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(477, 452);
			this->Controls->Add(this->txtObjeto);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtLugar);
			this->Controls->Add(this->dtpFecha);
			this->Controls->Add(this->btnCargarImagen);
			this->Controls->Add(this->pbPhoto);
			this->Controls->Add(this->btnEnviar);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtDescripcion);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MissingObjectForm";
			this->Text = L"MissingObjectForm";
			this->Load += gcnew System::EventHandler(this, &MissingObjectForm::MissingObjectForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhoto))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
			this->Close();
		}
		private: System::Void btnEnviar_Click(System::Object^ sender, System::EventArgs^ e) {
			ObjPerdido^ alerta = gcnew ObjPerdido();
			alerta->Description = txtDescripcion->Text;
			alerta->Lugar = txtLugar->Text;
			alerta->ObjetoEncontrado = txtObjeto->Text;

			if (pbPhoto != nullptr && pbPhoto->Image != nullptr) {
				System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream();
				pbPhoto->Image->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
				alerta->Photo = ms->ToArray();
			}

			alerta->Fecha = dtpFecha->Value;
			alerta->Solucionado = false;

			if (Usuario != nullptr && Usuario->cant_alertas != nullptr) {
				Usuario->cant_alertas[0] += 1;
				Service::modificarUsuarioID(Usuario);
			}

			Service::registrarAlerta(alerta);
			MessageBox::Show("Alerta enviada exitosamente", "Exito", MessageBoxButtons::OK);
			ClearFields();
		}
		private: System::Void pbPhoto_Click(System::Object^ sender, System::EventArgs^ e) {
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
		private: System::Void btnCargarImagen_Click(System::Object^ sender, System::EventArgs^ e) {
			SearchAndPutImagenOn(pbPhoto);
			MessageBox::Show("Imagen agregada exitosamente", "Exito", MessageBoxButtons::OK);
		}
		private: void ClearFields() {
			if (pbPhoto != nullptr) {
				pbPhoto->Image = nullptr;
				pbPhoto->Invalidate();
			}
			txtDescripcion->Clear();
			txtLugar->Clear();
			txtObjeto->Clear();
		}
		private: System::Void MissingObjectForm_Load(System::Object^ sender, System::EventArgs^ e) {
			ClearFields();
		}
	};
}
