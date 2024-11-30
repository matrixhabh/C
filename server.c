#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

void *handle_client(void *socket_desc) {
    int client_sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    FILE *file;

    // Receive request
    read(client_sock, buffer, BUFFER_SIZE);
    printf("Request:\n%s\n", buffer);

    // Serve an HTML file
    file = fopen("index.html", "r");
    if (file) {
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
        send(client_sock, response, strlen(response), 0);

        while (fgets(response, BUFFER_SIZE, file) != NULL) {
            send(client_sock, response, strlen(response), 0);
        }
        fclose(file);
    } else {
        sprintf(response, "HTTP/1.1 404 Not Found\r\n\r\nFile not found!");
        send(client_sock, response, strlen(response), 0);
    }

    // Close connection
    close(client_sock);
    free(socket_desc);
    return NULL;
}

int main() {
    int server_sock, client_sock, *new_sock;
    struct sockaddr_in server, client;
    socklen_t client_len = sizeof(client);
    pthread_t thread;

    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // Prepare server struct
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind
    if (bind(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        return 1;
    }

    // Listen
    listen(server_sock, MAX_CLIENTS);
    printf("Server is running on port %d...\n", PORT);

    // Accept connections
    while ((client_sock = accept(server_sock, (struct sockaddr *)&client, &client_len))) {
        printf("Connection accepted.\n");

        new_sock = malloc(sizeof(int));
        *new_sock = client_sock;

        // Create thread for each client
        if (pthread_create(&thread, NULL, handle_client, (void *)new_sock) < 0) {
            perror("Thread creation failed");
            return 1;
        }
        pthread_detach(thread); // Clean up thread resources
    }

    if (client_sock < 0) {
        perror("Accept failed");
        return 1;
    }

    close(server_sock);
    return 0;
}

// Key Takeaway: This program is useful for demonstrating socket programming, threading, and building a lightweight server.