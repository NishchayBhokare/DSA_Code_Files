/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v){
    cout<<"size: "<<v.size()<<endl;
    for(int i = 0; i<v.size(); ++i){
        cout<<v[i]<<" ";
    }
}

void printVectorOfPair(vector<pair<int,int>>&vpr){
    cout<<"size: "<<vpr.size()<<endl;
    for(int i = 0; i<vpr.size(); ++i){
        cout<<vpr[i].first<<" "<<vpr[i].second<<endl;
    }
}

void printArrayOfVector(vector<int> &v){
    cout<<"size: "<<v.size()<<endl;
    for(int i = 0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
}

int main()
{
                                                //pair
   pair<int,int> pr;
    pr = make_pair(2,3);
    // pr ={2,3};
    // cout<<pr.first<<" "<<pr.second;
    
    // cin>>pr.first;
    // cout<<"You entered "<<pr.first;
    
    // int a[]= {1,2,3};
    // int b[] = {4,5,6};
    
    // pair<int,int> pr2[3];
    // pr2[0] = {1,4};
    // pr2[1] = {2,5};
    // pr2[2] = {3,6};
    
    // swap(pr2[0],pr2[2]);
    
    // for(int i = 0; i<3; i++){
    //     cout<<pr2[i].first<<" "<<pr2[i].second<<endl; 
    // }
    
    // pair<int,int> pr3= pr; //we can copy also 
    // pr3.first = 5;
    // cout<<pr3.first<<" "<<pr3.second<<endl; 
    // cout<<pr.first<<" "<<pr.second<<endl; 
    
                                                     
                                                    
                                                    
                                                //vector
    // int arr[5];
    // vector<int> v;
    // int n;
    // cin>>n;
    // for(int i = 0; i<n; ++i){
    //     int value; 
    //     cin>>value;
    //     v.push_back(value);
    // }
    
    // vector<int> v2(5);
    // vector<int> v2(5,2);
    
    // v2.pop_back();
    
    // printVector(v2);
    
                                                // vector of pair
    // vector<pair<int,int>> vpr={{1,4},{2,5},{3,6}};
    // vector<pair<int,int>> vpr;
    
    // printVectorOfPair(vpr);
    // int n; 
    // cin>>n;
    // for(int i = 0; i<n; i++){
    //     int x,y;
    //     cin>>x>>y;
    //     vpr.push_back({x,y});
    // }
    //  printVectorOfPair(vpr);
                                            
                                            //Array of vector
    //Array of vector behaves like 2d Array
    // the number of column is differ..but rows are of same count.
    //but in vector of vector rows and column are same for every i th vector.
    // int N;
    // cin>>N;
    // vector<int> vArr[N]; //creating N number of vectors.
    
    
    // for(int i = 0; i<N; i++){
    //     int n;
    //     cin>>n; 
    //     for(int j = 0; j<n; j++){
    //         int x;
    //         cin>>x;
    //         vArr[i].push_back(x);
    //     }
    // }
    
    // for(int i = 0; i<N; i++){
    //     printArrayOfVector(vArr[i]);
    //     cout<<endl;
    // }
    
    
                                            //vector of vector

    
    // vector<vector<int>>vVR = {{1,2,3},{2,4,5},{6,7,8}};
    // vector<vector<int>> vvr;
    
    // int N;
    // cin>>N;
    // //using temp vector;
    // for(int i=0; i<N; i++){
    //     int n; 
    //     cin>>n;
    //     vector<int>temp; //create temp vector
    //     for(int j = 0; j<n; j++){
    //         int x;
    //         cin>>x;
    //         temp.push_back(x); //insert element into the temp vector
    //     }
    //     vvr.push_back(temp); //insert temp vector into the vector of vector vvr.
    // } 
    
    //without using temp
        //using temp vector;
    // for(int i=0; i<N; i++){
    //     int n; 
    //     cin>>n;
    //     vvr.push_back(vector<int>()); //inserting empty vector in vector of vector vvr.
    //     for(int j = 0; j<n; j++){
    //         int x;
    //         cin>>x;
    //         vvr[i].push_back(x); //so just add elments in that empty vector.
    //     }
    // }
    
    
    // for(int i = 0; i<vvr.size(); i++){
    //     printArrayOfVector(vvr[i]);
    //     cout<<endl;
    // }
    
    
                                            //Iterators
    // vector<int> v ={1,2,3,4};
    // vector<int> :: iterator it = v.begin();
    
    // for(it; it != v.end(); it++){
    //     cout<<(*it);
    // }
    // while(it != v.end()){
    //     cout<<*it;
    //     it++;
    // }
    
    // vector<pair<int,int>> vPr = {{1,2},{3,4},{5,6}};
    
    
    
    //without using auto keyword
    // vector<pair<int,int>> :: iterator it = vPr.begin();
    // for(it; it != vPr.end(); it++){
    //     // cout<<(*it).first<<" "<<(*it).second<<endl;
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    
    // with using auto keyword -> in this case no need to initialise type of iterator just use auto.
    // it automatically assumes correct type of iterator.
    // auto it = vPr.begin();
    // for(it; it != vPr.end(); it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    
    
    
                                            //range based loop
    // cout<<"optimised way"<<endl;
    // for(auto itr:vPr){
    //     cout<<itr.first<<" "<<itr.second<<endl;
    // }
    
    // vector<int> vtr = {2,9,3,4,5};
    // cout<<endl;
    // for(auto &i:vtr){
    //     cout<<++i<<" ";
    // }
    // cout<<endl;
    //  for(auto i:vtr){
    //     cout<<i<<" ";
    // }
    
    
    
                                        //Maps -> key value pair
    
    //TC--> insertion and accessing of one elem-> log(n) , insertion and accessing of n element -> Nlog(n)
    //keys are stored in sorted order
    //stores unique key..if we try to duplicate. it override previous value for that key.
    
    // map<int,string> mp; //normal maps generated from red black trees, which are self balancing trees.
    // mp[4] = "Bhokare";
    // mp[1] = "Nishchay";
    // mp[2] = "Pradip";
    // mp.insert({3,"Siddhu"});
    // mp.insert(make_pair(5,"Rani"));
    
    
    // auto it = mp.find(13); //log(n) TC
    
    // if(it == mp.end()){
    //     cout<<"No pair found"<<endl;
    // }
    // else {
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    
    // mp.erase(1); //we can pass directly key.
    // mp.erase(it); //we can pass iterator also.
    
    // for(auto i:mp){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    
    
    //solving one problem. 
//     5
// Nishu  
// Nishu
// Rutu
// Kruti
// Kruti

// sort above string in lexicographical order.
    // map<string,int> mp;
    
    // int N;
    // cin>>N;
    // for(int i = 0; i<N; i++){
    //     string str; 
    //     cin>>str;
    //     mp[str]++;
        
    //     // if(mp.find(str) != mp.end()){
    //     //     mp[str]++;
    //     // }
    //     // else{
    //     //     mp[str]=1;
    //     // }
    // }
    
    // for(auto i:mp){
    //     cout<<"String is "<<i.first<<" and its frequency is "<<i.second<<endl; 
    // }
    
    
    
                                                    //Unordered map
    //Implementation -> using hash mutable
    //Time complexity  for all task -> O(1).
    // Valid data type in key place are primitive data type and string.
    
    // unordered_map<string,int> ump;
    
    // int N;
    // cin>>N;
    // for(int i = 0; i<N; i++){
    //     string str;
    //     cin>>str;
    //     ump[str]++; //incrementing count.
    // }
    
    // for(auto i:ump)
    //     cout<<"String is "<<i.first<<" and its frequency is "<<i.second<<endl;
    
    
    
                                            
                                        //Set -> Collection of unique element
    //uses red black tree. all task has log(n) tc.
    // set<int> st;
    // st.insert(3); //log(n)
    // st.insert(7);
    // st.insert(5);
    // st.insert(1);
    // st.insert(3);
    
    // st.erase(7);
    // auto it = st.find(5);
    // if(it != st.end()){
    //     st.erase(it);
    //     // cout<<"Element is found "<<(*it)<<endl<<endl;
    // }
    
    // for(auto i:st) cout<<i<<endl;
    
    
    
                                        //Unordered Set.
    //implementation using Hash table 
    //All opration tc is O(1).
    // unordered_set<int>ust;
    // ust.insert(4);
    // ust.insert(9);
    // ust.insert(10);
    // ust.insert(6);
    // for(auto i:ust) cout<<i<<endl;
    
    //Question check if given string is present or not..if present print yes else no.
    // 5
    // abc
    // def
    // ghi
    // jkl
    // mno
    // 3
    // abc
    // xhx
    // ghi
    
    
    // unordered_set<string> ust;
    // int N; 
    // cin>>N;
    // for(int i = 0; i<N; i++){
    //     string str;
    //     cin>>str;
    //     ust.insert(str);
    // }
    
    // int q;
    // cin>>q;
    // while(q--){
    //     string str;
    //     cin>>str;
        
    //     if(ust.find(str) != ust.end()){
    //         cout<<"Yes Present "<<endl;
    //     }
    //     else cout<<"Not Present "<<endl;
    // }
    
                                        
                                        //Multiset
    
    //It is similar like set..only difference is duplicate elements are allowed.
    //remaining things are same like we will get elements in sorted order. tc etc.
    //Time complexity are same as normal set.
    //we can use this on behalf of prioriy queue.
    
    // multiset<int> mst;
    
    // mst.insert(4);
    // mst.insert(2);
    // mst.insert(7);
    // mst.insert(8);
    // mst.insert(2);
    // mst.insert(5);
    
    // // mst.erase(2); //REMEMBER -> It will delete all instances of integer 2 present in set.
    
    // auto it = mst.find(2); 
    // mst.erase(it); //REMEMBER -> it will delete first instance of integer 2 present in set.
    
    // for(auto i:mst){
    //     cout<<i<<" ";
    // }
    
    
    // solution for monk and magical candy bag Question
//     int test;
// 	cin>>test;
// 	while(test--){
// 		int N,K;
// 		cin>>N>>K;
// 		multiset<long long, greater<long long> > mst;
// 		long long maxCandies=0;

// 		for(int i = 0; i<N; i++){
// 			long long cokkies;
// 			cin>>cokkies;
// 			mst.insert(cokkies);
// 		}

// 		// for(auto i:mst) cout<<i<<" ";

// 		while(K--){
// 			auto it = mst.begin();
// 			long long candies = *it;
// 			maxCandies += candies;
// 			long long newCandies = candies/2;
// 			mst.erase(it);
// 			mst.insert(newCandies);
// 		}
		
// 		cout<<maxCandies<<endl;
// 	}	
		                            //Nested containers in map
    
    
    // map<pair<string,string>, vector<int> > mp;
    
    // int N; 
    // cin>>N;
    // for(int i = 0; i<N; i++){
    //     string str1,str2;
    //     cin>>str1>>str2;
    //     pair<string,string> pr;
    //     // pr.first = str1;
    //     // pr.second = str2;
    //     pr = make_pair(str1,str2);

    //     int n;
    //     cin>>n;
    //     vector<int> v;
    //     for(int i = 0; i<n; i++){
    //         int marks;
    //         cin>>marks;
    //         v.push_back(marks);
    //     }
    //     mp[pr]=v;
    // }
    
    // for(auto &i:mp){
    //     // pair<string,string> p = i.first;
    //     // vector<int> v = i.second;
        
    //     cout<<"Pair is {"<<i.first.first<<i.first.second<<"} and its values are ";
    //     for(auto &j:i.second){
    //         cout<<j<<" ";
    //     }cout<<endl;
    // }
    
    // 3
    // a b 5
    // 1 2 3 4 5
    // c d 2
    // 1 5
    // d f 7
    // 1 3 4 5 6 7 9
    
                     //The monk and class mark Question
    
    //Method 1 ->  by using map nested with vector. and by sorting vecotor.
    map<int,vector<string>, greater<int> > mp; //adding element in descending order.
    //by doing greater <int> , greatest element will be on top.
    int N;
    // cin>>N;
    
    // while(N--){
    //     string student;
    //     int marks;
    //     cin>>student>>marks;
    //     // st.insert({marks,student});
    //     mp[marks].push_back(student);
    // }
    
    // cout<<endl<<"Answer is "<<endl;
    // for(auto &i:mp){
    //     sort(i.second.begin(),i.second.end()); //by sorting vector
    //     for(auto &j:i.second){
    //         cout<<j<<" "<<i.first<<endl;
    //     }
    // }
    
    //Method 2:by using map nested by multiset. so multiset can automatically sorted lexicographically.
    
        //we can use multiset also instead of vector in map..then we dont need to add line to sort vector.
      //map<int,multiset<string>, greater<int> > mp;
        // int N;
        // cin>>N;
        
        // while(N--){
        //     string student;
        //     int marks;
        //     cin>>student>>marks;
        //     // st.insert({marks,student});
        //     // mp[marks].insert(student);
        // }
        
        // // cout<<endl<<"Answer is "<<endl;
        // for(auto &i:mp){
        //     // sort(i.second.begin(),i.second.end());
        //     for(auto &j:i.second){
        //         cout<<j<<" "<<i.first<<endl;
        //     }
        // }

    
    //Method 3: using vector nested by pair of int and string. and by writing cmp function.
    // bool cmp(pair<string,int>pr1, pair<string,int>pr2){
    //     if(pr1.second == pr2.second) return pr1.first < pr2.first; //if marks are same then sorted by name.
    //     return pr1.second > pr2.second; //else sort by marks.
    // }
    
    // int N;
    // cin>>N;
    // vector<pair<string,int>>vpr;

    // while(N--){
    //     string str;
    //     int marks;
    //     cin>>str>>marks;
    //     vpr.push_back({str,marks});
    // }

    // sort(vpr.begin(),vpr.end(), cmp);

    // for(auto i:vpr){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    
    
    
                                                 //Stack ->LIFO (Last in first out.)
    //can be use for reverse purpose also.
    // stack<int> st;
    // st.push(3);
    // st.push(5);
    // st.push(8);
    // st.push(2);
    
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    
    
        
    
    
                                        //Queue -> FIFO (Fist in first out.)
    // queue<int> q;
    // q.push(3);
    // q.push(6);
    // q.push(9);
    // q.push(6);
    
    // while(!q.empty()){
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    
    
    
    //Paranthesis Checking question
    
    // Method 1:
        // bool checkMatch(char ch1, char ch2){
        //     if(ch1 == '[' && ch2 == ']') return true;
        //     else if(ch1 == '(' && ch2 == ')') return true;
        //     else if(ch1 == '{' && ch2 == '}') return true;
            
        //     return false;
        // }
        // bool ispar(string x)
        // {

        
        // stack<char>st;
        // for(int i = 0; i<x.size(); i++){
        //     char ch = x[i];
        //     if(ch == '[' || ch == '(' || ch == '{'){
        //         st.push(ch);
        //     }
        //     else {
        //         if(st.empty()) return false;
                
        //         char top = st.top();
           
        //         if(checkMatch(top,ch)){
        //              st.pop();
        //         }
        //         else return false;
                
        //     }
        // }
        
        // if(st.empty()) return true;
        // return false;
        
        
        //Method 2: with using stack and unordered Map.
    //     unordered_map<char,int> ump ={ {'{',-1}, {'(',-2}, {'[', -3},
    //                               {'}',1},{')',2},{']',3} };
        
    //     stack<char>st;
        
    //     for(auto ch:x){
    //         if(ump[ch] < 0) st.push(ch);
    //         else{
    //             if(st.empty()) return false;
    //             char ch2 = st.top();
    //             if(ump[ch] + ump[ch2] == 0) st.pop();
    //             else return false;
    //         }
    //     }
        
    //     if(st.empty()) return true;
    //     return false;
        
    // }
    
    
    
    //Next greatest element question -> 
    //Method 1 -> tc - N2
    //N2 time complexity
    // vector<long long> ans(n,-1);
    // for(int i = 0; i<n; i++){
    //     int j = i+1;
    //     for(j; j<n; j++){
    //         if(arr[i] < arr[j]){
    //             ans[i]=arr[j];
    //             break;
    //         }
            
    //     }
    // }
    // return ans; 
    
    //Method 2 - Optimised solution using stack. O(N)
    //by traversing right to left.
    // stack<long long> st;
    // vector<long long> ans(n,-1);

    // for(int i = n-1; i>=0; i--){ //traversing from right to left
    //   if(!st.empty() && arr[i] < st.top())  //add element in answer array if current element in array is less than stack element,
    //   //that mens stack element is nearest rightest greater element.
    //       ans[i]=st.top(); //adding in asnwer array.
    //   else{ //if not.
    //       while(!st.empty() && arr[i] >= st.top()){ //then remove element in stack till current element is greater than stack top element.
    //           st.pop();
    //       }
           
    //       if(st.empty()) ans[i] = -1; //if stack is gets empty that means..we not found nearest rightmost greatest element.
    //       else if(arr[i] < st.top()) ans[i]=st.top(); //after popping if currentl element is lesser than stack element then add stack element in answer array
    //   }
    //     st.push(arr[i]); //push current element
    // }
    
    
    //Method 3 - another optimised solution. O(N)
    //by traversing left to right
    // stack<pair<int,long long> > st;
    // vector<long long> ans(n,-1);
    
    // for(int i = 0; i<n; i++){
    //     while(!st.empty() && arr[i] > st.top().second){
    //         ans[st.top().first] = arr[i];
    //         st.pop();
    //     }
    //     st.push({i,arr[i]});
    // }
    
    // return ans;
    
    //Method 4 - without using pair..only by using indexes.
    // stack<int> st;
    //     vector<long long> ans(n,-1);
        
    //     for(int i = 0; i<n; i++){
    //         while(!st.empty() && arr[i] > arr[st.top()] ){ 
    //             ans[st.top()] = arr[i];
    //             st.pop();
    //         }
    //         st.push(i);
    //     }
    // return ans;
    
    
    
    //How to write custom comparator function.
    //This function will be outside of main function.
    // bool cmp(pair<int,int>a, pair<int,int> b){ //function name can be anything.
    //     if(a.first == b.first){
    //         return a.second > b.second; //if we return false..then it will swap..else not.
    //     }
    //     return a.first < b.first;
    // }
        
    // int n = 6;
    // vector<pair<int,int>>a={ {4,3},{5,5},{5,3},{25,6},{7,9},{8,5} };
    // sort(a.begin(),a.end(), cmp);
    
    // for(auto i:a){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
    
    
                                        //Built in Algorithm
    
    //Lower bound and Upper bound.
     //List should be sored first.
    
    //lower_bound -> used to search element, if element is present, then it will return
        //address of element else returns next greater element address. If duplicate element is there..
        //it will return first instance of eleemnt eg 5 5 5 7 => ans will be first 5.
        
    // Upper_bound -> even if element is present, it will give iterator to next element addresss. if element is 
        //not found then also, it will give addresss of next greater element.  if duplicate elemetn is there.
        //then it will return next greater element. eg 5 5 5 7 => ans will be 7.
    
    //Use lower_bound(vector.begin(),vector.end(), 5) //like this way in vector.
    //but for set and map, use st.lower_bound(0) //like this way.
    //In map case, search will be applied by keys..not by value..and it will return pointer to pair..so we can access arrow symbol and first and second
    
    //by using this int *ptr = lower_bound(vector.begin(),vector.end(), 5) we will get pointer to 5 elemnt in array
    //and by usin int ind = lower_bound(vector.begin(),vector.end(), 5) - v.begin() we will get index of 5 element in array
    
    // vector<int> v = {3,4,5,6,8};
    // int arr[]={1,2,3,4,6};
    // auto it = upper_bound(v.begin(),v.end(),6);
    // auto it = upper_bound(arr,arr+5,5);
    // cout<<*it;
    
    // map<int,int> mp;
    // mp[0] = 3;
    // mp[1] = 5;
    // mp[2] = 5;
    // mp[3] = 5;
    // mp[4] = 7;
    // set<int> mp;
    // mp.insert(3);
    // mp.insert(5);
    // mp.insert(7);
    
    // auto it = mp.upper_bound(1); //in map case..it will check by keys value. so it will return next greater key value.
    // cout<< it->first;

    // vector<int> v = {3,5,6,7,5};
    // cout<<*min_element(v.begin()+1,v.end())<<endl; //min element will return iterator..so by derefrencing..we can do cout.
    
    // cout<<accumulate(v.begin(),v.end(),0)<<endl; //return total sum.
    
    // cout<<count(v.begin(),v.end(),5)<<endl; //will return count of element.
    
    // auto it = find(v.begin(),v.end(),6); //it will return pointing to element which need to find. if element is not found then it will return iterator pointing to end.
    // cout<<*it;
    
    
    //Lambda function -> this is syntax [](){  }();
     cout<<"outputing lambad function"<<[](int x){ return x+2;}(5)<<endl;
     
     
     vector<int> v = {3,-4,5,6};
     //all_of -> returns 1..if given condition is true for all the elements in list else returns 0.
     cout<<all_of(v.begin(),v.end(), [](int x){return x > 0;} )<<endl;
     
     //any of -> returns 1..if given condc  ition is true for any element in list else return 0.
     cout<<any_of(v.begin(),v.end(), [](int x){return x > 0;} )<<endl;
     
     //none of -> return 1, if given condition is false for all the element in list else return 0.
     cout<<none_of(v.begin(),v.end(),[](int x){return x < 0;} )<<endl;
    
    
    
    //Dabang Pattern
    int n = 5;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=(n-i+1); j++){
            cout<<j;
        }
        
        //first start pattern
        for(int j=1; j<i; j++){
            cout<<"**";
        }
        
        for(int j=(n-i+1); j>0; j--){
            cout<<j;
        }
        cout<<endl;
    }
    
    
    
    //left operator
    // int val = 3<<1; //-> which is nothing but multiplying 3 by 2.
    // val = 3<<2; //-> which is nothing but muliplying 3 by (2*2) so 3 * 4.
    
    //right shift operator
    // int val = 8>>1; //-> divide 8 by 2. so 4.
    // val = 8>>2; //-> divide 8 by two times two(2*2) so 2.
    
    int val = 8 << 1; // -> do multiply by 2 one time so 8*2 = 16.
    val = 8 << 2 // -> multiply by 2..two times. so, 8*(2*2) = 32.
    cout<<val;
    //in most of the cases..it works as above.and for greater number..due to shifting, +ve number will convert
    //into -ve number. because first bit is 1..which shows -ve number.
    //how to retrive this number..take 2's complement...
    //Do 1st compliment..by changing bits. from 0 to 1 or 1 to 0.
    //then add 0001 in bits.
    


                                 //add this in your new laptop,

    reverse string -> string 6).
    check power.-> test .cpp file
    bubble sort using recursion.
    selection sort.
    check for optimised merge sort. which uses pointers.

