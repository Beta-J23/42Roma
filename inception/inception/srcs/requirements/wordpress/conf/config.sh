#!/bin/sh
rm -rf /var/www/html/wordpress/wp-config.php
wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost="mariadb" --path="/var/www/html/wordpress/" --allow-root --skip-check
wp config set WP_CACHE true --raw --allow-root;
wp config set WP_CACHE_KEY_SALT alpelliz.42.fr --allow-root;
if ! wp core is-installed --allow-root; then
    wp core install --url="alpelliz.42.fr" --title="alpelliz's wordpress site" --admin_user="alpelliz" --admin_password="1234" --admin_email="youremail@gmail.com" --path="/var/www/html/wordpress/" --allow-root
fi
if ! wp user get Estriper --allow-root; then
    wp user create Estriper Estriper@cago.fr --role=author --user_pass="asdf" --allow-root
fi
chown -R www-data:www-data /var/www/html/wordpress
exec php-fpm7.3 --nodaemonize

#sleep 10

#wp config create	--allow-root \
#					--dbname=$SQL_DATABASE \
#					--dbuser=$SQL_USER \
#					--dbpass=$SQL_PASSWORD \
#					--dbhost=mariadb:3306 --path='/var/www/wordpress'