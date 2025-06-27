#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){

    int networksSocket;
    // AF_INET = IPv4
    // SOCK_STREAM = TCP Protocol
    networksSocket = socket(AF_INET , SOCK_STREAM , 0);

    // server IP and Port
    struct sockaddr_in serverAddress;
    // let it know it is a TCP Protocol
    serverAddress.sin_family = AF_INET;
    // Server port
    serverAddress.sin_port = htons(8000);
    // Get the local IP address
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    
    int statusOfConnection = connect(networksSocket , (struct sockaddr *) &serverAddress , sizeof(serverAddress));

    // check if theres an error at connecting 
    if (statusOfConnection == -1)
    {
        printf("Error at making socket\n");
    }
    
    char serverRespose [256];
    // recieve data from server
    recv(networksSocket , &serverRespose , sizeof(serverRespose) , 0);
    printf("the server sent the data: $s\n", serverRespose);

    // close socket
    close(socket);

    return 0;
}
