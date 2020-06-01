#ifndef __UNITSLIB_DERIVED_UNITS_HPP__
#define __UNITSLIB_DERIVED_UNITS_HPP__

#include <Unit.hpp>
#include <Product.hpp>
#include <Quotient.hpp>

namespace Units {
  using Newtons = typename Product<
    kilo<grams>,
    Quotient<
      Quotient<meters, seconds>,
      seconds
    >
  >::Base;
}

#endif
