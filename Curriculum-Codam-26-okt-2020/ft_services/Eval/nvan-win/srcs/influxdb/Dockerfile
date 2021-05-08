# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Dockerfile                                         :+:    :+:             #
#                                                      +:+                     #
#    By: nvan-win <nvan-win@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/28 12:15:57 by nvan-win      #+#    #+#                  #
#    Updated: 2021/01/28 13:54:36 by nvan-win      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FROM    alpine:3.12

RUN     apk update; \
        apk upgrade; \
        apk add influxdb

EXPOSE  8086

CMD     influxd run
