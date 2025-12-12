#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <fstream>


using namespace std;


/*DISCLAIMER: Questa parte è molto profonda e con tante sfaccettature
              quindi consiglio di consultare "dispense_labinfII.pdf" da pag 46 a 64.
              In questo esercizio alcune cose vengono saltate volontariamente (es: Distruttore, Polimorfismo, etc ...)
*/


class Forma {   // Classe base
    private:
        string nome;
        
    public:
        Forma(string n){
            nome = n;
        }
        
        void stampa() {
            cout << "Forma: " << nome << endl;
        }


};


class Cerchio : public Forma {   // Classe figlia Cerchio
    private:
        double raggio;
        
    public:
        
        Cerchio(double r):Forma("Cerchio"){
            Forma("Cerchio");
            raggio = r;
        }
        
        double area(); 
        void stampa();
        Cerchio operator+(const Cerchio &primo);

};

double Cerchio::area() {
    return M_PI * pow(raggio, 2);
}

void Cerchio::stampa(){
            Forma::stampa();
            cout << "Raggio: " << raggio << endl;
        }


Cerchio Cerchio::operator+(const Cerchio &primo) {        //operatore che somma raggi di due cerchi
            Cerchio c(raggio + primo.raggio);               // e ritorna un cerchio con raggio la somma dei due
            return c;
        }


/*Capiamo cosa abbiamo scritto:

    1) Una volta creata una classe base (es: Forma) posso creare una classe figlia (es: Cerchio) che eredita tutti i campi e metodi della classe base.
       Per fare questo uso la sintassi: "class NomeClasseFiglia : public NomeClasseBase { ... }"

    2) All'interno della classe figlia posso aggiungere nuovi campi e metodi specifici della classe figlia (es: raggio, area(), stampa()).
       e posso anche sovrascrivere i metodi della classe base (es: stampa()).
    
    3) Quando scrivo il costruttore della classe figlia devo chiamare il costruttore della classe base usando la sintassi:
           "NomeClasseFiglia(Tipi_parametri) : NomeClasseBase(Parametri_per_costruttore_base) { ... }"   

    4) Si possono ridefinire le operazioni tra oggetti di una classe (operator overloading).
       In questo esempio ho ridefinito l'operatore "+" per sommare i raggi di due cerchi.
       La sintassi per ridefinire un operatore e': 
           "TipoDiRitorno NomeClasse::operator<operatore>(Parametri) {} ... }"

       Dove <operatore> puo essere +, -, *, /, ==, !=, <, >, <=, >=, etc ...
       es:   
                class complesso {
                    double re, im;
                public:
                    complesso(double x, double y);
                    complesso operator+(const complesso &c);
                };
                
                ...

                complesso complesso::operator+(const complesso &c) {
                   complesso r;
                    r.re=re+c.re;
                    r.im=im+c.im;
                    return r;
                }

                int main() {
                    complesso a(1.0, 2.0);
                    complesso b(3.0, 4.0);
                    complesso c = a + b; // usa l'operatore ridefinito
                }

        
*/



int main() {

    Forma forma("Generica");
    forma.stampa();

    Cerchio c(5);
    c.stampa();
    cout << "Area cerchio: " << c.area() << endl;

    Cerchio c1(3);
    Cerchio c2(4);
    Cerchio c3 = c1 + c2;                   // usa l'operatore ridefinito
    c3.stampa();
    cout << "Area cerchio somma: " << c3.area() << endl;
    }




/*COSE DA RICORDARE:

 - Ogni istruzione in C++ termina con il punto e virgola ";"
 - Includere SEMPRE "using namespace std;"
 - Le parentesi graffe "{ ... }" servono a delimitare blocchi di codice (es: funzioni, cicli, condizioni, etc ...)
 - E' buona pratica indentare il codice (usare spazi o tabulazioni per rendere il codice piu leggibile)
 - Chiudere, una volta aperto, un file con "f.close();" e' fondamentale per evitare perdite di dati o errori!.

*/
