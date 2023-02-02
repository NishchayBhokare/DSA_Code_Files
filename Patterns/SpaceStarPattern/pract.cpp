// First Program
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number " << endl;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int space = i - 1;
        while (space) // for adding space
        {
            cout << " ";
            space--;
        }

        cout << "*"; // printing cross star

        for (int j = (n - i); j >= 0; j--) // adding space for vertical line
        {
            cout << " ";
        }

        cout << "*"; // printing for vertical line

        for (int j = (n - i); j >= 0; j--) // printing space
        {
            cout << " ";
        }

        cout << "*"; // printing for cross line
        cout << endl;
    }

    for (int i = 1; i < n; i++) // printing additionally for tail star
    {

        for (int j = 0; j <= n; j++)
        {
            cout << " ";
        }
        cout << "*";
        cout << endl;
    }
}