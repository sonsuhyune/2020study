//#define SQURE(x) (x*x) -->��ũ�� �Լ�
// ��ũ�� �Լ��� ����: �������
//               ����: ������ �Լ��� ���Ǵ� �Ұ���
//�׷���, inline�������� !
//:��ũ�� �Լ��� ������ �״�� �������鼭, ������ ������ �� �ִ�.

#include <iostream>
inline int SQURE(int x) {
	return x * x;
}

int main(void) {
	std::cout << SQURE(5) << std::endl;
	std::cout << SQURE(7) << std::endl;
	return 0;
}
//������ ����!!
//: SQURE(5), SQURE(7,6) �̷��� �Ϸ��� �����ε��� �Ǿ���Ѵ�.--> ��ũ�� �Լ��� �ڷ����� ������ BUT inline�Լ��� �׷��� ����
//: inline �Լ��� �ڷ����� ���������� �����ϴ� ����� �ڿ��� ���� template����!