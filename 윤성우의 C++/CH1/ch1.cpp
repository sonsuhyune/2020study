#include <iostream> //입출력 헤더파일

int main(void) {
	int num = 20;
	//std::cout<<"ㅇㅇ"; -->출력의 기본구성
	//std::endl --> 줄바꿈
	std::cout << "Hello World" << std::endl;
	std::cout << "Hello " << "World" << std::endl;

	std::cout << num;
	std::cout << " ";
	std::cout << "A";
	std::cout << " " << '3.24' << std::endl; //이렇게 하면 3.24가 출력되지 X
	std::cout << 3.24 << std::endl; //숫자를 print하려면 이렇게 '' 없이 해야함
	return 0;


}