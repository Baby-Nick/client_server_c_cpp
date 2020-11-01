// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <string>

#include "../include/enums.h"

#define PORT 9991

bool check_disconnect(std::string);

bool check_stop_server(std::string);

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024];
    std::string response_string = "F*ck off man.";
    conn_status conn_status = conn_close;
    server_status server_status = server_work;

    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }


    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 9991 
    if (bind(server_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    while (server_status == server_work) {
        if (listen(server_fd, 3) < 0) {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address, (socklen_t * ) & addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        conn_status = conn_open;
        while (conn_status == conn_open) {
            memset(buffer, 0, sizeof buffer);
            valread = read(new_socket, buffer, 1024);

            for (int i = 0; i < 1024; i++)
            {
                std::cout << char(buffer[i]) << std::endl;
            }

            std::cout << buffer << std::endl << std::endl;
            std::cout << "Message from client: " << std::endl << buffer << std::endl;
            std::cout << "Responce message from server:" << std::endl << response_string << std::endl;
            if (check_disconnect(buffer)) {
                conn_status = conn_close;
                break;
            }
            if (check_stop_server(buffer)) {
                server_status = server_stop;
                break;
            }
//            memset(buffer, 0, sizeof buffer);
            send(new_socket, &response_string, response_string.length() + 1, 0);
            std::cout << "Response message sent" << std::endl;
        }
    }
    return 0;
}

bool check_disconnect(std::string message) {
    std::cout << message << std::endl;
    for (int i = 0; i < message.length() + 1; ++i) {
        if (message[i] == '#') {
            return true;
        }
    }
    return false;

}

bool check_stop_server(std::string message) {
    std::cout << message << std::endl;
    for (int i = 0; i < message.length() + 1; ++i) {
        if (message[i] == '@')
            return true;
    }
    return false;
}
