#include "linked_list.hpp"

template <typename T>
LinkedList<T>::LinkedList()
{
  itemCount = 0;
  headPtr = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  itemCount = x.itemCount;
  Node<T>* origPtr = x.headPtr;
  if (origPtr == nullptr)
  	headPtr = nullptr;
  else
  {
  	headPtr = new Node<T>();
  	headPtr -> setItem(origPtr -> getItem());
  	Node<T>* newPtr = headPtr;
  	origPtr = origPtr -> getNext();
  	while (origPtr != nullptr)
  	{
  		T nextItem = origPtr -> getItem();
  		Node<T>* newNodePtr = new Node<T>(nextItem);
  		newPtr -> setNext(newNodePtr);
  		newPtr = newPtr -> getNext();
  		origPtr = origPtr -> getNext();
  	}
  }
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T>& x, LinkedList<T>& y)
{
  LinkedList<T> temp(x);
  x = y;
  y = temp;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& x)
{
  itemCount = x.itemCount;
  Node<T>* origPtr = x.headPtr;
  if (origPtr == nullptr)
  	headPtr = nullptr;
  else
  {
  	headPtr = new Node<T>();
  	headPtr -> setItem(origPtr -> getItem());
  	Node<T>* newPtr = headPtr;
  	origPtr = origPtr -> getNext();
  	while (origPtr != nullptr)
  	{
  		T nextItem = origPtr -> getItem();
  		Node<T>* newNodePtr = new Node<T>(nextItem);
  		newPtr -> setNext(newNodePtr);
  		newPtr = newPtr -> getNext();
  		origPtr = origPtr -> getNext();
  	}
  }
  return *this;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
  return (itemCount == 0);
}

template <typename T>
std::size_t LinkedList<T>::getLength() const
{
  return itemCount;
}

template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  bool canInsert = (position >= 0) && (position <= itemCount);
  if (position == 0)
  {
  	Node<T>* newNodePtr = new Node<T>(item);
  	newNodePtr -> setNext(headPtr);
  	headPtr = newNodePtr;
  	itemCount++;
  	return true;
  }
  Node<T>* prevPtr = getNodeAt(position - 1);
  bool isValid;
  if (position + 1 < itemCount)
  {
  	Node<T>* postPtr = getNodeAt(position + 1);
  	if (position >= 1)
  	{
  		isValid = (prevPtr -> getItem() < item) && (postPtr -> getItem() > item);
  	}
  	else
  	{
  		isValid = (postPtr -> getItem()) > item;
  	}
  }
  else
  {
  	isValid == true;
  }
  if(canInsert)
  {
  	Node<T>* newNodePtr = new Node<T>(item);
  	newNodePtr -> setNext(prevPtr -> getNext());
  	prevPtr -> setNext(newNodePtr);
  	itemCount++;
  }
  else
  {
  	throw(std::range_error("error in range"));
  }
  return canInsert;
}

template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  bool canRemove = (position >= 0) && (position <= itemCount - 1);
  if (canRemove)
  {
  	Node<T>* curPtr = nullptr;
  	if (position == 0)
  	{
  		curPtr = headPtr;
  		headPtr = headPtr -> getNext();
  	}
  	else
  	{
  		Node<T>* prevPtr = getNodeAt(position - 1);
  		curPtr = prevPtr -> getNext();
  		prevPtr -> setNext(curPtr -> getNext());
	}
	curPtr -> setNext(nullptr);
	delete curPtr;
	curPtr = nullptr;
	itemCount--;
  }
  else
  {
  	throw(std::range_error("error in range"));
  }
  return canRemove;
}

template <typename T>
void LinkedList<T>::clear()
{
  while (!isEmpty())
  {
  	remove(0);
  }
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
  bool canGet = (position >= 0) && (position < itemCount);
  if (canGet)
  {
  	Node<T>* nodePtr = getNodeAt(position);
  	return nodePtr -> getItem();
  }
  else
  {
  	throw(std::range_error("error in range"));
  }
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  bool canSet = (position >= 0) && (position <= itemCount);
  Node<T>* prevPtr = getNodeAt(position - 1);
  bool isValid;
  if (position <= itemCount)
  {
  	Node<T>* postPtr = getNodeAt(position);
  	if (position >= 1)
  	{
  		isValid = (prevPtr -> getItem() < newValue) && (postPtr -> getItem() > newValue);
  	}
  	else
  	{
  		isValid = (postPtr -> getItem()) > newValue;
  	}
  }
  else
  {
  	isValid = true;
  }
  if (canSet)
  {
  	while (itemCount > position)
  	{
  		remove(position);
  	}
  	insert(position, newValue);
  }
  else
  {
  	throw(std::range_error("error in range"));
  }
}

template <typename T>
Node<T>* LinkedList<T>::getNodeAt(int position) const
{
  Node<T>* curPtr = headPtr;
  for (std::size_t next = 0; next < position; next++)
  {
  	curPtr = curPtr -> getNext();
  }
  return curPtr;
}
