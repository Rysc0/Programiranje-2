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
                cout << "Dealokacija: " << help->sifra << endl;
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
            double iznos;
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

void alokacija(){

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
            break;
        case 4:
            // function
            break;
    }
}while(jos != 9);
 
 
    return 0;
}