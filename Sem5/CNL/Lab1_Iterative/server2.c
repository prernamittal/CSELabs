#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main(){
    int sockfd,newsockfd,n=1,clilen;
    struct sockaddr_in seraddr,cliaddr;
    sockfd = socket(AF_LOCAL,SOCK_STREAM,0);
    seraddr.sin_family = AF_LOCAL;
    seraddr.sin_addr.s_addr = inet_addr("172.16.57.167");
    seraddr.sin_port = htons(PORTNO);
    bind(sockfd,(struct sockaddr*)&seraddr,sizeof(seraddr));
    listen(sockfd,5);
    while(1){
        char buf[256] = {""};
        char word[256][256];
        printf("server waiting");
        clilen = sizeof(clilen);
        newsockfd = accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);
        n = read(newsockfd,buf,sizeof(buf));
        int i=0, k=0, j = 0;
        while(buf[k] != '\0'){
            while(buf[k] != '\0' && buf[k] != ' '){
                word[i][j++] = buf[k];
                k++;
            }
            word[i][j] = '\0';
            if (buf[k] == ' '){
                k++;
                i++;
            }
        }
        int n=i;
        char str[256];
        int count=0;
        for (int i=0;i<n+1;i++){
            int duplicate=0;
            for (int j=i+1;j<n+1;j++){
                if (strcmp(word[i],word[j])==0){
                    duplicate = 1;
                    count++;
                    break;
                }
            }
            if (!duplicate){
                strcat(str, word[i]);
                strcat(str, " ");
            }
        }
        printf("\nmessage from client: %s \n",buf);
    	printf("\nno. of duplicate words:%d\n",count);
        n = write(newsockfd,str,sizeof(str));
    }
}
