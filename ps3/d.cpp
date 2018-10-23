#include <bits/stdc++.h>
using namespace std;

int pos = 1;

class woman {
	public:
		string womanName;
		int dilation;
		int position;

		woman() {
			womanName = " ";
			dilation = 0;
			position = 0;
		}
		woman(string name,int dil) {
			womanName = name;
			dilation = dil;
			position = ::pos;
		}
		void setname(string name) {
			womanName = name;
		}
		void setdilation(int dil) {
			dilation = dil;
		}

		friend bool comp(const woman &a, const woman &b) {
			if(a.dilation == b.dilation) {
				return(a.position > b.position);
			} else {
				return (a.dilation < b.dilation);
			}
		}

};

// bool comp(woman &a, woman &b) {
// 	if(a.dilation == b.dilation) {
// 		return(a.position > b.position);
// 	} else {
// 		return (a.dilation < b.dilation);
// 	}
// }

class PQ {
	private:
		woman *harr;
		int size;
	public:
		PQ(int cap) {
			size = 0;
			harr = new woman[cap];
		}

		void swap(woman *x, woman *y) {
			woman temp = *x;
			*x = *y;
			*y = temp;
		}

		int parent(int i) {
			return (i-1)/2;
		}

		int getsize() {
			return size;
		}

		woman top() {
			return harr[0];
		}

		void push(woman k) {
			int i = size;
			++size;
			harr[i] = k;
			while(i != 0 && comp(harr[parent(i)],harr[i])) { 
				swap(&harr[i], &harr[parent(i)]);
				i = parent(i);
			}
		}

		void pop() {
			if(size == 1) {
				--size;
			} else {
				harr[0] = harr[size-1];
				--size;
				Heapify(0);
			}
		}

		void Heapify(int i) {
			int l = 2*i+1;
			int r = l+1;
			int largest = i;
			if(l < size && comp(harr[i],harr[l])) {
				largest = l;
			}
			if(r < size && comp(harr[largest],harr[r])) {
				largest = r;
			}
			if (largest != i) {
				swap(&harr[i], &harr[largest]);
				Heapify(largest);
			}
		}

};

class HashTable {
	private:
		woman *hashtable;
		int tablesize;
	public:
		HashTable() {
			tablesize = 1300297;
			hashtable = new woman[tablesize];
		}

		int HashString(string name) {
  			int sum = 0;                
  			for (auto &c : name) 
    			sum = ((sum*26)%tablesize + (c-'A'+1))%tablesize; 
  			return sum;
		}

		woman insert(woman k) {
			int index = HashString(k.womanName);
			while(hashtable[index].dilation != 0) {
				index = (index + 1) % tablesize;
			}
			hashtable[index] = k;
			return k;
		}

		woman update(string name, int dilation) {
			int index = find(name);
			hashtable[index].dilation += dilation;
			return hashtable[index];
		}

		woman getwoman(string name) {
			woman topwoman = hashtable[find(name)];
			return topwoman;
		}

		int find(string name) {
			int index =  HashString(name);
			while(hashtable[index].womanName != name) {
				index = (index + 1) % tablesize;
			}
			return index;
		}
};

HashTable HT = HashTable();
PQ pq(1000000);

//Methods Required
void ArriveAtHospital(string womanName, int dilation) {
	::pq.push(::HT.insert(woman(womanName, dilation)));
}

void UpdateDilation(string womanName,int increaseDilation) {
	::pq.push(::HT.update(womanName,increaseDilation));
}

void GiveBirth(string womanName) {
	::pq.push(::HT.update(womanName,101));
}

string Query() {
	while(::pq.getsize() != 0) {
		if(::HT.getwoman(::pq.top().womanName).dilation > 100) {
			::pq.pop();
		} else {
			break;
		}
	}
	if(::pq.getsize() == 0) {
		return "The delivery suite is empty";
	} else {
		return ::pq.top().womanName;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int commands;
	cin >> commands;
	string name;
	int command,dilation;
	for(int i = 0; i < commands; i++) {
			cin >> command;
			// 	Depending on the commands being issued
			if(command == 0) {
				cin >> name >> dilation;
				ArriveAtHospital(name,dilation);
				::pos++;
			} else if(command == 1) {
				// Dilation here is increased dilation
				cin >> name >> dilation;
				UpdateDilation(name,dilation);
			} else if(command == 2) {
				cin >> name;
				GiveBirth(name);
			} else {
				cout << Query() << endl;
			}
	}
	cout << "By submitting this source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the code that I wrote and can prove it to Lab TA if asked." << endl;
}