package: clean
	rm -rf package.zip
	docker build -t package_builder .
	docker run -d --name package_builder package_builder
	docker cp package_builder:/app/package/package.zip .
	docker container stop package_builder
	@echo "Done building AWS Lambda package in package.zip!"

clean:
	docker system prune -f
	docker rmi -f package_builder
