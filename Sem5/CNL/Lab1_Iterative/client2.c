#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORTNO 10201

int main(){
    int sockfd,n=1,result;
    struct sockaddr_in address;
    char buf[256],ch[256];
    sockfd = socket(AF_LOCAL,SOCK_STREAM,0);
    address.sin_family = AF_LOCAL;
    address.sin_addr.s_addr = inet_addr("172.16.57.167");
    address.sin_port = htons(PORTNO);
    result = connect(sockfd,(struct sockaddr*)&address,sizeof(address));
    if(result == -1){
        perror("\nerror");
        exit(1);
    }
    while(strcmp(ch,"stop") != 0){
        printf("\n enter string : ");
        gets(ch);
        ch[strlen(ch)] = '\0';
        write(sockfd,ch,strlen(ch));
        printf("string sent back from server ..... ");
            read(sockfd,buf,sizeof(buf));
            puts(buf);
    }
}
