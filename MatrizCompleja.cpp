#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <ctime>
using std::time;
#include <stdlib.h>
using std::rand;
using std::srand;
#include "MatrizCompleja.hpp"

//constructor por parametros
MatrizCompleja::MatrizCompleja(){
	this->DIM=0;
}

MatrizCompleja::MatrizCompleja(int Dimension){
	this->DIM=Dimension;
	this->matriz;
	
	this->matriz = new Complejo *[this->DIM];
	for(int f=0; f < this->DIM; f++){
		this->matriz[f] = new Complejo [this->DIM];
	}
	
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
			matriz[f][c];
		}
	}
}

void MatrizCompleja::llenarMatriz(){
		cout<<"La Matriz Generada es: "<<endl;
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
			*(*(this->matriz+f)+c) = Complejo (1+rand()% 21, 1+rand()%21);
		}
	}
}


void MatrizCompleja::ImprimirMatSu(){
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
			cout<<"[ "<<this->matriz[f][c].getReal()<<"+"<<this->matriz[f][c].getIm()<<"i"<<" ]";
		}cout<<endl;
}
}

void MatrizCompleja::ImprimirMatRe(){
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
			cout<<"[ "<<this->matriz[f][c].getReal()<<"-"<<this->matriz[f][c].getIm()<<"i"<<" ]";
		}cout<<endl;
}
}

MatrizCompleja &operator +(MatrizCompleja &A, MatrizCompleja &B){
	int n = A.DIM;
	MatrizCompleja *Resul;
	Resul = new MatrizCompleja(n);
	
	for(int f=0; f < n; f++){
		for(int c=0; c < n; c++){
			Resul->matriz[f][c]= A.matriz[f][c]+B.matriz[f][c];
		}
	}
	cout<<"La suma es de dos Matrices Complejas es:"<<endl;
	return *Resul;
}

MatrizCompleja &operator -(MatrizCompleja &D, MatrizCompleja &C){
	int n = D.DIM;
	MatrizCompleja *Rest;
	Rest = new MatrizCompleja(n);
	
	for(int f=0; f < n; f++){
		for(int c=0; c < n; c++){
			Rest->matriz[f][c]= D.matriz[f][c]-C.matriz[f][c];
		}
	}
	cout<<"La Resta de dos Matrices Complejas es:"<<endl;
	return *Rest;
}