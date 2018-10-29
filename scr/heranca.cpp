#include <iostream>

using namespace std;

class Funcionario{
    private:
        double salario;
        string nome, nacionalidade,funcao;

    public:

        Funcionario(string nome = 0, string nacionalidade = 0, string funcao = 0, double salario = 0){
            this -> nome = nome;
            this -> nacionalidade = nacionalidade;
            this -> funcao = funcao;
            set_salario(salario);
        }
        string get_nome()const{return nome;}
        string get_nac()const{return nacionalidade;}
        string get_func()const{return funcao;}
        double get_salario()const{return salario;}

        void set_salario(double salario){
            if(salario > 0){
                this-> salario = salario;
            }
            else 
                this-> salario = 0;
        }

        void print() const {
            cout << "Nome: " << get_nome() << endl;
            cout << "Nacionalidade: " << get_nac() << endl;
            cout << "Função: " << get_func() << endl;
        }
};


class Jogador : public Funcionario{
    private: 
        int gols;

    public:

        Jogador(string nome, string nacionalidade, string funcao, double salario, int gols):Funcionario(nome,nacionalidade,funcao,salario){
            set_gols(gols);
        }
        void set_gols(int gols){
            if(gols > 0)
                this->gols = gols;
            else 
                this->gols = 0;
        }
        int get_gol() const{return gols;}
        double get_salarioTOTAL() const{
            return (get_salario() + get_gol()*0.1);
        }
        

        void print() const{
            Funcionario::print();
            cout << "Salario: " << get_salarioTOTAL() << endl;
        }
};

int main(){
    Funcionario f1("Jonathan","Brasileiro","dev",1000);
    f1.print();
}