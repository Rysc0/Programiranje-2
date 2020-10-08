#include <iostream>
#include <string.h>
using namespace std;
 
 
struct student{
    int maticni = 30500;
    string ime_prezime = "Marko Matic";
    int godina_upisa = 2016;
    int *mat,*god;
    string *im;
    

}s,*ptr;
 


int main(){
 
//  int maticni, godina_upisa;
//  string ime_prezime;
//  s.mat = new int;
// *s.mat = 30500;
//  memcpy(&maticni,&s.maticni,sizeof(int));
//  memcpy(&ime_prezime,&s.ime_prezime,sizeof(string));
//  memcpy(&godina_upisa,&s.godina_upisa,sizeof(int));
//  cout << s.maticni << "\t" << s.ime_prezime << "\t" << s.godina_upisa << endl;
//  cout << maticni << endl << ime_prezime << endl << godina_upisa << endl;

int *mata,*goda;
string *pre;

mata = new int;
goda = new int;
pre = new string;

 ptr = new student;
 *ptr->mat = 30500;
 *ptr->im = "Marko Matic";
 *ptr->god = 2016;

//  memcpy(mata,ptr->mat,sizeof(int));

//  cout << mata << "\t" << *ptr->mat << endl;

    return 0;
}