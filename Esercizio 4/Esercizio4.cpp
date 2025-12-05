#include <iostream>
#include <cmath>

using namespace std;



/*COSE DA RICORDARE:

 - Ogni istruzione in C++ termina con il punto e virgola ";"
 - Includere SEMPRE "using namespace std;"
 - Le parentesi graffe "{ ... }" servono a delimitare blocchi di codice (es: funzioni, cicli, condizioni, etc ...)
 - E' buona pratica indentare il codice (usare spazi o tabulazioni per rendere il codice piu leggibile)

*/


struct persona {
    string nome;
    int eta;
    double altezza;
};


/*Capiamo cosa abbiamo scritto:

    1) Le strutture (struct) permettono di creare nuovi tipi di dati composti da piu variabili (chiamate membri).
       Esempio: La struct "persona" contiene tre membri: "nome" (stringa)
                                                         "eta" (intero)
                                                         "altezza" (double).
                                                        

    2) La struttura di una struct e':
       
       struct nome_struct {
           tipo_membro1 nome_membro1;
           tipo_membro2 nome_membro2;
           ...
       };

    3) Per accedere ai membri di una struct si usa l'operatore punto (.):
       "nome_variabile.nome_membro"
        es: persona p;
            p.nome = "Mario";
            p.eta = 30;
            p.altezza = 1.75;

    NB: Quello che bisogna notare e che la struct crea un nuovo tipo di dato (persona) 
        che puo essere usato come qualsiasi altro tipo di dato (int, double, string, etc ...)

        --> Array, vector, funzioni ecc... possono usare le struct come tipi di dato!

*/

void inserisci_persona(persona &p) {    //"&" per passare la struct per riferimento senza ricreare una copia
    // Funzione che inserisce i dati di una persona
    cout << "Inserisci il nome: ";
    cin >> p.nome;
    cout << "Inserisci l'eta': ";
    cin >> p.eta;
    cout << "Inserisci l'altezza: ";
    cin >> p.altezza;

    //RICORDA VOID NON HA BISOGNO DI RETURN
}

persona elenco_persone(int n) {
    // Funzione che crea un array di struct persona e ne inserisce i dati
    persona persone[n];
    for (int i = 0; i < n; i++) {
        cout << "Inserisci i dati della persona " << (i + 1) << ":\n";
        inserisci_persona(persone[i]);
    }
    return persone[n];   
}


 int quanti_con_nome (persona persone[], int n, string nome_cercato) {   //Quando passi un array a una funzione,
                                                                        //non e' necessario specificare la dimensione dell'array
    // Funzione che conta quante persone hanno un certo nome
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (persone[i].nome == nome_cercato) {
            count++;
        }
    }
    return count;
}

