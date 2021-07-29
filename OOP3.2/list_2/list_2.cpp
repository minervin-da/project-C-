//  2.	Разработайте программу, которая
//  a.Заполняет list < int> 15 случайными значениями от 1 до 20, список может содержать от 0 до 20
//    значений(обязательно проверить на длине списка 0, 1. 2, 3, 4, 5, 7, 14)
//  b.Выводит содержимое списка в следующем порядке : первый элемент, последний элемент, второй элемент, предпоследний элемент, тритий элемент и т.д.
//
//  Например если список содержит :
//  1 2 3 4 5 6 7 8
//  то вывод будет иметь вид
//  1 8 2 7 3 6 4 5



#include <iostream>
#include <list>
#include <random>
#include <ctime>

void sort(std::list<int>& _list, int size)
{
    std::list<int>::iterator iter1;
    std::list<int>::reverse_iterator iter2;
    int tmp = size / 2;                                     //переменная для определения ограничения шага для печати
    int j = 0;
    for (iter1 = _list.begin(), iter2 = _list.rbegin(); iter1 != _list.end(), iter2 != _list.rend(); iter1++, iter2++)
    {
        if (j < tmp)                                        //если находимся в должном диапозоне, то печатаем значение итератора и значение реверсивного итератора
        {
            std::cout << *iter1 << '\t' << *iter2 << '\t';
        }
        else
        {
            if (size % 2 != 0)                              //если память массива не четная,то выводим дополнительно реверсный итератор на печать и завершаем
            {
                std::cout << *iter2;
                break;
            }
            else                                            //иначе просто завершаем
            {
                break;
            }

        }
        j++;

    }
}

int main()
{
    //int const N = 10;
    int const N = 15;
    std::list<int> randList[N];
    std::list<int>::iterator it;
    srand(time(NULL));
    
    for(int i =0; i<N; i++)
        randList->push_back(rand()%20);

    for (it = randList->begin(); it != randList->end(); it++)
        std::cout << (*it) << '\t';
    std::cout << '\n';

    sort(*randList, N);

}

