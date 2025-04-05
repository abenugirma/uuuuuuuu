//implmention of singl linked list.
#include <iostream>
using namespace std;

class Node {
	public:
		int data;
		Node *next;
		Node(int val) : data(val), next(nullptr) {}
};

class SinglyLinkedList {
	private:
		Node *head;
	public:
		SinglyLinkedList() : head(nullptr) {}

		void insertAtBegin(int val) {
			Node *newNode = new Node(val);
			newNode->next = head;
			head = newNode;
		}

		void insertAtEnd(int val) {
			Node *newNode = new Node(val);
			if (!head) {
				head = newNode;
				return;
			}
			Node *temp = head;
			while (temp->next)
				temp = temp->next;
			temp->next = newNode;
		}

		void insertAtPosition(int pos, int val) {
			if (pos < 1) {
				cout << "Invalid position.\n";
				return;
			}
			if (pos == 1) {
				insertAtBegin(val);
				return;
			}
			Node *newNode = new Node(val);
			Node *temp = head;
			for (int i = 1; i < pos - 1 && temp; i++)
				temp = temp->next;
			if (!temp) {
				cout << "Position out of range.\n";
				return;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}

		void deleteFromBegin() {
			if (!head) {
				cout << "List is empty.\n";
				return;
			}
			Node *temp = head;
			head = head->next;
			delete temp;
		}

		void deleteFromEnd() {
			if (!head) {
				cout << "List is empty.\n";
				return;
			}
			if (!head->next) {
				delete head;
				head = nullptr;
				return;
			}
			Node *temp = head;
			while (temp->next->next)
				temp = temp->next;
			delete temp->next;
			temp->next = nullptr;
		}

		void deleteFromPosition(int pos) {
			if (pos < 1 || !head) {
				cout << "Invalid position or empty list.\n";
				return;
			}
			if (pos == 1) {
				deleteFromBegin();
				return;
			}
			Node *temp = head;
			Node *prev = nullptr;
			for (int i = 1; i < pos && temp; i++) {
				prev = temp;
				temp = temp->next;
			}
			if (!temp) {
				cout << "Position out of range.\n";
				return;
			}
			prev->next = temp->next;
			delete temp;
		}

		void display() {
			if (!head) {
				cout << "List is empty.\n";
				return;
			}
			Node *temp = head;
			while (temp) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
};

int main() {
	SinglyLinkedList sll;
	int choice, val, pos;
	do {
		cout << "\nSINGLY LINKED LIST MENU\n";
		cout << "1. Insert at beginning\n";
		cout << "2. Insert at end\n";
		cout << "3. Insert at position\n";
		cout << "4. Delete from beginning\n";
		cout << "5. Delete from end\n";
		cout << "6. Delete from position\n";
		cout << "7. Display list\n";
		cout << "8. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "Enter value: ";
				cin >> val;
				sll.insertAtBegin(val);
				break;
			case 2:
				cout << "Enter value: ";
				cin >> val;
				sll.insertAtEnd(val);
				break;
			case 3:
				cout << "Enter position: ";
				cin >> pos;
				cout << "Enter value: ";
				cin >> val;
				sll.insertAtPosition(pos, val);
				break;
			case 4:
				sll.deleteFromBegin();
				break;
			case 5:
				sll.deleteFromEnd();
				break;
			case 6:
				cout << "Enter position: ";
				cin >> pos;
				sll.deleteFromPosition(pos);
				break;
			case 7:
				sll.display();
				break;
			case 8:
				cout << "Exiting...\n";
				break;
			default:
				cout << "Invalid choice.\n";
		}
	} while (choice != 8);
	return 0;
}