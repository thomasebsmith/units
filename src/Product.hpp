#ifndef __UNITSLIB_PRODUCT_HPP__
#define __UNITSLIB_PRODUCT_HPP__

#include <algorithm>
#include <type_traits>

namespace Units {
  // Forward declarations to prevent infinite #include recursion.
  template <typename Unit> class Inverse;
  class Unitless;

  template <typename Unit1, typename Unit2> class Product;
  template <typename Unit> struct _minID;
  template <typename Unit> struct _maxID;
  // Note: _merge should only be used on Bases.
  template <typename Unit1, typename Unit2> struct _merge;
  // Note: _simplify should only be used on _merged types.
  template <typename Unit> struct _simplify;

  // Constexpr-compliant abs implementation.
  constexpr int _abs(const int value) {
    return value < 0 ? -value : value;
  }

  constexpr bool _sorted(const int leftID, const int rightID) {
    if (_abs(leftID) > _abs(rightID)) {
      return false;
    }
    if (leftID != -rightID) {
      return true;
    }
    return leftID > rightID; // Inverses come second
  }

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
      _sorted(_maxID<Unit2>::value, _minID<Unit4>::value),
      Product<typename _merge<Product<Unit1, Unit2>, Unit3>::type, Unit4>,
      Product<typename _merge<Unit1, Product<Unit3, Unit4>>::type, Unit2>
    >;
  };

  // Case: left unit is a defined unit; right unit is a product.
  template <typename Unit1, typename Unit2, typename Unit3>
  struct _merge<Unit1, Product<Unit2, Unit3>> {
    using type = std::conditional_t<
      _sorted(_maxID<Unit1>::value, _minID<Unit2>::value),
      Product<Unit1, Product<Unit2, Unit3>>,
      Product<typename _merge<Unit1, Unit3>::type, Unit2>
    >;
  };

  // Case: left unit is a product; right unit is a defined unit.
  template <typename Unit1, typename Unit2, typename Unit3>
  struct _merge<Product<Unit1, Unit2>, Unit3> {
    using type = std::conditional_t<
      _sorted(_maxID<Unit2>::value, _minID<Unit3>::value),
      Product<Product<Unit1, Unit2>, Unit3>,
      Product<typename _merge<Unit1, Unit3>::type, Unit2>
    >;
  };

  // Base case: units to merge are both defined units.
  template <typename Unit1, typename Unit2>
  struct _merge {
    using type = std::conditional_t<
      _sorted(_maxID<Unit1>::value, _minID<Unit2>::value),
      Product<Unit1, Unit2>,
      Product<Unit2, Unit1>
    >;
  };

  template <typename Unit1, typename Unit2>
  struct _simplify<Product<Product<Unit1, Unit2>, Inverse<Unit2>>> {
    using type = typename _simplify<Unit1>::type;
  };

  template <typename Unit1, typename Unit2>
  struct _simplify<Product<Unit1, Unit2>> {
    using type = Product<typename _simplify<Unit1>::type, Unit2>;
  };

  template <typename Unit>
  struct _simplify<Product<Unit, Inverse<Unit>>> {
    using type = Unitless;
  };

  template <typename Unit>
  struct _simplify<Product<Unitless, Unit>> {
    using type = Unit;
  };

  template <typename Unit>
  struct _simplify {
    using type = Unit;
  };

  template <typename Unit1, typename Unit2>
  class Product {
  public:
    using Base = typename _simplify<typename _merge<
      typename Unit1::Base,
      typename Unit2::Base
    >::type>::type;
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
