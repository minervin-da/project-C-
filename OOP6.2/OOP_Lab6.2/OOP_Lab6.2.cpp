//2.	Написать программу, которая выполняет следующие действия
//(все операции должны выполняться с помощью стандартных алгоритмов) :
//	a.Заполняет вектор геометрическими фигурами.Геометрическая фигура может быть треугольником,
//	квадратом, прямоугольником или пяти угольником.Структура описывающая геометрическую фигуру  определена ниже,
//	b.Подсчитывает общее количество вершин всех фигур содержащихся в векторе(так треугольник 
//	добавляет к общему числу 3, квадрат 4 и т.д.)
//	c.Подсчитывает количество треугольников, квадратов и прямоугольников в векторе
//	d.Удаляет все пятиугольники
//	e.На основании этого вектора создает vector<Point>, который содержит координаты одной из вершин(любой)
//	каждой фигуры, т.е.первый элемент этого вектора содержит координаты одной из вершину первой фигуры, 
//	второй элемент этого вектора содержит координаты одной из вершину второй фигуры и т.д.
//	f.Изменяет вектор так, чтобы он содержал в начале все треугольники, потом все квадраты, а потом прямоугольники.
//	g.Распечатывает вектор после каждого этапа работы

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

typedef struct          //структура для координат
{
	int x;				//координата х
	int y;				//координата у

}Point;


typedef enum            //структура для наиманования фигур
{
	TREUG,				//треугольник
	KVADRAT,			//квадрат
	PRAMOYGOL,			//прямоугольник
	PJATIYGOL,			//пятиугольник
}ShapeElement;


typedef struct                                //для фигуры
{
	int col_peak;                             //кол-во вершин(треуг = 3, квадрат = 4, прямоугол = 4, пятиугольник = 5
	std::vector<Point> cordinat;			  //вектор содержащий координаты вершин фигур
	ShapeElement SHELEM;					  //один из элементов

}Shape;

class Figures																		//для массива фигур
{
private:
	std::vector<Shape> vec;																//массив фигур
public:
	Figures(void) {};																	//конструктор по умолчанию
	~Figures(void) {};																	//деструктор

	//функция для добавления фигуры

	void putInFigures(ShapeElement EL, int x1, int y1, int x2, int y2, int x3, 
					  int y3, int x4 = -1, int y4 = -1, int x5 = -1, int y5 = -1);		//Добавление фигуры
	void print();																		//функция печати массива фигур
	void SumPeaks();																	//для подсчета суммы вершин
	void SumFigurs();																	//для подсчета кол-ва треугольников, квадратов, чет-уг, и пяти-уг
	void DeletPug();																	//функция для удаления пятиугольников
	void sort();																		//сортировка массива,сначала тр-ки,потом квадраты,прямоугольники,пятиугольники
	void PushPoint(std::vector<Point>& P);												//заполнить вектор Point первыми вершинами нашего массива фигур
};

class Functor						//создаем функтор для подсчетов
{
public:
	Functor();
	void operator()(Shape& S);		//перегрузка оператора ()
	void printSumm();				//функция для вывода на печать функтора суммы
	void printColichFig();			//функция для вывода на печать кол-ва фигур
private:
	int Summ;
	int treug;
	int Kvadrat;
	int Pramoug;
	int Pjatiug;
};
Functor::Functor()
{
	Summ = 0;
	treug = 0;
	Kvadrat = 0;
	Pramoug = 0;
	Pjatiug = 0;
}

void Functor::operator()(Shape& S)				//функтор для подсчета кол-ва фигур
{
	Summ += S.col_peak;
	if (S.SHELEM == 0)
		treug++;
	if (S.SHELEM == 1)
		Kvadrat++;
	if (S.SHELEM == 2)
		Pramoug++;
	if (S.SHELEM == 3)
		Pjatiug++;
}

void Functor::printSumm()
{
	std::cout << "Summa peaks    =  " << Summ << "\n";

}
void Functor::printColichFig()
{
	std::cout << "Treugolniki : " << treug << "\n";
	std::cout << "Kvadrati    : " << Kvadrat << "\n";
	std::cout << "Pramoug     : " << Pramoug << "\n";
	std::cout << "Pjatiug     : " << Pjatiug << "\n";
}

