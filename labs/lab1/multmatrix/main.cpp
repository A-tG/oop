#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef float Matrix3x3[3][3];

void PrintMatrix(Matrix3x3 & matrix)
{
	for (auto & lineOfElements : matrix)
	{
		for (auto & element : lineOfElements)
		{
			cout << element << ' ';
		}
		cout << '\n';
	}
}

bool ReadMatrixFile(char* matrixFileName, Matrix3x3 & matrix)
{
	ifstream matrixFile(matrixFileName);
	if (!matrixFile.is_open())
	{
		cout << "Failed to open " << matrixFileName << " for reading\n";
		return false;
	}
	for (auto & lineOfElements : matrix)
	{
		for (auto & element : lineOfElements)
		{
			if (!(matrixFile >> element))
			{
				cout << "Failed to read matrix element from file\n";
				return false;
			}
		}
	}
	return true;
}

bool MultMatrix(Matrix3x3 & matrix1, Matrix3x3 & matrix2, Matrix3x3 & resultMatrix)
{

}

bool MultMatrix(char* matrixFileName1, char* matrixFileName2, Matrix3x3 & resultMatrix)
{
	Matrix3x3 matrix1;
	if (!ReadMatrixFile(matrixFileName1, matrix1))
	{
		cout << "Failed to read matrix from file " << matrixFileName1 << '\n';
		return false;
	}
	Matrix3x3 matrix2;
	if (!ReadMatrixFile(matrixFileName2, matrix2))
	{
		cout << "Failed to read matrix from file " << matrixFileName2 << '\n';
		return false;
	}
	MultMatrix(matrix1, matrix2, resultMatrix);
	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: multmatrix.exe <matrix file1> <matrix file2>\n";
		return 1;
	}
	char* matrixFileName1 = argv[1];
	char* matrixFileName2 = argv[2];
	Matrix3x3 resultMatrix;
	if (!MultMatrix(matrixFileName1, matrixFileName2, resultMatrix))
	{
		cout << "Failed to multiply matrix\n";
		return 1;
	}
	PrintMatrix(resultMatrix);
	return 0;
}