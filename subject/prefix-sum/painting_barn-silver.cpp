#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}


#define SIZE 1001

int main(){
	setIO("paintbarn");
	int n, k, x1, y1, x2, y2;
	cin >> n >> k;

	int barn[SIZE][SIZE] = {0};

	for (int i = 0; i < n; i++)
	{		
		cin >> x1 >> y1 >> x2 >> y2;

		barn[x1][y1] += 1;
		barn[x1][y2] -= 1;
		barn[x2][y1] -= 1;
		barn[x2][y2] += 1;
	}

	int ans = 0;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if(i > 0) barn[i][j] += barn[i - 1][j];
			if(j > 0) barn[i][j] += barn[i][j - 1];
			if(i > 0 && j > 0) barn[i][j] -= barn[i - 1][j- 1];

			ans += barn[i][j] == k;
		}
	}

	cout << ans << endl;
}