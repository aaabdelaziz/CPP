
#include <iostream>
#include <boost/lexical_cast.hpp>

int main()
{
    try
    {
        int num = boost::lexical_cast<int>("123");
        std::cout << "Converted integer: " << num << std::endl;

        std::string str = boost::lexical_cast<std::string>(456);
        std::cout << "Converted string: " << str << std::endl;

        std::cout << "Using Boost "
                  << BOOST_VERSION / 100000 << "."     // major version
                  << BOOST_VERSION / 100 % 1000 << "." // minor version
                  << BOOST_VERSION % 100               // patch level
                  << std::endl;
    }
    catch (const boost::bad_lexical_cast &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
