#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <random>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    
    unordered_set<int> letters;
    for (int num : a) letters.insert(num);
    for (int num : b) letters.insert(num);
    
    mt19937_64 rng(random_device{}());
    uniform_int_distribution<long long> dist(1, 1e13 + 1);
    unordered_map<int, long long> hash_letters;
    for (int num : letters) {
        hash_letters[num] = dist(rng);
    }
    
    vector<long long> pref_a(n, 0);
    long long s_a = 0;
    for (int i = 0; i < n; ++i) {
        s_a += hash_letters[a[i]];
        pref_a[i] = s_a;
    }
    
    vector<long long> pref_b(m, 0);
    long long s_b = 0;
    for (int i = 0; i < m; ++i) {
        s_b += hash_letters[b[i]];
        pref_b[i] = s_b;
    }
    
    int ans = 0;
    for (int l = min(n, m); l > 0; --l) {
        for (int i = 0; i <= n - l; ++i) {
            long long sub_a = (i > 0) ? (pref_a[i + l - 1] - pref_a[i - 1]) : pref_a[i + l - 1];
            
            for (int j = 0; j <= m - l; ++j) {
                long long sub_b = (j > 0) ? (pref_b[j + l - 1] - pref_b[j - 1]) : pref_b[j + l - 1];
                
                if (sub_a == sub_b) {
                    ans = l;
                    break;
                }
            }
            
            if (ans) break;
        }
        
        if (ans) break;
    }
    
    cout << ans << endl;
    
    return 0;
}