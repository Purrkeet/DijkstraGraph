#include "Figura.h"

Punto::Punto()
{
	setPunto(0,0);
}
Punto::Punto(int x, int y)
{
	setPunto(x, y);
}
Punto::~Punto()
{}
void Punto::setPunto(int x, int y)
{
	this->x = x;
	this->y = y;
}





Linea::Linea(Punto* pInicio, Punto* pFinal)
{
	this->pInicio = pInicio;
	this->pFinal = pFinal;
}
Linea::~Linea()
{}
void Linea::mostrar(Graphics^ lienzo)
{
	Pen^ lapiz = gcnew Pen(Color::Black, 2);
	lienzo->DrawLine(lapiz, pInicio->x, pInicio->y, 
							pFinal->x, pFinal->y);
}





Circulo::Circulo(Punto* origen, int radio)
{
	this->origen = origen;
	punto = new Punto(origen->x - radio, origen->y - radio);
	this->diametro = 2*radio;
}
Circulo::~Circulo()
{}
void Circulo::mostrar(Graphics^ lienzo)
{
	SolidBrush^ pincel = gcnew SolidBrush(Color::Yellow);
	lienzo->FillEllipse(pincel, punto->x, punto->y, diametro, diametro);
}
bool Circulo::entroAlCirculo(int x, int y)
{
	if (punto->x < x && x < punto->x + diametro)
	{
		if (punto->y < y && y < punto->y + diametro)
		{
			return true;
		}
	}
	
	return false;
}



Simbolo::Simbolo(Punto* origen, int dato)
{
	this->origen = origen;
	this->dato = dato;
	tamanio = 8;
}
Simbolo::~Simbolo()
{}
void Simbolo::mostrarSimbolo(Graphics^ lienzo)
{
	Font^ fuente = gcnew Font("Times New Roman", tamanio*2);
	SolidBrush^ pincel = gcnew SolidBrush(Color::Blue);
	
	lienzo->DrawString(dato.ToString(), fuente, pincel, origen->x - tamanio, origen->y - tamanio);
}

