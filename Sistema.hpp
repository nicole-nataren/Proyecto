#include "Matriz.hpp"
#include <iostream>
using std::ostream;

class Sistema:public Matriz{
	
	friend ostream &operator <<(ostream &,Sistema &);
	
	public: 
	
	Sistema(int );
	Sistema();
	~Sistema();
	float Gauss();
	llenarMatriz();
	
	private:
		
	float **matriz;
	int DIM;
};



