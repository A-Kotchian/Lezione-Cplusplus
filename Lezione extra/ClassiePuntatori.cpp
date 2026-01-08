#include <iostream>
#include <string>
using namespace std;


//Teoria:  (Puntatori -> Pag 1: "dispense_labinfII.pdf" ; Classi -> Pag 29: "dispense_labinfII.pdf")

/*Classi:

 Le Classi sono dei modelli per creare oggetti che raggruppano dati (attributi) e funzioni (metodi) correlate.
 Una classe è formata da:
    - Attributi: Variabili che rappresentano lo stato dell'oggetto.
    - Metodi: Funzioni che definiscono il comportamento dell'oggetto.

NB; I metodi possono essere usati solo da oggetti della classe. (Non posso usare metodi della classe su variabili NON della classe)

Ogni Attributo e Metodo può avere un livello di accesso:
    - Public: Accessibile da qualsiasi parte del programma.
    - Private: Accessibile solo all'interno della classe.

NB: Attributi e metodi nel private non possono essere usati direttamente da oggetti esterni alla classe.
    Per accedere a questi attributi/metodi si usano i metodi public.

Per accedere agli attributi e metodi di un oggetto si usa l'operatore punto (.):
    NomeClasse oggetto; // Puo essere inizializzato anche con parametri 
    oggetto.attributo;
    oggetto.metodo(parametri);


    Esempio di utilizzo:

    class Persona {
        private:
            string nome;
            int eta;

        public:
            // Costruttore
            Persona(string n, int e) {
                nome = n;
                eta = e;
            }

            string getNome() {
                return nome;
                }

            // Metodo setter
            void setEta(int e) { eta = e; }

            // Metodo per stampare
            void saluta() {
                cout << "Ciao, sono " << nome << " e ho " << eta << " anni." << endl;
            }
        };

        int Persona::getEta() {             //Posso definire anche funzioni fuori dalla classe
            return eta;
            } 

        // Nel main:
        Persona p("Marco", 25);      // Creo un oggetto
        p.saluta();                  // Output: Ciao, sono Marco e ho 25 anni.
        cout << p.getNome();         // Output: Marco
        p.setEta(26);                // Modifico eta tramite setter


NB: Un metodo molto importante è il costruttore, che viene chiamato automaticamente quando si crea un oggetto della classe.
    Serve per inizializzare gli attributi dell'oggetto.
    Il costruttore puo avere o non avere parametri.
    ES: 
        class Persona {
            public:
                Persona(string n, int e) { // Costruttore con parametri
                    nome = n;
                    eta = e;
                }
                Persona() { // Costruttore senza parametri
                    nome = "Sconosciuto";
                    eta = 0;
                }
        };



NB2: Posso usare i puntatori anche sulle classi:
        Persona* p = new Persona("Luca", 30); // Creo un oggetto dinamicamente
        p->saluta();                          // Uso l'operatore freccia (->) per accedere ai metodi
        delete p;                             // Dealloco la memoria


*/

