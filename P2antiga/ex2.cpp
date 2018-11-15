#include <iostream>
using namespace std;

class Funcionario 
{
 public:
   Funcionario(string codigoEntrada, string nomeEntrada, double salarioEntrada);
   void setNome(string nome );
   string getNome() const;
   void setCodigo(string codigo);
   string getCodigo() const;
   void setSalario(double salario);
   double getSalario() const;
   double remunaracao() const;           
   void print() const; 

 private:
   string nome;
   string codigo;
   double salario;
};

class Gerente: public Funcionario 
{
 public:
   Gerente(string codigoEntrada, string nomeEntrada, double salarioEntrada, int nmroSupEntrada);
   void setNmroSup(int supervisionados);
   int getNmroSup() const;
   double remunaracao() const;           
   void print() const; 

 private:
	int nmroSup;	
}; 


Funcionario::Funcionario(string codigoEntrada, string nomeEntrada, double salarioEntrada):nome( nomeEntrada ), codigo( codigoEntrada )
{
   setSalario(salarioEntrada);
} 

void Funcionario::setNome(string nomeEntrada ) 
{ 
   nome = nomeEntrada;  
} 


string Funcionario::getNome() const 
{ 
   return nome;  
} 


void Funcionario::setCodigo(string codigoEntrada )
{
   codigo = codigoEntrada; 
} 


string Funcionario::getCodigo() const
{
   return codigo;   
} 

void Funcionario::setSalario(double salarioEntrada){
   	salario = (salarioEntrada>0 ? salarioEntrada : 0);
}


double Funcionario::getSalario() const{
	return salario;
}

double Funcionario::remunaracao() const{
	return getSalario();
}


void Funcionario::print() const
{ 
   cout << getCodigo() << " " <<  getNome() << endl;
   cout << "Salario Fixo:" << getSalario()<< endl;
        
}

//classe gerente   
Gerente::Gerente(string codigoEntrada, string nomeEntrada, double salarioEntrada, int nmroSupEntrada):Funcionario(codigoEntrada, nomeEntrada, salarioEntrada){	
	setNmroSup(nmroSupEntrada);
}

void Gerente::setNmroSup(int supervisionados){
   	nmroSup  = (supervisionados>0 ? supervisionados : 0);
}

int Gerente::getNmroSup() const{
   return nmroSup;
}

double Gerente::remunaracao() const{
	return getSalario() + (getNmroSup()/100.0 * getSalario()) ;
}


void Gerente::print() const
{ 
   Funcionario::print();
   cout << "Supervisionados:" << getNmroSup()<< endl;
      
}


int main(){
	Funcionario f1("001", "Funcionio", 1000);
	f1.print();
	cout << "Remunera��o total: " << f1.remunaracao() << endl<<endl<<endl;
	
	Gerente g1("002", "Gerencio", 1000, 50);
	g1.print();
	cout << "Remunera��o total: " << g1.remunaracao() << endl;

}

