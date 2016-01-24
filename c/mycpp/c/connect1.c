#include <stdio.h>
#include <stdlib.h>
#include "mysql.h"

int main(int argc,char *argv[])
{
	MYSQL *conn_ptr;

	conn_ptr=mysql_init(NULL);
	if(!conn_ptr){
		fprintf(stderr,"mysql_init failed\n");
		return EXIT_FAILURE;
	}
	conn_ptr=mysql_real_connect(conn_ptr,"localhost","shixv","shixv","shixv",0,NULL,0);

	if(conn_ptr){
		printf("Connection success.");
	}else{
		printf("Connection failed.");
	}

	mysql_close(conn_ptr);
	return EXIT_SUCCESS;
}
