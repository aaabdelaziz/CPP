// https://www.geeksforgeeks.org/cpp-11-atomic-header/
// C++ Program to illustrate the usage of <atomic> Header
#include <atomic>
#include <iostream>
#include <thread>
using namespace std;


// Activate the requested example
#define EXAMPLE_1

/****************************************************************** */


#ifdef EXAMPLE_1
// To illustrate Atomic counter increament

// Create atomic counter
atomic<int> counter(0); 

void increment_counter(int id)
{
    for (int i = 0; i < 100000; ++i) {
        // Increment counter atomically
        counter.fetch_add(1);
    }
}

int main()
{
    // Every thread will increase the counter 100k times
    thread t1(increment_counter, 1);
    thread t2(increment_counter, 2);

    t1.join();
    t2.join();

    cout << "Counter: " << counter.load() << std::endl;

    return 0;
}



#elif EXAMPLE_2
// To illustrate the usage of Atomic flag

// Initialize atomic flag
atomic_flag flag = ATOMIC_FLAG_INIT;

void thread_function(int id)
{
    for (int i = 0; i < 5; ++i) {
        while (flag.test_and_set(memory_order_acquire)) {
        }
        // Acquire lock
        cout << "Thread " << id << " is running." << endl;
        flag.clear(memory_order_release); // Release lock
    }
}

// driver code
int main()
{
    thread t1(thread_function, 1);
    thread t2(thread_function, 2);

    t1.join();
    t2.join();

    return 0;
}


#endif
