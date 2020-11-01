// Client side C/C++ program to demonstrate Socket programming 
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9991


std::string get_message_from_keyboard();

int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    std::string input_str;
    char buffer[1024] = {0};


    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    if ((input_str = get_message_from_keyboard()).compare("-1") == 0) {
        printf("\n Input error \n");
        return -1;
    }

    while (input_str != "@" && input_str != "#") {
        std::cout << input_str <<std::endl;
        send(sock, &input_str, input_str.length() + 1, 0);
        std::cout << ("Input message sent") << std::endl;
        valread = read(sock, buffer, 1024);
        std::cout << "Responce from server:" << std::endl;
        std::cout << buffer << std::endl;
        if ((input_str = get_message_from_keyboard()).compare("-1") == 0) {
            printf("\n Input error \n");
            return -1;
        }
    }
    return 0;
}

std::string get_message_from_keyboard() {
    std::string word = "-1";
    std::cout << ("Please type your message to server:") << std::endl;
    getline(std::cin, word);
    return word;
}

