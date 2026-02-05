all:
	@mkdir -p /home/alpelliz/data/volume_mariadb
	@mkdir -p /home/alpelliz/data/volume_nginx
	@sh -c -e "echo '127.0.0.1 alpelliz.42.fr' >> /etc/hosts";
	@sh -c -e "echo '127.0.0.1 www.alpelliz.42.fr' >> /etc/hosts";
	@docker-compose -f srcs/docker-compose.yml up -d --build

down:
	@docker-compose -f srcs/docker-compose.yml down

clean: down
	@docker system prune -af
	@docker network prune -f

fclean: clean
	@docker volume remove srcs_volume_mariadb srcs_volume_nginx
	@rm -rf /home/alpelliz/data/volume_mariadb
	@rm -rf /home/alpelliz/data/volume_nginx
	@sed -i '/alpelliz.42.fr/d' /etc/hosts
	@sed -i '/www.alpelliz.42.fr/d' /etc/hosts
	
re: clean all
.PHONY: all down re clean