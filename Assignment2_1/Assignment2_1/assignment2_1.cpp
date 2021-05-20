#include <iostream>

using namespace std;

void SWAP(int&, int&);

int main()
{
	int* array_2D;
	int* row[4] = {0};

	array_2D = new int[20];

	int i, j, k;

	srand((unsigned int)time(NULL));			//�ð��� �õ尪���� rand()�Լ� �ʱ�ȭ

	for (i = 0; i < 4; ++i)
		row[i] = array_2D + (i * 5);			//array_2D 1���� �迭���� column�� 5�� 2���� �迭�� �����ؼ� �� ���� �ּҰ��� row�� i��°�� �Ҵ�.

	for (i = 0; i < 20; ++i)
		*(array_2D + i) = rand() % 20;			//��� ���� 0~19���� random number�� �ʱ�ȭ


	for (i = 0; i < 20; ++i)
	{
		if (i % 5 == 0)
			cout << endl;						//5��° �� ����
		cout << *(array_2D + i) << "\t";
	}											//������ ��� 

	for (i = 0; i < 4; ++i)
	{
		for (j = 4; j >= 0; --j)
		{
			for (k = 0; k < j; ++k)
			{
				if (*(*(row + i) + k) > *(*(row + i) + k + 1))
					SWAP(*(*(row + i) + k), *(*(row + i) + k + 1));
			}
		}
	}
	cout << endl;
	
	for (i = 0; i < 20; ++i)					
	{
		if (i % 5 == 0)
			cout << endl;
		cout << *(array_2D + i) << "\t";
	}

	delete[] array_2D;
}

void SWAP(int& num1, int& num2)				//pass by reference 
{
	int temp;		
	temp = num2;							//num2�� ���� temp�� �����ϰ� num2�� num1�� ����
	num2 = num1;
	num1 = temp;							//num1�� temp�� ���� �� ���� ����.
}