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
	int pos = 0;								//���� ������ matrix�� ���ڿ��� ������ �Ҵ� �Ǿ����� position
	int op;
	notes = new char*[MAXWORDS];				
	lowercase = new char* [MAXWORDS];			//�����͹迭 100ũ��� �����Ҵ�
	for (i = 0; i < MAXWORDS; ++i)
	{
		notes[i] = new char[WORDLEN];			//�� ��� 1024ũ��� �Ҵ�
		lowercase[i] = new char[WORDLEN];
	}

	char* inserted_str = new char[WORDLEN];

	while (true)
	{
		switch (op = my_getline(inserted_str, WORDLEN))		//op�� my_getline�� ��ȯ�ϴ� ���� �����Ѵ�. INSERT or FIND or END
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
	int op = 0;											//insert or find or end�� ������ ����
	int i = 0;					


	cin >> str;
	if (strcmp(str, "INSERT") == 0)			//���ڿ��� "INSERT"�� ���ٸ� (0)
	{
		op = INSERT;						//���� op(��ȯ �� ����) �� defined �� ���� INSERT���� �����Ѵ�. 
	}
	else if (strcmp(str, "FIND") == 0)		//���ڿ��� "FIND"�� ���ٸ� (0)
	{
		op = FIND;							//���� op(��ȯ �� ����) �� defined �� ���� INSERT���� �����Ѵ�. 
	}
	else if (strcmp(str, "END") == 0)					//���࿡ ��� ���ٸ� �� �޾ƴµ� ���ڿ��� END��� ���α׷� ����
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

	for (i = 0; i <= pos; ++i)							//ù��° �׺��� pos��ġ���� ��
	{
		if (pos == 0)
		{
			my_strcpy_low(*lower, str);
			my_strcpy(*matrix, str);
			++pos;
		}
		
		if (strcmp(*(lower + i), str_low) > 0)            //���� i��°���� str���� alphabetical order�� ������
		{


			for (j = pos - 1; j >= i; --j)               //������ ���ڿ��� ������ ��ġ�������� i��°���� ��ĭ�� �̵� �����ش�.(i��°�� ���� �ڸ��� Ȯ��)
			{
				if (j + 1 >= max)                     //���࿡ �ϳ��� �̵��ϴµ� �ڸ��� �����ϴٸ� �Լ� ����
				{
					cout << "is_Full" << endl;            //����Ʈ is_Full
					return;                           //�Լ�����
				}
				else
				{
					my_strcpy(*(lower + j + 1), *(lower + j));
					my_strcpy(*(matrix + j + 1), *(matrix + j));
				}
			}
			my_strcpy(*(lower + i), str_low);
			my_strcpy(*(matrix + i), str);      //���� str�� i��° ��ġ�� ����
			++pos;                              //���� ������ ��ġ�� ���� 
		}

		else if (strcmp(*(lower + i), str_low) < 0)
		{                                    //���⼭�� i���� pos�� ������
			continue;                           //���࿡ pos�� �� ��� ������ pos��ġ�� ������ �۴ٸ� 
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
		if (strcmp(*(matrix + i), str) == 0)			//���࿡ matrix�� i��° ����Ű�� ���ڿ��� str�� ���ٸ� 
		{
			cout << i << "." << str << endl;
			return;
		}
	}
	cout << "Not Found" << endl;
	return;
}