/*Puntatori:

    I puntatori è un tipo di dati che lavora con gli indirizzi di memoria delle variabili.
    Esistono puntatori di vari tipi, in base al tipo di dato a cui puntano. (int*, char*, double*, ecc... oppure void*)

    Per dichiarare un puntatore si usa l'operatore asterisco (*):
                                TipoDato* nomePuntatore;
                                nomePuntatore = &variabile;      // L'operatore & restituisce l'indirizzo di memoria della variabile
                                                                 NB: L'operatore & si usa per ottenere l'indirizzo della variabile (IMPORTANTE)
    Posso accedere al valore puntato usando l'operatore di dereferenziazione (*):
                                *nomePuntatore = valore_CosaVoglioFare;          

    Devo fare sempre ricordare che il puntatore è legato all'indirizzo di memoria della variabile a cui punta.
    ES:
        int var = 10;
        int* p = &var;    // pVar punta all'indirizzo di var
        *p = 20;          // Modifica il valore di var tramite il puntatore
        var = 30;         // Modifica il valore di var direttamente

        cout<< var;  // Stampa 30
        cout<<*p;    // Stampa 30 !!!    
    

    NB: 1) Posso passare puntatori ad altri puntatori:
            TipoDato* nomePuntatore1;
            TipoDato* nomePuntatore2;
            ...
            nomePuntatore2 = nomePuntatore1;      // Ora entrambi puntano alla stessa variabile

           Attenzione perche se cancello uno dei due puntatori, l'altro non sarà più usabile -> "Segmentation fault"


        2) Posso avere puntatori a puntatori:
            TipoDato** nomePuntatoreAPuntatore;
            ...
            nomePuntatoreAPuntatore = &nomePuntatore1;   // Puntatore a puntatore

        E cosi via...


        3) I puntatori possono essere usati per creare strutture dati dinamiche (es. array dinamici, liste collegate, ecc.)
             TipoDato* nomePuntatore = new TipoDato[dimensione];   // Allocazione dinamica di un array
             TipoDato* nomePuntatoreSingolo = new TipoDato;        // Allocazione dinamica di una singola variabile

             (In memoria ho un puntatore che punta ad un'area di memoria allocata dinamicamente e posso usarlo come una varibile normale)
                Per deallocare la memoria uso il comando:
                    delete[] nomePuntatore;        // Per array dinamici
                    delete nomePuntatoreSingolo;   // Per singole variabili
           
                    
        4) Esistono i puntatori costanti, cioè che non possono essere modificati.
            TipoDato* const nomePuntatoreCostante = &variabile;   // Il puntatore non può essere modificato per puntare ad un'altra variabile

           Se provo a fare:
                nomePuntatoreCostante = &altraVariabile;   // Errore di compilazione

    Fun fact: (pag 7-8) Quando si usa il passaggio per riferimento nelle funzioni, il programma in realtà utilizza i puntatori per accedere alle variabili originali.
                Quindi, quando si passa una variabile per riferimento, si sta effettivamente passando L' INDIRIZZO di memoria della variabile alla funzione.
                Questo permette alla funzione di modificare direttamente la variabile originale senza creare una copia separata.

    RICORDA: I PUNTATORI UNA VOLTA CREATI VANNO SEMPRE DISTRUTTI ALLA FINE CON IL COMANDO "delete" (o "delete[]" per array) PER EVITARE MEMORY LEAKS! 
*/


const int N = 5; // Numero massimo di voti per studente


// Classe Studente
class Studente {
private:
    string nome;
    int eta;
    double voti[N];      // Array dinamico di voti
    int numVoti;

public:
    // Costruttore
    Studente(string n, int e, int nVoti) {
        nome = n;
        eta = e;
        numVoti = nVoti;
        for (int i = 0; i < numVoti; i++) {
            voti[i] = 0.0;
        }
        cout << "Costruttore chiamato per: " << nome << endl;
    }

    // Metodi 
    void setVoto(int indice, double voto) {
        if (indice >= 0 && indice < numVoti) {
            voti[indice] = voto;
        }
    }

    string getNome() { return nome; }

    int getEta() { return eta; }

    // Calcola media voti
    double calcolaMedia() {
        double somma = 0;
        for (int i = 0; i < numVoti; i++) {
            somma += voti[i];
        }
        return somma / numVoti;
    }

    void stampaStudente(Studente s); // Dichiarazione funzione

    // Stampa informazioni
    void stampaInfo(){
        cout << "Nome: " << nome << ", Eta: " << eta << endl;
        cout << "Voti: ";
        for (int i = 0; i < numVoti; i++) {
            cout << voti[i] << " ";
        }
        cout << "\nMedia: " << calcolaMedia() << endl;
    }
};

// Funzione che riceve un puntatore a Studente
void modificaEta(Studente* s, int nuovaEta) {
    // Accesso ai membri tramite operatore freccia ->
    cout << "Modifico eta di " << s->getNome() << endl;
}

