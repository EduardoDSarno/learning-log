// gcc main.c -o main && sudo ./main

#include "client/client.h"
#include "server/server.h"
#include "shared/helpers.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

int main(void){

    srand(time(NULL)); // for rand sequence number

    ConnectionData *data = connection_init(12345, inet_addr("127.0.0.1"),80, inet_addr("127.0.0.1"));

    
    pthread_t server;
    pthread_create(&server, NULL, server_thread, data);
    sleep(1);

    pthread_t client;
    pthread_create(&client,NULL, client_thread, data);

    pthread_join(server, NULL);
    pthread_join(client, NULL);

    free(data);
 
}