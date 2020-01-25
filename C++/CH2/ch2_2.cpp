#include <iostream>
using namespace std;


/*참조자의 선언 가능 범위
 int &ref=20;     --> 불가능: 상수를 대상으로 참조자 선언은 불가능하다.
 int &ref;        --> 불가능: 참조자는 생성과 동시에 참조할 누군가를 선언해야한다.
 int &ref=NULL;   --> 불가능: 포인터처럼 NULL로 초기화하는 것도 불가능하다.
				  --> 참조자는 참조의 대상을 변경할 수 없다.
*/

//변수의 성향을 가진 대상이라면 참조자의 선언이 가능하다@@ --> 배열의 요소도 가능
int main(void) {
	int arr[3] = { 1,3,5 };
	int &ref1 = arr[0];
	int &ref2 = arr[1];
	int &ref3 = arr[2];

	cout << ref1 << endl;
	cout << ref2 << endl;
	cout << ref3 << endl;

	return 0;


}