//Joshua Ghilino CS 1575 Section 101

#include <iostream>

using namespace std;

void initMatrix();
void populateMatrix();
void printMatrix();
void totalFish();

class Matrix
{
private:

	int rows;
	int columns;
	int **data;	//points to integer pointers
	
public:

	Matrix(int r, int c)
	{
		rows = r;
		columns = c;
		initMatrix();
	}

	~Matrix() //Stop them memory leaks! >:D
	{
		for(int i = 0; i < rows; i++)
		{
			delete data[i];
		}

		delete[] data;
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

	void totalFish()	//Calculates optimial position and how many fish are caught
	{
		int* rowTotal = new int[rows];
		int* columnTotal = new int[columns];

		int row;
		int column;
		int maxFish = 0;

		//Sum rows
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				rowTotal[i] += data[i][j];
			}
		}

		//Sum columns
		for (int i = 0; i < columns; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				columnTotal[i] += data[j][i];
			}
		}

		//Find optimal position by adding row sum + column sum - intersection
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				if (rowTotal[i] + columnTotal[j] - data[i][j] > maxFish)
				{
					maxFish = rowTotal[i] + columnTotal[j] - data[i][j];
					row = i;
					column = j;
				}
			}
		}

		cout << "at (" << row << "," << column << ") Bender catches " << maxFish << " fish." << endl;

		delete[] rowTotal;
		delete[] columnTotal;
	}
};

int main()
{
	int rows;
	int columns;

	int numOfTestCases;

	cin >> numOfTestCases;

	for (int i = 0; i < numOfTestCases; i++)
	{
		cin >> rows;
		cin >> columns;
		Matrix matrix(rows, columns);

		matrix.populateMatrix();
		//matrix.printMatrix(); For debugging purposes 

		cout << "#" << i << ": ";
		matrix.totalFish();
	}
}
