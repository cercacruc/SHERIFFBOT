#pragma once
#include "UIStyles.h"

namespace GUIApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    using namespace System::Collections::Generic;
    using namespace BotModel;
    using namespace BotService;

    /// <summary>
    /// Resumen de RegisterForm
    /// </summary>
    public ref class RegisterForm : public System::Windows::Forms::Form
    {
    public:
        RegisterForm(void)
        {
            InitializeComponent();
            this->DoubleBuffered = true;
            StyleControls();

            textPassword->PasswordChar = '*';
        }

    protected:
        ~RegisterForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ btnRegister2;
        System::Windows::Forms::ComboBox^ textRole;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::TextBox^ textPassword;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::TextBox^ textUsername;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label1;

        System::Windows::Forms::Panel^ mainCard;
        System::Windows::Forms::Panel^ pnlUsername;
        System::Windows::Forms::Panel^ pnlPassword;
        System::Windows::Forms::Panel^ pnlRole;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
            this->btnRegister2 = (gcnew System::Windows::Forms::Button());
            this->textRole = (gcnew System::Windows::Forms::ComboBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->textPassword = (gcnew System::Windows::Forms::TextBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->textUsername = (gcnew System::Windows::Forms::TextBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->mainCard = (gcnew System::Windows::Forms::Panel());
            this->pnlUsername = (gcnew System::Windows::Forms::Panel());
            this->pnlPassword = (gcnew System::Windows::Forms::Panel());
            this->pnlRole = (gcnew System::Windows::Forms::Panel());
            this->mainCard->SuspendLayout();
            this->pnlUsername->SuspendLayout();
            this->pnlPassword->SuspendLayout();
            this->pnlRole->SuspendLayout();
            this->SuspendLayout();
            // 
            // btnRegister2
            // 
            this->btnRegister2->Location = System::Drawing::Point(115, 284);
            this->btnRegister2->Name = L"btnRegister2";
            this->btnRegister2->Size = System::Drawing::Size(260, 55);
            this->btnRegister2->TabIndex = 22;
            this->btnRegister2->Text = L"Registrarse";
            this->btnRegister2->UseVisualStyleBackColor = true;
            this->btnRegister2->Click += gcnew System::EventHandler(this, &RegisterForm::btnRegister2_Click);
            // 
            // textRole
            // 
            this->textRole->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(47)));
            this->textRole->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->textRole->ForeColor = System::Drawing::Color::White;
            this->textRole->FormattingEnabled = true;
            this->textRole->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Sheriff", L"Estudiante", L"Profesor", L"Visitante externo" });
            this->textRole->Location = System::Drawing::Point(3, 5);
            this->textRole->Name = L"textRole";
            this->textRole->Size = System::Drawing::Size(184, 24);
            this->textRole->TabIndex = 0;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->label4->Location = System::Drawing::Point(24, 218);
            this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(131, 23);
            this->label4->TabIndex = 20;
            this->label4->Text = L"Escoja su cargo:";
            this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // textPassword
            // 
            this->textPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(47)));
            this->textPassword->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textPassword->ForeColor = System::Drawing::Color::White;
            this->textPassword->Location = System::Drawing::Point(6, 6);
            this->textPassword->Margin = System::Windows::Forms::Padding(4);
            this->textPassword->Name = L"textPassword";
            this->textPassword->Size = System::Drawing::Size(178, 15);
            this->textPassword->TabIndex = 0;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->label3->Location = System::Drawing::Point(24, 156);
            this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(160, 23);
            this->label3->TabIndex = 18;
            this->label3->Text = L"Cree su contraseña:";
            this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // textUsername
            // 
            this->textUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(47)));
            this->textUsername->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textUsername->ForeColor = System::Drawing::Color::White;
            this->textUsername->Location = System::Drawing::Point(6, 6);
            this->textUsername->Margin = System::Windows::Forms::Padding(4);
            this->textUsername->Name = L"textUsername";
            this->textUsername->Size = System::Drawing::Size(178, 15);
            this->textUsername->TabIndex = 0;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->label2->Location = System::Drawing::Point(24, 93);
            this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(221, 23);
            this->label2->TabIndex = 16;
            this->label2->Text = L"Cree su nombre de usuario:";
            this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
            this->label1->Location = System::Drawing::Point(22, 25);
            this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(125, 37);
            this->label1->TabIndex = 15;
            this->label1->Text = L"Registro";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // mainCard
            // 
            this->mainCard->BackColor = System::Drawing::Color::Transparent;
            this->mainCard->Controls->Add(this->label1);
            this->mainCard->Controls->Add(this->label2);
            this->mainCard->Controls->Add(this->label3);
            this->mainCard->Controls->Add(this->label4);
            this->mainCard->Controls->Add(this->pnlUsername);
            this->mainCard->Controls->Add(this->pnlPassword);
            this->mainCard->Controls->Add(this->pnlRole);
            this->mainCard->Controls->Add(this->btnRegister2);
            this->mainCard->Location = System::Drawing::Point(20, 20);
            this->mainCard->Name = L"mainCard";
            this->mainCard->Size = System::Drawing::Size(493, 354);
            this->mainCard->TabIndex = 0;
            this->mainCard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &RegisterForm::mainCard_Paint);
            // 
            // pnlUsername
            // 
            this->pnlUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->pnlUsername->Controls->Add(this->textUsername);
            this->pnlUsername->Location = System::Drawing::Point(278, 86);
            this->pnlUsername->Name = L"pnlUsername";
            this->pnlUsername->Size = System::Drawing::Size(190, 32);
            this->pnlUsername->TabIndex = 21;
            this->pnlUsername->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &RegisterForm::pnlUsername_Paint);
            // 
            // pnlPassword
            // 
            this->pnlPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->pnlPassword->Controls->Add(this->textPassword);
            this->pnlPassword->Location = System::Drawing::Point(278, 149);
            this->pnlPassword->Name = L"pnlPassword";
            this->pnlPassword->Size = System::Drawing::Size(190, 32);
            this->pnlPassword->TabIndex = 22;
            this->pnlPassword->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &RegisterForm::pnlPassword_Paint);
            // 
            // pnlRole
            // 
            this->pnlRole->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->pnlRole->Controls->Add(this->textRole);
            this->pnlRole->Location = System::Drawing::Point(278, 211);
            this->pnlRole->Name = L"pnlRole";
            this->pnlRole->Size = System::Drawing::Size(190, 34);
            this->pnlRole->TabIndex = 23;
            this->pnlRole->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &RegisterForm::pnlRole_Paint);
            // 
            // RegisterForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->ClientSize = System::Drawing::Size(532, 393);
            this->Controls->Add(this->mainCard);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"RegisterForm";
            this->Text = L"Registro";
            this->mainCard->ResumeLayout(false);
            this->mainCard->PerformLayout();
            this->pnlUsername->ResumeLayout(false);
            this->pnlUsername->PerformLayout();
            this->pnlPassword->ResumeLayout(false);
            this->pnlPassword->PerformLayout();
            this->pnlRole->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void btnRegister2_Click(System::Object^ sender, System::EventArgs^ e) {
        try
        {
            if (String::IsNullOrEmpty(textUsername->Text) ||
                String::IsNullOrEmpty(textPassword->Text) ||
                String::IsNullOrEmpty(textRole->Text))
            {
                MessageBox::Show("Por favor, complete todos los campos",
                    "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            DatosUsuario^ usuario = gcnew DatosUsuario();

            usuario->Nombre = textUsername->Text;
            usuario->Contra = textPassword->Text;
            usuario->Cargo = textRole->Text;

            usuario->cant_alertas = gcnew array<int>(3);
            usuario->cant_alertas[0] = 0;  // Pérdidas
            usuario->cant_alertas[1] = 0;  // Altercados
            usuario->cant_alertas[2] = 0;  // Reportes DTI

            Service::registrarUsuario(usuario);

            MessageBox::Show("¡Registro exitoso!", "Éxito",
                MessageBoxButtons::OK, MessageBoxIcon::Information);

            this->Close();
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error al registrar usuario: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

           // --------- Estilos visuales ---------
    private:
        void StyleControls()
        {
            // Labels
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label2->ForeColor = System::Drawing::Color::FromArgb(200, 210, 230);
            this->label3->ForeColor = System::Drawing::Color::FromArgb(200, 210, 230);
            this->label4->ForeColor = System::Drawing::Color::FromArgb(200, 210, 230);

            // Botón principal
            this->btnRegister2->FlatStyle = FlatStyle::Flat;
            this->btnRegister2->FlatAppearance->BorderSize = 0;
            this->btnRegister2->BackColor = System::Drawing::Color::FromArgb(0, 140, 255);
            this->btnRegister2->ForeColor = System::Drawing::Color::White;
            this->btnRegister2->Font =
                gcnew System::Drawing::Font("Segoe UI", 10, System::Drawing::FontStyle::Bold);
            GUIApp::UIHelpers::SetRoundedRegion(this->btnRegister2, 18);
        }

        // --------- Wrappers de pintura ---------
    private:
        System::Void mainCard_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            GUIApp::UIHelpers::RoundedPanel_Paint(sender, e);
        }

        System::Void pnlUsername_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            e->Graphics->SmoothingMode =
                System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
            System::Drawing::Rectangle rect(0, 0,
                this->pnlUsername->Width - 1,
                this->pnlUsername->Height - 1);
            System::Drawing::Pen^ pen =
                gcnew System::Drawing::Pen(
                    System::Drawing::Color::FromArgb(0, 140, 255), 1.0f);
            e->Graphics->DrawRectangle(pen, rect);
        }

        System::Void pnlPassword_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            e->Graphics->SmoothingMode =
                System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
            System::Drawing::Rectangle rect(0, 0,
                this->pnlPassword->Width - 1,
                this->pnlPassword->Height - 1);
            System::Drawing::Pen^ pen =
                gcnew System::Drawing::Pen(
                    System::Drawing::Color::FromArgb(0, 140, 255), 1.0f);
            e->Graphics->DrawRectangle(pen, rect);
        }

        System::Void pnlRole_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            e->Graphics->SmoothingMode =
                System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
            System::Drawing::Rectangle rect(0, 0,
                this->pnlRole->Width - 1,
                this->pnlRole->Height - 1);
            System::Drawing::Pen^ pen =
                gcnew System::Drawing::Pen(
                    System::Drawing::Color::FromArgb(0, 140, 255), 1.0f);
            e->Graphics->DrawRectangle(pen, rect);
        }
    };
}
