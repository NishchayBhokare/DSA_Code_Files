//Minimum Cost To Make String Valid from coding ninja or Count the Reversals from gfg
//GFG
//gfg link- https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article


//Approach 1: Most optimised. TC-O(N) SC-O(1)
int countRev (string str)
{
    
  if(str.length() & 1) return -1; //string length is odd then brackets are not possible to balanced
  // creating stack
    
  int opening=0;
  int count=0; //creating two variable one for storing opening braces counta and another to store how many times we change closing braces to opening braces
  for(int i=0; i<str.length(); i++){ //looping over string
    char ch=str[i]; 
    if(ch == '{') opening++; //if opening braces encountered then increment opening
    
    else{ //else means closing braces
        if(opening == 0){ //and opening is 0, that means this closing bracket comes before opening so we need to change this to opening
            count++; //so increment count
            opening++;   //assume we changed this so now that closing brace become opening so increment count of opening.
        }
        else{ //if opening breaces greater than 0, and we encounterd ch as closing brace then eleminate this valid bracket i.e decrement opening.
            opening--; //once clsosing braces encounterd then decreement opening braces i.e eliminating braces
        }
    }
  }

  int ans=opening/2 + count; //once we reach last then answer will be opening braces divide by 2 and how many times we change closing braces to opening braces.
  return ans; //return ans;
}


//Approach2: Using stack TC-O(N) SC-O(N) 
//Analogy: if string is invalid that means, these follwing three cases will be there
// 1. {{{{{{ i.e only opening bracket.
// 2. }}}}}} i.e only closing bracket
// 3. }}}{{{ i.e odd combination of closing and opening,  }}}}{{{{ i.e even combination of closing and opening braces
int countRev (string str)
{

if(str.length() & 1) return -1; //string length is odd then brackets are not possible to balanced
  stack<char> st; // creating stack
  int count=0; //creating count with 0

  for(int i=0; i<str.length(); i++){ //looping over string
    char ch=str[i]; 
    if(ch == '{') st.push(ch); //if character is opening bracket then push into the stack.

    else{ //when char ch == '}' is closing bracket,
      if(!st.empty()) st.pop(); // and stack is not empty then pop out top element i.e its opening bracket

      else{ //if stack is empty means we need to change this closing bracket with opening bracket. so increment count.
        st.push('{'); //then push closing bracket as opening bracket in stack
          //and increment count.
          count++;
      }
    }
  }

//lastly in stack if stack is not empty then opening brackets will be present in stack,
//so to change those opening bracket we need to do size/2 operations. and also need to add count, because we might need to change closing braces to opening bracket when stack is empty
    count = st.size()/2 + count; 
    return count;
}




//Approach 3: TC-O(N) SC-O(N)
//Analogy: if string is invalid that means, these follwing three cases will be there after elminating those right braces like {}.
// 1. {{{{{{ i.e only opening bracket.
// 2. }}}}}} i.e only closing bracket
// 3. }}}{{{ i.e odd combination of closing and opening,  }}}}{{{{ i.e even combination of closing and opening braces
//so for first two cases size/2 number of operations required to validate braces.
//in third case for odd combination we need 4 operations to change i.e size of a+1/2 + size of b+1/2. a->{ and b->}
//and in odd case we need size of a/2+ size of b/2 operations, so if we observe carefully we can sum of equation on (size of a + 1)/2 + (size of b + 1)/2. to get minimum operation
int countRev (string str)
{
    
  if(str.length() & 1) return -1; //string length is odd then brackets are not possible to balanced
  stack<char> st; // creating stack

  for(int i=0; i<str.length(); i++){ //looping over string
    char ch=str[i]; 
    if(ch == '{') st.push(ch); //if character is opening bracket then push into the stack.

    else{ //when char ch == '}' is closing bracket,
      if(!st.empty() and st.top() == '{') st.pop(); // and stack is not empty and top character is opening bracket, then pop out top element i.e right braces and elminiate it.

      else{ //if stack is empty or if top is not opening bracket then push this invalid closin bracket into the stack
       st.push(ch);
      }
    }
  }

    int a=0,b=0; //a represent opening and b represent closing braces
    while(!st.empty()){
        char ch=st.top();
        if(ch == '{') a++; //count the number of openinig braces and closing breaces
        else b++;
        st.pop();
    }
  
    int ans = (a+1)/2 + (b+1)/2; //calculate ans by formula
    return ans; //and return 
}
