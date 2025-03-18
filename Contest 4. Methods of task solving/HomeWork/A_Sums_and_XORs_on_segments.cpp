#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int m;
    cin >> m;

    vector<long long> ps(n);
    vector<int> p_xor(n);
    long long s = 0;
    int xor_value = 0;

    for (int i = 0; i < n; ++i) {
        s += a[i];
        ps[i] = s;
        xor_value ^= a[i];
        p_xor[i] = xor_value;
    }

    for (int i = 0; i < m; ++i) {
        int query, l, r;
        cin >> query >> l >> r;

        if (query == 1) {
            long long sum = ps[r - 1];
            if (l > 1) {
                sum -= ps[l - 2];
            }
            cout << sum << endl;
        } else {
            int xor_result = p_xor[r - 1];
            if (l > 1) {
                xor_result ^= p_xor[l - 2];
            }
            cout << xor_result << endl;
        }
    }

    return 0;
}