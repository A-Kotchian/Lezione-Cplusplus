// #include <vector>
// #include <iostream>

// using namespace std;


// int numero_elementi(vector <int> v){

//     int numero = 0;
//     int mu=0;
//     for(int i=0; i<v.size(); i++){
//         mu=mu+v[i];
//     }
//     mu=mu/v.size();

//     for(int i=0; i<v.size(); i++){
//         if(v[i]>mu){
//             numero++;
//         }
//     }

//     return numero;
// }


// int main(){

//     vector <int> v={3, 2, 4, 1, 7, 6, 5};
//     cout<<"Numero di elementi maggiori della media: "<<numero_elementi(v)<<endl;
// }




// #include <iostream>
// #include <vector>
// using namespace std;

// const int N= 3;
// const int M= 4;

// vector <double> numeri_grandi(double A[M][N]){
//     vector <double> grandi;
//     for(int i=0; i<M; i++){         // Scorro le righe
//         double massimo= 2e-11;
//         //double massimo= A[0][i];
//         for(int j=0; j<N; j++){     // Scorro le colonne

//             if(A[i][j]>massimo){
//                 massimo= A[i][j];
//             }
//         }
//         grandi.push_back(massimo);
//     }
//     return grandi;
// }


// int main(){

//     double A[M][N]={{1,2,3},{4,5,-6},{7,-9,8},{12,11,-13}};
//     vector <double> grandi= numeri_grandi(A);

//     cout<<"Numeri grandi"<<endl;
//     for(int i=0; i<grandi.size(); i++){
//         cout<<grandi[i]<<" ";
//     }

// }



#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


struct Sfera{
    string nome;
    double raggio;
    double x;
    double y;
    double z;
};

class Insieme_Sfere{
    private:
        vector <Sfera> insieme;
    public:
        
        Insieme_Sfere(){
            vector <Sfera> insieme;
            insieme.clear();
        }

        bool inserisci(string nm, double x, double y, double z, double r){
            if(insieme.size()>0){
                for(int i =0; i<insieme.size(); i++){
                    //sfera si riferisce alla sfera gia presente nell'insieme e non quella da inserire
                    double sfera_x=insieme[i].x;
                    double sfera_y=insieme[i].y;
                    double sfera_z=insieme[i].z;
                    double sfera_r=insieme[i].raggio;
                    double distanza_centri= sqrt( pow((x - sfera_x),2) + pow((y - sfera_y),2) + pow((z - sfera_z),2) );
                    if(distanza_centri <= (sfera_r+r)){
                        return false;
                    }
                }
            }

            Sfera s;
            s.nome= nm;
            s.x= x;
            s.y= y;
            s.z= z;
            s.raggio= r;
            insieme.push_back(s);
            return true;
        }

        void visualizza(){

            if(insieme.size()==0){
                cout<<"Insieme vuoto!"<<endl;
            }
            else{
            for(int i=0; i<insieme.size();i++){
                cout<<"Sfera n°"<<i<<endl;
                cout<<"Nome: "<<insieme[i].nome<<endl;
                cout<<"Raggio: "<<insieme[i].raggio<<endl;
                cout<<"Centro: ("<<insieme[i].x<<", "<<insieme[i].y<<", "<<insieme[i].z<<")"<<endl;
                cout<<endl;
                }
            }
        }

        double volume_totale(){

            double volume=0;
            for(int i=0; i<insieme.size(); i++){
                volume=volume+ (4.0/3.0)*M_PI*pow(insieme[i].raggio, 3);
            }
            return volume;
        }


        vector <string> sfere_grandi(double r0){
            vector <string> grandi;
            for(int i=0; i<insieme.size(); i++){
                if(insieme[i].raggio >= r0){
                    grandi.push_back(insieme[i].nome);
                }
            }
            return grandi;
        }
};


int main(){

    Insieme_Sfere insieme_di_sfere;
    insieme_di_sfere.visualizza();
    cout<<endl;
    bool inserita;
    inserita=insieme_di_sfere.inserisci("Sfera1", 0,0,0, 2);
    inserita=insieme_di_sfere.inserisci("Sfera2", 5,5,5, 3);
    inserita=insieme_di_sfere.inserisci("Sfera3",10,10,10,2);
    insieme_di_sfere.visualizza();
    cout<<endl;


    cout<<"Volume totale: "<<insieme_di_sfere.volume_totale()<<endl;
    cout<<endl;

    inserita=insieme_di_sfere.inserisci("Sfera4",1,1,1,2);

    if(inserita==false){
        cout<<"Una sfera non inserita perche si interseca con un'altra sfera presente nell'insieme."<<endl;
    }
    cout<<endl;

    vector <string> grandi= insieme_di_sfere.sfere_grandi(2.5);
    cout<<"Sfere con raggio maggiore o uguale a 2.5:"<<endl;
    for(int i=0; i<grandi.size(); i++){
        cout<<grandi[i]<<endl;
    }
    
}





