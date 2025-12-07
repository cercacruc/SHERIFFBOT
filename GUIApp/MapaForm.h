#pragma once
#include "UIStyles.h"   // para usar UIHelpers

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace BotModel;
	using namespace BotService;

	/// <summary>
	/// Resumen de MapaForm
	/// </summary>
	public ref class MapaForm : public System::Windows::Forms::Form
	{
	public:
		Robot^ robotEncontrado;

		MapaForm(Robot^ robot)
		{
			InitializeComponent();
			robotEncontrado = robot;

			ApplyDarkTheme();
			StylePrimaryButton();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MapaForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MapaForm::typeid));
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnSalir
			// 
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(668, 12);
			this->btnSalir->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(143, 60);
			this->btnSalir->TabIndex = 37;
			this->btnSalir->Text = L"SALIR";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &MapaForm::btnSalir_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(40, 87);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(739, 489);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 38;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MapaForm::pictureBox1_Paint);
			// 
			// MapaForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(823, 702);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnSalir);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MapaForm";
			this->Text = L"Mapa del Robot";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		// ====== ESTILO ======

	private:
		void ApplyDarkTheme()
		{
			// Fondo del form
			this->BackColor = Color::FromArgb(20, 27, 47);
			this->ForeColor = Color::FromArgb(226, 232, 240);
			this->StartPosition = FormStartPosition::CenterScreen;

			// Opcional: bloquear maximizar para que se vea más "dialog"
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = true;

			// Fondo del mapa
			this->pictureBox1->BackColor = Color::FromArgb(10, 16, 32);
			this->pictureBox1->BorderStyle = BorderStyle::FixedSingle;
		}

		void StylePrimaryButton()
		{
			this->btnSalir->FlatStyle = FlatStyle::Flat;
			this->btnSalir->FlatAppearance->BorderSize = 0;
			this->btnSalir->BackColor = Color::FromArgb(0, 140, 255);
			this->btnSalir->ForeColor = Color::White;
			this->btnSalir->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);

			// Usa el helper de UI para bordes redondeados
			UIHelpers::SetRoundedRegionAuto(this->btnSalir);
		}

		// ====== LÓGICA ======

	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		//pictureBox1->Invalidate();  
		Graphics^ g = e->Graphics;
		SolidBrush^ brush = gcnew SolidBrush(Color::Red);

		double pos_x = robotEncontrado->PosicionRobot->x;
		double pos_y = robotEncontrado->PosicionRobot->y;
		double x_max = 935;
		double y_max = 465;
		double x_min = 0;
		double y_min = 0;
		int width = pictureBox1->Width;
		int heigth = pictureBox1->Height;

		double X_conversion = (pos_x - x_min) / (x_max - x_min);
		double Y_conversion = (pos_y - y_min) / (y_max - y_min);

		int x_pixel = (int)(X_conversion * width);
		int y_pixel = (int)((1 - Y_conversion) * heigth);

		g->FillEllipse(brush, x_pixel - 5, y_pixel - 5, 10, 10);

		delete brush;
	}
	};
}
