#include <iostream>
#define MAXVOL 9
#define MINIVOL 3
using namespace std;




void mulMatrix(int** matrix, int** printMatrix, int pos, int x, int y)
{
	int i, j, k;
	int** miniMatrix;
	miniMatrix = new int* [MINIVOL];			//3 x 3배열 작은 배열
	for (i = 0; i < MINIVOL; ++i)
		miniMatrix[i] = new int[MINIVOL];		//3 x 3으로 동적할당

	for (i = 0; i < MINIVOL; ++i)
		for (j = 0; j < MINIVOL; ++j)
			miniMatrix[i][j] = 0;				//미니 행렬을 모든 원소를 0으로 초기화 해준다. 

	

	int temp_x, temp_y;
	temp_x = x;
	temp_y = y;

	for (i = 0; i < 3; ++i)			//열과 행
	{
		for (j = 0; j < 3; ++j)		//각 원소
		{
			for (k = 0; k < 3; ++k)
			{
				miniMatrix[i][j] += matrix[(temp_x + k) / 9][(temp_x + k) % 9] * matrix[(temp_y + (k * 9) + j) / 9][(temp_y + (k * 9) + j) % 9];	
					//배개변수로 전달받은 좌상단의 원소를 이용해 3x3 곱을 3x3배열에 저장한다.


				//cout << "miniMatrix[i][j] : " << miniMatrix[i][j] << " " << matrix[(temp_x + k) / 9][(temp_x + k) % 9]  << "*" << matrix[(temp_y + (k * 9) + j) / 9][(temp_y + (k * 9) + j) % 9] << endl;
				//cout << "x : " << matrix[(temp_x + k) / 9][(temp_x + k) % 9] << " ";
				//cout << "y : " << matrix[(temp_y + (k * 9) + j) / 9][(temp_y + (k * 9) + j) % 9] << endl;
			}
			printMatrix[(pos + (i * 9)) / 9][(pos + (i * 9) + j) % 9] += miniMatrix[i][j];	//3x3곱을 프린트 행렬에 더한다.
			//cout << endl;
		}
		//cout << endl;
		temp_x += 9;
	}
	


	for (i = 0; i < MAXVOL; ++i)
	{
		for (j = 0; j < MAXVOL; ++j)
			cout << printMatrix[i][j] << "\t";
		cout << '\n';
	}
	cout << '\n' << '\n' << '\n';


	/*for (i = 0; i < MINIVOL; ++i)
	{
		for (j = 0; j < MINIVOL; ++j)
			cout << miniMatrix[i][j] << "\t";
		cout << endl;
	}*/


	for (i = 0; i < MINIVOL; ++i)
		delete[] miniMatrix[i];
	delete[] miniMatrix;
}



int main()
{
	int** matrix;
	int** printMatrix;
	int** matrix_numberd;
	int i, j, k;
	int a = 0;
	matrix_numberd = new int* [MAXVOL];				
	for (i = 0; i < MAXVOL; ++i)
		matrix_numberd[i] = new int[MAXVOL];			//9x9 배열을 동적할당한다. 이 배열은 원소의 번호를 값으로 저장한다. 

	printMatrix = new int* [MAXVOL];
	for (i = 0; i < MAXVOL; ++i)
		printMatrix[i] = new int[MAXVOL];				//출력이 되는 9x9배열을 동적할당한다. 이 배열은 미니 행렬들의 곱을 순차적으로 더해서 최종적으로 9x9행렬의 곱 결과가 저장될 배열이다

	matrix = new int* [MAXVOL];
	for (i = 0; i < MAXVOL; ++i)
		matrix[i] = new int[MAXVOL];					//0부터 80까지의 값이 저장되어있는 행렬의 곱의 대상 행렬이다. 

	for (i = 0; i < MAXVOL; ++i)
		for (j = 0; j < MAXVOL; ++j)
			printMatrix[i][j] = 0;						//출력배열을 모든원소를 0으로 초기화 해준다. 

	srand((unsigned int)time(NULL));

	for (i = 0; i < MAXVOL; ++i)
		for (j = 0; j < MAXVOL; ++j)
			matrix_numberd[i][j] = a++;					//행렬의 운소 위치를 저장할 배열에 1차원 배열로 생각을 하여 0부터 80까지 저장을 해준다. 
	a = 0;
	for (i = 0; i < MAXVOL; ++i)
		for (j = 0; j < MAXVOL; ++j)
			matrix[i][j] = a++;							// 행렬의 곱 대상 배열의 원소를 0부터 순찾ㄱ으로 80까지 초기화 해준다.
	


	/* for (i = 0; i < MAXVOL; ++i)
	{
		for (j = 0; j < MAXVOL; ++j)
		{
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	} */


	int N = 1;
	int pos = 0;
	int mul_x = 0, mul_y = 0;
	
		for (i = 0; i < 3; ++i)
		{
			for (j = 0; j < 3; ++j)
			{
				for (k = 0; k < 3; ++k)
				{
					int act_x, act_y;
					act_x = matrix_numberd[(mul_x + (k * 3) + (i * 3 * MAXVOL)) / 9][(mul_x + (k * 3) + (i * 3 * MAXVOL)) % 9];	//1차원 원소 번호로 이루어진 배열에서 곱이 이루어질 3x3배열의 좌상단 원소번호를 act_x에 저장
					act_y = matrix_numberd[(mul_y + (k * 3 * MAXVOL) + (j * 3)) / 9][(mul_y + (k * 3 * MAXVOL) + (j * 3)) % 9];//1차원 원소 번호로 이루어진 배열에서 곱이 이루어질 3x3배열의 좌상단 원소번호를 act_y에 저장
					cout << "N : " << N++ << '\n';
					//cout << "x : " << (mul_x + (k * 3) + (i * 3 * MAXVOL)) / 9 << " y : " << (mul_x + (k * 3) + (i * 3 * MAXVOL)) % 9 << endl;
					//cout << "x' : " << (mul_y + (k * 3 * MAXVOL) + (j * 3)) / 9 << " y' : " << (mul_y + (k * 3 * MAXVOL) + (j * 3)) % 9 << endl;
					mulMatrix(matrix, printMatrix, pos + (i * 3 * MAXVOL) + (j * 3), act_x, act_y);

					//cout << "pos : " << pos + (i * 3 * MAXVOL) + (j * 3) << endl;
					//cout << "x : " << matrix[(mul_x + (k * 3) + (i * 3 * MAXVOL)) / 9][(mul_x + (k * 3) + (i * 3 * MAXVOL)) % 9] << " ";
					//cout << "y : " << matrix[(mul_y + (k * 3 * MAXVOL) + (j * 3)) / 9][(mul_y + (k * 3 * MAXVOL) + (j * 3)) % 9] << endl;
				}

			}
		}
	
		
		for (int i = 0; i < MAXVOL; ++i)
		{
			delete[] matrix[i];
			delete[] printMatrix[i];
			delete[] matrix_numberd[i];					
		}
		delete[] matrix;
		delete[] printMatrix;
		delete[] matrix_numberd;		//동적할당에 사용된 행렬곱 대상 행렬 출력 행렬 원소번호를 답고잇는 행렬을 각각 동적할당을 해제한다

}