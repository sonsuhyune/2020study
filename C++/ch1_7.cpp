//namespace�� �⺻����
//: ������Ʈ ���࿡ �־ �߻��� �� �ִ� �̸��� �浹�� ���� ����
//: �����ϴ� namespace�� �ٸ��� ������ �Լ��̸�, ������ ������ �� �ִ�.
#include <iostream>

namespace Best {
	void SimpleFunc(void) {
		std::cout << "Best�� ������ �Լ�" << std::endl;
	}
}

namespace Prog {
	void SimpleFunc(void) {
		std::cout << "Prog���� ������ �Լ�" << std::endl;
	}
}

int main(void) {
	Best::SimpleFunc(); //"::"-->���� ���� ������
	Prog::SimpleFunc();
	return 0;
}