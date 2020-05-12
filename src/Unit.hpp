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
  template <typename Unit1, typename Unit2,
            bool sorted = Unit1::_id <= Unit2::_id
  >
  class Product;

  template <typename Unit1, typename Unit2>
  class Product<Unit1, Unit2, true> {
  public:
    // TODO: Remove divisions
    // TODO: merges
    using Base = Product<typename Unit1::Base, typename Unit2::Base>;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return Unit2::to_base(Unit1::to_base(value));
    }
    static std::string abbreviation() {
      return Unit1::abbreviation() + "⋅" + Unit2::abbreviation();
    }
    static constexpr int _id = -1; // TODO: remove
  };

  template <typename Unit1, typename Unit2>
  class Product<Unit1, Unit2, false> {
  public:
    // TODO: Remove divisions
    // TODO: merges
    using Base = Product<typename Unit2::Base, typename Unit1::Base>;
    template <typename Num>
    static constexpr Num to_base(Num value) {
      return Unit2::to_base(Unit1::to_base(value));
    }
    static std::string abbreviation() {
      return Unit1::abbreviation() + "⋅" + Unit2::abbreviation();
    }
    static constexpr int _id = -1;
  };
}

#endif
