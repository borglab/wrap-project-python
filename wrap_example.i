/* ----------------------------------------------------------------------------
 * GTSAM Copyright 2010, Georgia Tech Research Corporation,
 * Atlanta, Georgia 30332-0415
 * All Rights Reserved
 * Authors: Frank Dellaert, et al. (see THANKS for the full author list)
 * 
 * See LICENSE for the license information
 * -------------------------------------------------------------------------- */

/**
 * @file     wrap_example.i
 * @brief    Example wrapper interface file for Python
 * @author   Varun Agrawal
 * @author   Fan Jiang
 */

// This is an interface file for automatic Python wrapper generation.
// See gtsam.h for full documentation and more examples.
#include <src/greeting.h>

// The namespace should be the same as in the c++ source code.
namespace wrap_example {

class Greeting {
  Greeting();

  // We can wrap class variables but only if they are `public`
  string name;

  void sayHello(const string& name);
  void takeAPointer(const double* d) const;
  void sayGoodbye(wrap_example::Greeting** x) const;

};

template<T = {string, double}, R = {double}>
R CoolFunction(const T& s);

}  // namespace wrap_example
