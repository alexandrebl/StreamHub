#include <cstdlib>
#include <iostream>
#include <memory>
#include <boost/asio.hpp>
#include "tcpserver.h"

using namespace boost::asio;
using namespace ip;
using namespace std;

int main(const int argc, char* argv[]) {
	try {
		if (argc != 2) {
			std::cerr << "Usage: StreamHubService <port>\n";
			return 1;
		}

		io_service io_service;

		tcpserver s(io_service, atoi(argv[1]));

		io_service.run();
	} catch (exception& e) {
		cerr << "Exception: " << e.what() << "\n";
	}

	return 0;
}