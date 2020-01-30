#include <iostream>
using namespace std;

//함수의 반환형이 참조, main에서 함수의 반환을 참조로 받는 경우
int& RefRetFuncOne(int &ref) {
	ref++;
	return ref;
}

int main(void) {
	int num1 = 1;
	int &num2 = RefRetFuncOne(num1);
	num1++;
	num2++;
	num1++;

	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
}