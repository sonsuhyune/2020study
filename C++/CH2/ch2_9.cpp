#include <iostream>
using namespace std;

int main(void) {
	int *ptr = new int; //C++������ C�� malloc��� new�� �޸� ���� �Ҵ�-->ũ�⸦ ����Ʈ ������ ����ϴ� ���� ��ġ�� �ʾƵ� ��
	int &ref = *ptr; //�������� *(������)�� ���ؼ��� ������ ���� �� �� ����!
	ref = 20; //�����ڸ� �����߱⶧���� �����޴� *ptr�� �ٲ�
	cout << *ptr << endl;
}