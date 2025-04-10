#include <stddef.h> // For size_t
#include <stdint.h> // For uint32_t
#include <sys/socket.h> // For sa_family_t
#include <arpa/inet.h>  // For inet_pton

#include <netinet/in.h> // For sockaddr_in and sockaddr_in6
#include <stdio.h> // For printf
int main() {
    struct sockaddr_in sa = {0}; // IPv4
    struct sockaddr_in6 sa6 = {0}; // IPv6

    sa.sin_family = AF_INET;
    inet_pton(AF_INET, "10.12.110.57", &(sa.sin_addr)); // IPv4

    sa6.sin6_family = AF_INET6;
    inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr)); // IPv6

    return 0;
};