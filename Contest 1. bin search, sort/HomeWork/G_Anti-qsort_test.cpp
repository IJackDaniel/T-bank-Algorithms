#include <iostream>
#include <vector>

using namespace std;

void antiQsort(vector<int> & array) 
{
    for (int a = 0; a < array.size(); a++)
    {
        swap(array[a], array[a/2]);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }

    antiQsort(arr);

    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
}