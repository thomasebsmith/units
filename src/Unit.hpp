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
  template <typename Unit>
  class kilo {
  public:
    using Base = typename Unit::Base;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return value * 1000;
    }
    static std::string abbreviation() {
      return "k" + Unit::abbreviation();
    }
  };
}

#endif
