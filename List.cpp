#include <initializer_list>
#include "List.hpp"
#include <iostream>

template<typename T>
List<T>::List(std::initializer_list<T> il)
{
    for (auto &&i : il)
    {
        this->push_back(i);
    }
    
}

template <typename T>
typename List<T>::Node& List<T>::Iterator::operator*() const
{
    return *m_current;
}

template <typename T>
typename List<T>::Node* List<T>::Iterator::operator->() const
{
    return m_current;
}

template <typename T>
const typename List<T>::Iterator List<T>::Iterator::operator++(int)
{
    Node* tmp = m_current;
    if (m_current)
    {
        m_current = m_current->m_next;
    }
    return Iterator(tmp);
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++() //&
{
    operator++(0);
    return *this;
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator& rhs) const
{
    return this->m_current == rhs.m_current ? true : false;
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& rhs) const
{
    return this->m_current != rhs.m_current ? true : false;
}

template<typename T>
typename List<T>::Iterator List<T>::Iterator::operator+(int num)
{
    while (num)
    {
        m_current = m_current->m_next;
        --num;
    }
    return *this;
    
}

template <typename T>
void List<T>::push_back(const T& value)
{
    if (m_head == nullptr)
    {
        m_head = new Node(value);
    }
    else
    {
        Node* current = m_head;
        while (current->m_next)
        {
            current = current->m_next;
        }
        
        current->m_next = new Node(value);
    }
    ++m_size;
}

template <typename T>
void List<T>::push_front(const T& value)
{
    Node* nptr = new Node(value);
    Node* tmp = m_head;
    m_head = nptr;
    m_head->m_next = tmp;
    ++m_size;

}

template <typename T>
void List<T>::pop_back()
{
    if (!m_size)
    {
        return;
    }

    if (m_size == 1) {
        delete m_head;
        m_head = nullptr;
        m_size = 0;
        return;
    }
    Iterator it = begin();
    Iterator prev = it;
    ++it;

    while ((*it).m_next != end())
    {
        ++it;
        ++prev;
    }
    delete (*prev).m_next;
    (*prev).m_next = nullptr;
    --m_size;
}

template <typename T>
void List<T>::pop_front()
{
    if (!m_size)
    {
        return;
    }

    Node* tmp_next = m_head->m_next;
    delete m_head;
    m_head = tmp_next;
    
    --m_size;
}

template <typename T>
void List<T>::insert(Iterator pos, T value)
{
    Node* tmp = new Node(value);
    Node* next = (*pos).m_next;
    (*pos).m_next = tmp;
    (pos + 1)->m_next = next;
}

template <typename T>
T List<T>::front() const
{
    return (*(this->begin())).m_data;
}

template <typename T>
T List<T>::back() const
{
    Iterator it = begin();
    return (*(it + (m_size - 1))).m_data;
}

template <typename T>
unsigned int List<T>::size() const
{
    return m_size;
}

template <typename T>
typename List<T>::Iterator List<T>::begin() const
{
    return Iterator(m_head);
}

template <typename T>
typename List<T>::Iterator List<T>::end() const
{
    return Iterator(nullptr);
}
