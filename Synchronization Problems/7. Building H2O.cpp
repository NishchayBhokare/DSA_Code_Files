//Leetcode problem.


//Here we have to build h20 molecule in such a way that 2 Hydrogen molecules comes before 1 oxygen.
class H2O {
public:

    mutex m;
    condition_variable cv;
    int turn, Hcnt;

    H2O() {
        this->turn = 0; //initially turn will be zero.
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        unique_lock<mutex> lock(m);

        while(turn == 2) //if turn equals to 2 that means we have to wait for hydrogen's turn.
            cv.wait(lock);


        releaseHydrogen();
        turn++; //increment turn. If turn is 0 and 1 then hydrogen function will work. and 
        //if turn is 2 then oxygen function gets called.
        
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        unique_lock<mutex> lock(m);

        while(turn != 2)
            cv.wait(lock);


        releaseOxygen();
        turn = 0; //make turn to zero to get next set of hydrogen.

        cv.notify_all();
    }
};