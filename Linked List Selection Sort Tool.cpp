#include <iostream>
using namespace std;

class Node {
	public:
		int value;
		Node* next;
};

void printLinkedList(Node* n) {
	while(n != NULL) {
		cout << n->value << " ";
		n = n->next;
	}
	cout << endl;
}

void insertAtEnd(Node* head, int newValue) {
	Node* newNode = new Node();
	newNode->value = newValue;
	newNode->next = NULL;
	if(head == NULL) {
		head = newNode;
		return;
	}
	Node* currentLastNode = head;
	while(currentLastNode->next != NULL) {
		currentLastNode = currentLastNode->next;
	}
	currentLastNode->next = newNode;
}

void selectionSort(Node* head) {
	Node* temp = head;
	while(temp) {
		Node* smallestValue = temp;
		Node* unsortedElement = temp->next;
		while(unsortedElement) {
			if(unsortedElement->value < smallestValue->value) {
				smallestValue = unsortedElement;
			}
			unsortedElement = unsortedElement->next;
		}
		int tempValue = temp->value;
		temp->value = smallestValue->value;
		smallestValue->value = tempValue;
		temp = temp->next;
	}
}

int main() {
	int newValue;
	string temp;
	string option;
	Node* head = new Node();
	cout << "Write a list of integers separated by spaces below. Write a non-numeric character to end the list (e.g. 13 42 3 46 5 h): " << endl;
	cin >> newValue;
	head->value = newValue;
	while(cin >> newValue) {
		insertAtEnd(head, newValue);
	}
	cout << "Unsorted linked list: ";
	printLinkedList(head);
	selectionSort(head);
	cout << "Sorted linked list: ";
	printLinkedList(head);
}
