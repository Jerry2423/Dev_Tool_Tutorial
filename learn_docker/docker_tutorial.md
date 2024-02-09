## Docker Tutorial

### Basic Commands

- Run - start a new container: `docker run`
    - `-d`: detatch mode (run in back end)
    - `-e`: set environment variables, e.g. `-e MY_VAR=my_value`
    - `-p`: port mapping, e.g. `-p 8080:80` (host:container)
    - `-v`: volume mapping, e.g. `-v /host/path:/container/path`
    - `--name`: name the container
    - `--rm`: remove the container after it stops
    - `-it`: interactive mode

- Stop - stop a running container: `docker stop`

- ps - list running containers: `docker ps`
    - `-a`: list all containers

- rm - remove a container: `docker rm`

- rmi - remove an image: `docker rmi`

- images - list images: `docker images`

- pull - pull an image from a registry: `docker pull`

- push - push an image to a registry: `docker push /username/repo:tag`
    - `docker login`: log in to a registry
    - `docker logout`: log out of a registry
    - `docker tag`: tag an image, use **`:`** to specify a version or name (e.g. `docker tag my-image:latest my-image:1.0`)

- exec - run a command **in** a running container: `docker exec container_name command`

- Append a command: `docker run container_name command`

- Inspect - get detailed information about a container: `docker inspect container_name`

### Images

- Dockerfile: a file that contains instructions for building an image
    - `FROM`: base image
    - `RUN`: run a command
    - `COPY`: copy files from the host to the container
    - `WORKDIR`: set the working directory
    - `CMD`: default command to run when the container starts, but can be overridden
    - `ENTRYPOINT`: default command to run when the container starts
    - `EXPOSE`: expose a port
    - `ENV`: set environment variables
    - `VOLUME`: create a volume
    - `USER`: set the user

- Build an image: `docker build -t image_name .`

- Dockerfile example:
    ```Dockerfile
    FROM python:3.7 // base image
    WORKDIR /app
    RUN pip install -r requirements.txt // RUN a command
    COPY . /app
    CMD ["python", "app.py"] // command and parameters should be separated in a list
    ```

- CMD vs ENTRYPOINT:
    - `CMD`: default command to run when the container starts, but can be **overridden**
    - `ENTRYPOINT`: default command to run when the container starts, can append parameters in `docker run container_name appended_command`

### Images and Containers
- Containers are instances of images
- Images are blueprint. A running container uses an isolated **filesystem**. This isolated filesystem is provided by an image, and the image must contain everything needed to run an application - all dependencies, configurations, scripts, binaries, etc. The image also contains other configurations for the container, such as environment variables, a default command to run, and other metadata.
- We can have different containers running from the **same image**, and each container can have different configurations, such as environment variables, volumes, and network settings.
