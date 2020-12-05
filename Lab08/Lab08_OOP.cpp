#include <iostream>
#include "biblioteka_vrijeme.cc"
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <windows.h> // Sleep()
using namespace std;



class trokut{

	private: float s;
	private: cvrijeme vrijeme_unosa;
	
	public: 
		static int broj_unesenih;
		int sifra_trokuta;
		float a,b,c;
		
		float povrsina_trokuta(){
			s = (a+b+c)/float(2);
			float P = sqrt(s*(s-a)*(s-b)*(s-c));
			if(P < 0) return -1;
			return P;
		}
		
		void unos_trokuta(){
			vrijeme_unosa.pocetak();
			Sleep(rand()%100);
			sifra_trokuta = rand()%1000+1;
			a = rand()%10+1;
			b = rand()%10+1;
			c = rand()%10+1;
			broj_unesenih++;
			vrijeme_unosa.kraj();
		}
	
		void ispis_trokuta(){
			cout << sifra_trokuta << "\t" << a << "\t" << b << "\t" <<  c 
			<<  "\t" << setprecision(3) << povrsina_trokuta() << "\t" << vrijeme_unosa.proteklo() << endl;
		}
		
		int statistika(){
			int broj_trokuta = 0;
		
				if(povrsina_trokuta() > 0)
					broj_trokuta++;
			return broj_trokuta;
			
		}

		void swap_pages(){
			// make C the largest
			int temp = 0;
			for(int i = 0; i < 50; i++){
				if(a > b && a > c){
					temp = c;
					c = a;
					a = temp;
				}
				else if(b > c && b > a){
					temp = c;
					c = b;
					b = temp;
				}
				else continue; 	
			}
		}

		void pitagora(){
			swap_pages();
			float zbroj = sqrt(pow(a,2)+pow(b,2));
			if(c == zbroj)
				cout << sifra_trokuta << "\t" << a << "\t" << b << "\t" 
				<< c << "\t" << setprecision(3) << povrsina_trokuta() << "\t" << vrijeme_unosa.proteklo() << endl;	
		}
};		

		

int trokut::broj_unesenih = 0;

trokut instanca[50];


void input(){
	for(int i = 0; i < 50; i++){
        instanca[i].unos_trokuta();
	}
}

void ispis(){
	int broj = 0;
	cout << "Redni broj\t" << "Sifra\t" << "A\t" << "B\t" << "C\t" << "Povrsina\t" << "Vrijeme unosa" << endl;
	cout << "-------------------------------------------------------------" << endl;
	for(int i = 0; i < 50; i++){
		if(instanca[i].povrsina_trokuta() > 0){
			++broj;
			cout << broj << "\t";
            instanca[i].ispis_trokuta();
		}
	}
}

void statistika(){
	int trokuta = 0;
	cout << "Uneseno je: " << trokut::broj_unesenih << " trokuta a njih ";
    for(int i = 0; i < 50; i++){
       	if(instanca[i].povrsina_trokuta() > 0)
       		trokuta++;
		}
	cout << trokuta << endl;
	trokuta = 0;
}


void pravokutni(){
	cout << "Sifra\t" << "A\t" << "B\t" << "C\t" << "Povrsina\t" << "Vrijeme unosa" << endl;
	cout << "-------------------------------------------------------------" << endl;
	for(int i = 0; i < 50; i++){
		instanca[i].pitagora();
	}
}
 
 
int main(){

srand(time(NULL));

int jos;
do{
    cout <<"----------------------------------------------------------------------" << endl;
    cout << "1. Unos podataka o trokutima u polje trokuta" << endl;
    cout << "2. Ispis podataka o unesenim trokutima" << endl;
    cout << "3. Statistika" << endl;
    cout << "4. Prepoznavanje odredenih vrsta trokuta" << endl;
    cout << "9. Izlaz iz programa" << endl;
    cout <<"----------------------------------------------------------------------" << endl;
    cin >> jos;
    switch(jos){
        case 1:
            // function			
            input();
            break;
        case 2:
            // function
            ispis();
			break;
        case 3:
            // function
            statistika();
            break;
        case 4:
            // function
			pravokutni();
            break;
    }
}while(jos != 9);
 
 
    return 0;
}
