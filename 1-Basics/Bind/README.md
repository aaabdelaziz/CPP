# Bind Usage Examples
- In C++, the std::bind function is a part of the Standard Template Library (STL) 
- Used to bind a function or a member function to a specific object or value. 
- It creates a new function object by “binding” a function or member function to a specific object or value, allowing it to be called with a different number of arguments or with a different order of arguments.

```
    Syntax:

    std::bind(function, object/value, arguments...);

    Parameters:

    -> function:
        
        It is the member function that you want to bind. It can be a function pointer, a function object, or a member function pointer.
    
    -> object/value: 
    
        The object or value to which you want to bind the function. 
        For member functions, this is the object on which the member function will be called.  
        For free functions, this argument can be ignored.
    
    -> arguments: 
        Are any additional arguments that should be passed to the function when it is called. 
        These can include placeholders represented by std::placeholders::_1, std::placeholders::_2, etc, which can be used to specify where the arguments passed to the returned function object should be placed.

```

- Return Value: The std::bind function in C++ returns a function object, also known as a “call wrapper” or “binder”,

- The call wrapper can be any name that describes the current rquested call operation. (it makes the )

- Reference https://www.geeksforgeeks.org/working-and-examples-of-bind-in-cpp-stl/
