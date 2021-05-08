# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Dockerfile                                         :+:    :+:             #
#                                                      +:+                     #
#    By: nvan-win <nvan-win@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/13 10:02:39 by nvan-win      #+#    #+#                  #
#    Updated: 2021/02/04 17:52:05 by nvan-win      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FROM	alpine:3.12

LABEL	maintainer="Nina van Winden <nvan-win@student.codam.nl>"

# install packages
RUN		apk add mysql mysql-client

# MySQL database server configuration file
COPY	/srcs/my.cnf /etc/my.cnf

COPY	/srcs/startup.sh /tmp/startup.sh
RUN		chmod +x /tmp/startup.sh

# set up phpMyAdmin database
COPY	/srcs/create_tables.sql /tmp/create_tables.sql

EXPOSE	3306

CMD 	["/bin/sh", "/tmp/startup.sh"]
