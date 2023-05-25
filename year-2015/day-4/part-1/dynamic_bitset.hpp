#include <vector>
#include <fstream>

#ifndef DYNAMIC_BITSET_HPP
#define DYNAMIC_BITSET_HPP

class DynamicBitset {
public:
  const std::vector<bool>& get_bits() const;
  bool test(int) const;
  void set(int, bool);
  void expand(int, bool);

  friend std::ostream& operator<<(std::ostream&, const DynamicBitset&);

private:
  std::vector<bool> bits;
};

#endif
