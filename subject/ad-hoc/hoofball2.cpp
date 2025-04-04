#include <fstream>
#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_X = 1000;

int N, cows[MAX_N], cowsPassingTo[MAX_N];

// Which cow does a given cow pass to?
int passToCow(int cow) {
	int leftCow = -1;
	int rightCow = -1;
	int leftRange = MAX_X;
	int rightRange = MAX_X;
	// For each cow, find closest cows to it on the left and right
	for (int i = 0; i < N; i++) {
		if (cows[i] < cows[cow] && cows[cow] - cows[i] < leftRange) {
			leftCow = i;
			leftRange = cows[cow] - cows[i];
		}
		if (cows[i] > cows[cow] && cows[i] - cows[cow] < rightRange) {
			rightCow = i;
			rightRange = cows[i] - cows[cow];
		}
	}

	// Return the position identifier of cow that the given cow passes to
	if (leftRange <= rightRange) { return leftCow; }
	return rightCow;
}

int main() {
	ifstream fin("hoofball.in");
	ofstream fout("hoofball.out");
	fin >> N;
	int ballsNeeded = 0;
	for (int i = 0; i < N; i++) { fin >> cows[i]; }
	for (int i = 0; i < N; i++) { cowsPassingTo[passToCow(i)]++; }
	for (int i = 0; i < N; i++) {
		// This is a source cow, so give it a ball
		if (cowsPassingTo[i] == 0) { cout << cows[i] << endl;  ballsNeeded++; }
		// This cow only passes to 1 other cow forever, so give it a ball
		if (i < passToCow(i) && passToCow(passToCow(i)) == i && cowsPassingTo[i] == 1 &&
		    cowsPassingTo[passToCow(i)] == 1) {
                cout << cows[i] << endl;
			ballsNeeded++;
		}
	}
	fout << ballsNeeded << "\n";
}