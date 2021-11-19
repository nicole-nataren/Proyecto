#include "Complejo.hpp"

class MatrizCompleja{

	friend MatrizCompleja &operator +(MatrizCompleja &, MatrizCompleja &);
	friend MatrizCompleja &operator -(MatrizCompleja &, MatrizCompleja &);
	
	
	public:
		MatrizCompleja(int);
		MatrizCompleja();
		void llenarMatriz();
		void ImprimirMatSu();
		void ImprimirMatRe();
		void MultEsca(int);
	
	private:
		int DIM;
		Complejo **matriz;	
};



