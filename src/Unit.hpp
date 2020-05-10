#ifndef __UNITSLIB_UNIT_HPP__
#define __UNITSLIB_UNIT_HPP__

#include <string>

namespace Units {
  class meters {
  public:
    using Base = meters;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return value;
    }
    static std::string abbreviation() {
      return "m";
    }
  };
  class seconds {
  public:
    using Base = seconds;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return value;
    }
    static std::string abbreviation() {
      return "s";
    }
  };
  template <typename Unit>
  class kilo {
  public:
    using Base = typename Unit::Base;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return value * 1e3;
    }
    static std::string abbreviation() {
      return "k" + Unit::abbreviation();
    }
  };
  template <typename Unit>
  class mega {
  public:
    using Base = typename Unit::Base;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return value * 1e6;
    }
    static std::string abbreviation() {
      return "M" + Unit::abbreviation();
    }
  };
  template <typename Unit>
  class milli {
  public:
    using Base = typename Unit::Base;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return value / 1e3;
    }
    static std::string abbreviation() {
      return "m" + Unit::abbreviation();
    }
  };
  template <typename Unit>
  class micro {
  public:
    using Base = typename Unit::Base;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return value / 1e6;
    }
    static std::string abbreviation() {
      return "µ" + Unit::abbreviation();
    }
  };
  template <typename Unit1, typename Unit2>
  class Product {
  public:
    // TODO: Remove divisions
    using Base = Product<typename Unit1::Base, typename Unit2::Base>;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return Unit2::to_base(Unit1::to_base(value));
    }
    static std::string abbreviation() {
      return Unit1::abbreviation() + "⋅" + Unit2::abbreviation();
    }
  };
}

#endif
