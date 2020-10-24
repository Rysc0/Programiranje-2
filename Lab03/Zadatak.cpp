#include <iostream>
#include "biblioteka_vrijeme.cc"
using namespace std;
 
struct pisac_t{
    int sifra;
    char ime_prez[50];
    char naslov[50];
    double vrijeme_unosa;
    pisac_t *next;
    pisac_t *prev;
};

// print from head
void ispis_head(pisac_t *head){
    pisac_t *current = head ->next;
    while(current != NULL){
        cout <<"----------------------------------------------------------------------" << endl;
        cout << "Sifra autora: " << current->sifra << endl;
        cout << "Ime i prezime: " << current->ime_prez << endl;
        cout << "Naslov: " << current->naslov << endl;
        cout << "Vrijeme unosa: " << current->vrijeme_unosa << endl;
        cout << "Next addr: " << current->next << endl;
        cout <<"----------------------------------------------------------------------" << endl;
        current = current->next; 
    }
}
// add_at_end
void add_at_end(pisac_t *head){
    pisac_t *current = head;
    pisac_t *novi;

    while(current->next){
        current = current->next;
    }

    novi = new pisac_t;
    novi->prev = current;
    novi->next = NULL;
    current->next = novi;
    vrijeme_pocetak();
    cout << "Unesi sifru autora: ";
    cin >> novi->sifra;
    cout << "Unesi ime i prezime autora: ";
    unos(novi->ime_prez);
    cout << "Unesi naslov djela: ";
    unos(novi->naslov);
    vrijeme_kraj();
    novi->vrijeme_unosa = vrijeme_proteklo()/1000;

    cout << "ISPISUJEM..." << endl;
    ispis_head(head);
}

// print from tail
void ispis_tail(pisac_t *head){
    pisac_t *temp = head->next;
    while(temp->next){
        temp = temp->next;
    }
    while(temp != head){
        cout <<"----------------------------------------------------------------------" << endl;
        cout << "Sifra autora: " << temp->sifra << endl;
        cout << "Ime i prezime: " << temp->ime_prez << endl;
        cout << "Naslov: " << temp->naslov << endl;
        cout << "Vrijeme unosa: " << temp->vrijeme_unosa << endl;
        cout << "Prev addr: " << temp->next << endl;
        cout <<"----------------------------------------------------------------------" << endl;
        temp = temp->prev; 
    }
    cout << "glava" << endl;
}
// add_at_start
void add_at_start(pisac_t *head){
    if(!head->next){
        add_at_end(head);
        return;
    }
    else{
        pisac_t *current = head->next;
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

        novi->prev = head;  // head <- novi element
        novi->next = current; // novi element -> current
        head->next = novi;
        current->prev = novi; // head -> novi element
        // head->left = NULL;
        // current->prev = novi; // novi element <- curren
    }
    // ispis_tail(head);
}

// delete node

// print binary tree
// add note to binary tree
 
int main(){

pisac_t *head = new pisac_t;
head->next = NULL;
head->prev = NULL;

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
            add_at_end(head);
            break;
        case 2:
            add_at_start(head);
            ispis_tail(head);
            break;
        case 3:
           
            break;
        case 4:
            
            break;
    }
}while(jos != 9);
 
 
    return 0;
}
