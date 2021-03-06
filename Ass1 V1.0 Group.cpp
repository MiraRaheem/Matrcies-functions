// Ass1 V1.0 Group.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Author 1: Mira Mohamed (20170305)
//Author 2: Nada Mohamed (20170316)
//Author 3: Nourhan Ihab (20170324)
//Title: Matrix Functions
// Version: 1.0
//Date: 8/10/2018

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

struct matrix
{
	int** data;
	int row, col;
};

void creatematrix(int row, int col, int num[], matrix& mat);
matrix operator+  (matrix mat1, matrix mat2);
matrix operator-  (matrix mat1, matrix mat2);
matrix operator*  (matrix mat1, matrix mat2);
matrix operator+  (matrix mat1, int scalar);
matrix operator-  (matrix mat1, int scalar);
matrix operator*  (matrix mat1, int scalar);

matrix operator+= (matrix& mat1, matrix mat2);
matrix operator-= (matrix& mat1, matrix mat2);
matrix operator+= (matrix& mat, int scalar);
matrix operator-= (matrix& mat, int scalar);
void operator++ (matrix& mat);
void operator-- (matrix& mat);
istream& operator>> (istream& in, matrix& mat);

ostream& operator<< (ostream& out, matrix mat);
bool   operator== (matrix mat1, matrix mat2);
bool   operator!= (matrix mat1, matrix mat2);
matrix transpose(matrix mat3, matrix &mat4);
bool   isSquare(matrix mat);
bool   isSymetric(matrix mat);
bool   isIdentity(matrix mat);

int main()
{
	int data1[] = { 1,2,3,4,5,6,7,8 };
	int data2[] = { 13,233,3,4,5,6 };
	int data3[] = { 10,100,10,100,10,100,10,100 };

	matrix mat1, mat2, mat3;
	creatematrix(4, 2, data1, mat1);
	creatematrix(2, 3, data2, mat2);
	creatematrix(4, 2, data3, mat3);

	cout << mat1 << endl;
	cout << mat2 << endl;
	cout << mat3 << endl;

	cout << (mat3 + mat3) << endl << endl;
	cout << (mat3 - mat1) << endl << endl;
	cout << (mat1 * mat2) << endl << endl;

	cout << (mat1 + 2) << endl;
	cout << (mat2 - 3) << endl;
	cout << (mat3 * 5) << endl;
	
	delete mat1.data;
	delete mat2.data;
	delete mat3.data;

	return 0;
}


void creatematrix(int row, int col, int num[], matrix& mat) {
	mat.row = row;
	mat.col = col;
	mat.data = new int*[row];

	for (int i = 0; i < row; i++) {
		mat.data[i] = new int[col];

		for (int j = 0; j < col; j++) {
			mat.data[i][j] = num[i * col + j];
		}
	}
}


// By Nourhan.

//Adding two matrcis.
matrix operator+  (matrix mat1, matrix mat2) {
	
	if ((mat1.row == mat2.row) && (mat1.col == mat2.col)) {
		matrix mat3;
		mat3.row = mat1.row;
		mat3.col = mat1.col;
		
		mat3.data = new int* [mat3.row];

		for (int i = 0; i < mat3.row; i++) {
			mat3.data[i] = new int[mat3.col];

			for (int j = 0; j < mat3.col; j++) {
				mat3.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
			}
		}
		return mat3;
	}
	else {
		cout << "Not Possible" << endl;
	}
}


//Subtracting two matrcies.
matrix operator-  (matrix mat1, matrix mat2) {
	
	if ((mat1.row == mat2.row) && (mat1.col == mat2.col)) {
		matrix mat3;
		mat3.row = mat1.row;
		mat3.col = mat1.col;

		mat3.data = new int*[mat3.row];

		for (int i = 0; i < mat3.row; i++) {
			mat3.data[i] = new int[mat3.col];

			for (int j = 0; j < mat3.col; j++) {
				mat3.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
			}
		}
		return mat3;
	}
	
	else {
		cout << "Not Possible;" << endl;
	}
}


//Multiplying two matrcies.
matrix operator*  (matrix mat1, matrix mat2) {
	if (mat1.col == mat2.row) {
		matrix mat3;
		mat3.row = mat1.row;
		mat3.col = mat2.col;

		mat3.data = new int*[mat3.row];

		for (int i = 0; i < mat3.row; i++) {
			mat3.data[i] = new int[mat3.col];

			for (int j = 0; j < mat3.col; j++) {
				mat3.data[i][j] = 0;
			}
		}

		for (int i = 0; i < mat3.row; i++) {
			for (int k = 0; k < mat3.col; k++) {
				for (int j = 0; j < mat1.col; j++) {
					mat3.data[i][k] += (mat1.data[i][j] * mat2.data[j][k]);
				}
			}
		}
		return mat3;
	}

	else {
		cout << "Not Possible" << endl;
	}
}


