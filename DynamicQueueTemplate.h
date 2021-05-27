#ifndef DYNAMICQUEUETEMPLATE_H
#define DYNAMICQUEUETEMPLATE_H
#include <iostream>
using namespace std;

// DynamicQueueTemplate template
template <class T>
class DynamicQueueTemplate
{
private:
    // Structure for the queue nodes
    struct QueueNode
    {
        T value;			// Value in a node
        QueueNode* next;	// Pointer to the next node
    };

    QueueNode* front;  // The front of the queue
    QueueNode* rear;   // The rear of the queue
    int numItems;      // Number of items in the queue
public:
    // Constructor
    DynamicQueueTemplate();

    // Destructor
    ~DynamicQueueTemplate();

    // Queue operations
    void enqueue(T);
    void dequeue(T&);
    bool isEmpty() const;
    void display();
    void clear();
};

// Default constructor
template <class T>
DynamicQueueTemplate<T>::DynamicQueueTemplate()
{
    front = nullptr;
    rear = nullptr;
    numItems = 0;
}

// Destructor                                
template <class T>
DynamicQueueTemplate<T>::~DynamicQueueTemplate()
{
    clear();
}


// PreCondition: valid T 'item'
// PostCondition: insert the value at the rear of the queue
template <class T>
void DynamicQueueTemplate<T>::enqueue(T item)
{
    QueueNode* newNode = nullptr;

    // Create a new node and store num there.
    newNode = new QueueNode;
    newNode->value = item;
    newNode->next = nullptr;

    // Adjust front and rear as necessary.
    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    // Update numItems.
    numItems++;
}


// PreCondition: reference T 'item'
// PostCondition: remove the value at the front of the queue
template <class T>
void DynamicQueueTemplate<T>::dequeue(T& item)
{
    QueueNode* temp = nullptr;

    if (isEmpty())
    {
        cout << "The queue is empty.\n";
    }
    else
    {
        // Save the front node value in num.
        item = front->value;

        // Remove the front node and delete it.
        temp = front;
        front = front->next;
        delete temp;

        // Update numItems.
        numItems--;
    }
}

// PreCondition: NA
// PostCondition: return true if the queue is empty, false if it's not
template <class T>
bool DynamicQueueTemplate<T>::isEmpty() const
{
    bool status;

    if (numItems > 0)
        status = false;
    else
        status = true;
    return status;
}

// PreCondition: NA
// PostCondition: dequeue or clear all the elements in the queue
template <class T>
void DynamicQueueTemplate<T>::clear()
{
    T value;   // Dummy variable for dequeue

    while (!isEmpty())
        dequeue(value);
}

// PreCondition: NA
// PostCondition: display the elements in the queue
template <class T>
void DynamicQueueTemplate<T>::display()
{
    QueueNode* temp = front;
    while (temp != nullptr)
    {
        cout << temp->value << "\n";
        temp = temp->next;
    }
}
#endif