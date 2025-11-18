#pragma once
#include "MapaForm.h"

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

	/// <summary>
	/// Resumen de ControlRobotForm
	/// </summary>
	public ref class ControlRobotForm : public System::Windows::Forms::Form
	{
	public:
		Robot^ robotEncontrado;

		ControlRobotForm(Robot^ robot)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			robotEncontrado = robot;

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~ControlRobotForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	protected:


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
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

	private: AForge::Video::DirectShow::FilterInfoCollection^ videoDivices;
	private: AForge::Video::DirectShow::VideoCaptureDevice^ videoSource;
	private: Bitmap^ currentFrame;
	Object^ frameLock = gcnew Object();
	bool isProcesing = false;//////////////////////////////////////
	private: System::Windows::Forms::Button^ btnSalir;

	private: System::Windows::Forms::Button^ btnVerMapa;
	private: System::Windows::Forms::Button^ btnReconectar;

		   bool isClosing = false;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>

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
			this->txtRobot->Multiline = true;
			this->txtRobot->Name = L"txtRobot";
			this->txtRobot->Size = System::Drawing::Size(138, 29);
			this->txtRobot->TabIndex = 34;
			this->txtRobot->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// giroIzquierda
			// 
			this->giroIzquierda->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"giroIzquierda.Image")));
			this->giroIzquierda->Location = System::Drawing::Point(128, 521);
			this->giroIzquierda->Name = L"giroIzquierda";
			this->giroIzquierda->Size = System::Drawing::Size(127, 122);
			this->giroIzquierda->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->giroIzquierda->TabIndex = 33;
			this->giroIzquierda->TabStop = false;
			this->giroIzquierda->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &ControlRobotForm::giroIzquierda_MouseDown);
			this->giroIzquierda->MouseLeave += gcnew System::EventHandler(this, &ControlRobotForm::giroIzquierda_MouseLeave);
			this->giroIzquierda->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &ControlRobotForm::giroIzquierda_MouseUp);
			// 
			// giroDerecha
			// 
			this->giroDerecha->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"giroDerecha.Image")));
			this->giroDerecha->Location = System::Drawing::Point(486, 521);
			this->giroDerecha->Name = L"giroDerecha";
			this->giroDerecha->Size = System::Drawing::Size(127, 122);
			this->giroDerecha->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
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
			this->btnAtras->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
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
			this->btnAdelante->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
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
			this->btnRight->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
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
			this->btnLeft->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
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
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(586, 12);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(143, 60);
			this->btnSalir->TabIndex = 36;
			this->btnSalir->Text = L"SALIR";
			this->btnSalir->UseVisualStyleBackColor = true;
			this->btnSalir->Click += gcnew System::EventHandler(this, &ControlRobotForm::btnSalir_Click);
			// 
			// btnVerMapa
			// 
			this->btnVerMapa->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVerMapa->Location = System::Drawing::Point(437, 12);
			this->btnVerMapa->Name = L"btnVerMapa";
			this->btnVerMapa->Size = System::Drawing::Size(143, 60);
			this->btnVerMapa->TabIndex = 37;
			this->btnVerMapa->Text = L"VER MAPA";
			this->btnVerMapa->UseVisualStyleBackColor = true;
			this->btnVerMapa->Click += gcnew System::EventHandler(this, &ControlRobotForm::btnVerMapa_Click);
			// 
			// btnReconectar
			// 
			this->btnReconectar->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReconectar->Location = System::Drawing::Point(12, 649);
			this->btnReconectar->Name = L"btnReconectar";
			this->btnReconectar->Size = System::Drawing::Size(140, 39);
			this->btnReconectar->TabIndex = 38;
			this->btnReconectar->Text = L"RECONECTAR";
			this->btnReconectar->UseVisualStyleBackColor = true;
			this->btnReconectar->Click += gcnew System::EventHandler(this, &ControlRobotForm::btnReconectar_Click);
			// 
			// ControlRobotForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(741, 697);
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
			this->Name = L"ControlRobotForm";
			this->Text = L"ControlRobotForm";
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
		private: System::Void ControlRobotForm_Load(System::Object^ sender, System::EventArgs^ e) {
			txtRobot->Enabled = false;
			if (robotEncontrado != nullptr) {
				txtRobot->Text = robotEncontrado->Nombre;
			}
			// Conectar con Arduino al cargar el formulario
			if (!Service::ConectarArduino()) {
				MessageBox::Show("No se pudo conectar con Arduino", "Advertencia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
		private: void Bitmap_Disposed(System::Object^ sender, System::EventArgs^ e) {
		
		}
		private: System::Void btnAdelante_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			// Encender LED cuando se presiona el botón
			Service::ComandoLED(1, true);
		}

		private: System::Void btnAdelante_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			// Apagar LED cuando se suelta el botón
			Service::ComandoLED(1, false);
		}
		private: System::Void btnAdelante_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			// Apagar LED si el mouse sale del botón mientras está presionado
			if (Control::MouseButtons == System::Windows::Forms::MouseButtons::Left) {
				Service::ComandoLED(1, false);
			}
		}
		private: System::Void btnAtras_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			// Encender LED cuando se presiona el botón
			Service::ComandoLED(2, true);
		}
		private: System::Void btnAtras_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			// Apagar LED cuando se suelta el botón
			Service::ComandoLED(2, false);
		}
		private: System::Void btnAtras_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			// Apagar LED si el mouse sale del botón mientras está presionado
			if (Control::MouseButtons == System::Windows::Forms::MouseButtons::Left) {
				Service::ComandoLED(2, false);
			}
		}
		private: System::Void btnRight_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			// Encender LED cuando se presiona el botón
			Service::ComandoLED(3, true);
		}
		private: System::Void btnRight_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			// Apagar LED cuando se suelta el botón
			Service::ComandoLED(3, false);
		}
		private: System::Void btnRight_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			// Apagar LED si el mouse sale del botón mientras está presionado
			if (Control::MouseButtons == System::Windows::Forms::MouseButtons::Left) {
				Service::ComandoLED(3, false);
			}
		}
		private: System::Void btnLeft_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			// Encender LED cuando se presiona el botón
			Service::ComandoLED(4, true);
		}
		private: System::Void btnLeft_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			// Apagar LED cuando se suelta el botón
			Service::ComandoLED(4, false);
		}
		private: System::Void btnLeft_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			// Apagar LED si el mouse sale del botón mientras está presionado
			if (Control::MouseButtons == System::Windows::Forms::MouseButtons::Left) {
				Service::ComandoLED(4, false);
			}
		}
		private: System::Void giroDerecha_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			// Encender LED cuando se presiona el botón
			Service::ComandoLED(5, true);
		}
		private: System::Void giroDerecha_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			// Apagar LED cuando se suelta el botón
			Service::ComandoLED(5, false);
		}
		private: System::Void giroDerecha_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			// Apagar LED si el mouse sale del botón mientras está presionado
			if (Control::MouseButtons == System::Windows::Forms::MouseButtons::Left) {
				Service::ComandoLED(5, false);
			}
		}
		private: System::Void giroIzquierda_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			// Encender LED cuando se presiona el botón
			Service::ComandoLED(6, true);
		}
		private: System::Void giroIzquierda_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			// Apagar LED cuando se suelta el botón
			Service::ComandoLED(6, false);
		}
		private: System::Void giroIzquierda_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			// Apagar LED si el mouse sale del botón mientras está presionado
			if (Control::MouseButtons == System::Windows::Forms::MouseButtons::Left) {
				Service::ComandoLED(6, false);
			}
		}
		private: System::Boolean InicializarCamara() {
			try {
				this->videoDivices = gcnew FilterInfoCollection(FilterCategory::VideoInputDevice);
				if (videoDivices->Count == 0) {
					return false;
				}

				String^ camID = this->videoDivices[0]->MonikerString;
				this->videoSource = gcnew VideoCaptureDevice(camID);
				this->videoSource->NewFrame += gcnew AForge::Video::NewFrameEventHandler(this, &ControlRobotForm::video_NewFrame);

				this->videoSource->Start();
				return true;
			}
			catch (Exception^ ex) {
				throw ex;
				return false;
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
						this->pbCamara->BeginInvoke(gcnew Action<Bitmap^>(this, &ControlRobotForm::ActualizarPictureBox), newFrame);
					}
					else if (!this->isClosing) {
						ActualizarPictureBox(newFrame);
					}
				}

				//Liberar frame anterior si existe
				if (oldFrame != nullptr) {
					delete oldFrame;
				}
			}
			catch (Exception^ ex) {
				//Ignorar errores durante el cierre
				if (!this->isClosing) {
					System::Diagnostics::Debug::WriteLine("Error en video_NewFrame: " + ex->Message);
				}
				if (newFrame != nullptr) delete newFrame;
				if (oldFrame != nullptr) delete oldFrame;
			}
		}
		private: System::Void ActualizarPictureBox(Bitmap^ frame) {
			if (this->isClosing) {
				delete frame; // Importante: liberar frame si no se usará
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
				delete frame; // Liberar frame si hay error
				System::Diagnostics::Debug::WriteLine("Error actualizando PictureBox: " + ex->Message);
			}
		}
		private: System::Void ControlRobotForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			this->DesactivarCamara();
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
			MapaForm^ form = gcnew MapaForm();
			this->Hide();
			form->ShowDialog();
			this->Show();
		}
		private: System::Void btnReconectar_Click(System::Object^ sender, System::EventArgs^ e) {
			Service::LiberarPuertoCOM3();

			System::Threading::Thread::Sleep(1000);

			if (Service::ConectarArduino()) {
				MessageBox::Show("✅ Reconectado exitosamente", "Éxito");
			}
			else {
				MessageBox::Show("❌ No se pudo reconectar", "Error");
			}
		}
	};
}
