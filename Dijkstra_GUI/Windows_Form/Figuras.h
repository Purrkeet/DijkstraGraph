
#include <vector>
#include "Figura.h"

using namespace std;

class Circulos
{
private:
	vector<Circulo*> circulos;

public:
	Circulos();
	~Circulos();
	void agregar(int x, int y, int radio);
	void mostrar(Graphics^);
	Punto* encontrarCirculo(int x, int y);
};

class Relaciones
{
private:
	vector<Linea*> relaciones;
public:
	Relaciones();
	~Relaciones();
	void agregar(int xI, int yI, int xF, int yF);
	void mostrar(Graphics^);
};