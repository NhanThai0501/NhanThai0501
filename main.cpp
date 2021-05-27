// Name: Nhan Thai
// Date: 5/21/2021
// Description: Assignment Chapter 19

#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <map>
#include <numeric>
#include "input.h"
#include "SearchAndSort (1).h"

// Class function
#include "StaticStackTemplate.h"
#include "DynamicStackTemplate.h"

#include "StaticQueueTemplate.h"
#include "DynamicQueueTemplate.h"

#include "IntStack.h"
#include "MathStack.h"
#include "MathStackTemplate.h" // using template <class T>

#include "Inventory.h"

// Function prototype
int menuOption(int option);
void Challenge1();
void Challenge2();
void Challenge3();
void Challenge4();
void Challenge7();
void Challenge8();
void Challenge9();

void menuStack(int& choice);
void getObjectData(Inventory& obj);
void displayObjectData(Inventory obj);
void Challenge12();

void menuQueue(int& choice);
void Challenge13();
void Challenge14();

// Main function
int main()
{
    do
    {
        system("cls");
        int option = 0;
        switch (menuOption(option))
        {
        case 0: exit(1); break;
        case 1: system("cls"); Challenge1(); break;
        case 2: system("cls"); Challenge2(); break;
        case 3: system("cls"); Challenge3(); break;
        case 4: system("cls"); Challenge4(); break;
        case 7: system("cls"); Challenge7(); break;
        case 8: system("cls"); Challenge8(); break;
        case 9: system("cls"); Challenge9(); break;
        case 12: system("cls"); Challenge12(); break;
        case 13: system("cls"); Challenge13(); break;
        case 14: system("cls"); Challenge14(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

    return 0;

}

//PreCondition: valid integer option
//POstCondition: return option
int menuOption(int option)
{
    cout << "\n\t\t Chapter 19 Assignment (page 1219 - 1222) by Nhan Thai";
    cout << "\n\t" + string(60, char(205));
    cout << "\n\t\t  1. Static Stack Template";
    cout << "\n\t\t  2. Dynamic Stack Template";
    cout << "\n\t\t  3. Static Queue Template";
    cout << "\n\t\t  4. Dynamic Queue Template";
    cout << "\n\t\t  7. Dynamic MathStack";
    cout << "\n\t\t  8. Dynamic MathStack Template";
    cout << "\n\t\t  9. File Reverser";
    cout << "\n\t\t  12. Inventory Bin Stack";
    cout << "\n\t\t  13. Inventory Bin Queue";
    cout << "\n\t\t  14. Balanced Parentheses";
    cout << "\n\t" + string(60, char(196));
    cout << "\n\t\t  0. Quit";
    cout << "\n\t" + string(60, char(205));

    option = inputInteger("\n\t\tOption: ", 0, 14);

    return option;

}


void Challenge1()
{
    cout << "\n\t\t  1. Static Stack Template by Nhan Thai \n\n";
    int size = inputInteger("Enter the size of the stack: ", true);
    StaticStackTemplate<double> test1(size);

    for (int i = 0; i < size; i++)
        test1.push(rand() % 100 * 0.11);

    cout << "\nBefore:\n" << test1 << '\n';

    double element;
    cout << "How many element do you want to pop? (0.." << size << "): ";
    int count = inputInteger("", 0, size);
    for (int i = 0; i < count; i++)
        test1.pop(element);

    cout << "\nAfter:\n" << test1 << '\n';


    if (test1.isEmpty())
        cout << "My static stack is empty.\n";
    else
        cout << "My static stack is not empty.\n";

    if (test1.isFull())
        cout << "My static stack is full.\n";
    else
        cout << "My static stack is not full.\n";

}

void Challenge2()
{
    cout << "\n\t\t  2. Dynamic Stack Template by Nhan Thai \n\n";
    DynamicStackTemplate<string> test1;
    string str;

    int size = inputInteger("How many element do you want to push?: ", 0, true);
    for (int i = 0; i < size; i++)
    {
        str = inputString("Enter some string: ", true);
        test1.push(str);
    }
    
    cout << "\nDisplay the content in dynamic stack: \n";
    test1.display();

    cout << "\n\n";
    string popElements;
    cout << "How many element do you want to pop? (0.." << size << "): ";
    int count = inputInteger("", 0, size);
    for (int i = 0; i < count; i++)
        test1.pop(popElements);

    cout << "\nDisplay the content in dynamic stack after being pop out: \n";
    test1.display();

    if (test1.isEmpty())
        cout << "\nThere is no element left in the dynamic stack.\n\n";
    else
        cout << "\nDynamic stack still has some element(s) inside.\n\n";
          
}

void Challenge3()
{
    cout << "\n\t\t  3. Static Queue Template by Nhan Thai \n\n";
    int size = inputInteger("Enter the size of the stack: ", true);
    StaticQueueTemplate<double> test1(size);
    double num;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter some double value: ";
        num = inputDouble("", true);
        test1.enqueue(num);
    }

    cout << "\n";
    test1.display();


    double popElements;
    cout << "How many element do you want to pop? (0.." << size << "): ";
    int count = inputInteger("", 0, size);
    for (int i = 0; i < count; i++)
        test1.dequeue(popElements);

    cout << "\nDisplay content in static queue after being pop: \n";
    test1.display();
        
}

void Challenge4()
{
    cout << "\n\t\t  4. Dynamic Queue Template by Nhan Thai \n\n";
    DynamicQueueTemplate<string> test1;
    string str;

    int size = inputInteger("Enter the size of the dynamic queue: ", true);

    cout << "\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter some string value: ";
        str = inputString("", true);
        test1.enqueue(str);
    }

    cout << "\n";
    test1.display();

    string popElements;
    cout << "How many element do you want to pop? (0.." << size << "): ";
    int count = inputInteger("", 0, size);
    for (int i = 0; i < count; i++)
        test1.dequeue(popElements);

    cout << "\nDisplay content in dynamic queue after being pop: \n";
    test1.display();

}


void Challenge7()
{
    cout << "\n\t\t  7. Dynamic MathStack by Nhan Thai \n\n";
    int popValue;
    cout << "\nMathStack: Addition\n\n";
    MathStack test1(2);

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the value #" << i + 1 << ": ";
        int num = inputInteger("", true);
        test1.push(num);
    }

    test1.add();

    cout << "\nThe sum of two pop value is: ";
    test1.pop(popValue);
    cout << popValue << "\n";

    cout << "\nMathStack: Subtraction\n\n";
    MathStack test2(2);
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the value #" << i + 1 << ": ";
        int num = inputInteger("", true);
        test2.push(num);
    }

    test2.sub();

    cout << "\nThe difference of two pop value is: ";
    test2.pop(popValue);
    cout << popValue << "\n";

    cout << "\nMathStack: Multiplication\n\n";
    MathStack test3(2);

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the value #" << i + 1 << ": ";
        int num = inputInteger("", true);
        test3.push(num);
    }

    test3.multiply();
    cout << "\nThe multiplication of two pop value is: ";
    test3.pop(popValue);
    cout << popValue << "\n";

    cout << "\nMathStack: Division\n\n";
    MathStack test4(2);

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the value #" << i + 1 << ": ";
        int num = inputInteger("", true);
        test4.push(num);
    }

    test4.division();
    cout << "\nThe division of two pop value is: ";
    test4.pop(popValue);
    cout << popValue << "\n";

    cout << "\nMathStack: Addition of all value\n\n";
    int size = inputInteger("Enter the size of the dynamic MathStack: ", true);
    MathStack test5(size);

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value #" << i + 1 << ": ";
        int num = inputInteger("", true);
        test5.push(num);
    }

    test5.addAll();
    cout << "\nThe sum of all value is: ";
    test5.pop(popValue);
    cout << popValue << "\n";

    cout << "\nMathStack: Multiplication of all value\n\n";
    size = inputInteger("Enter the size of the dynamic MathStack: ", true);
    MathStack test6(size);

    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value #" << i + 1 << ": ";
        int num = inputInteger("", true);
        test6.push(num);
    }

    test6.multiplyAll();
    cout << "\nThe multiplication of all value is: ";
    test6.pop(popValue);
    cout << popValue << "\n";
    
}

