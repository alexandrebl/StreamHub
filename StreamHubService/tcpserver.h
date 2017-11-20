#pragma once
#include <boost/asio/ip/tcp.hpp>

using boost::asio::ip::tcp;
using boost::asio::io_service;

class tcpserver {
public:
	tcp::acceptor acceptor;
	tcp::socket socket;

	tcpserver(io_service& io_service, const short port);

private:
	void do_accept();
};