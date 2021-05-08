FROM alpine:3.11.7

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.13.3-static_linux_amd64.tar.gz && \
	tar -C . -xzf telegraf-1.13.3-static_linux_amd64.tar.gz && \
	chmod +x telegraf/telegraf && \
	cp telegraf/telegraf /usr/bin/

COPY telegraf.conf /etc/telegraf/telegraf.conf

EXPOSE 8125

CMD telegraf
