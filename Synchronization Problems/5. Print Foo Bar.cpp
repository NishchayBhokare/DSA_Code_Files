//Leetcode problem.

class FooBar {
private:
    int n, turn; //creating turn variable to decide whose turn is there.
    mutex m; //initializing mutex.
    condition_variable cv; //and conditional variable.

public:
    FooBar(int n) {
        this->n = n;
        this->turn = 0; // if turn = 0 will print Foo and if turn = 1 will print Bar
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	unique_lock<mutex> lock(m); //making lock

            while(turn == 1) //if turn equals to 1 that means we have to print bar so thread should wait here.
                cv.wait(lock); //if thread goes into wait state, it releases lock.

        	printFoo(); //if turn is zero then we will print Foo.
            turn = 1; // and make turn to 1 so that we can print bar.
            cv.notify_all(); // notify other threads.
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	unique_lock<mutex> lock(m);

            while(turn == 0) // if turn is zero than wait here till turn not becomes 1.
                cv.wait(lock);
            
        	printBar();
            turn = 0;
            cv.notify_all();
        }
    }
};