//namespace의 기본원리
//: 프로젝트 진행에 있어서 발생할 수 있는 이름의 충돌을 막을 목적
//: 존재하는 namespace가 다르면 동일한 함수이름, 변수를 선언할 수 있다.
#include <iostream>

namespace Best {
	void SimpleFunc(void) {
		std::cout << "Best가 정의한 함수" << std::endl;
	}
}

namespace Prog {
	void SimpleFunc(void) {
		std::cout << "Prog에서 정의한 함수" << std::endl;
	}
}

int main(void) {
	Best::SimpleFunc(); //"::"-->범위 지정 연산자
	Prog::SimpleFunc();
	return 0;
}