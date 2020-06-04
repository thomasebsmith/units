#ifndef __UNITSLIB_DERIVED_UNITS_HPP__
#define __UNITSLIB_DERIVED_UNITS_HPP__

#include <Unit.hpp>
#include <Product.hpp>
#include <Power.hpp>

namespace Units {
  using newtons = Product<
    kilo<grams>,
    Product<meters,
      Power<seconds, -2>
    >
  >;

  using pascals = Product<
    kilo<grams>,
    Product<
      Power<meters, -1>,
      Power<seconds, -2>
    >
  >::Base;
}

#endif
