//leetcode problem Medium

class ZeroEvenOdd {
private:
    int n, turn, i;
    mutex m;
    condition_variable cv;


public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->turn = 0; //using turn variable.
        this->i=1; //setting i as 1 because we will start i from 1 to n.
    }

    //we have set zeroFunct to print first by making turn as 0. 
    void zero(function<void(int)> printNumber) {
        

        while(i<=n){

            unique_lock<mutex> lock(m);
            
            while(i<=n && turn != 0) //jab tak zero nhi hai..wait karlo.
                cv.wait(lock);

            if(i > n) //if i goes beyond n then break.
                break;

            printNumber(0); //print zero.
            turn = (i%2) == 0 ? 2 : 1; //beautiful condition of turn. here we're setting whose turn will be
            //next. so if i's value is even then even function will having turn else odd function.     

            cv.notify_all(); //notify to all other threads.
        }
     
    }

    void even(function<void(int)> printNumber) {
        
        while(i<=n){
            unique_lock<mutex> lock(m);

            while(i<=n && turn != 2) //wait till turn not equal to 2.
                cv.wait(lock);


           
            if(i>n)
                break;
            
            printNumber(i);
            turn = 0; //here make turn to zero, cause we have to print zero after every interger.
            i++; //increment i.
            
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {

        while(i<=n){
            unique_lock<mutex> lock(m);

            while(i<=n && turn != 1)
                cv.wait(lock);


           
            if(i>n)
                break;

            printNumber(i);
            turn = 0; //same here make turn to zero.
            i++;
            
            cv.notify_all();
        }
    }
};