#include <stdio.h>

using namespace System::Drawing;


class Punto
{

public:
	int x;
	int y;

	Punto();
	Punto(int x, int y);
	~Punto();
	void setPunto(int x, int y);
};


class Linea
{
protected:
	Punto* pInicio;
	Punto* pFinal;
public:
	Linea(Punto* pInicio, Punto* pFinal);
	~Linea();
	void mostrar(Graphics^);
};



class Circulo
{
private:
	Punto* punto;
	Punto* pCentro;
	int diametro;
public:
	Circulo(Punto* pCentro, int radio);
	~Circulo();
	Punto* encontrarCentro(int x, int y);
	void mostrar(Graphics^);
};


class Signo
{
private:
	int simbolo;
public:
	Signo(int simbolo);
	~Signo();
	int getSimbolo();
	void setSimbolo(int simbolo);
};