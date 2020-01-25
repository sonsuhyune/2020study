//namespace의 중첩
//: 중첩이 가능하기때문에 계층적이 구조를 가질 수 있다.
#include <iostream>

namespace Parent {
	int num = 1;
	namespace Subone {
		int num = 3;
	}
	namespace SubTwo {
		int num = 4;
	}
}

