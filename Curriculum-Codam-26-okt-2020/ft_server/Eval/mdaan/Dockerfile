# OS for container
FROM	debian:buster

# Copy all sources into root folder
COPY	srcs/. /root/
COPY	srcs/autoindex.sh .

# Updates
RUN		apt-get update
RUN		apt-get upgrade -y
RUN		apt-get -y install wget

# Required packages
RUN		apt-get -y install nginx
RUN		apt-get -y install mariadb-server
RUN		apt-get -y install php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

# SSL certificate
RUN		openssl req -x509 -nodes -days 1024 -subj "/C=NL/ST=Noord-Holland/L=Amsterdam/O=CODAM/CN=localhost" -newkey rsa:2048 -keyout /etc/ssl/private/maria.key -out /etc/ssl/certs/maria.crt;

# Move homepage to right location
RUN		mv /root/index.html /var/www/html
RUN		mv /root/nginx.conf /etc/nginx/sites-enabled
RUN		rm -rf /etc/nginx/sites-enabled/default
RUN		rm -rf /etc/nginx/sites-available/default

# Configure MySQL and make database called wordpress
RUN		bash /root/startsql.sh

# Install and configure Wordpress
RUN		wget -c -P ./tmp/ https://wordpress.org/latest.tar.gz
RUN		tar -xvzf ./tmp/latest.tar.gz -C /var/www/html
RUN		mv /root/wp-config.php /var/www/html/wordpress/wp-config.php
RUN		service mysql start && \
		wget -c -P ./tmp/ https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
		chmod +x ./tmp/wp-cli.phar && \
		mv ./tmp/wp-cli.phar /usr/local/bin/wp && \
		wp core install --path='/var/www/html/wordpress' --allow-root --url="/"  --title="Welcome to my empty blog!!" --admin_user="maria" --admin_password="password" --admin_email="mariadaan@gmail.com" && \
		mysql -e "USE wordpress;UPDATE wp_options SET option_value='https://localhost/wordpress' WHERE option_name='siteurl' OR option_name='home';"

# Install and configure PHPMyAdmin
RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-english.tar.gz
RUN		tar xzfv phpMyAdmin-5.0.4-english.tar.gz -C /root
RUN		mkdir /var/www/html/phpmyadmin
RUN		cp -a /root/phpMyAdmin-5.0.4-english/. /var/www/html/phpmyadmin/
RUN		rm -rf /root/phpMyAdmin-5.0.4-english
RUN		rm -rf phpMyAdmin-5.0.4-english.tar.gz
RUN		mv /root/config.inc.php /var/www/html/phpmyadmin

# Grant permissions and access
RUN		chown -R www-data:www-data /var/www/*
RUN		chmod -R 755 /var/www/*
RUN		chmod 775 autoindex.sh

# Start services
CMD		service mysql restart && service php7.3-fpm start && nginx -g 'daemon off;'

EXPOSE	80 443
