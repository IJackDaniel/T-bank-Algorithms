#include <iostream>
#include <vector>

using namespace std;

class Stack
{
private:
    vector<int> array;

    public:
    Stack() {}

    void push(int n)
    {
        array.push_back(n);
    }

    void del()
    {
        array.pop_back();
    }

    int min()
    {
        //
    }

    void show()
    {
        for (int i = array.size() - 1; i >= 0; i--)
        {
            cout << array[i] << endl;
        }
    }
};

int main()
{
    int n;
    cin >> n;

    Stack stack;

    int command, num;
    for (int a = 0; a < n; a++)
    {
        cin >> command >> num;
        switch (command)
        {
        case 1:
            stack.push(num);
            break;
        
            case 2:
            stack.del();
            break;
        
            case 3:
            // stack.min();
            stack.show();
            break;
        
        default:
            break;
        }
    }
    return 0;
}