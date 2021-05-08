FROM alpine:3.11.7

RUN apk update && \
	apk add nginx sudo mysql-client jq curl supervisor && \
	apk add php7 php7-fpm php7-opcache php7-common php7-curl php7-json php7-mbstring php7-xml php7-zip php7-gd php7-soap php7-tokenizer php7-dom php7-exif php7-fileinfo php7-mysqli php7-zlib php7-phar

RUN mkdir /var/run/nginx && \
	mkdir -p /www && \
	adduser -D -g 'www' www && \
	chown -R www:www /var/lib/nginx

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

COPY nginx.conf /etc/nginx/nginx.conf
COPY php-fpm.conf /etc/php7/php-fpm.conf
COPY supervisord.conf /etc/supervisord.conf
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x /entrypoint.sh

EXPOSE 5050

CMD ./entrypoint.sh