#ifndef __UNITSLIB_PRODUCT_HPP__
#define __UNITSLIB_PRODUCT_HPP__

#include <algorithm>
#include <type_traits>

namespace Units {
  // Forward declarations to prevent infinite #include recursion.
  template <typename Unit> class Inverse;
  class Unitless;

  template <typename Unit1, typename Unit2> class Product;

  namespace __units_private__ {
    template <typename Unit> struct minID;
    template <typename Unit> struct maxID;
    // Note: merge should only be used on Bases.
    template <typename Unit1, typename Unit2> struct merge;
    // Note: simplify should only be used on merged types.
    template <typename Unit> struct simplify;

    // Constexpr-compliant abs implementation.
    constexpr int abs(const int value) {
      return value < 0 ? -value : value;
    }

    constexpr bool sorted(const int leftID, const int rightID) {
      if (abs(leftID) > abs(rightID)) {
        return false;
      }
      if (leftID != -rightID) {
        return true;
      }
      return leftID > rightID; // Inverses come second
    }

    template <typename Unit1, typename Unit2>
    struct minID<Product<Unit1, Unit2>> {
      static constexpr int value = std::min(
        minID<Unit1>::value,
        minID<Unit2>::value
      );
    };
    template <typename Unit>
    struct minID {
      static constexpr int value = Unit::_id;
    };

    template <typename Unit1, typename Unit2>
    struct maxID<Product<Unit1, Unit2>> {
      static constexpr int value = std::max(
        maxID<Unit1>::value,
        maxID<Unit2>::value
      );
    };
    template <typename Unit>
    struct maxID {
      static constexpr int value = Unit::_id;
    };

    // Worst case: both units are products.
    template <typename Unit1, typename Unit2, typename Unit3, typename Unit4>
    struct merge<Product<Unit1, Unit2>, Product<Unit3, Unit4>> {
      using type = std::conditional_t<
        sorted(maxID<Unit2>::value, minID<Unit4>::value),
        Product<typename merge<Product<Unit1, Unit2>, Unit3>::type, Unit4>,
        Product<typename merge<Unit1, Product<Unit3, Unit4>>::type, Unit2>
      >;
    };

    // Case: left unit is a defined unit; right unit is a product.
    template <typename Unit1, typename Unit2, typename Unit3>
    struct merge<Unit1, Product<Unit2, Unit3>> {
      using type = std::conditional_t<
        sorted(maxID<Unit1>::value, minID<Unit3>::value),
        Product<typename merge<Unit1, Unit2>::type, Unit3>,
        Product<typename merge<Unit1, Unit3>::type, Unit2>
      >;
    };

    // Case: left unit is a product; right unit is a defined unit.
    template <typename Unit1, typename Unit2, typename Unit3>
    struct merge<Product<Unit1, Unit2>, Unit3> {
      using type = std::conditional_t<
        sorted(maxID<Unit2>::value, minID<Unit3>::value),
        Product<Product<Unit1, Unit2>, Unit3>,
        Product<typename merge<Unit1, Unit3>::type, Unit2>
      >;
    };

    // Base case: units to merge are both defined units.
    template <typename Unit1, typename Unit2>
    struct merge {
      using type = std::conditional_t<
        sorted(maxID<Unit1>::value, minID<Unit2>::value),
        Product<Unit1, Unit2>,
        Product<Unit2, Unit1>
      >;
    };

    template <typename Unit1, typename Unit2>
    struct simplify<Product<Product<Unit1, Unit2>, Inverse<Unit2>>> {
      using type = typename simplify<Unit1>::type;
    };

    template <typename Unit1, typename Unit2>
    struct simplify<Product<Unit1, Unit2>> {
      using type = Product<typename simplify<Unit1>::type, Unit2>;
    };

    template <typename Unit>
    struct simplify<Product<Unit, Inverse<Unit>>> {
      using type = Unitless;
    };

    template <typename Unit>
    struct simplify<Product<Unitless, Unit>> {
      using type = Unit;
    };

    template <typename Unit>
    struct simplify {
      using type = Unit;
    };
  }

  template <typename Unit1, typename Unit2>
  class Product {
  public:
    using Base = typename __units_private__::simplify<
      typename __units_private__::merge<
        typename Unit1::Base,
        typename Unit2::Base
      >::type
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
