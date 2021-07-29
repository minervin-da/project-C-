//вставить три 1 без использования цикла!!!
//Задание к лабораторной работе.Необходимо выполнить ВСЕ задания.
//
//1)	Напишите алгоритм сортировки(любой простейший) содержимого вектора целых чисел, используя оператор operator[].
//
//2)	Напишите алгоритм сортировки(любой простейший) содержимого вектора целых чисел, используя метод at().
//
//3)	Напишите алгоритм сортировки(любой простейший) содержимого вектора целых чисел, используя для доступа к содержимому вектора только итераторы.
//		Для работы с итераторами допустимо использовать только операторы получения текущего элемента и перехода в следующему
//		(подсказка, можно сохранять копию итератора указывающего на некоторый элемент).
//
//4)	Прочитайте во встроенный массив С содержимое текстового файлы, скопируйте данные в вектор одной строкой кода(без циклов и алгоритмов STL)
//
//5)	Напишите программу, сохраняющую в векторе числа, полученные из стандартного ввода(окончанием ввода является число 0).Удалите все элементы, 
//		которые делятся на 2 (не используете стандартные алгоритмы STL), если последнее число 1. Если последнее число 2, 
//		добавьте после каждого числа которое делится на 3 три единицы.
//
//6)	Напишите функцию void fillRandom(double* array, int size) заполняющую массив случайными значениями в интервале от - 1.0 до 1.0.
//		Заполните с помощью заданной функции вектора размером 5, 10, 25, 50, 100 и отсортируйте его содержимое
//      (с помощью любого разработанного ранее алгоритма модифицированного для сортировки действительных чисел)
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>

//заполнение случайными числами
template<class T>
void randVector(std::vector<T> vec, int N)
{
	for (int i = 0; i < N; i++)
	{
		vec[i] = rand();
	}
}

//Алгоритм сортировки (пузырьком) вектора, используя оператор operator[].
template<class T>
void sortBubble(std::vector<T> &A)
{
	for (int i = 0; i < A.size() - 1; i++)
	{
		for (int j = 0; j < A.size() - 1; j++)
		{
			if (A[j] < A[j + 1])
			{
				int tmp = A[j + 1];
				A[j + 1] = A[j];
				A[j] = tmp;
			}
		}
	}
}

//Aлгоритм сортировки (пузырьком) вектора, используя метод at().
template<class T>
void sortBubble_at(std::vector<T>& A)
{
	for (int i = 0; i < A.size() - 1; i++)
	{
		for (int j = 0; j < A.size() - 1; j++)
		{
			if (A.at(j) < A.at(j + 1))
			{
				int tmp = A.at(j + 1);
				A.at(j + 1) = A.at(j);
				A.at(j) = tmp;
			}
		}
	}
}

//Алгоритм сортировки(пузырьком) вектораб используя итератор.
void sortBubble_iterat(std::vector<int>& A)
{
	for(std::vector<int>::iterator it1 = A.begin(); it1 < A.end(); it1++)
	{
		for(std::vector<int>::iterator it2 = A.begin(); it2 < A.end(); it2++)
		{
			if (*it2 > *it1)
			{
				int tmp = *it2;
				*it2 = *it1;
				*it1 = tmp;
			}
		}
	}
}

//Заполнение массива из файла
void readFile(std::string *mas)
{

	std::ifstream in;
	in.open("E:\\text.txt");
	if (!in)
	{
		// выводим следующее сообщение об ошибке и выполняем функцию exit()
		std::cerr << "Uh oh, SomeText.txt could not be opened for reading!" << std::endl;
		exit(1);
	}
	
	while (in)
	{
		getline(in, *mas);
	}
}

//Заполнение вектора числами, с окончанием в ввода если число равен 0. 
template<class T>
void popVector(std::vector<T>& vec, int n)
{
	for (int i = 0; i < n; i++)
	{
		int b;
		std::cin >> b;

		if (b != 0)
		{
			vec.push_back(b);
		}
		else
		{
			break;
		}
	}
}

