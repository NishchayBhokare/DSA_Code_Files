// #include<iostream>
// using namespace std;
// int main(){
//     // this is one approach but time complexity is n2;
//     int arr[]={2,3,4,4,4,4,4,4,5,6,6,6,6,6};
//     int size=sizeof(arr)/sizeof(arr[0]);
//     int i=0;
//     while (i<size)
//     {
//         if(arr[i]!=arr[i+1]){
//             i++;
//         }
//         else{
//             for(int j=i;j<size;j++){
//                 arr[j]=arr[j+1];
//             }
//             --size;
//         }
//     }
//     for(int i=0;i<size;i++){
//         cout<<arr[i];
//     }
    
// }

#include<iostream>
using namespace std;
int main(){
    //This is optimized approach which having time complexity big oh of n;
    int arr[]={5,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    int i=0, j=1;
    while (j<size)
    {
        if(arr[i]!=arr[j])
        {
            arr[i+1]=arr[j];
            i++;
        }
        else{
            j++;
        }
    }
    for(int k=0;k<=i;k++){
        cout<<arr[k]<<",";
    }
    
}