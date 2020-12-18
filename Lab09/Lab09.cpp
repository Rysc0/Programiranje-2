#include <iostream>
#include "biblioteka_vrijeme.cc"

using namespace std;
  
class stavka{
    // private:
    //     stavka* next;

    public:
        int sifra;
        char naziv[20];
        float cijena;
        int kolicina;
        stavka *next;

        // konstruktor
        stavka(){
            cout << "Alociram element liste..." << endl;
            next = NULL;
        }

        // dekonstruktor
        ~stavka(){
            cout << "Unistio sam: " << this->sifra << endl;
        }
        // nekako radi, samo ne diraj
        void deleteList(){  
            stavka *current = this->next;
            while(current != NULL){
                stavka *help = current;
               
                current = current->next;
                // cout << "Dealokacija: " << help->sifra << endl;
                delete help;
                
            }
            delete current; 
            this->next = NULL;   
        }

        void unos_u_listu(){
            stavka *novi, *zadnji;
            zadnji = this;
            while(zadnji->next)
                zadnji = zadnji->next;

            novi = new stavka;
            zadnji->next = novi;
            cout << "Sifra: ";
            cin >> novi->sifra;
            cout << "Naziv: ";
            cin >> novi->naziv;
            cout << "Cijena: ";
            cin >> novi->cijena;
            cout << "Kolicina: ";
            cin >> novi->kolicina;
            // novi->next = NULL; // obrisi poslje ak ne popravi destruktora
            // linija nije potrebna, al nek ostane za sad
        }

        void ispis_liste(){
            stavka *current = this->next;
            double iznos = 0;
            cout << "Sifra\t" << "Naziv\t" << "Cijena\t" << "Kolicina\t" << endl;
            cout << "------------------------------------------" << endl;
            while(current){
                cout << "Sifra: " << current->sifra << endl;
                cout << "Naziv: " << current->naziv << endl;
                cout << "Cijena: " << current->cijena << endl;
                cout << "Kolicina: " << current->kolicina << endl;
                iznos += (current->cijena * current->kolicina);
                current = current->next;
                cout << "------------------------------------------" << endl;
            }
            cout << "Iznos = " << iznos << endl;
            // this->~stavka();
        }

         
};

stavka *lista;
stavka **pointer_array;



void operacija(){
    int kljuc;
    do{
        cout << "Unesi broj liste (0-9): ";
        cin >> kljuc;
    }
    while (kljuc<0 || kljuc>9);
        
    pointer_array[kljuc]->unos_u_listu();
    pointer_array[kljuc]->ispis_liste();
    
}

void alokacija_polja(){
    cout << "ALOKUJEM" << endl;
    pointer_array = new stavka*[10];
    for(int i = 0; i < 10; i++){
        pointer_array[i] = new stavka;
    }
    cout << "gotovo..." << endl;
}

void arrayCheck(){
    if(pointer_array) cout << "DA" << endl;
    else alokacija_polja();
    operacija();
}

void dealokacija_svih(){
    for(int i = 0; i < 10; i++){
        if(pointer_array[i]->next){
            pointer_array[i]->deleteList();
        }
    }
    // for(int i = 0; i < 10; i++){
    //     delete pointer_array[i];
    // }
    delete pointer_array;
}


int main(){

// alokacija glave liste
lista = new stavka;
// lista->next = NULL;



int jos;
do{
    cout <<"----------------------------------------------------------------------" << endl;
    cout << "1. Alokacija glave pojedine vezane liste, unos pojedinog elementa liste, ispis svih elemenata liste" << endl;
    cout << "2. Iznos (prema uputi) svih elemenata liste, dealokacija vezane liste (glava ostaje)" << endl;
    cout << "3. Alokacija polja vezanih listi/unos podataka u zadanu vezanu listu/ispis pojedine vezane liste" << endl;
    cout << "4. Dealokacija svih vezanih listi i polja" << endl;
    cout << "9. Izlaz iz programa" << endl;
    cout <<"----------------------------------------------------------------------" << endl;
    cin >> jos;
    switch(jos){
        case 1:
            // function
            lista->unos_u_listu();
            break;
        case 2:
            // function
            cout << "------------------------------------------" << endl;
            lista->ispis_liste();
            lista->deleteList();
            // lista->~stavka(); 
            break;
        case 3:
            // function
            arrayCheck();
            break;
        case 4:
            // function
            dealokacija_svih();
            break;
    }
}while(jos != 9);
 
 
    return 0;
}