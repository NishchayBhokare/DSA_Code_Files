#include<iostream>
#include<queue>
using namespace std;

int main(){
//     priority_queue<int, vector<int>> maxi; //max heap that is descending priority queue.
//     maxi.push(7);
//     maxi.push(4);
//     maxi.push(1);
//     maxi.push(8);

//     int p_size=maxi.size();
// // Traversing over the priority queue
//     for(int i=0;i<p_size;i++){
//     cout<<maxi.top()<<" ";
//     maxi.pop();
// }
    

    priority_queue<int , vector<int>, greater<int>> mini; //min heap that is ascending priority queue.
    mini.push(7);
    mini.push(4);
    mini.push(1);
    mini.push(8);
    cout<<mini.empty()<<endl;

    int p_size=mini.size();
// Traversing over the priority queue
    for(int i=0;i<p_size;i++){
    cout<<mini.top()<<" ";
    mini.pop();
}
}