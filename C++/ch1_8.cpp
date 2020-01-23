//namespace 기반의 함수선언과 정의를 따로 할 수 있다!
//선언은 namespace안에서, 정의는 밖에서
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

//정의는 아래에서..!
void Best::SimpleFunc(void) {
	std::cout << "Best에서 정의한 함수" << std::endl;
}

void Prog::SimpleFunc(void) {
	std::cout << "Prog에서 정의한 함수" << std::endl;
}
