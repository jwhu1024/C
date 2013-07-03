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
        struct sockaddr_un server_address;      /*?��?一?�UNIX?��??��?結�?*/
        struct sockaddr_un client_address;
        int i, bytes;
        char ch_send, ch_recv;

        unlink ("server_socket");       /*?�除?��?server_socket對象*/

        /*?�建 socket, ?�信?�議?�AF_UNIX, SCK_STREAM ?��??��?*/
        server_sockfd = socket (AF_UNIX, SOCK_STREAM, 0);

        /*?�置?��??�信???�信?�議)*/
        server_address.sun_family = AF_UNIX;

        /*?�置?��??�信??socket 對象)*/
        strcpy (server_address.sun_path, "server_socket");

        /*?�置?��??�信???��??�地?�?�度)*/
        server_len = sizeof (server_address);

        /*綁�? socket 對象*/
        bind (server_sockfd, (struct sockaddr *)&server_address, server_len);

        /*??��網絡,?��??�為5*/
        listen (server_sockfd, 5);

        printf ("Server is waiting for client connect...\n");

        client_len = sizeof (client_address);

        /*?��?客戶端�?�? �??��??�用來�??�客?�端?��?; �??��??�用來�??�客?�端?��??�大�?/
        /*建�?(返�?)一?�到客戶端�??�件?�述�??�以對客?�端?��?寫�?�?/
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