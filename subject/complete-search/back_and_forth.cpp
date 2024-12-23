#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int buckets[20];
int bucketsPlace [20];
int total, current;
set<int> ans;

void check(int day){
    if(day == 4){
        ans.insert(current);        
        return;
    }

    for (int i = 0; i < 20; i++)
    {
        if(day % 2 == 0 && bucketsPlace[i] == 1){
            int a = buckets[i];            
            current -= a;
            bucketsPlace[i] = 0;            
            check(day + 1);     
            bucketsPlace[i] = 1;       
            current += a;
        } else if(day % 2 == 1 && bucketsPlace[i] == 0){
            int a = buckets[i];
            current += a;    
            bucketsPlace[i] = 1;        
            check(day + 1);     
            bucketsPlace[i] = 0;       
            current -= a;
        }
    }

}

int main(){
    setIO("backforth");
    total = 0; current = 1000;    

    for (int i = 0; i < 20; i++)
    {
        bucketsPlace[i] = i < 10;
        cin >> buckets[i];
    }
    check(0);
    
    cout << ans.size() << endl;
}