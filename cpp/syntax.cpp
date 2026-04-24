#include <array>       // std::array fixed-size container.
#include <functional>  // std::function callable wrapper.
#include <iostream>    // std::cout terminal output.
#include <map>         // std::map key/value dictionary.
#include <stdexcept>   // std::runtime_error exception type.
#include <string>      // std::string dynamic text.
#include <vector>      // std::vector dynamic array.

#include "syntax.h"  // Classes, templates, and function declarations.

// This function converts a double to an integer by truncating decimals.
int TruncateDouble(double x) { return static_cast<int>(x); }

int main() {
  // This writes plain text output to the terminal.
  std::cout << "Hello, C++ syntax program!\n\n";

  // FUNDAMENTAL TYPES

  bool boolean_value = false;          // bool stores true/false.
  char character_letter = 'a';         // char stores one byte character.
  unsigned char u8 = 200;              // unsigned char stores 0..255.
  int integer = 2;                     // int stores whole numbers.
  long long integer64 = 1'000'000LL;   // long long often stores 64-bit ints.
  float single_precision = 0.5f;       // float stores single-precision decimal.
  double double_precision = 0.25;      // double stores double-precision decimal.
  const double pi = 3.1415926535;      // const marks immutable data.

  // This prints fundamental values so they are used and visible.
  std::cout << "bool=" << boolean_value << ", char=" << character_letter
            << ", u8=" << static_cast<int>(u8) << ", int=" << integer
            << ", int64=" << integer64 << ", float=" << single_precision
            << ", double=" << double_precision << ", pi=" << pi << "\n\n";

  // ARRAYS AND CONTAINERS

  std::array<double, 5> fixed_array = {1.0, 0.5, 0.25, 0.125, 0.0625};
  std::vector<int> dynamic_array = {1, 2, 3};  // vector can grow at runtime.
  dynamic_array.push_back(4);                  // Append one element.

  std::map<std::string, int> score = {{"alice", 10}, {"bob", 7}};
  score["carol"] = 9;  // Insert/update by key.

  std::cout << "fixed_array values: ";
  for (double value : fixed_array) {  // Range-based for loop.
    std::cout << value << " ";
  }
  std::cout << "\ndynamic_array size=" << dynamic_array.size()
            << ", carol score=" << score["carol"] << "\n\n";

  // CONTROL FLOW

  bool should_do = true;       // This drives if/else branching.
  bool otherwise_todo = true;  // This drives else-if branch.
  if (!should_do) {
    std::cout << "First branch.\n";
  } else if (otherwise_todo) {
    std::cout << "Else-if branch.\n";
  } else {
    std::cout << "Final else branch.\n";
  }

  std::cout << "for loop: ";
  for (std::size_t k = 0; k < dynamic_array.size(); ++k) {  // Indexed loop.
    std::cout << dynamic_array[k] << " ";
  }
  std::cout << "\n";

  int counter = 2;  // This state changes during while loop.
  std::cout << "while loop: ";
  while (counter < 100) {  // Run while condition is true.
    counter *= 2;
    std::cout << counter << " ";
  }
  std::cout << "\n";

  int switch_value = 2;  // This selects one switch case.
  std::cout << "switch: ";
  switch (switch_value) {
    case 1:
      std::cout << "one\n";
      break;  // break prevents fallthrough.
    case 2:
      std::cout << "two\n";
      break;
    default:
      std::cout << "other\n";
      break;
  }
  std::cout << "\n";

  // STRINGS

  std::string greeting = "Hello";         // std::string stores text.
  greeting += ", world";                  // Concatenation/appending.
  std::size_t where = greeting.find("w");  // Search returns position.
  std::cout << "string=\"" << greeting << "\", find('w')=" << where << "\n\n";

  // FUNCTIONS, LAMBDAS, AND FUNCTION POINTERS

  int (*function_pointer)(double) = TruncateDouble;  // Pointer to function.
  std::function<double(double)> square =              // Lambda with callable type.
      [](double x) { return x * x; };
  std::cout << "TruncateDouble(pi)=" << function_pointer(pi)
            << ", square(3)=" << square(3.0) << "\n\n";

  // REFERENCES AND POINTERS

  int value = 5;            // Regular integer value.
  int& alias = value;       // Reference is another name for same object.
  int* address = &value;    // Pointer stores object address.
  alias += 1;               // Mutating alias mutates value.
  *address += 1;            // Dereferencing pointer mutates value.
  std::cout << "value after ref+ptr updates=" << value << "\n\n";

  // CLASSES AND OBJECTS

  AClass cls;               // Instantiate object.
  cls.SetX(4);              // Set internal integer.
  cls.SetZAsProduct(5.2);   // Compute z = c*x.
  std::cout << "AClass z=" << cls.GetZ() << "\n";

  AClass cls2;              // Separate instance has separate state.
  cls2.SetX(8);
  cls2.SetZAsProduct(1.703333);
  std::cout << "AClass z1=" << cls.GetZ() << ", z2=" << cls2.GetZ() << "\n\n";

  Summer summer;            // Derived class from Operation.
  Multiplier multiplier;    // Another derived class from Operation.
  std::cout << "summer sum=" << summer.GetSum()
            << ", multiplier product=" << multiplier.GetProduct() << "\n\n";

  // TYPE ALIASES AND ENUMS

  using UnsignedInt = unsigned int;  // using creates readable type alias.
  UnsignedInt alias_value = 5;

  enum class Mode { kRead, kWrite };  // enum class creates scoped constants.
  Mode mode = Mode::kRead;
  std::cout << "alias_value=" << alias_value
            << ", mode_is_read=" << (mode == Mode::kRead) << "\n\n";

  // TEMPLATES

  Line<double> line_double(2.0 * pi, 1.0);  // Generic class with double.
  Line<int> line_int(2, 1);                  // Same template with int.
  std::cout << "Line<double>(1.0)=" << line_double.Compute(1.0)
            << ", Line<int>(1)=" << line_int.Compute(1) << "\n\n";

  // EXCEPTIONS

  try {  // try block captures exceptions from risky code.
    throw std::runtime_error("Example exception");
  } catch (const std::exception& ex) {  // catch handles base exception types.
    std::cout << "Caught exception: " << ex.what() << "\n";
  }

  return 0;  // Returning 0 indicates successful program completion.
}
