#include<my_global.h>
#include<WinSock2.h>
#include<mysql.h>
#pragma comment(lib, "libmysql.lib")

int main(void)
{
	printf("MySQL client version : %s\n", mysql_get_client_info());
}