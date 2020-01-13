#include <iostream>
#include <fstream>
using namespace std;

#define M 8
#define N 40

void readPlate(int plate[M][N])
{
	ifstream f;
	f.open("Plate.txt");

	string x;
	int i = 0;
	while(f >> x)
	{
		for(int j = 0; j < N;j++)
		{
			plate[i][j] = x[j] - '0';
		}
		i++;
	}
}

void readDigits(int digits[10][5][3])
{
	int n = 0;
	int row = 1;

	ifstream f;
	f.open("Digits.txt");

	string x;

	int i = 0;
	while(f >> x)
	{
		for(int j = 0;j < 3;j++)
		{
			digits[n][i][j] = x[j] - '0';
		}
		i++;

		if(i == 5)
		{
			i = 0;
			n +=1;
		}
	}
}

int noiseCounter(int digit,int row,int col,int plate[][40],int digits[][5][3])
{
	int errors = 0;

	for(int i = 0; i < 5;i++)
	{
		for(int j = 0; j < 3;j++)
		{
			if(plate[row+i][col+j] != digits[digit][i][j])
			{
				errors++;
			}
		}
	}

	return errors;
}

int main()
{
	int plate[M][N];
	int digits[10][5][3];
	readPlate(plate);

	readDigits(digits);

	cout << noiseCounter(0,1,3,plate,digits) << endl;

	// cout << "Plate.txt : " << endl;
	// for(int k = 0; k < M;k++)
	// {
	// 	for(int q = 0;q < N; q++)
	// 	{
	// 		cout << plate[k][q];
	// 	}

	// 	cout << endl;
	// }

	// cout << endl << "Digits.txt : " << endl;
	// for(int k = 0;k < 10;k++)
	// {
	// 	for(int q = 0;q<5;q++)
	// 	{
	// 		for(int p = 0; p < 3;p++)
	// 		{
	// 			cout << digits[k][q][p];
	// 		}
	// 		cout << endl;
	// 	}
	// 	cout << endl;
	// }

	return 0;
}