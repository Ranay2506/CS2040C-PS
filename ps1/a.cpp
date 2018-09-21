#include <iostream>
#include <sstream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int numofcase,numofnum, token;
	int counter = 0;
	int arrayofnum[500];
	string input;
	long long int mediantotal;
	cin >> numofcase;
	
	while (counter < numofcase) {
		cin >> numofnum;
		cin.ignore(100,'\n');
		getline(cin,input);
		istringstream ss(input);
		mediantotal = 0;
		int numbercount = 1;
		int increase = 1;
		while(ss >> token) {
			arrayofnum[numbercount-1] = token;
			sort(arrayofnum,arrayofnum+numbercount);
			if (numbercount == 1) {
				mediantotal = arrayofnum[0];
			//	cout << mediantotal << endl;
			}
			else if (numbercount % 2 == 0) {
				mediantotal += (arrayofnum[(numbercount-1)/2] + arrayofnum[((numbercount-1)/2)+1]) / 2;
				//cout << median << endl;
			} else {
				mediantotal += arrayofnum[numbercount-1-increase];
				increase++;
			}
			//cout << mediantotal << endl;
			numbercount++;
		}
		cout << mediantotal << endl;
		counter++;
		fill_n(arrayofnum,500,0);
	}
	
	return 0;
}
