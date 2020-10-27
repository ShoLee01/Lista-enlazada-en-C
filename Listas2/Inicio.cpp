#include <iostream>
#include "Liatas.h"
using namespace std;

int main() {
	int elem;
	int dato;
	Listas* Nodo = new Listas();
	while (true)
	{
		cout << "********** MENU **********";
		cout << "1.- Agregar Elemento: ";
		cout << "2.- Elimanar: ";
		cout << "3.- Modificar en posicion: ";
		cout << "4.- modificar por elemento: ";
		cout << "5.- Mostrar: ";
		cout << "Seleccione opcion: "; cin >> elem;
		system("CLS");
		switch (elem)
		{
		case 1:	cout << "Digite elemento: "; cin >> elem; 
						Nodo->Agregar(elem); break;
		case 2: cout << "Digite elemento a eliminar"; cin >>
						elem;Nodo->Eliminar(elem); break;
		case 3: cout << "Digite posicion :" << endl; cin >> elem;
				cout << "Digite numero a remplazar: " ; cin >> dato;
				Nodo->ModificarElem(elem, dato); break;
		case 4: cout << "Digite elemento a reemplazar: " << endl; cin >> elem ;
				cout << "Digite nuevo elemento: "; cin >> dato;
				Nodo->ModificarPos(elem, dato); break;
		case 5: for (int i = 0; i < Nodo->GetTam(); i++) {
			cout << Nodo->MostrarPos(i)<<endl;
				}	break;
		default:
			cout << "Opcion no valida";
			break;
			system("PAUSE");
			system("CLS");
		}
	}

}