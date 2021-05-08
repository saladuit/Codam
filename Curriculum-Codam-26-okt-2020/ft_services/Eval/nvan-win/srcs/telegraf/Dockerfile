# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Dockerfile                                         :+:    :+:             #
#                                                      +:+                     #
#    By: nvan-win <nvan-win@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/27 17:03:43 by nvan-win      #+#    #+#                  #
#    Updated: 2021/02/08 18:19:30 by nvan-win      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FROM	alpine:3.12

RUN 	apk update; \
		apk update; \
        apk add libc6-compat	

# install Telegraf
RUN		wget https://dl.influxdata.com/telegraf/releases/telegraf-1.17.2_linux_amd64.tar.gz; \
		tar xf telegraf-1.17.2_linux_amd64.tar.gz

# Telegraf config file
COPY 	srcs/telegraf.conf /etc/telegraf/telegraf.conf

EXPOSE	8125

CMD		./telegraf-1.17.2/usr/bin/telegraf