void Challenge8()
{
    cout << "\n\t\t  8. Dynamic MathStack Template by Nhan Thai \n\n";
    double popValue;
    cout << "\nMathStack Template: Addition\n\n";
    MathStackTemplate<double> test1;

    
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the value #" << i + 1 << ": ";
        int num = inputDouble("", true);
        test1.push(num);
    }

    test1.add();

    cout << "\nThe sum of two pop value is: ";
    test1.pop(popValue);
    cout << popValue << "\n";

    cout << "\nMathStack Template: Subtraction\n\n";
    MathStackTemplate<double> test2;
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the value #" << i + 1 << ": ";
        double num = inputDouble("", true);
        test2.push(num);
    }

    test2.sub();

    cout << "\nThe difference of two pop value is: ";
    test2.pop(popValue);
    cout << popValue << "\n";

    cout << "\nMathStack Template: Multiplication\n\n";
    MathStackTemplate<double> test3;

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the value #" << i + 1 << ": ";
        double num = inputDouble("", true);
        test3.push(num);
    }

    test3.multiply();
    cout << "\nThe multiplication of two pop value is: ";
    test3.pop(popValue);
    cout << popValue << "\n";

    cout << "\nMathStack Template: Division\n\n";
    MathStackTemplate<double> test4;

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter the value #" << i + 1 << ": ";
        double num = inputDouble("", true);
        test4.push(num);
    }

    test4.division();
    cout << "\nThe division of two pop value is: ";
    test4.pop(popValue);
    cout << popValue << "\n";

    cout << "\nMathStack Template: Addition of all value\n\n";
    int count = inputInteger("How many value do you want to input?: ", true);
    MathStackTemplate<double> test5;

    for (int i = 0; i < count; i++)
    {
        cout << "Enter the value #" << i + 1 << ": ";
        double num = inputDouble("", true);
        test5.push(num);
    }

    test5.addAll();
    cout << "\nThe sum of all value is: ";
    test5.pop(popValue);
    cout << popValue << "\n";

    cout << "\nMathStack Template: Multiplication of all value\n\n";
    count = inputInteger("How many value do you want to input?: ", true);
    MathStackTemplate<double> test6;

    for (int i = 0; i < count; i++)
    {
        cout << "Enter the value #" << i + 1 << ": ";
        double num = inputDouble("", true);
        test6.push(num);
    }

    test6.multiplyAll();
    cout << "\nThe multiplication of all value is: ";
    test6.pop(popValue);
    cout << popValue << "\n";
}

