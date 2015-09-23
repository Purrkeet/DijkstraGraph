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
	Pen^ lapiz = gcnew Pen(Color::Black);
	lienzo->DrawLine(lapiz, pInicio->x, pInicio->y, 
							pFinal->x, pFinal->y);
}





Circulo::Circulo(Punto* pCentro, int radio)
{
	this->pCentro = pCentro;
	punto = new Punto(pCentro->x - radio, pCentro->y - radio);
	this->diametro = 2*radio;
}
Circulo::~Circulo()
{}
void Circulo::mostrar(Graphics^ lienzo)
{
	SolidBrush^ pincel = gcnew SolidBrush(Color::Yellow);
	lienzo->FillEllipse(pincel, punto->x, punto->y, diametro, diametro);
}
Punto* Circulo::encontrarCentro(int x, int y)
{
	if (punto->x < x && x < punto->x + diametro)
	{
		if (punto->x < x && x < punto->x + diametro)
		{
			return pCentro;
		}
	}
	
	return NULL;
}




Signo::Signo(int simbolo)
{
	setSimbolo(simbolo);
}
Signo::~Signo()
{}
int Signo::getSimbolo()
{
	return simbolo;
}
void Signo::setSimbolo(int simbolo)
{
	this->simbolo = simbolo;
}