#ifndef __UNITSLIB_POWER_HPP__
#define __UNITSLIB_POWER_HPP__

#include <Product.hpp>
#include <Quotient.hpp>
#include <Unit.hpp>
#include <type_traits>

namespace Units {
  template <typename Unit, int exponent>
  class Power {
  public:
    using Equivalent = std::conditional_t<
      exponent == 0,
      Unitless,
      std::conditional_t<
        !(exponent <= 0),
        std::conditional_t<
          exponent == 1,
          Unit,
          Product<Power<Unit, exponent - 1>, Unit>
        >,
        std::conditional_t<
          exponent == -1,
          Inverse<Unit>,
          Quotient<Power<Unit, exponent + 1>, Unit>
        >
      >
    >;

    using Base = typename Equivalent::Base;

    template <typename Num>
    static constexpr Num to_base(Num value) {
      return Equivalent::to_base(value);
    }

    static std::string abbreviation() {
      // TODO: Format this nicely
      return Equivalent::abbreviation();
    }
  };
}

#endif
