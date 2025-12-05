#include <iostream>
#include <cmath>
#include <random>
#include <vector>
#include <fstream>

using namespace std;



//Esempio di D20 https://tinyurl.com/5c3dp69d


minstd_rand0 generatore1; // crea un generatore di numeri casuali
mt19937 generatore2; // crea un generatore di numeri casuali piu complesso

double lancio_d20() {
    // Funzione che simula il lancio di un dado a 20 facce
    uniform_int_distribution<int> distribuzione(1, 20); // distribuzione uniforme tra 1 e 20
    return distribuzione(generatore2); // restituisce un numero casuale tra 1 e 20
}




int main() {
                                    // inizializza il generatore con un seme casuale
    generatore2.seed(time(0));      //Prende come valore il tempo attuale in secondi come seme

    // distribuzione normale con media 0 e deviazione standard 1
    normal_distribution<double> distribuzione_normale(0.0, 0.2);

    const int N = 100000;
    double sum = 0.0;
    double sum_quadrato = 0.0;

    std::cout << "Prime 10 estrazioni (N(0,1)):";
    for (int i = 0; i < N; ++i) {
        double x = distribuzione_normale(generatore2);
        sum += x;
        sum_quadrato += pow(x, 2);

    }

    double mean = sum / N;
    double variance = sum_quadrato / N - pow(mean, 2);

    cout << "\nMedia campionaria: " << mean << "\nVarianza campionaria: " << variance << std::endl;



/*Capiamo cosa abbiamo scritto:
    1) Per generare numeri casuali in C++ possiamo usare la libreria <random> che offre vari generatori e distribuzioni.
       In questo esempio abbiamo usato il generatore Mersenne Twister (mt19937) e una distribuzione normale (normal_distribution).
       Una volta che abbiamo il generatore dobbiamo scegliere una distribuzione (es: uniforme, normale, etc ...) e usarla per estrarre numeri casuali.

       NB: Il generatore deve essere inizializzato con un seme (seed) per garantire la casualità. 
       In questo caso abbiamo usato il tempo attuale in secondi. (time(0)) -> Molto sicuro.

    2) La distribuzione normale è definita da una media (mean) e una deviazione standard (stddev).
       La distribuzione uniforme è definita da un intervallo [min, max] e ha bisogno di tipi interi (int) o reali (double).

*/



    vector <int> lanci;
    for (int i = 0; i < 100; ++i) {
        int lancio = lancio_d20();
        lanci.push_back(lancio);
    }
    cout << "Lanci del D20: ";
    for (int lancio : lanci) {
        cout << lancio << " ";
    }
    cout << endl;

    
    fstream f;
    f.open("lanci_d20.csv", ios::out);   // scrivere "ios::out" , leggere "ios::in" , leggere e scrivere "ios::in | ios::out"

    if (!f) {
        cout << "Errore nell'apertura del file!" << endl;
        return 1; // termina il programma con un codice di errore
    }

    for (int lancio : lanci) {
        f << lancio << " ";
    }
    f.close();
    cout << "Lanci del D20 salvati in lanci_d20.csv" << endl;

/*Capiamo cosa abbiamo scritto:
    1) Per scrivere/leggere su un file in C++ usiamo la libreria <fstream> che offre la classe fstream.
       Per aprire un file usiamo il metodo open() specificando il nome del file e la modalità (lettura, scrittura, etc ...).
       es:
            fstream f;
            
            f.open("nomefile.csv", ios::out); // per scrivere su un file

            oppure
            f.open("nomefile.csv", ios::in); // per leggere da un file

            oppure 
            f.open("nomefile.csv", ios::in | ios::out); // per leggere e scrivere su un file


       NB:E' importante controllare se il file è stato aperto correttamente, si usa:
            
            if (f.fail()==true) {
                cout << "Errore nell'apertura del file!" << endl;
                break; // o return 1; per terminare il programma
            }
    
    2) Per scrivere su un file usiamo l'operatore "<<" come per cout. ("f << valore << ... << endl;" )
       Per leggere da un file usiamo l'operatore ">>" come per cin. ("f >> variabile >> ...;" )
        NB: Se non si sanno il numero di dati da leggere si puo usare un ciclo while:
            es:
                while(f.eof() == false) {       //f.eof() ritorna true se siamo alla fine del file (End Of File)
                    int x;
                    f >> x >> ws;               // ws serve per l'eventuale andata a capo e evita spazi inutili
                    cout << x << endl;
                }
    3) Una volta finito di usare il file è fondamentale chiuderlo con il metodo close() per evitare perdite di dati o errori.
    
    NB: Quando scrivi un file non è detto che deve essere per forza un .csv, puo essere anche un .txt o altro.
        L'estensione serve solo per indicare il tipo di file.
    
*/

}



/*COSE DA RICORDARE:

 - Ogni istruzione in C++ termina con il punto e virgola ";"
 - Includere SEMPRE "using namespace std;"
 - Le parentesi graffe "{ ... }" servono a delimitare blocchi di codice (es: funzioni, cicli, condizioni, etc ...)
 - E' buona pratica indentare il codice (usare spazi o tabulazioni per rendere il codice piu leggibile)
 - Chiudere, una volta aperto, un file con "f.close();" e' fondamentale per evitare perdite di dati o errori!.

*/
