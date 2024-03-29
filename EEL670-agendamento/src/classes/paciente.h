#ifndef paciente_h
#define paciente_h
#include <string>

using namespace std;


//base class
class Paciente{

    //for print and reciving input
    friend ostream &operator <<(ostream &lhs,Paciente&rhs);
    friend istream &operator >>(istream &lhs,Paciente&rhs);

    private:
        string name;
    public:
        string details;
        virtual ~Paciente(){}; //avoid memory leak from children
        Paciente(string init_name);
        Paciente();
        Paciente(const Paciente &paciente); //cpy constructor
        virtual string &getName();
        virtual void setDetails();

        //default comparisions
        bool operator>(Paciente const& other);
        bool operator<(Paciente const& other); 
        bool operator==(Paciente const& other); 

};

class Paciente_Doente: public Paciente {
    private:
        double gravidade=2.0;
    public:
        Paciente_Doente();
        //allow to inherit base constructor since c++11
        //using Paciente::Paciente; //deprecated
        double getGravidade();
        void setDetails();
};

class Paciente_Internado : public Paciente{
    private:
        unsigned diasInternados=5;
    public:
        Paciente_Internado();
        //allow to inherit base constructor since c++11
        //using Paciente::Paciente;  //deprecated
        void setDetails();
};



#endif