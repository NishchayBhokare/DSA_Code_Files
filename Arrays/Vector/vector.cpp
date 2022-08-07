#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 3};
    //    vector<int> v2(3,4); //it will initialize all elements as 4 in the vector.
    v1.push_back(5);
    v1.pop_back();
    // cout<<v1.at(1);
    //    cout<<v1.capacity();
    //    v1.shrink_to_fit();
    //    cout<<v1.capacity();

    //    cout<<v1.back();
    // cout<<v1.size();
    // v1.resize(1);
    // cout<<v1.size();
    // int *pos=v1.data(); //it will return address of first element of a vector.
    // cout<<*pos;
    // cout<<sizeof(v1)<<endl;
    // cout<<v1.empty();
    // v1.assign(2, 8); // it assigns new value by replacing old ones. simply it will add 8 for 2 times in vector.
    // v1.clear();
    // v1.insert(v1.begin(),9);
    // v1.erase(v1.begin());
    // v1.emplace(v1.begin(),9);
    v1.resize(2);
    
    //    for(auto i:v1){
    //     cout<<i;
    //    }

    //   for(auto i=v1.begin();i!=v1.end();i++){
    //     cout<<*i;
    //   }

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
}