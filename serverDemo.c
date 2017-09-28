/* server.c */ 
#include <stdio.h> 
#include <string.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <ctype.h>
#include "wrap.h" 
#include "user_webserver.h" 

#define MAXLINE 1024 
#define SERV_PORT 8000

//void webserver_recv(int connfd);

int main(void) 
{ 
	struct sockaddr_in servaddr, cliaddr; 
	socklen_t cliaddr_len; 
	int listenfd, connfd; 
	char buf[MAXLINE]; 
	char str[INET_ADDRSTRLEN]; 
	int i, n; 
    char *ptemp = NULL;
	
	listenfd = Socket(AF_INET, SOCK_STREAM, 0); 
	
	bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(SERV_PORT); 
	
	Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)); 
	Listen(listenfd, 20); 
	printf("Accepting connections ...\n"); 
	
	while (1) 
	{ 
		cliaddr_len = sizeof(cliaddr); 
		connfd = Accept(listenfd,(struct sockaddr *)&cliaddr, &cliaddr_len); 
		
		while (1) 
		{ 
			n = Read(connfd, buf, MAXLINE); 
			if (n == 0) 
			{ 
				printf("the other side has been closed.\n"); 
				break; 
			} 
			printf("%s\n", buf); 
			ptemp = (char *)strstr(buf, "\r\n\r\n");
			if (ptemp == NULL) 
			{
				printf("recv the rest data.\n"); 
				continue;//recv the rest data
			}


			/*printf("received from %s at PORT %d\n", 
				inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), 
				ntohs(cliaddr.sin_port));*/
			
			//for (i = 0; i < n; i++) 
			//	buf[i] = toupper(buf[i]); 

			//webserver_recv(connfd);
			webserver_recv(NULL, buf, n);
			break;

		} 
		Close(connfd); 
	} 
}

#if 0
void webserver_recv(int connfd)
{
		char httphead[2048];
		char psend[2048];

		memset(httphead, 0, 2048);
		memset(psend, 0, 2048);

		sprintf(httphead,"HTTP/1.1 200 OK\r\n");
        sprintf(httphead + strlen(httphead),"Content-type: text/plain\r\n\r\n");

        //sprintf(psend + strlen(psend),"<html> <head><title>OPEN LOONGSON Server</title></head> <body> ");

		sprintf(psend + strlen(psend)," |********************************************************************************************| \r\n");
		sprintf(psend + strlen(psend)," |                                                                                            | \r\n");
		sprintf(psend + strlen(psend)," |      /////////  /////////  /////////  //     //                                            | \r\n");              
		sprintf(psend + strlen(psend)," |     //     //  //     //  //         ///    //                                             | \r\n");              
		sprintf(psend + strlen(psend)," |    //     //  //     //  //         ////   //                                              | \r\n");              
		sprintf(psend + strlen(psend)," |   //     //  /////////  /////////  //  // //               www.openloongson.org            | \r\n");           
		sprintf(psend + strlen(psend)," |  //     //  //         //         //   ////                                                | \r\n");              
		sprintf(psend + strlen(psend)," | //     //  //         //         //    ///                                                 | \r\n"); 
		sprintf(psend + strlen(psend)," |/////////  //         /////////  //     //                                                  | \r\n");              
		sprintf(psend + strlen(psend)," |                                                                                            | \r\n");
		sprintf(psend + strlen(psend)," |                                                                                            | \r\n");
		sprintf(psend + strlen(psend)," |      //         /////////  /////////  //     //  /////////  /////////  /////////  //     //| \r\n");
		sprintf(psend + strlen(psend)," |     //         //     //  //     //  ///    //  //         //     //  //     //  ///    // | \r\n");
		sprintf(psend + strlen(psend)," |    //         //     //  //     //  ////   //  //         //         //     //  ////   //  | \r\n");
		sprintf(psend + strlen(psend)," |   //         //     //  //     //  //  // //  //         /////////  //     //  //  // //   | \r\n");
		sprintf(psend + strlen(psend)," |  //         //     //  //     //  //   ////  //   ////         //  //     //  //   ////    | \r\n");
		sprintf(psend + strlen(psend)," | //         //     //  //     //  //    ///  //     //  //     //  //     //  //    ///     | \r\n");
		sprintf(psend + strlen(psend)," |/////////  /////////  /////////  //     //  /////////  /////////  /////////  //     //      | \r\n");
		sprintf(psend + strlen(psend)," |                                                                                            | \r\n");
		sprintf(psend + strlen(psend)," |********************************************************************************************| \r\n");
																																			 
        //sprintf(psend + strlen(psend),"</body> </html>");

		

        sprintf(httphead + strlen(httphead), psend);

		Write(connfd, httphead, strlen(httphead)); 

}
#endif




