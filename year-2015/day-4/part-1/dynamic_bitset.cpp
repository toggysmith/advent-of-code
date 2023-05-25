#include "dynamic_bitset.hpp"
#include <iostream>

const std::vector<bool>&
DynamicBitset::get_bits() const {
  return bits;
}

bool
DynamicBitset::test(int position) const {
  return bits[position];
}

void
DynamicBitset::set(int position, bool value) {
  bits[position] = value;
}

void
DynamicBitset::expand(int amount, bool value) {
  for (int i = 0; i < amount; i++) {
    bits.push_back(value);
  }
}

std::ostream&
operator<<(std::ostream& os, const DynamicBitset& bitset) {
  auto& bits{ bitset.get_bits() };
  size_t no_of_bits{ bits.size() };

  for (size_t i = 0; i < no_of_bits; i++) {
    os << static_cast<int>(bits[i]);
  }

  return os;
}
