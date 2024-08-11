// Program to demonstrate simple listening for a connection.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MYPORT "20202"
#define BACKLOG 10
#define BUFFER_DEFAULT 2048
#define LOCALHOST "localhost"


int main(int argc, char *argv[]){

    int status;
    struct addrinfo hints;
    struct addrinfo *servinfo;      // where the results will go

    memset(&hints, 0, sizeof(hints));  // zero storage
    hints.ai_family = AF_UNSPEC;        // don't care if ipv4 or ipv6
    hints.ai_socktype = SOCK_STREAM;    // TCP stream socket
    hints.ai_flags = AI_PASSIVE;        // fill in my IP for me 

    // have geteaddrinfo do the work -- service 20202 
    if ((status = getaddrinfo(NULL, MYPORT, &hints, &servinfo)) !=0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    int lis_socketfd;
    // open the socket with information from getaddrinfo()
    lis_socketfd = socket(servinfo->ai_family,
                        servinfo->ai_socktype,
                        servinfo->ai_protocol);
    if (lis_socketfd == -1) {
        perror("Failed to open socket: ");
        exit(1);
    }

    // start listening by calling bind
    bind(lis_socketfd, servinfo->ai_addr, servinfo->ai_addrlen);

    // free up the servinfo since no longer needed
    freeaddrinfo(servinfo);

    // set to reuse the port to prevent errors from previous runs
    int yes=1;
    if (setsockopt(lis_socketfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
        perror("Error setting setsockopt: ");
        exit(1);
    }

    // now we need to listen for messages
    listen(lis_socketfd, BACKLOG);

    // now accept incoming connection
    struct sockaddr_storage remote_addr;
    socklen_t addr_size;

    addr_size = sizeof(remote_addr);
    int new_fd;
    new_fd = accept(lis_socketfd, (struct sockaddr *)&remote_addr, &addr_size);
    send(new_fd, "Hello, world!", 13, 0);


    // recieve information from our connection
    char r_buffer[BUFFER_DEFAULT];
    int r_len = 1;
    while ((r_len = recv(new_fd, r_buffer, BUFFER_DEFAULT - 1, 0)) > 0)  {
        fprintf(stderr, "Length of message: %d\n", r_len);
        r_buffer[r_len < BUFFER_DEFAULT - 1 ? r_len + 1 : BUFFER_DEFAULT] = '\0';
        fprintf(stdout, "Message: %s", r_buffer);
     };

    if (r_len == -1) {
        perror("Error receiving from network: ");
    }
    close(new_fd);
    // 0 response indicates client has shutdown
    close(lis_socketfd);

    
}