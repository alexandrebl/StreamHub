#include "session.h"

session::session(boost::asio::ip::tcp::socket socket) : socket_(std::move(socket)) {}

void session::start() {
	do_read();
}

void session::do_read() {
	const auto self(shared_from_this());
	socket_.async_read_some(boost::asio::buffer(data_, max_length),
		[this, self](boost::system::error_code ec, std::size_t length) {
		if (!ec) {
			do_write(length);
		}
	});
}

void session::do_write(const std::size_t length) {
	const auto self(shared_from_this());
	boost::asio::async_write(socket_, boost::asio::buffer(data_, length),
		[this, self](boost::system::error_code ec, std::size_t) {
		if (!ec) {
			do_read();
		}
	});
}