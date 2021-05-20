#include <iostream>

using namespace std;

void Rightprint(void);
void Wrongprint(void);

int main()
{
	void (*fp)();

	char* password = new char[10];			//비밀번호를 받기 위한 문자열 동적할당

	cout << "Please input password : ";
	cin >> password;

	if (strcmp(password, "1234") == 0)
	{
		fp = Rightprint;					//fp에 Rightprint주소값 할당
		fp();								//fp함수 호출(Rightprint 간접 호출)
	}
	else
	{
		fp = Wrongprint;					//fp에 Wrongprint주소값 할당
		fp();								//fp함수 호출(Rightprint 간접 호출)
	}

	delete[] password;
}

void Rightprint(void)
{
	cout << "이름 : 박지용" << endl;
	cout << "학교 : 광운대학교" << endl;
	cout << "학과 : 컴퓨터정보공학부" << endl;
	cout << "학번 : 2018202030" << endl;
}

void Wrongprint(void)
{
	cout << "Wrong Password" << endl;
}