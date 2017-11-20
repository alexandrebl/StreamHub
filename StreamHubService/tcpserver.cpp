#include "tcpserver.h"
#include "session.h"

using boost::asio::io_service;
using boost::asio::ip::tcp;
using boost::system::error_code;

tcpserver::tcpserver(io_service& io_service, const short port)
	: acceptor_(io_service, tcp::endpoint(tcp::v4(), port)),
	socket_(io_service) {
	do_accept();
}

void tcpserver::do_accept() {
		acceptor_.async_accept(socket_,
			[this](error_code ec) {
			if (!ec) {
				std::make_shared<session>(std::move(socket_))->start();
			}

			do_accept();
		});
	}