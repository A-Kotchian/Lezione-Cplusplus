#include <iostream>
#include <cmath>
#include <set>

using namespace std;





void scambia(int &x, int &y) { // passaggio per riferimento
	int z = x;
	x = y;
	y = z;
}

/*Capiamo cosa abbiamo scritto:
 - In C++, il passaggio per riferimento permette di modificare le variabili originali
   passate a una funzione, invece di lavorare su copie locali usando il simbolo "&" accanto
    al tipo di dato nella dichiarazione della funzione.

    Il passaggio per riferimento rende piu veloce il codice occupando meno memoria.


    NB: Le modifiche fatte alle variabili all'interno della funzione vengono fatte anche dove la variabile è stata definita.
        Quindi se ti serve il valore della variabile ma non modificarla NON usare il passaggio per riferimento!
        es: 
        
        void funzione(int a)
            { a = a + 1; } // Modifica la variabile originale
            
        void funzione(int &a) 
            { a = a+1  } // Non modifica la variabile originale
 
    NB2: Se si inserisce anche "const" prima del tipo di dato (es: void funzione(const int &a) {...} )
         la variabile passata per riferimento non potra essere modificata all'interno della funzione.
         Questo e' utile per proteggere i dati originali da modifiche accidentali.
         (Ridarà errore se si prova a modificare la variabile all'interno della funzione)

*/



int main() {
    int a = 5, b = 10;
    cout << "Prima dello scambio: a = " << a << ", b = " << b << endl;
    scambia(a, b);
    cout << "Dopo lo scambio: a = " << a << ", b = " << b << endl;


    // puntatori a variabili esistenti
    int *pa = &a;
    int *pb = &b;
    cout << "Indirizzi: pa = " << pa << ", pb = " << pb << endl;
    cout << "Valori tramite puntatore: *pa = " << *pa << ", *pb = " << *pb << endl;


    /*Capiamo cosa abbiamo scritto:
        1) I puntatori sono variabili che memorizzano l'indirizzo  di un'altra variabile.
           Si dichiarano usando l'asterisco (*) prima del nome del puntatore.
           Va specificato il tipo di dato a cui il puntatore punta.
           es: 
                int *p;
                int a = 10;
                p = &a; // Il puntatore p ora punta all'indirizzo di a
                
                oppure

                int a = 10;
                int *p = &a; // Dichiarazione e assegnazione in una riga

            1a) Il puntatore inizialmente puo "puntare" anche niente:
                es:
                    int *p = nullptr; // Puntatore che non punta a nulla
        
        
        2) Per fare operazioni sul puntatore si usano:
            - L'operatore "&" per ottenere l'indirizzo di una variabile
            - L'operatore "*" per usare il valore della variabile a cui punta il puntatore

            es:
                int a=10;
                int *p = &a;
                int raddoppio= *p * 2; // Raddoppia il valore di a usando il puntatore p
        
        NB: Ogni volta che si definisce un puntatore è buona pratica eliminarlo alla fine del suo utilizzo
        con il comando "delete nome_puntatore;" per evitare perdite di memoria.


    */

 
    // array dinamico e aritmetica dei puntatori
    int n = 6;
    int *v = new int[n];   //Ho dato la tipologia di array (int) e la dimensione (n)

    cout << "Inserisci " << n << " numeri interi:" << endl;
    for (int i = 0; i < n; i++) {
        cin>> v[i]; 
    }
    
    for (int i = 0; i < n; i++) {
        v[i] = i * 10;  // Inizializzo l'array
    }

    cout << "Elementi dell'array dinamico:" << endl;
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";  // Stampo gli elementi dell'array
    }
    cout << endl;
    delete[] v;  // Libero la memoria allocata per l'array dinamico


/*Capiamo cosa abbiamo scritto:
    1) Gli array dinamici permettono di creare array con dimensione variabile durante l'esecuzione del programma.
       Si usano i puntatori e l'operatore "new" per allocare memoria per l'array.

       es:
            int n = 10;
            int *v = new int[n]; // Crea un array dinamico di interi di dimensione n

            
        NB: Un altro tipo di array dinamici sono i vector.


    2) Per accedere agli elementi dell'array dinamico si usa la stessa sintassi degli array normali:
        es: v[i] per accedere all'elemento in posizione i

        Si possono trattare come normali array (assegnazione, lettura, cicli, etc ...)

    3) E' importante liberare la memoria allocata per l'array dinamico alla fine del suo utilizzo
       usando il comando "delete[] nome_array;"

       es:
            delete[] v; // Libera la memoria allocata per l'array dinamico v




*/


    // esempio di std::set
    set<int> s = {3, 1, 4, 5, 9, 2, 6};

    cout << "set (ordinato, senza duplicati): ";
    for (int x : s) cout << x << " ";
    cout << endl;

    int da_trovare = 4;
    if (s.find(da_trovare) != s.end()) {
        cout << da_trovare << " trovato nel set\n";
    } else {
        cout << da_trovare << " non presente\n";
    }

    s.insert(10);
    s.erase(1);


/*Capiamo cosa abbiamo scritto:
    1) Un set e' una collezione di elementi UNICI e ordinati.
       In C++ si usa la libreria <set> per creare e gestire i set.

       es:
            set<tipo_di_dato> nome_set = {elementi_iniziali};

    2) Le operazioni principali sui set sono:
        - Inserimento: nome_set.insert(valore);
        - Cancellazione: nome_set.erase(valore);
        - Ricerca: nome_set.find(valore); // Restituisce un iteratore all'elemento o nome_set.end() se non trovato
        - Iterazione: si puo usare un ciclo for per scorrere tutti gli elementi del set

    
    
*/
}






/*COSE DA RICORDARE:

 - Ogni istruzione in C++ termina con il punto e virgola ";"
 - Includere SEMPRE "using namespace std;"
 - Le parentesi graffe "{ ... }" servono a delimitare blocchi di codice (es: funzioni, cicli, condizioni, etc ...)
 - E' buona pratica indentare il codice (usare spazi o tabulazioni per rendere il codice piu leggibile)

*/
