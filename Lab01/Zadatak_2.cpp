#include <iostream>

using namespace std;
 


void povrsina(double a, double b){
    double area = a * b;
    cout << "Povrsina pravokutnika iznosi: " << area << endl;
}

void povrsina_kruga(double radius){
    double area = radius*radius*3.14;
    cout << "Povrsina kruga je: " << area << endl;
}

void porvsina_pravokutnog_trokuta(double a, double b){
    double area = (a*b)/2;
    cout << "Povrsina pravokutnog trokuta je: " << area << endl;
}
 
int main(){
    // double a,b;
   
    // do{
    //     cout << "Unesi stranicu a: ";
    //     cin >> a;
    //     cout << "Unesi stranicu b: ";
    //     cin >> b;
    // }while(a < 0 || b < 0);
    // povrsina(a,b);
    // -----------------------------------------------
    // cout << "Unesi stranice: ";
    // cin >> a >> b;
    // if(a < 0 || b < 0){
    //     cout << "ERROR" << endl;
    //     return 0;
    // }

    // povrsina(a,b);


    // ------------------------------------------------------
   
    // double r;
    // do{
    //     cout << "Unesi radius: ";
    //     cin >> r;
    // }while(r < 0);
    // povrsina_kruga(r);

    // ----------------------------------------------------------

    // double r;
    // cout << "Unesi radius: ";
    // cin >> r;
    // if(r < 0){
    //     cout << "ERROR" << endl;
    //     return 0;
    // }
    // povrsina_kruga(r);

    // ----------------------------------------------------------------

    double a,b;
    do{
        cout << "Unesi a i b: ";
        cin >> a >> b;
    }while(a < 0 || b < 0);

    porvsina_pravokutnog_trokuta(a,b);



    
 
    return 0;
}