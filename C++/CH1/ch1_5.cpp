//�Լ� �����ε�
//: "�Լ��� �̸�", "���޵Ǵ� ������ ����"--> �� �ΰ����� ȣ���� �Լ� ����
//: �׷��� ������, �Լ��� �̸��� ������ "�Ű������� ����", "�Ű������� �ڷ���"�� �ٸ��� �Լ������ε� ����

int MyFunc(int num) {
	num++;
	return num;
}

int MyFunc(int a, int b) {
	return a + b;
}
int main(void) {
	MyFunc(20);
	MyFunc(30, 40);
	return 0;
}