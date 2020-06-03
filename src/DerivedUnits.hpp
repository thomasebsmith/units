#ifndef __UNITSLIB_DERIVED_UNITS_HPP__
#define __UNITSLIB_DERIVED_UNITS_HPP__

#include <Unit.hpp>
#include <Product.hpp>
#include <Quotient.hpp>

namespace Units {
  using newtons = typename Product<
    kilo<grams>,
    Quotient<
      Quotient<meters, seconds>,
      seconds
    >
  >::Base;

  using pascals = typename Quotient<
    kilo<grams>,
    Product<
      Product<meters, seconds>,
      seconds
    >
  >::Base;
}

#endif
