// Third program
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number for a pattern" << endl;
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
        int space = n - i - 1;
        while (space)
        {
            cout << " ";
            space--;
        }
        cout << "*"; // printing first tail cross

        for (int j = i; j >= 0; j--) // printing space
        {
            cout << " ";
        }
        cout << "*"; // printing tail vertical

        for (int j = i; j >= 0; j--) // printing space
        {
            cout << " ";
        }

        cout << "*"; // printing tail cross
        cout << endl;
    }
}