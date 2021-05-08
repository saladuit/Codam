# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Dockerfile                                         :+:    :+:             #
#                                                      +:+                     #
#    By: nvan-win <nvan-win@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/13 08:38:26 by nvan-win      #+#    #+#                  #
#    Updated: 2021/02/09 17:55:42 by nvan-win      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FROM	alpine:3.12

LABEL	maintainer="Nina van Winden <nvan-win@student.codam.nl>"

# install packages
RUN		apk update; \
		apk upgrade; \
		apk add supervisor; \
		apk add nginx; \
		apk add openssl; \
		apk add openssh

# configure supervisor and the processes it manages
COPY    /srcs/supervisord.conf  /etc/supervisord.conf

# nginx config file
COPY	/srcs/nginx.conf /etc/nginx/nginx.conf

# create new user and group 'www' for nginx
RUN		adduser -D -g 'www' www

# create a directory for html files
RUN		mkdir /www; \
		chown -R www:www /var/lib/nginx; \
		chown -R www:www /www

RUN		mkdir -p /var/run/nginx

COPY	srcs/index.html /www/index.html

# create authentication key pairs for SSH
RUN		adduser -D user
RUN		echo "user:password" | chpasswd
RUN		ssh-keygen -A

# create SSL certificates
RUN		openssl req -x509 -days 365 -newkey rsa:2048 -nodes -sha256 \
		-out /etc/ssl/certs/nginx-selfsigned.crt \
		-keyout	/etc/ssl/private/nginx-selfsigned.key \
		-subj "/C=NL/ST=NH/L=Amsterdam/O=Codam/CN=nginx-svc"; \
		chmod 775 /etc/ssl/private/nginx-selfsigned.key; \
		chmod 775 /etc/ssl/certs/nginx-selfsigned.crt

EXPOSE 	80 443 22

CMD		["/usr/bin/supervisord"]
