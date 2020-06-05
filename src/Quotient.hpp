#ifndef __UNITSLIB_QUOTIENT_HPP__
#define __UNITSLIB_QUOTIENT_HPP__

#include <Product.hpp>

namespace Units {
  template <typename Unit> class Inverse;

  namespace __units_private__ {
    template <typename Num, typename Unit>
    constexpr Num inverse_to_base(const Num value) {
      return value == 0 ? 0 : value / (Unit::to_base(value) / value);
    }
  }

  template <typename Unit1, typename Unit2>
  class Inverse<Product<Unit1, Unit2>> {
  public:
    using Base = typename Product<Inverse<Unit1>, Inverse<Unit2>>::Base;

    template <typename Num>
    static constexpr Num to_base(const Num value) {
      return __units_private__::inverse_to_base<
        Num,
        Product<Unit1, Unit2>
      >(value);
    }
    static std::string abbreviation() {
      return "(" + Product<Unit1, Unit2>::abbreviation() + ")⁻¹";
    }
  };

  template <typename Unit>
  class Inverse<Inverse<Unit>> {
  public:
    using Base = typename Unit::Base;

    template <typename Num>
    static constexpr Num to_base(const Num value) {
      return __units_private__::inverse_to_base<Num, Unit>(value);
    }
    static std::string abbreviation() {
      return Unit::abbreviation();
    }
    static constexpr int _id = -Unit::_id;
  };

  template <typename Unit>
  class Inverse {
  public:
    using Base = Inverse<typename Unit::Base>;

    template <typename Num>
    static constexpr Num to_base(Num value) {
      return Unit::to_base(value);
    }
    static std::string abbreviation() {
      return Unit::abbreviation() + "⁻¹";
    }
    static constexpr int _id = -Unit::_id;
  };

  template <typename Unit1, typename Unit2>
  using Quotient = Product<Unit1, Inverse<Unit2>>;
};

#endif
