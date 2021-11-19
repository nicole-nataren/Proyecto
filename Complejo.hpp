class Complejo{
	
	friend Complejo &operator+(Complejo &, Complejo &);
	friend Complejo &operator-(Complejo &, Complejo &);
	
public:
	Complejo(int , int );
	Complejo();
	
	void MostrarCompSu();
	void MostrarCompRe();
	void setReal(int);
	const int getReal();
	void setIm(int);
	const int getIm();
	
private: 
	int real, imag;	
};



