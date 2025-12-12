#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <fstream>


using namespace std;


class Studente{

    private:
        string nome;
        vector<double> voti;

    public:
        Studente();                                      // costruttore
        Studente(string nome, vector<double> voti);      // costruttore con parametri (*)

        void aggiungi_voto(double voto);
        double calcola_media();

        bool promossi(){                                //Posso scrivere metodi anche inline dentro la classe
            return calcola_media() >= 6.0;
        };

        vector<string> studenti_promossi();


        /*Capiamo cosa abbiamo scritto:
            1) Per definire una classe in C++ usiamo la parola chiave "class" seguita dal nome della classe e dalle parentesi graffe "{ ... }".
               All'interno delle parentesi graffe definiamo gli attributi (variabili) e i metodi (funzioni) della classe.
            
            2) Gli attributi e i metodi possono essere pubblici (public) o privati (private).
               Gli attributi/metodi pubblici possono essere accessibili dall'esterno della classe( altre classi, funzioni o nel main), mentre quelli privati no.

                NB: Si dice Incapsulamento se una classe ha solo campi privati e per accedere a dati si usano i metodi pubblici.
            
            3) Per definire un metodo all'interno di una classe usiamo la stessa sintassi delle funzioni normali, ma senza il tipo di ritorno (void, int, etc ...).
                NB: I metodi posso definirli dentro alla classe(metodo inline) o fuori dalla classe con la sintassi: 
                "Tipo_variabile NomeClasse::NomeMetodo(Elementi_da_passare) {
                                                    cosa_deve_fare 
                                                    
                                                } "
            
            4) Se si vuole accedere ad un campo (se è pubblico) o ad un metodo (se è pubblico) di una classe si usa l'operatore punto "."
                es:
                    Studenti studente1;          // creo un oggetto della classe Studenti
                    studente1.nome = "Mario";    // accedo al campo nome e gli assegno il valore "Mario"
                    studente1.aggiungi_voto(8.5); // accedo al metodo aggiungi_voto e gli passo il valore 8.5

                    (questa cosa si puo fare fuori dalla classe, ad esempio nel main o in altre funzioni)
        
            5) Posso definire un metodo direttamente dentro la classe (metodo inline) come per il metodo "promossi()" qui sopra.
                In questo caso il metodo deve essere breve e semplice, altrimenti è meglio definirlo fuori dalla classe per rendere il codice piu leggibile.
*/


};



Studente::Studente() {
    nome = "Mario"; 
    voti.clear();
}

Studente::Studente(string nome_inserire, vector<double> voti_inserire) {
    nome=nome_inserire;
    voti=voti_inserire;      //NB: Attenzione a non confondervi
                             // nome e voti sono gli attributi della classe
                             // nome_inserire e voti_inserire sono i parametri del costruttore che inserisci
}   


/*Capiamo cosa abbiamo scritto:

    1) Quando definisci il costruttore posso avere diverse scelte per inizializzare gli attributi della classe.
       Nel primo costruttore (senza parametri) inizializzo con valori di default.
       Nel secondo costruttore (con parametri) inizializzo gli attributi con i valori passati come parametri.

*/


void Studente::aggiungi_voto(double voto) {
    voti.push_back(voto);
}

double Studente::calcola_media() {
    double somma = 0.0;
    for (double voto : voti) {
        somma += voto;
    }
    return somma / voti.size();
}




vector<string> Studente::studenti_promossi() {
    vector<string> lista;
    if (promossi()) {                       // NB: qui "promossi()" e' un metodo della classe Studenti
                                            // quindi lo posso chiamare direttamente senza specificare l'oggetto (es: studente1.promossi())
        lista.push_back(nome);
    }
    return lista;
}

/*Capiamo cosa abbiamo scritto:
    1) Per definire un metodo fuori dalla classe usiamo la sintassi "Tipo_variabile NomeClasse::NomeMetodo(Elementi_da_passare) { ... }"
       dove "NomeClasse::" indica che il metodo appartiene alla classe "NomeClasse".
    
    2) All'interno del metodo possiamo accedere agli attributi e ai metodi della classe direttamente perche' siamo all'interno della classe stessa.
       (es: nel metodo calcola_media() accedo all'attributo voti direttamente)

    3) Per restituire un valore da un metodo usiamo la parola chiave "return" seguita dal valore da restituire.
        NB: Il tipo di ritorno del metodo deve essere lo stesso del tipo di dato che si vuole restituire (es: double, int, bool, etc ...)!!

    4) Una parte importante della classi è il costruttore con la sintassi:
            NomeClasse::NomeClasse() {
                // inizializzazioni
            }

       Il costruttore viene chiamato automaticamente quando si crea un oggetto della classe e serve per inizializzare gli attributi della classe.

       NB: Il costruttore non ha un tipo di ritorno (neanche void) e posso avere piu costruttori con parametri diversi (overloading dei costruttori)!


*/





int main() {

    Studente studente1;
    studente1.aggiungi_voto(2);
    studente1.aggiungi_voto(5);
    studente1.aggiungi_voto(3);

    cout << "Media voti dello studente: " << studente1.calcola_media() << endl;

    if (studente1.promossi()) {
        cout << "Lo studente e' promosso!" << endl;
    } else {
        cout << "Lo studente  non e' promosso!" << endl;
    }

    vector<string> promossi = studente1.studenti_promossi();


    Studente *studente2 = new Studente("Luigi", {7, 8, 9});             

    cout << "Media voti dello studente2: " << studente2->calcola_media() << endl;

    delete studente2;  
    /*Capiamo cosa abbiamo scritto:

            1) Nel main creo un oggetto della classe Studente e per usare i metodi della classe uso l'operatore punto "."
                 es: Studente studente1;                   
                     studente1.aggiungi_voto(8.5);    
            
            2) Posso anche creare un oggetto della classe Studente dinamicamente usando il puntatore e l'operatore "new".
                 es: Studente *studente2 = new Studente("Luigi", {7, 8, 9});
               
               Ma una volta definito cosi devo usare l'operatore "->" per accedere ai metodi della classe.
                 es: studente2->calcola_media();

               NB: Ricorda che ogni volta che crei una variabile dinamica o puntatore devi alla fine usare "delete" per liberare la memoria.
                    es: delete studente2;
    */







    
}








/*COSE DA RICORDARE:

 - Ogni istruzione in C++ termina con il punto e virgola ";"
 - Includere SEMPRE "using namespace std;"
 - Le parentesi graffe "{ ... }" servono a delimitare blocchi di codice (es: funzioni, cicli, condizioni, etc ...)
 - E' buona pratica indentare il codice (usare spazi o tabulazioni per rendere il codice piu leggibile)
 - Chiudere, una volta aperto, un file con "f.close();" e' fondamentale per evitare perdite di dati o errori!.

*/
