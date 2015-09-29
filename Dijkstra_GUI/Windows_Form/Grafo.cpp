#include "Grafo.h"

/*-----------------------------------*/
Grafo::Grafo()
{
	grafo = GrafoNodos();
}
Grafo::~Grafo()
{}
Nodo Grafo::getNodo(int nodo)
{
	return grafo[nodo];
}
void Grafo::insertarVertice(GVertice* nuevoVertice)
{	
	Nodo nodo = Nodo();
	nodo.first = nuevoVertice;
	nodo.second = Aristas();
	grafo.push_back(nodo);
}
void Grafo::insertarRelacion(GVertice* origen, GVertice* destino, int peso)
{
	if (origen != NULL && destino != NULL)
	{
		GArista* aristaOrigen = new GArista(origen->getCentro(), destino->getCentro(), peso);
		GArista* aristaDestino = new GArista(destino->getCentro(), origen->getCentro(), peso);

		int nodo;

		nodo = origen->getPrimero() - 1;
		grafo[nodo].second.push_back(aristaOrigen);
		nodo = destino->getPrimero() - 1;
		grafo[nodo].second.push_back(aristaDestino);
	}	
}
void Grafo::mostrarGrafo(Graphics^ lienzo)
{
	for (int i = 0; i < grafo.size(); i++)
	{
		grafo[i].first->mostrarVertice(lienzo);
	}
	for (int i = 0; i < grafo.size(); i++)
	{
		for (int j = 0; j < grafo[i].second.size(); j++)
			grafo[i].second[j]->mostrarArista(lienzo);
	}
}
int Grafo::encontrarVertice(int x, int y)
{
	GVertice* buscando = NULL;
	for (int i = 0; i < grafo.size(); i++)
	{
		buscando = grafo[i].first->entroAlVertice(x, y);
		if (buscando != NULL)
			return i;
	}
	return NO_EXISTE;
}
/*-----------------------------------*/
/*-----------------------------------*/
GrafoFacade::GrafoFacade()
{
	this->grafo = new Grafo();
	this->datoInicio = NUMERO_INICIO;
	
	this->selectVertice = NULL;
	this->selectFila = -1;
	this->tablaRelacion = NULL;	
	matrizAdy = Gi(MAX);	
}
GrafoFacade::~GrafoFacade()
{}
void GrafoFacade::insertarVertice(int x, int y)
{
	int nodo = grafo->encontrarVertice(x, y);	
	if (nodo == NO_EXISTE)
	{
		TPunto origen;
		origen.setPunto(x, y);
		GVertice* nuevoVertice = new GVertice(origen, datoInicio);
		grafo->insertarVertice(nuevoVertice);
		datoInicio++;
	}
}
void GrafoFacade::insertarRelacion(int x, int y)
{
	int nodo = grafo->encontrarVertice(x, y);

	if (nodo != NO_EXISTE)
	{
		GVertice* buscando = grafo->getNodo(nodo).first;
		if (selectVertice == NULL)
		{
			selectVertice = buscando;
		}
		else if (selectVertice != buscando)
		{
			grafo->insertarRelacion(selectVertice, buscando, 0);
			int u = selectVertice->getPrimero() - 1;
			int v = buscando->getPrimero() - 1;

			matrizAdy[u].push_back(ii(v, 0));
			matrizAdy[v].push_back(ii(u, 0));			

			selectVertice = NULL;
		}
	}	
}
void GrafoFacade::mostrarGrafo(Graphics^ lienzo)
{
	grafo->mostrarGrafo(lienzo);
}
void GrafoFacade::exportarMatriadyacencia()
{}
void GrafoFacade::cambiarPesoRelacion(int peso)
{
	if (selectFila != NO_EXISTE)
	{
		ii nodo = tablaRelacion->getFila(selectFila)->getNodoDatos();
		int u = nodo.first - 1;
		int v = nodo.second - 1;
		int indice = 0;
		
		
		for (int i = 0; i < matrizAdy[v].size(); i++)
		{
			if (matrizAdy[v][i].first == u)
			{
				indice = i;
				break;
			}
		}
		matrizAdy[u][selectFila].second = peso;
		matrizAdy[v][indice].second = peso;
		
		grafo->getNodo(u).second[selectFila]->setPeso(peso);
		grafo->getNodo(v).second[indice]->setPeso(peso);

		tablaRelacion->getFila(selectFila)->setPeso(peso);
	}
}
void GrafoFacade::encontrarFilaTablaRelacion(int x, int y)
{
	if (tablaRelacion != NULL)
	{
		int posicion = tablaRelacion->encontrarFila(x, y);
		if (posicion != NO_EXISTE)
		{
			if (selectFila != NO_EXISTE)
			{
				tablaRelacion->getFila(selectFila)->setEstado(false);
			}
			selectFila = posicion;
			tablaRelacion->getFila(selectFila)->setEstado(true);
		}
	}
	
}
void GrafoFacade::visualizarRelacionesNodo(int x, int y)
{
	int nodo = grafo->encontrarVertice(x, y);
	if (nodo != NO_EXISTE)
	{
		if (selectFila != NO_EXISTE)
		{
			tablaRelacion->getFila(selectFila)->setEstado(false);
			selectFila = NO_EXISTE;
		}		
		
		TPunto auxiliar;
		auxiliar.setPunto(LADO, LADO);
		tablaRelacion = new TablaRelacion(matrizAdy, nodo, auxiliar);
	}
}
void GrafoFacade::mostrarTablaRelacion(Graphics^ lienzo)
{
	if (tablaRelacion != NULL)
	{
		tablaRelacion->mostrarTablaRelacion(lienzo);
		if (selectFila != NO_EXISTE)
			tablaRelacion->getFila(selectFila)->mostrarBloqueRelacion(lienzo);
	}
}
/*-----------------------------------*/
/*-----------------------------------*/
TablaRelacion::TablaRelacion(Gi grafo, int nodo, TPunto origen)
{
	this->origen = origen;
	this->tabla = TABLA();

	inicializarTablaRelacion(grafo, nodo);
}
void TablaRelacion::inicializarTablaRelacion(Gi grafo, int nodo)
{
	TPunto auxiliar;
	int u, v, w;
	u = nodo + 1;
	int acumulado = origen.y;
	for (int i = 0; i < grafo[nodo].size(); i++)
	{
		v = grafo[nodo][i].first + 1;
		w = grafo[nodo][i].second;
		auxiliar.setPunto(origen.x, acumulado);
		FILA fila = new BloqueRelacion(auxiliar, u, v, w);
		tabla.push_back(fila);
		acumulado += LADO;
	}
	auxiliar.setPunto(origen.x + 3 * LADO, acumulado);
	this->destino = auxiliar;
}
TablaRelacion::~TablaRelacion()
{}
FILA TablaRelacion::getFila(int posicion)
{
	return tabla[posicion];
}
int TablaRelacion::encontrarFila(int x, int y)
{
	if (origen.x < x && x < destino.x)
	{
		if (origen.y < y && y < destino.y)
			return (y - origen.y) / LADO;
	}	
	return NO_EXISTE;
}
void TablaRelacion::mostrarTablaRelacion(Graphics^ lienzo)
{
	for (int i = 0; i < tabla.size(); i++)
	{
		tabla[i]->mostrarBloqueRelacion(lienzo);
	}
}
