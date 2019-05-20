#pragma once 
#include<iostream> 
using namespace std;
template<class T>
struct elem
{

	elem<T>*next;
	elem<T>*prev;
	T obj;
};
template<class T>
class list_
{
	elem<T>*head;
	elem<T>*tail;
	size_t size_;
public:
	list_();
	void push_back(const T& obj);
	void push_front(const T& obj);
	void pop_back();
	void pop_front();
	void insert(size_t pos, const T&obj);
	void erase(size_t pos);
	size_t size()const;
	const T& getElement(size_t pos)const;
	list_(const list_<T>&right);
	list_(list_<T>&&right);
	list_<T> operator=(const list_<T>&right);
	list_<T> operator=(list_<T>&&right);
	~list_;
	~list_();
	template<class T>
	friend ostream& operator<<(ostream&os, const list_<T>&l);
};

template<class T>
inline list_<T>::list_()
{
	head = tail = nullptr;
	size_ = 0;
}

template<class T>
inline void list_<T>::push_back(const T & obj)
{
	elem<T> *nel = new elem<T>;
	nel->obj = obj;
	if (size_ = 0)
	{
		nel->next = nel->prev = nullptr;
		head = tail = nel;
	}
	else {
		nel->next = nullptr;
		nel->prev = tail;
		tail->next = nel;
		tail = nel;
	}

	size_++;
}

template<class T>
inline void list_<T>::push_front(const T & obj)
{
	elem<T> *nel = new elem<T>;
	nel->obj = obj;
	if (size_ = 0)
	{
		nel->next = nel->prev = nullptr;
		head = tail = nel;
	}
	else {
		nel->next = head;
		nel->prev = nullptr;
		head->prev = nel;
		head = nel;
	}

	size_++;
}

template<class T>
inline void list_<T>::pop_back()
{
	if (size_ == 0)
	{
		return;
	}
	if (size_ == 1)
	{
		delete head;
		head = tail = nullptr;
		size_--;
		return;
	}
	tail = tail->prev;
	delete tail->next;
	tail->next = nullptr;
	size_--;
}

template<class T>
inline void list_<T>::pop_front()
{
	if (size_ == 0)
	{
		return;
	}
	if (size_ == 1)
	{
		delete head;
		head = tail = nullptr;
		size_--;
		return;
	}
	head = head->next;
	delete head->prev;
	head->prev = nullptr;
	size_--;
}

template<class T>
inline void list_<T>::insert(size_t pos, const T & obj)
{
	if (pos > size)
	{
		return;
	}

	if (pos == 0)
	{
		this->push_front(obj);
		return;
	}
	if (pos == size)
	{
		this->push_back(obj);
		return;
	}
	elem<T> *nel = new elem<T>;
	nel->obj = obj;
	elem<T> *tmp;
	if (size_ - pos < size_ / 2)
	{
		pos = size_ - pos;
		tmp = tail;
		for (size_t i = 0; i < pos - 1; i++)
		{
			tmp = tmp->prev;
		}
	}
	else
	{
		tmp = head;
		for (size_t i = 0; i < pos - 1; i++)
		{
			tmp = tmp->next;
		}
	}
	nel->next = tmp;
	nel->prev = tmp->prev;
	tmp->prev->next = nel;
	nel->next->prev = nel;
	size++;
}

template<class T>
inline void list_<T>::erase(size_t pos)
{
	if (pos > size)
	{
		return;
	}

	if (pos == 0)
	{
		this->pop_front(obj);
		return;
	}
	if (pos == size)
	{
		this->push_back(obj);
		return;
	}
	elem<T> *tmp;
	if (size_ - pos < size_ / 2)
	{
		pos = size_ - pos;
		tmp = tail;
		for (size_t i = 0; i < pos; i++)
		{
			tmp = tmp->prev;
		}
	}
	else
	{
		tmp = head;
		for (size_t i = 0; i < pos; i++)
		{
			tmp = tmp->next;
		}
	}
	tmp->next->prev = tmp->prev;
	tmp->prev->next = tmp->next;
	delete tmp;
	size--;
}

template<class T>
inline size_t list_<T>::size() const
{
	return size_
}

template<class T>
inline const T & list_<T>::getElement(size_t pos) const
{
	if (pos > size)
	{
		return;
	}

	if (pos == 0)
	{
		return head->obj;
	}
	if (pos == size)
	{
		return tail->obj;
	}
	elem<T> *tmp;
	if (size_ - pos < size_ / 2)
	{
		pos = size_ - pos;
		tmp = tail;
		for (size_t i = 0; i < pos; i++)
		{
			tmp = tmp->prev;
		}
	}
	else
	{
		tmp = head;
		for (size_t i = 0; i < pos; i++)
		{
			tmp = tmp->next;
		}
	}
	return tmp->obj;
}

template<class T>
inline list_<T>::list_(const list_<T>& right)
{
	this->size_ = right.size_;
	if (size_ == 0)
	{
		head = nullptr;
		tail = nullptr;
		return;
	}
	elem<T> *tmp;
	tmp = right.head;
	for (size_t i = 0; i < this->size_; i++)
	{
		this->push_back(tmp->obj);
		tmp = tmp->next;
	}
}

template<class T>
inline list_<T>::list_(list_<T>&& right)
{
	this->size_ = 0;
	swap(this->size_, right.size_);
	head = nullptr;
	tail = nullptr;
	swap(this->head, right.head);
	swap(this->tail, right.tail);
}

template<class T>
inline list_<T> list_<T>::operator=(const list_<T>& right)
{
	if (this == &right)
	{
		return *this<T>;
	}
	this->~list_();
	this->size_ = right.size_;
	if (size_ == 0)
	{
		head = nullptr;
		tail = nullptr;
		return *this;
	}
	elem<T> *tmp;
	tmp = right.head;
	for (size_t i = 0; i < this->size_; i++)
	{
		this->push_back(tmp->obj);
		tmp = tmp->next;
	}
	return *this<T>;
}

template<class T>
inline list_<T> list_<T>::operator=(list_<T>&& right)
{
	swap(this->size_, right.size_);
	swap(this->head, right.head);
	swap(this->tail, right.tail);
	return *this<T>;
}

template<class T>
inline list_<T>::~list_()
{
	while (tail != nullptr)
	{
		pop_back();
	}
}

template<class T>
inline ostream & operator<<(ostream & os, const list_<T>& l)
{
	elem <T> *tmp = l.head;
	for (size_t i = 0; i < l.size_; i++)
	{
		cout << tmp->obj << " ";
		tmp = tmp->next;
	}
	return os;
}