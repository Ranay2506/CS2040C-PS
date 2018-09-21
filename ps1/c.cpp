#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long numofcase,numofnum,token;
	cin >> numofcase;
	cin >> numofnum;
	cin.ignore(100,'\n');
	long numbercount = 0;
	long long int mediantotal = 0;
    long counter1 = 0;
    long counter3 = 0;
    long counter5 = 0;
	while(cin >> token) {
		numbercount++;
		if (token == 1) {
			counter1 += 1;
		} else if(token == 3) {
			counter3 += 1;
		} else {
			counter5 += 1;
		}
		long arrayeo = numbercount % 2; // Check if it is even
		long median1 = numbercount/2; // Lower Bound
		long median2 = numbercount/2 + 1; // Upper Bound
		if(arrayeo != 0) {
			// 1 1 1 x x
			if(median2 <= counter1) {
				mediantotal += 1;
			// 1 1 3 x x
			} else if (median2 <= counter1+counter3) {
				mediantotal += 3;
			} else {
			// x x 5 5 5
				mediantotal += 5;
			}
		} else {
			//  1 1 1 1 x x
			if(counter1 > median1) {
				mediantotal += 1;
			} else if(counter5 > median1) {
				// x x 5 5 5 5
				mediantotal += 5;
			} else if(counter1 == median1 && counter5 == median1) {
				// 1 1 1 5 5 5
				mediantotal += 3;
			} else if (counter3 == median1 && counter5 == median1) {
				// 3 3 3 5 5 5;
				mediantotal += 4;
			} else if(counter1 == median1){
				// 1 1 1 3 x x
				mediantotal += 2;
			} else if(counter5 == median1) {
				// x x 3 5 5 5
				mediantotal += 4;
			// x x 3 3 x x
			} else {
				mediantotal += 3;
			}
		}
		if(numbercount == numofnum) {
			break;
		}
	}
	cout << mediantotal << endl;
	cout << "By submitting this source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the code that I wrote and can prove it to Lab TA if asked." << endl;
	return 0;
}
	
