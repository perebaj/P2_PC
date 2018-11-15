#include <iostream>

using namespace std;

class Fracao
{
  public:
    Fracao(int n, int d) : num(n), den((d != 0) ? d : 1)
    { /*vazio*/
    }
    Fracao() : num(0), den(1)
    { /*vazio*/
    }

    friend ostream &operator<<(ostream &output, const Fracao &f1);
    friend const Fracao operator*(int a, const Fracao &f1);

  private:
    int num, den;
};

ostream &operator <<(ostream &output, const Fracao &f1){
    output << f1.num << "/" << f1.den;
}

const Fracao operator*(int a, const Fracao &f1){
    return Fracao(a*f1.num, f1.den);
}
int main() 
{
    Fracao A(1, 4), B(3, 1), C(A);
    cout << "A=" << A << endl;
    cout << "B=" << B << endl;
    cout << "C=" << C << endl;
    C = 8 * A;
    cout << "C = 8 * A = " << C << endl;
    cout << "C++ = " << C++ << endl;
    if (C == B)
        cout << "C e B são iguais" << endl;
    A = A * B;
    cout << "A = A * B = " << A << endl;
    return 0;
}