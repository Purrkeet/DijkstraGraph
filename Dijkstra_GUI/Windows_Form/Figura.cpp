#include "Figura.h"

/*-----------------------------------*/
/*-----------------------------------*/
Simbolo::Simbolo(TPunto origen, int signo)
{
	this->origen = origen;
	this->signo = signo;
	this->tamanio = TAMANIO;
}
Simbolo::~Simbolo()
{}
int Simbolo::getSigno()
{
	return signo;
}
void Simbolo::setSigno(int signo)
{
	this->signo = signo;
}
void Simbolo::mostrarSimbolo(Graphics^ lienzo)
{
	Font^ fuente = gcnew Font("Times New Roman", tamanio * 2);
	SolidBrush^ pincel = gcnew SolidBrush(Color::Blue);

	lienzo->DrawString(signo.ToString(), fuente, pincel,
		origen.x, origen.y);
}
/*-----------------------------------*/
/*-----------------------------------*/
Circulo::Circulo(TPunto centro, int radio)
{
	this->centro = centro;
	this->diametro = 2 * radio;

	this->origen.x = centro.x - radio;
	this->origen.y = centro.y - radio;
}
Circulo::~Circulo()
{}
TPunto Circulo::getCentro()
{
	return centro;
}
bool Circulo::entroAlCirculo(int x, int y)
{
	if (origen.x < x && x < origen.x + diametro)
	{
		if (origen.y < y && y < origen.y + diametro)
		{
			return true;
		}
	}
	return false;
}
void Circulo::mostrarCirculo(Graphics^ lienzo)
{
	SolidBrush^ pincel = gcnew SolidBrush(Color::Yellow);
	lienzo->FillEllipse(pincel, origen.x, origen.y, diametro, diametro);
}
/*-----------------------------------*/
/*-----------------------------------*/
CirculoRelacion::CirculoRelacion(TPunto centro, int radio) : Circulo(centro, radio)
{}
CirculoRelacion::~CirculoRelacion()
{}
void CirculoRelacion::mostrarCirculo(Graphics^ lienzo)
{
	SolidBrush^ pincel = gcnew SolidBrush(Color::Brown);
	lienzo->FillEllipse(pincel, origen.x, origen.y, diametro, diametro);
}
/*-----------------------------------*/
/*-----------------------------------*/
LineaDireccional::LineaDireccional(TPunto origen, TPunto destino)
{
	this->origen = origen;
	this->destino = destino;
	this->unidireccion = new CirculoRelacion(destino, radio);
}
LineaDireccional::~LineaDireccional()
{}
void LineaDireccional::mostrarLineaDireccional(Graphics^ lienzo)
{
	Pen^ lapiz = gcnew Pen(Color::Black, 2);
	lienzo->DrawLine(lapiz, origen.x, origen.y,
		destino.x, destino.y);
	unidireccion->mostrarCirculo(lienzo);
}
/*-----------------------------------*/
/*-----------------------------------*/
GVertice::GVertice(TPunto origen, int primero)
{
	this->primero = primero;
	circulo = new Circulo(origen, RADIO);
	origen.setPunto(origen.x - RADIO, origen.y - RADIO);
	simbolo = new Simbolo(origen, primero);
}
GVertice::~GVertice()
{}
int GVertice::getPrimero()
{
	return primero;
}
TPunto GVertice::getCentro()
{
	return circulo->getCentro();
}
GVertice* GVertice::entroAlVertice(int x, int y)
{
	if (circulo->entroAlCirculo(x, y))
		return this;
	return NULL;
}
void GVertice::mostrarVertice(Graphics^ lienzo)
{
	circulo->mostrarCirculo(lienzo);
	simbolo->mostrarSimbolo(lienzo);
}
/*-----------------------------------*/
/*-----------------------------------*/
GArista::GArista(TPunto origen, TPunto destino, int peso)
{
	this->estado = true;

	inicializarSimbolo(origen, destino, peso);
	inicializarLineaDireccional(origen, destino);
}
GArista::~GArista()
{}
void GArista::inicializarSimbolo(TPunto origen, TPunto destino, int peso)
{
	TPunto centro;
	centro.setPunto((origen.x + destino.x) / 2.0,
		(origen.y + destino.y) / 2.0);
	simbolo = new Simbolo(centro, peso);
}
void GArista::inicializarLineaDireccional(TPunto origen, TPunto destino)
{
	float cat1 = destino.x - origen.x;
	float cat2 = destino.y - origen.y;

	float hipot = sqrt(cat1*cat1 + cat2*cat2);

	TPunto auxiliar;
	auxiliar.x = (cat1*RADIO) / hipot;
	auxiliar.y = (cat2*RADIO) / hipot;

	origen.x += auxiliar.x;
	origen.y += auxiliar.y;

	destino.x -= auxiliar.x;
	destino.y -= auxiliar.y;

	linea = new LineaDireccional(origen, destino);
}
void GArista::setPeso(int peso)
{
	simbolo->setSigno(peso);
}
void GArista::setEstado(bool estado)
{
	this->estado = estado;
}
void GArista::mostrarArista(Graphics^ lienzo)
{
	if (estado)
	{
		linea->mostrarLineaDireccional(lienzo);
		simbolo->mostrarSimbolo(lienzo);
	}	
}
/*-----------------------------------*/
/*-----------------------------------*/
BloqueRelacion::BloqueRelacion(TPunto origen, int u, int v, int w)
{
	this->origen = origen;
	this->peso = w;
	nodo.first = u;
	nodo.second = v;
	estado = false;
	ancho = LADO * 3;
	alto = LADO;
}
BloqueRelacion::~BloqueRelacion()
{}
ii BloqueRelacion::getNodoDatos()
{
	return nodo;
}
void BloqueRelacion::setEstado(bool estado)
{
	this->estado = estado;
}
void BloqueRelacion::setPeso(int peso)
{
	this->peso = peso;
}
bool BloqueRelacion::entroAlBloque(int x, int y)
{
	if (origen.x < x && x < origen.x + ancho)
	{
		if (origen.y < y && y < origen.y + alto)
			return true;
	}
	return false;
}
void BloqueRelacion::mostrarBloqueRelacion(Graphics^ lienzo)
{
	Font^ fuente = gcnew Font("Times New Roman", TAMANIO * 2);
	SolidBrush^ pincel = gcnew SolidBrush(Color::Blue);
	Pen^ lapiz;
	if (estado)
		lapiz = gcnew Pen(Color::Red, 2);
	else
		lapiz = gcnew Pen(Color::Black, 2);
	
	lienzo->DrawRectangle(lapiz, origen.x, origen.y, ancho, alto);
	lienzo->DrawString(nodo.first.ToString(), fuente, pincel, origen.x, origen.y);
	lienzo->DrawString(nodo.second.ToString(), fuente, pincel, origen.x + LADO, origen.y);
	lienzo->DrawString(peso.ToString(), fuente, pincel,	origen.x + LADO * 2, origen.y);
}

