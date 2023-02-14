
// Junayad Bin Forhad
// 160158218
// 09/08/2022

// WeightedList.h - class definitions for a weighted list

#ifndef _WEIGHTEDLIST_H_
#define _WEIGHTEDLIST_H_

#include <iostream>

template <typename T>

class WeightedList
{
    struct Node
    {
        T data;
        Node *next;

        Node(const T &_data)
        {
            data = _data;
            next = nullptr;
        }
    };
    Node *front;
    int num;

public:
    // TODO: Complete the iterator class
    class iterator
    {
        friend class WeightedList;
        Node *current;
        iterator(Node *_current)
        {
            current = _current;
        }

    public:
        iterator()
        {
            current = nullptr;
        }
        T &operator*()
        {
            return current->data;
        }
        iterator &operator++()
        {
            current = current->next;
            return *this;
        }
        iterator operator++(int)
        {
            iterator temp = *this;
            current = current->next;
            return temp;
        }
        bool operator==(const iterator &rhs)
        {
            return current == rhs.current;
        }
        bool operator!=(const iterator &rhs)
        {
            return current != rhs.current;
        }
    };

    // TODO: Complete the weighted list functionality.
    //       You can put your function declarations or prototypes here
    //       and function definitions or implementations below

    WeightedList();                                   // A default constructor for the list.
    WeightedList(const WeightedList &rhs);            // A copy constructor for the list.
    WeightedList &operator=(const WeightedList &rhs); // A copy assignment for the list.
    WeightedList(WeightedList &&rhs);                 // A move constructor for the list.
    WeightedList &operator=(WeightedList &&rhs);      // A move assignment for the list.
    iterator begin();                                 // Return an iterator to the beginning of the list.
    iterator end();                                   // Return an iterator to the end of the list.
    void push_back(const T &data);                    // Push data of type T to the end of the list.
    iterator search(const T &data);                   // Search for an item with value data. Return the iterator to this item.
    iterator erase(iterator it);                      // Erase a data item. Return the iterator to the next item.
    iterator erase(iterator begin, iterator end);     // Erase a range of data items from begin to end excluding end. Return an iterator to end.
    bool empty() const;                               // Return true if the list is empty, false otherwise.
    int size() const;                                 // Return the number of data items in the list.
    ~WeightedList();                                  // A destructor for the weighted list.
    iterator operator++();                            // Perform pre-increment on an iterator and return the next iterator.
    iterator operator++(int);                         // Return the current iterator then perform a post-increment on it.
    bool operator==(iterator rhs);                    // Return true if both iterators point to the same data item, false otherwise.
    bool operator!=(iterator rhs);                    // Return false if both iterators point to the same data item, true otherwise.
    T &operator*();                                   // A reference to the data element referred to by the iterator.
};

template <typename T>
WeightedList<T>::WeightedList()
{
    front = nullptr;
    num = 0;
}

template <typename T>
WeightedList<T>::WeightedList(const WeightedList &rhs)
{
    front = nullptr;
    num = 0;
    Node *temp = rhs.front;
    while (temp != nullptr)
    {
        push_back(temp->data);
        temp = temp->next;
    }
}

template <typename T>
WeightedList<T> &WeightedList<T>::operator=(const WeightedList &rhs)
{
    if (this != &rhs)
    {
        // delete the current list
        Node *temp = front;
        while (temp != nullptr)
        {
            temp = temp->next;
            delete temp;
        }

        front = nullptr;
        num = 0;
        temp = rhs.front;
        while (temp != nullptr)
        {
            push_back(temp->data);
            temp = temp->next;
        }
    }
    return *this;
}

template <typename T>
WeightedList<T>::WeightedList(WeightedList &&rhs)
{
    front = rhs.front;
    num = rhs.num;
    rhs.front = nullptr;
    rhs.num = 0;
}

template <typename T>
WeightedList<T> &WeightedList<T>::operator=(WeightedList &&rhs)
{
    if (this != &rhs)
    {
        // delete the current list
        Node *temp = front;
        while (temp != nullptr)
        {
            temp = temp->next;
            delete temp;
        }

        front = rhs.front;
        num = rhs.num;
        rhs.front = nullptr;
        rhs.num = 0;
    }
    return *this;
}

template <typename T>
typename WeightedList<T>::iterator WeightedList<T>::begin()
{
    return iterator(front);
}

template <typename T>
typename WeightedList<T>::iterator WeightedList<T>::end()
{
    return iterator(nullptr);
}

template <typename T>
void WeightedList<T>::push_back(const T &data)
{
    Node *temp = new Node(data);
    if (front == nullptr)
    {
        front = temp;
    }
    else
    {
        Node *temp2 = front;
        while (temp2->next != nullptr)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp;
    }
    num++;
}

template <typename T>
typename WeightedList<T>::iterator WeightedList<T>::search(const T &data)
{
    // if front is nullptr, return end()
    if (front == nullptr)
    {
        return end();
    }
    // if data is present at front, do nothing
    if (front->data == data)
    {
        return begin();
    }

    // find the previous element of the data element
    Node *prev1 = nullptr; // one step before the data element
    Node *prev2 = nullptr; // two steps before the data element
    Node *temp = front;
    while (temp != nullptr && temp->data != data)
    {
        prev2 = prev1;
        prev1 = temp;
        temp = temp->next;
    }

    // if data is not found, return end()
    if (temp == nullptr)
    {
        return end();
    }
    if (temp == front)
    {
        return begin();
    }

    // if data is found, move it up by one space in the list
    if (prev2 != nullptr)
    {
        prev2->next = temp;
        if (temp == front)
        {
            prev2 = temp;
        }
    }
    if (prev1 != nullptr)
    {
        prev1->next = temp->next;
        if (prev1 == front)
        {
            front = temp;
        }
    }
    temp->next = prev1;

    return iterator(temp);
}

template <typename T>
typename WeightedList<T>::iterator WeightedList<T>::erase(iterator it)
{
    // if it is end(), return end()
    if (it == end())
    {
        return end();
    }
    // if it is begin(), delete the first element
    if (it == begin())
    {
        Node *temp = front;
        front = front->next;
        delete temp;
        num--;
        return begin();
    }
    Node *prev = front;
    while (prev->next != it.current)
    {
        prev = prev->next;
    }
    prev->next = it.current->next;
    delete it.current;
    num--;
    return iterator(prev->next);
}

template <typename T>
typename WeightedList<T>::iterator WeightedList<T>::erase(iterator begin, iterator end)
{
    while (begin != end)
    {
        begin = erase(begin);
    }
    return begin;
}

template <typename T>
bool WeightedList<T>::empty() const
{
    return num == 0;
}

template <typename T>
int WeightedList<T>::size() const
{
    return num;
}

template <typename T>
WeightedList<T>::~WeightedList()
{
    erase(begin(), end());
}

#endif // _WEIGHTEDLIST_H_