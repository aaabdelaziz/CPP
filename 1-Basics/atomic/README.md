
# Atomic Operation 

- Atomic is used in c++11 to introduce powerful mechanism for managing concurrent access to shared data in multithreaded applications. 
- It provides atomic types and operations that ensure safe access to variables, preventing data races and potential issues in multithreaded code.
- Concurrent data access is regulated by a memory model for which the behavior is well-defined if one thread tries to access the data that another thread is currently accessing.
- The <atomic> header provides some functions to perform these atomic operations.
- Resources (https://www.geeksforgeeks.org/cpp-11-atomic-header/)

```
-------------------------------------------------------------------------------------------------------------------------------------------------
No.             Function             Description
-------------------------------------------------------------------------------------------------------------------------------------------------
1               load()              This function loads the value stored in the atomic object.
2               store()             The function stores the value in the atomic object.
3               exchange()          This function replaces the value stored in the atomic object and returns the previously stored value.
4               wait()              This function is used to block the thread.
5               notify_one()        Notifies one of the threads that was waiting for the atomic object.
6               notify_all()        Notifies all the threads that were waiting for the atomic object.
7               fetch_add()         Gets the current value stored and adds the given value to the atomic object's value.
8               fetch_sub()         Gets the current value stored and subtracts the given value from the atomic object's value.
9               fetch_and()         Gets the current value stored and performs bitwise AND operation with atomic value and given value.
10              fetch_or()          Gets the current value stored and performs bitwise OR operation with atomic value and given value.
11              fetch_xor()         Gets the current value stored and performs bitwise XOR operation with atomic value and given value.
```