void Challenge9()
{
    cout << "\n\t\t  9. File Reverser by Nhan Thai \n\n";

    DynamicStackTemplate<char> charStack;
    char ch;

    string str = inputString("Enter some sentence(s): ", true);

    // Write some contents in the file
    ofstream writeFile;
    writeFile.open("input.txt");

    writeFile << str;
     
    writeFile.close();
    
    // Open the file and read the file
    ifstream inputFile;
    inputFile.open("input.txt");

    cout << "\nReading file:\n";
    while (inputFile.get(ch)) 
    {
        // Push every letter in stack
        cout << ch;
        charStack.push(ch);
    }

    inputFile.close();

    // Write the reverse contents that have been read
    ofstream outputFile;
    outputFile.open("reverse.txt");

    cout << "\n\nWriting file:\n";
    while (!charStack.isEmpty()) 
    {
        // Pop out every letter from stack to make it reverse.
        charStack.pop(ch);
        cout << ch;
        outputFile << ch;
    }

    outputFile.close();

}

// PreCondition: valid reference integer 'choice'
// PostCondition: NA
void menuStack(int& choice)
{
    cout << "\n\t===== INVENTORY BIN STACK =====\n";
    cout << "\n\t" + string(35, char(205));
    cout << "\n\tEnter a choice from menu below:";
    cout << "\n\t1) Add part to inventory";
    cout << "\n\t2) Take part from inventory";
    cout << "\n\t" + string(35, char(205));
    cout << "\n\t0) Quit";
    cout << "\n\t" + string(35, char(196));
    choice = inputInteger("\n\tOption: ", 0, 2);
    
}

