#include "Figura.h"
#include <fstream>
#include <vector>

using namespace std;

#define NO_EXISTE -1
#define MAX 50

static const int NUMERO_INICIO = 1;
static const char LETRA_INICIO = 'A';


typedef vector<GArista*> Aristas;
typedef pair<GVertice*, Aristas> Nodo;
typedef vector<Nodo> GrafoNodos;
typedef BloqueRelacion* FILA;
typedef vector<FILA> TABLA;

typedef pair<int, int> ii;
typedef vector<ii> Vi;
typedef vector<Vi> Gi;

/*-----------------------------------*/
class Grafo
{
private:
	char caracter;
	GrafoNodos grafo;
public:
	Grafo();
	~Grafo();
	Nodo getNodo(int nodo);
	void cambiarPesoRelacion(int peso);
	void insertarVertice(GVertice* nuevoVertice);
	void insertarRelacion(GVertice* origen, GVertice* destino, int peso);
	void mostrarGrafo(Graphics^ lienzo);
	int encontrarVertice(int x, int y);
};
/*-----------------------------------*/
class TablaRelacion;
/*-----------------------------------*/
class GrafoFacade
{
private:
	Gi matrizAdy;
	Grafo* grafo;
	GVertice* selectVertice;
	int selectFila;
	TablaRelacion* tablaRelacion;
	int datoInicio;

	void inicializarMatrizAdyacencia();
public:
	GrafoFacade();
	~GrafoFacade();

	void setBidireccional(bool bidireccional);
	void insertarVertice(int x, int y);
	void insertarRelacion(int x, int y);
	void mostrarGrafo(Graphics^);

	void exportarMatriadyacencia();

	void cambiarPesoRelacion(int peso);
	void encontrarFilaTablaRelacion(int x, int y);
	void visualizarRelacionesNodo(int x, int y);
	void mostrarTablaRelacion(Graphics^ lienzo);
	
};
/*-----------------------------------*/
class TablaRelacion
{
private:
	TABLA tabla;
	TPunto origen;
	TPunto destino;

	void inicializarTablaRelacion(Gi grafo, int nodo);
public:
	TablaRelacion(Gi grafo, int nodo, TPunto origen);
	~TablaRelacion();
	FILA getFila(int posicion);
	int encontrarFila(int x, int y);
	void mostrarTablaRelacion(Graphics^ lienzo);
};