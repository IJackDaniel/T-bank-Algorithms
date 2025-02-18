#include <iostream>

using namespace std;

int main() 
{
    int l = 1, r;
    cin >> r;
    r++;

    int m = 0;
    while (r - l > 1)
    {
        m = (r + l) / 2;
        cout << m << endl;
        // cout << l << " " << r << endl << endl;
        
        fflush(stdout);
        string result;
        cin >> result;

        if (result == ">=")
        {
            l = m;
        }
        else 
        {
            r = m;
        }
    }
    cout << "! " << l;
}
