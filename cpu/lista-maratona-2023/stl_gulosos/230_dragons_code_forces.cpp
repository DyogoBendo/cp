#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int s, n;
    cin >> s >> n;

    vector<pair<int,int>> pairArray(n);

    for (size_t i = 0; i < n; i++)
    {
        int dragon, power;
        cin >> dragon >> power;
        pairArray[i] = make_pair(dragon, power);
    }

    sort(pairArray.begin(), pairArray.end());


    bool isCapable = true;
    for (size_t i = 0; i < n; i++)
    {
        int dragon, power;
        tie(dragon, power) = pairArray[i];

        if(s > dragon){
            s += power;
        } else{
            isCapable = false;
        }
    }
    
    if(isCapable){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}