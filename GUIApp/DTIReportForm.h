#pragma once
#include "UIStyles.h"   // UIHelpers::SetRoundedRegion, OutlineButton_Paint

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
	/// Resumen de DTIReportForm
	/// </summary>
	public ref class DTIReportForm : public System::Windows::Forms::Form
	{
	public:
		DatosUsuario^ Usuario;

		DTIReportForm(DatosUsuario^ usuario)
		{
			InitializeComponent();
			Usuario = usuario;

			// ===== UPGRADE VISUAL =====
			ApplyDarkTheme();
			StyleButtons();
			StyleTextBoxes();
			StyleComboTipoAlerta();
			StyleDateTimePicker();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~DTIReportForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ cbTipoAlerta;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnLlamar;
	private: System::Windows::Forms::TextBox^ txtDescription;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtLugar;
	private: System::Windows::Forms::DateTimePicker^ dtpFecha;
	private: System::Windows::Forms::Label^ label3;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DTIReportForm::typeid));
			this->cbTipoAlerta = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnLlamar = (gcnew System::Windows::Forms::Button());
			this->txtDescription = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtLugar = (gcnew System::Windows::Forms::TextBox());
			this->dtpFecha = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnVolver = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// cbTipoAlerta
			// 
			this->cbTipoAlerta->FormattingEnabled = true;
			this->cbTipoAlerta->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Necesidades tecnologicas", L"Prestamo de dispositivo",
					L"Proteccion contra ciberdelincuencia", L"Autenticación y acceso a aplicaciones y datos PUCP"
			});
			this->cbTipoAlerta->Location = System::Drawing::Point(141, 76);
			this->cbTipoAlerta->Name = L"cbTipoAlerta";
			this->cbTipoAlerta->Size = System::Drawing::Size(293, 24);
			this->cbTipoAlerta->TabIndex = 27;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(19, 76);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(116, 20);
			this->label4->TabIndex = 26;
			this->label4->Text = L"Tipo de alerta:";
			// 
			// btnLlamar
			// 
			this->btnLlamar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnLlamar->Location = System::Drawing::Point(30, 310);
			this->btnLlamar->Name = L"btnLlamar";
			this->btnLlamar->Size = System::Drawing::Size(193, 47);
			this->btnLlamar->TabIndex = 25;
			this->btnLlamar->Text = L"Llamar";
			this->btnLlamar->UseVisualStyleBackColor = true;
			this->btnLlamar->Click += gcnew System::EventHandler(this, &DTIReportForm::btnLlamar_Click);
			// 
			// txtDescription
			// 
			this->txtDescription->Location = System::Drawing::Point(14, 143);
			this->txtDescription->Multiline = true;
			this->txtDescription->Name = L"txtDescription";
			this->txtDescription->Size = System::Drawing::Size(445, 83);
			this->txtDescription->TabIndex = 21;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(19, 120);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 20);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Descripción:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(106, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(252, 43);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Llamada al DTI";
			// 
			// txtLugar
			// 
			this->txtLugar->Location = System::Drawing::Point(253, 263);
			this->txtLugar->Name = L"txtLugar";
			this->txtLugar->Size = System::Drawing::Size(163, 22);
			this->txtLugar->TabIndex = 48;
			// 
			// dtpFecha
			// 
			this->dtpFecha->Location = System::Drawing::Point(23, 263);
			this->dtpFecha->Name = L"dtpFecha";
			this->dtpFecha->Size = System::Drawing::Size(200, 22);
			this->dtpFecha->TabIndex = 47;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(19, 240);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 20);
			this->label3->TabIndex = 46;
			this->label3->Text = L"Fecha y lugar:";
			// 
			// btnVolver
			// 
			this->btnVolver->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnVolver->Location = System::Drawing::Point(253, 310);
			this->btnVolver->Name = L"btnVolver";
			this->btnVolver->Size = System::Drawing::Size(193, 47);
			this->btnVolver->TabIndex = 24;
			this->btnVolver->Text = L"Volver";
			this->btnVolver->UseVisualStyleBackColor = true;
			this->btnVolver->Click += gcnew System::EventHandler(this, &DTIReportForm::btnVolver_Click);
			// 
			// DTIReportForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(477, 369);
			this->Controls->Add(this->txtLugar);
			this->Controls->Add(this->dtpFecha);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->cbTipoAlerta);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnLlamar);
			this->Controls->Add(this->btnVolver);
			this->Controls->Add(this->txtDescription);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"DTIReportForm";
			this->Text = L"DTIReportForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// =============== ESTILO ===============

		void ApplyDarkTheme()
		{
			Color back = Color::FromArgb(20, 27, 47);
			Color fore = Color::FromArgb(224, 231, 255);

			this->BackColor = back;
			this->ForeColor = fore;

			array<Label^>^ labels = gcnew array<Label^>{
				label1, label2, label3, label4
			};

			for each(Label ^ lb in labels)
			{
				if (lb != nullptr)
					lb->ForeColor = fore;
			}
		}

		void StyleButtons()
		{
			// Botón principal (acción fuerte)
			array<Button^>^ primary = gcnew array<Button^>{
				btnLlamar
			};

			for each(Button ^ b in primary)
			{
				if (b == nullptr) continue;
				b->FlatStyle = FlatStyle::Flat;
				b->FlatAppearance->BorderSize = 0;
				b->BackColor = Color::FromArgb(0, 140, 255);
				b->ForeColor = Color::White;
				b->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
				UIHelpers::SetRoundedRegion(b, 18);
			}

			// Botón secundario (outline)
			array<Button^>^ secondary = gcnew array<Button^>{
				btnVolver
			};

			for each(Button ^ b in secondary)
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
		}

		void StyleTextBoxes()
		{
			Color back = Color::FromArgb(10, 16, 32);
			Color fore = Color::FromArgb(226, 232, 240);

			array<TextBox^>^ boxes = gcnew array<TextBox^>{
				txtDescription, txtLugar
			};

			for each(TextBox ^ tb in boxes)
			{
				if (tb == nullptr) continue;
				tb->BackColor = back;
				tb->ForeColor = fore;
				tb->BorderStyle = BorderStyle::FixedSingle;
			}
		}

		void StyleComboTipoAlerta()
		{
			if (cbTipoAlerta == nullptr) return;

			cbTipoAlerta->FlatStyle = FlatStyle::Flat;
			cbTipoAlerta->DropDownStyle = ComboBoxStyle::DropDownList;
			cbTipoAlerta->BackColor = Color::FromArgb(15, 23, 42);
			cbTipoAlerta->ForeColor = Color::FromArgb(226, 232, 240);
			cbTipoAlerta->DrawMode = DrawMode::OwnerDrawFixed;
			cbTipoAlerta->DrawItem += gcnew DrawItemEventHandler(this, &DTIReportForm::cbTipoAlerta_DrawItem);
		}

		void StyleDateTimePicker()
		{
			if (dtpFecha == nullptr) return;

			// No se puede oscurecer totalmente el control, pero sí el calendario
			dtpFecha->CalendarMonthBackground = Color::FromArgb(15, 23, 42);
			dtpFecha->CalendarForeColor = Color::FromArgb(226, 232, 240);
		}

		void cbTipoAlerta_DrawItem(System::Object^ sender, DrawItemEventArgs^ e)
		{
			if (e->Index < 0) return;

			ComboBox^ cb = safe_cast<ComboBox^>(sender);

			bool selected = (e->State & DrawItemState::Selected) == DrawItemState::Selected;
			Color back = selected ? Color::FromArgb(37, 99, 235) : Color::FromArgb(15, 23, 42);
			Color fore = Color::FromArgb(226, 232, 240);

			e->Graphics->FillRectangle(gcnew SolidBrush(back), e->Bounds);

			String^ text = cb->Items[e->Index]->ToString();
			e->Graphics->DrawString(
				text,
				cb->Font,
				gcnew SolidBrush(fore),
				RectangleF(
					(float)e->Bounds.X,
					(float)e->Bounds.Y,
					(float)e->Bounds.Width,
					(float)e->Bounds.Height
				)
			);

			e->DrawFocusRectangle();
		}

		// =============== LÓGICA ORIGINAL ===============

	private: System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnLlamar_Click(System::Object^ sender, System::EventArgs^ e) {
		DTIReport^ reporte = gcnew DTIReport();
		reporte->Description = txtDescription->Text;
		reporte->Fecha = dtpFecha->Value;
		reporte->tipoReporte = cbTipoAlerta->Text;

		reporte->Lugar = txtLugar->Text;

		// vincula con usuario
		reporte->UsuarioID = Usuario->ID;
		reporte->UsuarioNombre = Usuario->Nombre;

		reporte->Solucionado = false;

		if (Usuario != nullptr && Usuario->cant_alertas != nullptr) {
			Usuario->cant_alertas[2] += 1;
			Service::modificarUsuarioID(Usuario);
		}

		Service::registrarAlerta(reporte);
		MessageBox::Show("Se ha llamado al DTI", "Exito", MessageBoxButtons::OK);
		ClearFields();
	}
	private: void ClearFields() {
		txtDescription->Text = "";
		txtLugar->Text = "";
		cbTipoAlerta->SelectedIndex = -1;
	}
	};
}
