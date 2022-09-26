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

	void initMatrix()	//Allocates memory for the rows and columns of the matrix
	{
		data = new int*[rows];
		for (int i = 0; i < rows; i++)
		{
			data[i] = new int[columns];
		}
	}

	void populateMatrix()	//Reads input from command line to populate matrix
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

	void printMatrix()	//Prints matrix out to command line
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
	int rows;
	int columns;

	int numOfTestCases;
	cout << "Num of test cases: ";
	cin >> numOfTestCases;
	cout << endl;

	for (int i = 0; i < numOfTestCases; i++)
	{
		cin >> rows;
		cin >> columns;
		Matrix matrix(rows, columns);
		matrix.populateMatrix();
		matrix.printMatrix();
	}

	int test;
	cout << "done";
	cin >> test;
}
