#include <iostream>

using namespace std;

class 대학
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
		cout << "학교 : " << U_Name << '\n';
		cout << "학번 : " << U_StuID << '\n';
		cout << "학년 : " << year << '\n';
	}
	대학(char* school, char* ID, int year, char OOP_grade, char DLC_grade, char* name, int age)
	{
		int len = strlen(name) + 1;
		strcpy_s(U_Name, len, name);

		this->year = year;

		len = strlen(ID) + 1;
		strcpy_s(U_StuID, len, ID);
	}
	~대학()
	{

	}

private:
	char U_Name[20];
	int year;
	char U_StuID[20];
};

class 컴퓨터정보공학 :public 대학
{
public:
	컴퓨터정보공학(char* school, char* ID, int year, char OOP_grade, char DLC_grade, char* name, int age) : 대학(school, ID, year, OOP_grade, DLC_grade, name, age)
	{
		Object_Oriented_Programming = OOP_grade;
		Digital_Logic_Circuit = DLC_grade;
	}
	void showgarde()
	{
		cout << "객체지향프로그래밍 학점: " << Object_Oriented_Programming << '\n';
		cout << "디지털논리회로 학점: " << Digital_Logic_Circuit << '\n';
	}
	~컴퓨터정보공학()
	{

	}

private:
	char Object_Oriented_Programming;
	char Digital_Logic_Circuit;
};

class 학생정보 :public 컴퓨터정보공학
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

	학생정보(char* school, char* ID, int year, char OOP_grade, char DLC_grade, char* name, int age) : 컴퓨터정보공학(school, ID, year, OOP_grade, DLC_grade, name, age)
	{
		int len = strlen(name) + 1;
		strcpy_s(Name, len, name);
		this->age = age;
	}
	~학생정보()
	{
		
	}

private:
	char Name[10];
	int age;
};


int main()
{
	학생정보** stu;
	stu = new 학생정보*[100];
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
				cout << "학교 : ";
				cin >> school;
				cout << "학번 : ";
				cin >> ID;
				cout << "학년 : ";
				cin >> year;
				cout << "객제치향프로그래밍 학점 : ";
				cin >> OOP_grade;
				cout << "디지털논리회로 학점 : ";
				cin >> DLC_grade;
				cout << "이름 : ";
				cin >> name;
				cout << "나이 : ";
				cin >> age;

				stu[count] = new 학생정보(school, ID, year, OOP_grade, DLC_grade, name, age);
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