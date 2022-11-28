#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#define MAX 256 
#define PORT 8089
#define SA struct sockaddr 
  
int main() 
{ 
	int sockfd, connfd; 
	struct sockaddr_in servaddr, cli; 
	char serverResponse[MAX];
    int len;		  
	// socket create and varification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n");	
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 
							  
	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 
										  
	// connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("connection with the server failed...\n"); 
		exit(0); 
	} 
	else
		printf("connected to the server..\n"); 
												  
    len = read(sockfd, &serverResponse, sizeof(serverResponse));
    if(len > 0) {
        printf("Received data from server : %s", serverResponse);
    }
    // close the socket 
	close(sockfd); 
} 
