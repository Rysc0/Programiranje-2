#include <iostream>
#include "biblioteka_vrijeme.cc"
#include <cmath>
#include <cstdlib>
#include <iomanip>
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
			//srand(time(NULL));
			vrijeme_unosa.pocetak();
			sifra_trokuta = rand()%1000+1;
			a = rand()%10+1;
			b = rand()%10+1;
			c = rand()%10+1;
			broj_unesenih++;
			vrijeme_unosa.kraj();
		
		//	cin >>  sifra_trokuta >> a >> b >> c;

		
		}
	
		void ispis_trokuta(){
			cout << sifra_trokuta << "\t" << a << "\t" << b << "\t" <<  c 
			<<  "\t" << povrsina_trokuta() << "\t" << vrijeme_unosa.proteklo() << endl;
		}
		
		int statistika(){
			int broj_trokuta = 0;
		
				if(povrsina_trokuta() > 0)
					broj_trokuta++;
			return broj_trokuta;
			
		}
};		

		

int trokut::broj_unesenih = 0;

trokut instanca[50];

 
int main(){

srand(time(NULL));
int trokuta = 0;
int broj = 0;
int br = 0;
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
						
            for(int i = 0; i < 50; i++){
			//	cout << "uso sam" << ++broj << " puta" << endl;
            	instanca[i].unos_trokuta();
			}
            break;
        case 2:
            // function
            for(int i = 0; i < 50; i++){
			//	cout << "uso sam" << ++br << " puta" << endl;
				if(instanca[i].povrsina_trokuta() > 0)
            		instanca[i].ispis_trokuta();
			}
            break;
        case 3:
            // function
            cout << "Uneseno je: " << trokut::broj_unesenih << " trokuta a njih ";
            for(int i = 0; i < 50; i++){
            	if(instanca[i].povrsina_trokuta() > 0)
            		trokuta++;
			}
			cout << trokuta << endl;
			trokuta = 0;
            break;
        case 4:
            // function
            break;
    }
}while(jos != 9);
 
 
    return 0;
}
