#ifndef __UNITSLIB_OPERATORS_HPP__
#define __UNITSLIB_OPERATORS_HPP__

#include <Unit.hpp>
#include <Measurement.hpp>

namespace Units {
  // Distance units:
  Measurement<double, meters> operator "" _m(long double value) {
    return Measurement { static_cast<double>(value), meters{} };
  }
  Measurement<double, kilo<meters>> operator "" _km(long double value) {
    return Measurement { static_cast<double>(value), kilo<meters>{} };
  }
  Measurement<double, milli<meters>> operator "" _mm(long double value) {
    return Measurement { static_cast<double>(value), milli<meters>{} };
  }
  // Time units:
  Measurement<double, seconds> operator "" _s(long double value) {
    return Measurement { static_cast<double>(value), seconds{} };
  }
  Measurement<double, kilo<seconds>> operator "" _ks(long double value) {
    return Measurement { static_cast<double>(value), kilo<seconds>{} };
  }
  Measurement<double, milli<seconds>> operator "" _ms(long double value) {
    return Measurement { static_cast<double>(value), milli<seconds>{} };
  }
}

#endif
