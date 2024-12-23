#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("promote");

    int bs, be, ss, se, gs, ge, ps, pe;
    cin >> bs >> be >> ss >> se >> gs >> ge >> ps >> pe;

    int sp = 0, gp = 0, pp = 0;

    pp = pe - ps;
    gp = (ge - gs) + pp;
    sp = (se - ss) + gp;
    cout << sp << endl << gp << endl << pp << endl;
}