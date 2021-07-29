//Необходимо выполнить следующее задание :
//
//1.	Разработать функтор, позволяющий собирать статистику о последовательности целых чисел(послед может 
//	содержать числа от - 500 до 500).Функтор после обработки последовательности алгоритмом for_each должен предоставлять следующую статистику :
//a.Максимальное число в последовательности
//b.Минимальное число в последовательности
//c.Среднее число в последовательности
//d.Количество положительных чисел
//e.Количество отрицательных чисел
//f.Сумму нечетных элементов последовательности
//g.Сумму четных элементов последовательности
//h.Совпадают ли первый и последний элементы последовательности.
//
//Проверить работу программы на случайно сгенерированных последовательностях.


#include <iostream>
#include <vector>
#include <algorithm>

class Functor
{
public:
	Functor();
	void print();//функция для вывода на печать функтора
	void operator()(int val);
private:
	int min;//минимум
	int max;//максимум
	double average;//среднее число в последовательности
	int i;//для подсчета кол-ва чисел
	int positiv;//количество положительных чисел
	int negativ;//количество отрицательных чисел
	int sumNechElem;//сумма нечетных элементов последовательности
	int sumChetElem;//сумма четных элементов последовательности
	int firstElem;//первый элемент
	int lastElem;//последний элемент
	bool fistEquLast;//проверка равенста первого и последнего элемента

};

Functor::Functor()
{
	min = 0;
	max = 0;
	average = 0;
	i = 0;
	positiv = 0;
	negativ = 0;
	sumNechElem = 0;
	sumChetElem = 0;
	firstElem = 0;
	lastElem = 0;
	fistEquLast = true;
}

void Functor::operator()(int val)
{
	if (min > val)//ищим минимум в последовательности
	{
		min = val;
	}

	if (max < val)//ищем максимум в последовательности
	{
		max = val;
	}


	average = average + val;//считаем сумму всех чисел

	if (val > 0)//считаем кол-во положительных чисел
	{
		positiv++;
	}

	if (val < 0)//считаем кол-во отрицательных чисел
	{
		negativ++;
	}

	if (i % 2 == 0)//считаем сумму четных элементов последовательности
	{
		sumChetElem = sumChetElem + val;
	}
	else
	{
		sumNechElem = sumNechElem + val;
	}
	if (i == 0)
	{
		firstElem = val;
	}

	lastElem = val;

	if (firstElem == lastElem)
	{
		fistEquLast = true;
	}
	else
	{
		fistEquLast = false;
	}

	i++;//считаем общее кол-во чисел
}


void Functor::print()
{
	std::cout << "Minimum     =  " << min << "\n";
	std::cout << "Maximum     =  " << max << "\n";
	std::cout << "Sredn       =  " << average / i << "\n";//сумму делим на кол-во всех чисел для среднего
	std::cout << "Positive    =  " << positiv << "\n";
	std::cout << "Negative    =  " << negativ << "\n";
	std::cout << "SumChetElem =  " << sumChetElem << "\n";
	std::cout << "SumNechElem =  " << sumNechElem << "\n";
	std::cout << "first last equ:     " << "\n";
	if (fistEquLast)
	{
		std::cout << "First == Last\n";
	}
	else
	{
		std::cout << "First != Last\n";
	}
}

template<class T>
void printVector(std::vector<T>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << '\t';
	}
	std::cout << std::endl;
}

int main()
{
	const int N = 15;
	std::vector<int> vec(N);
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		vec[i] = rand() % 1000 - 500;
	}

	printVector(vec);

	Functor fun = std::for_each(vec.begin(), vec.end(), Functor());
	fun.print();
}