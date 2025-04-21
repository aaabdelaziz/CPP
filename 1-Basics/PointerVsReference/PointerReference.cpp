/*Pointers can be reassigned to point to different memory locations during their
lifetime.*/
int x = 10, y = 20;
int* ptr = &x; // ptr points to x
ptr = &y; // ptr now points to y
 
// References cannot be reassigned after initialization; they always refer to the same
object.
int x = 10, y = 20;
int& ref = x; // ref refers to x
ref = y; // This assigns the value of y to x, but ref still refers to x