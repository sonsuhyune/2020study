#include <iostream>
using namespace std;

int RefRetFuncTwo1(int &ref) { //��ȯ���� value�� ����!! ������XX
	ref++;
	return ref;

}

int main(void) {
	int num1 = 1;
	int num2 = RefRetFuncTwo1(num1); //�Լ��� ��ȯ���� value�� ����!
	                                 //int &num2=RefRetFuncTwo1(num1) --> �Ұ���! ��ȯ���� value�� �����̱� ������ ���� �� XX

	num1 += 1;
	num2 += 100;

	cout << "num1: " << num1 << endl;
	cout << "num2: " << num2 << endl;
}