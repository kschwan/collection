build_container:
	docker-compose build container

app:
	docker-compose run container /bin/bash -c "/usr/bin/scons -j `nproc` && /code/collection"

test:
	docker-compose run container /bin/bash -c "/usr/bin/scons -j `nproc` && /code/collection-test"

clean:
	docker-compose run container /usr/bin/scons -c