// Funzione che riceve un riferimento a Studente
void Studente::stampaStudente(Studente s) {
    s.stampaInfo();
}

int main() {
    cout << "=== ESEMPIO 1: Oggetto su stack ===" << endl;
    Studente s1("Mario", 20, 3);
    s1.setVoto(0, 28);
    s1.setVoto(1, 30);
    s1.setVoto(2, 25);
    s1.stampaInfo();

    cout << "\n=== ESEMPIO 2: Puntatore a oggetto ===" << endl;
    Studente* s2 = new Studente("Luigi", 22, 4);
    s2->setVoto(0, 27);
    s2->setVoto(1, 29);
    s2->setVoto(2, 30);
    s2->setVoto(3, 26);
    s2->stampaInfo();

    cout << "\n=== ESEMPIO 3: Array di puntatori ===" << endl;
    Studente* classe[3];
    classe[0] = new Studente("Anna", 21, 2);
    classe[1] = new Studente("Paolo", 23, 2);
    classe[2] = new Studente("Sara", 20, 2);

    for (int i = 0; i < 3; i++) {
        classe[i]->setVoto(0, 25 + i);
        classe[i]->setVoto(1, 28 + i);
    }

    cout << "\nStampa classe:" << endl;
    for (int i = 0; i < 3; i++) {
        classe[i]->stampaInfo();
        cout << "---" << endl;
    }

    cout << "\n=== ESEMPIO 4: Puntatore vs Riferimento ===" << endl;
    Studente* ptr = &s1;           // Puntatore a s1
    Studente& ref = s1;            // Riferimento a s1
    
    cout << "Accesso tramite puntatore: " << ptr->getNome() << endl;
    cout << "Accesso tramite riferimento: " << ref.getNome() << endl;

    cout << "\n=== PULIZIA MEMORIA ===" << endl;
    delete s2;  // Dealloca singolo oggetto
    
    for (int i = 0; i < 3; i++) {
        delete classe[i];  // Dealloca ogni oggetto nell'array
    }



}


//SE NON SIETE ANCORA SICURI OPPURE NON AVETE ANCORA CAPITO QUALCOSA
//POTETE SEGUIRE QUESTO LINK PER ULTERIORI SPIEGAZIONI ED ESEMPI: 
//=================================================================
//                                                                |
//          https://www.w3schools.com/cpp/default.asp             |
//                                                                |
//=================================================================

