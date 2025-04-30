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

void build(vector<int> &tree, vector<int> &src, int v, int tl, int tr) {
    if (tl == tr) {
        tree[v] = (int)(src[tl] == 1);
    } else {
        int tm = (tl + tr) / 2;
        build(tree, src, v * 2, tl, tm);
        build(tree, src, v * 2 + 1, tm + 1, tr);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
}

int get_kth(vector<int> &tree, int v, int tl, int tr, int k) {
    if (tl == tr) return tl;

    int tm = (tl + tr) / 2;
    if (k <= tree[v * 2]) {
        return get_kth(tree, v * 2, tl, tm, k);
    } else {
        return get_kth(tree, v * 2 + 1, tm + 1, tr, k - tree[v * 2]);
    }
}

void update(vector<int> &tree, int v, int tl, int tr, int pos) {
    if (tl == tr) {
        tree[v] = (int)!(bool)tree[v];
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(tree, v * 2, tl, tm, pos);
        } else {
            update(tree, v * 2 + 1, tm + 1, tr, pos);
        }
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
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
    int i, k;
    for (int req = 0; req < m; ++req) {
        cin >> req_type;
        if (req_type == '1') {
            cin >> i;
            update(tree, 1, 0, n - 1, i);
        } else {
            cin >> k;
            cout << get_kth(tree, 1, 0, n - 1, k + 1) << endl;
        }
    }
}