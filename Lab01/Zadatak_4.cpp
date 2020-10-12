#include <iostream>
#include "biblioteka_vrijeme.cc"
#include <cmath>
#include <iomanip>
using namespace std;
 
 
// void trokut(int a, int b, int c){
//     if((a+b > c) && (a+c > b) && (b+c > a))
//     int d = (a + b + c)/2;
//     cout << "Zbroj: " << d << endl;
// }


void zbroj(double a){
    double b = a + a;
    cout << "Zbroj: " << b << endl;
}

void zbroj(float a){
    float b = a + 1;
    cout << "Zbroj: " << b << endl;
}

int main(){
    int a,b,c;
    bool trokut;
    vrijeme_pocetak();
    do{
        cout << "Unesi stranice trokuta: ";
        cin >> a >> b >> c;
        if((a+b > c) && (a+c > b) && (b+c > a)){
            trokut = true;
        }
        else{
            trokut = false;
            cout << "Nema trokuta: " << vrijeme_kraj() << endl;
        } 
            
    }while(trokut == false);
    vrijeme_kraj();

    double s = (a+b+c)/2;
    double heron = sqrt(s*(s-a)*(s-b)*(s-c));
    cout << "Povrsina: " << fixed << setprecision(2) << heron << endl;
    
    cout << "Proteklo vrijeme: " << vrijeme_proteklo()/1000 << endl;
    return 0;
}