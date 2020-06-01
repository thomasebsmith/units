#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <units.hpp>

using namespace Units;

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
  Measurement length1 { 5.0, meters{} };
  Measurement length2 { 0.8, kilo<meters>{} };
  assert_close(length1 + length2, Measurement { 805.0, meters{} });
  assert_close(length1 - length2, Measurement {
    -0.795,
    kilo<meters>{}
  });
  Measurement time1 { 0.33, milli<seconds>{} };
  Measurement time2 { 50.0, micro<seconds>{} };
  assert_close(time1 + time2, Measurement { 0.38, milli<seconds>{} });
  assert_close(length2 * time1, Measurement {
    0.264,
    Product<meters, seconds>{}
  });
  assert_close(length2 * time1, time1 * length2);
  assert_close(length1 / time1, Measurement {
    5.0 / 0.00033,
    Quotient<meters, seconds>{}
  });
  assert_close(length1, 5.0_m);

  assert_close(5003.0_m, 5.003_km);

  auto length3 = 0.003801723293455219_km;
  assert_close(0.0303_ks * 90.0_mm, (length3 * length3) * 1000.0_ms / 5.3_m);

  assert_close(503.0_µm * 2.0_Ms, 251.5_µs * 4.0_Mm);

  assert_close(3.5389_kg, 3538.9_g);

  assert_close(1.0_N, 1.0_m * 1000.0_g / 1.0_s / 1.0_s);
  return 0;
}
