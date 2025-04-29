#!/bin/bash

gcc -o server hello.c -lfcgi
spawn-fcgi -p 8080 ./server

nginx -g 'daemon off;'