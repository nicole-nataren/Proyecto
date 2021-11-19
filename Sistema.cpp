#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
#include "Sistema.hpp"

Sistema::Sistema(int Dimension){
	this->DIM=Dimension;
    this->matriz;
    
    matriz = new float *[this->DIM];
    for(int f=0; f < this->DIM; f++){
		this->matriz[f] = new float [this->DIM];
	}
	
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
			matriz[f][c]=0;
		}
	}	
}

Sistema::Sistema(){
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

Sistema::llenarMatriz(){
	cout<<"La Matriz Generada es: "<<endl;
	for(int f=0; f < this->DIM; f++){
		for(int c=0; c < this->DIM; c++){
			*(*(this->matriz+f)+c) = float (1+rand()% 21);
		}
	}
}


//friend
ostream &operator <<(ostream &Imp,Sistema &A)
{
 for(int f=0; f < A.DIM; f++){
  for(int c=0; c < A.DIM; c++){
   Imp<<"["<<A.matriz[f][c]<<" ]";
  }
  cout<<endl;
 }
 return Imp;
}


float Sistema::Gauss(){
	float may, aux, pivote;//variable para almacenar el mayor de la columna 
    int ind;//indice del mayor-->indice de may
    
    for(int n=0; n < this->DIM; n++){//recorrer columnas de la matriz reducida
        may=abs(matriz[n][n]);
        ind=n;
        //recorrer filas de la columna n para buscar el indice del mayor
        for(int s=n+1; s < this->DIM; s++){
            if(may<abs(matriz[s][n])){
                may=abs(matriz[s][n]);
                ind=s;
            }
            
        }

        //cambiar filas
        if(n!=ind){
            for(int f=0; f < this->DIM+1; f++){
                aux=matriz[n][f];
                matriz[n][f]=matriz[ind][f];
                matriz[ind][f]=aux;
            }
            
        }
        if(matriz[n][n]==0){
            cout<<"No tiene solucion"<<endl;
            break;
        }
        else{
            
            for(int f=0; f < this->DIM; f++){//recorrer fila
                if(f!=n){
                    pivote=-matriz[f][n];
                    for(int c=n; c < this->DIM+1; c++){//recorrer elementos de una fila

                        matriz[f][c]=matriz[f][c]+pivote*matriz[n][c]/matriz[n][n];
                    }
                }
                else{
                    pivote=matriz[n][n];
                    for(int c=n; c < this->DIM+1; c++){
                        matriz[f][c]=matriz[f][c]/pivote;
                    }
                }
            }
        }    
	}
	
	cout<<endl;
	
		/*for(int f=0; f < this->DIM; f++){
			for(int c=0; c < this->DIM; c++){
				cout<<"[ "<<matriz[f][c]<<" ]";
			}cout<<endl;
		}cout<<endl;

*/
return 0;
}

//delete
Sistema::~Sistema(){
	delete [] matriz;
}