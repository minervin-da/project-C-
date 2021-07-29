#include <iostream>

const int N = 4;
const int M = 5;


void criterion_MM(int mat[N][M])
{
	int elem;
	int* vecElem = new int[N];
	int rezult = INT_MIN;

	std::cout << "\nStolbec min\n";
	for (int i = 0; i < N; i++)
	{
		elem = INT_MAX;
		for (int j = 0; j < M; j++)
		{
			if (mat[i][j] < elem)
			{
				elem = mat[i][j];
				vecElem[i] = elem;
			}
			
		}
		std::cout << vecElem[i] << '\n';
	}

	for (int i = 0; i < N; i++)
	{
		if (vecElem[i] > rezult)
		{
			rezult = vecElem[i];
		}
	}
	
	std::cout << "Criterion MM = " << rezult << ";" << std::endl;
}

void criterion_S(int mat[N][M])
{
	int elem , elem1;
	int vecElem[N] = {0,0,0,0};
	int vecElem1[N] = {0,0,0,0};
	int matElem[N][M];

	int rezult = INT_MAX;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			matElem[i][j] = mat[i][j];
		}
	}

	std::cout << std::endl << "Max element\n\n";
	for (int i = 0; i < N; i++)
	{
		elem = INT_MIN;
		for (int j = 0; j < M; j++)
		{
			if (mat[i][j] > elem)
			{
				elem = mat[i][j];
				vecElem[i] = elem;
			}
		}
		std::cout << vecElem[i] << '\n';
	}

	std::cout << std::endl << "Matrix poter\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			matElem[i][j] = vecElem[i] - matElem[i][j];
			std::cout << matElem[i][j] << '\t' ;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl << "Stolbec poter\n";
	for (int i = 0; i < N; i++)
	{
		elem1 = INT_MIN;
		for (int j = 0; j < M; j++)
		{
			if (matElem[i][j] > elem1)
			{
				elem1 = matElem[i][j];
				vecElem1[i] = elem1;
			}
		}
		std::cout << vecElem1[i] << '\n';
	}

	for (int i = 0; i < N; i++)
	{
		if (vecElem1[i] < rezult)
		{
			rezult = vecElem1[i];
		}
	}

	std::cout << "\nCriterion S = " << rezult << ";" << std::endl;
}

void criterion_HW(int mat[N][M], double C)
{
	int elem1;
	int elem2;

	double* vecMin = new double[N];
	double* vecMax = new double[N];
	double* vecElem = new double[N];

	double rezult = INT_MIN;
	std::cout << "\nMin stolbec\n";
	for (int i = 0; i < N; i++)
	{
		elem1 = INT_MAX;
		for (int j = 0; j < M; j++)
		{
			if (mat[i][j] < elem1)
			{
				elem1 = mat[i][j];
				vecMin[i] = elem1;
			}
		}
		std::cout << vecMin[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\nMax stolbec\n";
	for (int i = 0; i < N; i++)
	{
		elem2 = INT_MIN;
		for (int j = 0; j < M; j++)
		{
			if (mat[i][j] > elem2)
			{
				elem2 = mat[i][j];
				vecMax[i] = elem2;
			}
		}
		std::cout << vecMax[i] << std::endl;
	}

	std::cout << "\nMin stolbec umnogen na C\n";
	for (int i = 0; i < N; i++)
	{
		vecMin[i] = C * vecMin[i];
		std::cout << vecMin[i] << std::endl;
	}
	std::cout << '\n';

	std::cout << "\nMax stolbec umnogen na (C-1)\n";
	for (int i = 0; i < N; i++)
	{
		vecMax[i] = (1 - C) * vecMax[i];
		std::cout << vecMax[i] << std::endl;
	}
	std::cout << '\n';

	std::cout << "\nSumma ctolbcov\n";
	for (int i = 0; i < N; i++)
	{
		vecElem[i] = vecMin[i] + vecMax[i];
		std::cout << vecElem[i] << std::endl;
	}
	std::cout << '\n';
	for (int i = 0; i < N; i++)
	{
		if (vecElem[i] > rezult)
		{
			rezult = vecElem[i];
		}
	}
	std::cout << "Criterion HW = " << rezult << ";" << std::endl;
}


int main()
{
	//int const N = 4, M = 5;
	int matricDate[N][M] = { 15,10,0,-6,17,
							3,14,8,9,2,
							1,5,14,20,-3,
							7,19,10,2,0 };
	double C = 0.7;

	std::cout << "\nMatrix\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cout << matricDate[i][j] << '\t';
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	criterion_MM(matricDate);
	std::cout << '\n';
	criterion_S(matricDate);
	std::cout << '\n';
	criterion_HW(matricDate, C);
}


