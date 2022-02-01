#ifndef BITSET_HPP
#define BITSET_HPP
#include <string>

class Bitset{
public:

  // Default constructor for Bitset class
  Bitset();

  // Custom constructor that allows user to select the size
  Bitset(intmax_t size);

  // Custom constructor that uses a custom string
  Bitset(const std::string & value);

  // Destructor for Bitset class
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // Function that returns the size of the bitset
  intmax_t size() const;

  // Function that determines if the bitset is valid
  bool good() const;

  // Function that sets a chosen bit to one
  void set(intmax_t index);

  // Function that sets a chosen bit to zero
  void reset(intmax_t index);

  // Function that toggles the bit to the opposite of its current state
  void toggle(intmax_t index);

  // Function that returns whether or not a bit is set
  bool test(intmax_t index);

  // Function that returns string representation of bit
  std::string asString() const;

private:
  intmax_t bitsize;
  bool isValid;
  uint8_t *arr;
};

#endif
