#include <iostream>
using namespace std;


/*�������� ���� ���� ����
 int &ref=20;     --> �Ұ���: ����� ������� ������ ������ �Ұ����ϴ�.
 int &ref;        --> �Ұ���: �����ڴ� ������ ���ÿ� ������ �������� �����ؾ��Ѵ�.
 int &ref=NULL;   --> �Ұ���: ������ó�� NULL�� �ʱ�ȭ�ϴ� �͵� �Ұ����ϴ�.
				  --> �����ڴ� ������ ����� ������ �� ����.
*/

//������ ������ ���� ����̶�� �������� ������ �����ϴ�@@ --> �迭�� ��ҵ� ����
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