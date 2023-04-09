//Find maximum and minimum value.
//GFG
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int data;
};


//TC-O(N) SC-(h)
int maxValue=INT_MIN;
int minValue=INT_MAX;
    int findMax(Node *root)
    {
        //code here
        if(root!=NULL){
            maxValue=max(maxValue,root->data);
            findMax(root->left);
            findMax(root->right);
        }
        return maxValue;
    }
    int findMin(Node *root)
    {
        //code here
         if(root!=NULL){
            minValue=min(minValue,root->data);
            findMin(root->left);
            findMin(root->right);
        }
        return minValue;
    }