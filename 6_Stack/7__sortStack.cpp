//Sort stack
//GFG

#include<stack>
using namespace std;

//Approach 1: TC-O(N2) SC-O()
//first divide stack to single element then call sorted insert function.

void SortedInsert(stack<int>&st,int x){
	if(st.empty()){ //if stack is empty simply insert that given element i.e x and return.
		st.push(x);
		return;
	}

	int val=st.top();  //take top element a side
	if(x < val){ //if top most element is greater than x.
		st.pop(); //then pop out that top most element
		SortedInsert(st,x); //do recursive call
		st.push(val); //once inserted x, then before going back, insert val in stack one by one
	}
	else{
		st.push(x); //else, if x is greater than val, then insert that x on top of stack and return.
	}
}

void SortedStack :: sort()
{
   x`
		return;
	}

	int val=s.top();
	s.pop();

	sort();
	SortedInsert(s,val);
}

//small change in sorted insert function
void SortedInsert(stack<int>&st,int x){
	if(st.empty() or st.top() <= x){ //change is adding another condition when top element is less than x, so in those situation insert x on top
		st.push(x);
		return;
	}

	int val=st.top(); //we will reach here when top most element is greater than x,
	st.pop(); //so take a side and pop out element and do another recursive call.
	
	SortedInsert(st,x);
	
	st.push(val); //once inserted x at its correct position, then before going back, insert val in stack one by one.
}