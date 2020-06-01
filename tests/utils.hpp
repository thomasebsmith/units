#ifndef __UNITSLIB_TESTS_UTILS_HPP__
#define __UNITSLIB_TESTS_UTILS_HPP__

#include <units.hpp>
#include <stdexcept>
#include <string>
#include <type_traits>

class Assertion {
public:
  Assertion(bool assertion_passed, const std::string &message_if_false,
            bool negated_message = false):
    value{assertion_passed}, message{message_if_false},
    negated{negated_message} {}

  void error_if_false() {
    if (!value) {
      if (negated) {
        throw std::runtime_error("Assertion failed: it was not the case that " +
          message);
      }
      else {
        throw std::runtime_error("Assertion failed: it was the case that " +
          message);
      }
    }
  }

  Assertion operator!() {
    return { !value, message, !negated };
  }

private:
  bool value;
  std::string message;
  bool negated;
};

Assertion close(double a, double b) {
  static const double epsilon = 1.0e-12;
  return {
    (a - b) < epsilon && (b - a) < epsilon,
    std::to_string(a) + " != " + std::to_string(b)
  };
}

void test(Assertion assertion) {
  assertion.error_if_false();
}

template <typename Num, typename Unit, typename Unit2>
Assertion close(Units::Measurement<Num, Unit> a,
                Units::Measurement<Num, Unit2> b) {
  static_assert(
    std::is_same<typename Unit::Base, typename Unit2::Base>::value,
    "Compared measurements must have the same base unit"
  );
  return close(a.unit.to_base(a.value), b.unit.to_base(b.value));
}

#endif
