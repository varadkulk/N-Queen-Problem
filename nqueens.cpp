#include <simplecpp>
#include <iostream>
using namespace std;
int grid[10][10];
void print(int);
int x(int cl)
{
	return (cl / 65536);
}
int y(int cl)
{
	return (cl % 65536);
}
bool exit(int cl, int a, int clx, int cly)
{
	if ((clx >= (6 * a - a / 2) && clx <= (6 * a + a / 2)) && (cly >= (6.75 * a - a / 6) && cly <= (6.75 * a + a / 6)))
		return true;
	return false;
}

bool isSafe(int col, int row, int n)
{

	for (int i = 0; i < row; i++)
	{
		if (grid[i][col])
		{
			return false;
		}
	}

	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if (grid[i][j])
		{
			return false;
		}
	}

	for (int i = row, j = col; i >= 0 && j < n; j++, i--)
	{
		if (grid[i][j])
		{
			return false;
		}
	}
	return true;
}

bool solve(int n, int row)
{
	if (n == row)
	{
		print(n);
		return true;
	}

	bool res = false;
	for (int i = 0; i <= n - 1; i++)
	{
		if (isSafe(i, row, n))
		{
			grid[row][i] = 1;
			res = solve(n, row + 1) || res;
			grid[row][i] = 0;
		}
	}
	return res;
}
void squares(int n)
{

	Rectangle border(500, 500, 895, 895);
	border.setColor(COLOR(255, 255, 255));
	border.setFill();
	border.imprint();
	int a = 900 / n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Rectangle square((50 + ((2 * i + 1) * a / 2)), (50 + ((2 * j + 1) * a / 2)), a, a);
			square.imprint();
		}
	}
}
void printqueen(int i, int j, int n)
{
	int a = 900 / n;
	Rectangle queen((50 + ((2 * i + 1) * a / 2)), (50 + ((2 * j + 1) * a / 2)), a, a);
	queen.setFill();
	queen.imprint();
}
void print(int n)
{
	// squares(n);
	for (int i = 0; i <= n - 1; i++)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			// if (grid[i][j] == 1)
			// 	printqueen(i, j, n);
		}
	}
	wait(5);
}
main_program
{
	cin.tie(NULL);
	int n;
	cout << "Enter the number of queen" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			grid[i][j] = 0;
		}
	}
	initCanvas("N Queens Problem", 1000, 1000);
	Rectangle border(500, 500, 900, 900);
	bool res = solve(n, 0);
	if (res == false)
	{
		for (int i = 0; i <= n - 1; i++)
	{
		for (int j = 0; j <= n - 1; j++)
		{
			if (grid[i][j] == 1)
				printqueen(i, j, n);
		}
	}
		cout << "Not Possible!!" << endl;
	}
	else
	{
		while (1)
			wait(1);
	}
	return 0;
}
