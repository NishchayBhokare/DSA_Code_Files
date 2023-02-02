// Second Program
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number for a pattern" << endl;
    cin >> n;

    for (int i = 1; i < n; i++) // printing starting vertical line
    {

        for (int j = 0; j <= n; j++)
        {
            cout << " ";
        }
        cout << "*";
        cout << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        int space = n - i;
        while (space) // for adding space
        {
            cout << " ";
            space--;
        }

        cout << "*"; // printing cross star

        for (int j = (i - 1); j >= 0; j--) // adding space for vertical line
        {
            cout << " ";
        }

        cout << "*"; // printing for vertical line

        for (int j = (i - 1); j >= 0; j--) // printing space
        {
            cout << " ";
        }

        cout << "*"; // printing for cross line
        cout << endl;
    }
}