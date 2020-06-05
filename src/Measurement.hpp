#ifndef __UNITSLIB_MEASUREMENT_HPP__
#define __UNITSLIB_MEASUREMENT_HPP__

#include <iostream>
#include <type_traits>
#include <Unit.hpp>
#include <Product.hpp>
#include <Quotient.hpp>
#include <Power.hpp>

namespace Units {
  namespace __units_private__ {
    template <typename Num>
    constexpr Num power(Num value, int exponent) {
      return value == 0 ? 0 :
          exponent == 0 ? 1 :
           exponent < 0 ? power(value, exponent + 1) / value :
                          power(value, exponent - 1) * value;
    }
  }

  template <typename Num, typename Unit>
  struct Measurement {
    Measurement(Num value_in, const Unit &unit_in):
      value{value_in}, unit{unit_in} {}

    template <typename OtherUnit>
    constexpr Measurement<Num, typename Unit::Base> operator+ (
      const Measurement<Num, OtherUnit> other
    ) const {
      static_assert(std::is_same<
        typename Unit::Base,
        typename OtherUnit::Base
      >::value, "Incompatible units: added units must have the same base unit");
      return {
        unit.to_base(value) + other.unit.to_base(other.value),
        typename Unit::Base{}
      };
    }

    template <typename OtherUnit>
    constexpr Measurement<Num, typename Unit::Base> operator- (
      const Measurement<Num, OtherUnit> other
    ) const {
      static_assert(
        std::is_same<typename Unit::Base, typename OtherUnit::Base>::value,
        "Incompatible units: subtracted units must have the same base unit"
      );
      return {
        unit.to_base(value) - other.unit.to_base(other.value),
        typename Unit::Base{}
      };
    }
    template <typename OtherUnit>
    constexpr Measurement<
      Num,
      Product<typename Unit::Base, typename OtherUnit::Base>
    > operator* (const Measurement<Num, OtherUnit> other) const {
      return {
        unit.to_base(value) * other.unit.to_base(other.value),
        Product<typename Unit::Base, typename OtherUnit::Base>{}
      };
    }
    template <typename OtherUnit>
    constexpr Measurement<
      Num,
      Quotient<typename Unit::Base, typename OtherUnit::Base>
    > operator/ (const Measurement<Num, OtherUnit> other) const {
      return {
        unit.to_base(value) / other.unit.to_base(other.value),
        Quotient<typename Unit::Base, typename OtherUnit::Base>{}
      };
    }
    template <int exponent>
    constexpr Measurement<Num, Power<Unit, exponent>> pow() const {
      return {
        __units_private__::power(value, exponent),
        Power<Unit, exponent>{}
      };
    }


    const Num value;
    const Unit &unit;
  };

  template <typename Num, typename Unit>
  std::ostream &operator<<(
    std::ostream &out,
    const Measurement<Num, Unit> &measurement
  ) {
    return out << measurement.value << measurement.unit.abbreviation();
  }
}

#endif
