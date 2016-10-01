#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>


int main(int argc,char **argv)
{

 char buffer[200];
 char name[200];

    int sockfd  = 0;
 
      struct sockaddr_in servaddr;
 

   sockfd=socket(AF_INET,SOCK_STREAM,0);

     if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
        printf("\n Error : Could not create socket \n");
        return 1;
    }


    bzero(&servaddr,sizeof servaddr);

    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(22000);

    inet_pton(AF_INET,"127.0.0.1",&(servaddr.sin_addr));


    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))<0)
    {
        printf("\n Error : Connect Failed \n");
        return 1;
    }
    
     /* creation of fork */
               int     fd[2];
                pid_t   childpid;

                pipe(fd);
        
                if((childpid = fork()) == -1)
                {
                        perror("fork");
                        exit(1);
					}

 while(1)
    {


  int number_to_send ;


    printf("**************************************\n");
    printf (" 1  for Business and 2 for economy\n ");
    scanf ("%d", &number_to_send);
    printf("**************************************"\n);

  int converted_number = htonl(number_to_send);


   write(sockfd, &converted_number, sizeof(converted_number));



    char buffer[100];




  
 int Seat =0;
while(1) {
char abc[100];
printf("Enter Your name \n");
scanf("%s\n",abc);

write(sockfd, &abc, sizeof(abc));
char buffers[100];
char buffer1[100];

 Seat = Seat+1;
  read(sockfd, &buffers, sizeof(buffers));
  printf("*********************************\n");
		 printf("NAME:%s\n" , pipe(buffers)); // using pipes 
		 if(Seat >12) {
			 printf(" Seats are full\n");
			 exit(1);
		 }
       printf("Seat:%d\n",Seat);
    printf("*********************************\n");

}
  }


sleep(1);

close(sockfd); // closing down
}










