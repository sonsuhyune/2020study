//namespace�� ��Ī ����

namespace AAA {
	namespace BBB {
		namespace CCC {
			int num1;
			int num2;
		}
	}
}
int main(void) {
	namespace ABC = AAA::BBB::CCC; //namespace�� ���� ��Ī ����

	ABC::num1 = 10;
	ABC::num2 = 10;

}
