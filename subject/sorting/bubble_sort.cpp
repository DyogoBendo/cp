#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    int changes = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                changes ++;
            } 
        }
        
    }
    
    printf("Array is sorted in %d swaps.\n", changes);
    cout << "First Element: " << a[0] << endl;
    cout << "Last  Element: " << a[n - 1];
    return 0;
}