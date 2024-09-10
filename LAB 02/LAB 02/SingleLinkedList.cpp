#include<iostream>
using namespace std;


class Node {
	int data;
	Node* next;

public:
	Node(int v):next(NULL),data(v){}
	Node():next(NULL){}
	//make friend class for accessing private member
	friend class SingleLinkedList;
};


class SingleLinkedList {
	Node* head;

public:
	SingleLinkedList() :head(NULL) {}
	void InsertAtBegin(int v) {
		//create a node object for storing in linked list
		Node* n = new Node(v);
		n->next = head;
		head = n;
	}
	void  InsertAtEnd(int v) {	
		//create a node object for storing in linked list
		Node* n = new Node(v);
		Node* temp = head;
		if (head == NULL) {
			head = n; return;
		}
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = n;
	}
	void InsertAfter(int idx, int v) {
			if (idx < 0) {
				cout << "\nOut of Bound Index\n";
				return;
			}
			if (idx == 0) {
				InsertAtBegin(v);
				return;
			}
			Node* temp = head;
			int count = 0;
			while (temp != NULL && count < idx - 1) {
				temp = temp->next;
				count++;
			}
			//cout << (temp == NULL && count == idx - 1) << " " << (temp == NULL) << (count == idx - 1) << " " << count;
			if (temp == NULL && count == idx) InsertAtEnd(v);
			else if (temp != NULL) {

				Node* n = new Node(v);
				n->next = temp->next;
				temp->next = n;
			}else cout << "\nOut of bound index \n";

		
	}

	void Update(int index, int value) {
		if (index < 0) {
			cout << "\n --Index Out of Bound--\n";
			return;
		}
		Node* temp = head;
		int count = 0;
		while (temp != NULL && count < index) {
			temp = temp->next;
			count++;
		}
		cout << "count " << count << "  index " << index << endl;
		if (count == index && temp!=NULL) {
			temp->data=value;
		}
		else {
			cout << "\n --Index Out of Bound--\n";
		}
	}
	int search(int v) {
		Node* temp = head;
		if (!head) return -1;
		int count = 0;
		while (temp != NULL) {
			if (temp->data == v) {
				return count;
			}
			temp = temp->next;
			count++;
		}

		return -1;
	}

	void Delete(int v) {
		int idx = search(v);
		if (idx == -1) {
			cout << "\nNot Found\n";
			return;
		}
		Node* temp = head;
		if (idx == 0) {
			head = temp->next;
			return;
		}
		for (int i = 0; i < idx-1; i++)
		{
			temp = temp->next;
		}
		Node* Next = temp->next;
			temp->next = Next->next;

	}
	void Display() {
		Node* temp = head;
		cout << "\nSingle Linked List display now:\n";
		while (temp != NULL) {
			cout << temp->data;
			temp = temp->next;
			if (temp != NULL) cout << "->";

		}
	}
};



int main() {

	SingleLinkedList l;
	l.InsertAtBegin(12);
	l.InsertAtBegin(13);
	l.InsertAtEnd(15);
	l.InsertAtEnd(16);
	l.Display();
	int v;
	cout << "\nEnter th value which you want to search :";
	cin >> v;
	/*cout << "Enter index: ";
	cin >> idx;*/

	//l.InsertAfter(idx, v);
	l.Delete(v);
	//l.Display();

	l.Display();

	return 0;
}