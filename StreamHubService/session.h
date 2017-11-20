#pragma once
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/write.hpp>

using boost::asio::ip::tcp;

class session : public std::enable_shared_from_this<session> {
public:
	explicit session(tcp::socket socket);
	void start();

private:
	tcp::socket socket_;
	enum { max_length = 1024 };
	char data_[max_length];

	void do_read();
	void do_write(const std::size_t length);
};
