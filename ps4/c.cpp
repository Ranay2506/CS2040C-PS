// Copy paste this C++ Template and save it as "BabyNames.cpp"
#include <bits/stdc++.h>
using namespace std;

// write your matric number here:
// write your name here:
// write list of collaborators here:
// year 2018/19 Sem1 hash code: IEXVAR3BOJ4VIYLO (do NOT delete this line)

struct Pair {
	string name = "";
	int gender = 0;
};

class HashTable {
	private:
		Pair *hashtable;
		int tablesize;

	public:

		HashTable() {
			tablesize = 607151; // Need to Change
			hashtable = new Pair[tablesize];
		}

		int HashString(string name) {
  			int sum = 0;                
  			for (auto &c : name) {
    			sum = ((sum*26)%tablesize + (c-'A'+1))%tablesize; 
  			}
  			return sum;
		}

		void insert(string name, int gender) {
			int index = HashString(name);
			while(hashtable[index].gender != 0) {
				index = (index + 1) % tablesize;
			}
			hashtable[index].name = name;
			hashtable[index].gender = gender;
		}

		int findanderase(string name) {
			int index = HashString(name);
			while(hashtable[index].name != name) {
				index = (index + 1) % tablesize;
			}
			int temp = hashtable[index].gender;
			hashtable[index].gender = 0;
			return temp;
		}

}; 

struct Node {
	string name;
	Node *left;
	Node *right;
	int leftsize;
	int rightsize;
	int height;
};

class AVLTree {
	private:
		// Calculate the height at the node
		int height(Node *N) {
			if (N == NULL) {
				return 0;
			}
			return N->height;
		}

		int getsize(Node* node) {
			if(node == NULL) {
				return 0;
			} else {
				return 1 + node->leftsize + node->rightsize;
			}
		}

		Node* newNode(string name) {
			Node* node = new Node;
			node->name = name;
			node->left = NULL;
			node->right = NULL;
			node->leftsize = 0;
			node->rightsize = 0;
			node->height = 1;
			return node;
		}

		Node *rotateright(Node *y) {
			Node *x = y->left;
			y->left = x->right;
			x->right = y;
			y->height = max(height(y->left), height(y->right)) + 1;
			x->height = max(height(x->left), height(x->right)) + 1;
			y->leftsize = getsize(y->left);
			y->rightsize = getsize(y->right);
			x->leftsize = getsize(x->left);
			x->rightsize = getsize(x->right);
			return x;
		}

		Node *rotateleft(Node *x) {
			Node *y = x->right;
			x->right = y->left;
			y->left = x;
			y->height = max(height(y->left), height(y->right)) + 1;
			x->height = max(height(x->left), height(x->right)) + 1;
			y->leftsize = getsize(y->left);
			y->rightsize = getsize(y->right);
			x->leftsize = getsize(x->left);
			x->rightsize = getsize(x->right);
			return y;
		}

		int BalanceFactor(Node *N) {
			if(N == NULL) {
				return 0;
			}
			return height(N->left) - height(N->right);
		}

		Node* insertNode(Node* node, string name) {
			if(node == NULL) { // If head node
				node = newNode(name);
			} else if(name < node->name) {
				node->left = insertNode(node->left,name); // Go to the left sub tree
			} else {
				node->right = insertNode(node->right,name); // Go to the right sub tree
			}

			int balance = BalanceFactor(node);

			if(balance == 2) {
				int balance2 = BalanceFactor(node->left);
				if(balance2 == 1) {
					// Left Left Case
					node = rotateright(node);
				} else {
					// Left Right Case
					node->left = rotateleft(node->left);
					node = rotateright(node);
				}
			} else if(balance == -2) {
				int balance2 = BalanceFactor(node->right);
				if(balance2 == -1) {
					// Right Right Case
					node = rotateleft(node);
				} else {
					// Right Left Case
					node->right = rotateright(node->right);
					node = rotateleft(node);
				}
			}
			node->height = 1 + max(height(node->left),height(node->right));
			node->leftsize = getsize(node->left);
			node->rightsize = getsize(node->right); 

			// Else is Balanced
			return node;
		}

		Node* minvaluenode(Node* node) {
			Node* current = node;
			while(current->left != NULL) {
				current = current->left;
			}
			return current;
		}

		Node* deleteNode(Node* node, string name) {
			if(node == NULL) { //Empty
				return node;
			}
			if(treesize == 1) {
				return NULL;
			}
			if(name < node->name) {
				node->left = deleteNode(node->left,name);
			} else if(name > node->name) {
				node->right = deleteNode(node->right,name);
			} else {
				if((node->left == NULL) || (node->right == NULL)) {
					Node *temp = node->left ? node->left : node->right;

					if(temp == NULL) { // Leaf node (No children)
						temp = node;
						node = NULL;
					} else {
						*node = *temp;
						free(temp);
					}
				} else {
					Node *temp = minvaluenode(node->right);
					node->name = temp->name;
					node->right = deleteNode(node->right, node->name);
				}
			}

			if(node != NULL) {
				int balance = BalanceFactor(node);
				if(balance == 2) {
					int balance2 = BalanceFactor(node->left);
					if(balance2 == 1) {
						// Left Left Case
						node = rotateright(node);
					} else {
						// Left Right Case
						node->left = rotateleft(node->left);
						node = rotateright(node);
					}
				} else if(balance == -2) {
					int balance2 = BalanceFactor(node->right);
					if(balance2 == -1) {
						// Right Right Case
						node = rotateleft(node);
					} else {
						// Right Left Case
						node->right = rotateright(node->right);
						node = rotateleft(node);
					}
				}
				node->height = 1 + max(height(node->left), height(node->right));
				node->leftsize = getsize(node->left);
				node->rightsize = getsize(node->right);
			}
			// Else Balanced
			return node;
		}

