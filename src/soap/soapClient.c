/* soapClient.c
   Generated by gSOAP 2.8.70 for postivoService.h

gSOAP XML Web services tools
Copyright (C) 2000-2018, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"
#ifdef __cplusplus
extern "C" {
#endif

SOAP_SOURCE_STAMP("@(#) soapClient.c ver 2.8.70 2018-08-31 20:20:44 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__dispatch(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *login, char *api_USCOREpass, char *msg_USCOREtype, struct ArrayOfDocumentFiles *document_USCOREfiles, struct ArrayOfRecipients *recipients, struct ArrayOfOptions *options, struct ns2__dispatchResponse *_param_1)
{	struct ns2__dispatch soap_tmp_ns2__dispatch;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://api.postivo.pl:443/webservices.php";
	if (soap_action == NULL)
		soap_action = "http://api.postivo.pl#dispatch";
	soap_tmp_ns2__dispatch.login = login;
	soap_tmp_ns2__dispatch.api_USCOREpass = api_USCOREpass;
	soap_tmp_ns2__dispatch.msg_USCOREtype = msg_USCOREtype;
	soap_tmp_ns2__dispatch.document_USCOREfiles = document_USCOREfiles;
	soap_tmp_ns2__dispatch.recipients = recipients;
	soap_tmp_ns2__dispatch.options = options;
	soap_begin(soap);
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__dispatch(soap, &soap_tmp_ns2__dispatch);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__dispatch(soap, &soap_tmp_ns2__dispatch, "ns2:dispatch", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__dispatch(soap, &soap_tmp_ns2__dispatch, "ns2:dispatch", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!_param_1)
		return soap_closesock(soap);
	soap_default_ns2__dispatchResponse(soap, _param_1);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns2__dispatchResponse(soap, _param_1, "", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__getDispatchStatus(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *login, char *api_USCOREpass, struct ArrayOfDispatchIds *dispatch_USCOREids, struct ns2__getDispatchStatusResponse *_param_1)
{	struct ns2__getDispatchStatus soap_tmp_ns2__getDispatchStatus;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://api.postivo.pl:443/webservices.php";
	if (soap_action == NULL)
		soap_action = "http://api.postivo.pl#getDispatchStatus";
	soap_tmp_ns2__getDispatchStatus.login = login;
	soap_tmp_ns2__getDispatchStatus.api_USCOREpass = api_USCOREpass;
	soap_tmp_ns2__getDispatchStatus.dispatch_USCOREids = dispatch_USCOREids;
	soap_begin(soap);
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__getDispatchStatus(soap, &soap_tmp_ns2__getDispatchStatus);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__getDispatchStatus(soap, &soap_tmp_ns2__getDispatchStatus, "ns2:getDispatchStatus", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__getDispatchStatus(soap, &soap_tmp_ns2__getDispatchStatus, "ns2:getDispatchStatus", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!_param_1)
		return soap_closesock(soap);
	soap_default_ns2__getDispatchStatusResponse(soap, _param_1);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns2__getDispatchStatusResponse(soap, _param_1, "", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__getBalance(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *login, char *api_USCOREpass, struct ns2__getBalanceResponse *_param_1)
{	struct ns2__getBalance soap_tmp_ns2__getBalance;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://api.postivo.pl:443/webservices.php";
	if (soap_action == NULL)
		soap_action = "http://api.postivo.pl#getBalance";
	soap_tmp_ns2__getBalance.login = login;
	soap_tmp_ns2__getBalance.api_USCOREpass = api_USCOREpass;
	soap_begin(soap);
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__getBalance(soap, &soap_tmp_ns2__getBalance);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__getBalance(soap, &soap_tmp_ns2__getBalance, "ns2:getBalance", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__getBalance(soap, &soap_tmp_ns2__getBalance, "ns2:getBalance", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!_param_1)
		return soap_closesock(soap);
	soap_default_ns2__getBalanceResponse(soap, _param_1);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns2__getBalanceResponse(soap, _param_1, "", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__getConfigProfiles(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *login, char *api_USCOREpass, char *msg_USCOREtype, struct ns2__getConfigProfilesResponse *_param_1)
{	struct ns2__getConfigProfiles soap_tmp_ns2__getConfigProfiles;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://api.postivo.pl:443/webservices.php";
	if (soap_action == NULL)
		soap_action = "http://api.postivo.pl#getConfigProfiles";
	soap_tmp_ns2__getConfigProfiles.login = login;
	soap_tmp_ns2__getConfigProfiles.api_USCOREpass = api_USCOREpass;
	soap_tmp_ns2__getConfigProfiles.msg_USCOREtype = msg_USCOREtype;
	soap_begin(soap);
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__getConfigProfiles(soap, &soap_tmp_ns2__getConfigProfiles);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__getConfigProfiles(soap, &soap_tmp_ns2__getConfigProfiles, "ns2:getConfigProfiles", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__getConfigProfiles(soap, &soap_tmp_ns2__getConfigProfiles, "ns2:getConfigProfiles", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!_param_1)
		return soap_closesock(soap);
	soap_default_ns2__getConfigProfilesResponse(soap, _param_1);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns2__getConfigProfilesResponse(soap, _param_1, "", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__getSenders(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *login, char *api_USCOREpass, struct ns2__getSendersResponse *_param_1)
{	struct ns2__getSenders soap_tmp_ns2__getSenders;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://api.postivo.pl:443/webservices.php";
	if (soap_action == NULL)
		soap_action = "http://api.postivo.pl#getSenders";
	soap_tmp_ns2__getSenders.login = login;
	soap_tmp_ns2__getSenders.api_USCOREpass = api_USCOREpass;
	soap_begin(soap);
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__getSenders(soap, &soap_tmp_ns2__getSenders);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__getSenders(soap, &soap_tmp_ns2__getSenders, "ns2:getSenders", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__getSenders(soap, &soap_tmp_ns2__getSenders, "ns2:getSenders", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!_param_1)
		return soap_closesock(soap);
	soap_default_ns2__getSendersResponse(soap, _param_1);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns2__getSendersResponse(soap, _param_1, "", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__getCertificate(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *login, char *api_USCOREpass, char *dispatch_USCOREid, int certificate_USCOREtype, struct ns2__getCertificateResponse *_param_1)
{	struct ns2__getCertificate soap_tmp_ns2__getCertificate;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://api.postivo.pl:443/webservices.php";
	if (soap_action == NULL)
		soap_action = "http://api.postivo.pl#getCertificate";
	soap_tmp_ns2__getCertificate.login = login;
	soap_tmp_ns2__getCertificate.api_USCOREpass = api_USCOREpass;
	soap_tmp_ns2__getCertificate.dispatch_USCOREid = dispatch_USCOREid;
	soap_tmp_ns2__getCertificate.certificate_USCOREtype = certificate_USCOREtype;
	soap_begin(soap);
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__getCertificate(soap, &soap_tmp_ns2__getCertificate);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__getCertificate(soap, &soap_tmp_ns2__getCertificate, "ns2:getCertificate", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__getCertificate(soap, &soap_tmp_ns2__getCertificate, "ns2:getCertificate", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!_param_1)
		return soap_closesock(soap);
	soap_default_ns2__getCertificateResponse(soap, _param_1);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns2__getCertificateResponse(soap, _param_1, "", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__getPrice(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *login, char *api_USCOREpass, char *msg_USCOREtype, struct ArrayOfDocumentFiles *document_USCOREfiles, struct ArrayOfRecipients *recipients, int config_USCOREid, struct ns2__getPriceResponse *_param_1)
{	struct ns2__getPrice soap_tmp_ns2__getPrice;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://api.postivo.pl:443/webservices.php";
	if (soap_action == NULL)
		soap_action = "http://api.postivo.pl#getPrice";
	soap_tmp_ns2__getPrice.login = login;
	soap_tmp_ns2__getPrice.api_USCOREpass = api_USCOREpass;
	soap_tmp_ns2__getPrice.msg_USCOREtype = msg_USCOREtype;
	soap_tmp_ns2__getPrice.document_USCOREfiles = document_USCOREfiles;
	soap_tmp_ns2__getPrice.recipients = recipients;
	soap_tmp_ns2__getPrice.config_USCOREid = config_USCOREid;
	soap_begin(soap);
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__getPrice(soap, &soap_tmp_ns2__getPrice);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__getPrice(soap, &soap_tmp_ns2__getPrice, "ns2:getPrice", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__getPrice(soap, &soap_tmp_ns2__getPrice, "ns2:getPrice", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!_param_1)
		return soap_closesock(soap);
	soap_default_ns2__getPriceResponse(soap, _param_1);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns2__getPriceResponse(soap, _param_1, "", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__addSender(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *login, char *api_USCOREpass, struct ns1__SenderData *sender_USCOREdata, enum xsd__boolean accept_USCOREterms, struct ns2__addSenderResponse *_param_1)
{	struct ns2__addSender soap_tmp_ns2__addSender;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://api.postivo.pl:443/webservices.php";
	if (soap_action == NULL)
		soap_action = "http://api.postivo.pl#addSender";
	soap_tmp_ns2__addSender.login = login;
	soap_tmp_ns2__addSender.api_USCOREpass = api_USCOREpass;
	soap_tmp_ns2__addSender.sender_USCOREdata = sender_USCOREdata;
	soap_tmp_ns2__addSender.accept_USCOREterms = accept_USCOREterms;
	soap_begin(soap);
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__addSender(soap, &soap_tmp_ns2__addSender);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__addSender(soap, &soap_tmp_ns2__addSender, "ns2:addSender", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__addSender(soap, &soap_tmp_ns2__addSender, "ns2:addSender", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!_param_1)
		return soap_closesock(soap);
	soap_default_ns2__addSenderResponse(soap, _param_1);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns2__addSenderResponse(soap, _param_1, "", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__verifySender(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *login, char *api_USCOREpass, int sender_USCOREid, char *verification_USCOREcode, struct ns2__verifySenderResponse *_param_1)
{	struct ns2__verifySender soap_tmp_ns2__verifySender;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://api.postivo.pl:443/webservices.php";
	if (soap_action == NULL)
		soap_action = "http://api.postivo.pl#verifySender";
	soap_tmp_ns2__verifySender.login = login;
	soap_tmp_ns2__verifySender.api_USCOREpass = api_USCOREpass;
	soap_tmp_ns2__verifySender.sender_USCOREid = sender_USCOREid;
	soap_tmp_ns2__verifySender.verification_USCOREcode = verification_USCOREcode;
	soap_begin(soap);
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__verifySender(soap, &soap_tmp_ns2__verifySender);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__verifySender(soap, &soap_tmp_ns2__verifySender, "ns2:verifySender", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__verifySender(soap, &soap_tmp_ns2__verifySender, "ns2:verifySender", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!_param_1)
		return soap_closesock(soap);
	soap_default_ns2__verifySenderResponse(soap, _param_1);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns2__verifySenderResponse(soap, _param_1, "", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__removeSender(struct soap *soap, const char *soap_endpoint, const char *soap_action, char *login, char *api_USCOREpass, int sender_USCOREid, struct ns2__removeSenderResponse *_param_1)
{	struct ns2__removeSender soap_tmp_ns2__removeSender;
	if (soap_endpoint == NULL)
		soap_endpoint = "https://api.postivo.pl:443/webservices.php";
	if (soap_action == NULL)
		soap_action = "http://api.postivo.pl#removeSender";
	soap_tmp_ns2__removeSender.login = login;
	soap_tmp_ns2__removeSender.api_USCOREpass = api_USCOREpass;
	soap_tmp_ns2__removeSender.sender_USCOREid = sender_USCOREid;
	soap_begin(soap);
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__removeSender(soap, &soap_tmp_ns2__removeSender);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__removeSender(soap, &soap_tmp_ns2__removeSender, "ns2:removeSender", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__removeSender(soap, &soap_tmp_ns2__removeSender, "ns2:removeSender", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!_param_1)
		return soap_closesock(soap);
	soap_default_ns2__removeSenderResponse(soap, _param_1);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_get_ns2__removeSenderResponse(soap, _param_1, "", NULL);
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.c */