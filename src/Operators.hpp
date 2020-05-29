#ifndef __UNITSLIB_OPERATORS_HPP__
#define __UNITSLIB_OPERATORS_HPP__

#include <Unit.hpp>
#include <Measurement.hpp>

namespace Units {
  Measurement<double, meters> operator "" _m(long double value) {
    return Measurement { static_cast<double>(value), meters{} };
  }
}

#endif
