//namespace의 별칭 지정

namespace AAA {
	namespace BBB {
		namespace CCC {
			int num1;
			int num2;
		}
	}
}
int main(void) {
	namespace ABC = AAA::BBB::CCC; //namespace에 대해 별칭 지정

	ABC::num1 = 10;
	ABC::num2 = 10;

}
