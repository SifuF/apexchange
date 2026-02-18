#include "order_book.hpp"

void OrderBook::test()
{
	submitOrder(Side::Buy, Type::Limit, 9850, 2, false);
	submitOrder(Side::Buy, Type::Limit, 9725, 5, true);
	submitOrder(Side::Buy, Type::Limit, 9675, 1, false);
	submitOrder(Side::Buy, Type::Limit, 9900, 4, true);
	submitOrder(Side::Buy, Type::Limit, 9550, 3, false);
	submitOrder(Side::Buy, Type::Limit, 9475, 6, false);
	submitOrder(Side::Buy, Type::Limit, 9950, 2, true);
	submitOrder(Side::Buy, Type::Limit, 9625, 1, false);
	submitOrder(Side::Buy, Type::Limit, 9775, 3, false);
	submitOrder(Side::Buy, Type::Limit, 9825, 2, true);
	submitOrder(Side::Buy, Type::Limit, 9500, 5, false);
	submitOrder(Side::Buy, Type::Limit, 9450, 4, false);
	submitOrder(Side::Buy, Type::Limit, 9925, 1, true);
	submitOrder(Side::Buy, Type::Limit, 9700, 2, false);
	submitOrder(Side::Buy, Type::Limit, 9650, 3, false);
	submitOrder(Side::Buy, Type::Limit, 9875, 2, true);
	submitOrder(Side::Buy, Type::Limit, 9575, 1, false);
	submitOrder(Side::Buy, Type::Limit, 9750, 6, false);
	submitOrder(Side::Buy, Type::Limit, 9600, 2, true);
	submitOrder(Side::Buy, Type::Limit, 9910, 3, false);

	submitOrder(Side::Sell, Type::Limit, 10100, 2, false);
	submitOrder(Side::Sell, Type::Limit, 10250, 3, true);
	submitOrder(Side::Sell, Type::Limit, 10075, 1, false);
	submitOrder(Side::Sell, Type::Limit, 10300, 5, false);
	submitOrder(Side::Sell, Type::Limit, 10150, 2, true);
	submitOrder(Side::Sell, Type::Limit, 10425, 4, false);
	submitOrder(Side::Sell, Type::Limit, 10200, 1, false);
	submitOrder(Side::Sell, Type::Limit, 10050, 3, true);
	submitOrder(Side::Sell, Type::Limit, 10350, 2, false);
	submitOrder(Side::Sell, Type::Limit, 10175, 6, false);
	submitOrder(Side::Sell, Type::Limit, 10500, 1, true);
	submitOrder(Side::Sell, Type::Limit, 10225, 3, false);
	submitOrder(Side::Sell, Type::Limit, 10090, 2, false);
	submitOrder(Side::Sell, Type::Limit, 10375, 4, true);
	submitOrder(Side::Sell, Type::Limit, 10125, 2, false);
	submitOrder(Side::Sell, Type::Limit, 10450, 1, false);
	submitOrder(Side::Sell, Type::Limit, 10275, 5, false);
	submitOrder(Side::Sell, Type::Limit, 10060, 2, true);
	submitOrder(Side::Sell, Type::Limit, 10325, 3, false);
	submitOrder(Side::Sell, Type::Limit, 10190, 1, true);

	printBook();
}

void OrderBook::submitOrder(Side side, Type type, uint64_t price, uint32_t quantity, bool postOnly)
{
	Order order {
		.id = getId(),
		.side = side,
		.type = type,
		.postOnly = postOnly,
		.price = price,
		.quantity = quantity
	};

	if (order.side == Side::Buy) {
		buys.insert(std::move(order));
	}
	else if (order.side == Side::Sell) {
		sells.insert(std::move(order));
	}
}

uint64_t OrderBook::getId()
{
	static uint64_t id{};
	if (id >= (std::numeric_limits<uint64_t>::max() - 1)) {
		throw std::overflow_error("ID counter overflow");
	}
	return id++;
}

void OrderBook::printBook()
{
	auto printSide = [this](Side side) {
		std::println("{}", (side == Side::Buy) ? "Buy" : "Sell");
		const auto& list = side == Side::Buy ? buys : sells;
		for (const auto& o : list) {
			std::println("{} {} {}", o.price, o.quantity, o.id);
		}
		std::println("");
    };
	printSide(Side::Sell);
	printSide(Side::Buy);
}
