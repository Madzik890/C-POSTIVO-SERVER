/*
 * Postivo API is section create for make "mirror server".
 * The prefix "post" means "postivo".
 */
#include "postivoAPI.h"
#include "serverLogs.h"


/// <global instances>
struct soap * g_soapAPI = NULL;
/// <global instances>

/// <summary>
/// Prepare the "g_soap", to work with the Postivo API.
/// </summary>
void initPostivoAPI()
{
  g_soapAPI = soap_new1(SOAP_C_UTFSTRING | SOAP_XML_INDENT | SOAP_ENC_SSL | SOAP_XML_TREE);//create soap
  soap_ssl_init();//init SSL
  writeLogs("Init the SSL.");
  soap_init(g_soapAPI);//init soap lib
  writeLogs("Init the SOAP.");

  soap_set_imode(g_soapAPI, SOAP_C_UTFSTRING); //input
  soap_set_omode(g_soapAPI, SOAP_C_UTFSTRING); //output?
  if (soap_ssl_server_context(g_soapAPI, SOAP_SSL_NO_AUTHENTICATION, NULL, NULL, NULL, NULL, NULL, NULL, NULL))//init SSL with no AUTHENTICATION
  {
    soap_print_fault(g_soapAPI, stderr);//print error
    exit(1);//exit because without ssl, cannot connect to HTTPS
  }
}

/// <summary>
/// Releasing memory.
/// </summary>
void closePostivoAPI()
{
  writeLogs("Close the SOAP.");
  soap_end(g_soapAPI);     // delete deserialized temp data
  soap_destroy(g_soapAPI); // delete deserialized data
  soap_free(g_soapAPI); // free context
}


/// <summary>
/// Creates a dispatch, using a information which sent user.
/// Sends a result to user.
/// Saves logs of whole operation.
/// </summary>
/// <param name = soap> User connection. </param>
/// <param name = login> User login. </param>
/// <param name = api_USCOREpass> User password. </param>
/// <param name = "msg_USCOREtype"> Type of dispatch. </param>
/// <param name = "document_USCOREfiles"> Array of documents, encoded in BASE64. </param>
/// <param name = "recipients"> Array of recipients. </param>
/// <param name = "options"> Additional options. </param>
/// <param name = "_param_1"> The result of connections. </param>
void postDispatch( char *login, char *api_USCOREpass, char *msg_USCOREtype, struct ArrayOfDocumentFiles *document_USCOREfiles, struct ArrayOfRecipients *recipients, struct ArrayOfOptions *options, struct ns2__dispatchResponse *_param_1)
{
  struct ns2__dispatchResponse m_dispatchStatus;
  if(soap_call_ns2__dispatch(g_soapAPI, NULL, NULL, login, api_USCOREpass, msg_USCOREtype, document_USCOREfiles, recipients , options, &m_dispatchStatus) == SOAP_OK)//try execute the soap method
  {
    (*_param_1) = m_dispatchStatus;
  }
  else
    soap_print_fault(g_soapAPI, stderr);//print error
}

/// <summary>
/// Gets a results and sends it to the user.
/// Saves logs of whole operation.
/// </summary>
/// <param name = soap> User connection. </param>
/// <param name = login> User login. </param>
/// <param name = api_USCOREpass> User password. </param>
/// <param name = dispatch_USCOREids"> IDs of dispatchs. </param>
/// <param name = "_param_1"> The result of connections. </param>
void postGetDispatchStatus(char *login, char *api_USCOREpass, struct ArrayOfDispatchIds *dispatch_USCOREids, struct ns2__getDispatchStatusResponse *_param_1)
{
  struct ns2__getDispatchStatusResponse m_dispatchStatus;
  if(soap_call_ns2__getDispatchStatus(g_soapAPI, NULL, NULL, login, api_USCOREpass, dispatch_USCOREids, &m_dispatchStatus) == SOAP_OK)
  {
    (*_param_1) = m_dispatchStatus;
  }
  else
    soap_print_fault(g_soapAPI, stderr);//print error
}

