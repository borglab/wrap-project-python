#include <iostream>
#include <string>

namespace wrap_example {

class Greeting {
 public:
  std::string name;

  /// Print a greeting and optionally add name
  void sayHello(const std::string& s = "");

  /// Print a farewell
  void sayGoodbye() const;
};

}  // namespace wrap_example
