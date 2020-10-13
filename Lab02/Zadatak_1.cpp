#include <iostream>
#include "biblioteka_vrijeme.cc"
#include <ctime>
#include <unistd.h>
using namespace std;
 
struct pisac_t{
    int sifra;
    string ime_prez, naslov;
    int vrijeme_unosa;
    pisac_t *next;
};


pisac_t *createNode(pisac_t *head){
    pisac_t *node = new pisac_t;
    vrijeme_pocetak();
    cout << "Unesi sifru autora: ";
    cin >> node->sifra;
    cout << "Unesi ime i prezime autora: ";
    cin >> node->ime_prez;
    cout << "Unesi naslov djela: ";
    cin >> node->naslov;
    vrijeme_kraj();
    node->vrijeme_unosa = vrijeme_proteklo();
    return node;
}

pisac_t *addToList(pisac_t *head){
    pisac_t *temp;
    temp = createNode(head);
    temp->next = head;
    head = temp;
    return head;

}

void ispis(pisac_t *head){
    int sec;
    cout << "Displaying list...";
    for(int i = 0; i < 10; i++){
        sec = rand()%3;
        cout << ".";
        sleep(sec);
    }
    cout << endl;
    while(head != NULL){
        cout << head->sifra << "\n" << head->ime_prez << "\n" << head->naslov 
        << "\n" << head->vrijeme_unosa << endl << endl;
        head = head->next;
    }
}

// typedef pisac_t lista;

int main(){
srand(time(NULL));
int jos;
pisac_t *head = NULL;
pisac_t *temp;
// lista *head = NULL;
// lista *temp;
// pisac_t *node = new pisac_t;
do{
    cout <<"----------------------------------------------------------------------" << endl;
    cout << "1. Unos novog elementa vezane liste na kraj" << endl;
    cout << "2. Ispis sadržaja vezane liste zajedno sa zbrojem primatnih ključeva" << endl;
    cout << "3. Pretraživanje vezane liste (prema primarnom ključu)" << endl;
    cout << "4. Brisanje elemenata liste (prema primarnom ključu)" << endl;
    cout << "9. Izlaz iz programa" << endl;
    cout <<"----------------------------------------------------------------------" << endl;
    cin >> jos;
    switch(jos){
        case 1:
            head = addToList(head);
            break;
        case 2:
            ispis(head);
            break;
        case 3:
            //funkcija
            break;
        case 4:
            //funkcija
            break;
        case 9:
            //funkcija
            break;
    }
}while(jos != 9);
 
 
    return 0;
}