//Удаление и вставка чисел в вектор.
void vectorInsEres(std::vector<int>& vec, int size)
{
	std::vector<int>::iterator it = vec.end() - 1;
	if (*it == 2)
	{
		for (std::vector<int>::iterator it2 = vec.begin(); it2 != vec.end(); it2++)
		{
			if (*it2 % 3 == 0)
			{
				it2 = vec.insert(it2 + 1, 3, 1);
			}
		}
	}
	else if (*it == 1)
	{
		std::vector<int>::iterator it2 = vec.begin();
		while (it2 != vec.end())
		{
			if (*it2 % 2 == 0)
			{
				it2 = vec.erase(it2);
			}
			else
				it2++;
		}
	}
}

//Заполнения массива числами в диапазоне от -1 до 1.
template<class T>
void fillRandom(T* array, int size)
{
	int i;
	double x = -1.0, y = 1.0;

	srand(time(NULL));

	for (i = 0; i < size; i++)
		array[i] = (T)rand() / (RAND_MAX) * (y - x) + x;
}

//Сортировка массива методом пузырьков.
template<class T>
void sortBubbleMas(T* massiv, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (massiv[j] < massiv[j + 1])
			{
				T tmp = massiv[j + 1];
				massiv[j + 1] = massiv[j];
				massiv[j] = tmp;
			}
		}
	}
}

//Вывод вектора на экран.
template<class T>
void printVector(std::vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << '\t';
	}
	std::cout << std::endl;
}

//Вывод массива на экран.
template<class T>
void printMassiv(T* massiv, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << massiv[i] << '\n';
}


int main()
{
	int const N = 2000, n=10;

	std::vector<int> A1(N), A2(N), A3(N), A4(N);
	int C[5] = { 3, 7, 3, 5, 7 };
	std::vector<int> B;
	std::vector<std::string> text;
	double mas[N];
	std::string m[N];

	clock_t start1, start2, start3, start4;
	double end1, end2, end3, end4;

	readFile(m);								//чтение из файла

	std::vector<std::string> vec(m, m+N);
	
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
	}
	std::cout << std::endl;
	std::cout << "------------------------------" << std::endl;

	srand(time(NULL));
	
	randVector(A1, N);
	//printVector(A);

	
	start1 = clock();
	std::sort(A1.begin(), A1.end());
	end1 = (double)(clock() - start1) / CLOCKS_PER_SEC;
	
	std::cout << "Time sort = " << end1<< ";" << '\n';
	std::cout << "------------------------------" << std::endl;


	randVector(A2, N);
	start2 = clock();
	sortBubble(A2);
	end2 = (double)(clock() - start2) / CLOCKS_PER_SEC;
	std::cout << "Time sort bubble = " << end2 << ";" << '\n';
	std::cout << "------------------------------" << std::endl;


	randVector(A3, N);
	start3 = clock();
	sortBubble_at(A3);
	end3 = (double)(clock() - start3) / CLOCKS_PER_SEC;
	std::cout << "Time at. = " << end3 << ";" << '\n';
	std::cout << "------------------------------" << std::endl;


	randVector(A4, N);
	start4 = clock();
	
	sortBubble_iterat(A4);
	end4 = (double)(clock() - start4) / CLOCKS_PER_SEC;
	std::cout << "Time iterator = " << end4 << ";" << '\n';
	std::cout << "------------------------------" << std::endl;
	
	popVector(B, N);											//Заполнение вектора В

	vectorInsEres(B, N);										//Удаление и вставка элеменов в вектор.
	
	printVector(B);												//Вывов вектора В
	
	std::cout << "------------------------------" << std::endl;
	fillRandom(mas, n);											//заполнение массива случайными числами в диапазоне от -1 до 1
	printMassiv(mas, n);										//вывод на экран массива случайних чисел
	
	std::cout << "------------------------------" << std::endl;
	sortBubbleMas(mas, n);										//сортировка массива
	printMassiv(mas, n);										//вывод на экран отсортированого массива
	
	return 0;
}


