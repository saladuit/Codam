FROM alpine:3.11.7

RUN apk update && \
	apk add libc6-compat

RUN wget https://dl.grafana.com/oss/release/grafana-7.2.0.linux-amd64.tar.gz && \
	tar -zxvf grafana-7.2.0.linux-amd64.tar.gz

COPY datasource.yaml /grafana-7.2.0/conf/provisioning/datasources/datasource.yaml
COPY nginx_dashboard.json /grafana-7.2.0/conf/provisioning/dashboards/nginx_dashboard.json
COPY ftps_dashboard.json /grafana-7.2.0/conf/provisioning/dashboards/ftps_dashboard.json
COPY mysql_dashboard.json /grafana-7.2.0/conf/provisioning/dashboards/mysql_dashboard.json
COPY wordpress_dashboard.json /grafana-7.2.0/conf/provisioning/dashboards/wordpress_dashboard.json
COPY phpmyadmin_dashboard.json /grafana-7.2.0/conf/provisioning/dashboards/phpmyadmin_dashboard.json
COPY influxdb_dashboard.json /grafana-7.2.0/conf/provisioning/dashboards/influxdb_dashboard.json
COPY grafana_dashboard.json /grafana-7.2.0/conf/provisioning/dashboards/grafana_dashboard.json
COPY default.yaml /grafana-7.2.0/conf/provisioning/dashboards/default.yaml

EXPOSE 3000

CMD cd grafana-7.2.0 && ./bin/grafana-server
