//Необходимо выполнить ВСЕ задания :
//1.	Разработать программу, которая, используя только стандартные алгоритмы и функторы, умножает каждый элемент списка 
//чисел с плавающей  точкой на число PI

//2.	Разработать программу, которая:
//a.Реализует иерархию геометрических фигур состоящую из :
//i.Класс Shape.
//1.	Содержит информацию о положении центра фигуры(координаты x и y).
//2.	Содердит метод IsMoreLeft, позволяющий определить расположена ли данная фигура левее
//(определяется по положению центра) чем фигура переданная в качестве аргумента
//3.	Содердит метод IsUpper, позволяющий определить расположена ли данная фигура выше
//(определяется по положению центра) чем фигура переданная в качестве аргумента
//4.	Определяет чисто виртаульную функцию рисования Draw
//(каждая фигура в реализации этой функци должна выводить на стандартный вывод свое название и положение цента)
//ii.Класс Circle производный от класса Shape
//1.	Реализует Draw
//iii.Класс Triangle производный от класса Shape
//1.	Реализует Draw
//iv.Класс Square производный от класса Shape
//1.	Реализует Draw
//b.Содержит список list<Shape*>, заполенный указателями на различные фигуры
//c.С помощью стандартных алгоритмов и адаптеров выводит(Draw) все фигуры
//d.С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра слева - направо
//(имется в виду, что в начале списка должны идти фигуры находящиеся левее, координата x) и выводит фигуры(Draw)
//e.С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра справа - налево и выводит фигуры
//f.С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра сверху - вниз и выводит фигуры
//g.С помощью стандартных алгоритмов и адаптеров сортирует список по положению центра снизу - вверх и выводит фигуры

#include <iostream>
#include <list>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>



class Functor_PI
{
public:
	double PI = 3.14;
	double operator()(double& val)
	{
		val = val * PI;
		return val;
	}
};


class Shape
{
public:
	int x;															//Координаты центра фигуры
	int y;

	Shape();														//Конструктор по умолчанию
	Shape(int _x, int _y);											//Конструктор с параметрами
	virtual ~Shape();												//вирутальный деструктор
	
	bool IsMoreLeft(const Shape* Sp) const;							//позволяет оперделить,расположена ли фигура левее,чем фигура переданная в качестве параметра
	bool IsUpper(const Shape* Sp) const;							//позволяет оперделить,расположена ли фигура выше,чем фигура переданная в качестве параметра
	virtual void Draw() const = 0;
};
Shape::Shape()														//Конструктор по умолчанию
{
	int x = 0;
	int y = 0;
}

Shape::Shape(int _x, int _y)										//Конструктор с параметрами
{
	this->x = _x;
	this->y = _y;
}

Shape::~Shape()														//деструктор
{

}


bool Shape::IsMoreLeft(const Shape* Sp) const						//определение левее ли наша фигура
{
	return (x < Sp->x);												//если по оси х меньше значение нашей фигуры то левее в остальных случаях нет

}

bool Shape::IsUpper(const Shape* Sp) const							//определение выше ли наша фигура
{
	return (y > Sp->y);												//если по оси у значение нашей фигуры больше, то тогда выше, в остальных случаях нет


}


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

class Circle : public Shape
{
public:
	Circle() :Shape() {}
	Circle(int x, int y) :Shape(x, y) {}
	void Draw() const override;

};

void::Circle::Draw() const
{
	std::cout << "Circle  : " << x << "," << y << "\n";
}

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

class Triagle : public Shape
{
public:
	Triagle() :Shape() {}
	Triagle(int x, int y) :Shape(x, y) {}
	void Draw() const override;
};
void::Triagle::Draw() const
{
	std::cout << "Triagle : " << x << "," << y << "\n";
}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

class Square : public Shape
{
public:
	Square() : Shape() {}
	Square(int x, int y) :Shape(x, y) {}
	void Draw()const  override;
};
void::Square::Draw() const
{
	std::cout << "Square : " << x << "," << y << "\n";
}


int main()
{
	std::list<double> mas = {2.4, 3.0, 5.1, 0.4, 2.0, 1.5};
	for (std::list<double>::iterator it = mas.begin(); it != mas.end(); it++)
	{
		std::cout << *it << '\t';
	}
	std::cout << "\n----------------------------------------------------------------\n";
	std::for_each(mas.begin(), mas.end(), Functor_PI());

	for (std::list<double>::iterator it = mas.begin(); it != mas.end(); it++)
	{
		std::cout << *it << '\t';
	}

	//------------------------------------------------------------------------------------------------------------------------------

	Circle c1(2, 30);
	Triagle t1(10, 4);
	Square s1(3, 5);
	Circle c2(6, 10);
	Triagle t2(7, 6);
	Square s2(0, 0);
	Circle c3(11, 11);
	Triagle t3(8, 2);
	Square s3(5, 7);

	std::list<Shape*> figura;						//создаем  список лист заполненый указателями на различные фигуры(b)
	figura.push_back(&c1);
	figura.push_back(&t1);
	figura.push_back(&s1);
	figura.push_back(&c2);
	figura.push_back(&t2);
	figura.push_back(&s2);
	figura.push_back(&c3);
	figura.push_back(&t3);
	figura.push_back(&s3);

	//выводим Draw е фигуры

	std::cout << "\n\n---------------------------Draw Figurs-------------------------------------\n";
	std::for_each(figura.begin(), figura.end(), std::const_mem_fun_t<void, Shape>(&Shape::Draw));
	std::cout << "\n----------------------------------------------------------------\n";

	//сортировка слева-направо

	std::cout << "\nleft->right: \n";
	figura.sort(std::mem_fun(&Shape::IsMoreLeft));
	std::for_each(figura.begin(), figura.end(), std::mem_fun(&Shape::Draw));
	std::cout << "\n----------------------------------------------------------------\n";

	//сортировка справа-налево

	std::cout << "\nright->left: \n";
	figura.sort(std::mem_fun(&Shape::IsMoreLeft));
	std::reverse(std::begin(figura), std::end(figura));
	std::for_each(figura.begin(), figura.end(), std::mem_fun(&Shape::Draw));
	std::cout << "\n----------------------------------------------------------------\n";

	//сортировка сверху вниз

	std::cout << "\nUP: \n";
	figura.sort(std::mem_fun(&Shape::IsUpper));
	std::for_each(figura.begin(), figura.end(), std::mem_fun(&Shape::Draw));
	std::cout << "\n----------------------------------------------------------------\n";

	//сортировка сверху вниз

	std::cout << "\nDOWN: \n";
	figura.sort(std::mem_fun(&Shape::IsUpper));
	std::reverse(std::begin(figura), std::end(figura));
	std::for_each(figura.begin(), figura.end(), std::mem_fun(&Shape::Draw));
	return 0;
}