//Sorting 

selection sort-> on every iteration find minelement...swap minelement to its right position..i.e first left position...as we incrementing outer loop i. for next iteration...we will traverse for i+1.
 
bubble sort-> compare adjacent element...and check if ith element is greater than i+1, then swap it. so on every iteration largest element will get bubble out to the last position of array. and on every iteration we are size will get reduce by 1.
 
Insertion sort-> considereing first element is sorted...so pointing i to j+1. comparing ith element with previous element...if  i th element is lesser than previous element then  do assignment like arr[j]=arr[j+1] and then at right posotion insert ith element.
 
Merge Sort -> divide array into two half...then we will get this half as sorted..so  create two arrays..each for first half and second half..then copy original array element into the newly created array..and do operation like merging two sorted arrays into the original array.
 
Quick sort-> first do partition...in partition..we are placing start element(considering pivot elemtn) in his right position...for that..first check how many element's are lesser than it...once checked...swap first element on his right position...now second task is...on left part of this pivotelement...all elements should be smaller and on right part all elements are greater.
so to make this...point i to the start element and j to the end element...and check...for every elment. if it's lesser than or greater than pivot element and swap accroding to it. and return pivot indedx.
    
    
//not able to solve problem
not able to solve letter combination.
not able to sovle permuatation of string.
not able to solve reverse linkedlist in k groups.
circular list or not.
sort 0's 1's 2's in linkedlist.
add two numbers linked list.
clone linked list using random pointers.
merge sort in linked list.

