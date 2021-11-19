#include "Matriz.hpp"
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
#include <iostream>

//constructor
Matriz::Matriz(int dimension) {
    this->DIM = dimension;
    this->matriz;
 
    
    matriz = new float *[this->DIM];
    for(int f=0; f < this->DIM; f++){
		this->matriz[f] = new float [this->DIM];
	}
	
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
			*(*(this->matriz+f)+c)=0;
		}
	}	
}

//sobrecarga
Matriz::Matriz(){
	this->DIM = 0;
    this->matriz;
    
    matriz = new float *[this->DIM];
    for(int f=0; f < this->DIM; f++){
		this->matriz[f] = new float [this->DIM];
	}
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
			*(*(this->matriz+f)+c)=0;
		}
	}
}

//crear matriz y llenar
void Matriz::llenarMatriz(){
	cout<<"La Matriz Generada es: "<<endl;
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
			*(*(this->matriz+f)+c) = float (1+rand()% 21);
		}
	}
	
}

//Imprimir
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


//Multiplicar escalar
void Matriz::multiplicarEscalar(int Esca){
	
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
            matriz[f][c] = matriz[f][c]*Esca;
		}
	}
}

//dividir escalar;
void Matriz::dividirEscalar(int Esca){
	
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
            matriz[f][c] = matriz[f][c]/Esca;
		}
	}
}

//Friend Suma
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

// friend resta
Matriz &operator -(Matriz &A, Matriz &B){	
int n=A.DIM;
Matriz *resul;
resul = new Matriz(n);

for(int f=0; f < n; f++){
	for(int c=0; c < n ; c++){
		resul->matriz[f][c]= A.matriz[f][c]-B.matriz[f][c];
	}
	cout<<endl;
}

cout<<"La Resta es:"<<endl;

return *resul;
	
}

//friend Multiplicar
Matriz &operator *(Matriz &A, Matriz &B){
int n=A.DIM;	
Matriz *Mul;
Mul = new Matriz(n);

for(int f=0; f < n; f++){
	for(int c=0; c < n; c++){
		Mul->matriz[f][c]=0;
		for(int s=0; s < n; s++){
			Mul->matriz[f][c]+=A.matriz[f][s]*B.matriz[s][c];
		}
		}
	}
	cout<<"La Multiplicacion es: "<<endl;
	
	return *Mul;
	}

//Destructor
Matriz::~Matriz(){
 delete[] matriz;
}