FROM alpine:3.11.7

RUN apk update && \
	apk add nginx openssl openssh supervisor

RUN mkdir /var/run/nginx && \
	adduser -D -g 'www' www && \
	mkdir /www && \
	chown -R www:www /var/lib/nginx && \
	chown -R www:www /www && \
	adduser -h / -D admin && \
	echo "admin:admin" | chpasswd

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj '/C=NL/ST=Utrecht/O=Codam/CN=ft_services' -keyout /etc/ssl/cert.key -out /etc/ssl/cert.crt

COPY nginx.conf /etc/nginx/nginx.conf
COPY supervisord.conf /etc/supervisord.conf
COPY index.html /www/index.html
COPY sshd_config /etc/ssh/sshd_config
COPY entrypoint.sh /entrypoint.sh
RUN chmod +x ./entrypoint.sh

EXPOSE 80 443 22

CMD ./entrypoint.sh
