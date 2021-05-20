#include <iostream>
#include <cstring>

using namespace std;

class MyAccount
{
public:
	MyAccount();
	MyAccount(char* in_name, char* in_account);			//������ �����ε�
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

MyAccount::MyAccount(char* in_name, char* in_account)			//�����ε� ������
{
	Money = 0;

	int len = strlen(in_name) + 1;								//�Էµ� �̸��� ���̸� �ι��ڸ� ���� + 1�ؼ� len�� �����Ѵ� 
	Name = new char[len];
	strcpy_s(Name, len, in_name);								//Name�� len��ŭ �����Ҵ��� �ϰ� ������ ȣ�⿡ �Ű������� �� in_name�� �����Ѵ�.

	len = strlen(in_account) + 1;
	Account_Number = new char[len];								//�Էµ� ������ ���̸� �ι��ڸ� ���� + 1�ؼ� len�� �����Ѵ� 
	strcpy_s(Account_Number, len, in_account);					//accout_number�� len��ŭ �����Ҵ��� �ϰ� ������ ȣ�⿡ �Ű������� �� in_name�� �����Ѵ�.

}

void MyAccount::show()
{
	cout << "\tName : " << Name << "\tAccount : " << Account_Number << "\tMomney : " << Money << "\n";
}

void MyAccount::DEPOSIT(char* in_account, int money)
{
	if (strcmp(in_account, Account_Number) == 0)			//���࿡ �Է¹��� ���¿� account_number�� �����ϴٸ� ���� �����Ѵ�
		Money += money;
}
void MyAccount::WITHDRAW(char* in_account, int money)
{
	if (strcmp(in_account, Account_Number) == 0)	//���࿡ �Է¹��� ���¿� account_number�� �����ϴٸ� ���� �����Ѵ�
	{					
		if(Money >= (Money - money))
			Money -= money;
	}
}


MyAccount::~MyAccount()
{
	delete[] Name;											//�����Ҵ��ߴ� �̸��� �����Ҵ����� ��Ų��
	delete[] Account_Number;								//�����Ҵ��ߴ� ���¹�ȣ�� �����Ҵ� ������Ų��
}

int main()
{
	MyAccount* stu[5];			//������ ��ü �迭

	int money;
	char command[10];
	char name[100];
	char account[100];

	int count = 0;
	char c;
	int i = 0;

	while (true)
	{
		cin >> command;				//Ŀ�ǵ带 �Է¹޴´�

		if (strcmp(command, "NEW") == 0)			//NEW�� ���»���
		{
			if (count == 5)
				cout << "Number of Account is Limited\n";

			else
			{
				cout << "���»���\n";
				cin >> name;								//�̸� �Է�

				cin >> account;								//���� �Է�
				stu[count++] = new MyAccount(name, account);		//count�� �÷����鼭 ���»����� �ϰ� �����ε� �����ڸ� ȣ���Ѵ�
			}
		}
		else if (strcmp(command, "DEPOSIT") == 0)				//Ŀ�ǵ尡 �������� ���
		{
			i = 0;
			cin >> account;										//���¹�ȣ�� �Է¹ް� 
			cin >> money;										//������ ���� �Է� �޴´�
			if (count == 0)
				cout << "Nmber of Account is 0\n";
			else
			{
				while (i < count)
				{
					stu[i]->DEPOSIT(account, money);			//������ ���¸��� ���°� �´� ���� ã�� ���� ���� �����Ѵ�
					++i;
				}
			}
		}
		else if (strcmp(command, "WITHDRAW") == 0)				//Ŀ�ǵ尡 ������ ���
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
					stu[i]->WITHDRAW(account, money);			//������ ���¸��� ���°� �´� ���� ã�� ���� ���� �����Ѵ�
					++i;
				}
			}
		}
		else if (strcmp(command, "PRINT") == 0)					//Ŀ�ǵ尡 ����Ʈ �� ���
		{
			cout << "PRINT\n";
			i = 0;
			while (i < count)
			{
				cout << i;										//������ ������ ���� ��, count������ show()�Լ��� ȣ���Ѵ�
				stu[i]->show();
				++i;
			}
		}
		else if (strcmp(command, "EXIT") == 0)
		{
			i = 0;
			while (i < count)
			{
				cout << "��������  : " << i << endl;
				delete stu[i];
				++i;
			}

			return 0;
		}
		
	}

	return 0;
}