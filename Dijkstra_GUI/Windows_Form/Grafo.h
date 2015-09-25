#include "Figura.h"
#include <vector>

using namespace std;

static const int NUMERO_INICIO = 1;
static const char LETRA_INICIO = 'A';

class Vertice
{
private:
	Punto* origen;
	Circulo* circulo;
	Simbolo* simbolo;
public:
	int dato;
	Vertice(Punto* origen, int dato);
	~Vertice();
	Punto* getOrigen();
	Vertice* entroAlVertice(int x, int y);
	void mostrarVertice(Graphics^);
};

class Relacion
{
private:
	Linea* linea;
	Simbolo* simbolo;
	bool bidireccional;
	int peso;
public:
	Relacion(Vertice*, Vertice*);
	~Relacion();
	void mostrarRelacion(Graphics^);
	void setPeso(int peso);
};

typedef pair<Vertice*, vector<Relacion*>> Nodo;
typedef vector<Nodo> Gf;

class Grafo
{
private:
	char caracter;
	Gf grafo;

	void buscarVertice(Punto* origen);
public:
	Grafo();
	~Grafo();
	void agregarVertice(Vertice* nuevo);
	void agregarRelacion(Vertice* nodoOrigen, Vertice* nodoDestino);
	void mostrarGrafo(Graphics^);
	Vertice* encontrarVertice(int x, int y);
};

class GrafoFacade
{
private:
	Grafo* grafo;
	Vertice* primero;
	int datoInicial;
public:
	GrafoFacade();
	~GrafoFacade();
	void agregarVertice(int x, int y);
	void agregarRelacion(int x, int y);
	void mostrarGrafo(Graphics^);
};