// PreCondition: a reference 'obj' of class Inventory
// PostCondition: NA
void getObjectData(Inventory& obj)
{
    int serial, lot;
    string date;
    cout << "\nSerial Number #: ";
    obj.setSerialNum(inputInteger("", true));

    while (!obj.dateValidation(date))
    {
        date = inputString("\nDate (MM/DD/YYYY): ", false);
    }

    obj.setManufactDate(date);
    cout << "\nLot Number: ";
    obj.setLotNum(inputInteger("", true));
}

// PreCondition: object 'obj' of class Inventory
// PostCondition: NA
void displayObjectData(Inventory obj)
{
    cout << "\nSerial Number: " << obj.getSerialNum();
    cout << "\nManufacture Date: " << obj.getManufactDate();
    cout << "\nLot Number: " << obj.getLotNum();
    cout << "\n";
}

void Challenge12()
{
    cout << "\n\t\t  12. Inventory Bin Stack by Nhan Thai \n\n";
    DynamicStackTemplate<Inventory> binStack;

    Inventory object;

    int choice;

    do
    {
        menuStack(choice);

        switch (choice)
        {
        case 1:
            getObjectData(object);
            binStack.push(object);
            cout << "\nA new part has been added.\n";
            break;
        case 2:
            if (binStack.isEmpty())
                cout << "\nInventory is empty!\n";
            else
            {
                binStack.pop(object);
                cout << "\nOne part has been removed.\n";
            }
            break;
        case 0:
            break;
        default:
            break;
        }
    } while (choice != 0);

    int count = 1;
    while (!binStack.isEmpty())
    {
        
        cout << "\nObject " << count << ": ";
        binStack.pop(object);
        displayObjectData(object);   
        count++;
    }
        
}

// PreCondition: valid reference integer 'choice'
// PostCondition: NA
void menuQueue(int& choice)
{
    cout << "\n\t===== INVENTORY BIN QUEUE =====\n";
    cout << "\n\t" + string(35, char(205));
    cout << "\n\tEnter a choice from menu below:";
    cout << "\n\t1) Add part to inventory";
    cout << "\n\t2) Take part from inventory";
    cout << "\n\t" + string(35, char(205));
    cout << "\n\t0) Quit";
    cout << "\n\t" + string(35, char(196));
    choice = inputInteger("\n\tOption: ", 0, 2);

}

void Challenge13()
{
    cout << "\n\t\t  13. Inventory Bin Queue by Nhan Thai \n\n";
    DynamicQueueTemplate<Inventory> binStack;

    Inventory object;
    int choice;

    do
    {
        menuQueue(choice);

        switch (choice)
        {
        case 1:
            getObjectData(object);
            binStack.enqueue(object);
            cout << "\nA new part has been added.\n";
            break;
        case 2:
            if (binStack.isEmpty())
                cout << "\nInventory is empty!\n";
            else
            {
                binStack.dequeue(object);
                cout << "\nOne part has been removed.\n";
            }
            break;
        case 0:
            break;
        default:
            break;
        }
    } while (choice != 0);

    int count = 1;
    while (!binStack.isEmpty())
    {
        
        cout << "\nObject " << count << ": ";
        binStack.dequeue(object);
        displayObjectData(object);
        count++;
    }
}

void Challenge14()
{
    cout << "\n\t\t  14. Balanced Parentheses by Nhan Thai \n\n";

    DynamicStackTemplate<char> parentheses;
    char ch;
    bool isBalanced = true;

    string str = inputString ("Enter some sentence(s): ", true);
   
    //loop on all characters of input string
    for (int i = 0; i < str.length(); i++) 
    {         
        //check current char if it is opening parenthesis
        if (str[i] == '(') 
        {
            //if it is, push it onto stack
            parentheses.push(str[i]);
        }
        //check if current char is closing parenthesis
        else if (str[i] == ')') 
        {
            //first check if stack is empty
            //this means the expression is unbalanced
            if (parentheses.isEmpty()) 
            {
                cout << "Expression not balanced!\n";
                isBalanced = false;
                //break from loop
                break;
            }
            //if stack is not empty, it will have both left and right parentheses, so pop it out
            else 
            {
                parentheses.pop(ch);
            }
        } 
    } 

    // check conditions
    if (isBalanced && parentheses.isEmpty())
        cout << "Expression is balanced or the string does not have any parentheses.\n";
    else 
        cout << "Expression is not balanced.\n";

}