note -> why mege sort in linked list and quick sort in arryas prefarable.
able to solve but face difficulties for reverse stack using recursion. 
largest area in histogram. ->24th october 
celebrity problem -> 25th october
Max Rectangle -> 25th october    
Nstack in an array -> 26th october
design stack that supports push, pop in O(1) -> 27th october.
quueue implementation -> 27th october
first-ve numerb in k. (queue) -> 27th october.
check optimised solution for first-ve numerb in k which is O(N) SC-O(1) from gfg    
Reverse First K elements of Queue -> 28th october.
first non repeating character in a stream -> 29th october.
    
//need to practice sliding window problems. 
    
    // end
    return 0;
}








class NStack
{
public:
    // Initialize your data structure.
    int *arr;
    vector<stack<int>>stackTracker;
    int size;
    NStack(int N, int S)
    {   
        size = S;
        arr = new int[S];
        stackTracker.resize(N);
        for(int i = 0; i<S; i++) arr[i] = -1;
    }

    int getAvailableIndex(int *arr, int size){
        int i = 0;
        while(i<size && arr[i] != -1) i++;
        if(i<size) return i;
        return -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {   int stNo = m-1;
        int index = getAvailableIndex(arr,size);
        if(index != -1){
            arr[index] = x;
            stackTracker[stNo].push(index);
            return true;
        }
        else return false;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        int stNo = m-1;
        if(stackTracker[stNo].size() > 0){
            int index = stackTracker[stNo].top();
            stackTracker[stNo].pop();
            int val = arr[index];
            arr[index] = -1;
            return val;
        }
        else return -1;
    }
};
   






