#Dockerfile for mariadb

FROM debian:buster

RUN apt update -y && apt upgrade -y

RUN apt-get install mariadb-server -y

COPY conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf

#COPY conf/auto_config.sh /tmp/auto_config.sh

COPY tools/my_sql_script.sh my_sql_script.sh

CMD ["sh", "my_sql_script.sh"]
