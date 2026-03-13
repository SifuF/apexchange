// apexchange by SifuF 

#include "order_book.hpp"

#include <iostream>

int main()
{
    try {
        OrderBook orderBook;
        orderBook.test();
    }
    catch (...) {
        std::cerr << " Unhandled exception";
    }
  
    return 0;
}
