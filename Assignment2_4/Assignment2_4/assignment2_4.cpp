#include <iostream>
#define MAXVOL 9
#define MINIVOL 3
using namespace std;




void mulMatrix(int** matrix, int** printMatrix, int pos, int x, int y)
{
	int i, j, k;
	int** miniMatrix;
	miniMatrix = new int* [MINIVOL];			//3 x 3�迭 ���� �迭
	for (i = 0; i < MINIVOL; ++i)
		miniMatrix[i] = new int[MINIVOL];		//3 x 3���� �����Ҵ�

	for (i = 0; i < MINIVOL; ++i)
		for (j = 0; j < MINIVOL; ++j)
			miniMatrix[i][j] = 0;				//�̴� ����� ��� ���Ҹ� 0���� �ʱ�ȭ ���ش�. 

	

	int temp_x, temp_y;
	temp_x = x;
	temp_y = y;

	for (i = 0; i < 3; ++i)			//���� ��
	{
		for (j = 0; j < 3; ++j)		//�� ����
		{
			for (k = 0; k < 3; ++k)
			{
				miniMatrix[i][j] += matrix[(temp_x + k) / 9][(temp_x + k) % 9] * matrix[(temp_y + (k * 9) + j) / 9][(temp_y + (k * 9) + j) % 9];	
					//�谳������ ���޹��� �»���� ���Ҹ� �̿��� 3x3 ���� 3x3�迭�� �����Ѵ�.


				//cout << "miniMatrix[i][j] : " << miniMatrix[i][j] << " " << matrix[(temp_x + k) / 9][(temp_x + k) % 9]  << "*" << matrix[(temp_y + (k * 9) + j) / 9][(temp_y + (k * 9) + j) % 9] << endl;
				//cout << "x : " << matrix[(temp_x + k) / 9][(temp_x + k) % 9] << " ";
				//cout << "y : " << matrix[(temp_y + (k * 9) + j) / 9][(temp_y + (k * 9) + j) % 9] << endl;
			}
			printMatrix[(pos + (i * 9)) / 9][(pos + (i * 9) + j) % 9] += miniMatrix[i][j];	//3x3���� ����Ʈ ��Ŀ� ���Ѵ�.
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
		matrix_numberd[i] = new int[MAXVOL];			//9x9 �迭�� �����Ҵ��Ѵ�. �� �迭�� ������ ��ȣ�� ������ �����Ѵ�. 

	printMatrix = new int* [MAXVOL];
	for (i = 0; i < MAXVOL; ++i)
		printMatrix[i] = new int[MAXVOL];				//����� �Ǵ� 9x9�迭�� �����Ҵ��Ѵ�. �� �迭�� �̴� ��ĵ��� ���� ���������� ���ؼ� ���������� 9x9����� �� ����� ����� �迭�̴�

	matrix = new int* [MAXVOL];
	for (i = 0; i < MAXVOL; ++i)
		matrix[i] = new int[MAXVOL];					//0���� 80������ ���� ����Ǿ��ִ� ����� ���� ��� ����̴�. 

	for (i = 0; i < MAXVOL; ++i)
		for (j = 0; j < MAXVOL; ++j)
			printMatrix[i][j] = 0;						//��¹迭�� �����Ҹ� 0���� �ʱ�ȭ ���ش�. 

	srand((unsigned int)time(NULL));

	for (i = 0; i < MAXVOL; ++i)
		for (j = 0; j < MAXVOL; ++j)
			matrix_numberd[i][j] = a++;					//����� ��� ��ġ�� ������ �迭�� 1���� �迭�� ������ �Ͽ� 0���� 80���� ������ ���ش�. 
	a = 0;
	for (i = 0; i < MAXVOL; ++i)
		for (j = 0; j < MAXVOL; ++j)
			matrix[i][j] = a++;							// ����� �� ��� �迭�� ���Ҹ� 0���� ��ã������ 80���� �ʱ�ȭ ���ش�.
	


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
					act_x = matrix_numberd[(mul_x + (k * 3) + (i * 3 * MAXVOL)) / 9][(mul_x + (k * 3) + (i * 3 * MAXVOL)) % 9];	//1���� ���� ��ȣ�� �̷���� �迭���� ���� �̷���� 3x3�迭�� �»�� ���ҹ�ȣ�� act_x�� ����
					act_y = matrix_numberd[(mul_y + (k * 3 * MAXVOL) + (j * 3)) / 9][(mul_y + (k * 3 * MAXVOL) + (j * 3)) % 9];//1���� ���� ��ȣ�� �̷���� �迭���� ���� �̷���� 3x3�迭�� �»�� ���ҹ�ȣ�� act_y�� ����
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
		delete[] matrix_numberd;		//�����Ҵ翡 ���� ��İ� ��� ��� ��� ��� ���ҹ�ȣ�� ����մ� ����� ���� �����Ҵ��� �����Ѵ�

}