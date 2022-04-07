#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"

template <typename T>
class Deque: public AbstractDeque<T>{
	public:
		Deque();
		Deque(const Deque& x);
		~Deque();
		Deque& operator=(const Deque& x);
		bool isEmpty() const noexcept;
		void pushFront(const T & item);
		void popFront();
		T front() const;
		void pushBack(const T & item);
		void popBack();
		T back() const;
		
	private:
		LinkedList<T> list;
  
};

#include "deque.tpp"

#endif
