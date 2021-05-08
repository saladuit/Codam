# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Dockerfile                                         :+:    :+:             #
#                                                      +:+                     #
#    By: nvan-win <nvan-win@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/13 08:38:17 by nvan-win      #+#    #+#                  #
#    Updated: 2021/02/04 17:38:07 by nvan-win      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FROM	alpine:3.12

LABEL	maintainer="Nina van Winden <nvan-win@student.codam.nl>"

# install packages
RUN     apk update; \
        apk upgrade; \
		apk add supervisor; \		
        apk add nginx; \
		apk add php7 php7-fpm php7-opcache php7-gd php7-mysqli php7-zlib php7-curl php7-mbstring php7-json php7-session; \
        apk add wget

# configure supervisor and the processes it manages
COPY    /srcs/supervisord.conf  /etc/supervisord.conf

# nginx config file
COPY	/srcs/nginx.conf /etc/nginx/nginx.conf

# phpMyAdmin config file
COPY	/srcs/config.inc.php /www/

# create new user and group 'www' for nginx
RUN     adduser -D -g 'www' www

# create a directory for html files
RUN		mkdir -p /www; \
		chown -R www:www /var/lib/nginx; \
		chown -R www:www /www

RUN		mkdir -p /var/run/nginx

RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz; \
		tar -zxvf phpMyAdmin-5.0.4-english.tar.gz --strip-components=1 -C /www; \
		rm phpMyAdmin-5.0.4-english.tar.gz

EXPOSE  5000

CMD		["/usr/bin/supervisord"]