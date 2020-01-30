#include <iostream>
using namespace std;

int& RefRetFuncOne1 (int &ref){
	ref++;
	return ref;

}

int main(void) {
	int num1 = 1;
	int num2 = RefRetFuncOne1(num1); //이전 코드: &num2로 받음

	num1 += 1;
	num2 += 100;

	cout << "num1: " << num1<<endl;
	cout << "num2: " << num2 << endl;
}