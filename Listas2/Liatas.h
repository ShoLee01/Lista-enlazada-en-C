#pragma once
#include <iostream>
using namespace std;

class Listas{
	struct Nodo
	{
		int Num;
		Nodo* sig;
		Nodo(int _num, Nodo* Dato = NULL) {
			this->Num = _num;
			this->sig = Dato;
		}
	};
private:
	int Size;
	Nodo* ini;
public:
	Listas();
	~Listas();
	void AgregarInicio(int);
	void AgregarFinal(int);
	void AgregarenPos(int,int);
	void  Eliminar(int);
	void ModificarPos(int,int);
	void ModificarElem(int,int);
	int MostrarPos(int);
	int GetTam();
};

Listas::Listas()
{
	Size = 0;
	ini = NULL;
}

Listas::~Listas(){}

void Listas::AgregarFinal(int num)

{
	
	
		if (ini == NULL) {
		AgregarInicio(num);
	}
	else
	{
			Size++;
			Nodo* aux;
			aux = ini;
			
		while (aux->sig!=NULL)
		{
			aux = aux->sig;
		}
		Nodo* Agregar = new Nodo(num);
		aux->sig = Agregar;
	}
	
}
void Listas::AgregarInicio(int num)

{
	Size++;
	Nodo* nuevo = new Nodo(num, ini);
	ini = nuevo;
}
void Listas::Eliminar(int pos)
{
	
	if ((pos >= 0) && (pos < Size)) {
		int cont = 0;
		Nodo* aux;
		Nodo* anterior;
		anterior = NULL;
		aux = ini;
		while(cont< pos-1){
			anterior = aux;
			aux = aux->sig;
			cont++;
		}
		if (anterior==NULL)
		{
			ini = ini->sig;
			delete aux;
		}
		else
		{
			anterior->sig= aux->sig;
			delete aux;
		}
		--Size;
}
}
void Listas::ModificarPos(int pos, int elem)
{

	if ( pos>= 0 && pos < Size) {
		Nodo* aux;
		int cont = 0;
		aux = ini;
		while (cont< pos-1)
		{
			aux=aux->sig;
			cont++;
		}
		aux->Num = elem;
	}else {
		cout << "No se encontro elemento :c " << endl;
		system("pause");
	}
}
void Listas::ModificarElem(int bus, int edi)
{

	if (ini!=NULL) {
		int cont = 0;
		bool key= true;
		Nodo* aux;
		aux = ini;
		while (cont<Size)
		{
			cont++;
			if(aux->Num == bus) {
				aux->Num = edi;
				key = false;
			}
			aux = aux->sig;
		}
		
		
		if(key)
		{
			cout << "No se encontro elemento :c "<<endl;
			system("pause");
		}
	}
}
int Listas::MostrarPos(int Pos) {
	if (ini != NULL) {
		int cont = 0;
		Nodo* aux;
		aux = ini;
		while (cont<Pos) {
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
	if (pos >= 0 && pos < Size) {
		Nodo* push = NULL;
		Nodo* aux = ini;
		Nodo* anterior = NULL;
		int cont = 0;
		while(cont<pos-1){
			anterior = aux;
			aux = aux->sig;
			cont++;
		}
		push = new Nodo(elem,aux);
		anterior->sig = push;
		++Size;
	}
}
int Listas::GetTam() {
	return Size;
}