#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <sys/un.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
        int server_sockfd, client_sockfd;
        int server_len, client_len;
        struct sockaddr_un server_address;      /*?²æ?ä¸€?‹UNIX?Ÿå??¥å?çµæ?*/
        struct sockaddr_un client_address;
        int i, bytes;
        char ch_send, ch_recv;

        unlink ("server_socket");       /*?ªé™¤?Ÿæ?server_socketå°è±¡*/

        /*?µå»º socket, ?šä¿¡?”è­°?ºAF_UNIX, SCK_STREAM ?¸æ??¹å?*/
        server_sockfd = socket (AF_UNIX, SOCK_STREAM, 0);

        /*?ç½®?å??¨ä¿¡???šä¿¡?”è­°)*/
        server_address.sun_family = AF_UNIX;

        /*?ç½®?å??¨ä¿¡??socket å°è±¡)*/
        strcpy (server_address.sun_path, "server_socket");

        /*?ç½®?å??¨ä¿¡???å??¨åœ°?€?·åº¦)*/
        server_len = sizeof (server_address);

        /*ç¶å? socket å°è±¡*/
        bind (server_sockfd, (struct sockaddr *)&server_address, server_len);

        /*??½ç¶²çµ¡,?Šå??¸ç‚º5*/
        listen (server_sockfd, 5);

        printf ("Server is waiting for client connect...\n");

        client_len = sizeof (client_address);

        /*?¥å?å®¢æˆ¶ç«¯è?æ±? ç¬??‹å??¸ç”¨ä¾†å??²å®¢?¶ç«¯?°å?; ç¬??‹å??¸ç”¨ä¾†å??²å®¢?¶ç«¯?°å??„å¤§å°?/
        /*å»ºç?(è¿”å?)ä¸€?‹åˆ°å®¢æˆ¶ç«¯ç??‡ä»¶?è¿°ç¬??¨ä»¥å°å®¢?¶ç«¯?„è?å¯«æ?ä½?/
        client_sockfd = accept (server_sockfd, (struct sockaddr *)&server_address, (socklen_t *)&client_len);
        if (client_sockfd == -1) {
                perror ("accept");
                exit (EXIT_FAILURE);
        }

        printf ("The server is waiting for client data...\n");

        for (i = 0, ch_send = '1'; i < 5; i++, ch_send++) {
                if ((bytes = read (client_sockfd, &ch_recv, 1)) == -1) {
                        perror ("read");
                        exit (EXIT_FAILURE);
                }

                printf ("The character receiver from client is %c\n", ch_recv);

                sleep (1);

                if ((bytes = write (client_sockfd, &ch_send, 1)) == -1) {
                        perror ("read");
                        exit (EXIT_FAILURE);
                }
        }

                close (client_sockfd);
                unlink ("server socket");
}