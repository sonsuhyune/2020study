#include <iostream>

//Q. ����ڷκ��� ������ �Է¹޾Ƽ� ���

int main(void) {
	char name[100];
	char lang[200];

	std::cout << "�̸��� �����Դϱ�? ";
	std::cin >> name; //���ڿ� �Է¹�ĵ� ���� �ٸ� ������ �Է¹�İ� ����

	std::cout << "�����ϴ� ���α׷��� ���� �����ΰ���? ";
	std::cin >> lang;

	std::cout << "�� �̸��� " << name << "�Դϴ�." << std::endl;
	std::cout << "���� �����ϴ� ���� " << lang << "�Դϴ�." << std::endl;

	return 0;

}