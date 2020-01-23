#include <iostream>

//Q. 사용자가 입력한 두수 사이의 정수의 합

int main(void) {
	int val1, val2;
	int result = 0;
	
	std::cout << "두 개의 숫자입력: ";
	std::cin >> val1 >> val2; //공백단위로 끊어서 변수에 저장됨

	if (val1 > val2){
		for (int i = val2 + 1; i < val1; i++) {
			result += i;
		}
	}

	if (val1 < val2) {
		for (int i = val1 + 1; i < val2; i++) {
			result += i;
		}
	}
	std::cout << "두 수 사이의 정수 합: " << result << std::endl;
	return 0;
}