//
//Выполнить ВСЕ задания
//
//1.	Написать программу, которая выполняет следующие действия :
//a.Читает содержимое текстового файла
//b.Выделяет слова, словом считаются последовательность символов разделенных пробелами
//и / или знаками табуляции и / или символами новой строки
//c.Вывести список слов присутствующий в тексте без повторений
//(имеется в виду, что одно и то же слово может присутствовать в списке только один раз)
//


#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>


int main()
{
	std::vector<std::string> vec(0);
	std::ifstream file("OOP_Lab6.1.cpp");
	std::string str;

	if (file.is_open())																					//читаем текст и записываем каждое слово в элемент массива строк
	{
		int i = 0;
		while (file >> str)
		{
			if (str.length() < 2)
				continue;
			else
			{
				vec.push_back(str);
				i++;
			}
		}
	}

	std::cout << "-------------------------------------------------------------------\n";				//выводим на печать
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << "\n";
	}



	for (std::vector<std::string>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
	{
		for (auto i = iter + 1; i != vec.end();)
		{
			if (*iter == *i)
			{
				i = vec.erase(i);
			}
			else
			{
				++i;
			}
		}
	}

	std::cout << "-------------------------------------------------------------------\n";
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << "\n";
	}
	std::cout << "-------------------------------------------------------------------\n";
}