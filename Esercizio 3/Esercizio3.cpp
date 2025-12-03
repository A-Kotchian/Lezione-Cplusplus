#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*COSE DA RICORDARE:

 - Ogni istruzione in C++ termina con il punto e virgola ";"
 - Includere SEMPRE "using namespace std;"
 - Le parentesi graffe "{ ... }" servono a delimitare blocchi di codice (es: funzioni, cicli, condizioni, etc ...)
 - E' buona pratica indentare il codice (usare spazi o tabulazioni per rendere il codice piu leggibile)

*/


#define N 3
constexpr int M = 4;

/*Capiamo cosa abbiamo scritto:
    Per definire costanti in C++ si possono usare due metodi principali:
    1) La direttiva del preprocessore "#define N valore" che sostituisce
         tutte le occorrenze di "N" con "valore" prima della compilazione.
    2) La parola chiave "constexpr" che definisce una costante di tipo specifico
         che viene valutata a tempo di compilazione.
    NB: Le costanti definite in questi modi non possono essere modificate durante l'esecuzione del programma.

*/



    
vector<double> vettore_somma_tra_vettori(vector <double> v1, vector<double> v2){
    // Funzione che somma due vettori elemento per elemento (vettori con stessa dimensione)
    
    vector<double> risultato(v1.size());
    for(size_t i = 0; i < v1.size(); i++){
        risultato[i] = v1[i] + v2[i];
    }

    return risultato;
}


/*Capiamo cosa abbiamo scritto:
    1) Un oggetto più potente degli array in C++ è il "vector" (vettore dinamico)
       che permette di avere una collezione di elementi dello stesso tipo
       con dimensione VARIABILE durante l'esecuzione del programma.

    Per definire un vector si usa la seguente sintassi:
        vector<tipo_di_dato> nome_vettore(dimensione)={elementi};
    NB: La dimensione può essere omessa se si inizializzano gli elementi tra {}
         es: vector<int> v = {1, 2, 3}; // vettore di interi con 3 elementi
        Puoi anche non mettere gli elementi iniziali e poi aggiungerli dopo.

    2)Esistono dei comandi per gestire i vector:
        - Aggiungere un elemento alla fine: nome_vettore.push_back(valore);
        - Rimuovere l'ultimo elemento: nome_vettore.pop_back();
        - Ottenere la dimensione del vettore: nome_vettore.size();
        - Accedere ad un elemento specifico: nome_vettore[indice]; // indice parte da 0
        - Per cancellare tutto il contenuto: nome_vettore.clear();
        ...

    3) Per scorrere tutti gli elementi di un vector si puo usare un ciclo for:
        for (size_t i = 0; i < nome_vettore.size(); i++) {
            // codice da eseguire per ogni elemento, accessibile con nome_vettore[i]
        }

*/



int main(){

    int vettore[N];
    double v[N]={1,2,3};
    double w[]={4,5,6};

    double matrice[N][M]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    cout<<"Inserisci elementi del vettore: ";
    for(int i=0; i<N; i++){
        cin>> vettore[i];
    }

    int conta=0;
    for(int i=0; i<N; i++){
        conta++;
    }
    cout<<"Hai inserito "<<conta<<" elementi nel vettore."<<endl;



    for (int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<< matrice[i][j]<<" ";
        }
        cout << endl;
    }


    /*Capiamo cosa abbiamo scritto:
        1) Un array è un oggetto che permette di avere piu valori dello stesso tipo
        associati ad un unico nome.
        Esistono array monodimensionali (vettori es: tipo_variabile nome[dimensione])
        e multidimensionali (matrici es: tipo_variabile nome[dimensione1][dimensione2]).
        La dimensione si puo inserire tra [dimensione] oppure non inserirla [] ma vanno messi gli elementi tra {}.
        NB: La dimensione di un array deve essere una costante (definita con #define o const).
            NON PUO VARIARE IN TUTTO IL CODICE.
            
        2)Se devi accedere ad un elemento specifico dell'array si usa l'indice tra parentesi quadre,
        ricordando che il primo elemento ha indice 0 !!!!!
            es: vettore[0] -> primo elemento
                vettore[1] -> secondo elemento
                ...
                vettore[N-1] -> ultimo elemento
        3) Per scorrere tutti gli elementi di un array si puo usare un ciclo for:
            for (int i = 0; i < dimensione; i++) {
                // codice da eseguire per ogni elemento, accessibile con nome[i]
            }
        
        4) Per array multidimensionali (o matrici) si usano piu indici: (es: r [3][4] =elemento in  3 riga e 4 colonna)
            es: matrice[0][0] -> primo elemento della prima riga
                matrice[1][2] -> terzo elemento della seconda riga
                ...
                matrice[N-1][M-1] -> ultimo elemento dell'ultima riga
            4a) Se devi accedere ad un elemento specifico di una matrice bisogna usare 2 cicli for annidati:
                for (int i = 0; i < dimensione1; i++) {
                    for (int j = 0; j < dimensione2; j++) {
                        // codice da eseguire per ogni elemento, accessibile con nome[i][j]
                    }
                }
                Dove, per le matrici, dimensione1= numero di righe e dimensione2= numero di colonne.

        5) Posso definire matrici di dimensione variabile usando i vector di vector:
            es: vector< vector<tipo_di_dato> > nome_matrice(numero_di_righe);
                for (int i = 0; i < numero_di_righe; i++) {
                    nome_matrice[i].resize(numero_di_colonne);
                }
                
                oppure 

                vector<vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
                
            NB: In questo modo posso creare matrici con dimensione variabile durante l'esecuzione del programma.

    */











}