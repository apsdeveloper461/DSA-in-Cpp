#include<iostream>
#include<conio.h>
using namespace std;
void Insert(int, int*&,int&,bool);
void Remove(int*&, int&);
int getIdx(int);
int search(int*, int);
int index_at(int,int*);
bool back(int idx);
bool front(int size, int idx);
void display(int*,int);
void update(int*, int);

int main() {
	int size = 0;
	cout << "Enter the size of array : ";
	cin >> size;
	//declare memmory on heap and asign value according to user requirment
	int* array1 = new int[size];

	for (int i = 0; i < size; i++) {
		cout << "Enter the Value of Element at index " << i << " : ";
		cin >> array1[i];
	}
		char choice;
	do {
		cout << "\n\n1)Insert Value at the start..\n2)Insert Value at the end..\n3)Remove element at specific index..\n4)Update element in the array..\n5)Search value from the array..\n6)Check value at_index..\n7)Display array..\n0)exit..\n";
		do
		{
			cout << "\n\tEnter your choice from the list :";
			choice = _getche();
			if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6' || choice == '7' || choice == '0') break;

		} while (true);

		int x;
		cout << endl;
		switch (choice)
		{
		case '1':
			cout << "Enter the Value which you want to insert at start : ";
			cin >> x;
			Insert(x, array1, size, true);
			break;
		case '2':
			cout << "Enter the Value which you want to insert at end : ";
			cin >> x;
			Insert(x, array1, size, false);
			break;
		case '3':
			Remove(array1, size);
			break;
		case '4':
			update(array1, size);
			break;
		case '5':
			x=search(array1, size);
			if (x == -1) cout << "\n-- Not Found --\n";
			else cout << " \n -- Found at " << x << " index --\n";
			break;
		case '6':
			x=index_at(size, array1);
			cout << "\nValue at index is " << x << endl;
			break;
		case '7':
			display(array1,size);
			break;
		default:
			break;
		}
		if (choice == '0') break;
	} while (true);

	


}


//Function to add integer data in first of arr
void Insert(int a, int*& arr, int& size, bool atStart) {
	int* temp = new int[size];

	for (int i = 0; i < size; ++i) {
		temp[i] = arr[i];
	}
	size++;
	//creating new array with adding one index
	arr = new int[size];
	if (atStart) {
		arr[0] = a;
		for (int i = 1; i < size; ++i) {
			arr[i] = temp[i - 1];
		}
	}
	else {
		for (int i = 0; i < size - 1; ++i) {
			arr[i] = temp[i];
		}
		arr[size - 1] = a;
	}

}

void Remove(int*& arr, int& size)
{
	int idx = getIdx(size);
	int* temp = new int[size];

	for (int i = 0; i < size; ++i) {
		temp[i] = arr[i];
	}
	size--;
	//creating new array with less one index
	arr = new int[size];
		for (int i = 0; i < size+1; ++i) {
			if (i < idx) {
			arr[i] = temp[i];
			continue;
			}
			if (i == idx) {
				continue;
			}
			arr[i - 1] = temp[i];
		}
}

//Display array 

int getIdx(int size)
{
	int idx = 0;
	do {
		cout << "Enter the index which you want to change(0 -- " << size-1 << ") :";
		cin >> idx;
		if (front(size,idx) || back(idx)) {
			cout << "--Invalid Index --\n";
		}
	} while (front(size, idx) || back(idx));
	return idx;
}

int search(int* arr, int size)
{
	int x;
cout << "Enter the Value which you want to search : ";
cin >> x;
	for (int i = 0; i < size; i++)
	{
		if (x == arr[i]) return i;
	}
	return -1;
}

int index_at(int size,int* arr)
{
	int idx = getIdx(size);

	return arr[idx];
}

bool back(int idx)
{
	return idx<0? true:false;
}

bool front(int size, int idx)
{
	return idx<size? false:true;
}

void display(int *arr,int s) {
	cout << "Display the array : \n";
	for (int i = 0; i < s; ++i) {
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void update(int* arr, int size)
{
	int idx = getIdx(size);
	cout << "Enter the value which you want to enter at selected index: ";
	int x;
	cin >> x;
	arr[idx] = x;
}
