#include <iostream>
#include "biblioteka_vrijeme.cc"        
using namespace std;
 

struct pisac_t{
    int sifra;
    char ime_prez[50];
    char naslov[50];
    double vrijeme_unosa;
    pisac_t *left;
    pisac_t *right;
};

void add_to_list_at_end(pisac_t *head){
    pisac_t *current = head;
    pisac_t *novi;

    while(current->right){
        current = current->right;
    }

    novi = new pisac_t;
    novi->left = current;
    novi->right = NULL;
    current->right = novi;
    vrijeme_pocetak();
    cout << "Unesi sifru autora: ";
    cin >> novi->sifra;
    cout << "Unesi ime i prezime autora: ";
    unos(novi->ime_prez);
    cout << "Unesi naslov djela: ";
    unos(novi->naslov);
    vrijeme_kraj();
    novi->vrijeme_unosa = vrijeme_proteklo()/1000;



    while(head->right != NULL){
        cout <<"----------------------------------------------------------------------" << endl;
        cout << "Sifra autora: " << head->sifra << endl;
        cout << "Ime i prezime: " << head->ime_prez << endl;
        cout << "Naslov: " << head->naslov << endl;
        cout << "Vrijeme unosa: " << head->vrijeme_unosa << endl;
        cout <<"----------------------------------------------------------------------" << endl;
        head = head->right; 
    }

}


void add_to_list_at_start(pisac_t *head){

    if(head->right == NULL){
        add_to_list_at_end(head);
        return;
    }

    else{
        pisac_t *current = head->right;
        pisac_t *novi = new pisac_t;

        vrijeme_pocetak();
        cout << "Unesi sifru autora: ";
        cin >> novi->sifra;
        cout << "Unesi ime i prezime autora: ";
        unos(novi->ime_prez);
        cout << "Unesi naslov: ";
        unos(novi->naslov);
        vrijeme_kraj();
        novi->vrijeme_unosa = vrijeme_proteklo()/1000;

        novi->left = head;
        novi->right = current;
        head->right = novi;
        current->left = novi;

        pisac_t *tail;
        while(current){
            current = current->right;
        }
        tail = current;

        while(tail->left){
            cout <<"----------------------------------------------------------------------" << endl;
            cout << "Sifra autora: " << head->sifra << endl;
            cout << "Ime i prezime: " << head->ime_prez << endl;
            cout << "Naslov: " << head->naslov << endl;
            cout << "Vrijeme unosa: " << head->vrijeme_unosa << endl;
            cout <<"----------------------------------------------------------------------" << endl;
            tail = tail->left;
        }

    }
    
}



int main(){

pisac_t *head = new pisac_t;
head->left = NULL;
head->right = NULL;


int jos;
do{
    cout <<"----------------------------------------------------------------------" << endl;
    cout << "1. Dodavanje elementa na kraj dvostruko vezane liste, ispis liste od početka" << endl;
    cout << "2. Dodavanje elementa na početak dvostruko vezane liste, ispis liste od kraja" << endl;
    cout << "3. Brisanje čvora iz dvostruko vezane liste" << endl;
    cout << "4. Dodavanje novog čvora u binarno stablo, ispis čvorova stabla" << endl;
    cout << "9. Izlaz iz programa" << endl;
    cout <<"----------------------------------------------------------------------" << endl;
    cin >> jos;
    switch(jos){
        case 1:
            add_to_list_at_end(head);
            break;
        case 2:
            add_to_list_at_start(head);
            break;
        case 3:
            
            break;
        case 4:
            
            break;
    }
}while(jos != 9);
 
 
    return 0;
}
 