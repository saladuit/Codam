# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Dockerfile                                         :+:    :+:             #
#                                                      +:+                     #
#    By: nvan-win <nvan-win@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/27 10:06:38 by nvan-win      #+#    #+#                  #
#    Updated: 2021/02/09 15:46:23 by nvan-win      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FROM    alpine:3.12

LABEL	maintainer="Nina van Winden <nvan-win@student.codam.nl>"

# install packages
RUN		apk update; \
        apk add vsftpd; \
        apk add openssl

# SSL
RUN		openssl req -x509 -days 365 -newkey rsa:2048 -nodes -sha256 \
		-out /etc/ssl/certs/vsftpd.crt \
		-keyout	/etc/ssl/private/vsftpd.key \
		-subj "/C=NL/ST=NH/L=Amsterdam/O=Codam/CN=ftps-svc"; \
		chmod 775 /etc/ssl/private/vsftpd.key; \
		chmod 775 /etc/ssl/certs/vsftpd.crt

# vsftpd config file
COPY	/srcs/vsftpd.conf /etc/vsftpd/vsftpd.conf

RUN		mkdir -p /var/ftps; \
		adduser -D user -h var/ftps; \
		echo "user:password" | chpasswd

COPY    /srcs/startup.sh /tmp/startup.sh
RUN     chmod +x /tmp/startup.sh

EXPOSE  20 21 21000

CMD     ./tmp/startup.sh