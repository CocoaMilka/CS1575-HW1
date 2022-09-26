#include <iostream>

using namespace std;

class Matrix
{
public:
	int rows;
	int columns;
	int *data[];

	Matrix(int r, int c)
	{
		rows = r;
		columns = c;
		*data = new int(r);
	}

	void populateMatrix()
	{
		int temp;
		for (int i = 0; i < rows; i++)
		{
			data[i] = new int(columns);
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
	cout << matrix1.data[0][2];
	cin >> test;
}