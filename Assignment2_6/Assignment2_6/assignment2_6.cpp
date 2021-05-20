#include <iostream>
#include <cstring>

using namespace std;

class MyAccount
{
public:
	MyAccount();
	MyAccount(char* in_name, char* in_account);			//생성자 오버로딩
	void show();
	void DEPOSIT(char* in_account, int money);
	void WITHDRAW(char* in_account, int money);
	~MyAccount();

private:
	unsigned int Money;
	char* Name;
	char* Account_Number;
};

MyAccount::MyAccount()
{
	Name = NULL;
	Account_Number = NULL;
	Money = 0;
}

MyAccount::MyAccount(char* in_name, char* in_account)			//오버로딩 생성자
{
	Money = 0;

	int len = strlen(in_name) + 1;								//입력된 이름의 길이를 널문자를 위해 + 1해서 len에 저장한다 
	Name = new char[len];
	strcpy_s(Name, len, in_name);								//Name을 len만큼 동적할당을 하고 생성자 호출에 매개변수로 온 in_name을 복사한다.

	len = strlen(in_account) + 1;
	Account_Number = new char[len];								//입력된 계좌의 길이를 널문자를 위해 + 1해서 len에 저장한다 
	strcpy_s(Account_Number, len, in_account);					//accout_number을 len만큼 동적할당을 하고 생성자 호출에 매개변수로 온 in_name을 복사한다.

}

void MyAccount::show()
{
	cout << "\tName : " << Name << "\tAccount : " << Account_Number << "\tMomney : " << Money << "\n";
}

void MyAccount::DEPOSIT(char* in_account, int money)
{
	if (strcmp(in_account, Account_Number) == 0)			//만약에 입력받은 계좌와 account_number이 동일하다면 돈을 저축한다
		Money += money;
}
void MyAccount::WITHDRAW(char* in_account, int money)
{
	if (strcmp(in_account, Account_Number) == 0)	//만약에 입력받은 계좌와 account_number이 동일하다면 돈을 저축한다
	{					
		if(Money >= (Money - money))
			Money -= money;
	}
}


MyAccount::~MyAccount()
{
	delete[] Name;											//동적할당했던 이름을 동적할당해제 시킨다
	delete[] Account_Number;								//동적할당했던 계좌번호를 동적할당 해제시킨다
}

int main()
{
	MyAccount* stu[5];			//포인터 객체 배열

	int money;
	char command[10];
	char name[100];
	char account[100];

	int count = 0;
	char c;
	int i = 0;

	while (true)
	{
		cin >> command;				//커맨드를 입력받는다

		if (strcmp(command, "NEW") == 0)			//NEW면 계좌생성
		{
			if (count == 5)
				cout << "Number of Account is Limited\n";

			else
			{
				cout << "계좌생성\n";
				cin >> name;								//이름 입력

				cin >> account;								//계좌 입력
				stu[count++] = new MyAccount(name, account);		//count를 늘려가면서 계좌생성을 하고 오버로딩 생성자를 호출한다
			}
		}
		else if (strcmp(command, "DEPOSIT") == 0)				//커맨드가 디포짓일 경우
		{
			i = 0;
			cin >> account;										//계좌번호를 입력받고 
			cin >> money;										//저축할 돈을 입력 받는다
			if (count == 0)
				cout << "Nmber of Account is 0\n";
			else
			{
				while (i < count)
				{
					stu[i]->DEPOSIT(account, money);			//생성된 계좌마다 계좌가 맞는 것을 찾은 다음 돈을 저축한다
					++i;
				}
			}
		}
		else if (strcmp(command, "WITHDRAW") == 0)				//커맨드가 인출일 경우
		{
			i = 0;
			cin >> account;
			cin >> money;
			if (count == 0)
				cout << "Nmber of Account is 0\n";
			else
			{
				while (i < count)
				{
					stu[i]->WITHDRAW(account, money);			//생성된 계좌마다 계좌가 맞는 것을 찾은 다음 돈을 인출한다
					++i;
				}
			}
		}
		else if (strcmp(command, "PRINT") == 0)					//커맨드가 프린트 일 경우
		{
			cout << "PRINT\n";
			i = 0;
			while (i < count)
			{
				cout << i;										//이제껏 생성된 계좌 즉, count번까지 show()함수를 호출한다
				stu[i]->show();
				++i;
			}
		}
		else if (strcmp(command, "EXIT") == 0)
		{
			i = 0;
			while (i < count)
			{
				cout << "계정삭제  : " << i << endl;
				delete stu[i];
				++i;
			}

			return 0;
		}
		
	}

	return 0;
}