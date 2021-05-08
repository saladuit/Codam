FROM alpine:3.11.7

RUN apk update && \
    apk add vsftpd openssl jq

RUN mkdir -p /etc/ssl/keys && \
    mkdir -p /etc/ssl/certs && \
    openssl req -x509 -newkey rsa:4096 -keyout /etc/ssl/keys/localhost.key -out /etc/ssl/certs/localhost.pem -days 365 -subj "/C=NL/ST=North Holland/L=Amsterdam/O=Codam/OU=Codam/CN=localhost" -nodes

COPY vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY entrypoint.sh /etc/vsftpd/entrypoint.sh
RUN chmod +x /etc/vsftpd/entrypoint.sh

EXPOSE 20 21 21000 21001

ENTRYPOINT /etc/vsftpd/entrypoint.sh