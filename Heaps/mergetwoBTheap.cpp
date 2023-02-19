//Example for merge given two heap in one heap.
// link- 
    // https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

   //Approach 1- using priority queue. TC- nlogn SC-m+n
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        priority_queue <int> pq;
        vector <int> c;
        //pushing data of both the vectors into the queue so that it will remain as heap.
        for(int i=0; i<n;i++){ 
            pq.push(a[i]);
        }
        for(int j=0; j<m; j++){
            pq.push(b[j]);
        }
        
        while(!pq.empty()){ //popping out one by one data from queue and storing to in vector c.
            c.push_back(pq.top());
            pq.pop();
        }
        
        return c; //returning vector.
    }
    

    // Approach 2- by sorting arrays. TC- nlong SC-m+n.
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
      vector<int> c;
      //in this method we are pushing all the data of vector a and b  into the vector c and then sort in decreasing order.
      for(auto i:a) c.push_back(i);//pushing all the elements in vector c.
      for(auto j:b) c.push_back(j);//pushing all the elements in vector c.
      sort(c.begin(), c.end(),greater<int>()); //sorting in decreasing order.
      return c; //returning c vector which is in decreasing order cause any decreasing sorted array is one kind of heap.
    }
    

    // Approach 3-Most efficient algo. linear approach by comparing. TC- n+m  SC-m+n.
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
      vector<int> c;
      int i=0; int j=0;
      //In this method we are comparing ith index element of vector a with jth index element vector b. 
      while(i<n && j<m){ //looping till size-1 
          if(a[i]>b[j]){ //if ith element is larger than jth element then simply push ith element in vector c.
            c.push_back(a[i]);
            i++;
          } 
          else { //otherwise push jth element in vector c.
              c.push_back(b[j]);
              j++;
          }
      }
      while(i<n) { c.push_back(a[i]); i++;} //if by any chance vector b get finished then we will simply put remaining elements of vector a into vector c.
      while(j<m) { c.push_back(b[j]); j++;} //similaryly vice versa.
       
      return c; //returning vector c. 
    }
    

    // Approach 4- with using manual heapify funciton. TC- nlong SC-m+n.
      vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
          vector<int> c; 

      for(auto i:a) c.push_back(i);//pushing all the elements in vector c.
      for(auto j:b) c.push_back(j);//pushing all the elements in vector c.

         int len=c.size(); //calculating length of vector c.

        for(int k=(len/2-1); k>=0; k--){ //zero base indexing so n/2-1 to 0.
            heapify(c,k,len); //calling heapify.
        }
        return c;
    }
      void heapify(vector <int> &c,int k,int len){
        int largest=k;
        int left=2*k+1; //in 1 base indexing 2*k
        int right=2*k+2; //in 1 base indexing 2*k+1.
        
        if(left < len && c[largest] < c[left]){ //left < len cause zero base indexing .
            largest=left;
        }
        
        if(right < len && c[largest] < c[right]){
            largest=right;
        }
        
        if(largest!=k) {
            swap(c[largest], c[k]);
            heapify(c,largest,len); //passing index of largest as k. so that we can set particular element in correct pos.
        }
    }