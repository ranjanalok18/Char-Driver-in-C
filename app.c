#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h> 
#include<sys/stat.h>
#include<fcntl.h>


int main()
{
	int fd=-1;
	char ubuf[50];
//	char ubuf[50]="Hello...Its User";
	char kbuf[20];
	fd=open("/dev/mycdev", O_RDWR);
	if(fd<0){
		perror("file: \n");
		return -1;
	}
	read(fd,kbuf,sizeof(kbuf));
	printf("%s\n",kbuf);
	strcpy(ubuf,"ITS USER");
	write(fd,ubuf,strlen(ubuf)+1);
	close(fd);
	return 0;
}
