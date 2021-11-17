#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class Matriz {
	
friend ostream &operator <<(ostream &,Matriz &);
friend Matriz &operator *(Matriz &, Matriz &);
friend Matriz &operator +(Matriz &, Matriz &);
friend Matriz &operator -(Matriz &);
	
    private:
        int DIM;
        int **matriz;

    public:
        Matriz(int);
        Matriz();
        ~Matriz();
        int crearM();
        

      	void multiplicarEscalar(int);

};

#endif