#include <iostream>

#define INSERT 5
#define FIND 4
#define END 6
#define WORDLEN 1024
#define MAXWORDS 100
#define NOTHING 10

using namespace std;

int my_getline(char* str, int max);
void insert(char** matrix, char** lower, char* str, int max, int& pos);
void find(char** matrix, char* str, int max, int& pos);

void my_strcpy_low(char* from, char* to)
{
	int i = 0;
	while (to[i] != '\0')
	{
		from[i] = tolower(to[i]);
		++i;
	}
	from[i] = '\0';
}

void my_strcpy(char* from, char* to)
{
	int i = 0;
	while (to[i] != '\0')
	{
		from[i] = to[i];
		++i;
	}
	from[i] = '\0';
}

int main()
{
	int i = 0;
	char** notes;
	char** lowercase;
	int pos = 0;								//더블 포인터 matrix에 문자열이 어디까지 할당 되었는지 position
	int op;
	notes = new char*[MAXWORDS];				
	lowercase = new char* [MAXWORDS];			//포인터배열 100크기로 동적할당
	for (i = 0; i < MAXWORDS; ++i)
	{
		notes[i] = new char[WORDLEN];			//각 행당 1024크기로 할당
		lowercase[i] = new char[WORDLEN];
	}

	char* inserted_str = new char[WORDLEN];

	while (true)
	{
		switch (op = my_getline(inserted_str, WORDLEN))		//op에 my_getline이 반환하는 값을 저장한다. INSERT or FIND or END
		{
		case INSERT:
			insert(notes, lowercase, inserted_str, MAXWORDS, pos);
			break;
		case FIND:
			find(notes, inserted_str, MAXWORDS, pos);
			break;
		case END:
			return 0;
		default:
			break;
		}
		
	}
	return 0;
}


int my_getline(char* str, int max)
{
	int op = 0;											//insert or find or end를 저장할 변수
	int i = 0;					


	cin >> str;
	if (strcmp(str, "INSERT") == 0)			//문자열이 "INSERT"와 같다면 (0)
	{
		op = INSERT;						//변수 op(반환 될 변수) 는 defined 된 값인 INSERT값을 저장한다. 
	}
	else if (strcmp(str, "FIND") == 0)		//문자열이 "FIND"와 같다면 (0)
	{
		op = FIND;							//변수 op(반환 될 변수) 는 defined 된 값인 INSERT값을 저장한다. 
	}
	else if (strcmp(str, "END") == 0)					//만약에 모든 문다를 다 받아는데 문자열이 END라면 프로그램 종료
		op = END;
	else
	{
		while (cin.get() != '\n');
		return NOTHING;
	}
	if(op != END)
		cin >> str;

	return op;
}


void insert(char** matrix, char** lower, char* str, int max, int& pos)
{
	int i, j;
	
	char str_low[WORDLEN];
	my_strcpy_low(str_low, str);


	for (i = 0; i < pos; ++i)
	{
		if (strcmp(*(lower + i), str_low) == 0)
			return;
	}

	for (i = 0; i <= pos; ++i)							//첫번째 항부터 pos위치까지 비교
	{
		if (pos == 0)
		{
			my_strcpy_low(*lower, str);
			my_strcpy(*matrix, str);
			++pos;
		}
		
		if (strcmp(*(lower + i), str_low) > 0)            //만약 i번째항이 str보다 alphabetical order가 작으면
		{


			for (j = pos - 1; j >= i; --j)               //마지막 문자열을 저장한 위치에서부터 i번째까지 한칸씩 이동 시켜준다.(i번째에 넣을 자리를 확보)
			{
				if (j + 1 >= max)                     //만약에 하나씩 이동하는데 자리가 부족하다면 함수 종료
				{
					cout << "is_Full" << endl;            //프린트 is_Full
					return;                           //함수종료
				}
				else
				{
					my_strcpy(*(lower + j + 1), *(lower + j));
					my_strcpy(*(matrix + j + 1), *(matrix + j));
				}
			}
			my_strcpy(*(lower + i), str_low);
			my_strcpy(*(matrix + i), str);      //현재 str을 i번째 위치에 저장
			++pos;                              //현재 저장할 위치값 증가 
		}

		else if (strcmp(*(lower + i), str_low) < 0)
		{                                    //여기서의 i값은 pos와 같을때
			continue;                           //만약에 pos전 의 모든 값들이 pos위치의 값보다 작다면 
		}

		for (i = 0; i < pos; ++i)
		{
			cout << i << "." << *(matrix + i) << endl;
		}

	}


	
	return;
}

void find(char** matrix, char* str, int max, int& pos)
{
	int i;
	for (i = 0; i < pos; ++i)
	{
		if (strcmp(*(matrix + i), str) == 0)			//만약에 matrix의 i번째 가르키는 문자열이 str과 같다면 
		{
			cout << i << "." << str << endl;
			return;
		}
	}
	cout << "Not Found" << endl;
	return;
}




