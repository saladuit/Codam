# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Dockerfile                                         :+:    :+:             #
#                                                      +:+                     #
#    By: nvan-win <nvan-win@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/13 08:38:33 by nvan-win      #+#    #+#                  #
#    Updated: 2021/02/10 10:15:12 by nvan-win      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FROM	alpine:3.12

LABEL	maintainer="Nina van Winden <nvan-win@student.codam.nl>"

# install packages
RUN		apk update; \
		apk upgrade; \
		apk add supervisor; \
		apk add nginx; \
		apk add mysql-client;\
		apk add php7 php7-fpm php7-opcache php7-common php7-curl php7-json php7-mbstring php7-xml php7-zip php7-gd php7-soap php7-tokenizer php7-dom php7-exif php7-fileinfo php7-mysqli php7-zlib php7-phar

# configure supervisor and the processes it manages
COPY    /srcs/supervisord.conf  /etc/supervisord.conf

# nginx config file
COPY	/srcs/nginx.conf /etc/nginx/nginx.conf

# change php-fpm user to 'www'
COPY	/srcs/php-fpm.conf /etc/php7/php-fpm.conf

# creating new user and group 'www' for nginx
RUN		adduser -D -g 'www' www

# create a directory for html files
RUN		mkdir /www; \
		chown -R www:www /var/lib/nginx; \
		chown -R www:www /www

RUN		mkdir -p /var/run/nginx

RUN 	wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar; \
		chmod +x wp-cli.phar; \
		mv wp-cli.phar /usr/local/bin/wp

COPY	/srcs/wp-config.php /tmp

COPY	/srcs/startup.sh /tmp/startup.sh
RUN		chmod +x /tmp/startup.sh

EXPOSE 	5050

CMD 	["sh", "-c", "/tmp/startup.sh ; /usr/bin/supervisord -c /etc/supervisord.conf"]
