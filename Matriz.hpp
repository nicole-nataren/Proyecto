#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
using std::ostream;

class Matriz {
friend ostream &operator <<(ostream &, Matriz &);	
friend Matriz &operator *(Matriz &, Matriz &);
friend Matriz &operator +(Matriz &, Matriz &);
friend Matriz &operator -(Matriz &, Matriz &);
	
    private:
        int DIM;
        float **matriz;

    public:
        Matriz(int);
        Matriz();
        ~Matriz();
        
        void llenarMatriz();
      	void multiplicarEscalar(int);
      	void dividirEscalar(int);

};

#endif



