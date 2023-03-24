#include<iostream>
using namespace std;

//Approach 1: Using loops
// int main(){
//     string str = "abbsba";
//     for(int i=0,j=str.length()-1; i<j; i++,j--){
//         if(str[i] != str[j]){
//             cout<<"Not a palindrom string"<<endl;
//             return 0;
//         }
//     }
//     cout<<"String is palindrome"<<endl;
//     return 0;
// }

//Approach 2: using recursion
 
bool checkPalindrome(string &str,int i,int j){ //Pass by reference
    //Base case
    if( i > j) return true;

    //Processing
    if(str[i] != str[j]) return false;

    //Recursive relation
    checkPalindrome(str,i+1,j-1);
}

int main(){
    string str = "abbba";
    if(checkPalindrome(str,0,str.length()-1)) cout<<"String is palindrome"<<endl;
    else cout<<"Not a palindrom string"<<endl;
    cout<<str<<endl;
}