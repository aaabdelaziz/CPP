// to understand more about move semantics
// https://www.google.com/search?q=youtube+%2B+move+semantics#fpstate=ive&vld=cid:f6c4db7a,vid:ehMg6zvXuMY,st:0
// https://www.udemy.com/course/beg-modern-cpp/learn/lecture/6569540#notes


# How to use LR values with Move semantic

- C++ introduced the L Value and R Value to help to create move semantics.
- Basically, Move semantics is very efficient to save memory and speed while we send an object to function.
- we need that function to take the ownership of that object. In this case what we can only send the object by reference to requested function, for example here I used to pass to processString().
- References (https://medium.com/@everythingismindgame/lvalue-rvalue-copy-and-move-construtors-314a49074e29)