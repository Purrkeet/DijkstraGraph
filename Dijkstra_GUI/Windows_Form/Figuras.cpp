#include "Figuras.h"

Circulos::Circulos()
{
	circulos = vector<Circulo*>(); 
}
Circulos::~Circulos()
{
	circulos.clear();
}
void Circulos::agregar(int x, int y, int radio)
{
	Punto* pCentro = new Punto(x, y);
	Circulo* circulo = new Circulo(pCentro, radio);
	circulos.push_back(circulo);
}
void Circulos::mostrar(Graphics^ lienzo)
{
	for (int i = 0; i < circulos.size(); i++)
	{
		circulos[i]->mostrar(lienzo);
	}
}
Punto* Circulos::encontrarCirculo(int x, int y)
{
	Punto* temporal;
	for (int i = 0; i < circulos.size(); i++)
	{
		temporal = circulos[i]->encontrarCentro(x, y);
		if (temporal != NULL) 
		{
			return temporal;
		}
	}
	return NULL;
}





Relaciones::Relaciones()
{
	relaciones = vector<Linea*>();
}
Relaciones::~Relaciones()
{}
void Relaciones::agregar(int xI, int yI, int xF, int yF)
{
	Punto* pInicio = new Punto(xI, yI);
	Punto* pFinal = new Punto(xF, yF);
	Linea* linea = new Linea(pInicio, pFinal);
	relaciones.push_back(linea);
}
void Relaciones::mostrar(Graphics^ lienzo)
{
	for (int i = 0; i < relaciones.size(); i++)
	{
		relaciones[i]->mostrar(lienzo);
	}
}