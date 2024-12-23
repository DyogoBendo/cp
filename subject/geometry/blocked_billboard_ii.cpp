#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

struct rect{
    int x1, x2, y1, y2;
};

int main(){
    setIO("billboard");
    rect lawnmower, billboard;
    cin >> lawnmower.x1 >> lawnmower.y1 >> lawnmower.x2 >> lawnmower.y2;
    cin >> billboard.x1 >> billboard.y1 >> billboard.x2 >> billboard.y2;

    int ans = 0;
    if( ((lawnmower.x1 >= billboard.x1 && lawnmower.x1 <= lawnmower.x2) || 
        (lawnmower.x2 >= billboard.x1 && lawnmower.x2 <= lawnmower.x2)) &&
        ((lawnmower.y1 >= billboard.y1 && lawnmower.y1 <= lawnmower.y2) ||
        (lawnmower.y2 >= billboard.y1 && lawnmower.y2 <= lawnmower.y2))
    ) {
        if((lawnmower.y1 >= billboard.y1 && lawnmower.y2 <= billboard.y2) && (lawnmower.x1 >= billboard.x1 && lawnmower.x2 <= billboard.x2)) ans = 0;
        else if(lawnmower.y1 >= billboard.y1 && lawnmower.y2 <= billboard.y2){
            int height = lawnmower.y2 - lawnmower.y1;
            int widht = max(max(0, billboard.x1 - lawnmower.x1), max(0, lawnmower.x2 - billboard.x2));
            ans = height * widht;
        } else if (lawnmower.x1 >= billboard.x1 && lawnmower.x2 <= billboard.x2){
            int widht = lawnmower.x2 - lawnmower.x1;
            int height = max(max(0, billboard.y1 - lawnmower.y1), max(0, lawnmower.y2 - billboard.y2));
            ans = height * widht;
        } else{
            ans = (lawnmower.x2 - lawnmower.x1) * (lawnmower.y2 - lawnmower.y1);
        }
    } else{
        ans = (lawnmower.x2 - lawnmower.x1) * (lawnmower.y2 - lawnmower.y1);
    }
    cout << ans << endl;
}