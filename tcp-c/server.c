#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h> 
#define MAX 256 
#define PORT 8089 
#define SA struct sockaddr 
  
// Driver function 
int main() 
{ 
	int sockfd, clientfd, len; 
	struct sockaddr_in servaddr, cli;
    char serverMessage[MAX] = "Hello from server\n";
	// socket create and verification	
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
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 
										  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully binded..\n"); 
												  
	// Now server is ready to listen and verification 
	if ((listen(sockfd, 5)) != 0) { 
		printf("Listen failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server listening..\n"); 
	len = sizeof(cli); 
															  
	// Accept the data packet from client and verification 
	clientfd = accept(sockfd, (SA*)&cli, &len); 
	if (clientfd < 0) { 
		printf("server acccept failed...\n"); 
		exit(0);	
	} 
	else
		printf("server acccept the client...\n"); 
																		  
	// send a string
    write(clientfd, serverMessage, strlen(serverMessage));
    // After chatting close the socket 
	close(sockfd); 
} 
