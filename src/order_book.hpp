#ifndef ORDER_BOOK_H
#define ORDER_BOOK_H

#include <cassert>
#include <cstdint>
#include <limits>
#include <print>
#include <set>
#include <stdexcept>

enum class Side
{
    Buy,
    Sell
};

enum class Type
{
    Market,
    Limit
};

struct Order
{
    uint64_t id{};
    Side side{};
    Type type{};
    bool postOnly{};
    uint64_t price{};
    uint32_t quantity{};

    bool operator<(const Order& other) const {
        return (side == Side::Buy) ? (this->price < other.price) :
            (this->price >= other.price);
    }
};

class OrderBook
{
public:
    OrderBook() {}

    void submitOrder(Side side, Type type, uint64_t price,
        uint32_t quantity, bool postOnly);

    void test();

private:
    uint64_t getId();
    void printBook();

    OrderBook(const OrderBook& other) = delete;
    OrderBook(OrderBook&& other) = delete;
    OrderBook& operator=(const OrderBook& other) = delete;
    OrderBook& operator=(OrderBook&& other) = delete;

    std::set<Order> buys{};
    std::set<Order> sells{};
};

#endif // ORDER_BOOK_H
