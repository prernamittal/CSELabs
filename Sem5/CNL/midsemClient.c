#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define portno 7777

struct studentInfo{
	char name[50];
	long int regno;
};
struct studentInfo student;

int main(){
	int sockfd;
	struct sockaddr_in addr;
	sockfd=socket(AF_INET, SOCK_STREAM, 0);
	addr.sin_family=AF_INET;
	addr.sin_addr.s_addr=inet_addr("172.16.57.152");
	addr.sin_port=htons(portno);

	connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));

	printf("Enter name: ");
	scanf("%s", student.name);
	printf("Enter regno: ");
	scanf("%ld", &student.regno);

	//for writing to server
	write(sockfd, (struct studentInfo *)&student, sizeof(student));

	//for reading from server and printing
	read(sockfd, (struct studentInfo *)&student, sizeof(student));
	printf("Name: %s\n", student.name);
	printf("RegNo: %ld", student.regno);






}