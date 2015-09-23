#include "Dijkstra.h"
//#pragma once
//#include "Dijkstra.h"
namespace PrimeraEntregaMComputacional {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de principal
	/// </summary>
	public ref class principal : public System::Windows::Forms::Form
	{
	public:
		principal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~principal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  NodoOrigen;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  NodoDestino;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Peso;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::RadioButton^  rbNoDirigido;
	private: System::Windows::Forms::RadioButton^  rbDirigido;

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->rbNoDirigido = (gcnew System::Windows::Forms::RadioButton());
			this->rbDirigido = (gcnew System::Windows::Forms::RadioButton());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->NodoOrigen = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->NodoDestino = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Peso = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->groupBox4);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(12, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(359, 214);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Definiendo el grafo";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &principal::groupBox1_Enter);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->rbNoDirigido);
			this->groupBox4->Controls->Add(this->rbDirigido);
			this->groupBox4->Location = System::Drawing::Point(11, 129);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(342, 68);
			this->groupBox4->TabIndex = 8;
			this->groupBox4->TabStop = false;
			// 
			// rbNoDirigido
			// 
			this->rbNoDirigido->AutoSize = true;
			this->rbNoDirigido->Location = System::Drawing::Point(192, 28);
			this->rbNoDirigido->Name = L"rbNoDirigido";
			this->rbNoDirigido->Size = System::Drawing::Size(122, 28);
			this->rbNoDirigido->TabIndex = 1;
			this->rbNoDirigido->Text = L"No Dirigido";
			this->rbNoDirigido->UseVisualStyleBackColor = true;
			// 
			// rbDirigido
			// 
			this->rbDirigido->AutoSize = true;
			this->rbDirigido->Checked = true;
			this->rbDirigido->Location = System::Drawing::Point(19, 28);
			this->rbDirigido->Name = L"rbDirigido";
			this->rbDirigido->Size = System::Drawing::Size(92, 28);
			this->rbDirigido->TabIndex = 0;
			this->rbDirigido->TabStop = true;
			this->rbDirigido->Text = L"Dirigido";
			this->rbDirigido->UseVisualStyleBackColor = true;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(180, 89);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(101, 29);
			this->textBox2->TabIndex = 7;
			this->textBox2->Text = L"0";
			this->textBox2->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &principal::ValidarSoloNumero);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(287, 86);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(38, 37);
			this->button3->TabIndex = 6;
			this->button3->Text = L"+";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &principal::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(136, 86);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(38, 37);
			this->button4->TabIndex = 5;
			this->button4->Text = L"-";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &principal::button4_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 92);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 24);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Aristas :";
			// 
			// textBox1
			// 
			this->textBox1->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->textBox1->Location = System::Drawing::Point(180, 33);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(101, 29);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"0";
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &principal::ValidarSoloNumero);
			this->textBox1->Leave += gcnew System::EventHandler(this, &principal::textBox1_Leave);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(287, 30);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(38, 37);
			this->button2->TabIndex = 2;
			this->button2->Text = L"+";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &principal::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(136, 30);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(38, 37);
			this->button1->TabIndex = 1;
			this->button1->Text = L"-";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &principal::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Nodos :";
			// 
			// groupBox2
			// 
			this->groupBox2->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox2->Controls->Add(this->panel1);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(17, 244);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(365, 385);
			this->groupBox2->TabIndex = 1;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Ingreso de datos";
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->panel1->AutoSize = true;
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(6, 28);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(353, 293);
			this->panel1->TabIndex = 4;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCellsExceptHeaders;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->NodoOrigen,
					this->NodoDestino, this->Peso
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(353, 293);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->EditingControlShowing += gcnew System::Windows::Forms::DataGridViewEditingControlShowingEventHandler(this, &principal::dataGridView1_EditingControlShowing);
			// 
			// NodoOrigen
			// 
			this->NodoOrigen->Frozen = true;
			this->NodoOrigen->HeaderText = L"Nodo Origen";
			this->NodoOrigen->Name = L"NodoOrigen";
			// 
			// NodoDestino
			// 
			this->NodoDestino->Frozen = true;
			this->NodoDestino->HeaderText = L"Nodo Destino";
			this->NodoDestino->Name = L"NodoDestino";
			// 
			// Peso
			// 
			this->Peso->Frozen = true;
			this->Peso->HeaderText = L"Distancia o Peso";
			this->Peso->Name = L"Peso";
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button5->Location = System::Drawing::Point(333, 46);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(160, 70);
			this->button5->TabIndex = 1;
			this->button5->Text = L"&Resolver";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &principal::button5_Click);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Control;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Dock = System::Windows::Forms::DockStyle::Top;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(0, 0);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(909, 22);
			this->textBox3->TabIndex = 3;
			this->textBox3->Text = L"Resolución del Problema de Ruta Mínima Usando el Algoritmo de Dijkstra";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->richTextBox1);
			this->groupBox3->Controls->Add(this->comboBox2);
			this->groupBox3->Controls->Add(this->button5);
			this->groupBox3->Controls->Add(this->comboBox1);
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->label3);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox3->Location = System::Drawing::Point(377, 24);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(520, 527);
			this->groupBox3->TabIndex = 4;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Consulta al Grafo";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(11, 146);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(503, 375);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->Text = L"La ruta mas corta hallada desde xxx hasta xxx es:";
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(184, 84);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 32);
			this->comboBox2->TabIndex = 3;
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(184, 46);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 32);
			this->comboBox1->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(113, 88);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(64, 24);
			this->label4->TabIndex = 1;
			this->label4->Text = L"hasta :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 49);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(152, 24);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Resolver desde :";
			// 
			// principal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(909, 641);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->KeyPreview = true;
			this->Name = L"principal";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dijkstra - Matemática Computacional";
			this->Load += gcnew System::EventHandler(this, &principal::principal_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void principal_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void ValidarSoloNumero(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
	
	if (!((e->KeyChar >= '0'  &&e->KeyChar <= '9') || e->KeyChar == 8 || e->KeyChar == 127)){
		e->Handled = true;
	}
	
		
}
		 bool Suma(System::Windows::Forms::TextBox^ tb, bool suma){
			 if (suma){
				 tb->Text = Convert::ToString(Convert::ToInt32(tb->Text) + 1);
			 }
			 else{
				 int nuevo_numero = Convert::ToInt32(tb->Text) - 1;
				 if (nuevo_numero < 0) return false; // si no se pueden borrar mas retorna falso
				 tb->Text = Convert::ToString( nuevo_numero);
			 }
			 return true;
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//String ^numero = textBox1->Text;
	//int num = Convert::ToInt32(numero)+1;
	//textBox1->Text = Convert::ToString(Convert::ToInt32(textBox1->Text) + 1);
	Suma(textBox1, true);
	if (Convert::ToInt32(textBox1->Text) >= 2){
		llenarCombos(Convert::ToInt32(textBox1->Text));
	}
	
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	
	//agregar filas a la tabla
		//si no hay por lo menos 2 nodos, no se pueden agregar aristas
	if (Convert::ToInt32(textBox1->Text) >= 2){
		Suma(textBox2, true);
		dataGridView1->Rows->Add();
	}
		
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Suma(textBox1, false);
	if (Convert::ToInt32(textBox1->Text) < 2){
		dataGridView1->Rows->Clear();
		textBox2->Text = "0";
	}
		
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	bool hayFilas = Suma(textBox2, false);
	//eliminar filas
	if (hayFilas){
		dataGridView1->Rows->RemoveAt(dataGridView1->Rows->Count - 1);
	}
}
	private: System::Void Celda_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^  e)
{
	if (!((e->KeyChar >= '0'  &&e->KeyChar <= '9') || e->KeyChar == 8 || e->KeyChar == 127)){
		e->Handled = true;
	}
}
	void validarCeldas(){
		int nodos = Convert::ToInt32(textBox1->Text);
		for (int i = 0; i < dataGridView1->RowCount; ++i){
			int u =Convert::ToInt32(dataGridView1->Rows[i]->Cells["NodoOrigen"]->Value);
			if (u >= nodos){
				dataGridView1->Rows[i]->Cells["NodoOrigen"]->Value = "0";
				MessageBox::Show("Solo se admiten valores de 0 a "+(nodos-1));
			}
			int v =Convert::ToInt32(dataGridView1->Rows[i]->Cells["NodoDestino"]->Value);
			if (v >= nodos){
				
				dataGridView1->Rows[i]->Cells["NodoDestino"]->Value = "0";
				MessageBox::Show("Solo se admiten valores de 0 a " + (nodos - 1));
			}
		}
				 
	}
	private: System::Void Celda_TextChanged(System::Object^ sender, System::EventArgs^ e)//System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		validarCeldas();
	}
			 void llenarCombos(int hasta){
				 comboBox1->Items->Clear(); comboBox2->Items->Clear();

				 for (int i = 0; i < hasta; i++)
				 {
					 comboBox1->Items->Add(i);
					 comboBox2->Items->Add(i);
				 }
				 
			 }
