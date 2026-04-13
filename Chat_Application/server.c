#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
 
int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address); 
    char buffer[1024] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&amp;address, sizeof(address));
    listen(server_fd, 3);

    printf("Server started on port %d...\n", PORT);

    new_socket = accept(server_fd, (struct sockaddr *)&amp;address, (socklen_t*)&amp;addrlen);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        read(new_socket, buffer, 1024);
        printf("Client: %s\n", buffer);

        printf("You: ");
        fgets(buffer, 1024, stdin);
        send(new_socket, buffer, strlen(buffer), 0);
    }

    return 0;
}

