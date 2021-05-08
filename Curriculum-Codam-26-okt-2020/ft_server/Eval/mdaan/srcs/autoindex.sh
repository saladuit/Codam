if [ "$1" = "off" ]; then
	sed -i 's/autoindex	on/autoindex off/' /etc/nginx/sites-enabled/nginx.config
	service nginx restart
	echo "autoindex off"
elif [ "$1" = "on" ]; then
	sed -i 's/autoindex off/autoindex on/' /etc/nginx/sites-enabled/nginx.config
	service nginx restart
	echo "autoindex on"
fi