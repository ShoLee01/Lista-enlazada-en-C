#include <iostream>
#include "Listas N.h"//Listas Noramles
//#include "Listas C.h"//Listas Circular
//#include "Listas D.h"//Lista Doblemente enlazada
using namespace std;

int main() {
	int elem;
	int dato;
	Listas* Nodo = new Listas();
	while (true)
	{
		cout << "********** MENU **********" << endl;
		cout << "1.- Agregar Elemento Inicio : " << endl;
		cout << "2.- Agregar Elemento Final: " << endl;
		cout << "3.- Eliminar: " << endl;
		cout << "4.- Modificar en posicion: " << endl;
		cout << "5.- modificar por elemento: " << endl;
		cout << "6.- Mostrar: " << endl;
		cout << "7.- Agregar en posicion: " << endl;
		cout << "Seleccione opcion: "; cin >> elem;
		system("cls");
		switch (elem)
		{
		case 1:	cout << "Digite elemento: "; cin >> elem;
			Nodo->AgregarInicio(elem); break;
		case 2:	cout << "Digite elemento: "; cin >> elem;
			Nodo->AgregarFinal(elem); break;

		case 3: cout << "Digite elemento a eliminar: "; cin >>
			elem; Nodo->Eliminar(elem); break;
		case 4: cout << "Digite posicion :" << endl; cin >> elem;
			cout << "Digite numero a remplazar: "; cin >> dato;
			Nodo->ModificarPos(elem, dato); break;
		case 5: cout << "Digite elemento a reemplazar: " << endl; cin >> elem;
			cout << "Digite nuevo elemento: "; cin >> dato;
			Nodo->ModificarElem(elem, dato); break;
		case 6: for (int i = 0; i < Nodo->GetTam(); i++) {
			cout << Nodo->MostrarPos(i) << endl;
		}
			  system("pause"); break;
		case 7: cout << "Digite Posiscion: " << endl; cin >> elem;
			cout << "Digit elemento a agregar: "; cin >> dato;
			Nodo->AgregarenPos(elem, dato); break;
		default:
			cout << "Opcion no valida" << endl; system("PAUSE");
			break;

		}
			  system("cls");
		}

	}

