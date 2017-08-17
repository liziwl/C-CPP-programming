#ifndef HTTPCnx_HPP
#define HTTPCnx_HPP

#include <string>
#include "tcpconnector.h"

class HTTPCnx {
    std::string   host;
	TCPConnector* connector;
	TCPStream*    stream;

	public:
		HTTPCnx(const char *host);
		~HTTPCnx();
        std::string get(const char *page);
};

#endif 
