#include <iostream>
using namespace std;

class Complexo { 
 private:
  double real;
  double imag; 

 public: 
    Complexo (){            
       real =imag = 0;
       }

    Complexo (double R, double I){
         real = R;
         imag = I;
         } 
         

	friend ostream &operator<<(ostream &saida, const Complexo &o2);

	const Complexo operator+(const Complexo &o1) const{
		return Complexo(real+o1.real, imag+o1.imag);
	}

	friend const Complexo operator+(double o1, const Complexo& o2);

	const Complexo operator++(int) {
	  Complexo aux = *this;
	  real++;
	  return aux;
	}


	bool operator==(const Complexo& o2) const{
		if((real==o2.real) && (imag==o2.imag))
			return true;
		else
			return false;
	}

};

ostream &operator<<(ostream &saida, const Complexo &o2){
	if(o2.imag>=0)
		saida << o2.real << "+" << o2.imag << "i";
	else
		saida << o2.real << o2.imag << "i";
	return saida;
}


const Complexo operator+(double o1, const Complexo& o2){
  return Complexo(o1 + o2.real, o2.imag);
} 




int main () {
	Complexo A(3,4), B(5,0), C;
	cout << "A = " << A << endl << "B = " << B << endl;
	C = A + B;
	cout << "C = A + B = " << C << endl;
	A = 4.0 + A;
	cout << "A = 4.0 + A = " << A << endl;
	cout << "A++ (incrementa 1 na parte real): " << A++ << endl;
	if(C==A)
		cout << "C e A s�o iguais"<< endl;
return 0;
}



