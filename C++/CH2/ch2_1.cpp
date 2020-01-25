#include <iostream>
using namespace std;
int main(void) {
	int num1 = 1020;
	int &num2 = num1; //num2는 num1의 참조자=num1으로 하는 모든 연산은 num2로 하는 것과 동일한 결과를 가져옴
	                  //                    =num2의 값이 변경되면 num1의 값도 함께 변함

	num2 = 3047; //num2의 값 변경--> num1의 참조자인 num2의 값이 변경됐기때문에 num1의 값도 변경됨

	cout << "VAL: " << num1 << endl;
	cout << "REF: " << num2 << endl;

	cout << "VAL: " << &num1 << endl; //&: 주소값
	cout << "REF: " << &num2 << endl;

	return 0;
}

