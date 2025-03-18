#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<vector<int>> array;

public:
    Stack() {};

    void push(int n)
    {
        if (array.size() == 0)
        {
            array.push_back({n, n});
        }
        else
        {
            int lst = array[array.size() - 1][1];
            if (lst < n)
            {
                array.push_back({n, lst});
            }
            else
            {
                array.push_back({n, n});
            }
        }
        
    }

    void del()
    {
        array.pop_back();
    }

    int min()
    {
        return array[array.size() - 1][1];
    }
};

int main()
{
    int n;
    cin >> n;

    Stack stack;

    int command, num, mn;
    for (int a = 0; a < n; a++)
    {
        cin >> command;
        switch (command)
        {
            case 1:
            {
                cin >> num;
                stack.push(num);
                break;
            }
            
            case 2:
            {
                stack.del();
                break;
            }
            
            case 3:
            {
                mn = stack.min();
                cout << mn << endl;
                break;
            }
            
            default:
            {
                break;    
            }
        }
    }
    return 0;
}