#include "Matriz.hpp"

class Sistema:public Matriz{
	
	public: 
	
	Sistema(int );
	float Gauss();
	crearM();
	
	private:
		
	int **matriz;
	int DIM;
};