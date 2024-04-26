#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;
using namespace boost::asio::ip;

string generateResponse() {
    return "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, world!</h1>";
}

int main() {
    io_service service;
    tcp::acceptor acceptor(service, tcp::endpoint(tcp::v4(), 8080));

    while (true) {
        tcp::socket socket(service);
        acceptor.accept(socket);

        string response = generateResponse();

        boost::system::error_code ignored_error;
        write(socket, buffer(response), ignored_error);
    }

    return 0;
}