/// <summary>
/// Gets a balance of the user account.
/// Saves logs of whole operation.
/// </summary>
/// <param name = soap> User connection. </param>
/// <param name = login> User login. </param>
/// <param name = api_USCOREpass> User password. </param>
/// <param name = "_param_1"> The result of connections. </param>
void postGetBalance(char *login, char *api_USCOREpass, struct ns2__getBalanceResponse *_param_1)
{
  struct ns2__getBalanceResponse m_balanceStatus;//object which is returning in the SOAP function

  if(soap_call_ns2__getBalance(g_soapAPI, NULL, NULL, login, api_USCOREpass, &m_balanceStatus) == SOAP_OK)//try execute the soap method
  {
    (*_param_1) = m_balanceStatus;
  }
  else
    soap_print_fault(g_soapAPI, stderr);//print error*/
}

/// <summary>
/// Gets a price of shipping.
/// Saves logs of whole operation.
/// </summary>
/// <param name = soap> User connection. </param>
/// <param name = login> User login. </param>
/// <param name = api_USCOREpass> User password. </param>
/// <param name = "msg_USCOREtype"> Type of dispatch. </param>
/// <param name = "document_USCOREfiles"> Array of documents, encoded in BASE64. </param>
/// <param name = "recipients"> Array of recipients. </param>
/// <param name = "options"> Additional options. </param>
/// <param name = "_param_1"> The result of connections. </param>
void postGetPrice(char *login, char *api_USCOREpass, char *msg_USCOREtype, struct ArrayOfDocumentFiles *document_USCOREfiles, struct ArrayOfRecipients *recipients, int config_USCOREid, struct ns2__getPriceResponse *_param_1)
{
  struct ns2__getPriceResponse m_priceStatus;
  if(soap_call_ns2__getPrice(g_soapAPI, NULL, NULL, login, api_USCOREpass, msg_USCOREtype, document_USCOREfiles, recipients, config_USCOREid, &m_priceStatus) == SOAP_OK)
  {
    (*_param_1) = m_priceStatus;
  }
  else
    soap_print_fault(g_soapAPI, stderr);//print error*/
}

/// <summary>
/// Gets config profiles from user account.
/// Saves logs of whole operation.
/// </summary>
/// <param name = soap> User connection. </param>
/// <param name = login> User login. </param>
/// <param name = "api_USCOREpass"> User password. </param>
/// <param name = "msg_USCOREtype"> Type of dispatch. </param>
/// <param name = "_param_1"> Array of config profiles. </param>
void postGetConfigProfiles(char *login, char *api_USCOREpass, char *msg_USCOREtype, struct ns2__getConfigProfilesResponse *_param_1)
{
  struct ns2__getConfigProfilesResponse m_configProfilesStatus;
  if(soap_call_ns2__getConfigProfiles(g_soapAPI, NULL, NULL, login, api_USCOREpass, msg_USCOREtype, &m_configProfilesStatus) == SOAP_OK)
  {
    (*_param_1) = m_configProfilesStatus;
  }
  else
    soap_print_fault(g_soapAPI, stderr);

}

/// <summary>
/// Gets senders from the user account.
/// Saves logs of whole operation.
/// </summary>
/// <param name = "soap"> User connection. </param>
/// <param name = "login"> User login. </param>
/// <param name = "api_USCOREpass"> User password. </param>
/// <param name = "_param_1"> Array of sendes. </param>
void postGetSenders(char *login, char *api_USCOREpass, struct ns2__getSendersResponse *_param_1)
{
  struct ns2__getSendersResponse m_sendersStatus;
  if(soap_call_ns2__getSenders(g_soapAPI, NULL, NULL, login, api_USCOREpass, &m_sendersStatus) == SOAP_OK)
  {
    (*_param_1) = m_sendersStatus;
  }
  else
    soap_print_fault(g_soapAPI, stderr);
}

