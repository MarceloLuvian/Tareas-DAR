#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

int login(){
char user[10];
char pass[10];
printf(" [usuario]   [contraseña] \n");
scanf ("%s %s", user, pass);

}

int main(void){
int fd; //Descriptor del FIFO
int len; //Bytes leidos del FIFO
char buf[PIPE_BUF];
 mode_t mode = 0666;
int comp;
char *UUID2 = "8AB7-4EFE";
 if ((mkfifo("fifo1",mode)) < 0) {
 	perror ("mkfifo");
 	exit (EXIT_FAILURE);
 }
 //Apertura del FIFO de solo lectura
 if ((fd = open("fifo1", O_RDONLY)) < 0){
 	perror("open");
 	exit(EXIT_FAILURE);
 }
 			
 //Lectura y visualizacion de la salida del FIFO hasta EOF
 while ((len = read(fd, buf, PIPE_BUF - 1)) > 0)
 
comp = strncmp(buf, UUID2, 3);
printf("%i\n", comp );
if (comp == 0){
	login();
	printf(" ACCESO AUTORIZADO: \n ");
	printf("La memoria esta conectada con el UUID:  ");
	printf("%s", buf);

}else {
	printf(" La memoria no esta conectada\n");
}
  
	
 close(fd);
 exit(EXIT_SUCCESS);

}
