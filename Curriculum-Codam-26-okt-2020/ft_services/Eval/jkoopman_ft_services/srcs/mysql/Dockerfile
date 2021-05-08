FROM alpine:3.11.7

RUN apk update && \
	apk add mysql mysql-client

COPY my.cnf /etc/my.cnf
COPY entrypoint.sh /entrypoint.sh
COPY init.sql /init.sql
RUN chmod +x /entrypoint.sh

EXPOSE 3306

CMD ./entrypoint.sh
