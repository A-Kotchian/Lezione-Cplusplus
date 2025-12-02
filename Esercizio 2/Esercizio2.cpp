#include <iostream>
#include <cmath>
using namespace std;

        
/*COSE DA RICORDARE:

 - Ogni istruzione in C++ termina con il punto e virgola ";"
 - Includere SEMPRE "using namespace std;"
 - Le parentesi graffe "{ ... }" servono a delimitare blocchi di codice (es: funzioni, cicli, condizioni, etc ...)
 - E' buona pratica indentare il codice (usare spazi o tabulazioni per rendere il codice piu leggibile)

*/


int somma_elementi(int a, int b) {
    // Questa e' una funzione di esempio che somma due numeri interi
    return a + b;

    //oppure
    //int risultato = a + b;
    //return risultato;
}

/**Capiamo cosa abbiamo scritto:
 
 - Per creare un comando personalizzato (funzione) si usa la seguente sintassi:
 
    tipo_di_ritorno nome_funzione(lista_parametri) {
        // corpo della funzione
        return valore_di_ritorno;
    }
 
    - "tipo_di_ritorno" e' il tipo di dato che la funzione restituisce (es: int, double, string, void se non restituisce nulla, etc ...)
    - "nome_funzione" e' il nome che diamo alla funzione (deve essere univoco e seguire le regole per i nomi delle variabili)
    - "lista_parametri" e' una lista di variabili che la funzione prende in input (se non ci sono parametri si lascia vuota)
    - "return valore_di_ritorno;" e' l'istruzione che restituisce il valore dalla funzione al punto in cui e' stata chiamata
    
    NB: se la funzione è VOID NON VA MESSO IL RETURN

*/

void maggiore_di_tutti(int a, int b){
    // Funzione che legge 5 numeri interi da tastiera e restituisce il maggiore
    int max_num = 100000000 ; // Inizializzo max_num al valore minimo possibile per un intero
    if (a > b) {
        cout<<"a è il tuo numero piu grande"<<endl;
    }
    else cout<<"b è il tuo numero piu grande"<<endl;


    int n;
    if(a>5) n=1;
    else n=2;

    switch (n) {
    case 1:
        cout<< "a è maggiore a 5"<<endl;
        break;
    default:
        cout<< "a è minore o uguale a 5"<<endl;
    }


/*Capiamo cosa abbiamo scritto: 
    1) La struttura di controllo "if (condizione) 
                                    { cosa_deve_fare }
                                  else 
                                    { cosa_deve_fare } " 
      permette di eseguire blocchi di codice diversi a seconda che la condizione sia vera o falsa.
      NB: - La parte "else { ... }" e' opzionale, non sempre serve.
          - Se ho solo 1 riga di codice da eseguire non servono le parentesi graffe "{ ... }"
          - Posso avere piu di una condizione usando "else if (condizione) { ... }" oppure 
            se deve fare la stessa cosa in piu condizioni usare "||" (OR logico) oppure "&&" (AND logico)

    2) Switch puo essere scritto come:
        switch (variabile) {
        case valore1:
            // codice da eseguire se variabile e' uguale a valore1
            break;
        ...
        default:
            // codice da eseguire se variabile non corrisponde a nessun caso precedente
        }

    
        NB:Switch puo essere usato anche unendo piu casi tra loro usando: 
        switch (variabile) {
        case valore1: case valore2:
            // codice da eseguire se variabile e' uguale a valore1 o valore2
        ...

    
    */


}

double somma_elementi(double vettore[], int size) {
    //funzione che somma elementi dell array
    double somma=0;
    for(int i=0; i<size; i++){
        somma=somma+ vettore[i];
    }

    return somma;




/*Capiamo cosa abbiamo scritto:
    1) La struttura di controllo " for (inizializzazione; condizione; incremento) { ... } "
       permette di eseguire un blocco di codice piu volte (ciclo) fintanto che la condizione e' vera.
         NB: - L'incremento puo essere diverso tipo:
                i = i + 1;   // incremento di 1
                i += 2;      // incremento di 2
                i --;         // decremento di 1
                i += k;      // incremento di k
                operazioni piu complicate
             - La variabile "i" è stata definita int perche cosi aumenta come un int (1,2,3,4,...) se fosse double aumenterebbe tipo 1.0, ...

    2) Cose ripetitive come Somma, Prodotto, etc ... possono essere fatte anche con i cicli!
         2a) Struttura di una somma ripetitiva:
                double somma = 0;
                for (i=0; i<size; i++) {
                    ...
                    somma = somma + cosa_da_sommare;
                }
         2b) Struttura di un prodotto ripetitivo:
                double prodotto = 1;
                for (i=0; i<size; i++) {
                    ...
                    prodotto = prodotto * cosa_da_moltiplicare;
                }
    NB: Nei cicli for posso usare anche le condizioni if per fare operazioni condizionate all'interno del ciclo! es:
        for (i=0; i<size; i++) {
            if (condizione) {
                ...
            }
        }
    
    3) 
    
    -DA RICORDARE:
        Variabili definite/"nate" nei cicli for, if, while, etc ... esistono SOLO all'interno di quel blocco di codice!-> MORTE
        Usare variabili esterne per continuare a usarle dopo ("salvarle").
        Dentro i cicli o nel if posso scrivere che mi pare.

        

*/
}

int main() {
    // Funzione principale del programma

    int num1, num2;
    int n=10;
    double vettore[n];
    cout<<"Inserisci due numeri interi: "<<endl;
    cin>>num1>>num2;
    maggiore_di_tutti(num1, num2);
    cout<<"Inserisci 10 numeri nel vettore: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vettore[i];
    }
    double risultato= somma_elementi(vettore, n);
    cout<<"La somma degli elementi del vettore e': "<<risultato<<endl;

}