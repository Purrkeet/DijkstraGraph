
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
	Punto* origen;
	int diametro;
public:
	Circulo(Punto* origen, int radio = 15);
	~Circulo();
	bool entroAlCirculo(int x, int y);
	void mostrar(Graphics^);
};

class Simbolo
{
private:
	int dato;
	int tamanio;
	Punto* origen;
public:
	Simbolo(Punto* origen, int dato);
	~Simbolo();
	void mostrarSimbolo(Graphics^);
};