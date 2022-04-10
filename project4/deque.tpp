#include "deque.hpp"

template <typename T>
Deque<T>::Deque() {}

template <typename T>
Deque<T>::Deque(const Deque& x)
{
	list = x.list;
}

template <typename T>
Deque<T>::~Deque()
{
	for(int i = 0; i < list.getLength(); i++)
		popBack();
}

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque<T>& x)
{
	list = x.list;
	return *this;
}

template <typename T>
bool Deque<T>::isEmpty() const noexcept
{
	return list.isEmpty();
}

template <typename T>
void Deque<T>::pushFront(const T & item)
{
	list.insert(0, item);
}

template <typename T>
void Deque<T>::popFront()
{
	list.remove(0);
}

template <typename T>
T Deque<T>::front() const
{
	return list.getEntry(0);
}

template <typename T>
void Deque<T>::pushBack(const T & item)
{
	list.insert(list.getLength(), item);
}

template <typename T>
void Deque<T>::popBack()
{
	list.remove(list.getLength() - 1);
}

template <typename T>
T Deque<T>::back() const
{
	return list.getEntry(list.getLength() - 1);
}
