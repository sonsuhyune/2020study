//namespace ����� �Լ������ ���Ǹ� ���� �� �� �ִ�!
//������ namespace�ȿ���, ���Ǵ� �ۿ���
#include <iostream>


namespace Best {
	void SimpleFunc(void);
}

namespace Prog {
	void SimpleFunc(void);
}

int main(void) {
	Best::SimpleFunc();
	Prog::SimpleFunc();
	return 0;
}

//���Ǵ� �Ʒ�����..!
void Best::SimpleFunc(void) {
	std::cout << "Best���� ������ �Լ�" << std::endl;
}

void Prog::SimpleFunc(void) {
	std::cout << "Prog���� ������ �Լ�" << std::endl;
}
