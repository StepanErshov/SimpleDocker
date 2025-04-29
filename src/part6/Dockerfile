FROM nginx

RUN useradd -ms /bin/bash appuser

WORKDIR /home/

COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./hello.c .
COPY ./entrypoint.sh .

RUN chmod +x entrypoint.sh && apt update && apt install -y gcc spawn-fcgi libfcgi-dev && rm -rf /var/lib/apt/lists/* && chown -R appuser:appuser /home

USER appuser
  	
ENTRYPOINT ["./entrypoint.sh"] 