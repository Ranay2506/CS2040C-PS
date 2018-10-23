#include <bits/stdc++.h>
using namespace std;

int pos = 1;
// Object
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
		void setpos(int pos) {
			position = pos;
		}
};

struct comp {
	bool operator()(const woman& a, const woman& b) {
		if(b.dilation==a.dilation) {
			return b.position < a.position;
		}
		return b.dilation>a.dilation;
	}
};

// Global Variable
priority_queue<woman,vector<woman>,comp> pq1;
unordered_map<string,woman> u;

//Methods Required
void ArriveAtHospital(string womanName, int dilation) {
	woman temp = woman(womanName, dilation);
	::u[womanName] = temp;
	::pq1.push(temp);
}

void UpdateDilation(string womanName,int increaseDilation) {
	::u[womanName].dilation += increaseDilation;
	::pq1.push(u[womanName]);
}

void GiveBirth(string womanName) {
	::u[womanName].dilation = 101;
}

string Query() {
	while(::pq1.size() != 0) {
		if(::u[::pq1.top().womanName].dilation > 100) {
			::pq1.pop();
		} else {
			break;
		}
	}
	if(::pq1.size() == 0) {
		return "The delivery suite is empty";
	} else {
		return ::pq1.top().womanName;
	}
}


// PS3 need to use PQ
// Main Program starts here
int main() {
	int commands;
	cin >> commands;
	string name;
	int command,dilation;
	woman test[commands]; 
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
}