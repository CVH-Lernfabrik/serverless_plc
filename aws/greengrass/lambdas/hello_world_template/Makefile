package: clean
	rm -rf package.zip
	cp -a ../aws-greengrass-core-sdk .
	docker build -t package_builder .
	docker run -d --name package_builder package_builder
	docker cp package_builder:/app/package/package.zip .
	docker container stop package_builder
	@echo "Done building AWS Lambda package in package.zip!"

clean:
	rm -rf aws-greengrass-core-sdk
	docker system prune -f
	bash -c "if docker images | grep package_builder; then docker rmi -f package_builder; fi"
