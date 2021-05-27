#ifndef STATICQUEUETEMPLATE_H
#define STATICQUEUETEMPLATE_H
#include <iostream>
using namespace std;

// Stack template
template <class T>
class StaticQueueTemplate
{
private:
    T* queueArray;		// Points to the queue array
    int queueSize;		// The queue size
    int front;			// Subscript of the queue front
    int rear;			// Subscript of the queue rear
    int numItems;		// Number of items in the queue
public:
    // Constructor
    StaticQueueTemplate(int);

    // Copy constructor
    StaticQueueTemplate(const StaticQueueTemplate&);

    // Destructor
    ~StaticQueueTemplate();

    // StaticQueueTemplate operations
    void enqueue(T);
    void dequeue(T&);
    bool isEmpty() const;
    bool isFull() const;
    void display();
    void clear();
};

// Default constructor
template <class T>
StaticQueueTemplate<T>::StaticQueueTemplate(int s)
{
    queueArray = new T[s];
    queueSize = s;
    front = -1;
    rear = -1;
    numItems = 0;
}

// Copy constructor                                             
template <class T>
StaticQueueTemplate<T>::StaticQueueTemplate(const StaticQueueTemplate& obj)
{
    // Allocate the queue array.
    queueArray = new T[obj.queueSize];

    // Copy the other object's attributes.
    queueSize = obj.queueSize;
    front = obj.front;
    rear = obj.rear;
    numItems = obj.numItems;

    // Copy the other object's queue array.
    for (int count = 0; count < obj.queueSize; count++)
        queueArray[count] = obj.queueArray[count];
}

// Destructor                                                   
template <class T>
StaticQueueTemplate<T>::~StaticQueueTemplate()
{
    delete[] queueArray;
}

// PreCondition: valid T 'item'
// PostCondition: insert the value at the rear of the queue
template <class T>
void StaticQueueTemplate<T>::enqueue(T item)
{
    if (isFull())
        cout << "The queue is full.\n";
    else
    {
        // Calculate the new rear position
        rear = (rear + 1) % queueSize;
        // Insert new item
        queueArray[rear] = item;
        // Update item count
        numItems++;
    }
}

// PreCondition: reference T 'item'
// PostCondition: remove the value at the front of the queue
template <class T>
void StaticQueueTemplate<T>::dequeue(T& item)
{
    if (isEmpty())
        cout << "The queue is empty.\n";
    else
    {
        // Move front
        front = (front + 1) % queueSize;
        // Retrieve the front item
        item = queueArray[front];
        // Update item count
        numItems--;
    }
}

// PreCondition: NA
// PostCondition: return true if the queue is empty, false if it's not
template <class T>
bool StaticQueueTemplate<T>::isEmpty() const
{
    bool status;

    if (numItems)
        status = false;
    else
        status = true;

    return status;
}

// PreCondition: NA
// PostCondition: returns true if the queue is full, otherwise false
template <class T>
bool StaticQueueTemplate<T>::isFull() const
{
    bool status;

    if (numItems < queueSize)
        status = false;
    else
        status = true;

    return status;
}

// PreCondition: NA
// PostCondition: clear all the elements in the queue by setting front indices, end indices, and 'numItems' to 0
template <class T>
void StaticQueueTemplate<T>::clear()
{
    front = queueSize - 1;
    rear = queueSize - 1;
    numItems = 0;
}

// PreCondition: NA
// PostCondition: display the elements in the queue
template <class T>
void StaticQueueTemplate<T>::display()
{
    for (int i = 0; i < numItems; i++)
    {
        cout << queueArray[i] << "\n";
    }
}

#endif