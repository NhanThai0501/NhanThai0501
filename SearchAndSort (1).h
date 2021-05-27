#include <vector>
using namespace std;

//********************************************************************
// The selectionSort function sorts a string array in ascending order. *
//********************************************************************
void selectionSort(string array[], int size)
{
	int minIndex;
	string minValue;

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}

//*****************************************************************
// The linearSearch function performs a linear search on an       *
// integer array. The array arr, which has a maximum of size      *
// elements, is searched for the number stored in value. If the   *
// number is found, its array subscript is returned. Otherwise,   *
// -1 is returned indicating the value was not in the array.      *
//*****************************************************************
int linearSearch(const int arr[], int size, int value)
{
	int index = 0;       // Used as a subscript to search array
	int position = -1;   // To record position of search value
	bool found = false;  // Flag to indicate if the value was found

	while (index < size && !found)
	{
		if (arr[index] == value)  // If the value is found
		{
			found = true;         // Set the flag
			position = index;     // Record the value's subscript
		}
		index++;                  // Go to the next element
	}
	return position;              // Return the position, or -1
}

//***************************************************************
// The binarySearch function performs a binary search on an     *
// integer array. array, which has a maximum of size elements,  *
// is searched for the number stored in value. If the number is *
// found, its array subscript is returned. Otherwise, -1 is     *
// returned indicating the value was not in the array.          *
//***************************************************************

int binarySearch(const int array[], int size, int value)
{
	int first = 0,             // First array element
		last = size - 1,       // Last array element
		middle,                // Mid point of search
		position = -1;         // Position of search value
	bool found = false;        // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2;     // Calculate mid point
		if (array[middle] == value)      // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value)  // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;           // If value is in upper half
	}
	return position;
}

//***************************************************
// The swap function swaps int a and b in memory.       *
//***************************************************
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//*****************************************************
// The swap function swaps doubles a and b in memory. *
//*****************************************************
void swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//********************************************************************
// The selectionSort function sorts an int array in ascending order. *
//********************************************************************
void selectionSort(int array[], int size)
{
	int minIndex, minValue;

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}

void dynamicSelectionSort(int* array, int size)
{
	int minIndex, minValue;

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}

void selectionSort(double array[], int size)
{
	int minIndex, minValue;

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}

void dynamicSelectionSort(double* array, int size)
{
	int minIndex, minValue;

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}

void selectionSort(float array[], int size)
{
	int minIndex, minValue;

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}

void dynamicSelectionSort(float* array, int size)
{
	int minIndex, minValue;

	for (int start = 0; start < (size - 1); start++)
	{
		minIndex = start;
		minValue = array[start];
		for (int index = start + 1; index < size; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}

//***********************************************************************
// The selectionSort function sorts a string vector in ascending order. *
//***********************************************************************
void selectionSort(vector<string>& v)
{
	int minIndex;
	string minValue;

	for (int start = 0; start < (v.size() - 1); start++)
	{
		minIndex = start;
		minValue = v[start];
		for (int index = start + 1; index < v.size(); index++)
		{
			if (v[index] < minValue)
			{
				minValue = v[index];
				minIndex = index;
			}
		}
		swap(v[minIndex], v[start]);
	}
}

//***************************************************
// The swap function swaps a and b in memory.       *
//***************************************************
void swap(string& a, string& b)
{
	string temp = a;
	a = b;
	b = temp;
}

//***************************************************************
// The binarySearch function performs a binary search on a      *
// string vector. array, which has a maximum of size elements,  *
// is searched for the number stored in value. If the number is *
// found, its vector subscript is returned. Otherwise, -1 is    *
// returned indicating the value was not in the vector.         *
//***************************************************************

int binarySearch(const vector<string>& v, string str)
{
	int first = 0,             // First vector element
		last = v.size() - 1,   // Last vector element
		middle,                // Mid point of search
		position = -1;         // Position of search value
	bool found = false;        // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2; // Calculate mid point
		if (v[middle] == str)        // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (v[middle] > str)    // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;      // If value is in upper half
	}
	return position;
}


//***************************************************************
// Definition of function dualSort. Accepts id and sales arrays *
// as arguments. The size of these arrays is passed into size.  *
// This function performs a descending order selection sort on  *
// the sales array. The elements of the id array are exchanged  *
// identically as those of the sales array. size is the number  *
// of elements in each array.                                   *
//***************************************************************

void dualSort(int id[], double sales[], int size)
{
	int start, maxIndex, tempid;
	double maxValue;

	for (start = 0; start < (size - 1); start++)
	{
		maxIndex = start;
		maxValue = sales[start];
		tempid = id[start];
		for (int index = start + 1; index < size; index++)
		{
			if (sales[index] > maxValue)
			{
				maxValue = sales[index];
				tempid = id[index];
				maxIndex = index;
			}
		}
		swap(sales[maxIndex], sales[start]);
		swap(id[maxIndex], id[start]);
	}
}

//*****************************************************************
// The bubbleSort function sorts an int array in ascending order. *
//*****************************************************************
void bubbleSort(int array[], int size)
{
	int maxElement;
	int index;

	for (maxElement = size - 1; maxElement > 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (array[index] > array[index + 1])
			{
				swap(array[index], array[index + 1]);
			}
		}
	}
}
