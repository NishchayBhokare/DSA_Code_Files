// The Celebrity Problem
//GFG  

//Approach 1: Most optimised approach.Two pointer approach TC-O(N) SC-O(1)  
//Conditions for celebrity candidate:
    //Everyone knows celebrity candidate
    //Celebrity candidate dont know any one.

 int celebrity(vector<vector<int> >& mat) {

    int firstP=0;
    int secondP=mat.size()-1;
    while(firstP<secondP){ //finding potential candidate of celebrity.
        
        if(mat[firstP][secondP]==1) firstP++;
        
        else if(mat[secondP][firstP]==1) secondP--;
        
        else{
            firstP++; secondP--;
        }
    }
    
    if(firstP>secondP)  //if first and second crosess each other..then there no celebrity present.
        return -1;
    
    for(int i=0; i<mat.size(); i++){ //both first and second person will points same person. so take any one.
        
        if(i!=firstP && (mat[firstP][i] !=0 || mat[i][firstP] != 1)){ //cross checking possible celebrity row and column.
            return -1; //if row does'nt equals to 0 because celebrity does'nt know anyone.
            // and column doesn't equals to 1 because everyone knows celebrity. then return -1.
        }
    }
    
    return firstP;
}

//similar like aboev approach.
int celebrity(vector<vector<int> >& matrix, int n) 
{   
    
    int candidate=n-1;
    int i=0;
    while(i < candidate){ //first calculating potential candidate. after loop over i and candidate will points to same person.  
        if(matrix[i][candidate] == 1) i++;
        else candidate--;
    }

//     int candidate=0; //another way to calculate potential candidate
//    for(int i=1; i<n; i++){
//       if(matrix[candidate][i] == 1) candidate=i;
//   }
    
    
   //check row and col for this possible celerbity. he should not know anyone.
        for(int i=0; i<mat.size(); i++){
            //check for row & col.
            if(i!=candidate && (mat[candidate][i] == 1 || mat[i][candidate] == 0)){
                return -1; //not celebrity.
            }
        }
        
        return candidate;
}
    



//Approcha 2: using stack Tc-O(N) SC-O(N)
    int celebrity(vector<vector<int> >& matrix, int n) 
    {   
       stack<int> st;
       for(int i=0; i<n; i++){ //pushing all the indexes into the stack
           st.push(i);
       }
       
       while(st.size() != 1){ //loop till stack size not equals to 1
           int a=st.top(); 
           st.pop();
           int b=st.top();
           st.pop(); //pop out and store top two elements.
           
           if(matrix[a][b] == 1) st.push(b); //if a knows b then push b into the stack and discard a becuase a cant be celebrity.
           else st.push(a); //else when a dont know b, then b won't be celebrity, so push a.
       }
       
       //at the we will get 1 element into the stack, and that might be our potential candidate
       //checking horizontal line is zero or not it must be zero for celebrity
        int index = st.top();
        if(st.size() == 1) {
            //check row for this possible celerbity. he should not know anyone.
            for(int i=0; i<n; i++){
                //check for row & col.   
                if(i!=index && (mat[index][i] == 1 || mat[i][index] == 0)){
                   return -1;
                }
            }
        }
        return index;
    }


   
   //Approach 3: TC-O(N2) SC-(1)
   //calculating horizotal sum for every ith index, if horizontal sum is zero then calculate vertical sum for that ith index.
   int celebrity(vector<vector<int> >& matrix, int n) 
    {   
       for(int i=0; i<n; i++){
           int horizontalSum=0;
           for(int j=0; j<n; j++){
               horizontalSum+=matrix[i][j];
           }
           
           if(horizontalSum == 0){
               int verticalSum=0;
               for(int a=0,b=i; a<n; a++){
                   verticalSum+=matrix[a][b];
               }
               if(verticalSum == n-1) return i;
           }
       }
       return -1;
    }

//          1 
//          1
//          1
// 0  0  0  0  0  0  0
//          1
//          1
//          1