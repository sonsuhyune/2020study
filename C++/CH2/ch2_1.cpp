#include <iostream>
using namespace std;
int main(void) {
	int num1 = 1020;
	int &num2 = num1; //num2�� num1�� ������=num1���� �ϴ� ��� ������ num2�� �ϴ� �Ͱ� ������ ����� ������
	                  //                    =num2�� ���� ����Ǹ� num1�� ���� �Բ� ����

	num2 = 3047; //num2�� �� ����--> num1�� �������� num2�� ���� ����Ʊ⶧���� num1�� ���� �����

	cout << "VAL: " << num1 << endl;
	cout << "REF: " << num2 << endl;

	cout << "VAL: " << &num1 << endl; //&: �ּҰ�
	cout << "REF: " << &num2 << endl;

	return 0;
}

