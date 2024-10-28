FROM ubuntu:noble

RUN set -ex \
    && apt update \
    && apt -y install build-essential libcppunit-1.15-0 libcppunit-dev libgmock-dev libgtest-dev \
    scons python3-pip python3-git python3-toml python3-pydantic inotify-tools valgrind \
    && apt clean \
    && git config --global --add safe.directory /code

WORKDIR /code
