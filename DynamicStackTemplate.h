#pragma once
template <class T>
class DynamicStackTemplate
{
private:
    // Structure for the stach nodes
    struct StackNode
    {
        T value;          // Value in the node
        StackNode* next;  // Pointer to next node
    };

    StackNode* top;     // Pointer to the stack top

public:
    // Default constructor
    DynamicStackTemplate()
    {
        top = nullptr;
    }

    // Destructor
    ~DynamicStackTemplate();

    // Stack operations
    void push(T);
    void pop(T&);
    void display();
    bool isEmpty();
};

// Destructor                                      
template <class T>
DynamicStackTemplate<T>::~DynamicStackTemplate()
{
    StackNode* nodePtr, * nextNode;

    // Position nodePtr at the top of the stack.
    nodePtr = top;

    // Traverse the list deleting each node.
    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

// PreCondition: valid T 'item'
// PostCondition: push value onto the stack
template <class T>
void DynamicStackTemplate<T>::push(T item)
{
    StackNode* newNode = nullptr; // Pointer to a new node

    // Allocate a new node and store num there.
    newNode = new StackNode;
    newNode->value = item;

    // If there are no nodes in the list
    // make newNode the first node.
    if (isEmpty())
    {
        top = newNode;
        newNode->next = nullptr;
    }
    else  // Otherwise, insert NewNode before top.
    {
        newNode->next = top;
        top = newNode;
    }
}

// PreCondition: reference valid T 'item'
// PostCondition: pop the value at the top of the stack off
template <class T>
void DynamicStackTemplate<T>::pop(T& item)
{
    StackNode* temp = nullptr; // Temporary pointer

    // First make sure the stack isn't empty.
    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }
    else  // pop value off top of stack
    {
        item = top->value;
        temp = top->next;
        delete top;
        top = temp;
    }
}

// PreCondition: NA 
// PostCondition: return true if the stack is empty and false if it's not
template <class T>
bool DynamicStackTemplate<T>::isEmpty()
{
    bool status;

    if (!top)
        status = true;
    else
        status = false;

    return status;
}

// PreCondition: NA
// PostCondition: display the elements in the stack
template <class T>
void DynamicStackTemplate<T>::display()
{
    StackNode* temp = top;
    while (temp != nullptr)
    {
        cout << temp->value << "\n";
        temp = temp->next;
    }
}


