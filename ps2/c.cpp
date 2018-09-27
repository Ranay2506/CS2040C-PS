#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	cin.ignore();
	int counter = 0;
	string userinput;
	while (counter < tc){
		getline(cin,userinput);
		list<char> splitinput;
		list<char>::iterator it;
		it = splitinput.begin();
		for (int i = 0; i < userinput.length();i++) {
			if(userinput[i] == ']') { // Points to the tail of the list
				it = splitinput.end();
			} else if (userinput[i] == '<') {
				// Check if the list is empty or it is starting from the beginning
				if (splitinput.empty() == true || it == splitinput.begin()) { 
					continue;
				} else {
					--it;
					it = splitinput.erase(it);
				}
			// Points to the head of the list
			} else if(userinput[i] == '[') { 
				it = splitinput.begin();
			} else {
				it = splitinput.insert(it,userinput[i]);
				++it;
			}
			//cout << *it << endl;
		}
		for (auto v : splitinput) {
			cout << v;
		}
		cout << endl;
		splitinput.clear();
		counter++;
	}
	return 0;
}
