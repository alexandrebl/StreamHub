#include <cstdlib>
#include <iostream>
#include <memory>
#include <boost/asio.hpp>
#include "session.h"
#include "tcpserver.h"

using boost::asio::io_service;
using boost::asio::ip::tcp;

int main(const int argc, char* argv[]) {
	try {
		if (argc != 2) {
			std::cerr << "Usage: StreamHubService <port>\n";
			return 1;
		}

		io_service io_service;

		tcpserver s(io_service, std::atoi(argv[1]));

		io_service.run();
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}