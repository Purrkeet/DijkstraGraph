#include "Grafo.h"

Vertice::Vertice(Punto* origen, int dato)
{
	this->dato = dato;
	this->origen = origen;

	circulo = new Circulo(origen);
	simbolo = new Simbolo(origen, dato);
}
Vertice::~Vertice()
{}
Vertice* Vertice::entroAlVertice(int x, int y)
{
	if(circulo->entroAlCirculo(x, y))
		return this;
	return NULL;
}
void Vertice::mostrarVertice(Graphics^ lienzo)
{
	circulo->mostrar(lienzo);
	simbolo->mostrarSimbolo(lienzo);
}
Punto* Vertice::getOrigen()
{
	return origen;
}



Relacion::Relacion(Vertice* nodoOrigen, Vertice* nodoDestino)
{
	this->peso = 0;
	Punto* origen = nodoOrigen->getOrigen();
	Punto* destino = nodoDestino->getOrigen();
	linea = new Linea(origen, destino);
	
	simbolo = new Simbolo(new Punto((origen->x + destino->x) / 2,
									(origen->y + destino->y) / 2), peso);
}
Relacion::~Relacion()
{
}
void Relacion::mostrarRelacion(Graphics^ lienzo)
{
	linea->mostrar(lienzo);
	simbolo->mostrarSimbolo(lienzo);
}
void Relacion::setPeso(int peso)
{
	this->peso = peso;
}



Grafo::Grafo()
{
	grafo = Gf();
}
Grafo::~Grafo()
{}
void Grafo::agregarVertice(Vertice* nuevo)
{
	Nodo nodo = Nodo();
	nodo.first = nuevo;
	nodo.second = vector<Relacion*>();
	grafo.push_back(nodo);
}
void Grafo::agregarRelacion(Vertice* nodoOrigen, Vertice* nodoDestino)
{
	Relacion* arista = new Relacion(nodoOrigen, nodoDestino);
	Nodo nodo;
	
	grafo[nodoOrigen->dato - NUMERO_INICIO].second.push_back(arista);
}
void Grafo::mostrarGrafo(Graphics^ lienzo)
{
	Nodo nodo;
	for (int i = 0; i < grafo.size(); i++)
	{
		nodo = grafo[i];
		for (int j = 0; j < nodo.second.size(); j++)
		{
			nodo.second[j]->mostrarRelacion(lienzo);
		}			
	}
	for (int i = 0; i < grafo.size(); i++)
	{
		nodo = grafo[i];
		nodo.first->mostrarVertice(lienzo);
	}
}
Vertice* Grafo::encontrarVertice(int x, int y)
{
	Vertice* buscando = NULL;
	Nodo nodo;
	for (int i = 0; i < grafo.size(); i++)
	{
		nodo = grafo[i];
		buscando = nodo.first->entroAlVertice(x, y);
		if (buscando != NULL)
			return buscando;
	}

	return NULL;
}



GrafoFacade::GrafoFacade()
{
	datoInicial = NUMERO_INICIO;
	grafo = new Grafo();
	primero = NULL;
}
GrafoFacade::~GrafoFacade()
{}
void GrafoFacade::agregarVertice(int x, int y)
{
	Vertice* nuevo = new Vertice(new Punto(x, y), datoInicial);
	grafo->agregarVertice(nuevo);
	datoInicial++;
}
void GrafoFacade::agregarRelacion(int x, int y)
{
	Vertice* buscando = grafo->encontrarVertice(x, y);
	if (buscando != NULL)
	{
		if (primero == NULL) 
		{
			primero = buscando;
		}
		else if (buscando != primero)
		{
			grafo->agregarRelacion(primero, buscando);
			primero = NULL;
		}
	}	
}
void GrafoFacade::mostrarGrafo(Graphics^ lienzo)
{
	grafo->mostrarGrafo(lienzo);
}