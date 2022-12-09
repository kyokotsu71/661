#include <iostream>
#include <fstream>

//Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
//Если суммы цифр минимального и максимального элементов матрицы одинаковы, 
//упорядочить строки матрицы по неубыванию суммы элементов.

// Функции / процедуры
void Read(int &n, int matrix[100][100]) {

		std::cin >> n;
		std::ifstream in("input.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			in >> matrix[i][j];
		}
	}
}

void write(int &n, int matrix[100][100]) {
	std::ofstream out("output.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			out << matrix[i][j]<< " ";
		}
		out << std::endl;
	}
	out.close();
}

void sumrow(int n, int matrix[100][100], int sumrow[100]) {
	int temp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp += matrix[i][j];
		}
		sumrow[i] += temp;


		temp = 0;
	}
}

int maxsum(int n, int matrix[100][100]) {
	int maxelement = 0;
	int summax = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] > maxelement) {
				maxelement = matrix[i][j];
			}
		}
	}
	while (maxelement > 0) {
		summax += maxelement % 10;
		maxelement /= 10;
	}
	return maxelement;
}

int minsum(int n, int matrix[100][100]) {
	int minelement = INT_MAX;
	int summin = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] < minelement) {
				minelement = matrix[i][j];
			}
		}

	}
	while (minelement > 0) {
		summin += minelement % 10;
		minelement /= 10;
	}
	return minelement;
}

void Sortrows(int n, int matrix[100][100], int sumrows[100]) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sumrows[i] > sumrows[j]) {
				for (int k = 0; k < n; k++) {
					std::swap(matrix[i][k], matrix[j][k]);
				}
			}

		}
	}
}

//main


int main()
{
	setlocale(0, "ru");

	int matrix[100][100];
	int summax = 0;
	int summin = 0;
	int sumrows[100];
	int n;



	Read(n, matrix);
	maxsum(n, matrix);
	minsum(n, matrix);
	sumrow(n, matrix, sumrows);




	if (summax == summin){
		Sortrows(n, matrix, sumrows);
	}
	write(n, matrix);






}

//Перегрузка

int Multiple(int a, long b, int mm) {
	a = 10;
	b = 18;
	mm = a * b;

}
int Multiple(int a, int b, int mm) {
	a = 10;
	b = 18;
	mm = a * b;

}
int Multiple(int a, int b, double c, int mm) {
	a = 10;
	b = 18;
	c = 9;
	mm = a * (b + c);
}

int Func(int x) {
	x = 5;
	x++;
	std::cout << x;
}
int Func(int &x) {
	x = 5;
	x++;
	std::cout << x;
}