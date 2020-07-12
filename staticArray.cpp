
#include<cstdlib> //exit()
#include"staticArrayClass.h"

int main() {
	Array<int> a(20);
	short choice;
	char again;
	do {
		cout << "\t\t Welcome :" << endl;
		cout << "\t1)insert an element." << endl;
		cout << "\t2)search for an element." << endl;
		cout << "\t3)delete an element." << endl;
		cout << "\t4)display all the elements." << endl;
		cout << "\t5)Quit" << endl;
		cout << "enter your choice : ";
		cin >> choice;
		switch (choice) {
		case 1: {
			int value;
			cout << "Enter a value : "; cin >> value;
			a.insertElement(value);
		} break;
		case 2: {
			int value;
			cout << "Enter a value : "; cin >> value;
			a.searchElement(value);
		} break;
		case 3: {
			int value;
			cout << "Enter a value : "; cin >> value;
			a.deleteElement(value);
		}
		case 4: {
			a.displayArray();
		} break;
		case 5: {
			cout << "Thank you...";
			exit(EXIT_SUCCESS);
		} break;
		default: cout << "The Number entered is not correct." << endl;
		
		}
		cout << "Do you have another task ? : "; 
		cin >> again;

	} while (again == 'y' || again == 'Y');
	cin.get();
}