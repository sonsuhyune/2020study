#include <iostream>
using namespace std;
//������ ������ ������ ���� ����!

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
