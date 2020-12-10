//
// Created by Nikita Mastinen on 10.12.2020.
//

#ifndef RESIDUE_RESIDUE_H
#define RESIDUE_RESIDUE_H

#endif //RESIDUE_RESIDUE_H

#include <cmath>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

template<unsigned N>
struct sqrt_calculator {
  static const unsigned root = static_cast<unsigned>(sqrt(N + 1));
};

template<unsigned N>
const unsigned sqrt_calculator_v = sqrt_calculator<N>::root;

template<unsigned N, unsigned int M>
struct is_prime_calculator {
  static const bool value = (N % M != 0 && is_prime_calculator<N, M - 1>::value);
};

template<unsigned N>
struct is_prime_calculator<N, 1> {
  static const bool value = true;
};

template<unsigned N>
struct is_prime {
  static const bool value = is_prime_calculator<N, sqrt_calculator_v<N>>::value;
};

template<>
struct is_prime<1> {
  static const bool value = false;
};

template<unsigned N>
const bool is_prime_v = is_prime<N>::value;

template <unsigned N, unsigned M>
struct count_max_degree {
  static const unsigned value = (N % M == 0 ? M : 1) *
                                count_max_degree<N / M * !static_cast<bool>(N % M), M>::value;
};

template <unsigned M>
struct count_max_degree<0, M> {
  static const unsigned value = 1;
};

template<unsigned N, unsigned M>
struct number_of_prime_divisors_calculator {
  static const unsigned value = (N % M == 0 && is_prime_v<M> ?
      number_of_prime_divisors_calculator<N / count_max_degree<N, M>::value, M - 1>::value + 1:
      number_of_prime_divisors_calculator<N, M - 1>::value);
};

template<unsigned N>
struct number_of_prime_divisors_calculator<N, 1> {
  static const unsigned value = is_prime_v<N>;
};

template<unsigned N>
struct number_of_prime_divisors {
  static const unsigned value = number_of_prime_divisors_calculator<N, static_cast<signed>(sqrt(N))>::value;
};

template<unsigned N>
struct has_primitive_root {
  static const bool value = (N % 2 == 0 ?
      (N / 2 % 2 == 1) && number_of_prime_divisors<N / 2>::value == 1 :
      number_of_prime_divisors<N>::value == 1);
};

template<>
struct has_primitive_root<2> {
  static const bool value = true;
};

template<>
struct has_primitive_root<4> {
  static const bool value = true;
};

template<unsigned N>
bool has_primitive_root_v = has_primitive_root<N>::value;
