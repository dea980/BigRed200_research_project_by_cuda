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
 
    int s_socketfd;
    // open the socket with information from getaddrinfo()
    s_socketfd = socket(servinfo->ai_family,
                        servinfo->ai_socktype,
                        servinfo->ai_protocol);
    if (s_socketfd == -1) {
        perror("Failed to open socket: ");
        exit(1);
    }

    char message[] = "Hello world!";

    // start sending text to the open socket
    connect(s_socketfd, servinfo->ai_addr, servinfo->ai_addrlen);

    char *s_buffer = NULL;
    size_t s_len = 0;
    char r_buffer[BUFFER_DEFAULT];
    size_t r_len = BUFFER_DEFAULT;
    ssize_t bytes_read;

    // We expect an initial greeting from the server when we connect
    r_len = recv(s_socketfd, r_buffer, BUFFER_DEFAULT, 0);
    fprintf(stderr, "Message from server: %s\n",r_buffer);

    while ((bytes_read = getline(&s_buffer, &s_len, stdin)) != -1) {
        send(s_socketfd, s_buffer, bytes_read, 0);
    }
    free(s_buffer);



    // 0 response indicates client has shutdown
    close(s_socketfd);

    freeaddrinfo(servinfo);
}