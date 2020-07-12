#include "greeting.h"

namespace wrap_example {

/// Print a greeting
void Greeting::sayHello() const {
    std::cout << "Hello from C++!" << std::endl;
}

/// Print a farewell
void Greeting::sayGoodbye() const {
    std::cout << "Goodbye, robot" << std::endl;
}

};
