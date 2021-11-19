#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <cstdlib>
#include "Complejo.hpp"

Complejo::Complejo(int _real, int _imag){
	this->real = _real;
	this->imag = _imag;
}

Complejo::Complejo(){
	this->real = 0;
	this->imag = 0;
}
//friend
Complejo &operator+(Complejo &C1, Complejo &C2){
	int re = C1.real+C2.real;
	int im = C1.imag+C2.imag;
	Complejo suma(re, im);
	return *(new Complejo(re,im)); 
}

Complejo &operator-(Complejo &C1, Complejo &C2){
	int re = C1.real-C2.real;
	int im = C1.imag-C2.imag;
	Complejo Resta(re, im);
	return *(new Complejo(re,im)); 
}

//funcion miembro
void Complejo::MostrarCompSu(){
	cout<<"El numero Complejo es: "<<this->real<<"+"<<this->imag<<"i"<<endl;
}

void Complejo::MostrarCompRe(){
	cout<<"El numero Complejo es: "<<this->real<<"-"<<this->imag<<"i"<<endl;
}

void Complejo::setReal(int _real){
	this->real = _real;
}

const int Complejo::getReal(){
	return this->real;
}

void Complejo::setIm(int _imag){
	this->imag = _imag;
}

const int Complejo::getIm(){
	return this->imag;
}