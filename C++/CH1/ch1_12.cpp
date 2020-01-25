
int val = 100; //전역변수 선언

int SimpleFunc(void) {
	int val = 20;
	val += 3; //지역변수 val
	::val += 7; //전역변수 val "::"-->이용!!
}