#include <iostream>
#include <vector>
using namespace std;

int main()
{
   //  int arr[100];//if we not initilized then array contain any random elements.
   //  int arr[100]={}; //if we initialize to empty then it will contain 0, in all place.

   //  vector<int> arr(100); //if we not initialized vector, then also it will contain 0 in all place.
   vector<int> arr(100, 0); // after initialisation to 0, it will definitely contain 0 to all places
   for (int i = 0; i < 100; i++)
   {
      cout << arr[i] << " ";
   }
}