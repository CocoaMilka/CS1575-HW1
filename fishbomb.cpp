#include <iostream>

using namespace std;

void initMatrix();
void populateMatrix();
void printMatrix();

class Matrix
{
public:
	int rows;
	int columns;
	int **data;	//points to integer pointers

	Matrix(int r, int c)
	{
		rows = r;
		columns = c;
		initMatrix();
	}

	void initMatrix()
	{
		data = new int*[rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new int[columns];
		}
	}

	void populateMatrix()
	{
		int temp;
		for(int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cin >> temp;
				data[i][j] = temp;
			}
		}
	}

	void printMatrix()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
	}
};

int main()
{
	Matrix matrix1(3, 3);
	matrix1.populateMatrix();
	matrix1.printMatrix();

	int test;
	cout << "done";
	cin >> test;
}
