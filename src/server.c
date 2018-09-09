#include "server.h"

/// <global instances>
SOAP_SOCKET g_soapSocket;
struct soap * g_soap = NULL;
/// </global instances>

/// <summary>
/// Prepare the "g_soap", to work with users.
/// </summary>
/// <param name = "port"> The server port </param>
void initServer(unsigned long port)
{
  printf("Started initing the server.\n");
  g_soap = soap_new1(SOAP_C_UTFSTRING | SOAP_XML_INDENT | SOAP_ENC_SSL | SOAP_XML_TREE);//create soap
  g_soap->accept_timeout = 24*60*60;             /* quit after 24h of inactivity (optional) */
  g_soap->send_timeout = g_soap->recv_timeout = 5; /* max send and receive socket inactivity time (sec) */
  g_soap->transfer_timeout = 10;                 /* max time for send or receive of messages (sec) */
  g_soapSocket = soap_bind(g_soap, NULL, port, 100);
  printf("Server started.\n");
  printf("Server is working on port:%d\n",port);
}

/// <summary>
/// Shutdown server.
/// </summary>
void closeServer()
{
  soap_destroy(g_soap); /* delete deserialized objects */
  soap_end(g_soap);     /* delete heap and temp data */
  soap_free(g_soap);    /* we're done with the context */
}

void * requestClient(void * argc)
{
  struct soap * m_soap = (struct soap *)argc;
  printf("User connected\n");
  if(m_soap != NULL)
  {
    soap_serve(m_soap);   /* serve request, ignoring failures */
    soap_destroy(m_soap); /* delete deserialized objects */
    soap_end(m_soap);     /* delete heap and temp data */
  }

  return NULL;
}
