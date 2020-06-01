#include "utils.hpp"
#include <units.hpp>

using namespace Units;

int main() {
  Measurement length1 { 5.0, meters{} };
  Measurement length2 { 0.8, kilo<meters>{} };
  test(close(length1 + length2, Measurement { 805.0, meters{} }));
  test(close(length1 - length2, Measurement {
    -0.795,
    kilo<meters>{}
  }));
  Measurement time1 { 0.33, milli<seconds>{} };
  Measurement time2 { 50.0, micro<seconds>{} };
  test(close(time1 + time2, Measurement { 0.38, milli<seconds>{} }));
  test(close(length2 * time1, Measurement {
    0.264,
    Product<meters, seconds>{}
  }));
  test(close(length2 * time1, time1 * length2));
  test(close(length1 / time1, Measurement {
    5.0 / 0.00033,
    Quotient<meters, seconds>{}
  }));
  test(close(length1, 5.0_m));

  test(close(5003.0_m, 5.003_km));

  auto length3 = 0.003801723293455219_km;
  test(close(0.0303_ks * 90.0_mm, (length3 * length3) * 1000.0_ms / 5.3_m));

  test(close(503.0_µm * 2.0_Ms, 251.5_µs * 4.0_Mm));

  test(close(3.5389_kg, 3538.9_g));

  test(close(1.0_N, 1.0_m * 1000.0_g / 1.0_s / 1.0_s));
  test(!close(1.0_N, 1.1_m * 0.9_kg / 1.0_s / 1.0_s));

  test(close(0.053_MA, 53.0_kA));
  test(close(273.15_K, 273150.0_mK));
  test(close(8080.8_µcd, 8.0808_mcd));
  return 0;
}
