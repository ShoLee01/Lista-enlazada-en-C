#pragma once
#pragma once
#include <iostream>
using namespace std;

class Listas {
	struct Nodo
	{
		int Num;
		Nodo* sig;
		Nodo* anterior;
		Nodo(int _num, Nodo* Sig = NULL,Nodo* Antes=NULL) {
			this->Num = _num;
			this->anterior = Antes;
			this->sig = Sig;
		}
	};
private:
	int Size;
	Nodo* ini;
	Nodo* Antes;
public:
	Listas();
	~Listas();
	void AgregarInicio(int);
	void AgregarFinal(int);
	void AgregarenPos(int, int);
	void  Eliminar(int);
	void ModificarPos(int, int);
	void ModificarElem(int, int);
	int MostrarPos(int);
	int GetTam();
};

Listas::Listas()
{
	Size = 0;
	ini = NULL;
	Antes = NULL;
}

Listas::~Listas() {}
void Listas::AgregarFinal(int num)

{


	if (ini == NULL&&Antes==NULL) {
		AgregarInicio(num);
	}
	else
	{
		Size++;
		Nodo* aux;
		aux = ini;
		Nodo* Antes = NULL;
		while (aux->sig != ini)
		{
			Antes = aux;
			aux = aux->sig;
		}
		if (Antes == NULL) {
			Nodo* Elem = new Nodo(num, ini, aux);
			aux->anterior = Elem;
			aux->sig = Elem;
		}
		else
		{
			Nodo* Elem = new Nodo(num, ini, Antes);
			aux->sig = Elem;
		}
		
	}

}
void Listas::AgregarInicio(int num)

{
	if (ini==NULL&&Antes==NULL) {
		Size++;
		Nodo* nuevo = new Nodo(num, ini, ini);
		ini = nuevo;
		ini->sig=nuevo;
		ini->anterior = nuevo;
		
	}
	else {
		Size++;
		Nodo* aux = ini;
		Nodo* Primero = ini;
		Nodo* antes = NULL;
		while (aux->sig!=ini)
		{
			antes = aux;
			aux = aux->sig;
		}
		if (antes == NULL) {
			Nodo* Elem = new Nodo(num, ini, aux);
			aux->anterior = Elem;
			aux->sig = Elem;

		}
		else
		{
			Nodo* Elem = new Nodo(num, Primero, aux);
			aux->anterior = Elem;
			Elem->sig = Primero;
			Elem->anterior = aux;
			aux->sig = Elem;
			ini = Elem;
		}
		
	}
	
}
void Listas::Eliminar(int pos)
{
	if ((pos >= 0) && (pos <=Size)) {
		Nodo* Primero = ini;
		Nodo* Anterior = NULL;
		Nodo* aux = ini;
		int cont = 0;
		while (cont<pos-1) {
			Anterior = aux;
			aux = aux->sig;
			cont++;
		}
		if (pos - 1 == 0)//Elemento de inicio
		{
			Primero = Primero->sig;
			Primero->anterior = aux;
			aux->sig = Primero;
			ini = Primero;
		}
		else
		{
			if (Size == pos) {//Elemento Final
				Anterior->sig =Primero;
				Primero->anterior = Anterior;

			}
			else {//Elemento intermedio

				Anterior->sig=aux->sig;
				aux = aux->sig;
				aux->anterior = Anterior;

			}
		}
		--Size;
	}
}

void Listas::ModificarPos(int pos, int elem)
{

	if (pos >= 0 && pos < Size) {
		Nodo* aux;
		int cont = 0;
		aux = ini;
		while (cont < pos - 1)
		{
			aux = aux->sig;
			cont++;
		}
		aux->Num = elem;
	}
	else {
		cout << "No se encontro elemento :c " << endl;
		system("pause");
	}
}
void Listas::ModificarElem(int bus, int edi)
{

	if (ini != NULL) {
		int cont = 0;
		bool key = true;
		Nodo* aux;
		aux = ini;
		while (cont < Size)
		{
			cont++;
			if (aux->Num == bus) {
				aux->Num = edi;
				key = false;
				break;
			}
			aux = aux->sig;
		}


		if (key)
		{
			cout << "No se encontro elemento :c " << endl;
			system("pause");
		}
	}
}
int Listas::MostrarPos(int Pos) {
	if (ini != NULL) {
		int cont = 0;
		Nodo* aux;
		aux = ini;
		while (cont < Pos) {
			aux = aux->sig;
			cont++;
		}
		return aux->Num;
	}
	else
	{
		cout << "Viva chucho xd";

	}
}
void Listas::AgregarenPos(int pos, int elem) {
	if (pos >= 0 && pos <= Size) {
		Nodo* push = NULL;
		Nodo* aux = ini;
		Nodo* anterior = NULL;
		int cont = 0;
		while (cont < pos - 1) {
			anterior = aux;
			aux = aux->sig;
			cont++;
		}
		if (pos == 1) {
			AgregarInicio(elem);
		}
		else
		{
			if (pos == Size) {
				AgregarFinal(elem);
			}
			else
			{
				push = new Nodo(elem,aux,anterior);
				anterior->sig = push;
				push->anterior = anterior;
				push->sig = aux;
				aux->anterior = push;
				++Size;
			}
		}
	
	}
}
int Listas::GetTam() {
	return Size;
}