FROM alpine:3.11.7

RUN apk update && \
	apk add influxdb

EXPOSE 8086

CMD influxd run
