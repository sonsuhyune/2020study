#include <iostream>
using namespace std;
//포인터 변수도 참조자 선언 가능!

int main(void) {
	int num = 12;
	int *ptr = &num;
	int **dptr = &ptr;

	int &ref = num;
	int *(&pref) = ptr;
	int **(&dpref) = dptr;

	cout << "ref: " << ref << endl;
	cout << "*pref: " << *pref << endl;
	cout << "**dpref: " << **dpref << endl;

	return 0;

}
