#include <iostream>

using namespace std;

void Rightprint(void);
void Wrongprint(void);

int main()
{
	void (*fp)();

	char* password = new char[10];			//��й�ȣ�� �ޱ� ���� ���ڿ� �����Ҵ�

	cout << "Please input password : ";
	cin >> password;

	if (strcmp(password, "1234") == 0)
	{
		fp = Rightprint;					//fp�� Rightprint�ּҰ� �Ҵ�
		fp();								//fp�Լ� ȣ��(Rightprint ���� ȣ��)
	}
	else
	{
		fp = Wrongprint;					//fp�� Wrongprint�ּҰ� �Ҵ�
		fp();								//fp�Լ� ȣ��(Rightprint ���� ȣ��)
	}

	delete[] password;
}

void Rightprint(void)
{
	cout << "�̸� : ������" << endl;
	cout << "�б� : ������б�" << endl;
	cout << "�а� : ��ǻ���������к�" << endl;
	cout << "�й� : 2018202030" << endl;
}

void Wrongprint(void)
{
	cout << "Wrong Password" << endl;
}