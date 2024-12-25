//GFG.

bool lemonadeChange(int N, vector<int> &bills) {
    int fiveCoins = 0;
    int tenCoins = 0;
    //as there is no need to track 20rs coins.

    for(int i=0; i<N; i++){
        
        if(bills[i] == 5) fiveCoins++; //if five coins given by customer..then just increment fiveCoins cnt. as we don't have to return.
        else if(bills[i] == 10){ //if 10 rs coins given then need to return 5rs coins.
            tenCoins++;
            
            if(fiveCoins) fiveCoins--; //if five rs coins is there then decrement it by one.
            else return false; //else return false. not possible.
        }
        else{
            
            ///if 20rs given by customer then need to return 15. we can give by 10+5 or 5+5+5.
            if(tenCoins && fiveCoins){ //checking for comination of 10+5.
                tenCoins--; 
                fiveCoins--;
            }
            else if(fiveCoins >= 3){ //checking for three five coins.
                fiveCoins -= 3;
            }
            else return false; //else return false.
        }
    }
    
    return true; //if reach till here then return true.
}