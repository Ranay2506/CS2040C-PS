#include <bits/stdc++.h>
using namespace std;

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
			tablesize = 1300297; // Need to Change
			hashtable = new Pair[tablesize];
		}

		int HashString(string name) {
  			int sum = 0;                
  			for (auto &c : name) 
    			sum = ((sum*26)%tablesize + (c-'A'+1))%tablesize; 
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
			int temp = index;
			hashtable[index].gender = 0
			return temp;
		}

};