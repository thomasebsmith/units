#ifndef __UNITSLIB_UNIT_HPP__
#define __UNITSLIB_UNIT_HPP__

#include <string>
#include <type_traits>

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
    static constexpr int _id = 1;
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
    static constexpr int _id = 2;
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
    static constexpr int _id = Base::_id;
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
    static constexpr int _id = Base::_id;
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
    static constexpr int _id = Base::_id;
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
    static constexpr int _id = Base::_id;
  };

  class Unitless {
  public:
    using Base = Unitless;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return value;
    }
    static std::string abbreviation() {
      return "";
    }
    static constexpr int _id = 0;
  };
}

#endif
