#ifndef _STATIC_ARRAY_CLASS
#define _STATIC_ARRAY_CLASS
#include<iostream>

			//this program has diffrent functions:
			//insertElement() : insert an element into the array
			//deleteElement() : delete element from the array
			//sortArray()     : sorts the array 
			//searchElement() : search for a specific element in the array
			//displayArray()  : displays all the elements of the array
			//isFull()        : returns 1 if the array is full
			//isEmpty()       : returns 1 if the array is Empty

using std::cout;			
using std::cin;
using std::endl;

template<class T>
class Array {
private:
	T* array;
	int size;
	int index;
public:
	Array();				//DEFAULT CONSTRUCTOR
	Array(const int&);		// CONSTRUCTOR WITH ARGUMENTS
	Array(const Array&);    //COPY CONSTRUCTOR
	~Array();
	void insertElement(T);
	void deleteElement(T);
	void searchElement(T) const;
	void sortArray();
	void displayArray()const;
	bool isEmpty()const;
	bool isFull()const;
	int getIndex() { return index; }

};

//Default constructor::
template<class T>
Array<T> ::Array() {
	size = 5; //default size
	array = new T[size];
	index = -1;
}
//constructor with argument::
template<class T>
Array<T> ::Array(const int& x) {
	size = x;
	array = new T[size];
	index = -1;
}
//Copy constructor ::
template<class T>
Array<T> ::Array(const Array& originalArray) {
	size = originalArray.size;
	array = new T[size];
	for (int i = 0; i < size; i++) {
		array[i] = originalArray.array[i];
	}
	index = size - 1;
}
template<class T>
Array<T> :: ~Array() {
	delete[] array;
}
//isEmpty()
template<class T>
bool Array<T> ::isEmpty() const {
	if (index == -1) return true;
	return false;
}

//isFull()
template<class T>
bool Array<T> ::isFull() const {
	if (index == size - 1)
		return true;
	return false;
}
//insert Function ::
template<class T>
void Array<T> ::insertElement(T element) {
	if (isFull())
		cout << "the Array is overFlow." << endl;
	else {
		array[++index] = element;
	}
}
//Search Function :
template<class T>
void Array<T> ::searchElement(T element)const {
	// we are going to use linear search ::
	if (isEmpty()) {
		cout << "the Array is empty." << endl;
	}
	else {
		int position = -1;
		for (int i = 0; i < size; i++) {
			if (*(array + i) == element) {
				position = i;
				break;
			}
		}
		if (position == -1)
			cout << "the element does not exist" << endl;
		cout << "the element exist in the position : " << position << endl;
	}
}
//Deletion function :
template<class T>
void Array<T> ::deleteElement(T element) {
	// we are going to use linear search ::
	if (isEmpty()) {
		cout << "the Array is empty." << endl;
	}
	else {
		bool found = false;
		int count = 0, position = -1;
		while (!found && count < size) {
			if (*(array + count) == element) {
				cout << "the element is deleted"<< endl;
				position = count;
				found = true;
			}
			else count++;
		}
		if (position == -1)
			cout << "the element does not exist." << endl;
		else {
			for (int i = position; i < index; i++) {
				array[i] = array[i + 1];
			}
			index--;
		}
	}
}
//display Function :
template<class T>
void Array<T>::displayArray()const {
	if (isEmpty())
		cout << "the Array is Empty." << endl;
	else {
		cout << "The Array's Elements are : " << endl;
		for (int i = 0; i <= index; i++)
			cout << array[i] << " ";
	}
	cout << "\nThe Number of elements is : " << index + 1 << endl;
	cout << "\nThe rest is " << (size - 1) - index << " elements." << endl;

}
// sort Function :
template<class T>
void Array<T> ::sortArray() {
	//the time complexity is : O(n!) very bad.
	for (int i = 0; i <= index; i++) {
		int temp = 0;
		for (int j = i; j <= index; j++) {
			if (array[j] < array[i]) {
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

#endif

