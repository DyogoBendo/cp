#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    int n;
    cin >> n;

    map<string, int> cycle;

    cycle.insert({"Ox", 0});
    cycle.insert({"Tiger", 1});
    cycle.insert({"Rabbit", 2});
    cycle.insert({"Dragon", 3});
    cycle.insert({"Snake", 4});
    cycle.insert({"Horse", 5});
    cycle.insert({"Goat", 6});
    cycle.insert({"Monkey", 7});
    cycle.insert({"Rooster", 8});
    cycle.insert({"Dog", 9});
    cycle.insert({"Pig", 10});
    cycle.insert({"Rat", 11});    

    map<string, int> ages;
    map<string, string> zodic;
    ages.insert({"Bessie", 0});    
    zodic.insert({"Bessie", "Ox"});    

    for (int i = 0; i < n; i++)
    {
        string c1, _, moment, z1, z2, c2;
        cin >> c1 >> _ >> _ >> moment >> z1 >> _ >> _ >> c2;

        int a1 = ages[c2];
        z2 = zodic[c2];

        int zv1 = cycle[z1];
        int zv2 = cycle[z2];
        int diff;

        zodic[c1] = z1;

        if(moment == "previous"){
            
            if(zv2 > zv1){
                diff = zv2 - zv1;
            } else{
                diff = 12 - (zv1 - zv2);
            }
            ages[c1] = a1 - diff;
        } else{
            if(zv1 > zv2){
                diff = zv1 - zv2;
            } else{
                diff = 12 - (zv2 - zv1);
            }
            ages[c1] = a1 + diff;
        }

    }
    
    cout << abs(ages["Elsie"]) << endl;
}