#include "greeting.h"

namespace wrap_example {

/// Print a greeting
void Greeting::sayHello(const std::string& s) {
  name = s;
  std::cout << "Hello from C++!" << (name.empty() ? "" : " " + name)
            << std::endl;
}

/// Print a farewell
void Greeting::sayGoodbye() const {
  std::cout << "Goodbye, robot" << std::endl;
}

};  // namespace wrap_example
