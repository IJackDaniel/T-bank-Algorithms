#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr;
    for (int a = 0; a < n; a++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    vector<int> requests;
    for (int b = 0; b < k; b++)
    {
        int req;
        cin >> req;
        requests.push_back(req);
    }

    for (const int find: requests) 
    {   
        int l = -1, r = n - 1;
        while (r - l > 1) 
        {
            int m = (l + r) / 2;
            (arr[m] >= find) ? r = m: l = m;
        }

        if (arr[r] == find || l == -1) cout << arr[r] << endl;
        else if (arr[r] - find < find - arr[l]) cout << arr[r] << endl;
        else cout << arr[l] << endl;
    }
}
