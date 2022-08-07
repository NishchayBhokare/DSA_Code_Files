// Example for Find minimum and maximum element in an array.
// link-
    // https://practice.geeksforgeeks.org/problems/find-minimum-and-maximum-element-in-an-array4428/1/#


pair<long long, long long> getMinMax(long long a[], int n)
{ //Time complexity is O(n);

    pair<long long int, long long int> MinMax; //Creating a pair
    int min = a[0]; // we are assuming first element is max;
    int max = a[0]; // we are assuming first element is min;

    for (int i = 1; i < n; i++) // Looping from 1 to n-1.
    {
        if (a[i] > max) // if a[i] > max element then, max = a[i] otherwise moven on.
        {
            max = a[i]; // Overwriting value of max element cause a[i] is greater.
        }

        if (a[i] < min) // if a[i] < min element then, min = a[i] otherwise moven on.
        {
            min = a[i]; // Overwriting value of min element cause a[i] is smaller.
        }
    }

    MinMax.first = min;  // adding  min as first element in pair.
    MinMax.second = max; // adding  max as second element in pair.

    return MinMax; // returning pair.
}


// solution with the help of max, min default algorithm.

pair<long long, long long> getMinMax(long long a[], int n)
{
    pair<long long int, long long int> MinMax;
    long long max_elm = a[0];
    long long min_elm = a[0];

    for (int i = 1; i < n; i++)
    {
        max_elm = max(a[i], max_elm); // we are using max algorithm to get max value.
        min_elm = min(a[i], min_elm); // we are using min algorithm to get min value.
    }

    MinMax.first = min_elm;
    MinMax.second = max_elm;

    return MinMax;
}