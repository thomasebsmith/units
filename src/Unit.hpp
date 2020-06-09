#ifndef __UNITSLIB_UNIT_HPP__
#define __UNITSLIB_UNIT_HPP__

#include <string>
#include <type_traits>

namespace Units {
  // Forward declaration of kilo<Unit> for grams (base unit is kilo<grams>):
  template <typename Unit>
  class kilo;

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
  class grams {
  public:
    using Base = kilo<grams>;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return value / 1e3;
    }
    static std::string abbreviation() {
      return "g";
    }
    static constexpr int _id = 3;
  };
  class amperes {
  public:
    using Base = amperes;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return value;
    }
    static std::string abbreviation() {
      return "A";
    }
    static constexpr int _id = 4;
  };
  class kelvins {
  public:
    using Base = kelvins;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return value;
    }
    static std::string abbreviation() {
      return "K";
    }
    static constexpr int _id = 5;
  };
  class candelas {
  public: 
    using Base = candelas;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return value;
    }
    static std::string abbreviation() {
      return "cd";
    }
    static constexpr int _id = 6;
  };

  template <typename Unit>
  class kilo {
  public:
    using Base = typename Unit::Base;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return Unit::to_base(value) * 1e3;
    }
    static std::string abbreviation() {
      return "k" + Unit::abbreviation();
    }
    static constexpr int _id = Unit::_id;
  };
  template <typename Unit>
  class mega {
  public:
    using Base = typename Unit::Base;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return Unit::to_base(value) * 1e6;
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
      return Unit::to_base(value) / 1e3;
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
      return Unit::to_base(value) / 1e6;
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
