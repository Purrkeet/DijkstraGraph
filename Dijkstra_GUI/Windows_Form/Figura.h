#include <iostream>
#include <math.h>

#define RADIO 15
#define LADO 30
#define TAMANIO 10

using namespace System::Drawing;
using namespace std;

struct TPunto
{
	float x, y;
	void setPunto(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};
/*-----------------------------------*/
class Simbolo
{
private:
	TPunto origen;
	int signo;
	int tamanio;
public:
	Simbolo(TPunto origen, int signo);
	~Simbolo();
	int getSigno();
	void setSigno(int signo);
	void mostrarSimbolo(Graphics^);
};
/*-----------------------------------*/
class Circulo
{
protected:
	TPunto origen;
	TPunto centro;
	float diametro;
public:
	Circulo(TPunto centro, int radio);
	~Circulo();
	TPunto getCentro();
	bool entroAlCirculo(int x, int y);
	void mostrarCirculo(Graphics^);
};

class CirculoRelacion : public Circulo
{
public:
	CirculoRelacion(TPunto centro, int radio);
	~CirculoRelacion();
	void mostrarCirculo(Graphics^ lienzo);
};
/*-----------------------------------*/
class LineaDireccional
{
private:
	static const int radio = 5;
	TPunto origen;
	TPunto destino;
	CirculoRelacion* unidireccion;
public:
	LineaDireccional(TPunto origen, TPunto destino);
	~LineaDireccional();
	void mostrarLineaDireccional(Graphics^);
};
/*-----------------------------------*/
class GVertice
{
private:
	Circulo* circulo;
	Simbolo* simbolo;
	int primero;

public:
	GVertice(TPunto origen, int primero);
	~GVertice();
	TPunto getCentro();
	int getPrimero();
	GVertice* entroAlVertice(int x, int y);
	void mostrarVertice(Graphics^ lienzo);
};

class GArista
{
private:
	LineaDireccional* linea;
	Simbolo* simbolo;
	bool estado;
	void inicializarSimbolo(TPunto origen, TPunto destino, int peso);
	void inicializarLineaDireccional(TPunto origen, TPunto destino);
public:
	GArista(TPunto origen, TPunto destino, int peso);
	~GArista();
	void setPeso(int peso);
	void setEstado(bool estado);
	void mostrarArista(Graphics^ lienzo);
};

typedef pair<int, int> ii;

class BloqueRelacion
{
private:
	TPunto origen;
	bool estado;
	float ancho, alto;
	ii nodo;
	int peso;
public:
	BloqueRelacion(TPunto origen, int u, int v, int w);
	~BloqueRelacion();
	ii getNodoDatos();
	void setEstado(bool estado);
	void setPeso(int peso);
	bool entroAlBloque(int x, int y);
	void mostrarBloqueRelacion(Graphics^ lienzo);
};