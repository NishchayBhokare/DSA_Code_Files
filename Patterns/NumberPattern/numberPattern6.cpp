#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    int count = n * n; // count is n*n for eg if n is 3 then count will be 3*3 i.e  9. so we will print count from 9 to 1.
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << count << " ";
            count--;
        }
        cout << endl;
    }
}