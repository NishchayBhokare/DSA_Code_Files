
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


//Approahc 2: using semaphore. 

class Semaphore{
    private:
        int count;
        mutex mtx;
        condition_variable cv;

    public:
    void setCount(int c){
        this->count = c;
    }

    void wait(){

        unique_lock<mutex> lock(mtx);
        count--;

        if(count < 0) //agar count lesser than zero hai matlab already koi thread c.s ke andar hai. so wait.
        //kynki initially count is 1 so if one thread is already there and another thread comes then 1-2 equals to -1 which lesser than zero.
            cv.wait(lock);
    }


    void signal(){
        unique_lock<mutex> lock(mtx);
        count++;

        if(count <= 0) //agar count lesser than zero hai that means aur threads wait kar rahe hai..so notify kardo.
        //agar single thread hoti toh count 1 hojata 0 se. after increment
            cv.notify_all();
    }
};


class DiningPhilosophers {
public:
    Semaphore fork[5]; 
    mutex m;
    condition_variable cv;

    DiningPhilosophers() {
        
        for(int i=0; i<5; i++){
            fork[i].setCount(1);
        }
    }

    void wantsToEat(int ph,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		
        

        unique_lock<mutex>lock(m);
    
       fork[ph].wait();
       fork[(ph+1)%5].wait(); 
       
       pickLeftFork();
       pickRightFork();

       eat();        

       fork[ph].signal();
       fork[(ph+1)%5].signal(); 

       putLeftFork();
       putRightFork();

       cv.notify_all();
    }
};

//Approach 3:Philosopher picks Fork when both forks are available. my way. not good.
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