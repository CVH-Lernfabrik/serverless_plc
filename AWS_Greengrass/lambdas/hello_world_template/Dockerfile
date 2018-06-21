# Use an official Node.js runtime as a parent image
FROM node:6.14.2-slim

# Set the working directory to /app
WORKDIR /app

# Install all necessary packages
RUN apt-get update
RUN apt-get install zip -y

# Create the package directory
RUN mkdir -p package/

# Copy the requirements for the Lambda function into the container at /app/package
COPY package.json /app/package

# Install the necessary dependencies and copy local resources
RUN npm install --prefix ./package
COPY aws-greengrass-core-sdk /app/package/
COPY src/* /app/package/

# Zip all dependencies
RUN cd package; zip -r package.zip . -x \*.git\* \*env\* *.zip

# Docker container will be inactive, yet reachable after hosting it so that the
# dependencies can be extracted to the local machine in this time
CMD ["sleep", "100"]
