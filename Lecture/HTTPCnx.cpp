#include <stdio.h>
#include <string.h>
#include "HTTPCnx.hpp"

#define MSGLEN 5000

using namespace std;

HTTPCnx::HTTPCnx(const char *h) {
   host = string(h);
   connector = new TCPConnector();
   stream = connector->connect(h,80,1); 
}

HTTPCnx::~HTTPCnx() {
	delete connector;
}

string HTTPCnx::get(const char *page) {
   char    message[MSGLEN];
   string  full_message;
   ssize_t s;
   sprintf(message,"GET %s HTTP/1.1\nHOST: %s\n\n",
                   page, host.c_str());
   stream->send(message, strlen(message));
   full_message = "";
   do {
     s = stream->receive(message, MSGLEN, 1);
     if (s > 0) {
       full_message += string(message).substr(0, s-1);
     }
   } while (s > 0);
   return full_message;
}
