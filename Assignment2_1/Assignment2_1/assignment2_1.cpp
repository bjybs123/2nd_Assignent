#include <iostream>

using namespace std;

void SWAP(int&, int&);

int main()
{
	int* array_2D;
	int* row[4] = {0};

	array_2D = new int[20];

	int i, j, k;

	srand((unsigned int)time(NULL));			//시간을 시드값으로 rand()함수 초기화

	for (i = 0; i < 4; ++i)
		row[i] = array_2D + (i * 5);			//array_2D 1차원 배열에서 column이 5인 2차원 배열로 생각해서 각 행의 주소값을 row의 i번째에 할당.

	for (i = 0; i < 20; ++i)
		*(array_2D + i) = rand() % 20;			//모든 원소 0~19까지 random number로 초기화


	for (i = 0; i < 20; ++i)
	{
		if (i % 5 == 0)
			cout << endl;						//5번째 항 개행
		cout << *(array_2D + i) << "\t";
	}											//모든원소 출력 

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
	temp = num2;							//num2를 변수 temp에 저장하고 num2에 num1을 저장
	num2 = num1;
	num1 = temp;							//num1에 temp에 저장 된 값을 저장.
}