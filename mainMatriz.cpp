#include <string>
#include <stdlib.h>
using std::srand;
using std::rand;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
#include <ctime>
using std::time;
#include "Matriz.hpp"
#include "Sistema.hpp"
#include "MatrizCompleja.hpp"

int main() {

	srand(time(NULL));
    string nombre;
    char op1,op2, op3;
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
    
    Sistema *ptrD;
    ptrD = new Sistema(dimension);
	
	MatrizCompleja A(dimension);
	MatrizCompleja B(dimension);
	MatrizCompleja D(dimension);
	
	system("cls");
	
	
	cout<<"A continuacion te mostramos de opcion de cual calculadora deseas utilizar"<<endl;
	cout<<"\t1)Calculadora de Matrices Normales"<<endl;
	cout<<"\t2)Calculadora que suma y resta Matrices Complejas"<<endl;
	cout<<"\t3)Salir."<<endl;
	cout<<"Ingresa tu opcion: ";
	cin>>op1;
	
    switch(op1){
    	
    	case '1':
		    cout<<nombre<<" Acontinuacion te mostramos un menu para realizar multiples operaciones con matrices"<<endl;
			cout<<"\nOperaciones con Matrices:"<<endl;
			cout<<"\ta) Multiplicacion por un Escalar."<<endl;
			cout<<"\tb) Division por un Escalar."<<endl;
			cout<<"\tc) Suma de dos Matrices."<<endl;
			cout<<"\td) Producto de dos Matrices."<<endl;
			cout<<"\te) Resta de dos Matrices."<<endl;
			cout<<"\t\n\nSolucion de sistemas:"<<endl;
			cout<<"\tf) Gauss Jordan"<<endl;
		
		    cout<<"\nPor favor ingresa tu opcion con la letra respectiva (a-f): ";
			cin>>op2;
			system("cls");
			
			switch(op2){
				
				case 'a':
		            ptrA->llenarMatriz();
		            cout<<*ptrA;
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
					ptrA->llenarMatriz();
					cout<<*ptrA;
					cout<<endl;
					cout<<nombre<<" Ingresa el escalar: ";
					cin>>escalar;
					cout<<"\nEl Resultado de tu Division por un Escalar es: "<<endl;
					ptrA->dividirEscalar(escalar);
		            cout<<*ptrA;
					cout<<endl;
					cout<<nombre<<" Gracias por utilizar esta calculadora de Matrices!"<<endl;
				break;
					
				case 'c':
		            ptrA->llenarMatriz();
		            cout<<*ptrA;
					cout<<endl;
					ptrB->llenarMatriz();
					cout<<*ptrB;
					cout<<endl;
					C=*ptrA+*ptrB;
					cout<<C<<endl;
					cout<<nombre<<" Gracias por utilizar esta calculadora de Matrices!"<<endl;
				break;	
		
				case 'd':
					ptrA->llenarMatriz();
					cout<<*ptrA;
					cout<<endl;
					ptrB->llenarMatriz();
					cout<<*ptrB;
					cout<<endl;
					C=*ptrA**ptrB;
					cout<<C<<endl;
					cout<<nombre<<" Gracias por utilizar esta calculadora de Matrices!"<<endl;
				break;	
			
				case 'e':
					ptrA->llenarMatriz();
					cout<<*ptrA;
					cout<<endl;
					ptrB->llenarMatriz();
					cout<<*ptrB;
					cout<<endl;
					C=*ptrA-*ptrB;
					cout<<C<<endl;
					cout<<nombre<<" Gracias por utilizar esta calculadora de Matrices!"<<endl;
				break;
		
				case 'f':
					ptrD->llenarMatriz();
					cout<<*ptrD;
					cout<<"\nLa solucion del sistema por medio de Gauss Jordan es: "<<endl;
					ptrD->Gauss();
					cout<<*ptrD;
					cout<<endl;
					cout<<nombre<<" Gracias por utilizar esta calculadora de Matrices!"<<endl;	
				break;
				
				default:
					
					cout<<"\tERROR!!"<<endl;
					cout<<"Usted ha ingresa una opcion incorrecta."<<endl;
					cout<<"Volver a correr el programe e ingresar una opcion correcta."<<endl;
			}
		break;	
		
		case '2':
				system("cls");
				cout<<"\n\tBIENVENIDO"<<endl;
				cout<<"A continuacion te presento una calculadora de Matrices con complejos"<<endl;
				cout<<"Esta Calculadora solo efectua suma y resta de Matrices Complejas"<<endl;
				
				system("pause");
				system("cls");
				cout<<"Que operacion deseas realizar?"<<endl;
				cout<<"\t1)Suma de Matrices Complejas"<<endl;
				cout<<"\t2)Resta de Matrices Complejas"<<endl;
				cout<<"\t3)Salir"<<endl;
				cout<<"Ingresa tu opcion: ";
				cin>>op3;
				
				switch(op3){
					
				case '1':
					A.llenarMatriz();
					A.ImprimirMatSu();
					cout<<endl;
					B.llenarMatriz();
					B.ImprimirMatSu();
					cout<<endl;
					D=A+B;
					D.ImprimirMatSu();
				break;
				
				case '2':
					A.llenarMatriz();
					A.ImprimirMatRe();
					cout<<endl;
					B.llenarMatriz();
					B.ImprimirMatRe();
					cout<<endl;
					D=A-B;
					D.ImprimirMatRe();	
				break;
				
				default:
					cout<<"Usted ingreso la opcion Salir"<<endl;
			
			}				
		break;			
	}
	

	system("pause");
	return 0;
	
}