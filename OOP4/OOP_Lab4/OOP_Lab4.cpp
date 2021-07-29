//	Реализуйте следующие классы
//	Контейнер, который содержит значения факториала от 1!до 10!.
//Интерфейс класса должен включать в себя как минимум :
//o	Конструктор по умолчанию
//o	Функцию получения итератора указывающего на первый элемент контейнера - begin()
//o	Функцию получения итератора указывающего на элемент, следующий за последним - end()
//Доступ к элементам этого контейнера возможен только с помощью итераторов возвращаемых функциями begin() и end().
//Контейнер не должен содержать в памяти свои элементы, они должны вычисляться при обращении к ним через итератор
//Класс итератора для перечисления элементов этого контейнера, объекты этого класса возвращаются
//функциями begin() и end().Итератор должен быть двунаправленным.
//Итератор должен быть совместимым с STL(проверить это можно используя алгоритм copy для копирования содержимого 
//разработанного контейнера в vector<int>)

#include <iostream>
#include <vector>
#include <cstdlib>


class Factorial
{
private:
	std::vector<int> vec;
public:
	Factorial(int size = 10);							//конструктор
	std::vector<int>::iterator m_begin();				//Итератор для получения доступа к первому элементу контейнера
	std::vector<int>::iterator m_end();					//Итератор для получения доступа указывающего на элемент за последним
	void operator()(std::vector<int>::iterator it);		//перегрузка оператора () для вывода подсчитанного факториала числа
	int m_get(int j);									//функция для подсчета факториала числа

};


Factorial::Factorial(int size)							//конструктор
{
	for (int i = 0; i < size; i++)
	{
		vec.push_back(i + 1);
	}
	std::vector<int>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++)
	{
		std::cout << *iter << " ";
	}
}



std::vector<int>::iterator Factorial::m_begin()			//итератор на первый элемент 
{

	std::vector<int>::iterator iter;
	iter = vec.begin();
	return iter;
}

std::vector<int>::iterator Factorial::m_end()			//итератор на элемент следующий за последним
{
	std::vector<int>::iterator iter;
	iter = vec.end();
	return iter;
}

int Factorial::m_get(int j)								//функция для подсчета факториала числа
{
	if (j == 1)											//если числа 1 то возващаем его самого
	{
		return j;
	}
	else                                                //если значение отличное от 1, то перемножаем его от 1 до самого числа
	{
		int f = 1;
		for (int i = 1; i <= j; ++i)
		{
			f = f * i;
		}

		return f;
	}
}

void Factorial::operator()(std::vector<int>::iterator it)
{
	std::cout << "\nComputation factorial:\n";
	std::cout << *it << " fact: " << m_get(*it) << "\n";		//выводим на печать наше значение и вызов функции для подсчета его факториала

}

int main()
{

	Factorial numb;



	numb(numb.m_begin());
	numb(numb.m_begin() + 4);
	numb(numb.m_end() - 1);

	std::cout << '\n';
	std::cout << "Factorial number: " << *(numb.m_begin() + 5) << " ";
	std::cout << "= " << numb.m_get(6) << '\n';



	return 0;
}