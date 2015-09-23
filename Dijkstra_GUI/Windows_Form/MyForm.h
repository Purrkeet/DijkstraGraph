#pragma once
#include "Figuras.h"


namespace Windows_Form {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		int x, y;
		Circulos* listaCirculos;
	public:
		MyForm(void)
		{
			InitializeComponent();
			listaCirculos = new Circulos();
			x = 0; y = 0;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~MyForm()
		{
			
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^  ciclo;
	private: System::Windows::Forms::Panel^  panelPrincipal;

	protected:

	protected:

	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->ciclo = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelPrincipal = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// ciclo
			// 
			this->ciclo->Enabled = true;
			this->ciclo->Interval = 75;
			this->ciclo->Tick += gcnew System::EventHandler(this, &MyForm::ciclo_Tick);
			// 
			// panelPrincipal
			// 
			this->panelPrincipal->BackColor = System::Drawing::Color::White;
			this->panelPrincipal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelPrincipal->Location = System::Drawing::Point(0, 0);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(584, 412);
			this->panelPrincipal->TabIndex = 0;
			this->panelPrincipal->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panelPrincipal_MouseClick);
			this->panelPrincipal->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panelPrincipal_MouseMove);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(584, 412);
			this->Controls->Add(this->panelPrincipal);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void ciclo_Tick(System::Object^  sender, System::EventArgs^  e) {
				Graphics^ lienzo = this->panelPrincipal->CreateGraphics();

				listaCirculos->mostrar(lienzo);

				delete lienzo;
		}
	private: System::Void panelPrincipal_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 x = e->Location.X;
				 y = e->Location.Y;
				 
	}
	private: System::Void panelPrincipal_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 
				 if (e->Button == System::Windows::Forms::MouseButtons::Left)
				 {
					 listaCirculos->agregar(x, y, 15);
				 }					 
				 else if (e->Button == System::Windows::Forms::MouseButtons::Right) 
				 {
					 Punto* nodo = listaCirculos->encontrarCirculo(x, y);
					 MessageBox::Show("(x, y) = (" + nodo->x + ", " + nodo->y + ")");
					 
					 
				 }
					 
				 
	}
	};
}
