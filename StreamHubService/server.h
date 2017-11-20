#pragma once
#include <boost/asio.hpp>

class server {
public:
	server(boost::asio::io_service& io_service, const short port);
};