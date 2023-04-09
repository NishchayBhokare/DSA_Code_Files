#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
int main()
{
// creation of hash map
    // Insertion way 1;
    unordered_map<string, int> m1 { {"nish", 3}, {"gajendra", 4}, {"viraj", 6} };

    // ordered_map<char,int>m1;  //same with ordered map.

    // Insertion way 2;
       m1["ajit"] = 9;

    // Insertion way 3;
    pair<string, int> p1 = make_pair("kiran", 10);
    // m1.insert(p1);  //or m1.insert(make_pair("kiran",10));

    // Insertion way 4;
    pair<string, int> p2("rohan", 7);
    // m1.insert(p2);


//Difference between at() and [].
    //m1.at() -> will give corresponding value of given key, if key is not present then it will give error.
    //m1[] -> will give corresponding value of given key, if key is not present then, it will create entry for given key and initialise value with 0 for given key.

    cout<<m1.at("nish")<<endl;
    cout<<m1["nish"]<<endl; //Accessing key which are present in map.

    // cout<<endl<<m1.at("vikas")<<endl; //Accessing key which are not present in map, So in this case of at(), it will give error and terminate program

    cout<<endl<<m1["vikas"]<<endl; //Accessing key which are not present in map, So in this case of [], it will create entry for corresponding key with value 0. i.e vikas -> 0. 


//size
    cout << "size is " << m1.size()<<endl;


//empty
    cout<<"empty "<<m1.empty()<<endl;


//to check key is present or not (searching).
    cout<<m1.count("nish")<<endl; //it will return 1 if key is present in map otherwise it will return 0;


//to delete key
    // m1.erase("nish");  

//Traversing 
    //1) Using Normal for loop.
    cout<<endl;
    for(auto i:m1){
        cout<<i.first<<" -> "<<i.second<<endl;
    } cout<<endl;


    //2) Using iterator.
    unordered_map<string, int> :: iterator itr = m1.begin();
    while(itr != m1.end() ){
        cout<<itr->first<<" -> "<<itr->second<<endl;
        itr++;
    }


//find function
    unordered_map<string,int> :: iterator it = m1.find("nish");
    //find-> it will return iterator pointing to the particular key. if key is not found then it will return iterator which points/refers to map.end().

    if(m1.find("nish") == m1.end()){ //if this condition gets true that means m1 return iterator which points to m1.end() that means key is not found or present.
        cout<<"String is not found "<<endl;
    }
    else cout<<"String is found "<<endl; //else key is found

    auto it1=m1.find("nish"); //it will return iterator which pointing to nish key.
    cout<<it1->first;
}
