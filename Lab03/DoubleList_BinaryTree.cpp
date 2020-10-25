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
    cout << "Sifra" << "\t" << "Ime i prezime" << "\t" << "Naslov" << "\t" 
        << "Vrijeme unosa" << "\t" << "Next addr" << endl;
    while(current != NULL){
        cout <<"----------------------------------------------------------------------" << endl;
        cout << current->sifra << "\t" << current->ime_prez << "\t" << current->naslov << "\t" 
            << current->vrijeme_unosa << "\t" << current->next << endl;
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
     cout << "Sifra" << "\t" << "Ime i prezime" << "\t" << "Naslov" << "\t" 
        << "Vrijeme unosa" << "\t" << "Next addr" << endl;
    while(temp != head){
        cout <<"----------------------------------------------------------------------" << endl;
        cout << temp->sifra << "\t" << temp->ime_prez << "\t" << temp->naslov << "\t" 
            << temp->vrijeme_unosa << "\t" << temp->next << endl;
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
        
    }
    cout << "ISPISUJEM..." << endl;
    ispis_tail(head);
}

// delete node
void deleteNode(pisac_t *head, int sifra){
    pisac_t *current = head->next;
    pisac_t *previous = head;

    // find node that needs to be deleted
    if(current == NULL){                        // do you really need this ???
            cout << "Lista je prazna!" << endl;
    }
    else{
        while(current != NULL){
            if(current->sifra == sifra){
                // change pointers
                previous->next = current->next; // connect previous node to next node
                current->prev = previous; // connect next node to previous
                // delete node
                delete current;
                cout << "Node deleted" << endl;
                break;
            }
            else{
                current = current->next;
                previous = previous->next;
            }
            if(current == NULL){                // do you really need this ???
                cout << "Nema takvog zapisa!" << endl;
            }
        }
    }
}

// print binary tree
void print_tree(pisac_t *root){
    static pisac_t *korijen = root;
    if(root == NULL){
        return;
    }
    print_tree(root->prev);
    if(root!=korijen){
        cout <<"----------------------------------------------------------------------" << endl;
        cout << root->sifra << "\t" << root->ime_prez << "\t" << root->naslov << "\t" 
            << root->vrijeme_unosa << "\t" << root->next << endl;
        cout <<"----------------------------------------------------------------------" << endl;
    }
    print_tree(root->next);
}

// add note to binary tree
void add_to_binary_tree(pisac_t *root){
    pisac_t *help = root;
    bool failed = true;

    pisac_t *novi = new pisac_t;
    cout << "UNOS U BINARNO STABLO" << endl;
    vrijeme_pocetak();
    cout << "Unesi sifru autora: ";
    cin >> novi->sifra;
    cout << "Unesi ime i prezime autora: ";
    unos(novi->ime_prez);
    cout << "Unesi naslov: ";
    unos(novi->naslov);
    vrijeme_kraj();
    novi->vrijeme_unosa = vrijeme_proteklo()/1000;

    do{
        if(novi->sifra > help->sifra){
            if(help->next != NULL){
                help = help->next;
            }
            else{
                help->next = novi;
                novi->next = NULL;
                novi->prev = NULL;
                failed = false;
            }
        }
        else{
            if(help->prev != NULL){
                help = help->prev;
            }
            else{
                help->prev = novi;
                novi->prev = NULL;
                novi->next = NULL;
                failed = false;
            }
        }
    }while(failed == true);
}


int kljuc(){
    int sifra;
    cout << "Unesi sifru: ";
    cin >> sifra;
    return sifra;
}


int main(){

// head pointer for doubly linked list
pisac_t *head = new pisac_t;
head->next = NULL;
head->prev = NULL;

// root pointer for binary tree
pisac_t *root = new pisac_t;
root->next = NULL; // using it as root right
root->prev = NULL; // using it as root left

int jos;
do{
    cout <<"----------------------------------------------------------------------" << endl;
    cout << "1. Dodavanje elementa na kraj dvostruko vezane liste, ispis liste od početka" << endl;
    cout << "2. Dodavanje elementa na početak dvostruko vezane liste, ispis liste od kraja" << endl;
    cout << "3. Brisanje čvora iz dvostruko vezane liste" << endl;
    cout << "4. Dodavanje novog čvora u binarno stablo, ispis čvorova stabla" << endl;
    cout << "5. Brisanje cvora iz binarnog stabla, ispis cvorova" << endl;
    cout << "9. Izlaz iz programa" << endl;
    cout <<"----------------------------------------------------------------------" << endl;
    cin >> jos;
    switch(jos){
        case 1:
            add_at_end(head);
            break;
        case 2:
            add_at_start(head);
            break;
        case 3:
            deleteNode(head,kljuc());
            cout << "ISPIS LISTE..." << endl;
            ispis_head(head);
            break;
        case 4:
            add_to_binary_tree(root);
            print_tree(root);
            break;
        case 5:
            // delete node from tree
            break;
    }
}while(jos != 9);
 
 
    return 0;
}
