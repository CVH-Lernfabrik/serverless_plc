#!/bin/bash

# cert_gen.sh
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-05-04
#
# Description: Bash file to create a self-signed x509_v3 server certificate

# Paths
CA_PATH=/home/pi/OPC_UA/opcua/certs/CA
SERVER_PATH=/home/pi/OPC_UA/opcua/certs/server

# Subject
SUBJ_BASE="/C=DE/ST=Germany/L=Heiligenhaus/O=Hochschule Bochum/OU=CVH-Lernfabrik/emailAddress=lukas.friedrichsen@hs-bochum.de"
SUBJ_CA="/CN=OPC_UA_CA_certificate$SUBJ_BASE"
SUBJ_SERVER="/CN=OPC_UA_server_certificate$SUBJ_BASE"

# Generate a temporary file to store the x509_v3 extensions for the server-certificate in since they can't be passed directly via the command line
EXT_TEMP=$(mktemp /tmp/ext_temp.XXX) || { echo "Can't create temporary file!"; exit 1; }
sed -e 's/^.*&&& //' > $EXT_TEMP << EndExtensions
	&&& [ Extensions ]
	&&& basicConstraints=critical,CA:false
	&&& keyUsage=critical,digitalSignature,keyEncipherment
	&&& extendedKeyUsage=serverAuth
	&&& subjectAltName=IP:192.168.1.42,IP:127.0.0.1
EndExtensions

# Remove possible old certificates
echo "Removing possible old certificates!"
sudo rm -f ${CA_PATH}/*
sudo rm -f ${SERVER_PATH}/*

# CA-certificate
echo "Generating CA-certificate!"
sudo openssl req -x509 -sha256 -newkey rsa:4096 -nodes -keyout ${CA_PATH}/private.pem.key -days 3652 -extensions v3_ca -subj "$SUBJ_CA" -out ${CA_PATH}/ca.pem.crt
sudo chmod 400 ${CA_PATH}/private.pem.key
sudo chmod 444 ${CA_PATH}/ca.pem.crt

# Server-certificate CSR
echo "Generating server-certificate CSR!"
sudo openssl req -sha256 -newkey rsa:4096 -nodes -keyout ${SERVER_PATH}/private.pem.key -extensions v3_ca -subj "$SUBJ_SERVER" -out ${SERVER_PATH}/certificate.pem.csr
sudo chmod 400 ${SERVER_PATH}/private.pem.key

# Sign server-certificate CSR
echo "Signing server-certificate CSR with the generated CA-certificate!"
sudo openssl x509 -req -in ${SERVER_PATH}/certificate.pem.csr -CA ${CA_PATH}/ca.pem.crt -CAkey ${CA_PATH}/private.pem.key -CAcreateserial -days 3652 -extfile $EXT_TEMP -extensions Extensions -out ${SERVER_PATH}/certificate.pem.crt
sudo chmod 444 ${SERVER_PATH}/certificate.pem.crt

# Clean up
sudo rm -f ${CA_PATH}/ca.srl
sudo rm -f ${SERVER_PATH}/certificate.pem.csr
rm $EXT_TEMP
