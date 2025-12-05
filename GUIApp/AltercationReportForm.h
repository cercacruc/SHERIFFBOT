#pragma once
#include "UIStyles.h"

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;


	using namespace BotModel;
	using namespace BotService;
	using namespace System::Collections::Generic;

	public ref class AltercationReportForm : public System::Windows::Forms::Form
	{
	public:
		DatosUsuario^ Usuario;

		AltercationReportForm(DatosUsuario^ usuario)
		{
			InitializeComponent();

			this->DoubleBuffered = true;
			Usuario = usuario;

			ApplyDarkTheme();
			StyleButtons();
			StyleInputs();
		}

	protected:
		~AltercationReportForm()
		{
			if (components)
				delete components;
		}

	private:
		System::Windows::Forms::Button^ btnEnviar;
		System::Windows::Forms::Button^ btnVolver;

		System::Windows::Forms::Label^ label4;
		System::Windows::Forms::TextBox^ txtDescription;

		System::Windows::Forms::Label^ label2;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Button^ btnCargarImagen;
		System::Windows::Forms::PictureBox^ pbPhoto;

		System::Windows::Forms::TextBox^ txtLugar;
		System::Windows::Forms::DateTimePicker^ dtpFecha;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources =
				(gcnew System::ComponentModel::ComponentResourceManager(AltercationReportForm::typeid));
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
			this->btnEnviar->TabIndex = 4;
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
			this->btnVolver->TabIndex = 5;
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
			this->label4->TabIndex = 6;
			this->label4->Text = L"Fecha y lugar:";
			// 
			// txtDescription
			// 
			this->txtDescription->Location = System::Drawing::Point(18, 90);
			this->txtDescription->Multiline = true;
			this->txtDescription->Name = L"txtDescription";
			this->txtDescription->Size = System::Drawing::Size(227, 166);
			this->txtDescription->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(23, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Descripción:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(
				L"Microsoft YaHei UI", 22.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(48, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(395, 48);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Reporte de altercado";
			// 
			// btnCargarImagen
			// 
			this->btnCargarImagen->Location = System::Drawing::Point(255, 232);
			this->btnCargarImagen->Margin = System::Windows::Forms::Padding(2);
			this->btnCargarImagen->Name = L"btnCargarImagen";
			this->btnCargarImagen->Size = System::Drawing::Size(207, 24);
			this->btnCargarImagen->TabIndex = 3;
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
			this->pbPhoto->TabIndex = 7;
			this->pbPhoto->TabStop = false;
			this->pbPhoto->Click += gcnew System::EventHandler(this, &AltercationReportForm::pbPhoto_Click);
			this->pbPhoto->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &AltercationReportForm::PictureBoxBorder_Paint);

			// 
			// txtLugar
			// 
			this->txtLugar->Location = System::Drawing::Point(255, 282);
			this->txtLugar->Name = L"txtLugar";
			this->txtLugar->Size = System::Drawing::Size(163, 22);
			this->txtLugar->TabIndex = 3;
			// 
			// dtpFecha
			// 
			this->dtpFecha->Location = System::Drawing::Point(27, 282);
			this->dtpFecha->Name = L"dtpFecha";
			this->dtpFecha->Size = System::Drawing::Size(200, 22);
			this->dtpFecha->TabIndex = 2;
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
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(
				resources->GetObject(L"$this.Icon")));
			this->Name = L"AltercationReportForm";
			this->Text = L"Reporte de altercado";
			this->Load += gcnew System::EventHandler(this, &AltercationReportForm::AltercationReportForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPhoto))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// ========= ESTILOS =========

		void ApplyDarkTheme()
		{
			Color back = Color::FromArgb(20, 27, 47);
			Color fore = Color::FromArgb(224, 231, 255);

			this->BackColor = back;
			this->ForeColor = fore;

			array<Label^>^ labels = gcnew array<Label^> { label1, label2, label4 };
			for each (Label ^ lb in labels)
			{
				if (lb != nullptr)
					lb->ForeColor = fore;
			}
		}

		void StyleButtons()
		{
			// Botón primario: Enviar
			array<Button^>^ primaryButtons = gcnew array<Button^> { btnEnviar };

			for each (Button ^ b in primaryButtons)
			{
				if (b == nullptr) continue;
				b->FlatStyle = FlatStyle::Flat;
				b->FlatAppearance->BorderSize = 0;
				b->BackColor = Color::FromArgb(0, 140, 255);
				b->ForeColor = Color::White;
				b->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
				UIHelpers::SetRoundedRegionAuto(b);
			}

			// Botones secundarios: Volver, Cargar imagen
			array<Button^>^ secondaryButtons = gcnew array<Button^> { btnVolver, btnCargarImagen };

			for each (Button ^ b in secondaryButtons)
			{
				if (b == nullptr) continue;
				b->FlatStyle = FlatStyle::Flat;
				b->FlatAppearance->BorderSize = 0;
				b->BackColor = Color::FromArgb(20, 27, 47);
				b->ForeColor = Color::FromArgb(224, 231, 255);
				b->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Regular);
				b->Paint += gcnew PaintEventHandler(&UIHelpers::OutlineButton_Paint);
				UIHelpers::SetRoundedRegionAuto(b);
			}
		}

		void StyleInputs()
		{
			Color back = Color::FromArgb(10, 16, 32);
			Color fore = Color::FromArgb(226, 232, 240);

			array<TextBox^>^ boxes = gcnew array<TextBox^> {
				txtDescription, txtLugar
			};

			for each (TextBox ^ tb in boxes)
			{
				if (tb == nullptr) continue;
				tb->BackColor = back;
				tb->ForeColor = fore;
				tb->BorderStyle = BorderStyle::FixedSingle;
			}

			// DateTimePicker: al menos le bajamos el fondo oscuro
			if (dtpFecha != nullptr) {
				dtpFecha->CalendarMonthBackground = back;
				dtpFecha->CalendarForeColor = fore;
			}
		}
		private: System::Void PictureBoxBorder_Paint(System::Object^ sender, PaintEventArgs^ e) {
			PictureBox^ pb = safe_cast<PictureBox^>(sender);
			e->Graphics->SmoothingMode = SmoothingMode::AntiAlias;

			Rectangle rect = pb->ClientRectangle;
			rect.Inflate(-1, -1);

			Pen^ pen = gcnew Pen(Color::FromArgb(56, 189, 248), 2.0f);
			e->Graphics->DrawRectangle(pen, rect);
			delete pen;
		}

		// ========= LÓGICA =========

	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void btnEnviar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (Usuario == nullptr) {
				MessageBox::Show("No se ha identificado al usuario.", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			if (String::IsNullOrWhiteSpace(txtDescription->Text) ||
				String::IsNullOrWhiteSpace(txtLugar->Text)) {
				MessageBox::Show("Complete la descripción y el lugar.", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			Altercado^ alerta = gcnew Altercado();
			alerta->Description = txtDescription->Text;
			alerta->Lugar = txtLugar->Text;

			// Vincular con usuario
			alerta->UsuarioID = Usuario->ID;
			alerta->UsuarioNombre = Usuario->Nombre;

			if (pbPhoto != nullptr && pbPhoto->Image != nullptr) {
				System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream();
				pbPhoto->Image->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
				alerta->Photo = ms->ToArray();
			}

			alerta->Fecha = dtpFecha->Value;
			alerta->Solucionado = false;

			// Actualizar contador de alertas de altercado
			if (Usuario->cant_alertas != nullptr && Usuario->cant_alertas->Length > 1) {
				Usuario->cant_alertas[1] += 1;
				Service::modificarUsuarioID(Usuario);
			}

			Service::registrarAlerta(alerta);
			MessageBox::Show("Alerta enviada exitosamente", "Éxito",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
			ClearFields();
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al enviar alerta: " + ex->Message,
				"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void pbPhoto_Click(System::Object^ sender, System::EventArgs^ e) {
		SearchAndPutImagenOn(pbPhoto);
		MessageBox::Show("Imagen agregada exitosamente", "Éxito", MessageBoxButtons::OK);
	}

	private: System::Void btnCargarImagen_Click(System::Object^ sender, System::EventArgs^ e) {
		SearchAndPutImagenOn(pbPhoto);
		MessageBox::Show("Imagen agregada exitosamente", "Éxito", MessageBoxButtons::OK);
	}

	private: void SearchAndPutImagenOn(PictureBox^ pb) {
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
		dtpFecha->Value = DateTime::Now;
	}

	private: System::Void AltercationReportForm_Load(System::Object^ sender, System::EventArgs^ e) {
		ClearFields();
	}
	};
}
