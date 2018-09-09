#ifndef POSTIVO_H
#define POSTIVO_H

#include "soap/soapH.h"

/// <global instances>
extern struct soap * g_soapAPI;
/// <global instances>

/// <functions>
void initPostivoAPI();
void closePostivoAPI();

void postDispatch(char *login, char *api_USCOREpass, char *msg_USCOREtype, struct ArrayOfDocumentFiles *document_USCOREfiles, struct ArrayOfRecipients *recipients, struct ArrayOfOptions *options, struct ns2__dispatchResponse *_param_1);
void postGetDispatchStatus(char *login, char *api_USCOREpass, struct ArrayOfDispatchIds *dispatch_USCOREids, struct ns2__getDispatchStatusResponse *_param_1);
void postGetBalance(char *login, char *api_USCOREpass, struct ns2__getBalanceResponse *_param_1);
void postGetPrice(char *login, char *api_USCOREpass, char *msg_USCOREtype, struct ArrayOfDocumentFiles *document_USCOREfiles, struct ArrayOfRecipients *recipients, int config_USCOREid, struct ns2__getPriceResponse *_param_1);
void postGetConfigProfiles(char *login, char *api_USCOREpass, char *msg_USCOREtype, struct ns2__getConfigProfilesResponse *_param_1);
void postGetSenders(char *login, char *api_USCOREpass, struct ns2__getSendersResponse *_param_1);
void postGetCertificate(char *login, char *api_USCOREpass, char *dispatch_USCOREid, int certificate_USCOREtype, struct ns2__getCertificateResponse *_param_1);
void postAddSender(char *login, char *api_USCOREpass, struct ns1__SenderData *sender_USCOREdata, enum xsd__boolean accept_USCOREterms, struct ns2__addSenderResponse *_param_1);
void postVerifySender(char *login, char *api_USCOREpass, int sender_USCOREid, char *verification_USCOREcode, struct ns2__verifySenderResponse *_param_1);
void postVerifySenderID();
void postRemoveSender(char *login, char *api_USCOREpass, int sender_USCOREid, struct ns2__removeSenderResponse *_param_1);
/// <functions>


#endif
