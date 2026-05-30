
//Approach 1: Optimised Approach. using Mutex 
class DiningPhilosophers {
public:
    mutex forks[5];

    DiningPhilosophers() {
        
    }


    void wantsToEat(int ph,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		
        
        
        int left = ph;
        int right = (ph+1)%5;

        int firstFork = min(left,right);
        int secondFork = max(left,right); //used to avoid circular condition. last person
        //will not take 4th fork first, it will take 0th fork due to which circular chain breaks.
        
        // 0th Philosopher takes firstfork is 0 and wait for secondfork 1 ( suddenly philosopher 1 comes)
        // 1st philospher takes firstfork 1 and wait for secondfork 2.
        // 2nd philospher takes firstfork 2 and wait for secondfork 3.
        // 3rd philospher takes firstfork 3 and wait for secondfork 4.
        // 4th philospher try to take firstFork 0 (goes in wait).

        // so 3 rd philospher completes its execution and release 3rd and 4th forks. and reaming DiningPhilosopher
        // complete their execution.

        unique_lock<mutex>lock1(forks[firstFork]); //make locks 
        unique_lock<mutex>lock2(forks[secondFork]);


        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();

    
    //optional as via destructor lock will get released so explicitly no need to mention.

        // lock1.unlock();
        // lock2.unlock();

    }
};

//Approach 2:Philosopher picks Fork when both forks are available.
class DiningPhilosophers {
public:
    vector<int>fork;
    mutex m;
    condition_variable cv;

    DiningPhilosophers(): fork(5,0) {
        
    }

    void wantsToEat(int ph,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork)  {
		
        unique_lock<mutex>lock(m); //It is not acheving concurrency. as on entry, we are locking threads.

        while(fork[ph] == 1 || fork[(ph+1) % 5] == 1){
            cv.wait(lock);
        }

        fork[ph] = 1;
        fork[(ph+1) % 5] = 1;
      

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();
        
        fork[ph] = 0;
        fork[(ph+1) % 5] = 0;

        cv.notify_all(); 
    }
};