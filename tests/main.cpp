#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <units.hpp>

using Units::Measurement;

void assert_close(double a, double b) {
  static const double epsilon = 1.0e-12;
  if ((a - b) >= epsilon || (b - a) >= epsilon) {
    throw std::runtime_error(
      "Assertion failed: " + std::to_string(a) + " != " + std::to_string(b)
    );
  }
}

template <typename Num, typename Unit, typename Unit2>
void assert_close(Measurement<Num, Unit> a, Measurement<Num, Unit2> b) {
  static_assert(
    std::is_same<typename Unit::Base, typename Unit2::Base>::value,
    "Compared measurements must have the same base unit"
  );
  assert_close(a.unit.to_base(a.value), b.unit.to_base(b.value));
}

int main() {
  Measurement length1 { 5.0, Units::meters{} };
  Measurement length2 { 0.8, Units::kilo<Units::meters>{} };
  assert_close(length1 + length2, Measurement { 805.0, Units::meters{} });
  assert_close(length1 - length2, Measurement {
    -0.795,
    Units::kilo<Units::meters>{}
  });
  return 0;
}
