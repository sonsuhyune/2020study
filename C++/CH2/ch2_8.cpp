#include <iostream>
using namespace std;

//const 참조자는 상수를 참조할 수 있다! 
//매개변수형이 참조자인 경우에 상수를 전달할 수 있도록 하기 위해!
int Adder(const int &num1, const int &num2) {
	return num1 + num2;
}
int main(void) {

	const int &ref1 = 20;
	const int &ref2 = 40;

	int result;
	result = Adder(ref1, ref2);
	cout << "result: " << result << endl;

	return 0;


}