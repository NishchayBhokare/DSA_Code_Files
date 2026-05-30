#include<iostream>
#include<bits/stdc++.h>
#include <unistd.h>
#include<thread>

using namespace std;

Lock = lock() (Mutual Exclusion)
void taskA(){
    lock.acquire()
    for(int i=0; i<10; ++i){
        fprintf("Task A: ", A);
        fflush(stdout);
    }
    lock.release()
}

void taskB(){

    for(int i=0; i<10; ++i){
        fprintf("Task B: ", B);
        fflush(stdout);
    }
}

int main(){

    thread t1(taskA);
    thread t2(taskB);

    t1.start();
    t2.start();
    t1.join();
    t2.join();

    return 0;
}