#pragma once
#include "MapaForm.h"
#include "UIStyles.h"  // <<< usar helpers de estilo

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace BotModel;
	using namespace BotService;

	using namespace AForge::Video;
	using namespace AForge::Video::DirectShow;
	using namespace ZXing;
	using namespace System::Threading;

	public ref class ControlRobotForm : public System::Windows::Forms::Form
	{
	private:
		int robotOrientacion = 0;
		int movimiento = 20;
		int x_max = 935;
		int y_max = 465;

	public:
		Robot^ robotEncontrado;

		ControlRobotForm(Robot^ robot)
		{
			InitializeComponent();
			robotEncontrado = robot;

			this->DoubleBuffered = true;      // <<< suaviza repintado
			StyleControls();                  // <<< aplica estilo visual
		}

	protected:
		~ControlRobotForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;

	private: System::Windows::Forms::PictureBox^ pbCamara;
	private: System::Windows::Forms::TextBox^ txtRobot;
	private: System::Windows::Forms::PictureBox^ giroIzquierda;
	private: System::Windows::Forms::PictureBox^ giroDerecha;
	private: System::Windows::Forms::PictureBox^ btnAtras;
	private: System::Windows::Forms::PictureBox^ btnAdelante;
	private: System::Windows::Forms::PictureBox^ btnRight;
	private: System::Windows::Forms::PictureBox^ btnLeft;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnSalir;
	private: System::Windows::Forms::Button^ btnVerMapa;
	private: System::Windows::Forms::Button^ btnReconectar;

		   // <<< NUEVO: panel de estado interno
	private: System::Windows::Forms::Label^ lblEstadoRobot;
	private: System::Windows::Forms::TextBox^ txtEstadoRobot;

	private: AForge::Video::DirectShow::FilterInfoCollection^ videoDivices;
	private: AForge::Video::DirectShow::VideoCaptureDevice^ videoSource;
	private: Bitmap^ currentFrame;
		   Object^ frameLock = gcnew Object();
		   bool isProcesing = false;
		   bool isClosing = false;

#pragma region Windows Form Designer generated code

		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ControlRobotForm::typeid));
			   this->pbCamara = (gcnew System::Windows::Forms::PictureBox());
			   this->txtRobot = (gcnew System::Windows::Forms::TextBox());
			   this->giroIzquierda = (gcnew System::Windows::Forms::PictureBox());
			   this->giroDerecha = (gcnew System::Windows::Forms::PictureBox());
			   this->btnAtras = (gcnew System::Windows::Forms::PictureBox());
			   this->btnAdelante = (gcnew System::Windows::Forms::PictureBox());
			   this->btnRight = (gcnew System::Windows::Forms::PictureBox());
			   this->btnLeft = (gcnew System::Windows::Forms::PictureBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->btnSalir = (gcnew System::Windows::Forms::Button());
			   this->btnVerMapa = (gcnew System::Windows::Forms::Button());
			   this->btnReconectar = (gcnew System::Windows::Forms::Button());
			   this->lblEstadoRobot = (gcnew System::Windows::Forms::Label());
			   this->txtEstadoRobot = (gcnew System::Windows::Forms::TextBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbCamara))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->giroIzquierda))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->giroDerecha))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAtras))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAdelante))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnRight))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnLeft))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // pbCamara
			   // 
			   this->pbCamara->Location = System::Drawing::Point(18, 114);
			   this->pbCamara->Name = L"pbCamara";
			   this->pbCamara->Size = System::Drawing::Size(711, 362);
			   this->pbCamara->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pbCamara->TabIndex = 35;
			   this->pbCamara->TabStop = false;
			   // 
			   // txtRobot
			   // 
			   this->txtRobot->Location = System::Drawing::Point(197, 24);
			   this->txtRobot->Name = L"txtRobot";
			   this->txtRobot->Size = System::Drawing::Size(138, 22);
			   this->txtRobot->TabIndex = 34;
			   this->txtRobot->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			   // 
			   // giroIzquierda
			   // 
			   this->giroIzquierda->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"giroIzquierda.Image")));
			   this->giroIzquierda->Location = System::Drawing::Point(152, 537);
			   this->giroIzquierda->Name = L"giroIzquierda";
			   this->giroIzquierda->Size = System::Drawing::Size(88, 96);
			   this->giroIzquierda->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->giroIzquierda->TabIndex = 33;
			   this->giroIzquierda->TabStop = false;
			   this->giroIzquierda->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ControlRobotForm::giroIzquierda_MouseDown);
			   this->giroIzquierda->MouseLeave += gcnew System::EventHandler(this, &ControlRobotForm::giroIzquierda_MouseLeave);
			   this->giroIzquierda->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ControlRobotForm::giroIzquierda_MouseUp);
			   // 
			   // giroDerecha
			   // 
			   this->giroDerecha->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"giroDerecha.Image")));
			   this->giroDerecha->Location = System::Drawing::Point(499, 537);
			   this->giroDerecha->Name = L"giroDerecha";
			   this->giroDerecha->Size = System::Drawing::Size(90, 96);
			   this->giroDerecha->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->giroDerecha->TabIndex = 32;
			   this->giroDerecha->TabStop = false;
			   this->giroDerecha->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ControlRobotForm::giroDerecha_MouseDown);
			   this->giroDerecha->MouseLeave += gcnew System::EventHandler(this, &ControlRobotForm::giroDerecha_MouseLeave);
			   this->giroDerecha->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ControlRobotForm::giroDerecha_MouseUp);
			   // 
			   // btnAtras
			   // 
			   this->btnAtras->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAtras.Image")));
			   this->btnAtras->Location = System::Drawing::Point(334, 623);
			   this->btnAtras->Name = L"btnAtras";
			   this->btnAtras->Size = System::Drawing::Size(74, 65);
			   this->btnAtras->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->btnAtras->TabIndex = 31;
			   this->btnAtras->TabStop = false;
			   this->btnAtras->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ControlRobotForm::btnAtras_MouseDown);
			   this->btnAtras->MouseLeave += gcnew System::EventHandler(this, &ControlRobotForm::btnAtras_MouseLeave);
			   this->btnAtras->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ControlRobotForm::btnAtras_MouseUp);
			   // 
			   // btnAdelante
			   // 
			   this->btnAdelante->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAdelante.Image")));
			   this->btnAdelante->Location = System::Drawing::Point(334, 481);
			   this->btnAdelante->Name = L"btnAdelante";
			   this->btnAdelante->Size = System::Drawing::Size(74, 65);
			   this->btnAdelante->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->btnAdelante->TabIndex = 30;
			   this->btnAdelante->TabStop = false;
			   this->btnAdelante->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ControlRobotForm::btnAdelante_MouseDown);
			   this->btnAdelante->MouseLeave += gcnew System::EventHandler(this, &ControlRobotForm::btnAdelante_MouseLeave);
			   this->btnAdelante->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ControlRobotForm::btnAdelante_MouseUp);
			   // 
			   // btnRight
			   // 
			   this->btnRight->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRight.Image")));
			   this->btnRight->Location = System::Drawing::Point(406, 552);
			   this->btnRight->Name = L"btnRight";
			   this->btnRight->Size = System::Drawing::Size(74, 65);
			   this->btnRight->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->btnRight->TabIndex = 29;
			   this->btnRight->TabStop = false;
			   this->btnRight->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ControlRobotForm::btnRight_MouseDown);
			   this->btnRight->MouseLeave += gcnew System::EventHandler(this, &ControlRobotForm::btnRight_MouseLeave);
			   this->btnRight->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ControlRobotForm::btnRight_MouseUp);
			   // 
			   // btnLeft
			   // 
			   this->btnLeft->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnLeft.Image")));
			   this->btnLeft->Location = System::Drawing::Point(261, 552);
			   this->btnLeft->Name = L"btnLeft";
			   this->btnLeft->Size = System::Drawing::Size(74, 65);
			   this->btnLeft->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->btnLeft->TabIndex = 28;
			   this->btnLeft->TabStop = false;
			   this->btnLeft->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ControlRobotForm::btnLeft_MouseDown);
			   this->btnLeft->MouseLeave += gcnew System::EventHandler(this, &ControlRobotForm::btnLeft_MouseLeave);
			   this->btnLeft->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ControlRobotForm::btnLeft_MouseUp);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			   this->label3->Location = System::Drawing::Point(13, 71);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(205, 29);
			   this->label3->TabIndex = 27;
			   this->label3->Text = L"Cámara del robot:";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			   this->label1->Location = System::Drawing::Point(36, 24);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(155, 29);
			   this->label1->TabIndex = 24;
			   this->label1->Text = L"Robot Name:";
			   // 
			   // btnSalir
			   // 
			   this->btnSalir->Location = System::Drawing::Point(586, 12);
			   this->btnSalir->Name = L"btnSalir";
			   this->btnSalir->Size = System::Drawing::Size(143, 60);
			   this->btnSalir->TabIndex = 36;
			   this->btnSalir->Text = L"Salir";
			   this->btnSalir->UseVisualStyleBackColor = true;
			   this->btnSalir->Click += gcnew System::EventHandler(this, &ControlRobotForm::btnSalir_Click);
			   // 
			   // btnVerMapa
			   // 
			   this->btnVerMapa->Location = System::Drawing::Point(437, 12);
			   this->btnVerMapa->Name = L"btnVerMapa";
			   this->btnVerMapa->Size = System::Drawing::Size(143, 60);
			   this->btnVerMapa->TabIndex = 37;
			   this->btnVerMapa->Text = L"Ver mapa";
			   this->btnVerMapa->UseVisualStyleBackColor = true;
			   this->btnVerMapa->Click += gcnew System::EventHandler(this, &ControlRobotForm::btnVerMapa_Click);
			   // 
			   // btnReconectar
			   // 
			   this->btnReconectar->Location = System::Drawing::Point(18, 649);
			   this->btnReconectar->Name = L"btnReconectar";
			   this->btnReconectar->Size = System::Drawing::Size(140, 39);
			   this->btnReconectar->TabIndex = 38;
			   this->btnReconectar->Text = L"Reconectar";
			   this->btnReconectar->UseVisualStyleBackColor = true;
			   this->btnReconectar->Click += gcnew System::EventHandler(this, &ControlRobotForm::btnReconectar_Click);
			   // 
			   // lblEstadoRobot
			   // 
			   this->lblEstadoRobot->AutoSize = true;
			   this->lblEstadoRobot->Location = System::Drawing::Point(435, 74);
			   this->lblEstadoRobot->Name = L"lblEstadoRobot";
			   this->lblEstadoRobot->Size = System::Drawing::Size(109, 16);
			   this->lblEstadoRobot->TabIndex = 39;
			   this->lblEstadoRobot->Text = L"Estado del robot:";
			   // 
			   // txtEstadoRobot
			   // 
			   this->txtEstadoRobot->Location = System::Drawing::Point(435, 93);
			   this->txtEstadoRobot->Name = L"txtEstadoRobot";
			   this->txtEstadoRobot->ReadOnly = true;
			   this->txtEstadoRobot->Size = System::Drawing::Size(294, 22);
			   this->txtEstadoRobot->TabIndex = 40;
			   // 
			   // ControlRobotForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(741, 697);
			   this->Controls->Add(this->txtEstadoRobot);
			   this->Controls->Add(this->lblEstadoRobot);
			   this->Controls->Add(this->btnReconectar);
			   this->Controls->Add(this->btnVerMapa);
			   this->Controls->Add(this->btnSalir);
			   this->Controls->Add(this->pbCamara);
			   this->Controls->Add(this->txtRobot);
			   this->Controls->Add(this->giroIzquierda);
			   this->Controls->Add(this->giroDerecha);
			   this->Controls->Add(this->btnAtras);
			   this->Controls->Add(this->btnAdelante);
			   this->Controls->Add(this->btnRight);
			   this->Controls->Add(this->btnLeft);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label1);
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->Name = L"ControlRobotForm";
			   this->Text = L"Control del robot";
			   this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ControlRobotForm::ControlRobotForm_FormClosing);
			   this->Load += gcnew System::EventHandler(this, &ControlRobotForm::ControlRobotForm_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbCamara))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->giroIzquierda))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->giroDerecha))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAtras))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAdelante))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnRight))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnLeft))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

		   // ======== ESTILO VISUAL (UIStyles) ========

	private:
		void StyleControls()
		{
			// Form
			this->BackColor = Color::FromArgb(5, 8, 22);
			this->ForeColor = Color::White;
			this->StartPosition = FormStartPosition::CenterScreen;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;

			// Labels
			this->label1->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, FontStyle::Regular);
			this->label3->Font = gcnew System::Drawing::Font(L"Segoe UI", 11, FontStyle::Regular);
			this->label1->ForeColor = Color::FromArgb(224, 231, 255);
			this->label3->ForeColor = Color::FromArgb(224, 231, 255);

			this->lblEstadoRobot->Font =
				gcnew System::Drawing::Font(L"Segoe UI", 9, FontStyle::Regular);
			this->lblEstadoRobot->ForeColor =
				Color::FromArgb(148, 163, 184);

			// TextBoxes
			Color backTb = Color::FromArgb(10, 16, 32);
			Color foreTb = Color::FromArgb(226, 232, 240);

			array<TextBox^>^ boxes = gcnew array<TextBox^> {
				this->txtRobot,
					this->txtEstadoRobot
			};

			for each (TextBox ^ tb in boxes)
			{
				tb->BackColor = backTb;
				tb->ForeColor = foreTb;
				tb->BorderStyle = BorderStyle::FixedSingle;
			}

			this->txtRobot->ReadOnly = true;
			this->txtRobot->TextAlign =
				System::Windows::Forms::HorizontalAlignment::Center;

			this->txtEstadoRobot->ReadOnly = true;
			this->txtEstadoRobot->TextAlign =
				System::Windows::Forms::HorizontalAlignment::Left;

			// Botón primario: Reconectar
			array<Button^>^ primaryButtons = gcnew array<Button^> {
				this->btnReconectar
			};

			for each (Button ^ b in primaryButtons)
			{
				b->FlatStyle = FlatStyle::Flat;
				b->FlatAppearance->BorderSize = 0;
				b->BackColor = Color::FromArgb(0, 140, 255);
				b->ForeColor = Color::White;
				b->Font = gcnew System::Drawing::Font(L"Segoe UI", 9, FontStyle::Bold);
				GUIApp::UIHelpers::SetRoundedRegionAuto(b);
			}

			// Botones secundarios: Ver mapa, Salir
			array<Button^>^ secondaryButtons = gcnew array<Button^> {
				this->btnVerMapa,
					this->btnSalir
			};

			for each (Button ^ b in secondaryButtons)
			{
				b->FlatStyle = FlatStyle::Flat;
				b->FlatAppearance->BorderSize = 0;
				b->BackColor = Color::FromArgb(20, 27, 47);
				b->ForeColor = Color::FromArgb(224, 231, 255);
				b->Font = gcnew System::Drawing::Font(L"Segoe UI", 9, FontStyle::Regular);
				b->Paint += gcnew PaintEventHandler(&GUIApp::UIHelpers::OutlineButton_Paint);
				GUIApp::UIHelpers::SetRoundedRegionAuto(b);
			}
		}

		// ======== LÓGICA ========

	private: System::Void ControlRobotForm_Load(System::Object^ sender, System::EventArgs^ e) {
		txtRobot->Enabled = false;

		if (robotEncontrado != nullptr) {
			txtRobot->Text = robotEncontrado->Nombre;
		}

		// Estado inicial
		UpdateRobotStatus("Listo");

		// Conectar con Arduino al cargar
		if (!Service::ConectarArduino()) {
			MessageBox::Show("No se pudo conectar con Arduino", "Advertencia",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

		// Conectar con MQTT al carga
		if (!Vehiculo::Connect()) {
			MessageBox::Show("No se pudo conectar con MQTT", "Advertencia",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		
		try {
			if (!this->InicializarCamara()) {
				MessageBox::Show("No se pudo acceder a la cámara");
				this->Close();
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error inicializando cámara: " + ex->Message);
			this->Close();
		}
		
	}

		   // <<< NUEVO: actualiza el estado en el textbox interno
	private:
		void UpdateRobotStatus(String^ accion)
		{
			if (robotEncontrado == nullptr || robotEncontrado->PosicionRobot == nullptr) {
				this->txtEstadoRobot->Text = "Sin datos de posición.";
				return;
			}

			this->txtEstadoRobot->Text =
				String::Format("{0} | Pos: ({1}, {2}) | Ángulo: {3}°",
					accion,
					robotEncontrado->PosicionRobot->x,
					robotEncontrado->PosicionRobot->y,
					robotOrientacion);
		}

	private: void Bitmap_Disposed(System::Object^ sender, System::EventArgs^ e) {
	}

		   // ========= MANEJO DE BOTONES DE MOVIMIENTO =========

	private: System::Void btnAdelante_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(1, true);
			Vehiculo::Forward();
		}
	}

	private: System::Void btnAdelante_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(1, false);
			String^ mensaje = "avanzar";
			MoverRobot(mensaje, robotOrientacion);
			Vehiculo::Stop();

			UpdateRobotStatus("Avanzó");   // <<< en vez de MessageBox
		}
	}

	private: System::Void btnAdelante_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		if (Control::MouseButtons == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(1, false);
			String^ mensaje = "avanzar";
			MoverRobot(mensaje, robotOrientacion);
			Vehiculo::Stop();

			UpdateRobotStatus("Avanzó");
		}
	}

	private: System::Void btnAtras_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(2, true);
			Vehiculo::Backward();
		}
	}

	private: System::Void btnAtras_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(2, false);
			String^ mensaje = "retroceder";    // <<< corregido typo
			MoverRobot(mensaje, robotOrientacion);
			Vehiculo::Stop();

			UpdateRobotStatus("Retrocedió");
		}
	}

	private: System::Void btnAtras_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		if (Control::MouseButtons == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(2, false);
			String^ mensaje = "retroceder";
			MoverRobot(mensaje, robotOrientacion);
			Vehiculo::Stop();

			UpdateRobotStatus("Retrocedió");
		}
	}

	private: System::Void btnRight_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(3, true);
			Vehiculo::Right();
		}
	}

	private: System::Void btnRight_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(3, false);
			String^ mensaje = "derecha";
			MoverRobot(mensaje, robotOrientacion);
			Vehiculo::Stop();

			UpdateRobotStatus("Se movió a la derecha");
		}
	}

	private: System::Void btnRight_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		if (Control::MouseButtons == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(3, false);
			String^ mensaje = "derecha";
			MoverRobot(mensaje, robotOrientacion);
			Vehiculo::Stop();

			UpdateRobotStatus("Se movió a la derecha");
		}
	}

	private: System::Void btnLeft_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(4, true);
			Vehiculo::Left();
		}
	}

	private: System::Void btnLeft_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(4, false);
			String^ mensaje = "izquierda";
			MoverRobot(mensaje, robotOrientacion);
			Vehiculo::Stop();

			UpdateRobotStatus("Se movió a la izquierda");
		}
	}

	private: System::Void btnLeft_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		if (Control::MouseButtons == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(4, false);
			String^ mensaje = "izquierda";
			MoverRobot(mensaje, robotOrientacion);
			Vehiculo::Stop();

			UpdateRobotStatus("Se movió a la izquierda");
		}
	}

	private: System::Void giroDerecha_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(5, true);
			Vehiculo::TurnRight();
		}
	}

	private: System::Void giroDerecha_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(5, false);

			robotOrientacion -= 90;
			if (robotOrientacion < 0) robotOrientacion = 270;

			Vehiculo::Stop();
			UpdateRobotStatus("Giró a la derecha");
		}
	}

	private: System::Void giroDerecha_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		if (Control::MouseButtons == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(5, false);

			robotOrientacion -= 90;
			if (robotOrientacion < 0) robotOrientacion = 270;

			Vehiculo::Stop();
			UpdateRobotStatus("Giró a la derecha");
		}
	}

	private: System::Void giroIzquierda_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(6, true);
			Vehiculo::TurnLeft();
		}
	}

	private: System::Void giroIzquierda_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(6, false);

			robotOrientacion += 90;
			if (robotOrientacion >= 360) robotOrientacion = 0;

			Vehiculo::Stop();
			UpdateRobotStatus("Giró a la izquierda");
		}
	}

	private: System::Void giroIzquierda_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		if (Control::MouseButtons == System::Windows::Forms::MouseButtons::Left) {
			Service::ComandoLED(6, false);

			robotOrientacion += 90;
			if (robotOrientacion >= 360) robotOrientacion = 0;

			Vehiculo::Stop();
			UpdateRobotStatus("Giró a la izquierda");
		}
	}

		   // ========= CÁMARA =========

	private: System::Boolean InicializarCamara() {
		try {
			this->videoDivices = gcnew FilterInfoCollection(FilterCategory::VideoInputDevice);
			if (videoDivices->Count == 0) {
				return false;
			}

			String^ camID = this->videoDivices[0]->MonikerString;
			this->videoSource = gcnew VideoCaptureDevice(camID);
			this->videoSource->NewFrame +=
				gcnew AForge::Video::NewFrameEventHandler(this, &ControlRobotForm::video_NewFrame);

			this->videoSource->Start();
			return true;
		}
		catch (Exception^ ex) {
			throw ex;
		}
	}

	private: System::Void video_NewFrame(System::Object^ sender, AForge::Video::NewFrameEventArgs^ e) {
		if (this->isClosing) return;

		Bitmap^ newFrame = nullptr;
		Bitmap^ oldFrame = nullptr;

		try {
			newFrame = (Bitmap^)e->Frame->Clone();

			if (Monitor::TryEnter(frameLock, 0)) {
				try {
					if (this->isClosing) return;

					oldFrame = this->currentFrame;
					this->currentFrame = (Bitmap^)newFrame->Clone();
				}
				finally {
					Monitor::Exit(frameLock);
				}

				if (!this->isClosing && this->pbCamara->InvokeRequired) {
					this->pbCamara->BeginInvoke(
						gcnew Action<Bitmap^>(this, &ControlRobotForm::ActualizarPictureBox),
						newFrame);
				}
				else if (!this->isClosing) {
					ActualizarPictureBox(newFrame);
				}
			}

			if (oldFrame != nullptr) {
				delete oldFrame;
			}
		}
		catch (Exception^ ex) {
			if (!this->isClosing) {
				System::Diagnostics::Debug::WriteLine("Error en video_NewFrame: " + ex->Message);
			}
			if (newFrame != nullptr) delete newFrame;
			if (oldFrame != nullptr) delete oldFrame;
		}
	}

	private: System::Void ActualizarPictureBox(Bitmap^ frame) {
		if (this->isClosing) {
			delete frame;
			return;
		}

		try {
			Image^ oldImage = this->pbCamara->Image;
			this->pbCamara->Image = frame;
			if (oldImage != nullptr) {
				delete oldImage;
			}
		}
		catch (Exception^ ex) {
			delete frame;
			System::Diagnostics::Debug::WriteLine("Error actualizando PictureBox: " + ex->Message);
		}
	}

	private: System::Void ControlRobotForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		this->DesactivarCamara();
		Service::DesconectarArduino();
		Vehiculo::Disconnect();
	}

	private: System::Void DesactivarCamara() {
		this->isClosing = true;

		if (this->videoSource != nullptr) {
			videoSource->SignalToStop();
			System::Threading::Thread::Sleep(100);
			delete videoSource;
			videoSource = nullptr;
		}

		Monitor::Enter(frameLock);
		try {
			if (this->currentFrame != nullptr) {
				delete currentFrame;
				currentFrame = nullptr;
			}
		}
		finally {
			Monitor::Exit(frameLock);
		}
	}

	private: System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void btnVerMapa_Click(System::Object^ sender, System::EventArgs^ e) {
		MapaForm^ form = gcnew MapaForm(robotEncontrado);
		this->Hide();
		form->ShowDialog();
		this->Show();
	}

		   // ========= LÓGICA DE MOVIMIENTO EN MAPA =========

	private: void MoverRobot(String^ mensaje, int robotOrientacion) {
		int currentX = robotEncontrado->PosicionRobot->x;
		int currentY = robotEncontrado->PosicionRobot->y;

		if (mensaje == "avanzar") {
			switch (robotOrientacion) {
			case 0: // +X
				currentX += movimiento;
				if (currentX >= x_max) currentX = x_max;
				break;
			case 90: // +Y
				currentY += movimiento;
				if (currentY >= y_max) currentY = y_max; // <<< corregido
				break;
			case 180: // -X
				currentX -= movimiento;
				if (currentX < 0) currentX = 0;
				break;
			case 270: // -Y
				currentY -= movimiento;
				if (currentY < 0) currentY = 0;
				break;
			}
		}
		else if (mensaje == "retroceder") {
			switch (robotOrientacion) {
			case 0: // -X
				currentX -= movimiento;
				if (currentX < 0) currentX = 0;
				break;
			case 90: // -Y
				currentY -= movimiento;
				if (currentY < 0) currentY = 0;
				break;
			case 180: // +X
				currentX += movimiento;
				if (currentX >= x_max) currentX = x_max;
				break;
			case 270: // +Y
				currentY += movimiento;
				if (currentY >= y_max) currentY = y_max;
				break;
			}
		}
		else if (mensaje == "derecha") {
			switch (robotOrientacion) {
			case 0: // -Y
				currentY -= movimiento;
				if (currentY < 0) currentY = 0;
				break;
			case 90: // +X
				currentX += movimiento;
				if (currentX >= x_max) currentX = x_max;
				break;
			case 180: // +Y
				currentY += movimiento;
				if (currentY >= y_max) currentY = y_max;
				break;
			case 270: // -X
				currentX -= movimiento;
				if (currentX < 0) currentX = 0;
				break;
			}
		}
		else if (mensaje == "izquierda") {
			switch (robotOrientacion) {
			case 0: // +Y
				currentY += movimiento;
				if (currentY >= y_max) currentY = y_max;  // <<< corregido
				break;
			case 90: // -X
				currentX -= movimiento;
				if (currentX < 0) currentX = 0;
				break;
			case 180: // -Y
				currentY -= movimiento;
				if (currentY < 0) currentY = 0;
				break;
			case 270: // +X
				currentX += movimiento;
				if (currentX >= x_max) currentX = x_max; // <<< corregido
				break;
			}
		}

		robotEncontrado->PosicionRobot->x = currentX;
		robotEncontrado->PosicionRobot->y = currentY;

		Service::modificarRobotID(robotEncontrado);
	}

	private: System::Void btnReconectar_Click(System::Object^ sender, System::EventArgs^ e) {
		Service::LiberarPuertoCOM3();
		Thread::Sleep(1000);

		if (Service::ConectarArduino() || Vehiculo::Connect()) {
			MessageBox::Show("Reconectado exitosamente", "Éxito");
		}
		else {
			MessageBox::Show("No se pudo reconectar", "Error");
		}
	}
	};

}
