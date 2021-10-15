#include <math.h>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
using namespace std;
int Correct_Input_Int();
double Correct_Input_Double();
int main()
{
	int x, y, n, m, i;
	double** matr;
	char code;
	srand(time(NULL));
	do
	{
		do
		{
			cout << "Please, enter size N = ";
			n = Correct_Input_Int();
			cout << "Please, enter size M = ";
			m = Correct_Input_Int();
		} while (n < 1 || m < 1);
		matr = new double* [n];
		for (i = 0; i < n; i++) matr[i] = new double[m];
		if (n == m && n == 1)
		{
			cout << "Massiv consists of 1 element! Nothing interesting!" << endl;
		}
		else
		{
			cout << "Do you want to randomise elements? Y/N" << endl;
			code = _getch();
			if (code == 'Y' || code == 'y')
			{
				for (x = 0; x < n; x++)
				{
					for (y = 0; y < m; y++)
					{
						//matr[x][y] = rand() - 16384.;
						*(*(matr + x) + y) = rand() - 16384.;
						cout << setw(10) << *(*(matr + x) + y);//matr[x][y];
					}
					cout << endl;
				}
			}
			else
			{
				cout << "Input massiv:\n";
				for (x = 0; x < n; x++)
				{
					for (y = 0; y < m; y++)
					{
						cout << "Write A" << x + 1 << "-" << y + 1 << " = ";
						//matr[x][y] = Correct_Input_Double();
						*(*(matr + x) + y) = Correct_Input_Double();
					}
				}
			}
			double* change_strings;
			for (int u = 0; u < n; u++)
			{
				for (int j = 0; j < n - 1; j++)
				{
					if (*(*(matr + j) + 0) > *(*(matr + j + 1) + 0))
					{
						change_strings = *(matr + j);//matr[j];
						//matr[j] = matr[j + 1];
						*(matr + j) = *(matr + j + 1);
						*(matr + j + 1) = change_strings;
						/*for (i = 0; i < m; i++)
						{
							matr[j][i] += matr[j + 1][i];
							matr[j + 1][i] = matr[j][i] - matr[j + 1][i];
							matr[j][i] -= matr[j + 1][i];
						}*/
					}
					else if (*(*(matr + j) + 0) == *(*(matr + j + 1) + 0))
					{
						for (int r = 0; r < m; r++)
						{
							if (*(*(matr + j) + r) > *(*(matr + j + 1) + r))
							{
								for (i = r; i < m; i++)
								{
									matr[j][i] += matr[j + 1][i];
									matr[j + 1][i] = matr[j][i] - matr[j + 1][i];
									matr[j][i] -= matr[j + 1][i];
								}
								break;
							}
						}
					}
					/*else if (matr[j][0] == matr[j + 1][0])
					{
						for (int r = 0; r < m; r++)
						{
							if (matr[j][r] > matr[j + 1][r])
							{
								for (i = r; i < m; i++)
								{
									matr[j][i] += matr[j + 1][i];
									matr[j + 1][i] = matr[j][i] - matr[j + 1][i];
									matr[j][i] -= matr[j + 1][i];
								}
								break;
							}
						}
					}*/
				}
			}
			cout << "Result:" << endl;
			for (x = 0; x < n; x++)
			{
				for (y = 0; y < m; y++)
				{
					cout << setw(10) << *(*(matr + x) + y);//matr[x][y];
				}
				cout << endl;
			}
		}
		for (i = 0; i < n; i++) delete[]matr[i];
		delete[]matr;
		cout << "Massiv deleted!" << endl;
		cout << "Do you want to continue? Y/N" << endl;
		code = _getch();
	} while (code == 'Y' || code == 'y');
	return 0;
}

double Correct_Input_Double()
{
	double a;
	while (true)
	{
		cin >> a;
		if (cin.get() == '\n') {
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error, please write numbers!\n" << "Try again!" << endl;
		}
	}
	return a;
}

int Correct_Input_Int()
{
	int a;
	while (true)
	{
		cin >> a;
		if (cin.get() == '\n') {
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error, please write numbers!\n" << "Try again!" << endl;
		}
	}
	return a;
}

