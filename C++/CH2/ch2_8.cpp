#include <iostream>
using namespace std;

//const �����ڴ� ����� ������ �� �ִ�! 
//�Ű��������� �������� ��쿡 ����� ������ �� �ֵ��� �ϱ� ����!
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