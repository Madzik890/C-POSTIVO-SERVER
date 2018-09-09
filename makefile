CC = gcc
PARAMETERS = -o postivoServer -Wall -DWITH_OPENSSL -std=gnu99 -lrt -I./include -L./lib
FILES = ./src/postivoS.c ./src/postivoAPI.c ./src/postivoService.c ./src/serverLogs.c ./src/serverOptions.c ./src/server.c ./src/soap/soapC.c ./src/soap/soapClient.c ./src/soap/soapServer.c ./src/soap/stdsoap2.c
LIBS = -lgsoapssl -lssl -lcrypto -pthread


all:	./src/postivoS.c ./src/postivoAPI.c ./src/postivoService.c ./src/serverLogs.c ./src/serverOptions.c ./src/server.c ./src/soap/soapC.c ./src/soap/soapClient.c ./src/soap/soapServer.c ./src/soap/stdsoap2.c
	$(CC) $(PARAMETERS) $(FILES) $(LIBS)

	
