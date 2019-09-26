#include "DB_connector.h"

void DB_connector::SignUpQuery(const char* query)
{
	query_stat = mysql_query(connection, query);
	if (query_stat != 0) {
		fprintf(stderr, "MySQL qeury error : %s\n", mysql_error(&conn));
		exit(EXIT_FAILURE);
	}
}
