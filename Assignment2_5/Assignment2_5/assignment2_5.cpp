#include <iostream>

#define MAXLINE 100
using namespace std;

class Mystring
{
private:
	char* Mystr;
public:
	char* Mystrcpy(char* scr, int len);
	int Find_char(char c);
	~Mystring()
	{
		delete[] Mystr;					//소멸자를 이용해 private 변수를 동적할당 해제시킨다
	}
	
};


char* Mystring::Mystrcpy(char* scr, int len)
{
	int i = 0;
	Mystr = new char[len + 1];			// 널문자를 위한 공간 확보 (len은 scr의 널문자 위치 이다.)
	while (i < len)
	{
		Mystr[i] = scr[i];				//매개변수로 전달받은 길이만큼 문자열에 저장한다
		++i;
	}
	Mystr[i] = '\0';
	return Mystr;
}



int Mystring::Find_char(char c)
{
	int i = 0;
	while (Mystr[i] != '\0')		//문자열이 널문자를 만나기 전까지 매개변수로 전달받은 문자를 찾는다 
	{
		if (Mystr[i] == c)
			return i;
		++i;
	}

	return -1;						//문자를 찾지 못 하면 -1을 반환단다. 
}


int main()
{
	Mystring STR;					//Mysting 객체 생성
	char str[MAXLINE];
	char c;
	int i = 0;

	while (cin.get(c) && c != '\n')
		str[i++] = c;
	str[i] = '\0';

	cout << "Copy String : ";
	cout << STR.Mystrcpy(str, i) << '\n';
	cin >> c;
	cout << STR.Find_char(c);
	return 0;
}