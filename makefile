CC = gcc
PARAMETERS = -o postivoServer -Wall -DWITH_OPENSSL -std=gnu99 -lrt -I./include -L./lib
HTTP = ./src/postivoS.c ./src/postivoAPI.c ./src/postivoService.c ./src/serverLogs.c ./src/serverOptions.c ./src/server.c ./src/soap/soapC.c ./src/soap/soapClient.c ./src/soap/soapServer.c ./src/soap/stdsoap2.c
HTTPS = ./src/postivoS.c ./src/postivoAPI.c ./src/postivoService.c ./src/serverLogs.c ./src/serverOptions.c ./src/server.c ./src/soapSSL/soapC.c ./src/soapSSL/soapClient.c ./src/soapSSL/soapServer.c ./src/soapSSL/stdsoap2.c
LIBS = -lgsoapssl -lssl -lcrypto -pthread


wossl:	$(HTTP)
	$(CC) $(PARAMETERS) $(HTTP) $(LIBS)
	
ssl:	$(HTTPS)
	$(CC) $(PARAMETERS) $(HTTPS) $(LIBS)

	
