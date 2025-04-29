# Simple Docker

## Part 1. Готовый докер

В качестве конечной цели своей небольшой практики ты сразу выбрал написание докер-образа для собственного веб-сервера, а потому в начале тебе нужно разобраться с уже готовым докер-образом для сервера.
Твой выбор пал на довольно простой **nginx**.

**== Задание ==**

##### Возьми официальный докер-образ с **nginx** и выкачай его при помощи `docker pull`.
![sudo_docker_pull_nginx](/src/pictures/1.1.png)
##### Проверь наличие докер-образа через `docker images`.
![sudo_docker_images](/src/pictures/1.2.png)
##### Запусти докер-образ через `docker run -d [image_id|repository]`.
##### Проверь, что образ запустился через `docker ps`.
![sudo_docker_run_d](/src/pictures/1.3.png)
##### Посмотри информацию о контейнере через `docker inspect [container_id|container_name]`.
![sudo_docker_inspect](/src/pictures/1.4.png)
##### По выводу команды определи и помести в отчёт размер контейнера, список замапленных портов и ip контейнера.
![sudo_docker_inspect+](/src/pictures/1-5.png)
##### Останови докер контейнер через `docker stop [container_id|container_name]`.
##### Проверь, что контейнер остановился через `docker ps`.
![sudo_docker_stop](/src/pictures/1.5.png)
##### Запусти докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду *run*.
##### Проверь, что в браузере по адресу *localhost:80* доступна стартовая страница **nginx**.
![sudo_docker_run_d_p_80:80_p_443:443_nginx](/src/pictures/1.6.jpg)
##### Перезапусти докер контейнер через `docker restart [container_id|container_name]`.
##### Проверь любым способом, что контейнер запустился.
![sudo_docker_restart](/src/pictures/1.7.png)

## Part 2. Операции с контейнером

##### Прочитай конфигурационный файл *nginx.conf* внутри докер контейнера через команду *exec*.
![sudo_docker_exec_](/src/pictures/2.1.png)

##### Создай на локальной машине файл *nginx.conf*.
##### Настрой в нем по пути */status* отдачу страницы статуса сервера **nginx**.
![nginx_conf](/src/pictures/2.2.png)
![nginx_conf1](/src/pictures/2.2.1.png)
##### Скопируй созданный файл *nginx.conf* внутрь докер-образа через команду `docker cp`.
![sudo_docker_cp](/src/pictures/2.3.png)
##### Перезапусти **nginx** внутри докер-образа через команду *exec*.
![sudo_docker_exec_nginx_reload](/src/pictures/2.4.png)
##### Проверь, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**.
![localhost/status](/src/pictures/2.5.png)
##### Экспортируй контейнер в файл *container.tar* через команду *export*.
![docker_tar](/src/pictures/2.5.1.png)
##### Останови контейнер.
![sudo_docker_stop](/src/pictures/2.5.2.png)
##### Удали образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры.
![sudo_docker_rmi](/src/pictures/2.6.png)
##### Удали остановленный контейнер.
![sudo_docker_rm](/src/pictures/2.7.png)
##### Импортируй контейнер обратно через команду *import*.
##### Запусти импортированный контейнер.
![import](/src/pictures/2.8.png)
##### Проверь, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**.
![localhost:80/status](/src/pictures/2.9.png)

## Part 3. Мини веб-сервер

##### Напиши мини-сервер на **C** и **FastCgi**, который будет возвращать простейшую страничку с надписью `Hello World!`.
![hello.c](/src/pictures/3.0.png)
##### Напиши свой *nginx.conf*, который будет проксировать все запросы с 81 порта на *127.0.0.1:8080*.
![nginx_conf_part2](/src/pictures/3.2.png)
##### Проверь, что в браузере по *localhost:81* отдается написанная тобой страничка.
![localhost:81](/src/pictures/3.3.png)
![localhost:82](/src/pictures/3.4.png)
![localhost:83](/src/pictures/3.5.png)
![localhost:84](/src/pictures/3.6.png)
![localhost:85](/src/pictures/3.7.png)
![localhost:86](/src/pictures/3.8.png)
![localhost:87](/src/pictures/3.9.png)
![HelloWorld!](/src/pictures/EEE.png)

## Part 4. Свой докер

#### Напиши свой докер-образ, который:
##### 1) собирает исходники мини сервера на FastCgi из [Части 3](#part-3-мини-веб-сервер);
##### 2) запускает его на 8080 порту;
##### 3) копирует внутрь образа написанный *./nginx/nginx.conf*;
##### 4) запускает **nginx**.
![Dockerfile](/src/pictures/4.0.png)
##### Собери написанный докер-образ через `docker build` при этом указав имя и тег.
##### Проверь через `docker images`, что все собралось корректно.
![sudo_docker_build](/src/pictures/4.1.png)
##### Запусти собранный докер-образ с маппингом 81 порта на 80 на локальной машине и маппингом папки *./nginx* внутрь контейнера по адресу, где лежат конфигурационные файлы **nginx**'а (см. [Часть 2](#part-2-операции-с-контейнером)).
##### Проверь, что по localhost:80 доступна страничка написанного мини сервера.
![sudo_docker_run](/src/pictures/4.2.png)
##### Допиши в *./nginx/nginx.conf* проксирование странички */status*, по которой надо отдавать статус сервера **nginx**.
![and_also_new_nginx](/src/pictures/4.3.png)
##### Перезапусти докер-образ.
*Если всё сделано верно, то, после сохранения файла и перезапуска контейнера, конфигурационный файл внутри докер-образа должен обновиться самостоятельно без лишних действий*.
##### Проверь, что теперь по *localhost:80/status* отдается страничка со статусом **nginx**
![new_localhost/status](/src/pictures/4.4.png)

## Part 5. **Dockle**

##### Просканируй образ из предыдущего задания через `dockle [image_id|repository]`.
![sudo_dockle](/src/pictures/5.1.png)
##### Исправь образ так, чтобы при проверке через **dockle** не было ошибок и предупреждений.
![sudo_dockle_bb](/src/pictures/5.2.png)
![new_Dockerfile](/src/pictures/5.3.png)

## Part 6. Базовый **Docker Compose**

##### Напиши файл *docker-compose.yml*, с помощью которого:
##### 1) Подними докер-контейнер из [Части 5](#part-5-инструмент-dockle) _(он должен работать в локальной сети, т. е. не нужно использовать инструкцию **EXPOSE** и мапить порты на локальную машину)_.
##### 2) Подними докер-контейнер с **nginx**, который будет проксировать все запросы с 8080 порта на 81 порт первого контейнера.
##### Замапь 8080 порт второго контейнера на 80 порт локальной машины.
![entrypoint.sh](/src/pictures/6.4.png)
![nginx_confff](/src/pictures/6.5.png)
![docker-compose.yml](/src/pictures/6.6.png)

##### Собери и запусти проект с помощью команд `docker-compose build` и `docker-compose up`.
![docker-compose_build](/src/pictures/6.1.png)
![docker-compose_up](/src/pictures/6.2.png)
##### Проверь, что в браузере по *localhost:80* отдается написанная тобой страничка, как и ранее.
![end](/src/pictures/6.3.png)
