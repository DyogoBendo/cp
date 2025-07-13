#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

// For the Order Statistic Tree
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, std::less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ost;

// Basic setup
using namespace std;
#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long

// A robust point/vector struct
struct pt {
    ll x, y;
    pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}

    // Lexicographical comparison for map keys and sorting
    bool operator<(const pt p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }

    pt operator-(const pt p) const { return pt(x - p.x, y - p.y); }
    ll operator^(const pt p) const { return x * p.y - y * p.x; } // Cross product
};

// Input stream operator for points
istream& operator>>(istream& in, pt& p) {
    return in >> p.x >> p.y;
}

// Squared distance between two points
ll dist2(pt p, pt q) {
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

// 2 * signed area of triangle p-q-r. Determines orientation.
ll cross_product(pt p, pt q, pt r) {
    return (q - p) ^ (r - p);
}

// Comparison function for radial sort.
// Sorts points counter-clockwise.
// Crucially, adds tie-breaking for collinear points.
bool compare_angle(pt p, pt q, const pt& reference) {
    // Translate points to be relative to the reference point
    p = p - reference;
    q = q - reference;
    
    // Determine quadrants
    int quad_p = (p.y < 0 || (p.y == 0 && p.x < 0)); // 0 for upper half-plane, 1 for lower
    int quad_q = (q.y < 0 || (q.y == 0 && q.x < 0));

    if (quad_p != quad_q) {
        return quad_p < quad_q;
    }

    // If in same half-plane, use cross product
    ll cp = p ^ q;
    if (cp != 0) {
        return cp > 0; // p is to the left of q (CCW)
    }

    // Tie-breaker: if collinear, closer point comes first
    return dist2(pt(0,0), p) < dist2(pt(0,0), q);
}

// Counts inversions in a vector in O(N log N)
ll count_inversions(const vector<int>& v) {
    if (v.empty()) {
        return 0;
    }
    ost s;
    ll inversions = 0;
    for (int i = 0; i < v.size(); ++i) {
        inversions += s.size() - s.order_of_key(v[i]);
        s.insert(v[i]);
    }
    return inversions;
}

// Solves for a given set of points (all on one side of st-en)
ll solve_for_side(pt st, pt en, vector<pt>& pts) {
    if (pts.size() < 2) {
        return 0;
    }

    // 1. Sort by angle around 'st' to get the initial order
    sort(pts.begin(), pts.end(), [&](pt p1, pt p2) {
        return compare_angle(p1, p2, st);
    });

    // 2. Assign IDs based on the 'st' sort
    map<pt, int> id_map;
    for (int i = 0; i < pts.size(); ++i) {
        id_map[pts[i]] = i;
    }

    // 3. Sort by angle around 'en'
    sort(pts.begin(), pts.end(), [&](pt p1, pt p2) {
        return compare_angle(p1, p2, en);
    });

    // 4. Create permutation vector
    vector<int> permutation;
    for (const auto& p : pts) {
        permutation.push_back(id_map[p]);
    }

    // 5. Count inversions
    return count_inversions(permutation);
}

int main() {
    darvem;

    pt st, en;
    cin >> st >> en;

    int n;
    cin >> n;

    vector<pt> above, below;

    for (int i = 0; i < n; i++) {
        pt p;
        cin >> p;

        ll cp = cross_product(st, en, p);

        if (cp > 0) {
            above.push_back(p);
        } else if (cp < 0) {
            below.push_back(p);
        }
        // Points with cp == 0 are collinear and are ignored
    }

    ll ans = solve_for_side(st, en, above) + solve_for_side(st, en, below);

    cout << ans << endl;

    return 0;
}