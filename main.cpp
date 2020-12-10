#include <iostream>
#include <vector>
#include "residue.h"

using namespace std;

int32_t main() {
  ///cout << number_of_prime_divisors<91>::value;
 cout << has_primitive_root_v<286>;
  cout << has_primitive_root<686>::value;
  cout << has_primitive_root<11>::value;
  cout << has_primitive_root<22>::value;
  cout << has_primitive_root<44>::value;
  cout << has_primitive_root<4>::value;

  //cout << is_prime<239>::value;
  return 0;
}