#pragma once
//#define CV_DISABLE_OPTIMIZATION
/*#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <msclr/marshal_cppstd.h>*/

namespace GUIApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace msclr::interop;

	using namespace BotModel;
	using namespace BotService;

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
			/*timer = gcnew System::Windows::Forms::Timer();
			timer->Interval = 33; // ~30 fps
			timer->Tick += gcnew System::EventHandler(this, &ControlRobotForm::timer_Tick);*/
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
		   //cv::VideoCapture* cap;

	private: System::Windows::Forms::TextBox^ txtRobot;
	private: System::Windows::Forms::PictureBox^ giroIzquierda;
	private: System::Windows::Forms::PictureBox^ giroDerecha;
	private: System::Windows::Forms::PictureBox^ btnAtras;

	private: System::Windows::Forms::PictureBox^ btnAdelante;
	private: System::Windows::Forms::PictureBox^ btnRight;




	private: System::Windows::Forms::PictureBox^ btnLeft;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private:
		System::Windows::Forms::Timer^ timer;

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
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbCamara))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->giroIzquierda))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->giroDerecha))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAtras))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAdelante))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnRight))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnLeft))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pbCamara
			// 
			this->pbCamara->Location = System::Drawing::Point(18, 114);
			this->pbCamara->Name = L"pbCamara";
			this->pbCamara->Size = System::Drawing::Size(302, 197);
			this->pbCamara->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbCamara->TabIndex = 35;
			this->pbCamara->TabStop = false;
			// 
			// txtRobot
			// 
			this->txtRobot->Location = System::Drawing::Point(362, 21);
			this->txtRobot->Multiline = true;
			this->txtRobot->Name = L"txtRobot";
			this->txtRobot->Size = System::Drawing::Size(138, 29);
			this->txtRobot->TabIndex = 34;
			// 
			// giroIzquierda
			// 
			this->giroIzquierda->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"giroIzquierda.Image")));
			this->giroIzquierda->Location = System::Drawing::Point(14, 403);
			this->giroIzquierda->Name = L"giroIzquierda";
			this->giroIzquierda->Size = System::Drawing::Size(182, 155);
			this->giroIzquierda->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->giroIzquierda->TabIndex = 33;
			this->giroIzquierda->TabStop = false;
			this->giroIzquierda->Click += gcnew System::EventHandler(this, &ControlRobotForm::giroIzquierda_Click_1);
			// 
			// giroDerecha
			// 
			this->giroDerecha->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"giroDerecha.Image")));
			this->giroDerecha->Location = System::Drawing::Point(545, 403);
			this->giroDerecha->Name = L"giroDerecha";
			this->giroDerecha->Size = System::Drawing::Size(182, 155);
			this->giroDerecha->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->giroDerecha->TabIndex = 32;
			this->giroDerecha->TabStop = false;
			this->giroDerecha->Click += gcnew System::EventHandler(this, &ControlRobotForm::giroDerecha_Click_1);
			// 
			// btnAtras
			// 
			this->btnAtras->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAtras.Image")));
			this->btnAtras->Location = System::Drawing::Point(310, 523);
			this->btnAtras->Name = L"btnAtras";
			this->btnAtras->Size = System::Drawing::Size(107, 95);
			this->btnAtras->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnAtras->TabIndex = 31;
			this->btnAtras->TabStop = false;
			this->btnAtras->Click += gcnew System::EventHandler(this, &ControlRobotForm::btnAtras_Click);
			// 
			// btnAdelante
			// 
			this->btnAdelante->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAdelante.Image")));
			this->btnAdelante->Location = System::Drawing::Point(310, 346);
			this->btnAdelante->Name = L"btnAdelante";
			this->btnAdelante->Size = System::Drawing::Size(107, 95);
			this->btnAdelante->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnAdelante->TabIndex = 30;
			this->btnAdelante->TabStop = false;
			this->btnAdelante->Click += gcnew System::EventHandler(this, &ControlRobotForm::btnAdelante_Click);
			// 
			// btnRight
			// 
			this->btnRight->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRight.Image")));
			this->btnRight->Location = System::Drawing::Point(408, 435);
			this->btnRight->Name = L"btnRight";
			this->btnRight->Size = System::Drawing::Size(107, 95);
			this->btnRight->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnRight->TabIndex = 29;
			this->btnRight->TabStop = false;
			this->btnRight->Click += gcnew System::EventHandler(this, &ControlRobotForm::btnRight_Click);
			// 
			// btnLeft
			// 
			this->btnLeft->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnLeft.Image")));
			this->btnLeft->Location = System::Drawing::Point(213, 435);
			this->btnLeft->Name = L"btnLeft";
			this->btnLeft->Size = System::Drawing::Size(107, 95);
			this->btnLeft->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->btnLeft->TabIndex = 28;
			this->btnLeft->TabStop = false;
			this->btnLeft->Click += gcnew System::EventHandler(this, &ControlRobotForm::btnLeft_Click_1);
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
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(419, 114);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(291, 197);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 26;
			this->pictureBox2->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label2->Location = System::Drawing::Point(414, 71);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(214, 29);
			this->label2->TabIndex = 25;
			this->label2->Text = L"Posición del robot:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(173, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(183, 29);
			this->label1->TabIndex = 24;
			this->label1->Text = L"Controlar Robot";
			// 
			// ControlRobotForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(741, 639);
			this->Controls->Add(this->pbCamara);
			this->Controls->Add(this->txtRobot);
			this->Controls->Add(this->giroIzquierda);
			this->Controls->Add(this->giroDerecha);
			this->Controls->Add(this->btnAtras);
			this->Controls->Add(this->btnAdelante);
			this->Controls->Add(this->btnRight);
			this->Controls->Add(this->btnLeft);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"ControlRobotForm";
			this->Text = L"ControlRobotForm";
			this->Load += gcnew System::EventHandler(this, &ControlRobotForm::ControlRobotForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbCamara))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->giroIzquierda))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->giroDerecha))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAtras))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnAdelante))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnRight))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnLeft))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ControlRobotForm_Load(System::Object^ sender, System::EventArgs^ e) {
		if (robotEncontrado != nullptr) {
			txtRobot->Text = robotEncontrado->Nombre;
			/*cap = new cv::VideoCapture(0, cv::CAP_DSHOW);
			if (!cap->isOpened()) {
				MessageBox::Show("No se pudo abrir la cámara");
				return;
			}
			timer->Start();*/
		}
		/*bool conectado = MQTTClient::Conectar();
		if (conectado == true) {
			MessageBox::Show("Se ha conectado exitosamente");
		}*/
	}
	private: void timer_Tick(System::Object^ sender, System::EventArgs^ e) {
		/*cv::Mat frame;
		if (!cap->read(frame) || frame.empty()) return;
		cv::cvtColor(frame, frame, cv::COLOR_RGB2BGR);
		cv::Mat* clonedFrame = new cv::Mat(frame.clone());

		System::Drawing::Bitmap^ bmp = gcnew System::Drawing::Bitmap(
			clonedFrame->cols, clonedFrame->rows, clonedFrame->step,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb,
			System::IntPtr(clonedFrame->data));

		bmp->Tag = System::IntPtr(clonedFrame);

		if (pictureBox1->Image != nullptr) {
			Bitmap_Disposed(pictureBox1->Image, nullptr);
			delete pictureBox1->Image;
		}

		pictureBox1->Image = bmp;*/
	}
	private: void Bitmap_Disposed(System::Object^ sender, System::EventArgs^ e) {
		/*System::Drawing::Bitmap^ bmp = safe_cast<System::Drawing::Bitmap^>(sender);

		if (bmp->Tag != nullptr)
		{
			System::IntPtr ptr = safe_cast<System::IntPtr>(bmp->Tag);
			cv::Mat* matPtr = static_cast<cv::Mat*>(ptr.ToPointer());
			if (matPtr != nullptr) {
				delete matPtr;
				bmp->Tag = nullptr;
			}
		}*/
	}
	private: System::Void btnAdelante_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Avanzo", "Exito", MessageBoxButtons::OK);
		MQTTClient::Adelante();
	}
	private: System::Void btnAtras_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Retrocedo", "Exito", MessageBoxButtons::OK);
		MQTTClient::Atras();
	}
	private: System::Void btnRight_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Avanzo hacia la derecha", "Exito", MessageBoxButtons::OK);
		MQTTClient::Derecha();
	}
	private: System::Void btnLeft_Click_1(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Avanzo hacia la izquierda", "Exito", MessageBoxButtons::OK);
		MQTTClient::Izquierda();
	}
	private: System::Void giroDerecha_Click_1(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Giro hacia la derecha", "Exito", MessageBoxButtons::OK);
		MQTTClient::RotarDerecha();
	}
	private: System::Void giroIzquierda_Click_1(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Giro hacia la izquierda", "Exito", MessageBoxButtons::OK);
		MQTTClient::RotarIzquierda();
	}
};
}
