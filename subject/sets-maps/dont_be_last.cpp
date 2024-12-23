#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int smaller(map<string, int> m, int v){
    int smaller = 100000;
    
    for(auto &cow: m){
        if(cow.second < smaller && cow.second != v){
            smaller = cow.second;
        }
    }
    
    if(smaller == 100000) return -1;
    return smaller;
}

int main(){
    setIO("notlast");

	int n;
    cin >> n;
    
    map<string, int> cows = {{"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, 
    {"Daisy", 0}, {"Gertie", 0}, {"Annabelle", 0}, {"Maggie", 0}, 
    {"Henrietta", 0}}; 
    
    for(int i = 0; i < n; i++){
        string s;
        int v;
        cin >> s >> v;
        cows[s] += v;
    }
    
    int sm = smaller(cows, -1);
    int second = smaller(cows, sm);
    
    int total = 0;
    string ans;
    
    for(auto cow: cows){
        if(cow.second == second){
            total ++;
            ans = cow.first;
        }
    }
    
    
    if(total != 1) cout << "Tie" << endl;
    else cout << ans << endl;
    
}