//Adding a number(scalar) to a matrix.
matrix operator+  (matrix mat1, int scalar) {
	for (int i = 0; i < mat1.row; i++) {
		for (int j = 0; j < mat1.col; j++) {
			mat1.data[i][j] += scalar;
		}
	}
	return mat1;
}


//Subtracting a number(scalar) to a matrix.
matrix operator-  (matrix mat1, int scalar) {
	for (int i = 0; i < mat1.row; i++) {
		for (int j = 0; j < mat1.col; j++) {
			mat1.data[i][j] -= scalar;
		}
	}
	return mat1;
}


//Multiplying a number(scalar) to a matrix.
matrix operator*  (matrix mat1, int scalar) {
	for (int i = 0; i < mat1.row; i++) {
		for (int j = 0; j < mat1.col; j++) {
			mat1.data[i][j] *= scalar;
		}
	}
	return mat1;
}



//By Mira

matrix operator+= (matrix& mat1, matrix mat2) {
	
	for (int i = 0; i < mat1.row; ++i) {
		for (int j = 0; j < mat1.col; ++j) {
			mat1.data[i][j] = mat1.data[i][j] + mat2.data[i][j];
		}
	}
	return mat1;

}


matrix operator-= (matrix& mat1, matrix mat2) {
	
	for (int i = 0; i < mat1.row; ++i) {
		for (int j = 0; j < mat1.col; ++j) {
			mat1.data[i][j] = mat1.data[i][j] - mat2.data[i][j];
		}
	}
	return mat1;
}


matrix operator+= (matrix& mat, int scalar) {
	for (int i = 0; i < mat.row; ++i) {
		for (int j = 0; j < mat.col; ++j) {
			mat.data[i][j] = mat.data[i][j] + scalar;
		}
	}
	return mat;
}


matrix operator-= (matrix& mat, int scalar) {
	for (int i = 0; i < mat.row; ++i) {
		for (int j = 0; j < mat.col; ++j) {
			mat.data[i][j] = mat.data[i][j] - scalar;
		}
	}
	return mat;
}


void operator++ (matrix& mat) {
	for (int i = 0; i < mat.row; ++i) {
		for (int j = 0; j < mat.col; ++j) {
			mat.data[i][j] ++;
		}
	}
}


void operator-- (matrix& mat) {
	for (int i = 0; i < mat.row; ++i) {
		for (int j = 0; j < mat.col; ++j) {
			mat.data[i][j]--;
		}
	}
}


istream& operator>> (istream& in, matrix& mat) {
	for (int i = 0; i < mat.row; ++i) {
		for (int j = 0; j < mat.col; ++j) {
			in >> mat.data[i][j];
		}
	}
	return in;
}


//By Nada

ostream& operator<< (ostream& out, matrix mat) {
	for (int i = 0; i < mat.row; ++i) {
		for (int j = 0; j < mat.col; ++j) {
			out << setw(5) << mat.data[i][j];

		}
		cout << endl;
	}
	return out;
}


bool   operator== (matrix mat1, matrix mat2) {
	for (int i = 0; i < mat1.row; i++) {
		for (int j = 0; j < mat1.col; j++) {
			if (mat1.data[i][j] != mat2.data[i][j])
				return false;
		}

		return true;
	}
}


bool   operator!= (matrix mat1, matrix mat2) {
	for (int i = 0; i < mat1.row; i++) {
		for (int j = 0; j < mat1.col; j++) {
			if (mat1.data[i][j] != mat2.data[i][j])
				return true;
		}

		return false;

	}
}


matrix transpose(matrix mat3, matrix &mat4) {

	for (int i = 0; i < mat3.col; i++)
	{
		for (int j = 0; j < mat3.row; j++) {
			mat4.data[i][j] = mat3.data[j][i];
		}
		cout << "\n ";
	}
	return mat4;
}


bool   isSquare(matrix mat) {
	int x = false;
	mat.data;
	if (mat.row == mat.col) {
		x = true;
	}
	return x;
}


bool   isSymetric(matrix mat) {

	int x = true;
	//   if (mat.row ==  mat.col )
	  //     x=true;

	for (int i = 0; i < mat.col; i++)
	{
		for (int j = 0; j < mat.row; j++) {
			if (mat.data[i][j] != mat.data[j][i])
				x = false;

		}
	}
	return x;
}


bool   isIdentity(matrix mat) {

	mat.data;
	int x = true;
	for (int i = 0; i < mat.row; i++)
	{
		for (int j = 0; j < mat.col; j++)
		{
			if (i == j && mat.data[i][j] != 1) {
				x = false;
			}
			else if (i != j && mat.data[i][j] != 0) {
				x = false;
			}
		}
	}
	return x;
}

