#include <bits/stdc++.h>

using namespace std;

int mdc(int a , int b){
    while(a % b){
        int r = a % b;
        a = b;
        b = r;
    }
    return b;
}


int main(){
    int n, k;

    cin >> n >> k;

    set<int>mdcSet;

    for (size_t i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        int m = mdc(a, k);

        mdcSet.insert(m);
    }
    
    vector<int> possibilities;
    possibilities.push_back(0);

    auto start = mdcSet.begin();
    while(start != mdcSet.end()){
        int num = *start;
        while(num % k) {
            cout << num << endl;
            possibilities.push_back(num % k);
            num += *start;            
        }
        start ++;
    }

    for (auto p : possibilities)
    {
        auto start = mdcSet.begin();
        while(start != mdcSet.end()){
            int num = p;
            while(num % k && num % *start) {
                possibilities.push_back(num % k);
                num += *start;            
            }
            start ++;
        }
    }
    
    
    cout << possibilities.size() << endl;
    for (auto p : possibilities)
    {
        cout << p << " ";
    }
    cout << endl;
}