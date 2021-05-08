# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Dockerfile                                         :+:    :+:             #
#                                                      +:+                     #
#    By: nvan-win <nvan-win@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/13 09:16:45 by nvan-win      #+#    #+#                  #
#    Updated: 2021/02/10 09:51:29 by nvan-win      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FROM    alpine:3.12

RUN     apk update; \
        apk upgrade; \
        apk add libc6-compat

# install Grafana
RUN     wget https://dl.grafana.com/oss/release/grafana-7.3.6.linux-amd64.tar.gz; \
        tar -zxvf grafana-7.3.6.linux-amd64.tar.gz

COPY    /srcs/datasource.yaml /grafana-7.3.6/conf/provisioning/datasources/datasource.yaml

# load dashboards into Grafana from the local filesystem
COPY    /srcs/default.yaml /grafana-7.3.6/conf/provisioning/dashboards/default.yaml
COPY    /srcs/nginx-dashboard.json /grafana-7.3.6/conf/provisioning/dashboards/
COPY    /srcs/mysql-dashboard.json /grafana-7.3.6/conf/provisioning/dashboards/
COPY    /srcs/phpmyadmin-dashboard.json /grafana-7.3.6/conf/provisioning/dashboards/
COPY    /srcs/wordpress-dashboard.json /grafana-7.3.6/conf/provisioning/dashboards/
COPY    /srcs/ftps-dashboard.json /grafana-7.3.6/conf/provisioning/dashboards/
COPY    /srcs/influxdb-dashboard.json /grafana-7.3.6/conf/provisioning/dashboards/
COPY    /srcs/grafana-dashboard.json /grafana-7.3.6/conf/provisioning/dashboards/
COPY    /srcs/telegraf-dashboard.json /grafana-7.3.6/conf/provisioning/dashboards/

EXPOSE  3000

WORKDIR /grafana-7.3.6

CMD     ./bin/grafana-server