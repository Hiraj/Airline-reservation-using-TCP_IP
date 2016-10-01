#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>




int main(void)
{





	int plane[21] = {0}, i=0,
    firstClass=1,economy=6,choice;
    char response[2];




  unsigned char  str1[10] = {0};
    char str[1000];
       char sendBuff[1025];
     int listen_fd = 0;
     int    comm_fd =0;
      int a;

    struct sockaddr_in servaddr;

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    printf("Socket Created sucessfully\n");
    ;
     bzero( &servaddr, sizeof(servaddr));
     memset(&servaddr, '0', sizeof(servaddr));
    memset(sendBuff, '0', sizeof(sendBuff));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htons(INADDR_ANY);
    servaddr.sin_port = htons(22000);

    bind(listen_fd, (struct sockaddr *) &servaddr, sizeof(servaddr));

    if(listen(listen_fd, 10) == -1)
    {
        printf("Failed to listen\n");
        return -1;
    }




    listen(listen_fd, 10);

    comm_fd = accept(listen_fd, (struct sockaddr*) NULL, NULL);



 while (1) {
	 int received_int = 0;

int return_status = read(comm_fd, &received_int, sizeof(received_int));
if (return_status > 0) {


	 int number =ntohl(received_int);
	  char buffer[100];
	  bzero(buffer , 250);






	 if(number ==1) {

	 while(1) {
	 int return_status = read(comm_fd, &buffer, sizeof(buffer));;

//        strcpy(firstname , buffer);




  char array1[100];
   char array2[100];


       write(comm_fd , &buffer , sizeof(buffer));

          write(comm_fd , &array2 , sizeof(array2));


    }
}

if(number==2)
{
if( !plane [economy] && economy<=20)
  {



  while(1) {
	 int return_status = read(comm_fd, &buffer, sizeof(buffer));;

       // strcpy(firstname , buffer);




  char array1[100];
   char array2[100];


       write(comm_fd , &buffer , sizeof(buffer));

        write(comm_fd , &array2 , sizeof(array2));


    }



}

else if(economy > 20 && firstClass<= 5)
{
  printf("The economy section is full.\n");
  printf("would you like to sit in first class");
  printf("section( Y or N)?");
  scanf("%s", response);

 if ( toupper(response[0])=='Y')
{
  printf("Your seat assignment is %d\n", firstClass);
  plane[firstClass++] = 1;
  i++;
}
else

 printf("Next flight leaves in 3 hours.\n");
}
if(choice==1)
{

if( !plane [firstClass] && firstClass <= 5){
printf("Your seat assignment is%d\n", firstClass);
plane[firstClass++] =1;
i++;


}

else if(firstClass >5 && economy <=20)
{
printf("The firstClass section is full.\n");
printf("Would you like to sit in the economy");
printf("section (Y or N)?");
scanf("%s", response);


 if(toupper(response[0])=='Y')
{
  printf("Your seat assignment is %d\n",economy);
  plane[economy++]=1;
  i++;
}
else
printf("Next flight leaves in 3 hours.\n");
}
else
printf("Next flight leaves in 3 hours.\n");
  }
}
else
{
  if(!plane[ firstClass] && firstClass <= 5)
{
  printf("Your seat assignment is %d\n", firstClass);
  plane[firstClass++] = 1;
  i++;
 }
else if( firstClass > 5 && economy <= 20)
{
printf("The first class section is full.\n");
printf("Would you like to sit in the economy ");
printf(" section (Y or N)?");
scanf("%s", response);

if(toupper(response[0]) == 'Y' )
{
printf("Your seat assignment is %d\n", economy);
plane[economy++] = 1;
i++;
 }
else
  printf("Next flight leaves in 3 hours.\n");
}
else
   printf("Next flight leaves in 3 hours.\n");
      }
   }

   printf("\nAll the seats for this flight are sold\n");

   return 0;
}





}



