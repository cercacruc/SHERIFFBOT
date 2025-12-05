#pragma once
#include "UIStyles.h"   // helpers de UI

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


    /// Resumen de ForgotPasswordForm

    public ref class ForgotPasswordForm : public System::Windows::Forms::Form
    {
    public:
        ForgotPasswordForm(void)
        {
            InitializeComponent();
            this->DoubleBuffered = true;
            StyleControls();

            // Campos de contraseña como password
            NewPassword1->PasswordChar = '*';
            NewPassword2->PasswordChar = '*';
        }

    protected:

        /// Limpiar los recursos que se estén usando.

        ~ForgotPasswordForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        // Controles de la UI
        System::Windows::Forms::Button^ btnSendPassword;
        System::Windows::Forms::Button^ btnReturnPassword;
        System::Windows::Forms::TextBox^ NewPassword2;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::TextBox^ NewPassword1;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::TextBox^ UserName;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label1;

        // Panel "tarjeta" y paneles de texto al estilo LoginForm
        System::Windows::Forms::Panel^ mainCard;
        System::Windows::Forms::Panel^ pnlUserName;
        System::Windows::Forms::Panel^ pnlNewPassword1;
        System::Windows::Forms::Panel^ pnlNewPassword2;


        /// Variable del diseñador necesaria.

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
     
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ForgotPasswordForm::typeid));
            this->btnSendPassword = (gcnew System::Windows::Forms::Button());
            this->btnReturnPassword = (gcnew System::Windows::Forms::Button());
            this->NewPassword2 = (gcnew System::Windows::Forms::TextBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->NewPassword1 = (gcnew System::Windows::Forms::TextBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->UserName = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->mainCard = (gcnew System::Windows::Forms::Panel());
            this->pnlUserName = (gcnew System::Windows::Forms::Panel());
            this->pnlNewPassword1 = (gcnew System::Windows::Forms::Panel());
            this->pnlNewPassword2 = (gcnew System::Windows::Forms::Panel());
            this->mainCard->SuspendLayout();
            this->pnlUserName->SuspendLayout();
            this->pnlNewPassword1->SuspendLayout();
            this->pnlNewPassword2->SuspendLayout();
            this->SuspendLayout();
            // 
            // btnSendPassword
            // 
            this->btnSendPassword->Location = System::Drawing::Point(100, 310);
            this->btnSendPassword->Name = L"btnSendPassword";
            this->btnSendPassword->Size = System::Drawing::Size(260, 48);
            this->btnSendPassword->TabIndex = 33;
            this->btnSendPassword->Text = L"Restablecer contraseña";
            this->btnSendPassword->UseVisualStyleBackColor = true;
            this->btnSendPassword->Click += gcnew System::EventHandler(this, &ForgotPasswordForm::btnSendPassword_Click);
            // 
            // btnReturnPassword
            // 
            this->btnReturnPassword->Location = System::Drawing::Point(135, 370);
            this->btnReturnPassword->Name = L"btnReturnPassword";
            this->btnReturnPassword->Size = System::Drawing::Size(190, 32);
            this->btnReturnPassword->TabIndex = 32;
            this->btnReturnPassword->Text = L"Volver al inicio de sesión";
            this->btnReturnPassword->UseVisualStyleBackColor = true;
            this->btnReturnPassword->Click += gcnew System::EventHandler(this, &ForgotPasswordForm::btnReturnPassword_Click);
            // 
            // NewPassword2
            // 
            this->NewPassword2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(47)));
            this->NewPassword2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->NewPassword2->ForeColor = System::Drawing::Color::White;
            this->NewPassword2->Location = System::Drawing::Point(6, 6);
            this->NewPassword2->Margin = System::Windows::Forms::Padding(4);
            this->NewPassword2->Name = L"NewPassword2";
            this->NewPassword2->Size = System::Drawing::Size(175, 15);
            this->NewPassword2->TabIndex = 0;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->label4->Location = System::Drawing::Point(32, 240);
            this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(191, 23);
            this->label4->TabIndex = 30;
            this->label4->Text = L"Confirme la contraseña:";
            this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // NewPassword1
            // 
            this->NewPassword1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(47)));
            this->NewPassword1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->NewPassword1->ForeColor = System::Drawing::Color::White;
            this->NewPassword1->Location = System::Drawing::Point(6, 6);
            this->NewPassword1->Margin = System::Windows::Forms::Padding(4);
            this->NewPassword1->Name = L"NewPassword1";
            this->NewPassword1->Size = System::Drawing::Size(175, 15);
            this->NewPassword1->TabIndex = 0;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->label3->Location = System::Drawing::Point(32, 175);
            this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(210, 23);
            this->label3->TabIndex = 28;
            this->label3->Text = L"Ingrese nueva contraseña:";
            this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // UserName
            // 
            this->UserName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(47)));
            this->UserName->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->UserName->ForeColor = System::Drawing::Color::White;
            this->UserName->Location = System::Drawing::Point(6, 6);
            this->UserName->Margin = System::Windows::Forms::Padding(4);
            this->UserName->Name = L"UserName";
            this->UserName->Size = System::Drawing::Size(175, 15);
            this->UserName->TabIndex = 0;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->label2->Location = System::Drawing::Point(32, 110);
            this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(72, 23);
            this->label2->TabIndex = 26;
            this->label2->Text = L"Usuario:";
            this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
            this->label1->Location = System::Drawing::Point(32, 32);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(314, 37);
            this->label1->TabIndex = 25;
            this->label1->Text = L"Restablecer contraseña";
            // 
            // mainCard
            // 
            this->mainCard->BackColor = System::Drawing::Color::Transparent;
            this->mainCard->Controls->Add(this->label1);
            this->mainCard->Controls->Add(this->label2);
            this->mainCard->Controls->Add(this->pnlUserName);
            this->mainCard->Controls->Add(this->label3);
            this->mainCard->Controls->Add(this->pnlNewPassword1);
            this->mainCard->Controls->Add(this->label4);
            this->mainCard->Controls->Add(this->pnlNewPassword2);
            this->mainCard->Controls->Add(this->btnSendPassword);
            this->mainCard->Controls->Add(this->btnReturnPassword);
            this->mainCard->Location = System::Drawing::Point(20, 20);
            this->mainCard->Name = L"mainCard";
            this->mainCard->Size = System::Drawing::Size(480, 440);
            this->mainCard->TabIndex = 0;
            this->mainCard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ForgotPasswordForm::mainCard_Paint);
            // 
            // pnlUserName
            // 
            this->pnlUserName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->pnlUserName->Controls->Add(this->UserName);
            this->pnlUserName->Location = System::Drawing::Point(267, 110);
            this->pnlUserName->Name = L"pnlUserName";
            this->pnlUserName->Size = System::Drawing::Size(190, 28);
            this->pnlUserName->TabIndex = 27;
            this->pnlUserName->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ForgotPasswordForm::pnlUserName_Paint);
            // 
            // pnlNewPassword1
            // 
            this->pnlNewPassword1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->pnlNewPassword1->Controls->Add(this->NewPassword1);
            this->pnlNewPassword1->Location = System::Drawing::Point(267, 175);
            this->pnlNewPassword1->Name = L"pnlNewPassword1";
            this->pnlNewPassword1->Size = System::Drawing::Size(190, 28);
            this->pnlNewPassword1->TabIndex = 29;
            this->pnlNewPassword1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ForgotPasswordForm::pnlNewPassword1_Paint);
            // 
            // pnlNewPassword2
            // 
            this->pnlNewPassword2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->pnlNewPassword2->Controls->Add(this->NewPassword2);
            this->pnlNewPassword2->Location = System::Drawing::Point(267, 240);
            this->pnlNewPassword2->Name = L"pnlNewPassword2";
            this->pnlNewPassword2->Size = System::Drawing::Size(190, 28);
            this->pnlNewPassword2->TabIndex = 31;
            this->pnlNewPassword2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ForgotPasswordForm::pnlNewPassword2_Paint);
            // 
            // ForgotPasswordForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->ClientSize = System::Drawing::Size(519, 484);
            this->Controls->Add(this->mainCard);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"ForgotPasswordForm";
            this->Text = L"Restablecer contraseña";
            this->Load += gcnew System::EventHandler(this, &ForgotPasswordForm::ForgotPasswordForm_Load);
            this->mainCard->ResumeLayout(false);
            this->mainCard->PerformLayout();
            this->pnlUserName->ResumeLayout(false);
            this->pnlUserName->PerformLayout();
            this->pnlNewPassword1->ResumeLayout(false);
            this->pnlNewPassword1->PerformLayout();
            this->pnlNewPassword2->ResumeLayout(false);
            this->pnlNewPassword2->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

        // ----------- LÓGICA DE NEGOCIO / SERVICE (igual que tu versión) -----------
    private: System::Void btnSendPassword_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (String::IsNullOrEmpty(UserName->Text) ||
                String::IsNullOrEmpty(NewPassword1->Text) ||
                String::IsNullOrEmpty(NewPassword2->Text)) {
                MessageBox::Show("Por favor, complete todos los campos",
                    "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }
            if (NewPassword1->Text != NewPassword2->Text) {
                MessageBox::Show("Las contraseñas no coinciden",
                    "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                NewPassword1->Text = "";
                NewPassword2->Text = "";
                NewPassword1->Focus();
                return;
            }

            int restablecer = Service::restablecerUsuario(
                UserName->Text,
                NewPassword1->Text,
                NewPassword2->Text
            );

            if (restablecer != 0) {
                MessageBox::Show("Contraseña restablecida exitosamente",
                    "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
                this->Close();
            }
            else {
                MessageBox::Show("Error al cambiar la contraseña",
                    "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error al restablecer contraseña: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: System::Void btnReturnPassword_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }

    private: void CargarDatos() {
        List<DatosUsuario^>^ usuarioList = Service::GetUsuarios();
        // (Por ahora sólo llama a Service, igual que tu versión original)
    }

    private: System::Void ForgotPasswordForm_Load(System::Object^ sender, System::EventArgs^ e) {
        CargarDatos();
    }

           // ------------------- ESTILOS VISUALES (igual filosofía que LoginForm) -------------------
    private:
        void StyleControls()
        {
            // Labels
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label2->ForeColor = System::Drawing::Color::FromArgb(200, 210, 230);
            this->label3->ForeColor = System::Drawing::Color::FromArgb(200, 210, 230);
            this->label4->ForeColor = System::Drawing::Color::FromArgb(200, 210, 230);

            // Botón primario (Restablecer)
            this->btnSendPassword->FlatStyle = FlatStyle::Flat;
            this->btnSendPassword->FlatAppearance->BorderSize = 0;
            this->btnSendPassword->BackColor = System::Drawing::Color::FromArgb(0, 140, 255);
            this->btnSendPassword->ForeColor = System::Drawing::Color::White;
            this->btnSendPassword->Font =
                gcnew System::Drawing::Font("Segoe UI", 10, System::Drawing::FontStyle::Bold);
            UIHelpers::SetRoundedRegionAuto(this->btnSendPassword);

            // Botón secundario (Volver)
            this->btnReturnPassword->FlatStyle = FlatStyle::Flat;
            this->btnReturnPassword->FlatAppearance->BorderSize = 0;
            this->btnReturnPassword->BackColor = System::Drawing::Color::FromArgb(20, 27, 47);
            this->btnReturnPassword->ForeColor =
                System::Drawing::Color::FromArgb(0, 140, 255);
            this->btnReturnPassword->Font =
                gcnew System::Drawing::Font("Segoe UI", 8, System::Drawing::FontStyle::Regular);
            UIHelpers::SetRoundedRegionAuto(this->btnReturnPassword);

            // Usar el helper de borde celeste tipo píldora
            this->btnReturnPassword->Paint += gcnew System::Windows::Forms::PaintEventHandler(
                &GUIApp::UIHelpers::OutlineButton_Paint);
        }

        // ------------------- PINTURA PERSONALIZADA -------------------
    private:
        System::Void mainCard_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            UIHelpers::RoundedPanel_Paint(sender, e);
        }

        System::Void pnlUserName_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            e->Graphics->SmoothingMode =
                System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

            System::Drawing::Rectangle rect(0, 0,
                this->pnlUserName->Width - 1,
                this->pnlUserName->Height - 1);

            System::Drawing::Pen^ pen =
                gcnew System::Drawing::Pen(
                    System::Drawing::Color::FromArgb(0, 140, 255), 1.0f);

            e->Graphics->DrawRectangle(pen, rect);
        }

        System::Void pnlNewPassword1_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            e->Graphics->SmoothingMode =
                System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

            System::Drawing::Rectangle rect(0, 0,
                this->pnlNewPassword1->Width - 1,
                this->pnlNewPassword1->Height - 1);

            System::Drawing::Pen^ pen =
                gcnew System::Drawing::Pen(
                    System::Drawing::Color::FromArgb(0, 140, 255), 1.0f);

            e->Graphics->DrawRectangle(pen, rect);
        }

        System::Void pnlNewPassword2_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            e->Graphics->SmoothingMode =
                System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

            System::Drawing::Rectangle rect(0, 0,
                this->pnlNewPassword2->Width - 1,
                this->pnlNewPassword2->Height - 1);

            System::Drawing::Pen^ pen =
                gcnew System::Drawing::Pen(
                    System::Drawing::Color::FromArgb(0, 140, 255), 1.0f);

            e->Graphics->DrawRectangle(pen, rect);
        }
    };
}
