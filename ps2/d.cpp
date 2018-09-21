#include <bits/stdc++.h>
using namespace std;

struct node {
	char data;
	node* next;
	node* prev;
};

class DLL {
	private:
		node* head;
		node* tail;
		node* dummyHead;
		node* dummyTail;
		int size;
		
		node* createNode(char val) {
			node* newNode = new node;
			newNode->data=val;
			newNode->next=NULL;
			newNode->prev=NULL;
			return newNode;
		}
	public:
		DLL() {
			node* head = NULL;
			node* tail = NULL;
			dummyHead = createNode(' ');
			dummyTail = createNode(' ');
			dummyHead->next = dummyTail;
			dummyTail->prev = dummyHead;
			size = 0;
		}
		node* Insert(char val,node* current) {
			node* newNode = createNode(val);
			if(size == 0) {
				newNode->prev = dummyHead;
				newNode->next = dummyTail;
				dummyTail->prev = newNode;
				dummyHead->next = newNode;
				head = newNode;
				size++;
				return newNode;
				// dummyHead <-> newNode(current) <-> dummyTail
			} else {
				newNode -> prev = current;
				newNode -> next = current -> next;
				current -> next -> prev = newNode;
				current -> next = newNode;
				size++;
				return newNode;
				// dummyHead <-> newNode(current) <-> oldhead <-> something <->something  <-> dummyTail
			}
			
		}
		node* Delete(node* current) {
			if(current == dummyHead) {
				return current;
			} else {
				node* leftNode = current->prev;
				node* rightNode = current->next;
				leftNode->next = rightNode;
				rightNode->prev = leftNode;
				delete current;
				size--;
				return leftNode;
			}	// dummyHead <->  newNode(current) <-> dummyTail
		}
		node* Gethead() {
			return dummyHead;
		}
		node* Gettail() {
			return dummyTail->prev;
		}
		void Print() {
			if(size == 0) {
				cout << "";
			}
			node* temp = dummyHead;
			temp = temp->next;
			while(temp != dummyTail) {
				cout << temp->data;
				temp = temp -> next;
			}
			cout << endl;
		}
		void Clear() {
			if(size == 0) {
				return;
			}
			node* temp = head;
			temp = temp->next;
			node* temp2;
			while(temp != dummyTail) {
				temp2 = temp->next;
				delete temp;
				temp = temp2;
			}
			size = 0;
		}
};

int main() {
	int tc;
	cin >> tc;
	cin.ignore();
	int counter = 0;
	string userinput;
	while (counter < tc){
		getline(cin,userinput);
		DLL output;
		node* current = output.Gethead();
		for (int i = 0; i < userinput.length();i++) {
			if(userinput[i] == ']') { 
				current = output.Gettail();			
			} else if(userinput[i] == '[') { 
				current = output.Gethead();		
			} else if(userinput[i] == '<') { 
				current = output.Delete(current);		
			} else {
				current = output.Insert(userinput[i],current);
			}
		}
		output.Print();
		output.Clear();
		counter++;
	}
	cout << "By submitting this source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the code that I wrote and can prove it to Lab TA if asked." << endl;
}
