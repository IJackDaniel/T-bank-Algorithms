#include <iostream>
#include <vector>

using namespace std;


int main ()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr;
    int x;
    for (int i = 0; i < n; i++) 
    {
        cin >> x;
        arr.push_back(x);
    }

    vector<int> arr_k;
    int y;
    for (int a = 0; a < k; a++) 
    {
        cin >> y;
        arr_k.push_back(y);
    }

    for (int j = 0; j < k; j++) 
    {
        int l = -1, r = n - 1;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            (arr[m] >= arr_k[j]) ? r = m: l = m;
        }
        if (arr[r] == arr_k[j])
        {
            cout << "YES" << " ";
        }
        else 
        {
            cout << "NO" << " ";
        }
    }

}