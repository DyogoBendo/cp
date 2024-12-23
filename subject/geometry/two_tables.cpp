#include <bits/stdc++.h>

using namespace std;

void solve(){
    int w1, h1, x1, x2, y1, y2, w2, h2;
    cin >> w1 >> h1 >> x1 >> y1 >> x2 >> y2 >> w2 >> h2;

    int left = x1;
    int right= w1 - x2;
    int bottom = y1;
    int top = h1 - y2;

    int horizontal_space = max(left, right);
    int vertical_space = max(bottom, top);

    int horizontal_move = min(left, right);
    int vertical_move = min(bottom, top);

    int horizontal_movement = max(w2 - horizontal_space, 0);
    int vertifical_movement = max(h2 - vertical_space, 0);  

    int horizontal_possible = horizontal_movement <= horizontal_move;
    int vertical_possible = vertifical_movement <= vertical_move;

    if(!horizontal_possible && !vertical_possible){
        cout << -1 << endl;
    } else{
        if(!horizontal_possible){
            cout << vertifical_movement << endl;
        } else if(!vertical_possible){
            cout << horizontal_movement << endl;
        } else{
            cout << min(horizontal_movement, vertifical_movement) << endl;
        }
    }

}

int main(){
    int t;
    cin >> t;
    while(t --) solve();
}