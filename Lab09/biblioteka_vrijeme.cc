#include <ctime>
//Mjerenje proteklog vremena u tisucinkama sekundi
class cvrijeme{
private:
	clock_t vrijeme1,vrijeme2;
	double razlika;
public:
	double pocetak(){
		vrijeme1=clock();
		return (double)vrijeme1;
	};
	double kraj(){
		vrijeme2=clock();
		return (double)vrijeme2;
	};
	double proteklo(){
		razlika=vrijeme2-vrijeme1;
		return razlika;
	};
};//cvrijeme
