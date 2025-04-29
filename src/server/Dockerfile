FROM alpine:latest

RUN apk add --no-cache \
        gnupg \
        ca-certificates \
        gcc \
        spawn-fcgi \
        curl

RUN addgroup -S nginx && adduser -S nginx -G nginx

HEALTHCHECK CMD curl --fail http://localhost/ || exit 1

WORKDIR /home/

COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./hello.c .
COPY ./entrypoint.sh .

RUN chmod +x entrypoint.sh && chown -R nginx:nginx /home

USER nginx

ENTRYPOINT ["./entrypoint.sh"]