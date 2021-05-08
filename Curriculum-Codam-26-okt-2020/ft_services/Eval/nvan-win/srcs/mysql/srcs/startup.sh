/usr/bin/mysql_install_db --user=mysql --ldata=/var/lib/mysql

echo "CREATE DATABASE IF NOT EXISTS $DB_NAME;" >> /tmp/wpdb.sql
echo "CREATE USER '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS';" >> /tmp/wpdb.sql
echo "GRANT ALL ON *.* TO '$DB_USER'@'%' IDENTIFIED BY '$DB_PASS' WITH GRANT OPTION;" >> /tmp/wpdb.sql
echo "DROP DATABASE test;" >> /tmp/wpdb.sql
echo "FLUSH PRIVILEGES;" >> /tmp/wpdb.sql

cat /tmp/create_tables.sql >> /tmp/wpdb.sql

/usr/bin/mysqld --user=mysql --init_file=/tmp/wpdb.sql