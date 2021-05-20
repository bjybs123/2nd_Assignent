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
		delete[] Mystr;					//�Ҹ��ڸ� �̿��� private ������ �����Ҵ� ������Ų��
	}
	
};


char* Mystring::Mystrcpy(char* scr, int len)
{
	int i = 0;
	Mystr = new char[len + 1];			// �ι��ڸ� ���� ���� Ȯ�� (len�� scr�� �ι��� ��ġ �̴�.)
	while (i < len)
	{
		Mystr[i] = scr[i];				//�Ű������� ���޹��� ���̸�ŭ ���ڿ��� �����Ѵ�
		++i;
	}
	Mystr[i] = '\0';
	return Mystr;
}



int Mystring::Find_char(char c)
{
	int i = 0;
	while (Mystr[i] != '\0')		//���ڿ��� �ι��ڸ� ������ ������ �Ű������� ���޹��� ���ڸ� ã�´� 
	{
		if (Mystr[i] == c)
			return i;
		++i;
	}

	return -1;						//���ڸ� ã�� �� �ϸ� -1�� ��ȯ�ܴ�. 
}


int main()
{
	Mystring STR;					//Mysting ��ü ����
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