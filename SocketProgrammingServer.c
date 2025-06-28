#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(){

    char massege[256] = "this is a massege from the server";

    // server socket creating
    int serverSocket;
    serverSocket = socket(AF_INET , SOCK_STREAM , 0);

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8000);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // bind socket to the spiecified address
    bind(serverSocket , (struct sockaddr_in*) &serverAddress , sizeof(serverAddress));

    listen(serverSocket , 1000);

    // client socket
    int clientSocket;
    clientSocket = accept(serverSocket , NULL , NULL);

    // send massege to the client
    send(clientSocket , massege , sizeof(massege) , 0);

    close(serverSocket);

    return 0;
}
