#ifndef __DB_CONNECTOR_H___
#define __DB_CONNECTOR_H___

#include <my_global.h>
#include <mysql.h>
#pragma comment(lib, "libmysql.lib")

namespace DB {

#define CHOP(x) x[strlen(x) - 1] = ' '
	
	typedef struct {
		char HOST[20];
		char USER[20];
		char PASS[20];
		char NAME[20];
	}Info;
	
	const Info setting(void) 
	{
		Info ret;

		printf("Input : <IP addr> <user> <password> <database name>");
		scanf("%s %s %s %s", &ret.HOST, &ret.USER, &ret.PASS, &ret.NAME);

		return ret;
	}
}

class DB_connector
{
private:
	MYSQL conn;
	MYSQL* connection;
	MYSQL_RES* sql_result;
	MYSQL_ROW sql_row;

	int query_stat;

	const DB::Info info = DB::setting();
public:
	DB_connector() {
		mysql_init(&(this->conn));

		this->connection = mysql_real_connect(
			&conn, info.HOST, info.USER, info.PASS, info.NAME,
			3306, (char*)NULL, 0
		);
		if (this->connection == NULL) {
			fprintf(stderr, "MySQL connect error %s\n", mysql_error(&(this->conn)));
			exit(EXIT_FAILURE);
		}

		sql_result = mysql_store_result(this->connection);
	}
	~DB_connector() {
		mysql_free_result(sql_result);
	}

public:
	void SignUpQuery(const char* query);
};

#endif // !__DB_CONNECTOR_H___
