#pragma once
#include "RegisterForm.h"
#include "LoginForm.h"
#include "UIStyles.h"   // kit de UI (UIHelpers)

namespace GUIApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Threading;

    /// <summary>
    /// Resumen de MainForm
    /// </summary>
    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void)
        {
            InitializeComponent();
            this->DoubleBuffered = true;

            // <<< Estilo base unificado >>>
            this->BackColor = System::Drawing::Color::FromArgb(5, 8, 22);
            this->ForeColor = System::Drawing::Color::White;
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;

            StyleButtons();   // aplicar estilos modernos
        }

    protected:
        ~MainForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ btnLogin;
        System::Windows::Forms::Button^ btnRegister;
        System::Windows::Forms::PictureBox^ pictureBox1;

        System::Windows::Forms::Panel^ mainCard;  // panel normal (lo pintamos redondeado)

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
            this->btnLogin = (gcnew System::Windows::Forms::Button());
            this->btnRegister = (gcnew System::Windows::Forms::Button());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->mainCard = (gcnew System::Windows::Forms::Panel());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->mainCard->SuspendLayout();
            this->SuspendLayout();
            // 
            // btnLogin
            // 
            this->btnLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->btnLogin->Location = System::Drawing::Point(82, 380);
            this->btnLogin->Name = L"btnLogin";
            this->btnLogin->Size = System::Drawing::Size(249, 66);
            this->btnLogin->TabIndex = 7;
            this->btnLogin->Text = L"Iniciar sesión";
            this->btnLogin->UseVisualStyleBackColor = true;
            this->btnLogin->Click += gcnew System::EventHandler(this, &MainForm::btnLogin_Click);
            // 
            // btnRegister
            // 
            this->btnRegister->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
            this->btnRegister->Location = System::Drawing::Point(82, 300);
            this->btnRegister->Name = L"btnRegister";
            this->btnRegister->Size = System::Drawing::Size(249, 62);
            this->btnRegister->TabIndex = 6;
            this->btnRegister->Text = L"Registrarse";
            this->btnRegister->UseVisualStyleBackColor = true;
            this->btnRegister->Click += gcnew System::EventHandler(this, &MainForm::btnRegister_Click);
            // 
            // pictureBox1
            // 
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(37, 40);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(340, 230);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 8;
            this->pictureBox1->TabStop = false;
            // 
            // mainCard
            // 
            this->mainCard->BackColor = System::Drawing::Color::Transparent;
            this->mainCard->Controls->Add(this->pictureBox1);
            this->mainCard->Controls->Add(this->btnRegister);
            this->mainCard->Controls->Add(this->btnLogin);
            this->mainCard->Location = System::Drawing::Point(20, 20);
            this->mainCard->Name = L"mainCard";
            this->mainCard->Size = System::Drawing::Size(416, 488);
            this->mainCard->TabIndex = 0;
            this->mainCard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::mainCard_Paint);
            // 
            // MainForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->ClientSize = System::Drawing::Size(457, 528);
            this->Controls->Add(this->mainCard);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"MainForm";
            this->Text = L"PUCPTA - Robot vigilante";
            this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->mainCard->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion

    private:
        // ----- Navegación -----
        System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {
            RegisterForm^ registerform = gcnew RegisterForm();
            registerform->Owner = this;
            this->Hide();
            registerform->ShowDialog();
            this->Show();
        }

        System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
            LoginForm^ loginForm = gcnew LoginForm();
            loginForm->Owner = this;
            this->Hide();
            loginForm->ShowDialog();
            this->Show();
        }

        // ----- Estilos de botones -----
        void StyleButtons()
        {
            // Botón primario (Iniciar sesión)
            this->btnLogin->FlatStyle = FlatStyle::Flat;
            this->btnLogin->FlatAppearance->BorderSize = 0;
            this->btnLogin->BackColor = System::Drawing::Color::FromArgb(0, 140, 255);
            this->btnLogin->ForeColor = System::Drawing::Color::White;
            this->btnLogin->Font =
                gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);
            GUIApp::UIHelpers::SetRoundedRegion(this->btnLogin, 18);

            // Botón secundario (Registrarse)
            this->btnRegister->FlatStyle = FlatStyle::Flat;
            this->btnRegister->FlatAppearance->BorderSize = 0;
            this->btnRegister->BackColor = System::Drawing::Color::FromArgb(20, 27, 47);
            this->btnRegister->ForeColor =
                System::Drawing::Color::FromArgb(224, 231, 255);
            this->btnRegister->Font =
                gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Regular);
            GUIApp::UIHelpers::SetRoundedRegion(this->btnRegister, 18);

            // Borde redondeado celeste (wrapper local)
            this->btnRegister->Paint += gcnew System::Windows::Forms::PaintEventHandler(
                this, &MainForm::btnRegister_Paint);
        }

        // ----- Wrappers para llamar a UIHelpers (evitan errores del diseñador) -----
    private:
        System::Void mainCard_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            GUIApp::UIHelpers::RoundedPanel_Paint(sender, e);
        }

        System::Void btnRegister_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            GUIApp::UIHelpers::OutlineButton_Paint(sender, e);
        }

        // ----- Hilo para hora en el título -----
        Thread^ myThread;
        delegate void MyDelegate(String^);

        System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
            myThread = gcnew Thread(gcnew ThreadStart(this, &MainForm::CargarHoraRealTime));
            myThread->IsBackground = true; // para que no bloquee al cerrar
            myThread->Start();
        }

        void CargarHoraRealTime() {
            String^ title = "PUCPTA - ";
            while (true)
            {
                try {
                    Thread::Sleep(1000);
                    Invoke(gcnew MyDelegate(this, &MainForm::UpdateTitle),
                        title + DateTime::Now.ToString());
                }
                catch (Exception^) {
                    return;
                }
            }
        }

        void UpdateTitle(String^ newTitle) {
            this->Text = newTitle;
        }
    };
}
