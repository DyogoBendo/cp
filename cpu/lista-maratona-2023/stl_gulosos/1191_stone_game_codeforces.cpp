#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    multiset<int> piles;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        piles.insert(a);
    }
    
    int number_of_two = 0, current_previous = -1, previous = -1, repeated = -1;
    int currentPlayer = 0;
    int currentMin = 0;

    for (auto pile : piles)
    {
        int qttd = piles.count(pile);
        if(qttd == 2 && repeated != pile){

            if(number_of_two == 1){
                cout << "cslnb" << endl;    
                return 0;
            }
            number_of_two ++;
            repeated = pile;
            previous = current_previous;
        }
        if(qttd > 2){
            cout << "cslnb" << endl;
            return 0;
        }
        current_previous = pile;
    }    

    if(number_of_two == 1){
        if(previous == repeated - 1){
            cout << "cslnb" << endl;
            return 0;
        } else{
            auto it = piles.find(repeated);
            piles.erase(it);
            piles.insert(repeated - 1);
            currentPlayer ++;
        }
    }
    
    for (auto pile : piles)
    {
        int removed = pile - currentMin;
        currentMin ++;
        currentPlayer = (currentPlayer + removed) % 2;
    }

    if(currentPlayer == 1){
        cout << "sjfnb" << endl;
    } else{
        cout << "cslnb" << endl;
    }   
}