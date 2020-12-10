#include <iostream>
#include <vector>
#include "residue.h"

using namespace std;

int32_t main() {
 Residue<12> x(11);
 Residue<12> y(2);
 x += y;
 x.pow(4);

  //cout << is_prime<239>::value;
  return 0;
}