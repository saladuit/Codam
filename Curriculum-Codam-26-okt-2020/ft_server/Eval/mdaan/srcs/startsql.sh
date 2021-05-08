service mysql start

# Configure a wordpress database
echo "CREATE DATABASE wordpress;" | mysql -u root
echo "CREATE USER 'maria'@'localhost';" | mysql -u root
echo "SET PASSWORD FOR 'maria'@'localhost' = PASSWORD('password');" | mysql -u root
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'maria'@'localhost' IDENTIFIED BY 'password';" | mysql -u root
echo "FLUSH PRIVILEGES;" | mysql -u root
