#pragma once
#include <boost/asio/ip/tcp.hpp>

class tcpserver {
public:
	boost::asio::ip::tcp::acceptor acceptor_;
	boost::asio::ip::tcp::socket socket_;

	tcpserver(boost::asio::io_service& io_service, const short port);

private:
	void do_accept();
};