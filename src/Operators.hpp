#ifndef __UNITSLIB_OPERATORS_HPP__
#define __UNITSLIB_OPERATORS_HPP__

#include <Unit.hpp>
#include <Measurement.hpp>

namespace Units {
  // Distance units:
  Measurement<double, meters> operator "" _m(long double value) {
    return Measurement { static_cast<double>(value), meters{} };
  }
  Measurement<double, mega<meters>> operator "" _Mm(long double value) {
    return Measurement { static_cast<double>(value), mega<meters>{} };
  }
  Measurement<double, kilo<meters>> operator "" _km(long double value) {
    return Measurement { static_cast<double>(value), kilo<meters>{} };
  }
  Measurement<double, milli<meters>> operator "" _mm(long double value) {
    return Measurement { static_cast<double>(value), milli<meters>{} };
  }
  Measurement<double, micro<meters>> operator "" _µm(long double value) {
    return Measurement { static_cast<double>(value), micro<meters>{} };
  }
  // Time units:
  Measurement<double, seconds> operator "" _s(long double value) {
    return Measurement { static_cast<double>(value), seconds{} };
  }
  Measurement<double, mega<seconds>> operator "" _Ms(long double value) {
    return Measurement { static_cast<double>(value), mega<seconds>{} };
  }
  Measurement<double, kilo<seconds>> operator "" _ks(long double value) {
    return Measurement { static_cast<double>(value), kilo<seconds>{} };
  }
  Measurement<double, milli<seconds>> operator "" _ms(long double value) {
    return Measurement { static_cast<double>(value), milli<seconds>{} };
  }
  Measurement<double, micro<seconds>> operator "" _µs(long double value) {
    return Measurement { static_cast<double>(value), micro<seconds>{} };
  }
}

#endif
