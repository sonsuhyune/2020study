#include <iostream> //����� �������

int main(void) {
	int num = 20;
	//std::cout<<"����"; -->����� �⺻����
	//std::endl --> �ٹٲ�
	std::cout << "Hello World" << std::endl;
	std::cout << "Hello " << "World" << std::endl;

	std::cout << num;
	std::cout << " ";
	std::cout << "A";
	std::cout << " " << '3.24' << std::endl; //�̷��� �ϸ� 3.24�� ��µ��� X
	std::cout << 3.24 << std::endl; //���ڸ� print�Ϸ��� �̷��� '' ���� �ؾ���
	return 0;


}