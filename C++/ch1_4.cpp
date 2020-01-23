#include <iostream>

//Q. 사용자로부터 정보를 입력받아서 출력

int main(void) {
	char name[100];
	char lang[200];

	std::cout << "이름은 무엇입니까? ";
	std::cin >> name; //문자열 입력방식도 앞의 다른 데이터 입력방식과 동일

	std::cout << "좋아하는 프로그래밍 언어는 무엇인가요? ";
	std::cin >> lang;

	std::cout << "내 이름은 " << name << "입니다." << std::endl;
	std::cout << "제일 좋아하는 언어는 " << lang << "입니다." << std::endl;

	return 0;

}