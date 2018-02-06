
#include <cstdlib>
#include <vector>
#include <iostream>
#include <iterator>


using namespace std;


vector<int> mergesort(vector<int> &unsorted) {


	vector<int> firsthalf;
	vector<int> secondhalf;

	for(int iter = 0; iter < unsorted.size(); ++iter) {
		
		if(iter < unsorted.size()/2) {
				firsthalf.push_back(unsorted[iter]);
		}
		else {
		
				secondhalf.push_back(unsorted[iter]);
		}
	
	}
	if(firsthalf.size() > 1) {
		firsthalf = mergesort(firsthalf);
	}
	if(secondhalf.size() > 1) {
		secondhalf = mergesort(secondhalf);
	}
	vector<int> sorted;

	auto leftptr = firsthalf.begin();
	auto rightptr = secondhalf.begin();
	
	while(sorted.size() < (firsthalf.size() + secondhalf.size())) {
		
		if(*leftptr < *rightptr and (leftptr != firsthalf.end())) {
			sorted.push_back(*leftptr);
			if(leftptr+1 == firsthalf.end()) {
				while(rightptr != secondhalf.end()) {
					sorted.push_back(*rightptr);
					++rightptr;
				}
				
			}
			++leftptr;
		}

		else {
			sorted.push_back(*rightptr);
			if(rightptr+1 == secondhalf.end()) {
				while(leftptr != firsthalf.end()) {
					sorted.push_back(*leftptr);
					++leftptr;
				}
			}
			++rightptr;
		}
	}

	return sorted;
}

int main() {

	vector<int> numvec = {4,6,123,29,79,1020,2,1,10,89,67};
	for (int x : numvec) {
		cout << x << " ";
	}
	cout << endl;
	numvec = mergesort(numvec);		
	for (int x : numvec) {
		cout << x << " ";
	
	}

	return 0;

}