/// <summary>
/// Gets certificates of the user account.
/// Saves logs of whole operation.
/// </summary>
/// <param name = soap> User connection. </param>
/// <param name = login> User login. </param>
/// <param name = "api_USCOREpass"> User password. </param>
/// <param name = "dispatch_USCOREid"> Dispatch id. </param>
/// <param name = "_param_1"> Result of connection. </param>
void postGetCertificate(char *login, char *api_USCOREpass, char *dispatch_USCOREid, int certificate_USCOREtype, struct ns2__getCertificateResponse *_param_1)
{
  struct ns2__getCertificateResponse m_certificateStatus;
  if(soap_call_ns2__getCertificate(g_soapAPI, NULL, NULL, login, api_USCOREpass, dispatch_USCOREid, certificate_USCOREtype, &m_certificateStatus) == SOAP_OK)
  {
    (*_param_1) = m_certificateStatus;
  }
  else
    soap_print_fault(g_soapAPI, stderr);
}

/// <summary>
/// Adds senderes to user account.
/// Saves logs of whole operation.
/// </summary>
/// <param name = "soap"> User connection. </param>
/// <param name = "login"> User login. </param>
/// <param name = "sender_USCOREdata"> Array of senders. </param>
/// <param name = "accept_USCOREterms"> Status of accepting terms. </param>
/// <param name = "_param_1"> Result of connection. </param>
void postAddSender(char *login, char *api_USCOREpass, struct ns1__SenderData *sender_USCOREdata, enum xsd__boolean accept_USCOREterms, struct ns2__addSenderResponse *_param_1)
{
  struct ns2__addSenderResponse m_addSenderStatus;
  if(soap_call_ns2__addSender(g_soapAPI, NULL, NULL, login, api_USCOREpass, sender_USCOREdata, accept_USCOREterms, &m_addSenderStatus) == SOAP_OK)
  {
    (*_param_1) = m_addSenderStatus;
  }
  else
    soap_print_fault(g_soapAPI, stderr);
}

/// <summary>
/// Adds senderes from user account.
/// Saves logs of whole operation.
/// </summary>
/// <param name = "soap"> User connection. </param>
/// <param name = "login"> User login. </param>
/// <param name = "sender_USCOREid"> ID of senders. </param>
/// <param name = "verification_USCOREcode"> Code of verification. </param>
/// <param name = "_param_1"> Result of connection. </param>
void postVerifySender(char *login, char *api_USCOREpass, int sender_USCOREid, char *verification_USCOREcode, struct ns2__verifySenderResponse *_param_1)
{
  struct ns2__verifySenderResponse m_verifySenderStatus;
  if(soap_call_ns2__verifySender(g_soapAPI, NULL, NULL, login, api_USCOREpass, sender_USCOREid, verification_USCOREcode, &m_verifySenderStatus) == SOAP_OK)
  {
    (*_param_1) = m_verifySenderStatus;
  }
  else
    soap_print_fault(g_soapAPI, stderr);
}

/// <summary>
/// </summary>
void postVerifySenderID()
{

}

/// <summary>
/// Removes a sender from user account.
/// Saves logs of whole operation.
/// </summary>
/// <param name = "soap"> User connection. </param>
/// <param name = "login"> User login. </param>
/// <param name = "sender_USCOREid"> Array of senders. </param>
/// <param name = "_param_1"> Result of connection. </param>
void postRemoveSender(char *login, char *api_USCOREpass, int sender_USCOREid, struct ns2__removeSenderResponse *_param_1)
{
  struct ns2__removeSenderResponse m_removeSenderStatus;
  if(soap_call_ns2__removeSender(g_soapAPI, NULL, NULL, login, api_USCOREpass, sender_USCOREid, &m_removeSenderStatus) == SOAP_OK)
  {
    (*_param_1) = m_removeSenderStatus;
  }
  else
    soap_print_fault(g_soapAPI, stderr);
}
