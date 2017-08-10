#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>
#include <errno.h>

#include "HTTPCnx.hpp"

#define  BUFFER_SZ   50

using namespace std;

int main(int argc, char **argv) {
    if ((argc < 2) || (argc > 3)) {
        cerr << "Usage : " << argv[0] << " website [<page>]\n";
        return 1;
    }
    HTTPCnx *http = new HTTPCnx(argv[1]);
    if (http) {
       char   line[BUFFER_SZ];
       int    len;
       int    code;
       string response = "";

       response = http->get((argc == 3 ? argv[2] : "/"));
       if (response.length()) {
          cout << response << endl;
       } else {
          cerr << "No response" << endl;
       }
    } else {
       perror("Connection");
       cerr << "(httptest) Failed to connect\n"; 
    }
    return 0;
}