/*              Good Luck per l'esame finale! :)

⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠞⠛⠉⢙⡛⣶⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣴⠋⠀⠀⠀⢰⠁⠀⠀⠉⢻⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⠇⠀⠀⠀⠀⠘⠀⠀⠀⠀⠀⠹⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡟⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠜⢹⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣶⡶⠶⠮⠭⠵⢖⠒⠿⢤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣠⡶⠿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠲⣄⡀⠀⠀⠀⠀⠀⣰⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⢀⣴⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠚⠿⡷⣄⣀⣴⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⣠⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠪⣻⣄⠀⠀⠀⣀⣀⠤⠴⠒⠚⢋⣭⣟⣯⣍⠉⠓⠒⠦⠤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣼⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⡝⣧⠔⠋⠁⠀⣀⠤⠔⣶⣿⡿⠿⠿⠿⠍⠉⠒⠢⢤⣀⠈⠑⠦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⣼⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡦⠤⢤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣞⣧⠤⠒⠉⠀⠀⠾⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢲⣴⣾⣷⢤⡀⠀⠀⠀⠀⠀⠀⠀
⢰⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡜⠀⠀⠀⠀⠈⠙⠳⢦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣾⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠟⢿⣿⣧⠙⢦⠀⠀⠀⠀⠀⠀
⡜⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠿⣦⣄⡀⠀⠐⢄⠀⠀⠀⢻⡇⠀⠀⠀⠀⡠⢊⣭⣬⣭⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⢿⡀⠀⠑⣄⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣦⡀⠀⠑⢄⣀⢿⠇⠀⠀⠀⡜⣼⠟⠁⠀⠀⠉⢿⡄⠀⠀⠀⠀⣠⠤⠤⠤⣀⡀⠈⠙⡄⠀⠈⢆⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⣝⢦⡀⠀⣠⡞⠢⢄⠀⡜⣼⠁⣠⣴⣶⢦⡀⠀⢻⠀⠀⢀⣎⡴⠟⠛⠛⠶⣝⢦⠀⠘⡄⠀⠈⢧⠀⠀
⢢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣧⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢦⢻⡾⠋⠀⣀⣀⠁⠁⡇⢰⢿⣄⣿⣎⢷⠀⢸⡇⠀⢸⡝⢀⣤⣄⡀⠀⠙⢷⡀⠀⢱⠀⠀⠈⡇⠀
⠸⡆⠀⠀⠀⠀⠀⠀⠀⠀⡸⠀⠀⠈⠙⣳⢦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠟⣧⠀⢀⣀⣀⡉⠱⣿⣼⣆⢿⠻⣯⡞⠀⢸⡇⠀⢸⣷⣏⢙⣿⡻⡆⠀⠀⢳⠀⠀⠀⠀⠀⢸⡀
⠀⢳⡀⠀⠀⠀⠀⠀⠉⠚⠁⠀⠀⠀⠀⠀⠉⠻⢿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⣰⡏⠈⠁⠀⠀⠉⠢⠈⠛⢻⣿⠿⠛⠁⢀⣿⠇⠀⠈⣿⣿⢿⡟⣧⡷⠀⠀⢸⡄⠀⠀⠀⠀⠈⡇
⠀⠈⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⢧⡀⠀⠀⠀⠢⠤⠔⡽⠁⠚⠉⠉⠉⢗⢷⣄⡠⣀⢻⣆⣀⣠⡿⠋⠀⠀⠀⠈⢿⡷⠿⠟⠁⠀⠀⣼⠀⠀⠀⠀⠀⠀⢱
⠀⠀⠀⠻⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢣⠻⡄⠀⢀⣀⡤⠞⠁⠀⠀⠀⠀⠀⠘⢦⡈⠁⠀⠀⠸⡟⠉⠀⠀⠀⠀⠀⠀⠀⠙⢦⣀⣤⡶⠟⠉⠙⠒⠀⠀⠀⠀⢘
⠀⠀⠀⠀⠈⠳⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⡀⠀⡇⣿⠛⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣤⡀⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⢠⠞⠍⠠⠤⠒⠂⢄⠀⠀⠀⠀⠀⢸
⠀⠀⠀⠀⠀⠀⠈⠙⠲⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢀⣽⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⡉⠓⠦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣉⡿⠓⠲⠄⠀⠀⠀⠀⡆
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠶⢤⣤⣄⣀⣠⣤⡤⠶⠛⣿⡀⠀⢢⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣿⣄⠀⠀⠉⠙⠒⠲⠤⠤⠤⣤⣤⡤⠖⠚⠁⠀⠀⠀⠀⠀⠀⠀⢰⠃
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣷⠀⠀⠱⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿⣿⣦⣄⡀⠀⠀⠀⢀⣼⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡞⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣧⡀⠀⠙⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢫⠙⢻⣿⣿⣿⣿⣿⣿⣿⣿⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡼⠁⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⡱⡀⠀⠀⠣⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠳⣔⢹⡉⢻⣿⣿⣿⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡞⠁⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣆⠀⠀⠈⠢⡀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠳⣥⣠⣹⣿⡿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠞⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⣕⢄⠀⠀⠈⠂⠀⠀⠀⠀⠀⠀⠀⠈⠓⠢⠌⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠃⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⢷⡦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠔⠋⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠺⢕⣦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠴⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⠻⠤⢄⣀⣀⣀⣀⣀⣀⣠⠤⠴⠒⠊⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀



*/