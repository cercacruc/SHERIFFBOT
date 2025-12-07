#pragma once
#include "UIStyles.h"   // DarkTabControl + UIHelpers

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de InformationRequestForm
	/// </summary>
	public ref class InformationRequestForm : public System::Windows::Forms::Form
	{
	public:
		InformationRequestForm(void)
		{
			InitializeComponent();

			// ---- upgrade visual ----
			UpgradeTabControlToDark();
			ApplyDarkTheme();
			StyleButton();
			StyleComboLugar();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~InformationRequestForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnReturnInfoRequest;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TabPage^ tabPage4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(InformationRequestForm::typeid));
			this->btnReturnInfoRequest = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->tabPage4->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnReturnInfoRequest
			// 
			this->btnReturnInfoRequest->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->btnReturnInfoRequest->Location = System::Drawing::Point(260, 396);
			this->btnReturnInfoRequest->Name = L"btnReturnInfoRequest";
			this->btnReturnInfoRequest->Size = System::Drawing::Size(193, 47);
			this->btnReturnInfoRequest->TabIndex = 27;
			this->btnReturnInfoRequest->Text = L"Volver";
			this->btnReturnInfoRequest->UseVisualStyleBackColor = true;
			this->btnReturnInfoRequest->Click += gcnew System::EventHandler(this, &InformationRequestForm::btnReturnInfoRequest_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Location = System::Drawing::Point(12, 72);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(648, 308);
			this->tabControl1->TabIndex = 25;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Size = System::Drawing::Size(657, 279);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Comida";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(196, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(281, 20);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Comedores y cafeterias disponibles:";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Size = System::Drawing::Size(657, 279);
			this->tabPage2->TabIndex = 0;
			this->tabPage2->Text = L"Aulas libres";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(256, 28);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(145, 20);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Aulas disponibles:";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label4);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(657, 279);
			this->tabPage3->TabIndex = 1;
			this->tabPage3->Text = L"Zonas de estudio";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(220, 23);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(230, 20);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Zonas de estudio disponibles:";
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->label6);
			this->tabPage4->Controls->Add(this->comboBox1);
			this->tabPage4->Controls->Add(this->label5);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Size = System::Drawing::Size(640, 279);
			this->tabPage4->TabIndex = 2;
			this->tabPage4->Text = L"Lugar";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label6->Location = System::Drawing::Point(276, 99);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(104, 20);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Como llegar:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(22) {
				L"Pabellón A", L"Pabellón B", L"Pabellón D", L"Pabellón E",
					L"Pabellón F", L"Pabellón H", L"Pabellón I", L"Pabellón J", L"Pabellón K", L"Pabellón L", L"Pabellón M", L"Pabellón N", L"Pabellón O",
					L"Pabellón P", L"Pabellón Q", L"Pabellón R", L"Pabellón S", L"Pabellón U", L"Pabellón V", L"Pabellón X", L"Pabellón Y", L"Pabellón Z"
			});
			this->comboBox1->Location = System::Drawing::Point(180, 59);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(310, 24);
			this->comboBox1->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label5->Location = System::Drawing::Point(240, 22);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(174, 20);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Ingrese una dirección:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(200, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(277, 29);
			this->label1->TabIndex = 26;
			this->label1->Text = L"Solicitud de información:";
			// 
			// InformationRequestForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(671, 455);
			this->Controls->Add(this->btnReturnInfoRequest);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"InformationRequestForm";
			this->Text = L"Solicitud de información";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// ================= ESTILO =================

		// Cambiar TabControl estándar por DarkTabControl (como en AdminAlertManagementForm)
		void UpgradeTabControlToDark()
		{
			if (this->tabControl1 == nullptr) return;

			TabControl^ original = this->tabControl1;
			GUIApp::DarkTabControl^ dark = gcnew GUIApp::DarkTabControl();

			dark->Location = original->Location;
			dark->Size = original->Size;
			dark->Anchor = original->Anchor;
			dark->Name = original->Name;

			while (original->TabPages->Count > 0)
			{
				TabPage^ p = original->TabPages[0];
				original->TabPages->RemoveAt(0);
				dark->TabPages->Add(p);
			}
			dark->SizeMode = TabSizeMode::Fixed;
			dark->ItemSize = System::Drawing::Size(120, 28); // ancho, alto (ajusta a gusto)

			this->Controls->Remove(original);
			this->tabControl1 = dark;
			this->Controls->Add(this->tabControl1);
		}

		void ApplyDarkTheme()
		{
			Color back = Color::FromArgb(20, 27, 47);
			Color fore = Color::FromArgb(224, 231, 255);

			this->BackColor = back;
			this->ForeColor = fore;
			this->StartPosition = FormStartPosition::CenterScreen;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;

			if (this->tabControl1 != nullptr)
			{
				this->tabControl1->BackColor = back;
				this->tabControl1->ForeColor = fore;

				for each (TabPage ^ page in this->tabControl1->TabPages)
				{
					page->BackColor = back;
					page->ForeColor = fore;
				}
			}

			// Título principal
			if (label1 != nullptr)
			{
				label1->ForeColor = Color::FromArgb(241, 245, 249);
				label1->Font = gcnew Drawing::Font("Segoe UI", 14, FontStyle::Bold);
			}

			// Labels internos
			array<Label^>^ labels = gcnew array<Label^>{
				label2, label3, label4, label5, label6
			};

			for each (Label ^ lb in labels)
			{
				if (lb != nullptr)
				{
					lb->ForeColor = fore;
					lb->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Regular);
				}
			}
		}

		void StyleButton()
		{
			// Botón "Volver" como botón primario
			btnReturnInfoRequest->FlatStyle = FlatStyle::Flat;
			btnReturnInfoRequest->FlatAppearance->BorderSize = 0;
			btnReturnInfoRequest->BackColor = Color::FromArgb(0, 140, 255);
			btnReturnInfoRequest->ForeColor = Color::White;
			btnReturnInfoRequest->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
			UIHelpers::SetRoundedRegionAuto(this->btnReturnInfoRequest);
		}

		void StyleComboLugar()
		{
			if (comboBox1 == nullptr) return;

			comboBox1->FlatStyle = FlatStyle::Flat;
			comboBox1->DropDownStyle = ComboBoxStyle::DropDownList;
			comboBox1->BackColor = Color::FromArgb(15, 23, 42);
			comboBox1->ForeColor = Color::FromArgb(226, 232, 240);
			comboBox1->DrawMode = DrawMode::OwnerDrawFixed;
			comboBox1->DrawItem += gcnew DrawItemEventHandler(this, &InformationRequestForm::comboBox1_DrawItem);
		}

		void comboBox1_DrawItem(System::Object^ sender, DrawItemEventArgs^ e)
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

		// ================= LÓGICA =================

	private: System::Void btnReturnInfoRequest_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
