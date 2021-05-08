#!/bin/sh
mkdir -p /usr/share/ftps/data
deluser admin
echo -e "admin\nadmin" | adduser -h /usr/share/ftps/data admin
chown admin:admin /usr/share/ftps/data
/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf