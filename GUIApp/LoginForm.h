#pragma once
#include "UsuarioPromedioForm.h"
#include "AdminForm.h"
#include "SheriffForm.h"
#include "ForgotPasswordForm.h"
#include "UIStyles.h"     // helpers de UI

namespace GUIApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::SqlClient;

    using namespace BotModel;
    using namespace BotService;

    /// <summary>
    /// Resumen de LoginForm
    /// </summary>
    public ref class LoginForm : public System::Windows::Forms::Form
    {
    public:
        LoginForm(void)
        {
            InitializeComponent();
            this->DoubleBuffered = true;

            this->BackColor = System::Drawing::Color::FromArgb(5, 8, 22);
            this->ForeColor = System::Drawing::Color::White;
            this->StartPosition = FormStartPosition::CenterScreen;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;

            StyleControls();
            ClearFields();

            Password->PasswordChar = '*';
        }

    protected:
        ~LoginForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ btnForgotPassword;
        System::Windows::Forms::Button^ btnLogin2;
        System::Windows::Forms::TextBox^ Password;
        System::Windows::Forms::Label^ label5;
        System::Windows::Forms::TextBox^ Username;
        System::Windows::Forms::Label^ label6;
        System::Windows::Forms::Label^ label7;

        System::Windows::Forms::Panel^ mainCard;
        System::Windows::Forms::Panel^ pnlUsername;
        System::Windows::Forms::Panel^ pnlPassword;

        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
            this->btnForgotPassword = (gcnew System::Windows::Forms::Button());
            this->btnLogin2 = (gcnew System::Windows::Forms::Button());
            this->Password = (gcnew System::Windows::Forms::TextBox());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->Username = (gcnew System::Windows::Forms::TextBox());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->mainCard = (gcnew System::Windows::Forms::Panel());
            this->pnlUsername = (gcnew System::Windows::Forms::Panel());
            this->pnlPassword = (gcnew System::Windows::Forms::Panel());
            this->mainCard->SuspendLayout();
            this->pnlUsername->SuspendLayout();
            this->pnlPassword->SuspendLayout();
            this->SuspendLayout();
            // 
            // btnForgotPassword
            // 
            this->btnForgotPassword->Location = System::Drawing::Point(137, 317);
            this->btnForgotPassword->Name = L"btnForgotPassword";
            this->btnForgotPassword->Size = System::Drawing::Size(210, 32);
            this->btnForgotPassword->TabIndex = 27;
            this->btnForgotPassword->Text = L"Olvidé mi contraseña";
            this->btnForgotPassword->UseVisualStyleBackColor = true;
            this->btnForgotPassword->Click += gcnew System::EventHandler(this, &LoginForm::btnForgotPassword_Click);
            // 
            // btnLogin2
            // 
            this->btnLogin2->Location = System::Drawing::Point(112, 241);
            this->btnLogin2->Name = L"btnLogin2";
            this->btnLogin2->Size = System::Drawing::Size(260, 59);
            this->btnLogin2->TabIndex = 26;
            this->btnLogin2->Text = L"Iniciar sesión";
            this->btnLogin2->UseVisualStyleBackColor = true;
            this->btnLogin2->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin2_Click);
            // 
            // Password
            // 
            this->Password->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(47)));
            this->Password->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->Password->ForeColor = System::Drawing::Color::White;
            this->Password->Location = System::Drawing::Point(6, 6);
            this->Password->Margin = System::Windows::Forms::Padding(4);
            this->Password->Name = L"Password";
            this->Password->Size = System::Drawing::Size(180, 15);
            this->Password->TabIndex = 0;
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->label5->Location = System::Drawing::Point(35, 171);
            this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(101, 23);
            this->label5->TabIndex = 24;
            this->label5->Text = L"Contraseña:";
            this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // Username
            // 
            this->Username->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
                static_cast<System::Int32>(static_cast<System::Byte>(47)));
            this->Username->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->Username->ForeColor = System::Drawing::Color::White;
            this->Username->Location = System::Drawing::Point(6, 6);
            this->Username->Margin = System::Windows::Forms::Padding(4);
            this->Username->Name = L"Username";
            this->Username->Size = System::Drawing::Size(180, 15);
            this->Username->TabIndex = 0;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->label6->Location = System::Drawing::Point(35, 108);
            this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(72, 23);
            this->label6->TabIndex = 22;
            this->label6->Text = L"Usuario:";
            this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
            this->label7->Location = System::Drawing::Point(33, 40);
            this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(214, 37);
            this->label7->TabIndex = 21;
            this->label7->Text = L"Inicio de sesión";
            this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // mainCard
            // 
            this->mainCard->BackColor = System::Drawing::Color::Transparent;
            this->mainCard->Controls->Add(this->label7);
            this->mainCard->Controls->Add(this->label6);
            this->mainCard->Controls->Add(this->label5);
            this->mainCard->Controls->Add(this->pnlUsername);
            this->mainCard->Controls->Add(this->pnlPassword);
            this->mainCard->Controls->Add(this->btnLogin2);
            this->mainCard->Controls->Add(this->btnForgotPassword);
            this->mainCard->Location = System::Drawing::Point(20, 20);
            this->mainCard->Name = L"mainCard";
            this->mainCard->Size = System::Drawing::Size(489, 368);
            this->mainCard->TabIndex = 0;
            this->mainCard->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LoginForm::mainCard_Paint);
            // 
            // pnlUsername
            // 
            this->pnlUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->pnlUsername->Controls->Add(this->Username);
            this->pnlUsername->Location = System::Drawing::Point(250, 108);
            this->pnlUsername->Name = L"pnlUsername";
            this->pnlUsername->Size = System::Drawing::Size(193, 28);
            this->pnlUsername->TabIndex = 25;
            this->pnlUsername->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LoginForm::pnlUsername_Paint);
            // 
            // pnlPassword
            // 
            this->pnlPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->pnlPassword->Controls->Add(this->Password);
            this->pnlPassword->Location = System::Drawing::Point(250, 166);
            this->pnlPassword->Name = L"pnlPassword";
            this->pnlPassword->Size = System::Drawing::Size(193, 28);
            this->pnlPassword->TabIndex = 26;
            this->pnlPassword->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &LoginForm::pnlPassword_Paint);
            // 
            // LoginForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(8)),
                static_cast<System::Int32>(static_cast<System::Byte>(22)));
            this->ClientSize = System::Drawing::Size(530, 400);
            this->Controls->Add(this->mainCard);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Name = L"LoginForm";
            this->Text = L"Inicio de sesión";
            this->mainCard->ResumeLayout(false);
            this->mainCard->PerformLayout();
            this->pnlUsername->ResumeLayout(false);
            this->pnlUsername->PerformLayout();
            this->pnlPassword->ResumeLayout(false);
            this->pnlPassword->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion

        // ---------- LÓGICA DE LOGIN ----------
    private: System::Void btnLogin2_Click(System::Object^ sender, System::EventArgs^ e) {

        try
        {
            if (String::IsNullOrEmpty(Username->Text) ||
                String::IsNullOrEmpty(Password->Text))
            {
                MessageBox::Show("Por favor, complete todos los campos",
                    "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            String^ username = Username->Text;
            String^ password = Password->Text;

            DatosUsuario^ usuarioEncontrado = Service::buscarUsuarioCredenciales(username, password);

            if (usuarioEncontrado != nullptr)
            {
                int userID = usuarioEncontrado->ID;
                String^ strID = userID.ToString();

                if (strID->Length >= 2)
                {
                    String^ primerosDigitos = strID->Substring(0, 2);

                    // ADMIN
                    if (primerosDigitos == "99")
                    {
                        AdminForm^ adminForm = gcnew AdminForm(usuarioEncontrado);
                        this->Hide();
                        adminForm->ShowDialog();
                        this->Show();
                    }
                    // SHERIFF
                    else if (primerosDigitos == "11")
                    {
                        SheriffForm^ sheriffForm = gcnew SheriffForm(usuarioEncontrado);
                        this->Hide();
                        sheriffForm->ShowDialog();
                        this->Show();
                    }
                    // USUARIO GENERAL
                    else if (primerosDigitos == "22" ||
                        primerosDigitos == "33" ||
                        primerosDigitos == "44")
                    {
                        UsuarioPromedioForm^ usuarioForm = gcnew UsuarioPromedioForm(usuarioEncontrado);
                        this->Hide();
                        usuarioForm->ShowDialog();
                        this->Show();
                    }
                }
            }
            else
            {
                MessageBox::Show("Nombre de usuario o contraseña incorrectos",
                    "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }

            ClearFields();
        }
        catch (SqlException^ sqlEx)
        {
            MessageBox::Show("Error SQL: " + sqlEx->Message,
                "Error en base de datos", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
        catch (Exception^ ex)
        {
            MessageBox::Show("Error al iniciar sesión: " + ex->Message,
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    private: void ClearFields() {
        Username->Text = "";
        Password->Text = "";
    }

    private: System::Void btnForgotPassword_Click(System::Object^ sender, System::EventArgs^ e) {
        ForgotPasswordForm^ form = gcnew ForgotPasswordForm();
        this->Hide();
        form->ShowDialog();
        this->Show();
    }

           // ---------- Estilos visuales ----------
    private:
        void StyleControls()
        {
            // Labels
            this->label7->ForeColor = System::Drawing::Color::White;
            this->label6->ForeColor = System::Drawing::Color::FromArgb(200, 210, 230);
            this->label5->ForeColor = System::Drawing::Color::FromArgb(200, 210, 230);

            // Botón primario (Iniciar sesión)
            this->btnLogin2->FlatStyle = FlatStyle::Flat;
            this->btnLogin2->FlatAppearance->BorderSize = 0;
            this->btnLogin2->BackColor = System::Drawing::Color::FromArgb(0, 140, 255);
            this->btnLogin2->ForeColor = System::Drawing::Color::White;
            this->btnLogin2->Font =
                gcnew System::Drawing::Font("Segoe UI", 10, System::Drawing::FontStyle::Bold);
            GUIApp::UIHelpers::SetRoundedRegion(this->btnLogin2, 18);

            // Botón secundario (Olvidé mi contraseña)
            this->btnForgotPassword->FlatStyle = FlatStyle::Flat;
            this->btnForgotPassword->FlatAppearance->BorderSize = 0;
            this->btnForgotPassword->BackColor = System::Drawing::Color::FromArgb(20, 27, 47);
            this->btnForgotPassword->ForeColor =
                System::Drawing::Color::FromArgb(0, 140, 255);
            this->btnForgotPassword->Font =
                gcnew System::Drawing::Font("Segoe UI", 8, System::Drawing::FontStyle::Regular);
            GUIApp::UIHelpers::SetRoundedRegion(this->btnForgotPassword, 12);

            this->btnForgotPassword->Paint += gcnew System::Windows::Forms::PaintEventHandler(
                this, &LoginForm::btnForgotPassword_Paint);
        }

        // ---------- Wrappers / pintura personalizada ----------
    private:
        System::Void mainCard_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            GUIApp::UIHelpers::RoundedPanel_Paint(sender, e);
        }

        // Borde tipo píldora con radio adaptado a la altura
        System::Void btnForgotPassword_Paint(System::Object^ sender,
            System::Windows::Forms::PaintEventArgs^ e)
        {
            System::Windows::Forms::Button^ b =
                safe_cast<System::Windows::Forms::Button^>(sender);

            e->Graphics->SmoothingMode =
                System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

            int r = (b->Height - 1) / 2; // radio según altura
            System::Drawing::Rectangle rect(0, 0, b->Width - 1, b->Height - 1);
            int d = r * 2;

            System::Drawing::Drawing2D::GraphicsPath^ path =
                gcnew System::Drawing::Drawing2D::GraphicsPath();
            path->AddArc(rect.X, rect.Y, d, d, 180, 90);
            path->AddArc(rect.Right - d, rect.Y, d, d, 270, 90);
            path->AddArc(rect.Right - d, rect.Bottom - d, d, d, 0, 90);
            path->AddArc(rect.X, rect.Bottom - d, d, d, 90, 90);
            path->CloseFigure();

            System::Drawing::Pen^ pen =
                gcnew System::Drawing::Pen(
                    System::Drawing::Color::FromArgb(0, 140, 255), 1.5f);

            e->Graphics->DrawPath(pen, path);
        }

        // Bordes celestes rectos de los paneles de texto
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
    };
}
