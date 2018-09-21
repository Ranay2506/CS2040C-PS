#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc,counter;
	cin >> tc;
	cin.ignore();
	string userinput;
	while (counter < tc){
		cin >> userinput;
		cin.ignore();
		list<char> splitinput;
		list<char>::iterator it;
		it = splitinput.begin();
		for (int i = 0; i < userinput.length();i++) {
			if(userinput[i] == ']') {
				it = splitinput.end();
			} else if (userinput[i] == '<') {
				if (splitinput.empty() == true) {
					continue;
				} else {
					splitinput.pop_back();
				}
			} 
			else {
				splitinput.insert(it,userinput[i]);
			}
		}
		for(auto v : splitinput) {
			cout << v;
		}
		cout << endl;
		splitinput.clear();
		counter++;
	}
}
