#ifndef __UNITSLIB_DERIVED_UNITS_HPP__
#define __UNITSLIB_DERIVED_UNITS_HPP__

#include <Unit.hpp>
#include <Product.hpp>
#include <Power.hpp>

namespace Units {
  using newtons = typename Product<
    kilo<grams>,
    Product<meters,
      Power<seconds, -2>
    >
  >::Base;

  using pascals = typename Product<
    kilo<grams>,
    Product<
      Power<meters, -1>,
      Power<seconds, -2>
    >
  >::Base;

  using joules = typename Product<meters, newtons>::Base;

  using watts = typename Quotient<joules, seconds>::Base;

  using coulombs = typename Product<seconds, amperes>::Base;

  using volts = typename Quotient<watts, amperes>::Base;

  using farads = typename Quotient<coulombs, volts>::Base;

  using ohms = typename Quotient<volts, amperes>::Base;

  using siemens = typename Inverse<ohms>::Base;

  using webers = typename Quotient<joules, amperes>::Base;

  using teslas = typename Quotient<webers, Power<meters, 2>>::Base;

  using henries = typename Product<ohms, seconds>::Base;

  using lux = typename Quotient<candelas, Power<meters, 2>>::Base;
}

#endif
