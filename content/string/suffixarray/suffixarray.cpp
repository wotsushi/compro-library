#include "suffixarray.hpp"

// begin
int main() {
  // sa = ["", "a", "abra", "abracadabra", "acadabra", "adabra", "bra",
  // "bracadabra", "cadabra", "cadabra", "dabra", "ra", "racadabra"]
  suffixarray sa("abracadabra");
  {
    string actual = sa[0];
    string expected = "";
    assert(actual == expected);
  }
  {
    string actual = sa[1];
    string expected = "a";
    assert(actual == expected);
  }
  {
    string actual = sa[2];
    string expected = "abra";
    assert(actual == expected);
  }
  {
    string actual = sa[11];
    string expected = "racadabra";
    assert(actual == expected);
  }
}
// end