//Circle Tour Example
//gfg

struct petrolPump
{
    int petrol;
    int distance;
};

//Approach 1: Most optimised approach TC-O(N) SC-O(1)
 int tour(petrolPump p[],int n)
    {
        int deficit=0; //kiti petrol kami padat ahe
        int balance=0; //how much balance is remaining for reaching to next petrol pum.
        int start=0; 
        for(int i=0; i<n; i++){
            //step1 : calculate balance 
            balance = balance + p[i].petrol - p[i].distance;
            
            if(balance < 0 ){ //if balance is less than 0, then tour is not possible from start index so update start index to i+1.
                start=i+1; //same like front = rear+1.
                deficit +=balance; //add those deficit balance in deficit variable
                balance = 0; //now restart balance with 0.
            }  
        }
        
        //why doing this because. for last element's of petrol-distance + dificit should be greater than or equal to 0.
        if(balance + deficit >= 0) return start; //to remove cases when we need to visit every petrol pump two times. 
        else return -1;
    }


//Approach 2: Checking for every index whether it can start or not. Tc-O(N2) SC-O(1)
int tour(petrolPump p[],int n)
    {
        int balance=0;
        int start=0;
        for(int start=0; start<n; start++){
            balance=0;
            int j=start;
            do{
                
            balance = balance + p[j].petrol - p[j].distance;
            if(balance < 0 ){
                break;
            }
           
            if(j==n-1) j=0;
            else j++;
            
          } while(start != j);
          
          if(balance >=0) return start;
        }
        
        return -1;
    }