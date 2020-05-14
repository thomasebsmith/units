#ifndef __UNITSLIB_MEASUREMENT_HPP__
#define __UNITSLIB_MEASUREMENT_HPP__

#include <iostream>
#include <type_traits>
#include <Unit.hpp>
#include <Product.hpp>
#include <Quotient.hpp>

namespace Units {
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
    > operator* (const Measurement<Num, OtherUnit> other) {
      return {
        unit.to_base(value) * other.unit.to_base(other.value),
        Product<typename Unit::Base, typename OtherUnit::Base>{}
      };
    }
    template <typename OtherUnit>
    constexpr Measurement<
      Num,
      Quotient<typename Unit::Base, typename OtherUnit::Base>
    > operator/ (const Measurement<Num, OtherUnit> other) {
      return {
        unit.to_base(value) / other.unit.to_base(other.value),
        Quotient<typename Unit::Base, typename OtherUnit::Base>{}
      };
    }


    Num value;
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
