#include <iostream>

namespace math
{
  const int one = 1;
  const int two = 2;
  const int three = 3;
  const int four = 4;
  const int five = 5;
  const int six = 6;
  const int seven = 7;
  const int eight = 8;
  const int nine = 9;
  
  int sum (const int a, const int b) { return a+b; }
  int sub (const int a, const int b) { return a-b; }
}

namespace smath
{
  const int one = 5;
  const int two = 2;
  const int three = 6;
  const int four = 4;
  const int five = 7;
  const int six = 9;
  const int seven = 3;
  const int eight = 8;
  const int nine = 1;
  
  int sum (const int a, const int b) { return a+b; }
  int sub (const int a, const int b) { return a-b; }
}
using namespace std;
/** 
 * Warning:
 *  - using one, two... etc without namespace will generate ambiguity
 *  - using cout, cin or endl is ok since we don't have any so called 
 *    members in our namespaces
 *  - we can also use a single member of a namespace. writing
 *    using math::one, one will automatically refer to "1"
 * 
 *  See more documentation at: http://www.cplusplus.com/doc/tutorial/namespaces/
 */
int main()
{
  cout << "Matematica giusta: sommo e sottraggo " << math::seven << ", " << math::three << endl;
  cout << math::seven << " + " << math::three << " = " << math::sum(math::seven, math::three) << endl;
  cout << math::seven << " - " << math::three << " = " << math::sub(math::seven, math::three) << endl;  
  
  cout << "Matematica giusta: sommo e sottraggo " << smath::seven << ", " << smath::three << endl;
  cout << smath::seven << " + " << smath::three << " = " << smath::sum(smath::seven, smath::three) << endl;
  cout << smath::seven << " - " << smath::three << " = " << smath::sub(smath::seven, smath::three) << endl;
 
  /** namespaces are limited by block which they're in, so there's
   *  no ambiguity in their use here
   */
   
  if(1)
  {
    using namespace math;
    cout << "Using Math: " << seven << "+" << three << " = " << sum(seven, three) << endl;    
  }
  
  if(1)
  {
    using namespace smath;
    cout << "Usign SMath: " << seven << "+" << three << " = " << sum(seven, three) << endl;    
  }
  
}
