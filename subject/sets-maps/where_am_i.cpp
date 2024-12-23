#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("whereami");

	int n;
    cin >> n;

    string s;
    cin >> s;

    int k = 1;

    while(k < n){
        set<string> colors; 
        int possible = 1;
        for(int i = 0; i < n; i ++){
            string sub = s.substr(i, k);
            possible = min(possible, (int) colors.insert(sub).second);
        }
        if(possible) break;
        k ++;
    }

    cout << k << endl;
    
}