//Leetcode Link: https://leetcode.com/problems/print-in-order/
//Print in order question where we have to print first function, second function and third function 
// in same order


#include<bits/stdc++.h>
using namespace std;
class Foo {
public:
    mutex m; //creating mutex
    condition_variable cv; //creating conditional variable
    int turn;
    Foo() {
        
        turn = 0; //initializing turn variable.
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst(); //print first function.
        turn=1; //make turn to 1.
        cv.notify_all(); //notify all other threads that, t1 thread first function execution completed.

    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> lock(m); //creating unique lock for function. making it as c.s
        while(turn != 1){ //till turn not equal to 1. be in loop, cause we have to print function second
            //in second place when first gets executed.
            cv.wait(lock); //wait till turn equals to 1.
        }

        printSecond(); //once while condition fails, first executed then print second.
        turn = 2; //make turn as 2.
        cv.notify_all(); //and notify all other threads that, second function execution completed.

    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex> lock(m); 
        while(turn != 2){ //till second function not executes, wait here.
            cv.wait(lock);
        }

        printThird(); //once done with second function, execute third.
        turn = 3; //make turn to 3.
        cv.notify_all(); //notify all other threads.

    }
};