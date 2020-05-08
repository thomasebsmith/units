#include <iostream>
#include <units.hpp>

int main() {
  Units::Measurement length1 { 5.0, Units::meters{} };
  Units::Measurement length2 { 0.8, Units::kilo<Units::meters>{} };
  std::cout << length1 + length2 << std::endl;
  return 0;
}
