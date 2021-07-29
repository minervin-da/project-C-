/*1.	Ниже приведен интерфейс класса очереди с приоритетами, который функционирует следующим образом.

В очередь могут быть добавлены элементы, каждому элементу при добавлении присваивается один из трех уровней приоритета(low, normal, high)

Элементы из очереди извлекаются в соответствии с их приоритетами(сначала извлекаются элементы с приоритетом high, потом normal, потом low), 
элементы с одинаковыми приоритетами извлекаются из очереди в порядки их поступления.

В очереди также может происходить операция акселерации – все элементы с приоритетом low находящиеся в момент акселерации в очереди увеличивают
свой приоритет до high и «обгоняют» элементы с приоритетом normal.

Реализовать этот класс, используя list или deque.Объяснить свой выбор.
Протестируете программу, добавьте отладочный вывод, показывающий, что  класс работает правильно.*/




#include <iostream>
#include <list>
#include <iterator>
#include <string>


typedef enum
{
    LOW,
    NORMAL,
    HIGN
}ElementPriority;

 struct QueueElement
{
    ElementPriority priority;
    std::string name;
    QueueElement(std::string name, ElementPriority priority);
};

 QueueElement::QueueElement(std::string _name, ElementPriority _priority)
 {
     this->name = _name;
     this->priority = _priority;
 }

class QueueWithPriority
{

    std::list<QueueElement> elem;

public:
    QueueWithPriority() {};
    ~QueueWithPriority() {};
    void PutElementToQueue(const QueueElement& element);
    QueueElement GetElementFromQueue();
    void Accelerate();
    void print();
};

void QueueWithPriority::PutElementToQueue(const QueueElement& element)
{
    std::list<QueueElement>::iterator iter;
    int check;
    bool insert = false;
    if ((!elem.empty()) & (element.priority != LOW))                    //если очередь не пуста и приоритет не нижайший
    {
        for (iter = elem.begin(); iter != elem.end(); iter++)
        {
            check = iter->priority - element.priority;                  //вычисляем тмп,если -1 то элемент встанет на свое нужное место
            if (check == -1)                                            //поподание элемента на свое место
            {
                elem.insert(iter, element);                             //вставка элемента
                insert = true;
                break;
            }
        }
        if (!insert)
        {
            elem.push_front(element);
        }
    }
    else {
        elem.push_back(element);                                    //Добавляем эл-т
    }
}

QueueElement QueueWithPriority::GetElementFromQueue()               //возвращаем первый приоритетный элемент
{
    if (!elem.empty())                                              //если очередь не пуста
    {

        QueueElement qu = elem.front();                             //получаем первый приоритетный элемент
        return qu;
    }
    else
        std::cout << "Error!!!\n ";
}

void QueueWithPriority::Accelerate()
{
    std::list< QueueElement>::iterator iter1;
    std::list< QueueElement>::iterator iter2;
    std::list< QueueElement>::iterator iter3;


    for (iter1 = --elem.end(); iter1 != elem.begin(); iter1--)      //проходим от конца по списку и заменяем LOW на HIGH
    {
        if (iter1->priority == LOW)
        {
            iter1->priority = HIGN;
            iter2 = iter1;                                          //получаем позицию последнего замененого элемента

        }

    }

    for (iter3 = elem.begin(); iter3 != elem.end(); iter3++)        //проходим от начала к концу списка
    {
        if (iter3->priority == NORMAL)                              //когда попадаем на начало нормалов, то переносим их за нашу полученную позицию iter2
        {
            elem.splice(iter3, elem, iter2, elem.end());
            break;                                                  //и заканчиваем операцию
        }

    }


}


void QueueWithPriority::print()
{
    std::list< QueueElement>::iterator iter;
    for (iter = elem.begin(); iter != elem.end(); iter++)
    {
        std::cout << iter->priority << '\t' << iter->name << "\n";

    }
}

int main()
{
    QueueElement e1("Dima", LOW), e2("Kolja", HIGN), e3("Misha", LOW), e4("Dasha", NORMAL), e5("Sidor", LOW),
                 e6("Juri", HIGN), e7("Katya", LOW), e8("Ivan", LOW), e9("Pavel", NORMAL), e10("Kiril", HIGN), e11("Anna", NORMAL);

    QueueWithPriority element;
    element.PutElementToQueue(e1);
    element.PutElementToQueue(e2);
    element.PutElementToQueue(e3);
    element.PutElementToQueue(e4);
    element.PutElementToQueue(e5);
    element.PutElementToQueue(e6);
    element.PutElementToQueue(e7);
    element.PutElementToQueue(e8);
    element.PutElementToQueue(e9);
    element.PutElementToQueue(e10);
    element.PutElementToQueue(e11);

    element.print();

    std::cout << "--------------------------------------------------------------------\n";

    QueueElement e12 = element.GetElementFromQueue();

    std::cout << e1.priority << '\t' << e1.name << '\n';

    std::cout << "---------------------------------------------------------------------\n";

    element.Accelerate();

    element.print();
}