/*
 *  This section creates a mirror server which is using only to saves operations logs.
 */
#include "soap/Postivo_x002eplBinding.nsmap"
#include "soap/soapH.h"
#include "postivoAPI.h"

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
int ns2__dispatch(struct soap* soap, char *login, char *api_USCOREpass, char *msg_USCOREtype, struct ArrayOfDocumentFiles *document_USCOREfiles, struct ArrayOfRecipients *recipients, struct ArrayOfOptions *options, struct ns2__dispatchResponse *_param_1)
{
  postDispatch(login, api_USCOREpass, msg_USCOREtype, document_USCOREfiles, recipients, options, _param_1);
  return SOAP_OK;
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
int ns2__getDispatchStatus(struct soap* soap, char *login, char *api_USCOREpass, struct ArrayOfDispatchIds *dispatch_USCOREids, struct ns2__getDispatchStatusResponse *_param_1)
{
  return SOAP_OK;
}

/// <summary>
/// Gets a balance of the user account.
/// Saves logs of whole operation.
/// </summary>
/// <param name = soap> User connection. </param>
/// <param name = login> User login. </param>
/// <param name = api_USCOREpass> User password. </param>
/// <param name = "_param_1"> The result of connections. </param>
int ns2__getBalance(struct soap* soap, char *login, char *api_USCOREpass, struct ns2__getBalanceResponse *_param_1)
{
  postGetBalance(login, api_USCOREpass, _param_1);
  return SOAP_OK;
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
int ns2__getPrice(struct soap* soap, char *login, char *api_USCOREpass, char *msg_USCOREtype, struct ArrayOfDocumentFiles *document_USCOREfiles, struct ArrayOfRecipients *recipients, int config_USCOREid, struct ns2__getPriceResponse *_param_1)
{
  postGetPrice(login, api_USCOREpass, msg_USCOREtype, document_USCOREfiles, recipients, config_USCOREid, _param_1);
  return SOAP_OK;
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
int ns2__getConfigProfiles(struct soap* soap, char *login, char *api_USCOREpass, char *msg_USCOREtype, struct ns2__getConfigProfilesResponse *_param_1)
{
  postGetConfigProfiles(login, api_USCOREpass, msg_USCOREtype, _param_1);
  return SOAP_OK;
}

/// <summary>
/// Gets senders from the user account.
/// Saves logs of whole operation.
/// </summary>
/// <param name = "soap"> User connection. </param>
/// <param name = "login"> User login. </param>
/// <param name = "api_USCOREpass"> User password. </param>
/// <param name = "_param_1"> Array of sendes. </param>
int ns2__getSenders(struct soap* soap, char *login, char *api_USCOREpass, struct ns2__getSendersResponse *_param_1)
{
  postGetSenders(login, api_USCOREpass, _param_1);
  return SOAP_OK;
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
int ns2__getCertificate(struct soap* soap, char *login, char *api_USCOREpass, char *dispatch_USCOREid, int certificate_USCOREtype, struct ns2__getCertificateResponse *_param_1)
{
  postGetCertificate(login, api_USCOREpass, dispatch_USCOREid, certificate_USCOREtype, _param_1);
  return SOAP_OK;
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
int ns2__addSender(struct soap* soap, char *login, char *api_USCOREpass, struct ns1__SenderData *sender_USCOREdata, enum xsd__boolean accept_USCOREterms, struct ns2__addSenderResponse *_param_1)
{
  postAddSender(login, api_USCOREpass, sender_USCOREdata, accept_USCOREterms, _param_1);
  return SOAP_OK;
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
int ns2__verifySender(struct soap* soap, char *login, char *api_USCOREpass, int sender_USCOREid, char *verification_USCOREcode, struct ns2__verifySenderResponse *_param_1)
{
  postVerifySender(login, api_USCOREpass, sender_USCOREid, verification_USCOREcode, _param_1);
  return SOAP_OK;
}

/// <summary>
/// Removes a sender from user account.
/// Saves logs of whole operation.
/// </summary>
/// <param name = "soap"> User connection. </param>
/// <param name = "login"> User login. </param>
/// <param name = "sender_USCOREid"> Array of senders. </param>
/// <param name = "_param_1"> Result of connection. </param>
int ns2__removeSender(struct soap* soap, char *login, char *api_USCOREpass, int sender_USCOREid, struct ns2__removeSenderResponse *_param_1)
{
  postRemoveSender(login, api_USCOREpass, sender_USCOREid, _param_1);
  return SOAP_OK;
}
