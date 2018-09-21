#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int numofcase,numofnum,token;
	int counter = 0;
	string input;
	cin >> numofcase;
	while (counter < numofcase) {
		cin >> numofnum;
		cin.ignore(100,'\n');
		vector<int> arrayofnum(numofnum);
		int numbercount = 1;
		long long int mediantotal = 0;
		priority_queue<int, vector<int>, greater<int>> minheap;
        priority_queue<int> maxheap;
        vector<int> res;
        int median = 0;
		for (int i = 0; i < numofnum; i++) {
			cin >> arrayofnum[i];
			if (arrayofnum[i] <= median) {
                maxheap.push(arrayofnum[i]);
            } else {
                minheap.push(arrayofnum[i]);
            }
            if (minheap.size() > maxheap.size()+1) {
                maxheap.push(minheap.top());
                minheap.pop();
            }
            if (maxheap.size() > minheap.size()+1) {
                minheap.push(maxheap.top());
                maxheap.pop();
            }
            if (minheap.size() == maxheap.size()) {
                median = (maxheap.top() + minheap.top())/2;
            } else if(minheap.size() > maxheap.size()) {
                median = (double)minheap.top();
            } else if (minheap.size() < maxheap.size()) {
                median = (double)maxheap.top();
            }
            mediantotal += median;
			numbercount++;
		}
		cout << mediantotal << endl;
		counter++;
	}
}
