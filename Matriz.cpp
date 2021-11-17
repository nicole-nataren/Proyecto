#include "Matriz.hpp"
#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

Matriz::Matriz(int dimension) {
    this->DIM = dimension;
    this->matriz;
 
    
    matriz = new int *[this->DIM];
    for(int f=0; f < this->DIM; f++){
		this->matriz[f] = new int [this->DIM];
	}
	
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
			matriz[f][c]=0;
		}
	}	
}

Matriz::Matriz(){
	this->DIM = 0;
    this->matriz;
    
    matriz = new int *[this->DIM];
    for(int f=0; f < this->DIM; f++){
		this->matriz[f] = new int [this->DIM];
	}
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
			matriz[f][c]=0;
		}
	}
}


int Matriz::crearM(){
	
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
			cout<<"Ingrese los datos de la matriz: ["<<f<<"]["<<c<<"]: ";
			cin>>this->matriz[f][c];
		}
	} cout<<endl;
	
	cout<<"La Matriz ingresada es: "<<endl;
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
			cout<<"[ "<<matriz[f][c]<<" ]";
			
		}cout<<endl;
	}
return 0;
}

ostream &operator <<(ostream &Imp,Matriz &Ma)
{
 for(int f=0; f < Ma.DIM; f++){
  for(int c=0; c < Ma.DIM; c++){
   Imp<<"["<<Ma.matriz[f][c]<<" ]";
  }
  cout<<endl;
 }
 return Imp;
}


void Matriz::multiplicarEscalar(int Esca){
	
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
            matriz[f][c] = matriz[f][c] * Esca;
		}
	}
}

Matriz &operator +(Matriz &A, Matriz &B){	
int n=A.DIM;
Matriz *resul;
resul = new Matriz(n);

for(int f=0; f < n; f++){
	for(int c=0; c < n ; c++){
		resul->matriz[f][c]= A.matriz[f][c]+B.matriz[f][c];
	}
	cout<<endl;
}

cout<<"La Suma es:"<<endl;

return *resul;
	
}


Matriz &operator *(Matriz &A, Matriz &B){
int n=A.DIM;	
Matriz *Mul;
Mul = new Matriz(n);

for(int f=0; f < n; f++){
	for(int c=0; c < n; c++){
		Mul->matriz[f][c]=0;
		for(int s=0; s < A.DIM; s++){
			Mul->matriz[f][c]+=A.matriz[f][s]*B.matriz[s][c];
		}
		}
	}
	cout<<"La Multiplicacion es: "<<endl;
	
	return *Mul;
	}

//destructor

Matriz::~Matriz(){
 delete[] matriz;
}