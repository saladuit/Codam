#!/bin/sh
APISERVER=https://kubernetes.default.svc
SERVICEACCOUNT=/var/run/secrets/kubernetes.io/serviceaccount
TOKEN=$(cat ${SERVICEACCOUNT}/token)
CACERT=${SERVICEACCOUNT}/ca.crt
URL=$(curl --cacert ${CACERT} --header "Authorization: Bearer ${TOKEN}" -X GET ${APISERVER}/api/v1/namespaces/default/services/wordpress/ 2>/dev/null| jq -r '.status | .loadBalancer | .ingress | .[] | .ip')
if [ ! -d "/www/wordpress" ]
then
    mkdir -p /www/wordpress
    cd /www/wordpress
    wp core download
    wp config create --dbname=wordpress --dbuser=mysql --dbpass=mysql --dbhost=mysql
    wp db create
    wp core install --url=${URL}:5050 --title=Wordpress --admin_user=admin --admin_password=admin --admin_email=yeet@example.com --skip-email
    wp user create user1 user1@example.com --user_pass=pass --role=subscriber
    wp user create user2 user2@example.com --user_pass=pass --role=subscriber
    wp user create editor1 editor1@example.com --user_pass=pass --role=editor
    chown -R www:www /www
fi
/usr/bin/supervisord -c /etc/supervisord.conf
