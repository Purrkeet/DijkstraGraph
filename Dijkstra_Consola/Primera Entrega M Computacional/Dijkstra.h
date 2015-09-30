//#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <functional>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;
typedef priority_queue<ii, vii, greater<ii> > pq;

#define  sf scanf
#define  INF 9999999 

class Dijkstra_
{
public:
	Dijkstra_(){}
	~Dijkstra_(){}

	string Resolver(bool Dirigido){
		string salida = "";
		freopen("in.txt", "r+t", stdin);

		//lectura de Nodos y Aristas


		sf("%d %d", &Nodos, &Aristas);
		//Inicializar el Grafo (arreglo de vectores de enteros)
		Grafo = vvii(Nodos);
		//lectura de las aristas
		for (int i = 0; i < Aristas; ++i)
		{
			int inicio, fin, peso;
			sf("%d %d %d", &inicio, &fin, &peso);
			//Grafo dirigido
			Grafo[inicio].push_back(ii(peso, fin));
			if (!Dirigido){
				Grafo[fin].push_back(ii(peso, inicio));
			}
		}
		//Leer las consultas de camino mas corto
		//Desde que nodo hasta que nodo
		int Desde, Hasta;
		while (sf("%d %d", &Desde, &Hasta) == 2){
			Dijkstra(Desde);
			//Una vez aplicado el algoritmo podemos consultar en tiempo O(1)
			//El camino mas corto

			if (Pesos[Hasta] == INF){
				salida = "No es posible llegar a: ";
				salida += to_string(Hasta+1);
				salida += " desde : ";
				salida += to_string(Desde+1);
				salida += ".\n";
			}
			else{
				salida += "La distancia más corta desde ";
				salida += to_string(Desde+1);
				salida += " hasta ";
				salida += to_string(Hasta+1);
				salida += " son: ";
				salida += to_string(Pesos[Hasta]);
				salida += " unidades."; 
				
				string camino = MostrarCamino(Desde, Hasta); //obtiene cantidad de caminos
				salida += (CantidadCaminos > 1) ? "\nLos caminos a seguir son : " : "\nEl camino a seguir es : ";
				salida += camino;
			}

		}


		return salida;
	}
	string MostrarCamino(int desde, int hasta){
		string salida = "";
		if (desde == hasta){
			CantidadCaminos++;
			salida += "\n";
			/*if (CantidadCaminos > 1)
				salida += "Otro camino: ";*/
			salida += to_string( desde+1);
			return salida;
		}
	
		for (int i = 0; i< Padres[hasta].size(); ++i){
			salida += MostrarCamino(desde, Padres[hasta][i]);
			salida += " - ";
			salida += to_string(hasta+1);
			
		}
		return salida;
	}

	void Dijkstra(int nodoInicial){
		Cola = pq();
		CantidadCaminos = 0;
		Pesos = vi(Nodos, INF); //Creamos un vector de pesos de nodos con valor infinito
		Padres = vvi(Nodos, vi(1, -1));
		Cola.push(ii(0, nodoInicial)); //El costo por estar en el inicio es 0
		Pesos[nodoInicial] = 0;
		while (!Cola.empty()){
			ii aristaActual = Cola.top(); Cola.pop();
			int NodoActual = aristaActual.second;
			int PesoActual = aristaActual.first;
			//buscamos en todas las aristas que estan adyacentes
			for (int i = 0; i < Grafo[NodoActual].size(); ++i)
			{
				ii aristaConsultada = Grafo[NodoActual][i];
				int NodoConsultado = aristaConsultada.second;
				int PesoAlNodoConsultado = aristaConsultada.first;
				//Si el peso desde el nodoActual + el peso hacia el nodo consultado es menor al peso guardado hacia el nodoConsultado
				//Entonces Relaja
				if (PesoActual + PesoAlNodoConsultado < Pesos[NodoConsultado]){
					Pesos[NodoConsultado] = PesoActual + PesoAlNodoConsultado;
					Padres[NodoConsultado] = vi(1, NodoActual);
					Cola.push(ii(Pesos[NodoConsultado], NodoConsultado));
				}
				else if (PesoActual + PesoAlNodoConsultado == Pesos[NodoConsultado]){
					Padres[NodoConsultado].push_back(NodoActual);
					Cola.push(ii(Pesos[NodoConsultado], NodoConsultado));
				}

			}


		}



	}
	//void Dijkstra(int nodoInicial){}
	//string MostrarCamino(int desde, int hasta);
	int Nodos, Aristas, CantidadCaminos;
	//string Resolver();
	vvii Grafo;
	pq Cola;
	vi Pesos;
	vvi Padres;
private:

};

