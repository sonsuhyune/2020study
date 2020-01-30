#include <iostream>
using namespace std;

int RefRetFuncTwo1(int &ref) { //반환형이 value의 형태!! 참조형XX
	ref++;
	return ref;

}

int main(void) {
	int num1 = 1;
	int num2 = RefRetFuncTwo1(num1); //함수의 반환값을 value로 받음!
	                                 //int &num2=RefRetFuncTwo1(num1) --> 불가능! 반환형이 value의 형태이기 때문에 받을 수 XX

	num1 += 1;
	num2 += 100;

	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
}