void Figures::putInFigures(ShapeElement EL, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int x5, int y5)
{
	Shape figyra;																//создаем структуру для фигуры
	Point cordinat1;															//создаем структуру для координат
	Point cordinat2;															//создаем структуру для координат
	Point cordinat3;															//создаем структуру для координат
	Point cordinat4;															//создаем структуру для координат
	Point cordinat5;															//создаем структуру для координат

	figyra.SHELEM = EL;															//смотрим какая у нас фигура и записываем в элемент
	
	if (EL == 0)								//если триугольник
	{
		figyra.col_peak = 3;					//записываем кол-во вершин и добавляем точки координат для фигуры
		cordinat1.x = x1;
		cordinat1.y = y1;
		figyra.cordinat.push_back(cordinat1);
		cordinat2.x = x2;
		cordinat2.y = y2;
		figyra.cordinat.push_back(cordinat2);
		cordinat3.x = x3;
		cordinat3.y = y3;
		figyra.cordinat.push_back(cordinat3);

	}
	else if (EL == 1)							//если квадрат
	{
		figyra.col_peak = 4;					//записываем кол-во вершин и добавляем точки координат для фигуры
		cordinat1.x = x1;
		cordinat1.y = y1;
		figyra.cordinat.push_back(cordinat1);
		cordinat2.x = x2;
		cordinat2.y = y2;
		figyra.cordinat.push_back(cordinat2);
		cordinat3.x = x3;
		cordinat3.y = y3;
		figyra.cordinat.push_back(cordinat3);
		cordinat4.x = x4;
		cordinat4.y = y4;
		figyra.cordinat.push_back(cordinat4);

	}
	else if (EL == 2)							//если прямоугольник
	{
		figyra.col_peak = 4;					//записываем кол-во вершин и добавляем точки координат для фигуры
		cordinat1.x = x1;
		cordinat1.y = y1;
		figyra.cordinat.push_back(cordinat1);
		cordinat2.x = x2;
		cordinat2.y = y2;
		figyra.cordinat.push_back(cordinat2);
		cordinat3.x = x3;
		cordinat3.y = y3;
		figyra.cordinat.push_back(cordinat3);
		cordinat4.x = x4;
		cordinat4.y = y4;
		figyra.cordinat.push_back(cordinat4);
	}
	else if (EL == 3)							//если пятиугольник
	{
		figyra.col_peak = 5;					//записываем кол-во вершин и добавляем точки координат для фигуры
		cordinat1.x = x1;
		cordinat1.y = y1;
		figyra.cordinat.push_back(cordinat1);
		cordinat2.x = x2;
		cordinat2.y = y2;
		figyra.cordinat.push_back(cordinat2);
		cordinat3.x = x3;
		cordinat3.y = y3;
		figyra.cordinat.push_back(cordinat3);
		cordinat4.x = x4;
		cordinat4.y = y4;
		figyra.cordinat.push_back(cordinat4);
		cordinat5.x = x5;
		cordinat5.y = y5;
		figyra.cordinat.push_back(cordinat5);

	}
	vec.push_back(figyra);						//вносим нашу фигуру в массив фигур

}

void Figures::print()
{
	
	std::cout << "Kolichestvo Figurs: " << vec.size() << "\n\n";						//печатаем кол-во фигур в массиве
	std::vector<Shape>::iterator iter;													//проходим его от начала до конца по итератору
	for (iter = vec.begin(); iter != vec.end(); iter++)
	{
		std::cout << "Figures:     " << iter->SHELEM << "\n";							//печатаем условное название елемента
		std::cout << "Kolichestvo peaks: " << iter->col_peak << "\n";					//печатаем кол-во вершин
		std::vector<Point>::iterator iter1 = iter->cordinat.begin();					//с помощью итераторов обходим наш вектор с вершинами
		std::vector<Point>::iterator iter2 = iter->cordinat.end();						//и выводим его на печать
		for (; iter1 != iter2; iter1++)
		{
			std::cout << iter1->x << ",";
			std::cout << iter1->y << " ";
			std::cout << "\n";
		}
		std::cout << "				" << "\n";
	}
}

void Figures::SumPeaks()															//подсчет суммы всех вершин в массиве с ипользованием функтора
{
	Functor C = std::for_each(vec.begin(), vec.end(), Functor());
	C.printSumm();
}

void Figures::SumFigurs()															//подсчет кол-ва каждых фигур в массиве фигур с использованием функтора
{
	Functor D = std::for_each(vec.begin(), vec.end(), Functor());
	D.printColichFig();
}

void Figures::DeletPug()															//удаляем пятиугольники
{


	auto q = std::remove_if(vec.begin(), vec.end(),
		[](const Shape& S)
		{
			return S.SHELEM == 3;													//ищем и сдвигаем итератором и функцией remove_if нужные нам элементы
		});
	vec.erase(q, vec.end());														//затем удалаем их
}

void Figures::sort()																//метод соритровки
{
	struct sort_class                                                               //сделаем не большую структуру для сортировки 
	{																				//по параметру элемента и ее результат передадим в алгоритм сорт
		bool operator()(Shape i, Shape j)
		{
			return (i.SHELEM < j.SHELEM);
		}
	}sortobj;

	std::sort(vec.begin(), vec.end(), sortobj);
}

void Figures::PushPoint(std::vector<Point>& P)						//заполняем вектор поинтеров значениями первых вершин нашего массива фигур
{
	std::transform(vec.begin(), vec.end(), std::back_inserter(P),
		[](const Shape& S)
		{
			return S.cordinat.at(2);
		});
}



int main()
{
	Figures figura;
	figura.putInFigures(TREUG, 0, 2, 6, 3, 3, 4);
	figura.putInFigures(PJATIYGOL, 5, 1, 2, 0, 7, 4, 9, 4, 3, 2);
	figura.putInFigures(KVADRAT, 4, 1, 2, 5, 3, 0, 1, 4);
	figura.putInFigures(PRAMOYGOL, 7, 0, 2, 1, 3, 5, 3, 1);
	figura.putInFigures(KVADRAT, 0, 11, 12, 15, 13, 0, 1, 14);
	figura.putInFigures(PJATIYGOL, 25, 1, 3, 0, 1, 2, 7, 1, 0, 1);
	figura.putInFigures(TREUG, 3, 1, 2, 2, 7, 9);
	figura.putInFigures(TREUG, 2, 6, 2, 0, 7, 9);

	std::cout << "----------------------------Figurs---------------------------------------\n";
	figura.print();
	figura.SumPeaks();
	figura.SumFigurs();
	std::cout << "\n-----------------------Delete pentagon-----------------------------------\n";

	figura.DeletPug();
	figura.print();
	figura.SumPeaks();
	figura.SumFigurs();
	std::cout << "\n-----------------------------Sort----------------------------------------\n";

	figura.sort();
	figura.print();
	figura.SumPeaks();
	figura.SumFigurs();

	std::cout << "\n-----------------------------Point----------------------------------------\n";

	std::vector<Point> point_vec;
	figura.PushPoint(point_vec);

	for (int i = 0; i < point_vec.size(); i++)
	{
		std::cout << point_vec[i].x << '\t' << point_vec[i].y << '\n';
	}
}
