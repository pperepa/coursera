/* Class Pair has already been declared
 * as shown in the following comments:
*/
#include <iostream>
#include "Pair.h"

// Implement its member functions below.
Pair::Pair(int a, int b)
{
    this->pa = new int(a);
    this->pb = new int(b);
}
Pair::Pair(const Pair &input)
{
    pa = new int(*(input.pa));
    pa = new int(*(input.pb));
}
Pair::~Pair()
{
    delete this->pa;
    delete this->pb;
}
/* Here is a main() function you can use
  * to check your implementation of the
  * class Pair member functions.
  */

int main()
{
    Pair p(15, 16);
    Pair q(p);
    Pair *hp = new Pair(23, 42);
    delete hp;
    std::cout << "If this message is printed,"
              << " at least the program hasn't crashed yet!\n"
              << "But you may want to print other diagnostic messages too." << std::endl;
    return 0;
}