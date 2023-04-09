// The Celebrity Problem
//GFG  

//Approach 1: Most optimised approach. TC-O(N) SC-O(1)  
//Conditions for celebrity candidate:
    //Everyone knows celebrity candidate
    //Celebrity candidate dont know any one.
int celebrity(vector<vector<int> >& matrix, int n) 
{   
    
    int candidate=n-1;
    int i=0;
    while(i < candidate){ //first calculating potential candidate.
        if(matrix[i][candidate] == 1) i++;
        else candidate--;
    }

//     int candidate=0; //another way to calculate potential candidate
//    for(int i=1; i<n; i++){
//       if(matrix[candidate][i] == 1) candidate=i;
//   }
    
    
    //calculating horizotal and vertical sum for candidate
    int horizontalSum=0,verticalSum=0;
    for(int i=candidate,j=0; j<n; j++){
        horizontalSum+=matrix[i][j];  //adding horizotal sum
        verticalSum+=matrix[j][i]; //similarly vertical sum
    }
    
    if(horizontalSum == 0 and verticalSum==n-1) return candidate; // if horizotal sum is 0 and vertical sum is n-1 that means this candidate is celebrity.
    //n-1 becuase we skipped this condition, matrix[candidate][candidate] i.e whether candidate knows itself, so to discad this, we check with n-1.
    return -1; //if not then return -1.`
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
       int horizontalSum=0;
       for(int i=st.top(),j=0; j<n; j++){
           horizontalSum+=matrix[i][j];
       }
       
       //checking vertically all 1's or not.
       if(horizontalSum == 0){
           int verticalSum = 0;
           
           for(int i=0,j=st.top(); i<n; i++){
               verticalSum+=matrix[i][j]; 
           }
            
           if(verticalSum == n-1) return st.top();
       }
       
       return -1;
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

      1 
         1
         1
0  0  0  0  0  0  0
         1
         1
         1