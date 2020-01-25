//함수 오버로딩
//: "함수의 이름", "전달되는 인자의 정보"--> 이 두가지로 호출할 함수 결정
//: 그렇기 때문에, 함수의 이름이 같더라도 "매개변수의 개수", "매개변수의 자료형"이 다르면 함수오버로딩 성립

int MyFunc(int num) {
	num++;
	return num;
}

int MyFunc(int a, int b) {
	return a + b;
}
int main(void) {
	MyFunc(20);
	MyFunc(30, 40);
	return 0;
}