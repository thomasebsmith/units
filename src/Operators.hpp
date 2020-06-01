#ifndef __UNITSLIB_OPERATORS_HPP__
#define __UNITSLIB_OPERATORS_HPP__

#include <Unit.hpp>
#include <Measurement.hpp>
#include <DerivedUnits.hpp>

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
  // Mass units:
  Measurement<double, grams> operator "" _g(long double value) {
    return Measurement { static_cast<double>(value), grams{} };
  }
  Measurement<double, mega<grams>> operator "" _Mg(long double value) {
    return Measurement { static_cast<double>(value), mega<grams>{} };
  }
  Measurement<double, kilo<grams>> operator "" _kg(long double value) {
    return Measurement { static_cast<double>(value), kilo<grams>{} };
  }
  Measurement<double, milli<grams>> operator "" _mg(long double value) {
    return Measurement { static_cast<double>(value), milli<grams>{} };
  }
  Measurement<double, micro<grams>> operator "" _µg(long double value) {
    return Measurement { static_cast<double>(value), micro<grams>{} };
  }
  // Electric current units:
  Measurement<double, grams> operator "" _A(long double value) {
    return Measurement { static_cast<double>(value), grams{} };
  }
  Measurement<double, mega<grams>> operator "" _MA(long double value) {
    return Measurement { static_cast<double>(value), mega<grams>{} };
  }
  Measurement<double, kilo<grams>> operator "" _kA(long double value) {
    return Measurement { static_cast<double>(value), kilo<grams>{} };
  }
  Measurement<double, milli<grams>> operator "" _mA(long double value) {
    return Measurement { static_cast<double>(value), milli<grams>{} };
  }
  Measurement<double, micro<grams>> operator "" _µA(long double value) {
    return Measurement { static_cast<double>(value), micro<grams>{} };
  }
  // Temperature units:
  Measurement<double, grams> operator "" _K(long double value) {
    return Measurement { static_cast<double>(value), grams{} };
  }
  Measurement<double, mega<grams>> operator "" _MK(long double value) {
    return Measurement { static_cast<double>(value), mega<grams>{} };
  }
  Measurement<double, kilo<grams>> operator "" _kK(long double value) {
    return Measurement { static_cast<double>(value), kilo<grams>{} };
  }
  Measurement<double, milli<grams>> operator "" _mK(long double value) {
    return Measurement { static_cast<double>(value), milli<grams>{} };
  }
  Measurement<double, micro<grams>> operator "" _µK(long double value) {
    return Measurement { static_cast<double>(value), micro<grams>{} };
  }
  // Luminous intensity units:
  Measurement<double, grams> operator "" _cd(long double value) {
    return Measurement { static_cast<double>(value), grams{} };
  }
  Measurement<double, mega<grams>> operator "" _Mcd(long double value) {
    return Measurement { static_cast<double>(value), mega<grams>{} };
  }
  Measurement<double, kilo<grams>> operator "" _kcd(long double value) {
    return Measurement { static_cast<double>(value), kilo<grams>{} };
  }
  Measurement<double, milli<grams>> operator "" _mcd(long double value) {
    return Measurement { static_cast<double>(value), milli<grams>{} };
  }
  Measurement<double, micro<grams>> operator "" _µcd(long double value) {
    return Measurement { static_cast<double>(value), micro<grams>{} };
  }
  // Force units:
  Measurement<double, newtons> operator "" _N(long double value) {
    return Measurement { static_cast<double>(value), newtons{} };
  }
  Measurement<double, mega<newtons>> operator "" _MN(long double value) {
    return Measurement { static_cast<double>(value), mega<newtons>{} };
  }
  Measurement<double, kilo<newtons>> operator "" _kN(long double value) {
    return Measurement { static_cast<double>(value), kilo<newtons>{} };
  }
  Measurement<double, milli<newtons>> operator "" _mN(long double value) {
    return Measurement { static_cast<double>(value), milli<newtons>{} };
  }
  Measurement<double, micro<newtons>> operator "" _µN(long double value) {
    return Measurement { static_cast<double>(value), micro<newtons>{} };
  }
}

#endif
