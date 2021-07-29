#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

const int HEIGHT_MAP = 35;
const int WIDTH_MAP = 40;
string TileMap[HEIGHT_MAP] = {
"5                                      5",
"5                                      5",
"5                                      5",
"5                                      5",
"5                                      5",
"5                                      5",
"5                                      5",
"5                                      5",
"5                                 6    5",
"5               4343434343     343434345",
"53434    6                             5",
"5      343434                          5",
"5                                      5",
"5               6                      5",
"5            4343434                   5",
"5                                      5",
"5                     3434             5",
"5      343434             6            5",
"5                         34343        5",
"5                                     h5",
"5h 6                             3434343",
"5434343 h                              5",
"5     43434       h      343434        5",
"5                43434343              5",
"5           6                          5",
"5      43434343                        5",
"5                                      5",
"5             343434343       6        5",
"5                        143434343     5",
"5     34                 2             5",
"5               h        2             5",
"5           01010101010102          1010",
"0101        22222222222222          2222",
"2222       h22222222222222h         2222",
"2222010101012222222222222201010101012222",
};

void randomMapGenerate() {//рандомно расставляем камни
	int randomElementX = 0;//случайный элемент по горизонтали
	int randomElementY = 0;//случ эл-т по вертикали
	srand(time(0));//рандом	
	int countStone = 1;//количество камней 1
	while (countStone > 0) {
		randomElementX = 1 + rand() % (WIDTH_MAP - 1);//рандомное по иксу от 1 до ширина карты-1, чтобы не получать числа бордюра карты
		randomElementY = 1 + rand() % (HEIGHT_MAP - 1);//по игреку так же
		if (TileMap[randomElementY][randomElementX] == ' ' && TileMap[randomElementY + 1][randomElementX] == '0' )
		{																							//если встретили символ пробел, 
			TileMap[randomElementY][randomElementX] = 'h';
			std::cout << "coordinate of Stone X:" << randomElementX << "\n" << "coordinate of Stone Y:" << randomElementY << "\n\n";
			countStone--;//создали камень=>счетчик камней будет "текущий минус 1"
		}
		if (TileMap[randomElementY][randomElementX] == ' ' && TileMap[randomElementY + 1][randomElementX] == '1')
		{																							//если встретили символ пробел, 
			TileMap[randomElementY][randomElementX] = 'h';
			std::cout << "coordinate of Stone X:" << randomElementX << "\n" << "coordinate of Stone Y:" << randomElementY << "\n\n";
			countStone--;//создали камень=>счетчик камней будет "текущий минус 1"
		}
		if (TileMap[randomElementY][randomElementX] == ' ' && TileMap[randomElementY + 1][randomElementX] == '3')
		{																							//если встретили символ пробел, 
			TileMap[randomElementY][randomElementX] = 'h';
			std::cout << "coordinate of Stone X:" << randomElementX << "\n" << "coordinate of Stone Y:" << randomElementY << "\n\n";
			countStone--;//создали камень=>счетчик камней будет "текущий минус 1"
		}
		if (TileMap[randomElementY][randomElementX] == ' ' && TileMap[randomElementY + 1][randomElementX] == '3')
		{																							//если встретили символ пробел, 
			TileMap[randomElementY][randomElementX] = 'h';
			std::cout << "coordinate of Stone X:" << randomElementX << "\n" << "coordinate of Stone Y:" << randomElementY << "\n\n";
			countStone--;//создали камень=>счетчик камней будет "текущий минус 1"
		}
	}
}

