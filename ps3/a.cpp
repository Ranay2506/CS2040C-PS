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

//Methods Required
void ArriveAtHospital(string womanName, int dilation) {
	woman temp = woman(womanName, dilation);
	::pq1.push(temp);
}

void UpdateDilation(string womanName,int increaseDilation) {
	stack<woman> tempstack;
	woman temp = woman();
	int newdilation;
	while(true) {
		if(womanName == ::pq1.top().womanName) {
			temp.setname(womanName);
			newdilation = ::pq1.top().dilation + increaseDilation;
			temp.setdilation(newdilation);
			temp.setpos(::pq1.top().position);
			::pq1.pop();
			::pq1.push(temp);
			while(true) {
				if(tempstack.size() == 0) {
					break;
				} else {
					temp.setname(tempstack.top().womanName);
					temp.setdilation(tempstack.top().dilation);
					temp.setpos(tempstack.top().position);
					tempstack.pop();
					::pq1.push(temp);
				}
			}
			break;
		} else {
			temp.setname(::pq1.top().womanName);
			temp.setdilation(::pq1.top().dilation);
			temp.setpos(::pq1.top().position);
			::pq1.pop();
			tempstack.push(temp);
		}
	}
}

void GiveBirth(string womanName) {
	stack<woman> tempstack;
	woman temp = woman();
	while(true) {
		if(womanName == ::pq1.top().womanName) {
			::pq1.pop();
			while(true) {
				if(tempstack.size() == 0) {
					break;
				} else {
					temp.setname(tempstack.top().womanName);
					temp.setdilation(tempstack.top().dilation);
					temp.setpos(tempstack.top().position);
					tempstack.pop();
					::pq1.push(temp);
				}
			}
			break;
		} else {
			temp.setname(::pq1.top().womanName);
			temp.setdilation(::pq1.top().dilation);
			temp.setpos(::pq1.top().position);
			::pq1.pop();
			tempstack.push(temp);
		}
	}
}

string Query() {
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