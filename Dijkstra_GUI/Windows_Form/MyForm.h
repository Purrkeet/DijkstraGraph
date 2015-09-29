#pragma once
#include "Grafo.h"

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
		int x, y, xS, yS;
		GrafoFacade* grafo;

	private: System::Windows::Forms::Button^  btnResolver;
	private: System::Windows::Forms::Button^  btnSalir;
	private: System::Windows::Forms::Button^  btnActualizar;

	private: System::Windows::Forms::Panel^  panelSecundario;
	private: System::Windows::Forms::RadioButton^  rbAgregar;
	private: System::Windows::Forms::TextBox^  tbPeso;
	private: System::Windows::Forms::RadioButton^  radioButton2;

	public:
		MyForm(void)
		{
			InitializeComponent();
			x = y = xS = yS = 0;
			grafo = new GrafoFacade();
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
			this->btnResolver = (gcnew System::Windows::Forms::Button());
			this->btnSalir = (gcnew System::Windows::Forms::Button());
			this->btnActualizar = (gcnew System::Windows::Forms::Button());
			this->panelSecundario = (gcnew System::Windows::Forms::Panel());
			this->rbAgregar = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->tbPeso = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// ciclo
			// 
			this->ciclo->Enabled = true;
			this->ciclo->Tick += gcnew System::EventHandler(this, &MyForm::ciclo_Tick);
			// 
			// panelPrincipal
			// 
			this->panelPrincipal->BackColor = System::Drawing::Color::White;
			this->panelPrincipal->Location = System::Drawing::Point(0, 0);
			this->panelPrincipal->Name = L"panelPrincipal";
			this->panelPrincipal->Size = System::Drawing::Size(500, 400);
			this->panelPrincipal->TabIndex = 0;
			this->panelPrincipal->DoubleClick += gcnew System::EventHandler(this, &MyForm::panelPrincipal_DoubleClick);
			this->panelPrincipal->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panelPrincipal_MouseClick);
			this->panelPrincipal->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panelPrincipal_MouseMove);
			// 
			// btnResolver
			// 
			this->btnResolver->BackColor = System::Drawing::Color::White;
			this->btnResolver->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnResolver->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnResolver->Location = System::Drawing::Point(589, 428);
			this->btnResolver->Name = L"btnResolver";
			this->btnResolver->Size = System::Drawing::Size(85, 23);
			this->btnResolver->TabIndex = 2;
			this->btnResolver->Text = L"Resolver";
			this->btnResolver->UseVisualStyleBackColor = false;
			this->btnResolver->Click += gcnew System::EventHandler(this, &MyForm::btnResolver_Click);
			// 
			// btnSalir
			// 
			this->btnSalir->BackColor = System::Drawing::Color::White;
			this->btnSalir->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSalir->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSalir->Location = System::Drawing::Point(5, 427);
			this->btnSalir->Name = L"btnSalir";
			this->btnSalir->Size = System::Drawing::Size(85, 23);
			this->btnSalir->TabIndex = 3;
			this->btnSalir->Text = L"Salir";
			this->btnSalir->UseVisualStyleBackColor = false;
			this->btnSalir->Click += gcnew System::EventHandler(this, &MyForm::btnSalir_Click);
			// 
			// btnActualizar
			// 
			this->btnActualizar->BackColor = System::Drawing::Color::White;
			this->btnActualizar->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnActualizar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnActualizar->Location = System::Drawing::Point(498, 428);
			this->btnActualizar->Name = L"btnActualizar";
			this->btnActualizar->Size = System::Drawing::Size(85, 23);
			this->btnActualizar->TabIndex = 4;
			this->btnActualizar->Text = L"Actualizar";
			this->btnActualizar->UseVisualStyleBackColor = false;
			this->btnActualizar->Click += gcnew System::EventHandler(this, &MyForm::btnActualizar_Click);
			// 
			// panelSecundario
			// 
			this->panelSecundario->BackColor = System::Drawing::Color::White;
			this->panelSecundario->Location = System::Drawing::Point(506, 0);
			this->panelSecundario->Name = L"panelSecundario";
			this->panelSecundario->Size = System::Drawing::Size(150, 400);
			this->panelSecundario->TabIndex = 5;
			this->panelSecundario->Click += gcnew System::EventHandler(this, &MyForm::panelSecundario_Click);
			this->panelSecundario->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panelSecundario_MouseMove);
			// 
			// rbAgregar
			// 
			this->rbAgregar->AutoSize = true;
			this->rbAgregar->Checked = true;
			this->rbAgregar->Location = System::Drawing::Point(176, 407);
			this->rbAgregar->Name = L"rbAgregar";
			this->rbAgregar->Size = System::Drawing::Size(62, 17);
			this->rbAgregar->TabIndex = 6;
			this->rbAgregar->TabStop = true;
			this->rbAgregar->Text = L"Agregar";
			this->rbAgregar->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(176, 427);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(69, 17);
			this->radioButton2->TabIndex = 7;
			this->radioButton2->Text = L"Visualizar";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// tbPeso
			// 
			this->tbPeso->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tbPeso->Location = System::Drawing::Point(382, 430);
			this->tbPeso->Name = L"tbPeso";
			this->tbPeso->Size = System::Drawing::Size(110, 20);
			this->tbPeso->TabIndex = 8;
			this->tbPeso->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::tbPeso_KeyPress);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ClientSize = System::Drawing::Size(684, 462);
			this->Controls->Add(this->tbPeso);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->rbAgregar);
			this->Controls->Add(this->panelSecundario);
			this->Controls->Add(this->btnActualizar);
			this->Controls->Add(this->btnSalir);
			this->Controls->Add(this->btnResolver);
			this->Controls->Add(this->panelPrincipal);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Algoritmo de Dijkstra";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
		private: System::Void ciclo_Tick(System::Object^  sender, System::EventArgs^  e) {
				Graphics^ lienzo = this->panelPrincipal->CreateGraphics();
				Graphics^ canvas = this->panelSecundario->CreateGraphics();

				float lAncho = lienzo->VisibleClipBounds.Width;
				float lAlto = lienzo->VisibleClipBounds.Height;

				BufferedGraphicsContext^ espacioBuffered = BufferedGraphicsManager::Current;
				espacioBuffered->MaximumBuffer = System::Drawing::Size(lAncho + 1.0, lAlto + 1.0);
				BufferedGraphics^ lienzoBuffer = espacioBuffered->Allocate(lienzo, Drawing::Rectangle(0.0, 0.0, lAncho, lAlto));
				
				lAncho = canvas->VisibleClipBounds.Width;
				lAlto = canvas->VisibleClipBounds.Height;

				BufferedGraphicsContext^ espacioCanvas = BufferedGraphicsManager::Current;
				espacioCanvas->MaximumBuffer = System::Drawing::Size(lAncho + 1.0, lAlto + 1.0);
				BufferedGraphics^ canvasBuffer = espacioBuffered->Allocate(canvas, Drawing::Rectangle(0.0, 0.0, lAncho, lAlto));

				lienzoBuffer->Graphics->Clear(Color::White);
				canvasBuffer->Graphics->Clear(Color::White);
				
				grafo->mostrarGrafo(lienzoBuffer->Graphics);
				grafo->mostrarTablaRelacion(canvasBuffer->Graphics);

				lienzoBuffer->Render(lienzo);
				canvasBuffer->Render(canvas);

				delete lienzoBuffer;
				delete lienzo;

				delete canvasBuffer;
				delete canvas;
		}
	private: System::Void panelPrincipal_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 x = e->Location.X;
				 y = e->Location.Y;
				 
	}
	private: System::Void panelPrincipal_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 
				 if (e->Button == System::Windows::Forms::MouseButtons::Left)
				 {
					 if (this->rbAgregar->Checked)
					 {
						 grafo->insertarVertice(x, y);
					 }
					 else
					 {
						 grafo->visualizarRelacionesNodo(x, y);
					 }
				 }					 
				 else if (e->Button == System::Windows::Forms::MouseButtons::Right) 
				 {
					 grafo->insertarRelacion(x, y);
				 }
					 
				 
	}
	private: System::Void panelPrincipal_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
				 if (!this->rbAgregar->Checked)
					MessageBox::Show("Se esta generando el algoritmo de dijkstra.");
	}
private: System::Void btnResolver_Click(System::Object^  sender, System::EventArgs^  e) {
			 grafo->exportarMatriadyacencia();
}
private: System::Void btnSalir_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->Close();
}
private: System::Void panelSecundario_Click(System::Object^  sender, System::EventArgs^  e) {
			 grafo->encontrarFilaTablaRelacion(xS, yS);
			 tbPeso->Focus();
}
private: System::Void panelSecundario_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 xS = e->Location.X;
			 yS = e->Location.Y;
}
private: System::Void tbPeso_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
			 if (('1' > e->KeyChar || e->KeyChar > '9') && e->KeyChar != 8)
				 e->KeyChar = 0;
}
private: System::Void btnActualizar_Click(System::Object^  sender, System::EventArgs^  e) {
			 if (tbPeso->Text->Length > 0)
			 {
				 grafo->cambiarPesoRelacion(Int32::Parse(this->tbPeso->Text));
				 tbPeso->Clear();
			 }			 
}
};
}
