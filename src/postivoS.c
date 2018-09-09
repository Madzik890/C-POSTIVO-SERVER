#include "server.h"
#include "postivoAPI.h"
#include "serverLogs.h"
#include "serverOptions.h"
#include <pthread.h>

int main()
{
  createLogs();
  initServer(u_serverPort);
  initPostivoAPI();

  if (soap_valid_socket(g_soapSocket))
  {
    while (soap_valid_socket(soap_accept(g_soap)))
    {
      pthread_t th_connection;
      if(pthread_create(&th_connection, NULL, (void*)requestClient, g_soap))
      {
        printf("Error creating thread\n");
        return 1;
      }

      if(pthread_join(th_connection, NULL))
      {
        printf("Error joining thread\n");
        return 2;
      }

    }
  }

  closePostivoAPI();
  closeServer();
  closeLogs;

  return 0;
}
