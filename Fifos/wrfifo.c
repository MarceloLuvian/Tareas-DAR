#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <err.h>
#include <blkid/blkid.h>



int Usuario () {
	int argc ;
char *argv[1];
char *argv1[2];
        int retval;
        char *user, *pass;   

        if(argc == 3) {

                user = argv[1];
                pass = strdup(argv1[2]);

        } else { 

                fprintf(stderr, "Usage: login [username] [password]\n");
              	
                exit(1);

        }

        return 1;
}


int main(int argc, char *argv[])
{
int fd; //Descriptores del FIFO
int len; //Bytes escritos en el FIFO
char buf[PIPE_BUF]; //Se asegura de escrituras atomicas 

char *UUID2 = "A1E6-99D8";
 int comp;
   blkid_probe pr = blkid_new_probe_from_filename(argv[1]);
   if (!pr) {
      err(1, "Fallo al abrir archivo de USB %s", argv[1]);
   }
   const char *uuid;
   blkid_do_probe(pr);
   blkid_probe_lookup_value(pr, "UUID", &uuid, NULL);
   if (strlen(uuid) > 1) {     
   		   		
   			
	//Abre el FIFO de solo escritura
if ((fd = open("fifo1",O_WRONLY)) < 0){
	perror("open");
	exit(EXIT_FAILURE);
}
} else {
      printf("%s has no UUID\n", argv[1]);
   }

 blkid_free_probe(pr);

len = sprintf (buf, "%s\n", uuid);

if ((write(fd, buf, len + 1)) < 0){
	perror("write");
	close(fd);
	exit(EXIT_FAILURE);
}

close(fd);
exit(EXIT_SUCCESS);

}