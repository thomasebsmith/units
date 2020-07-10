#ifndef __UNITSLIB_PRODUCT_HPP__
#define __UNITSLIB_PRODUCT_HPP__

#include <algorithm>
#include <type_traits>

namespace Units {
  // Forward declarations to prevent infinite #include recursion.
  template <typename Unit> class Inverse;
  class Unitless;

  template <typename Unit1, typename Unit2> class Product;

  // Semi-private namespace that contains utilities used for compile-time
  // multiplication.
  namespace __units_private__ {
    template <typename Unit> struct minID;
    template <typename Unit> struct maxID;
    // Note: merge should only be used on Bases.
    template <typename Unit1, typename Unit2> struct merge;
    template <typename Unit> struct is_simple;
    // Note: simplify should only be used on merged types.
    template <typename Unit> struct simplify;

    template <bool condition, typename T, typename U>
    using eval_if = typename std::conditional_t<condition, T, U>::type;

    // Constexpr-compliant abs implementation.
    constexpr int abs(const int value) {
      return value < 0 ? -value : value;
    }

    // Determines whether leftID could come before rightID in a sorted list of
    // units.
    constexpr bool sorted(const int leftID, const int rightID) {
      if (abs(leftID) > abs(rightID)) {
        return false;
      }
      if (leftID != -rightID) {
        return true;
      }
      return leftID > rightID; // Inverses come second
    }

    // Determines the lesser of the two unit IDs.
    constexpr int absMin(const int left, const int right) {
      return sorted(left, right) ? left : right;
    }

    // Determines the greater of the two unit IDs.
    constexpr int absMax(const int left, const int right) {
      return sorted(left, right) ? right : left;
    }

    // Determines the minimum ID within a product of units.
    template <typename Unit1, typename Unit2>
    struct minID<Product<Unit1, Unit2>> {
      static constexpr int value = absMin(
        minID<Unit1>::value,
        minID<Unit2>::value
      );
    };
    template <typename Unit>
    struct minID {
      static constexpr int value = Unit::_id;
    };

    // Determines the maximum ID within a product of units.
    template <typename Unit1, typename Unit2>
    struct maxID<Product<Unit1, Unit2>> {
      static constexpr int value = absMax(
        maxID<Unit1>::value,
        maxID<Unit2>::value
      );
    };
    template <typename Unit>
    struct maxID {
      static constexpr int value = Unit::_id;
    };

    // Determines whether a product is fully simplified.
    template <typename Unit1, typename Unit2>
    struct is_simple<Product<Product<Unit1, Unit2>, Inverse<Unit2>>> {
      static constexpr bool value = false;
    };

    template <typename Unit>
    struct is_simple<Product<Unit, Inverse<Unit>>> {
      static constexpr bool value = false;
    };

    template <typename Unit>
    struct is_simple<Product<Unitless, Unit>> {
      static constexpr bool value = false;
    };

    template <typename Unit>
    struct is_simple {
      static constexpr bool value = true;
    };


    // Creates a sorted product of units based on two existing products.
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
        Product<Product<Unit2, Unit3>, Unit1>
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

    // Removes unnecessary inverses from a list of products.
    template <typename Unit1, typename Unit2>
    struct simplify<Product<Product<Unit1, Unit2>, Inverse<Unit2>>> {
      using type = typename simplify<Unit1>::type;
    };

    template <typename Unit>
    struct simplify<Product<Unit, Inverse<Unit>>> {
      using type = Unitless;
    };

    template <typename Unit>
    struct simplify<Product<Unitless, Unit>> {
      using type = Unit;
    };

    // Used to allow the compiler to not blow up with too much template
    // recursion.
    template <typename Unit1, typename Unit2>
    struct delayed_product {
      using type = Product<Unit1, Unit2>;
    };

    template <typename Unit1, typename Unit2>
    struct simplify<Product<Unit1, Unit2>> {
      using _type = typename simplify<Unit1>::type;
      using type = eval_if<
        is_simple<Product<_type, Unit2>>::value,
        delayed_product<_type, Unit2>,
        simplify<Product<_type, Unit2>>
      >;
    };

    template <typename Unit>
    struct simplify {
      using type = Unit;
    };
  }

  // Recursively calculate the base unit by determining the ordered sequences
  // of products for Unit1 and Unit2 and then combining them.
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
