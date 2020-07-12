#include "greeting.h"

namespace gtsam_example {

/// Print a greeting
void Greeting::sayHello() const {
    std::cout << "Hello from C++!" << std::endl;
}

/// Print a farewell
void Greeting::sayGoodbye() const {
    std::cout << "Goodbye, robot" << std::endl;
}

};