private: System::Void dataGridView1_EditingControlShowing(System::Object^  sender, System::Windows::Forms::DataGridViewEditingControlShowingEventArgs^  e) {
	//e->Control->KeyPress += Celda_KeyPress(sender, e);
	e->Control->KeyPress += gcnew KeyPressEventHandler(this, &principal::Celda_KeyPress);
	e->Control->Leave += gcnew EventHandler(this, &principal::Celda_TextChanged);
}
private: System::Void textBox1_Leave(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	if (comboBox1->SelectedIndex >-1 && comboBox2->SelectedIndex > -1){
		
		//guardar archivo texto plano con datos
		FILE * archivo = fopen("in.txt","w+t");
		//freopen("in.txt", "w+t", stdout);
		fprintf(archivo,"%d %d\n", Convert::ToInt32(textBox1->Text), Convert::ToInt32(textBox2->Text));
		for (int i = 0; i < dataGridView1->Rows->Count; i++)
		{
			
			int u = Convert::ToInt32(dataGridView1->Rows[i]->Cells["NodoOrigen"]->Value);
			int v = Convert::ToInt32(dataGridView1->Rows[i]->Cells["NodoDestino"]->Value);
			int w = Convert::ToInt32(dataGridView1->Rows[i]->Cells["Peso"]->Value);
			fprintf(archivo, "%d %d %d\n", u, v, w);
		}
		int q1 = comboBox1->SelectedIndex, q2 = comboBox2->SelectedIndex;
		fprintf(archivo, "%d %d", q1, q2);
		fclose(archivo);
		//aplicar algoritmo
		Dijkstra_ * Dijks = new Dijkstra_();
		bool esDirigido = false;
		if (rbDirigido->Checked) esDirigido = true;
		String ^resultado = gcnew String(Dijks->Resolver(esDirigido).c_str());
		richTextBox1->Text = resultado;
	

	}


}
};
}
