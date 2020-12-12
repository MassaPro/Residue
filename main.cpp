#include <iostream>
#include <vector>
#include "residue.h"

using namespace std;

int32_t main() {
  //Residue<1>::getPrimitiveRoot();
  Residue<2>::getPrimitiveRoot();
  Residue<3>::getPrimitiveRoot();
  Residue<4>::getPrimitiveRoot();
  Residue<5>::getPrimitiveRoot();
  //cout << is_single_degree<49, prime_divisor<91, sqrt_calculator_v<91>>::value>::value;
}