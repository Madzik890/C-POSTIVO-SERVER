#ifndef SERVER_H
#define SERVER_H
#include "soap/soapH.h"

/// <global instances>
extern SOAP_SOCKET g_soapSocket;
extern struct soap * g_soap;
/// </global instances>

/// <functions>
void initServer(unsigned long port);
void closeServer();
/// </functions>
/// <thread functions>
void * requestClient(void * argc);

#endif
