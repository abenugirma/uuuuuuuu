//implementaion of doublyLinkedList.
#include <iostream>
using namespace std;

//Node structure for doubl linked list
struct Node {
	int data;       // Data store the node
	Node *prev;    // Pointer to the previos node
	Node *next;   // Pointer to the next node
	// Constract initilize a new node with a value

	Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Class to represents the douybl linked list
class DoublyLinkedList {
	private:
		Node *head;     // Pointer to the first node in the list
		Node *tail;   // Pointer to the last node in the last

	public:
		// Constructor to initialize an empty list
		DoublyLinkedList() : head(nullptr), tail(nullptr) {}

		// Insert a new node at the begning

		void insertAtBeginning(int data) {
			Node *newNode = new Node(data);    // Creat a new node
			if (!head) {   // if the list is empty
				head = tail = newNode;      // both head and tail point to the new node
			} else {
				newNode->next = head;      // link the current tail to the new node
				head->prev = newNode;
				head = newNode;
			}
		}

		void insertAtEnd(int data) {
			Node *newNode = new Node(data);
			if (!tail) {
				head = tail = newNode;
			} else {
				tail->next = newNode;
				newNode->prev = tail;
				tail = newNode;
			}
		}

		void insertAtPosition(int data, int position) {
			if (position <= 0) {
				cout << "Invalid position!" << endl;
				return;
			}
			if (position == 1) {
				insertAtBeginning(data);
				return;
			}
			Node *newNode = new Node(data);
			Node *current = head;
			int index = 1;
			while (current && index < position - 1) {
				current = current->next;
				index++;
			}
			if (!current) {
				cout << "Position out of range!" << endl;
				return;
			}
			newNode->next = current->next;
			if (current->next) {
				current->next->prev = newNode;
			} else {
				tail = newNode;
			}
			current->next = newNode;
			newNode->prev = current;
		}

		void deleteFromBeginning() {
			if (!head) {
				cout << "List is empty!" << endl;
				return;
			}
			Node *temp = head;
			head = head->next;
			if (head) {
				head->prev = nullptr;
			} else {
				tail = nullptr;
			}
			delete temp;
		}

		void deleteFromEnd() {
			if (!tail) {
				cout << "List is empty!" << endl;
				return;
			}
			Node *temp = tail;
			tail = tail->prev;
			if (tail) {
				tail->next = nullptr;
			} else {
				head = nullptr;
			}
			delete temp;
		}

		void deleteFromPosition(int position) {
			if (position <= 0 || !head) {
				cout << "Invalid position or empty list!" << endl;
				return;
			}
			if (position == 1) {
				deleteFromBeginning();
				return;
			}
			Node *current = head;
			int index = 1;
			while (current && index < position) {
				current = current->next;
				index++;
			}
			if (!current) {
				cout << "Position out of range!" << endl;
				return;
			}
			if (current->next) {
				current->next->prev = current->prev;
			} else {
				tail = current->prev;
			}
			if (current->prev) {
				current->prev->next = current->next;
			}
			delete current;
		}

		void displayList() {
			Node *current = head;
			while (current) {
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}
};

int main() {
	DoublyLinkedList dll;
	int choice, data, position;

	do {
		cout << "\nMenu:\n"
		     << "1. Insert at Beginning\n"
		     << "2. Insert at End\n"
		     << "3. Insert at Position\n"
		     << "4. Delete from Beginning\n"
		     << "5. Delete from End\n"
		     << "6. Delete from Position\n"
		     << "7. Display List\n"
		     << "8. Exit\n"
		     << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter data: ";
				cin >> data;
				dll.insertAtBeginning(data);
				break;
			case 2:
				cout << "Enter data: ";
				cin >> data;
				dll.insertAtEnd(data);
				break;
			case 3:
				cout << "Enter data: ";
				cin >> data;
				cout << "Enter position: ";
				cin >> position;
				dll.insertAtPosition(data, position);
				break;
			case 4:
				dll.deleteFromBeginning();
				break;
			case 5:
				dll.deleteFromEnd();
				break;
			case 6:
				cout << "Enter position: ";
				cin >> position;
				dll.deleteFromPosition(position);
				break;
			case 7:
				dll.displayList();
				break;
			case 8:
				cout << "Exiting..." << endl;
				break;
			default:
				cout << "Invalid choice!" << endl;
		}
	} while (choice != 8);

	return 0;
}