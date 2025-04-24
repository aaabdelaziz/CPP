
#include <iostream>
#include <utility> // used it for std::move
#include <string>

class StringHolder 
{

    public:
        // Constructor
        StringHolder(const std::string& data) : data_(data) {
            std::cout << "Constructed: " << data_ << std::endl;
        }

        // Move constructor
        StringHolder(StringHolder&& other) noexcept : data_(std::move(other.data_)) {
            std::cout << "Move constructed: " << data_ << std::endl;
        }

        // Destructor
        ~StringHolder() {
            std::cout << "Destructed: " << data_ << std::endl;
        }

        void show() const {
            std::cout << "Data: " << data_ << std::endl;
        }

    private:
        std::string data_;
};

// Function that takes ownership of a StringHolder object using move semantics
void processString(StringHolder holder) 
{
    holder.show();
}

int main()

{
    StringHolder original("Testing, Move Semantics!");

    // Passing by value will invoke the move constructor
    processString(std::move(original));

    // At this point, `original` is in a valid but unspecified state
    // Trying to use original here may lead to undesired outputs
    // original.show(); // Uncommenting this will lead to undefined behavior

    return 0; // The program will cleanly destruct remaining objects
}