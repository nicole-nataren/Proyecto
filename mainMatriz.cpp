#include <iostream>
#include <string>
#include <stdlib.h>

#include "Matriz.hpp"
#include "Sistema.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {

    string nombre;
    char opcion;
    int dimension, escalar;

    cout << "BIENVENIDO USUARIO!!" << endl;
	cout << "Por favor, ingresa tu nombre: ";
    cin >> nombre;

    system("cls");

    cout<<"\nHola " << nombre << "! Te presento una Calculadora de Matrices mxm"<<endl;
	cout<<"Espero sea muy util para ti!"<<endl;
	cout<<endl;
	
	cout<<nombre<<" Puedes ingresar la dimension de la matriz: ";
	cin>>dimension;
	cout<<endl;
	
    Matriz *ptrA;
	ptrA = new Matriz(dimension);
    Matriz *ptrB;
	ptrB = new Matriz(dimension);
    Matriz C (dimension);
	Sistema Sis1(dimension);
	
	system("cls");

    cout<<nombre<<" Acontinuacion te mostramos un menu para realizar multiples operaciones con matrices"<<endl;
	
	cout<<"\nOperaciones con Matrices:"<<endl;
	cout<<"\ta) Multiplicacion por un Escalar."<<endl;
	cout<<"\tb) Suma de dos Matrices."<<endl;
	cout<<"\tc) Producto de dos Matrices."<<endl;
	cout<<"\t\nSolucion de sistemas:"<<endl;
	cout<<"\td) Gauss Jordan"<<endl;

    cout<<"\nPor favor ingresa tu opcion con la letra respectiva (a-d): ";
	cin>>opcion;
	
	system("cls");
	
	cout<<endl;

    switch(opcion){
	
		case 'a':
            ptrA->crearM();
			cout<<endl;
			cout<<nombre<<" Ingresa el escalar: ";
			cin>>escalar;
			cout<<"\nEl Resultado de tu Multiplicacion por un Escalar es: "<<endl;
			ptrA->multiplicarEscalar(escalar);
            cout<<*ptrA;
			cout<<endl;
			cout<<nombre<<" Gracias por utilizar esta calculadora de Matrices!"<<endl;
		break;	
	
		case 'b':
            ptrA->crearM();
			cout<<endl;
			ptrB->crearM();
			C=*ptrA+*ptrB;
			cout<<C<<endl;
			cout<<nombre<<" Gracias por utilizar esta calculadora de Matrices!"<<endl;
		break;	
		
		case 'c':
			ptrA->crearM();
			cout<<endl;
			ptrB->crearM();
			cout<<endl;
			C=*ptrA**ptrB;
			cout<<C<<endl;
			cout<<nombre<<" Gracias por utilizar esta calculadora de Matrices!"<<endl;
		break;	
			
		case 'd':
		Sis1.crearM();
		cout<<"\nLa solucion del sistema por medio de Gauss Jordan es: "<<endl;
		Sis1.Gauss();
		cout<<Sis1<<endl;
		cout<<nombre<<" Gracias por utilizar esta calculadora de Matrices!"<<endl;
		break;
		
		default:
			
			cout<<"\tERROR!!"<<endl;
			cout<<"Usted ha ingresa una opcion incorrecta."<<endl;
			cout<<"Volver a correr el programe e ingresar una opcion correcta."<<endl;
	}
	return 0;
	
}