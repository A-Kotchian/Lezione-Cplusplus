#include <iostream>
#include <cmath>


using namespace std;

constexpr int numero = 100;          


/*Capiamo cosa abbiamo scritto:

    - " #include " permette di importare pacchetti/librerie
    o parte di codice gia scritta (es: Codice in piu parti io posso importare le funzione di un altro codice)


    - " using namespace std; " permette di evitare di scrivere " std:: " prima di ogni comando
    che fa parte della libreria standard (es: cout, cin, endl, etc ...)
    
    - "#define n= 100 " e' una direttiva al preprocessore che definisce una costante che puo essere usate
    nel codice (in questo caso n vale 100 in tutto il programma)


    Librerie piu usate:  iostream, vector, cmath, algorithm, set, map, etc ...

*/

//inizio del programma vero e proprio
int main(){

    
    cout << "Ciao Mondo!" << endl;
    cout << "Come ti chiami"<<endl;
    
    
    string nome_utente;
    cin>>nome_utente;

    cout<<"Ciao "<<nome_utente<<" facciamo un po di calcoli"<<endl<<"Inserisci 2 numeri interi"<<endl;

    int num1, num2;
    cin>>num1>>num2;
    cout<<"La somma(+) e': "<<num1+num2<<endl;
    cout<<"La differenza(-) e': "<<num1-num2<<endl;
    cout<<"Il prodotto(*) e': "<<num1*num2<<endl;
    cout<<"Il quoziente(/) e': "<<num1/num2<<endl;
    cout<<"Il resto della divisione(%) e': "<<num1%num2<<endl;  //NB: il resto e' definito solo per numeri interi NON per numeri con la virgola(double o float)
    cout<<"Il loro quadrato e': "<< pow(num2,2) <<" e "<<pow(num2,2)<<endl;


/*Capiamo cosa abbiamo scritto:

 1) " int main() { ... } " e' la funzione principale di ogni programma C++.
  Il programma inizia ad eseguire il codice a partire da questa funzione.


 2) " cout << "fras_da_scrivere" << endl; " e' un'istruzione che stampa a schermo (ESCE DAL COMPUTER = Computer-OUTput)
    2a) "cout << setprecision(4) << a << endl;" permette di stampare il valore della variabile "a" con 4 cifre significative
         (per usare "setprecision" bisogna includere la libreria "iomanip")
    2b) "cout << a << setw(7) << b << endl;" permette di stampare il valore della variabile "a" e poi della variabile "b"
         allineata a destra in uno spazio di 7 caratteri (per usare "setw" bisogna includere la libreria "iomanip")

 3) " cin >> variabile; " e' un'istruzione che legge un valore da tastiera (INSERISCI NEL COMPUTER = Computer-INput)

 4) In C++ si usando degli oggetti detti variabili che ti permettono di salvare in memoria numeri/parole/etc ...
    Le variabili possono essere del tipo:(i piu comuni)

    - int : numeri interi (es: -2, 0, 5, 100)
    - double/float : numeri con la virgola (es: 3.14, -0.001, 2.0)
    - string : sequenze di caratteri/parole (es: "Ciao", "1234", "Nome Cognome")
    - char : singoli caratteri (es: 'a', 'Z', '9')
    - bool : valori booleani (es: true, false)

 5) Esistono delle operationi matematiche di base che si possono fare con i numeri:

    - Somma: +
    - Sottrazione: -
    - Moltiplicazione: *
    - Divisione: /
    - Resto della divisione: %  (solo per numeri interi)

    5a) Per i numeri reali (double/float) esistono molte altre operazioni matematiche: (NB: per usarle bisogna includere la libreria "cmath")
        -Potenza: pow(base,esponente)
        -Radice quadrata: sqrt(numero)
        -Valore assoluto: abs(numero)

    5b) Per i booleani esistono le seguenti operazioni logiche: (utili per le condizioni)
        - AND logico: && (devono essere ENTRAMBE vere le due condizioni es: "cond1 && cond2")
        - OR logico: || (ALMENO UNA delle due condizioni deve essere vera es: "cond1 || cond2")
        - NOT logico: !
        - Uguale a: ==  (DIVERSO DA = perchè una singola "=" e' usata per l'assegnazione di valori alle variabili es: "int a = 5;"
                            mentre "a == 5" e' una condizione che verifica se il valore di a e' uguale a 5)

        - Diverso da: !=
        - Maggiore di: >
        - Minore di: <
        - Maggiore o uguale a: >=
        - Minore o uguale a: <=
     NB: Le operazioni in generale possono essere concatenate tra loro! es: (a + b) * (c - d) oppure (a > b) && (c != d) CONSIGLIATO RAGIONARE E USARE PARENTESI



*/

    //Tutto quello fatto puo essere anche salvato in una variabile (assegnamento di valori alle variabili):


    double somma, differenza, prodotto, quoziente, resto, quadrato_num1, quadrato_num2;   //ho deciso io che saranno double 
    somma = num1 + num2;
    differenza = num1 - num2;
    prodotto = num1 * num2;
    quoziente = num1 / num2;
    resto = num1 % num2;
    quadrato_num1 = pow(num1,2);
    quadrato_num2 = pow(num2,2);

    //cout<<somma<<differenza<<prodotto<<quoziente<<resto<<quadrato_num1<<quadrato_num2<<endl;

    
}
  



/*COSE DA RICORDARE:

 - Ogni istruzione in C++ termina con il punto e virgola ";"
 - Includere SEMPRE "using namespace std;"
 - Le parentesi graffe "{ ... }" servono a delimitare blocchi di codice (es: funzioni, cicli, condizioni, etc ...)
 - E' buona pratica indentare il codice (usare spazi o tabulazioni per rendere il codice piu leggibile)

*/
