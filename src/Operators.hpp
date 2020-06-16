#ifndef __UNITSLIB_OPERATORS_HPP__
#define __UNITSLIB_OPERATORS_HPP__

#include <Unit.hpp>
#include <Measurement.hpp>
#include <DerivedUnits.hpp>

namespace Units {
  // Distance units:
  Measurement<double, meters> operator "" _m(long double value) {
    return Measurement { static_cast<double>(value), meters{} };
  }
  Measurement<double, mega<meters>> operator "" _Mm(long double value) {
    return Measurement { static_cast<double>(value), mega<meters>{} };
  }
  Measurement<double, kilo<meters>> operator "" _km(long double value) {
    return Measurement { static_cast<double>(value), kilo<meters>{} };
  }
  Measurement<double, milli<meters>> operator "" _mm(long double value) {
    return Measurement { static_cast<double>(value), milli<meters>{} };
  }
  Measurement<double, micro<meters>> operator "" _µm(long double value) {
    return Measurement { static_cast<double>(value), micro<meters>{} };
  }
  // Time units:
  Measurement<double, seconds> operator "" _s(long double value) {
    return Measurement { static_cast<double>(value), seconds{} };
  }
  Measurement<double, mega<seconds>> operator "" _Ms(long double value) {
    return Measurement { static_cast<double>(value), mega<seconds>{} };
  }
  Measurement<double, kilo<seconds>> operator "" _ks(long double value) {
    return Measurement { static_cast<double>(value), kilo<seconds>{} };
  }
  Measurement<double, milli<seconds>> operator "" _ms(long double value) {
    return Measurement { static_cast<double>(value), milli<seconds>{} };
  }
  Measurement<double, micro<seconds>> operator "" _µs(long double value) {
    return Measurement { static_cast<double>(value), micro<seconds>{} };
  }
  // Mass units:
  Measurement<double, grams> operator "" _g(long double value) {
    return Measurement { static_cast<double>(value), grams{} };
  }
  Measurement<double, mega<grams>> operator "" _Mg(long double value) {
    return Measurement { static_cast<double>(value), mega<grams>{} };
  }
  Measurement<double, kilo<grams>> operator "" _kg(long double value) {
    return Measurement { static_cast<double>(value), kilo<grams>{} };
  }
  Measurement<double, milli<grams>> operator "" _mg(long double value) {
    return Measurement { static_cast<double>(value), milli<grams>{} };
  }
  Measurement<double, micro<grams>> operator "" _µg(long double value) {
    return Measurement { static_cast<double>(value), micro<grams>{} };
  }
  // Electric current units:
  Measurement<double, amperes> operator "" _A(long double value) {
    return Measurement { static_cast<double>(value), amperes{} };
  }
  Measurement<double, mega<amperes>> operator "" _MA(long double value) {
    return Measurement { static_cast<double>(value), mega<amperes>{} };
  }
  Measurement<double, kilo<amperes>> operator "" _kA(long double value) {
    return Measurement { static_cast<double>(value), kilo<amperes>{} };
  }
  Measurement<double, milli<amperes>> operator "" _mA(long double value) {
    return Measurement { static_cast<double>(value), milli<amperes>{} };
  }
  Measurement<double, micro<amperes>> operator "" _µA(long double value) {
    return Measurement { static_cast<double>(value), micro<amperes>{} };
  }
  // Temperature units:
  Measurement<double, kelvins> operator "" _K(long double value) {
    return Measurement { static_cast<double>(value), kelvins{} };
  }
  Measurement<double, mega<kelvins>> operator "" _MK(long double value) {
    return Measurement { static_cast<double>(value), mega<kelvins>{} };
  }
  Measurement<double, kilo<kelvins>> operator "" _kK(long double value) {
    return Measurement { static_cast<double>(value), kilo<kelvins>{} };
  }
  Measurement<double, milli<kelvins>> operator "" _mK(long double value) {
    return Measurement { static_cast<double>(value), milli<kelvins>{} };
  }
  Measurement<double, micro<kelvins>> operator "" _µK(long double value) {
    return Measurement { static_cast<double>(value), micro<kelvins>{} };
  }
  // Luminous intensity units:
  Measurement<double, candelas> operator "" _cd(long double value) {
    return Measurement { static_cast<double>(value), candelas{} };
  }
  Measurement<double, mega<candelas>> operator "" _Mcd(long double value) {
    return Measurement { static_cast<double>(value), mega<candelas>{} };
  }
  Measurement<double, kilo<candelas>> operator "" _kcd(long double value) {
    return Measurement { static_cast<double>(value), kilo<candelas>{} };
  }
  Measurement<double, milli<candelas>> operator "" _mcd(long double value) {
    return Measurement { static_cast<double>(value), milli<candelas>{} };
  }
  Measurement<double, micro<candelas>> operator "" _µcd(long double value) {
    return Measurement { static_cast<double>(value), micro<candelas>{} };
  }
  // Force units:
  Measurement<double, newtons> operator "" _N(long double value) {
    return Measurement { static_cast<double>(value), newtons{} };
  }
  Measurement<double, mega<newtons>> operator "" _MN(long double value) {
    return Measurement { static_cast<double>(value), mega<newtons>{} };
  }
  Measurement<double, kilo<newtons>> operator "" _kN(long double value) {
    return Measurement { static_cast<double>(value), kilo<newtons>{} };
  }
  Measurement<double, milli<newtons>> operator "" _mN(long double value) {
    return Measurement { static_cast<double>(value), milli<newtons>{} };
  }
  Measurement<double, micro<newtons>> operator "" _µN(long double value) {
    return Measurement { static_cast<double>(value), micro<newtons>{} };
  }
  // Pressure units:
  Measurement<double, pascals> operator "" _Pa(long double value) {
    return Measurement { static_cast<double>(value), pascals{} };
  }
  Measurement<double, mega<pascals>> operator "" _MPa(long double value) {
    return Measurement { static_cast<double>(value), mega<pascals>{} };
  }
  Measurement<double, kilo<pascals>> operator "" _kPa(long double value) {
    return Measurement { static_cast<double>(value), kilo<pascals>{} };
  }
  Measurement<double, milli<pascals>> operator "" _mPa(long double value) {
    return Measurement { static_cast<double>(value), milli<pascals>{} };
  }
  Measurement<double, micro<pascals>> operator "" _µPa(long double value) {
    return Measurement { static_cast<double>(value), micro<pascals>{} };
  }
  // Energy units:
  Measurement<double, joules> operator "" _J(long double value) {
    return Measurement { static_cast<double>(value), joules{} };
  }
  Measurement<double, mega<joules>> operator "" _MJ(long double value) {
    return Measurement { static_cast<double>(value), mega<joules>{} };
  }
  Measurement<double, kilo<joules>> operator "" _kJ(long double value) {
    return Measurement { static_cast<double>(value), kilo<joules>{} };
  }
  Measurement<double, milli<joules>> operator "" _mJ(long double value) {
    return Measurement { static_cast<double>(value), milli<joules>{} };
  }
  Measurement<double, micro<joules>> operator "" _µJ(long double value) {
    return Measurement { static_cast<double>(value), micro<joules>{} };
  }
  // Power units:
  Measurement<double, watts> operator "" _W(long double value) {
    return Measurement { static_cast<double>(value), watts{} };
  }
  Measurement<double, mega<watts>> operator "" _MW(long double value) {
    return Measurement { static_cast<double>(value), mega<watts>{} };
  }
  Measurement<double, kilo<watts>> operator "" _kW(long double value) {
    return Measurement { static_cast<double>(value), kilo<watts>{} };
  }
  Measurement<double, milli<watts>> operator "" _mW(long double value) {
    return Measurement { static_cast<double>(value), milli<watts>{} };
  }
  Measurement<double, micro<watts>> operator "" _µW(long double value) {
    return Measurement { static_cast<double>(value), micro<watts>{} };
  }
  // Electric charge units:
  Measurement<double, coulombs> operator "" _C(long double value) {
    return Measurement { static_cast<double>(value), coulombs{} };
  }
  Measurement<double, mega<coulombs>> operator "" _MC(long double value) {
    return Measurement { static_cast<double>(value), mega<coulombs>{} };
  }
  Measurement<double, kilo<coulombs>> operator "" _kC(long double value) {
    return Measurement { static_cast<double>(value), kilo<coulombs>{} };
  }
  Measurement<double, milli<coulombs>> operator "" _mC(long double value) {
    return Measurement { static_cast<double>(value), milli<coulombs>{} };
  }
  Measurement<double, micro<coulombs>> operator "" _µC(long double value) {
    return Measurement { static_cast<double>(value), micro<coulombs>{} };
  }
  // Voltage units:
  Measurement<double, volts> operator "" _V(long double value) {
    return Measurement { static_cast<double>(value), volts{} };
  }
  Measurement<double, mega<volts>> operator "" _MV(long double value) {
    return Measurement { static_cast<double>(value), mega<volts>{} };
  }
  Measurement<double, kilo<volts>> operator "" _kV(long double value) {
    return Measurement { static_cast<double>(value), kilo<volts>{} };
  }
  Measurement<double, milli<volts>> operator "" _mV(long double value) {
    return Measurement { static_cast<double>(value), milli<volts>{} };
  }
  Measurement<double, micro<volts>> operator "" _µV(long double value) {
    return Measurement { static_cast<double>(value), micro<volts>{} };
  }
  // Electrical capacitance units:
  Measurement<double, farads> operator "" _F(long double value) {
    return Measurement { static_cast<double>(value), farads{} };
  }
  Measurement<double, mega<farads>> operator "" _MF(long double value) {
    return Measurement { static_cast<double>(value), mega<farads>{} };
  }
  Measurement<double, kilo<farads>> operator "" _kF(long double value) {
    return Measurement { static_cast<double>(value), kilo<farads>{} };
  }
  Measurement<double, milli<farads>> operator "" _mF(long double value) {
    return Measurement { static_cast<double>(value), milli<farads>{} };
  }
  Measurement<double, micro<farads>> operator "" _µF(long double value) {
    return Measurement { static_cast<double>(value), micro<farads>{} };
  }
  // Electrical resistance units:
  Measurement<double, ohms> operator "" _Ω(long double value) {
    return Measurement { static_cast<double>(value), ohms{} };
  }
  Measurement<double, mega<ohms>> operator "" _MΩ(long double value) {
    return Measurement { static_cast<double>(value), mega<ohms>{} };
  }
  Measurement<double, kilo<ohms>> operator "" _kΩ(long double value) {
    return Measurement { static_cast<double>(value), kilo<ohms>{} };
  }
  Measurement<double, milli<ohms>> operator "" _mΩ(long double value) {
    return Measurement { static_cast<double>(value), milli<ohms>{} };
  }
  Measurement<double, micro<ohms>> operator "" _µΩ(long double value) {
    return Measurement { static_cast<double>(value), micro<ohms>{} };
  }
  // Electrical conductance units:
  Measurement<double, siemens> operator "" _S(long double value) {
    return Measurement { static_cast<double>(value), siemens{} };
  }
  Measurement<double, mega<siemens>> operator "" _MS(long double value) {
    return Measurement { static_cast<double>(value), mega<siemens>{} };
  }
  Measurement<double, kilo<siemens>> operator "" _kS(long double value) {
    return Measurement { static_cast<double>(value), kilo<siemens>{} };
  }
  Measurement<double, milli<siemens>> operator "" _mS(long double value) {
    return Measurement { static_cast<double>(value), milli<siemens>{} };
  }
  Measurement<double, micro<siemens>> operator "" _µS(long double value) {
    return Measurement { static_cast<double>(value), micro<siemens>{} };
  }
  // Magnetic flux units:
  Measurement<double, webers> operator "" _Wb(long double value) {
    return Measurement { static_cast<double>(value), webers{} };
  }
  Measurement<double, mega<webers>> operator "" _MWb(long double value) {
    return Measurement { static_cast<double>(value), mega<webers>{} };
  }
  Measurement<double, kilo<webers>> operator "" _kWb(long double value) {
    return Measurement { static_cast<double>(value), kilo<webers>{} };
  }
  Measurement<double, milli<webers>> operator "" _mWb(long double value) {
    return Measurement { static_cast<double>(value), milli<webers>{} };
  }
  Measurement<double, micro<webers>> operator "" _µWb(long double value) {
    return Measurement { static_cast<double>(value), micro<webers>{} };
  }
  // Magnetic induction units:
  Measurement<double, teslas> operator "" _T(long double value) {
    return Measurement { static_cast<double>(value), teslas{} };
  }
  Measurement<double, mega<teslas>> operator "" _MT(long double value) {
    return Measurement { static_cast<double>(value), mega<teslas>{} };
  }
  Measurement<double, kilo<teslas>> operator "" _kT(long double value) {
    return Measurement { static_cast<double>(value), kilo<teslas>{} };
  }
  Measurement<double, milli<teslas>> operator "" _mT(long double value) {
    return Measurement { static_cast<double>(value), milli<teslas>{} };
  }
  Measurement<double, micro<teslas>> operator "" _µT(long double value) {
    return Measurement { static_cast<double>(value), micro<teslas>{} };
  }
  // Electrical inductance units:
  Measurement<double, henries> operator "" _H(long double value) {
    return Measurement { static_cast<double>(value), henries{} };
  }
  Measurement<double, mega<henries>> operator "" _MH(long double value) {
    return Measurement { static_cast<double>(value), mega<henries>{} };
  }
  Measurement<double, kilo<henries>> operator "" _kH(long double value) {
    return Measurement { static_cast<double>(value), kilo<henries>{} };
  }
  Measurement<double, milli<henries>> operator "" _mH(long double value) {
    return Measurement { static_cast<double>(value), milli<henries>{} };
  }
  Measurement<double, micro<henries>> operator "" _µH(long double value) {
    return Measurement { static_cast<double>(value), micro<henries>{} };
  }
  // Illuminance units:
  Measurement<double, lux> operator "" _lx(long double value) {
    return Measurement { static_cast<double>(value), lux{} };
  }
  Measurement<double, mega<lux>> operator "" _Mlx(long double value) {
    return Measurement { static_cast<double>(value), mega<lux>{} };
  }
  Measurement<double, kilo<lux>> operator "" _klx(long double value) {
    return Measurement { static_cast<double>(value), kilo<lux>{} };
  }
  Measurement<double, milli<lux>> operator "" _mlx(long double value) {
    return Measurement { static_cast<double>(value), milli<lux>{} };
  }
  Measurement<double, micro<lux>> operator "" _µlx(long double value) {
    return Measurement { static_cast<double>(value), micro<lux>{} };
  }
}

#endif
