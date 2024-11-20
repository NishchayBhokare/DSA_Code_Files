#include <iostream>
using namespace std;

int raisedTo(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    else
    {
        return raisedTo(a, b - 1) * a;
    }
}

int main()
{
    cout<<raisedTo(3, 3);
}