	public:
		Node* root;
		int treesize;

		AVLTree() {
			root = NULL;
			treesize = 0;
		}

		void Insert(string name) {
			root = insertNode(root, name);
			treesize++;
			//cout << root->name << endl;
			//cout << "Debugging: ";
			//Inorder(root);
			//cout << endl;
		}

		void Delete(string name) {
			//cout << "Debugging: ";
			//Inorder(root);
			//cout << endl;
			root = deleteNode(root, name);
			treesize--;
			//if(root != NULL) {
			//	cout << root->name << endl;
			//	cout << "Debugging: ";
			//	Inorder(root);
			//	cout << endl;
			//}
		}

		int getrank(string name) {
			return rank(root,name);
		}

		int getsize() {
			return treesize;
		}

		void Print() {
			Inorder(root);
		}

		void Inorder(Node* node) {
			if(node != NULL) {
				Inorder(node->left);
				cout << node->name << ' ';
				Inorder(node->right);
			}
		}

		int rank(Node* node,string name) {
			if(node == NULL) {
				return 1;
			} else if(node->name == name) {
				return getsize(node->left) + 1;
			} else if (node->name > name) {
				return rank(node->left,name);
			} else {
				return getsize(node->left) + 1 + rank(node->right,name);
			}
		}
}; 

AVLTree malename[26];
AVLTree femalename[26];
HashTable linkmap;

int convertChar(char x) {
	return x - 'A';
}

void AddSuggestion(string babyName, int genderSuitability) {
	int index = convertChar(babyName[0]);
	if(genderSuitability == 1) {
		::malename[index].Insert(babyName);
	} else {
		::femalename[index].Insert(babyName);
	}
	::linkmap.insert(babyName,genderSuitability);
}

void RemoveSuggestion(string babyName) {
	int index = convertChar(babyName[0]);
	//::malename[index].Delete(babyName);
	//::femalename[index].Delete(babyName);
	int gender = ::linkmap.findanderase(babyName);
	if(gender == 1) {
		::malename[index].Delete(babyName);
	} else {
		::femalename[index].Delete(babyName);
	}
}

int Query(string START, string END, int gender) {
	int ans = 0;
	int first = convertChar(START[0]);
	int last = convertChar(END[0]);
	if(gender == 0) {
		if(first == last) {
			ans += ::malename[first].getrank(END) - ::malename[first].getrank(START);
			ans += ::femalename[first].getrank(END) - ::femalename[first].getrank(START);
		} else {
			ans += ::malename[first].getsize() - ::malename[first].getrank(START);
			ans += ::femalename[first].getsize() - ::femalename[first].getrank(START);
			for(int i = first+1;i < last;i++) {
				ans += ::malename[i].getsize();
				ans += ::femalename[i].getsize();
			}
			ans += ::malename[last].getrank(END);
			ans += ::femalename[last].getrank(END);
		}	
	} else if(gender == 1) {
		if(first == last) {
			ans += ::malename[first].getrank(END) - ::malename[first].getrank(START);
		} else {
			ans += ::malename[first].getsize() - ::malename[first].getrank(START);
			for(int i = first+1;i < last;i++) {
				ans += ::malename[i].getsize();
			}
			ans += ::malename[last].getrank(END);	
		}	
	} else {
		if(first == last) {
			ans += ::femalename[first].getrank(END) - ::femalename[first].getrank(START);
		} else {
			ans += ::femalename[first].getsize() - ::femalename[first].getrank(START);
			for(int i = first+1;i < last;i++) {
				ans += ::femalename[i].getsize();
			}
			ans += ::femalename[last].getrank(END);
		}
	}
	return ans;
}


int main(){
  while(true) {
    int cmd = 0, genderSuitability;
    char babyName[32], START[32], END[32];
    scanf("%d", &cmd);
    if (cmd == 0) break;
    else if(cmd == 1) {
      scanf("%s%d", babyName, &genderSuitability);
      AddSuggestion(string(babyName), genderSuitability);
    }
    else if(cmd == 2) {
      scanf("%s", babyName);
      RemoveSuggestion(string(babyName));
    }
    else if(cmd == 3) {
      scanf("%s%s%d", START, END, &genderSuitability);
      int ans = Query(string(START), string(END), genderSuitability);
      printf("%d\n", ans);
    }
  }
  //return 0;
}