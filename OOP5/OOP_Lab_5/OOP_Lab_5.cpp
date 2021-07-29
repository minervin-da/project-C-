//Написать программа, которая выполняет следующие действия :

//a.Заполняет vector<DataStruct> структурами DataStruct, при этом key1 и key2, 
//генерируются случайным образом в диапазоне от - 5 до 5, str заполняется из таблицы
//(таблица содержит 10 произвольных строк, индекс строки генерируется случайным образом)
//b.Выводит полученный вектор на печать
//c.Сортирует вектор следующим образом :
//i.По возрастанию key1
//ii.Если key1 одинаковые, то по возрастанию key2
//iii.Если key1 и key2 одинаковые, то по возрастанию длинны строки str
//d.Выводит полученный вектор на печать
//
//DataStruct определена следующим образом :
//typedef struct
//{
//	int       key1;
//	int       key2;
//	string  str;
//} DataStruct;

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

typedef struct
{
    int key1;
    int key2;
    std::string str;
} DataStruct;                                                                                    //наша структура

class ClassDataStruct                                                                           //класс для работы со структурой
{
private:
    std::vector<DataStruct> vec;
public:
    ClassDataStruct(std::string* data, int size);
    void print();
    void sort();
};

ClassDataStruct::ClassDataStruct(std::string* _data, int size)                                  //создаем объект из 10ти элементов DataStruct
{
    DataStruct Data;
    for (int i = 0; i < size; i++)
    {
        //Data.key1 = rand() % size - (size / 2);
        Data.key1 = 1;
        //Data.key2 = rand() % size - (size / 2);
        Data.key2 = 1;
        Data.str = _data[rand() % size];
        vec.push_back(Data);
    }
}



void ClassDataStruct::print()                                                                    //метод для печати
{
    for(std::vector<DataStruct>::iterator it = vec.begin(); it != vec.end(); it++)
    std::cout << it->str << '\t' << it->key1 << '\t' << it->key2 << '\n';
}

void ClassDataStruct::sort()                                                                    //метод сориторвки
{
    bool swap;
    for (std::vector<DataStruct>::iterator it1 = vec.begin(); it1 < vec.end(); it1++)
    {
        for (std::vector<DataStruct>::iterator it2 = vec.begin(); it2 < vec.end(); it2++)
        {
            swap = false;
            if (it1->key1 > it2->key1)                                                          //сортировка по первому ключу
                swap = true;
            else if (it1->key1 == it2->key1)                                                    //иначе есть первые ключи равны, то сортировка по второму ключу
            {
                if (it1->key2 > it2->key2)                                                      

                    swap = true;
                else if (it1->str.length() > it2->str.length())                                                //иначе если вторые ключи равны, то сортировка по строке
                {
                    if (it1->str.length() > it2->str.length())
                        swap = true;
                }
            }
            if (swap)
            {
                int tmp1 = it1->key1;
                int tmp2 = it1->key2;
                std::string stmp = it1->str;

                it1->key1 = it2->key1;
                it1->key2 = it2->key2;
                it1->str = it2->str;

                it2->key1 = tmp1;
                it2->key2 = tmp2;
                it2->str = stmp;
            }
        }
    }
}

int main()
{
    int const size = 10;
    std::string mas[size];
    std::ifstream input;
    input.open("dateFile.txt");
    
    for (int i = 0; i < size; i++)
    {
        getline(input, mas[i], '\n');
    }
    input.close();

    for (int i = 0; i < size; i++)
        std::cout << mas[i] << '\n';
    
    //srand(time(NULL));

    ClassDataStruct data(mas, size);

    std::cout << "------------------------------------" << '\n';
    data.print();

    data.sort();
    std::cout << "------------------------------------" << '\n';
    data.print();

}
