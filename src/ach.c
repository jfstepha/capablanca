/* (C) Jon Stephan 2015
 *
 */


#include "includes.h"
int ach_print( char *str )
{
    char buffer[ACH_BUFFER_LEN];
    ach_print_return( buffer, str);
}

int ach_print_return( char *buffer, char *str)
{
    int opt;
    int n;

    struct sockaddr_in serv_addr;
    struct hostent *server;

    d_printf("ACH print\n");

    /* Open a TCP socket (an Internet stream socket). */
    if ((net_globals.ach_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        d_printf( "CHESSD: can't open stream socket\n");
        return -1;
    }
    server = gethostbyname("localhost");
	if(server == NULL) {
	    d_printf("ACH_PRINT: no such host\n");
	    return(-1);
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
	      (char *)&serv_addr.sin_addr.s_addr,
	      server->h_length);
	serv_addr.sin_port = htons(DEFAULT_ACH_PORT);
    if (connect(net_globals.ach_sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
	      d_printf("ERROR connecting\n");
	      return(-1);
    }

    bzero(buffer,ACH_BUFFER_LEN);
    sprintf(buffer,"%s\n", str);
	n = write(net_globals.ach_sockfd, buffer,strlen(buffer));

	if (n < 0) {
	    d_printf("Error writing to ach socket\n");
	    return(-1);
	}
	bzero(buffer,ACH_BUFFER_LEN);
    n = read(net_globals.ach_sockfd,buffer,ACH_BUFFER_LEN-1);
	if (n < 0) {
	    d_printf("ERROR reading from socket");
	    return(-1);
	}
	d_printf("returned from ach server:%s\n",buffer);
	d_printf("ACH closing\n");

	close( net_globals.ach_sockfd);
	d_printf("ACH closed\n");
	return(0);

}

