#pragma once
#include "UIStyles.h"   // Para UIHelpers: botones redondeados, etc.

namespace GUIApp {

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

			this->DoubleBuffered = true;

			this->BackColor = System::Drawing::Color::FromArgb(5, 8, 22);
			this->ForeColor = System::Drawing::Color::White;
			this->StartPosition = FormStartPosition::CenterScreen;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;

			Usuario = usuario;

			// ---- upgrade visual ----
			ApplyDarkTheme();
			StyleButtonsAndInputs();
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

	private:
		System::Windows::Forms::Button^ btnEnviar;
		System::Windows::Forms::Button^ btnVolver;
		System::Windows::Forms::TextBox^ txtDescripcion;
		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::PictureBox^ pbPhoto;
		System::Windows::Forms::Button^ btnCargarImagen;
		System::Windows::Forms::DateTimePicker^ dtpFecha;
		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::TextBox^ txtLugar;
		System::Windows::Forms::Label^ label3;
		System::Windows::Forms::TextBox^ txtObjeto;

		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MissingObjectForm::typeid));
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
			this->btnEnviar->Location = System::Drawing::Point(34, 404);
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
			this->btnVolver->Location = System::Drawing::Point(244, 404);
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
			this->txtDescripcion->Size = System::Drawing::Size(241, 193);
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
			this->pbPhoto->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MissingObjectForm::PictureBoxBorder_Paint);
			// 
			// btnCargarImagen
			// 
			this->btnCargarImagen->Location = System::Drawing::Point(284, 236);
			this->btnCargarImagen->Margin = System::Windows::Forms::Padding(2);
			this->btnCargarImagen->Name = L"btnCargarImagen";
			this->btnCargarImagen->Size = System::Drawing::Size(153, 46);
			this->btnCargarImagen->TabIndex = 41;
			this->btnCargarImagen->Text = L"Cargar imagen";
			this->btnCargarImagen->UseVisualStyleBackColor = true;
			this->btnCargarImagen->Click += gcnew System::EventHandler(this, &MissingObjectForm::btnCargarImagen_Click);
			// 
			// dtpFecha
			// 
			this->dtpFecha->Location = System::Drawing::Point(42, 363);
			this->dtpFecha->Name = L"dtpFecha";
			this->dtpFecha->Size = System::Drawing::Size(200, 22);
			this->dtpFecha->TabIndex = 42;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(18, 330);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(251, 20);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Fecha, hora y lugar del hallazgo:";
			// 
			// txtLugar
			// 
			this->txtLugar->Location = System::Drawing::Point(274, 363);
			this->txtLugar->Name = L"txtLugar";
			this->txtLugar->Size = System::Drawing::Size(163, 22);
			this->txtLugar->TabIndex = 43;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(18, 299);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 20);
			this->label3->TabIndex = 44;
			this->label3->Text = L"Objeto Encontrado:";
			// 
			// txtObjeto
			// 
			this->txtObjeto->Location = System::Drawing::Point(274, 299);
			this->txtObjeto->Name = L"txtObjeto";
			this->txtObjeto->Size = System::Drawing::Size(163, 22);
			this->txtObjeto->TabIndex = 45;
			// 
			// MissingObjectForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(477, 471);
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MissingObjectForm";
			this->Text = L"Objeto perdido";
			this->Load += gcnew System::EventHandler(this, &MissingObjectForm::MissingObjectForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhoto))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// =============== ESTILO (Dark Theme) ===============

		void ApplyDarkTheme()
		{
			Color back = Color::FromArgb(20, 27, 47);
			Color fore = Color::FromArgb(224, 231, 255);

			this->BackColor = back;

			array<Label^>^ labels = gcnew array<Label^>{
				label1, label2, label3, label4
			};

			for each (Label ^ lb in labels)
			{
				if (lb != nullptr)
				{
					lb->ForeColor = fore;
					lb->BackColor = Color::Transparent;
				}
			}

			// PictureBox fondo oscuro
			if (pbPhoto != nullptr)
				pbPhoto->BackColor = Color::FromArgb(10, 16, 32);
		}

		void StyleButtonsAndInputs()
		{
			// Botón principal: Enviar
			array<Button^>^ primary = gcnew array<Button^> {
				btnEnviar
			};

			for each (Button ^ b in primary)
			{
				if (b == nullptr) continue;
				b->FlatStyle = FlatStyle::Flat;
				b->FlatAppearance->BorderSize = 0;
				b->BackColor = Color::FromArgb(0, 140, 255);
				b->ForeColor = Color::White;
				b->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
				UIHelpers::SetRoundedRegion(b, 18);
			}

			// Botón secundario: Volver
			array<Button^>^ secondary = gcnew array<Button^> {
				btnVolver, btnCargarImagen
			};

			for each (Button ^ b in secondary)
			{
				if (b == nullptr) continue;
				b->FlatStyle = FlatStyle::Flat;
				b->FlatAppearance->BorderSize = 0;
				b->BackColor = Color::FromArgb(20, 27, 47);
				b->ForeColor = Color::FromArgb(224, 231, 255);
				b->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Regular);
				b->Paint += gcnew PaintEventHandler(&UIHelpers::OutlineButton_Paint);
				UIHelpers::SetRoundedRegion(b, 18);
			}

			// TextBoxes en tema oscuro
			Color backBox = Color::FromArgb(10, 16, 32);
			Color foreBox = Color::FromArgb(226, 232, 240);

			array<TextBox^>^ boxes = gcnew array<TextBox^> {
				txtDescripcion, txtLugar, txtObjeto
			};

			for each (TextBox ^ tb in boxes)
			{
				if (tb == nullptr) continue;
				tb->BackColor = backBox;
				tb->ForeColor = foreBox;
				tb->BorderStyle = BorderStyle::FixedSingle;
			}

			// DateTimePicker con fondo oscuro (limitado, pero ayuda un poco)
			if (dtpFecha != nullptr)
			{
				dtpFecha->CalendarForeColor = Color::FromArgb(15, 23, 42);
				dtpFecha->CalendarMonthBackground = Color::FromArgb(30, 41, 59);
			}
		}

		// Borde celeste para PictureBox (igual que en AdminAlertManagementForm)
		void PictureBoxBorder_Paint(System::Object^ sender, PaintEventArgs^ e)
		{
			PictureBox^ pb = safe_cast<PictureBox^>(sender);
			e->Graphics->SmoothingMode =
				System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

			Rectangle rect = pb->ClientRectangle;
			rect.Inflate(-1, -1);   // margen interno

			Pen^ pen = gcnew Pen(Color::FromArgb(56, 189, 248), 2.0f);
			e->Graphics->DrawRectangle(pen, rect);

			delete pen;
		}

		// =============== LÓGICA ORIGINAL ===============

	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void btnEnviar_Click(System::Object^ sender, System::EventArgs^ e) {
		ObjPerdido^ alerta = gcnew ObjPerdido();
		alerta->Description = txtDescripcion->Text;
		alerta->Lugar = txtLugar->Text;
		alerta->ObjetoEncontrado = txtObjeto->Text;

		// vincula con usuario
		alerta->UsuarioID = Usuario->ID;
		alerta->UsuarioNombre = Usuario->Nombre;

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
		MessageBox::Show("Alerta enviada exitosamente", "Éxito", MessageBoxButtons::OK);
		ClearFields();
	}

	private: System::Void pbPhoto_Click(System::Object^ sender, System::EventArgs^ e) {
		SearchAndPutImagenOn(pbPhoto);
		MessageBox::Show("Imagen agregada exitosamente", "Éxito", MessageBoxButtons::OK);
	}

	private: void SearchAndPutImagenOn(PictureBox^ pb) { // se encarga de poder añadir la foto
		OpenFileDialog^ opfd = gcnew OpenFileDialog();
		opfd->Filter = "Image Files (*.jpg;*.jpeg;)|*.jpg;*.jpeg;";
		if (opfd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pb->Image = gcnew Bitmap(opfd->FileName);
		}
	}

	private: System::Void btnCargarImagen_Click(System::Object^ sender, System::EventArgs^ e) {
		SearchAndPutImagenOn(pbPhoto);
		MessageBox::Show("Imagen agregada exitosamente", "Éxito", MessageBoxButtons::OK);
	}

	private: void ClearFields() {
		if (pbPhoto != nullptr) {
			pbPhoto->Image = nullptr;
			pbPhoto->Invalidate();
		}
		txtDescripcion->Clear();
		txtLugar->Clear();
		txtObjeto->Clear();
		dtpFecha->Value = DateTime::Now;
	}

	private: System::Void MissingObjectForm_Load(System::Object^ sender, System::EventArgs^ e) {
		ClearFields();
	}
	};
}
