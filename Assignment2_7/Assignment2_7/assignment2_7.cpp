#include <iostream>

using namespace std;

class ����
{
public:
	bool FIND_ID(char* ID)
	{
		if (strcmp(ID, U_StuID) == 0)
			return true;
		return false;
	}
	void showschool()
	{
		cout << "�б� : " << U_Name << '\n';
		cout << "�й� : " << U_StuID << '\n';
		cout << "�г� : " << year << '\n';
	}
	����(char* school, char* ID, int year, char OOP_grade, char DLC_grade, char* name, int age)
	{
		int len = strlen(name) + 1;
		strcpy_s(U_Name, len, name);

		this->year = year;

		len = strlen(ID) + 1;
		strcpy_s(U_StuID, len, ID);
	}
	~����()
	{

	}

private:
	char U_Name[20];
	int year;
	char U_StuID[20];
};

class ��ǻ���������� :public ����
{
public:
	��ǻ����������(char* school, char* ID, int year, char OOP_grade, char DLC_grade, char* name, int age) : ����(school, ID, year, OOP_grade, DLC_grade, name, age)
	{
		Object_Oriented_Programming = OOP_grade;
		Digital_Logic_Circuit = DLC_grade;
	}
	void showgarde()
	{
		cout << "��ü�������α׷��� ����: " << Object_Oriented_Programming << '\n';
		cout << "�����г�ȸ�� ����: " << Digital_Logic_Circuit << '\n';
	}
	~��ǻ����������()
	{

	}

private:
	char Object_Oriented_Programming;
	char Digital_Logic_Circuit;
};

class �л����� :public ��ǻ����������
{
public:
	bool FIND(char* name, char* ID)
	{
		if (strcmp(name, Name) == 0)
		{
			if (FIND_ID(ID))
				return true;
		}
		return false;
	}

	�л�����(char* school, char* ID, int year, char OOP_grade, char DLC_grade, char* name, int age) : ��ǻ����������(school, ID, year, OOP_grade, DLC_grade, name, age)
	{
		int len = strlen(name) + 1;
		strcpy_s(Name, len, name);
		this->age = age;
	}
	~�л�����()
	{
		
	}

private:
	char Name[10];
	int age;
};


int main()
{
	�л�����** stu;
	stu = new �л�����*[100];
	int count = 0;

	char command[10];
	char school[20];
	char ID[20];
	int year;
	char OOP_grade;
	char DLC_grade;
	char name[10];
	int age;
	
	while (true)
	{
		cin >> command;

		if (strcmp(command, "INSERT") == 0)
		{
			if (count == 100)
				cout << "Limit Number is 100\n";
			else
			{
				cout << "�б� : ";
				cin >> school;
				cout << "�й� : ";
				cin >> ID;
				cout << "�г� : ";
				cin >> year;
				cout << "����ġ�����α׷��� ���� : ";
				cin >> OOP_grade;
				cout << "�����г�ȸ�� ���� : ";
				cin >> DLC_grade;
				cout << "�̸� : ";
				cin >> name;
				cout << "���� : ";
				cin >> age;

				stu[count] = new �л�����(school, ID, year, OOP_grade, DLC_grade, name, age);
				count++;
			}
		}
		else if (strcmp(command, "FIND") == 0)
		{
			cin >> name;
			cin >> ID;
			int i = 0;
			while (i < count)
			{
				if (stu[i]->FIND(name, ID))
				{
					cout << '\n';
					stu[i]->showschool();
					stu[i]->showgarde();
				}
				++i;
			}

		}
		else if (strcmp(command, "EXIT") == 0)
		{
			return 0;
		}
	}


	delete[] stu;
}