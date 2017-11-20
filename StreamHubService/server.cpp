#include "server.h"
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>


	server::server(boost::asio::io_service& io_service, const short port)
		: acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
		socket_(io_service) {
		do_accept();
	}

//private:
//	void do_accept() {
//		acceptor_.async_accept(socket_,
//			[this](boost::system::error_code ec) {
//			if (!ec) {
//				std::make_shared<session>(std::move(socket_))->start();
//			}
//
//			do_accept();
//		});
//	}
//
//	boost::asio::ip::tcp::acceptor acceptor_;
//	boost::asio::ip::tcp::socket socket_;
//};