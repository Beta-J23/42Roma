#FROM debian:buster

##RUN commands at container's build process:
##update all packages of apt (---The flag -y allow to automatically reply yes at questions posed by the program---)
#RUN apt update -y && apt upgrade -y
##install nginx
#RUN apt install nginx -y
##install openssl
#RUN apt show openssl
#RUN apt install openssl -y
##install my utilities
##RUN apt install vim -y
##folder where we will store the SSL certificate and the private key
#RUN mkdir -p /etc/nginx/ssl
##folder to store the config files of nginx  
#RUN mkdir -p /var/run/nginx

##modify permissions of folders
#RUN chmod 755 /var/www/html

#RUN chown -R www-data:www-data /var/www/html

#COPY conf/nginx.conf /etc/nginx/nginx.conf

#RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=login.42.fr/UID=login"

##COPY tools/certificate_script.sh certificate_script.sh

##CMD ["bash" "/certificate_script.sh"] [ "nginx", "-g", "daemon off;" ]

#EXPOSE 443

#CMD [ "nginx", "-g", "daemon off;" ]

FROM debian:buster
#update all packages of apt (---The flag -y allow to automatically reply yes at questions posed by the program, -qq do not show the output---)
RUN apt update -y -qq &&\
    apt upgrade -y -qq &&\
    apt install -y -qq nginx openssl && \
    apt-get clean && rm -r /var/lib/apt/lists/*
#Copy nginx configuration file personalizzato
COPY conf/nginx.conf /etc/nginx/conf.d/default.conf
RUN mkdir -p /run/nginx
RUN mkdir /etc/nginx/ssl
# Create a self-signed certificate without password
RUN openssl req -x509 -nodes -days 365 \
    -newkey rsa:2048 -keyout /etc/nginx/ssl/chiave.key \
    -out /etc/nginx/ssl/certificato.crt \
    -subj "/C=IT/L=RM/O=42_Roma/OU=alpelliz/CN=alpelliz"
EXPOSE 443
CMD ["nginx", "-g", "daemon off;"]