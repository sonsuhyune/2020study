#include <iostream>

int main(void) {
	int val1;
	std::cout << "첫번째 숫자입력: "; 
	std::cin >> val1; //화살표방향 조심..

	int val2;
	std::cout << "두번째 숫자입력: ";
	std::cin >> val2;
	
	int result=val1+val2;
	// std::cout << "덧셈 결과: " << val1 + val2 << std::endl;  이것도 아래와 같은 결과
	std::cout << "덧셈 결과: " << result << std::endl;
	return 0;
}
// C++은 변수의 선언위치에 제한XX-->그래서 중간중간 필요할때 선언할 수 있다.