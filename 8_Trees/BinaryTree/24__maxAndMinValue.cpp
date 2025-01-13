//Find maximum and minimum value.
//Very easy question.
//GFG
https://www.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

//TC-O(N) SC-(h)
int maxValue=INT_MIN;
int minValue=INT_MAX;
int findMax(Node *root)
{   
    if(root==NULL) return 0;
   
    maxValue=max(maxValue,root->data);
    findMax(root->left);
    findMax(root->right);
    return maxValue;
}
int findMin(Node *root)
{
    if(root==NULL) return 0;

    minValue=min(minValue,root->data);
    findMin(root->left);
    findMin(root->right);
    return minValue;
}