#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int x1, y1, x2, y2, x3, y3, x4, y4, x5,y5, x6, y6;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;


    int white_area = (x2 - x1) * (y2 -y1);

    int b1_intersec_white = max(((min(x2, x4) - max(x1, x3))) * (min(y2, y4) - (max(y1, y3))), 0LL); 
    int b2_intersec_white = max(((min(x2, x6) - max(x1, x5))) * (min(y2, y6) - (max(y1, y5))), 0LL);

    int xbi, xbf, ybi, ybf;
    xbi = max(x3, x5);
    xbf = min(x4, x6); 
    ybi = max(y3, y5);
    ybf = min(y4, x6); 

    int intersec_b1_b2 = max((xbf - xbi) * (ybf - ybi), 0LL);

    int result = b1_intersec_white + b2_intersec_white;

    cout << white_area << " - " << result << endl;

    cout << intersec_b1_b2 << endl;

    if(intersec_b1_b2 != 0){
        cout << max(0LL, (min(xbf, x2) - max(xbi, x1)) * (min(ybf, y2) - max(y1, ybi))) << endl;
        result -= max(0LL, (min(xbf, x2) - max(xbi, x1)) * (min(ybf, y2) - max(y1, ybi)));
    }

    cout << "result, white area: " << result << " - " << white_area << endl;
    if(result == white_area) cout << "NO" << endl;
    else cout << "YES" << endl;
}