#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
int main()
{
    // creation of hash map
    // Insertion way 1;
    unordered_map<string, int> m1{{"nish", 3}, {"gajendra", 4}, {"viraj", 6}};

    // Insertion way 2;
    //    m1["ajit"]=9;

    // Insertion way 3;
    pair<string, int> p1 = make_pair("kiran", 10);
    // m1.insert(p1);  //or m1.insert(make_pair("kiran",10));

    // Insertion way 4;
    pair<string, int> p2("rohan", 7);
    // m1.insert(p2);

    // size
    cout << "size is " << m1.size()<<endl;

    //to check key is present or not (searching).
    cout<<m1.count("nish")<<endl; //it will return 1 if present otherwise 0;

    //to delete key
    // m1.erase("nish");

    //use of iterator
    unordered_map<string,int> :: iterator it=m1.find("nish");

    //find- it will return iterator pointing to the particular element.
    // auto it=m1.find("nish");
    // cout<<it->first;

    //empty
    // cout<<"empty "<<m1.empty()<<endl;
    

    // Traversing

        // for(auto i:m1){
        //  cout<<i.first<<" "<<i.second<<endl;
        // }

        for(it=m1.begin();it!=m1.end();it++){
            cout<<it->first<<" "<<it->second<<endl;
        }
}
