FROM alpine:3.11.7

RUN apk update && \
	apk add php7 php7-fpm php7-mbstring php7-json php7-session php7-mysqli nginx supervisor

RUN mkdir /var/run/nginx && \
	adduser -D -g 'www' www && \
	mkdir /www && \
	chown -R www:www /var/lib/nginx && \
	chown -R www:www /www

RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-english.tar.gz -O - | tar -xz && \
	mv phpMyAdmin-5.0.2-english /www/phpmyadmin && \
	mkdir /www/phpmyadmin/tmp && \
	chown -R www:www /www/phpmyadmin/tmp

COPY nginx.conf /etc/nginx/nginx.conf
COPY config.inc.php /www/phpmyadmin/config.inc.php
COPY supervisord.conf /etc/supervisord.conf
COPY entrypoint.sh /entrypoint.sh

RUN chmod +x /entrypoint.sh

EXPOSE 5000

CMD ./entrypoint.sh
