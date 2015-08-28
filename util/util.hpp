#ifndef UTIL_HPP
#define UTIL_HPP

#include <string>
#include <map>

struct Order
{
  int orderId;

  Order();
};

class OrderBook
{
  //map<int, int> orders[2];
  Order orders[2];
};


#endif


