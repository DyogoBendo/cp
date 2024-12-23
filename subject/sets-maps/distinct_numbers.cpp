#include <bits/stdc++.h>

using namespace std;

bool comp(int a, int b){
    return a > b;
}

int main(){
    int n;
    cin >> n;

    vector<int> numbers;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        numbers.push_back(x);
    }


    sort(numbers.begin(), numbers.end(), comp);
    int prev = numbers[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if(numbers[i] != prev) count ++;
        prev = numbers[i];
    }
    
    
    cout << count << endl;
}