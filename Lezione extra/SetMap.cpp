#include <iostream>
#include <set>
#include <map>
#include <string>


using namespace std;

/*Teoria:  (Pag 18: "dispense_labinfII.pdf")
    Un insieme (set) è una struttura dati che consente di svolgere velocemente le operazioni di ricerca,
    inserimento e cancellazione.(Metodo molto veloce)

    Viene schematizzato come un albero formato da piu nodi-> Lista bidimensionale

    Bisogna includere la libreria <set> per utilizzare gli insiemi in C++.
    Comandi utili:

        *Creazione di un set:
                                set<TipoDato> nomeSet;
        *Inserimento di un elemento:
                                nomeSet.insert(valore);
        *Rimozione di un elemento:
                                nomeSet.erase(valore);
        *Ricerca di un elemento:
                                nomeSet.find(valore); 
        *Dimensione del set:
                                nomeSet.size();

    NB: Gli elementi SONO UNICI E IN ORDINE


    ------------------------------------------------------------------------------------------------------------------------------
    
    Le mappe (map) sono una generalizzazione del concetto di array.
    Una mappa è invece è un'applicazione che ad ogni chiave, appartenente ad un generico insieme
    finito X, associa un valore appartenente ad un insieme Y.
    
    Dal punto di vista implementativo le mappe sono realizzate in modo
    simile a quanto visto per i set, ovvero con alberi binari di ricerca. 
    Ogni elemento della mappa è però visto come una coppia (chiave,valore).

    (Le map le puoi vedere come 2 array che lavorano in coppia: uno per le chiavi ed uno per i valori associati a quelle chiavi)
    
    Bisogna includere la libreria <map> per utilizzare le mappe in C++.
    Comandi utili:

        *Creazione di una mappa:
                                map<TipoChiave, TipoValore> nomeMappa;      NB!!!!!
        *Inserimento di una coppia chiave-valore:
                                nomeMappa[chiave] = valore;
                                oppure
                                nomeMappa.insert({chiave, valore});
        *Rimozione di una coppia chiave-valore:
                                nomeMappa.erase(chiave);
        *Accesso al valore associato ad una chiave:
                                nomeMappa[chiave];
        *Verifica esistenza di una chiave:
                                nomeMappa.count(chiave);
        *Dimensione della mappa:
                                nomeMappa.size();
        *Per ottenere un valore:
                                valore = nomeMappa[chiave];
        *Puoi ricavare chiave e valore con:
                                nomeMappa->first  (chiave)
                                nomeMappa->second (valore)
        *Primo e ultimo elemento:
                                nomeMappa.begin()
                                nomeMappa.end()
        

*/


int main() {
    // Esempio di set

    cout<<endl;
    cout<<"-----------------SET-----------------"<<endl;
    set<int> numeri;
    
    // Inserimento elementi (i duplicati vengono ignorati)
    numeri.insert(5);
    numeri.insert(2);
    numeri.insert(8);
    numeri.insert(2);  // Duplicato, non verrà inserito
    numeri.insert(1);
    
    // Stampa degli elementi (ordinati automaticamente)
    cout << "Elementi nel set: ";
    for (int n : numeri) {
        cout << n << " ";
    }
    cout << endl;
    
    // Ricerca di un elemento
    int cerca = 5;
    if (numeri.find(cerca) != numeri.end()) {
        cout << cerca << " è presente nel set" << endl;
    }
    else {
        cout << cerca << " non è presente nel set" << endl;
    }
    
    // Rimozione di un elemento
    numeri.erase(2);
    cout << "Dopo la rimozione di 2: ";
    for (int n : numeri) {
        cout << n << " ";
    }
    
    cout << "\nDimensione del set: " << numeri.size() << endl;
    cout << endl;
    

//--------------------------------------------------------------------------------
    cout<<endl;
    cout<<"-----------------MAP-----------------"<<endl;

    // Esempio di map
    map<string, int> voti;
    
    // Inserimento coppie chiave-valore
    voti["Mario"] = 28;
    voti["Luigi"] = 30;
    voti["Anna"] = 25;
    voti.insert({"Paolo", 27});
    
    // Stampa degli elementi (ordinati per chiave)
    cout << "Voti degli studenti:" << endl;
    
    //Potresti usare gli iteratori al posto di auto nel for
    for (auto i = voti.begin(); i != voti.end(); ++i) {
        cout << i->first << ": " << i->second << endl;                      // NB: i->first è la chiave, i->second è il valore
    }
    
    // Accesso a un elemento
    cout << "Voto di Luigi: " << voti["Luigi"] << endl;
    
    // Verifica esistenza di una chiave
    string studente = "Anna";
    if (voti.count(studente) > 0) {
        cout << studente << " si presenta con voto " << voti[studente] << endl;
    }
    
    // Modifica di un valore
    voti["Mario"] = 30;
    cout<<"Modifica voto: "<<endl;
    cout << "Nuovo voto di Mario: " << voti["Mario"] << endl;
    
    // Rimozione di un elemento
    voti.erase("Paolo");
    
    // Dimensione delle strutture
    cout << "Dimensione della map: " << voti.size() << endl;
    
}