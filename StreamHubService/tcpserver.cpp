#include "tcpserver.h"
#include "session.h"

using boost::asio::io_service;
using boost::asio::ip::tcp;
using boost::system::error_code;

tcpserver::tcpserver(io_service& io_service, const short port)
	: acceptor(io_service, tcp::endpoint(tcp::v4(), port)),
	socket(io_service) {
	do_accept();
}

void tcpserver::do_accept() {
		acceptor.async_accept(socket,
			[this](error_code ec) {
			if (!ec) {
				std::make_shared<session>(std::move(socket))->start();
			}

			do_accept();
		});
	}