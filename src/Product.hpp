#ifndef __UNITSLIB_PRODUCT_HPP__
#define __UNITSLIB_PRODUCT_HPP__

#include <algorithm>
#include <type_traits>

namespace Units {
  template <typename Unit1, typename Unit2> class Product;
  template <typename Unit> struct _minID;
  template <typename Unit> struct _maxID;
  // Note: _merge should only be used on Bases.
  template <typename Unit1, typename Unit2> struct _merge;

  template <typename Unit1, typename Unit2>
  struct _minID<Product<Unit1, Unit2>> {
    static constexpr int value = std::min(
      _minID<Unit1>::value,
      _minID<Unit2>::value
    );
  };
  template <typename Unit>
  struct _minID {
    static constexpr int value = Unit::_id;
  };

  template <typename Unit1, typename Unit2>
  struct _maxID<Product<Unit1, Unit2>> {
    static constexpr int value = std::max(
      _maxID<Unit1>::value,
      _maxID<Unit2>::value
    );
  };
  template <typename Unit>
  struct _maxID {
    static constexpr int value = Unit::_id;
  };

  // Worst case: both units are products.
  template <typename Unit1, typename Unit2, typename Unit3, typename Unit4>
  struct _merge<Product<Unit1, Unit2>, Product<Unit3, Unit4>> {
    using type = std::conditional_t<
      _maxID<Unit2>::value <= _minID<Unit4>::value,
      Product<typename _merge<Product<Unit1, Unit2>, Unit3>::type, Unit4>,
      Product<typename _merge<Unit1, Product<Unit3, Unit4>>::type, Unit2>
    >;
  };

  // Case: left unit is a defined unit; right unit is a product.
  template <typename Unit1, typename Unit2, typename Unit3>
  struct _merge<Unit1, Product<Unit2, Unit3>> {
    using type = std::conditional_t<
      _maxID<Unit1>::value <= _minID<Unit2>::value,
      Product<Unit1, Product<Unit2, Unit3>>,
      Product<typename _merge<Unit1, Unit3>::type, Unit2>
    >;
  };

  // Case: left unit is a product; right unit is a defined unit.
  template <typename Unit1, typename Unit2, typename Unit3>
  struct _merge<Product<Unit1, Unit2>, Unit3> {
    using type = std::conditional_t<
      _maxID<Unit2>::value <= _minID<Unit3>::value,
      Product<Product<Unit1, Unit2>, Unit3>,
      Product<typename _merge<Unit1, Unit3>::type, Unit2>
    >;
  };

  // Base case: units to merge are both defined units.
  template <typename Unit1, typename Unit2>
  struct _merge {
    using type = std::conditional_t<
      _maxID<Unit1>::value <= _minID<Unit2>::value,
      Product<Unit1, Unit2>,
      Product<Unit2, Unit1>
    >;
  };

  template <typename Unit1, typename Unit2>
  class Product {
  public:
    using Base = typename _merge<
      typename Unit1::Base,
      typename Unit2::Base
    >::type;
    using Left = Unit1;
    using Right = Unit2;

    template <typename Num>
    static constexpr Num to_base(Num value) {
      return Unit2::to_base(Unit1::to_base(value));
    }
    static std::string abbreviation() {
      return Base::Left::abbreviation() + "⋅" + Base::Right::abbreviation();
    }
  };

}

#endif
