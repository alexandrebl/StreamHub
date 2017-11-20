#include "session.h"

using boost::asio::buffer;
using boost::asio::ip::tcp;
using boost::system::error_code;

session::session(tcp::socket socket) : socket_(std::move(socket)) {}

void session::start() {
	do_read();
}

void session::do_read() {
	const auto self(shared_from_this());
	socket_.async_read_some(buffer(data_, max_length),
		[this, self](error_code ec, size_t length) {
		if (!ec) {
			do_write(length);
		}
	});
}

void session::do_write(const size_t length) {
	const auto self(shared_from_this());
	boost::asio::async_write(socket_, buffer(data_, length),
		[this, self](error_code ec, size_t) {
		if (!ec) {
			do_read();
		}
	});
}