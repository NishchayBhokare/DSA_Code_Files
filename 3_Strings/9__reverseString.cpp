// leetcode

//Using recursion
void reverseUsingRecursion(vector<char>& s, int start, int end){
    if(start >= end) return;

    //processing part.
    swap(s[start], s[end]);
    // swap(s[start], s[s.size()-start-1]); //we can swap like this also..using single
    //varaible.
    

    return reverseUsingRecursion(s,start+1,end-1);
}
void reverseString(vector<char>& s) {
    reverseUsingRecursion(s,0,s.size()-1);
}


//using loops.
 void reverseString(vector<char>& s) {
    int start = 0, end = s.size()-1;
    while(start < end){
        swap(s[start++],s[end--]);
    }
}