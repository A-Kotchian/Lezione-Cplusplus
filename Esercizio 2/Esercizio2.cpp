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
    
    NB2: Le funzioni POSSONO richiamare altre funzioni (anche se stesse) al loro interno!
            void SommaRicorsiva(int partenza,int fine, int counter)
                {
                    if (partenza<=fine){
                        counter= counter + partenza;
                        SommaRicorsiva(partenza+1, fine, counter);
                    }
                    else {
                        cout<<"La somma e': "<< counter <<endl;
                        break;
                    }
                }
    
    I parametri iniziali posso definirli anche di default se l'utente non li specifica:
        tipo_di_ritorno nome_funzione(tipo_parametro1 nome1 = valore_default1, tipo_parametro2 nome2 = valore_default2, ...) {
            ...
        }
    I parametri possono essere anche passati per riferimento usando "&":
        tipo_di_ritorno nome_funzione(tipo_parametro1& nome1, tipo_parametro2& nome2, ...) {
            ...
        }
        
        In questo modo le modifiche fatte ai parametri all'interno della funzione si riflettono anche all'esterno della funzione.

*/

void maggiore_di_tutti(int a, int b){
    // Funzione che legge 5 numeri interi da tastiera e restituisce il maggiore
    int max_num = 100000000 ; // Inizializzo max_num al valore minimo possibile per un intero
    if (a > b) {
        cout<< a <<" è il tuo numero piu grande"<<endl;
    }
    else cout<< b << "è il tuo numero piu grande"<<endl;


    int n;
    if(a>5) n=1;
    else n=2;

    switch (n) {
    case 1:
        cout<< a <<" è maggiore a 5"<<endl;
        break;
    default:
        cout<< a <<" è minore o uguale a 5"<<endl;
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
    

*/
}

int main() {
    // Funzione principale del programma

    int num1, num2;
    int n=10;
    double vettore[n];

    cout<<"Benvenuto nel programma cosa vuoi fare?"<<endl;
    cout<<"Inserisci un numero (1-2-3) oppure se vuoi uscire inserisci 0: "<<endl;
    int i;
    while(i!=0){
        cout<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"1) Somma di elementi di un vettore"<<endl;
        cout<<"2) Trova il maggiore tra due numeri interi"<<endl;
        cin>>i;
        if(i==1){
            cout<<"Inserisci 10 numeri nel vettore: "<<endl;
            for(int i=0; i<n; i++){
                cin>>vettore[i];
            }
            double risultato= somma_elementi(vettore, n);
            cout<<"La somma degli elementi del vettore e': "<<risultato<<endl;
            i=3;
        }
        if(i==2){
            cout<<"Inserisci due numeri interi: "<<endl;
            cin>>num1>>num2;
            maggiore_di_tutti(num1, num2);
            i=3;
        }
        if(i!=0 && i!=1 && i!=2 && i!=3){
            cout<<"Hai inserito un numero non valido, riprova oppure inserisci 0 per uscire."<<endl;
        }
    }

    cout<<"Arrivederci!"<<endl;


/*Capiamo cosa abbiamo scritto:
    1) Il ciclo while funziona come il for ma senza inizializzazione e incremento:
        while (condizione) {
            // codice da eseguire fintanto che la condizione e' vera
        }

        NB: E' importante che la condizione diventi falsa ad un certo punto per evitare cicli infiniti!
        1a) Il ciclo while è molto utile se si deve ripetere qualcosa finche non viene verificata una condizione
            es: Vuoi che l utente inserisca 1 2 3 (che corrisponde ad un azione) ma lui inserisce ("ciao" oppure 6 )
                con il while puoi dare errore e chiedere di nuovo l input finche non inserisce un valore valido.

    2) Il ciclo while e ciclo for sono la stessa cosa in certi casi:

        for (inizializzazione; condizione; incremento) {
            // codice da eseguire
        }

        e' equivalente a:

        inizializzazione;
        while(condizione) {
            // codice da eseguire
            incremento;
        }

    3) Il ciclo while puo essere usato anche con la struttura DO-WHILE:

        do {
            // codice da eseguire almeno una volta
        } while (condizione);
        
       Continuerà finche la condizione del while è vera-> Ricorda che prima o poi la condizione deve essere
       falsa per evitare cicli infiniti!
       
       
    4) Un modo per bloccare cicli while o for o do-while è usare il comando "break;"
            while (true) { // ciclo infinito
                ...
                if (condizione_di_uscita) {
                    break; // esce dal ciclo
                }
                ...
            }  

        4a) Fun fact: esiste il comando "continue;" che salta alla prossima iterazione del ciclo
            
            es: for (i=0; i<10; i++) {
                    if (i % 2 == 0) {
                        continue; // salta il resto del ciclo per i pari
                    }
                    cout << i << " "; // stampa solo i numeri dispari
                }

    esempio figo:
        while (true) {
            cout << "Inserisci un numero (0 per uscire): ";
            int numero;
            cin >> numero;
            if (numero == 0) {
                cout<<"Arrivederci!"<<endl;
                break; // esce dal ciclo se l'utente inserisce 0
            }
            cout << "Hai inserito: " << numero << endl;
            
            //Qualcosa da fare con il numero inserito (es: Menu interattivo)

            }

*/

}
/*
    -DA RICORDARE:
        *Variabili definite/"nate" nei cicli for, if, while, etc ... esistono SOLO all'interno di quel blocco di codice!-> MORTE
        *Usare variabili esterne per continuare a usarle dopo ("salvarle").
        *Dentro i cicli o nel if posso scrivere che mi pare.
        *UCCIDERE i cicli while senno non finiscono piu.!!!!!!!!
*/