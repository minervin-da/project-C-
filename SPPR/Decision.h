#include <iostream>
#include <ctime>
#include <vector>

int const N = 9;
int const M = 9;

int k_max_mat[N][M][4] = { 0 };

std::vector<int> Domination(int matCrit[N][M])
{
	int vec[9] = { 0 };
	std::vector <int> rezult;
	for (int i = 0; i < N; i++)
	{
		int value = 0;
		for (int j = 0; j < M; j++)
		{
			if (i == j)
				continue;
			if (matCrit[i][j] == 1)
				value += 1;

		}
		vec[i] = value;	
	}


	int value_max = INT_MIN;
	int i = 0;
	int it = 0;
	int number = 0;

	for (int k = 0; k < N - 1; k++)
	{
		it += 1;
	}

	while (i < N)	
	{
		if (value_max <= vec[i])
		{
			
			value_max = vec[i];
			number = i;
			if (value_max == it)
			{
				rezult.push_back(number + 1);
			}
			
		}
		if (i != N)
			i++;
	}
	return rezult;
}

std::vector<int> Blocking(int matCrit[N][M])
{
	int vec[9] = { 0 };
	std::vector <int> rezult;
	for (int j = 0; j < N; j++)
	{
		int value = 0;
		for (int i = 0; i < M; i++)
		{
			if (i == j)
			{
				continue;
			}
			if (matCrit[i][j] == 0)
			{
				value += 1;
			}
		}
		vec[j] = value;
	}

	int value_max = INT_MIN;
	int i = 0;
	int it = 0;
	int number = 0;

	for (int k = 0; k < N - 1; k++)
	{
		it += 1;
	}
	while (i < N)
	{
		if (value_max <= vec[i])
		{
			
			value_max = vec[i];
			number = i;
			if (value_max == it)
				rezult.push_back(number + 1);
		}
		if (i != N)
			i++;
	}
	return rezult;
}

double Tournament(int matCrit[N][M], double *vec)
{
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == j)
				continue;
			if ((matCrit[i][j] == 1) && (matCrit[j][i] == 0))

			{

				vec[i] += 1;

			}

			else if ((matCrit[i][j] == 0) && (matCrit[j][i] == 1))

			{

				vec[i] += 0;//ну типа для порядка

			}

			else

			{

				vec[i] += 0.5;

			}
		}
	}
	return *vec;
}

void k_max(int matCrit[N][M], int k)
{	
	for (int i = 0; i < N; i++)
	{
		int val1 = 0,
			val2 = 0,
			val3 = 0;
		for (int j = 0; j < M; j++)
		{
			if ((matCrit[i][j] == 1) && (matCrit[j][i] == 0))
			{
				val1 += 1;
			}
			if ((matCrit[i][j] == 1) && (matCrit[j][i] == 1))
			{
				val2 += 1;
			}
			if ((matCrit[i][j] == 0) && (matCrit[j][i] == 0))
			{
				val3 += 1;
			}
		}
		for (int m = 0; m < 4; m++)
		{
			if (m == 0 || m == 2)
			{
				k_max_mat[k][i][m] = val1 + val2 + val3;
			}
			if (m == 1 || m == 3)
			{
				k_max_mat[k][i][m] = val1 + val3;
			}
		}
	}
}

