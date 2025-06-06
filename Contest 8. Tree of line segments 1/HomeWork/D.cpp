#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits.h>
#include <cassert>
#include <cstring>
#include <float.h>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <math.h>
#include <random>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <map>
#include <set>

using namespace std;

void build(vector<int> &tree, vector<int> &a, int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(tree, a, v * 2, tl, tm);
        build(tree, a, v * 2 + 1, tm + 1, tr);
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
    }
}

int get_gex(vector<int> &tree, int v, int tl, int tr, int l, int r, int x) {
    if (l > r) return INT_MAX;

    if (tl == tr) return (tree[v] >= x ? tl : INT_MAX);

    int tm = (tl + tr) / 2;

    if (tl < l) {
        return min(
            get_gex(tree, v * 2, tl, tm, l, min(r, tm), x),
            get_gex(tree, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x)
        );
    }

    if (tree[v * 2] >= x) {
        return get_gex(tree, v * 2, tl, tm, l, min(r, tm), x);
    } else {
        return get_gex(tree, v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    }
}

void update(vector<int> &tree, int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(tree, v * 2, tl, tm, pos, new_val);
        } else {
            update(tree, v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> tree(n * 4);
    build(tree, a, 1, 0, n - 1);

    char req_type;
    int i, v, x, l;
    for (int req = 0; req < m; ++req) {
        cin >> req_type;
        if (req_type == '1') {
            cin >> i >> v;
            update(tree, 1, 0, n - 1, i, v);
        } else {
            cin >> x >> l;
            int res = get_gex(tree, 1, 0, n - 1, l, n - 1, x);
            cout << (res == INT_MAX ? -1 : res) << endl;
        }
    }
}