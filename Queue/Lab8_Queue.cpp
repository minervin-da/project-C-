#include <iostream>
#include <iterator>

template<class T>
class Queue
{
	static const int START_SIZE = 100;
	int first,
		last,
		size_;
	T *queue;

public:
	class Iterator
	{
	private:
		T* A;
	public:
		Iterator(T* a) { A = a; }
		//~Iterator() {}
		T& operator++(int) { return *(A++); }
		T& operator++() { return *(++A); }
		T& operator--(int) { return *(A--); }
		T& operator--() { return *(--A); }
		T& operator*() { return *A; }
		T& operator+(int n) { return *(A + n); }
		T& operator-(int n) { return *(A - n); }
		bool operator=(const Iterator& it) { return A == it.A; }
		bool operator!=(const Iterator& it) { return A != it.A; }
		bool operator==(const Iterator& it) { return (A == it.A); }
	};
	Queue(int SIZE);
	Queue(void);
	~Queue();
	Queue(const Queue& s);
	void push_back(int &value);
	void pop_front(void);
	void out(void);
	T& front(void);
	Iterator erase(Iterator p);
	Iterator insert(Iterator position, const T& value);
	T& operator[](int i);
	void swap(Queue& that);
	Queue& operator=(Queue& that);
	Iterator begin() { return Queue<T>::Iterator(queue); }
	Iterator end() { return Queue<T>::Iterator(queue + last); }
	void clear(void);
	bool empty(void);
};


template<class T>
Queue<T>::Queue(void): size_(START_SIZE), last(NULL), first(NULL)
{
	queue = new int[size_];
}

template<class T>
Queue<T>::Queue(int SIZE) : size_(SIZE), last(NULL), first(NULL)
{
	if (SIZE < 1)
		size_ = START_SIZE;
	queue = new T[size_];
}

template<class T>
Queue<T>::Queue(const Queue<T>& s): size_(s.size_)
{
	this->queue = new T[size_];
	this->last = s.last;
	this->first = s.first;
	for (int i = 0; i < size_; i++)
		this->queue[i] = s.queue[i];	
}

template<class T>
Queue<T>::~Queue()
{
	delete [] queue;
}

template<class T>
void Queue<T>::push_back(int &value)
{

	last++;
	queue[last] = value;
	queue[first] = value;
	if (last + 1 == first || (last + 1 == size_ && !first))
	{
		const double COEFF = 1.6;
		size_ =this->size_ * COEFF;
		last =this->last + 1;
		T* tmp = new T[size_];
		for(int i =0; i < last - 1; i++)
		{
			tmp[i] = this->queue[i];
		}
		delete [] this->queue;
		this->queue = tmp;
	}
}

template<class T>
void Queue<T>::pop_front(void)
{
	if (first == last)
	{
		std::cout << "the queue is empty" << std::endl;
		return;
	}
	first++;
	if (first == size_)
		first = 0;
}

template<class T>
void Queue<T>::out(void)
{
	for (int i = first + 1; i < last + 1; i++)
		std::cout << ' ' << queue[i];
}

template<class T>
T& Queue<T>::front(void)
{
	return queue[first];
}

template<class T>
void Queue<T>::swap(Queue& that)
{	
	std::swap(size_, that.size_);
	std::swap(first, that.first);
	std::swap(last, that.last);
	std::swap(queue, that.queue);

}

template<class T>
Queue<T>& Queue<T>::operator=(Queue& that)
{
	if (this == &that)
		return *this;
	delete[] this->queue;
	this->queue = new T[this->size_ = that.size_];
	this->last = that.last;
	this->first = that.first;
	for (int i = 0; i < size_; i++)
		this->queue[i] = that.queue[i];
	return *this;
}

template<class T>
T& Queue<T>::operator[](int i)
{
	return queue[i];
}

template<class T>
typename Queue<T>::Iterator Queue<T>::erase(Iterator p)
{
	{
		for (p; p != end(); p++)
		{
			*p = (p + 1);

		}
		last--;
		return p;

	}
}

template<class T>
typename Queue<T>::Iterator Queue<T>::insert(Iterator position, const T& value)
{
	if (last + 1 == first || (last + 1 == size_ && !first))
	{
		const double COEFF = 1.6;
		size_ = this->size_ * COEFF;
		last = this->last + 1;
		T* tmp = new T[size_];
		for (int i = 0; i < last - 1; i++)
		{
			tmp[i] = this->queue[i];
		}
		delete[] this->queue;
		this->queue = tmp;
	}

	for (Iterator q(this->end()); q != position; q++)
		*q = (q - 1);
	*position = value;
	last = last + 1;
	return position;	
}

template<class T>
void Queue<T>::clear(void)
{
	return 0;
}

template<class T>
bool Queue<T>::empty()
{
	if (last == 0)
		return true;
	else
		return false;
}

int main()
{
	int n = 2;
	Queue<int> queue1;
	Queue<int> queue2;


	for (int i = 0; i < 10; i++)
	{
		queue1.push_back(i);
	}
	for (int i = 0; i < 15; i++)
	{
		queue2.push_back(i);
	}

	std::cout << "Push 1: ";
	queue1.out();
	std::cout << std::endl;
	std::cout << "Push 2: ";
	queue2.out();


	queue2.pop_front();
	std::cout << std::endl;
	std::cout << "Pop: ";
	queue2.out();

	std::cout << std::endl;
	queue1.push_back(n);
	std::cout << "Push 1 adding number: ";
	queue1.out();

	std::cout << std::endl;
	std::cout << "Front: ";
	std::cout << queue2.front() << std::endl;
	
	queue1.swap(queue2);
	std::cout << "Swap 1: ";
	queue1.out();
	std::cout << std::endl;
	std::cout << "Swap 2: ";
	queue2.out();

	Queue<int>::Iterator i(queue1.begin());
	Queue<int>::Iterator z(queue1.end());
	Queue<int>::Iterator j(queue2.begin());
	Queue<int>::Iterator b(queue2.end());
	std::cout << std::endl;


	for (; i != z; i++)
		std::cout << *i << ' ';
	
	/*queue2.erase(b);
	queue2.out();

	std::cout << std::endl;

	queue1.insert(i, n);
	queue1.out();*/


}