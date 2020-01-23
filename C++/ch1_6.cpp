//#define SQURE(x) (x*x) -->매크로 함수
// 매크로 함수의 장점: 성능향상
//               단점: 복잡한 함수의 정의는 불가능
//그래서, inline선언으로 !
//:매크로 함수의 장점은 그대로 가져오면서, 단점은 보완할 수 있다.

#include <iostream>
inline int SQURE(int x) {
	return x * x;
}

int main(void) {
	std::cout << SQURE(5) << std::endl;
	std::cout << SQURE(7) << std::endl;
	return 0;
}
//하지만 단점!!
//: SQURE(5), SQURE(7,6) 이렇게 하려면 오버로딩이 되어야한다.--> 매크로 함수는 자료형에 독립적 BUT inline함수는 그렇지 못함
//: inline 함수를 자료형에 독립적으로 선언하는 방법은 뒤에서 배우는 template으로!