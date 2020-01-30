#include <iostream>
using namespace std;

int main(void) {
	int *ptr = new int; //C++에서는 C의 malloc대신 new로 메모리 동적 할당-->크기를 바이트 단위로 계산하는 일을 거치지 않아도 됨
	int &ref = *ptr; //변수같은 *(포인터)에 대해서는 참조자 선언 할 수 있음!
	ref = 20; //참조자를 수정했기때문에 참조받는 *ptr도 바뀜
	cout << *ptr << endl;
}