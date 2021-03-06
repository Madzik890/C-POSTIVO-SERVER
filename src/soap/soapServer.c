/* soapServer.c
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

SOAP_SOURCE_STAMP("@(#) soapServer.c ver 2.8.70 2018-09-12 18:12:31 GMT")
SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	soap->keep_alive = soap->max_keep_alive + 1;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->keep_alive > 0 && soap->max_keep_alive > 0)
			soap->keep_alive--;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if ((soap_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap))) && soap->error && soap->error < SOAP_STOP)
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}
#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "ns2:dispatch"))
		return soap_serve_ns2__dispatch(soap);
	if (!soap_match_tag(soap, soap->tag, "ns2:getDispatchStatus"))
		return soap_serve_ns2__getDispatchStatus(soap);
	if (!soap_match_tag(soap, soap->tag, "ns2:getBalance"))
		return soap_serve_ns2__getBalance(soap);
	if (!soap_match_tag(soap, soap->tag, "ns2:getConfigProfiles"))
		return soap_serve_ns2__getConfigProfiles(soap);
	if (!soap_match_tag(soap, soap->tag, "ns2:getSenders"))
		return soap_serve_ns2__getSenders(soap);
	if (!soap_match_tag(soap, soap->tag, "ns2:getCertificate"))
		return soap_serve_ns2__getCertificate(soap);
	if (!soap_match_tag(soap, soap->tag, "ns2:getPrice"))
		return soap_serve_ns2__getPrice(soap);
	if (!soap_match_tag(soap, soap->tag, "ns2:addSender"))
		return soap_serve_ns2__addSender(soap);
	if (!soap_match_tag(soap, soap->tag, "ns2:verifySender"))
		return soap_serve_ns2__verifySender(soap);
	if (!soap_match_tag(soap, soap->tag, "ns2:removeSender"))
		return soap_serve_ns2__removeSender(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns2__dispatch(struct soap *soap)
{	struct ns2__dispatch soap_tmp_ns2__dispatch;
	struct ns2__dispatchResponse _param_1;
	soap_default_ns2__dispatchResponse(soap, &_param_1);
	soap_default_ns2__dispatch(soap, &soap_tmp_ns2__dispatch);
	if (!soap_get_ns2__dispatch(soap, &soap_tmp_ns2__dispatch, "ns2:dispatch", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns2__dispatch(soap, soap_tmp_ns2__dispatch.login, soap_tmp_ns2__dispatch.api_USCOREpass, soap_tmp_ns2__dispatch.msg_USCOREtype, soap_tmp_ns2__dispatch.document_USCOREfiles, soap_tmp_ns2__dispatch.recipients, soap_tmp_ns2__dispatch.options, &_param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__dispatchResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__dispatchResponse(soap, &_param_1, "ns2:dispatchResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__dispatchResponse(soap, &_param_1, "ns2:dispatchResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns2__getDispatchStatus(struct soap *soap)
{	struct ns2__getDispatchStatus soap_tmp_ns2__getDispatchStatus;
	struct ns2__getDispatchStatusResponse _param_1;
	soap_default_ns2__getDispatchStatusResponse(soap, &_param_1);
	soap_default_ns2__getDispatchStatus(soap, &soap_tmp_ns2__getDispatchStatus);
	if (!soap_get_ns2__getDispatchStatus(soap, &soap_tmp_ns2__getDispatchStatus, "ns2:getDispatchStatus", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns2__getDispatchStatus(soap, soap_tmp_ns2__getDispatchStatus.login, soap_tmp_ns2__getDispatchStatus.api_USCOREpass, soap_tmp_ns2__getDispatchStatus.dispatch_USCOREids, &_param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__getDispatchStatusResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__getDispatchStatusResponse(soap, &_param_1, "ns2:getDispatchStatusResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__getDispatchStatusResponse(soap, &_param_1, "ns2:getDispatchStatusResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns2__getBalance(struct soap *soap)
{	struct ns2__getBalance soap_tmp_ns2__getBalance;
	struct ns2__getBalanceResponse _param_1;
	soap_default_ns2__getBalanceResponse(soap, &_param_1);
	soap_default_ns2__getBalance(soap, &soap_tmp_ns2__getBalance);
	if (!soap_get_ns2__getBalance(soap, &soap_tmp_ns2__getBalance, "ns2:getBalance", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns2__getBalance(soap, soap_tmp_ns2__getBalance.login, soap_tmp_ns2__getBalance.api_USCOREpass, &_param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__getBalanceResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__getBalanceResponse(soap, &_param_1, "ns2:getBalanceResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__getBalanceResponse(soap, &_param_1, "ns2:getBalanceResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns2__getConfigProfiles(struct soap *soap)
{	struct ns2__getConfigProfiles soap_tmp_ns2__getConfigProfiles;
	struct ns2__getConfigProfilesResponse _param_1;
	soap_default_ns2__getConfigProfilesResponse(soap, &_param_1);
	soap_default_ns2__getConfigProfiles(soap, &soap_tmp_ns2__getConfigProfiles);
	if (!soap_get_ns2__getConfigProfiles(soap, &soap_tmp_ns2__getConfigProfiles, "ns2:getConfigProfiles", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns2__getConfigProfiles(soap, soap_tmp_ns2__getConfigProfiles.login, soap_tmp_ns2__getConfigProfiles.api_USCOREpass, soap_tmp_ns2__getConfigProfiles.msg_USCOREtype, &_param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__getConfigProfilesResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__getConfigProfilesResponse(soap, &_param_1, "ns2:getConfigProfilesResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__getConfigProfilesResponse(soap, &_param_1, "ns2:getConfigProfilesResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns2__getSenders(struct soap *soap)
{	struct ns2__getSenders soap_tmp_ns2__getSenders;
	struct ns2__getSendersResponse _param_1;
	soap_default_ns2__getSendersResponse(soap, &_param_1);
	soap_default_ns2__getSenders(soap, &soap_tmp_ns2__getSenders);
	if (!soap_get_ns2__getSenders(soap, &soap_tmp_ns2__getSenders, "ns2:getSenders", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns2__getSenders(soap, soap_tmp_ns2__getSenders.login, soap_tmp_ns2__getSenders.api_USCOREpass, &_param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__getSendersResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__getSendersResponse(soap, &_param_1, "ns2:getSendersResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__getSendersResponse(soap, &_param_1, "ns2:getSendersResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns2__getCertificate(struct soap *soap)
{	struct ns2__getCertificate soap_tmp_ns2__getCertificate;
	struct ns2__getCertificateResponse _param_1;
	soap_default_ns2__getCertificateResponse(soap, &_param_1);
	soap_default_ns2__getCertificate(soap, &soap_tmp_ns2__getCertificate);
	if (!soap_get_ns2__getCertificate(soap, &soap_tmp_ns2__getCertificate, "ns2:getCertificate", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns2__getCertificate(soap, soap_tmp_ns2__getCertificate.login, soap_tmp_ns2__getCertificate.api_USCOREpass, soap_tmp_ns2__getCertificate.dispatch_USCOREid, soap_tmp_ns2__getCertificate.certificate_USCOREtype, &_param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__getCertificateResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__getCertificateResponse(soap, &_param_1, "ns2:getCertificateResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__getCertificateResponse(soap, &_param_1, "ns2:getCertificateResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns2__getPrice(struct soap *soap)
{	struct ns2__getPrice soap_tmp_ns2__getPrice;
	struct ns2__getPriceResponse _param_1;
	soap_default_ns2__getPriceResponse(soap, &_param_1);
	soap_default_ns2__getPrice(soap, &soap_tmp_ns2__getPrice);
	if (!soap_get_ns2__getPrice(soap, &soap_tmp_ns2__getPrice, "ns2:getPrice", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns2__getPrice(soap, soap_tmp_ns2__getPrice.login, soap_tmp_ns2__getPrice.api_USCOREpass, soap_tmp_ns2__getPrice.msg_USCOREtype, soap_tmp_ns2__getPrice.document_USCOREfiles, soap_tmp_ns2__getPrice.recipients, soap_tmp_ns2__getPrice.config_USCOREid, &_param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__getPriceResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__getPriceResponse(soap, &_param_1, "ns2:getPriceResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__getPriceResponse(soap, &_param_1, "ns2:getPriceResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns2__addSender(struct soap *soap)
{	struct ns2__addSender soap_tmp_ns2__addSender;
	struct ns2__addSenderResponse _param_1;
	soap_default_ns2__addSenderResponse(soap, &_param_1);
	soap_default_ns2__addSender(soap, &soap_tmp_ns2__addSender);
	if (!soap_get_ns2__addSender(soap, &soap_tmp_ns2__addSender, "ns2:addSender", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns2__addSender(soap, soap_tmp_ns2__addSender.login, soap_tmp_ns2__addSender.api_USCOREpass, soap_tmp_ns2__addSender.sender_USCOREdata, soap_tmp_ns2__addSender.accept_USCOREterms, &_param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__addSenderResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__addSenderResponse(soap, &_param_1, "ns2:addSenderResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__addSenderResponse(soap, &_param_1, "ns2:addSenderResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns2__verifySender(struct soap *soap)
{	struct ns2__verifySender soap_tmp_ns2__verifySender;
	struct ns2__verifySenderResponse _param_1;
	soap_default_ns2__verifySenderResponse(soap, &_param_1);
	soap_default_ns2__verifySender(soap, &soap_tmp_ns2__verifySender);
	if (!soap_get_ns2__verifySender(soap, &soap_tmp_ns2__verifySender, "ns2:verifySender", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns2__verifySender(soap, soap_tmp_ns2__verifySender.login, soap_tmp_ns2__verifySender.api_USCOREpass, soap_tmp_ns2__verifySender.sender_USCOREid, soap_tmp_ns2__verifySender.verification_USCOREcode, &_param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__verifySenderResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__verifySenderResponse(soap, &_param_1, "ns2:verifySenderResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__verifySenderResponse(soap, &_param_1, "ns2:verifySenderResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns2__removeSender(struct soap *soap)
{	struct ns2__removeSender soap_tmp_ns2__removeSender;
	struct ns2__removeSenderResponse _param_1;
	soap_default_ns2__removeSenderResponse(soap, &_param_1);
	soap_default_ns2__removeSender(soap, &soap_tmp_ns2__removeSender);
	if (!soap_get_ns2__removeSender(soap, &soap_tmp_ns2__removeSender, "ns2:removeSender", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns2__removeSender(soap, soap_tmp_ns2__removeSender.login, soap_tmp_ns2__removeSender.api_USCOREpass, soap_tmp_ns2__removeSender.sender_USCOREid, &_param_1);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__removeSenderResponse(soap, &_param_1);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__removeSenderResponse(soap, &_param_1, "ns2:removeSenderResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__removeSenderResponse(soap, &_param_1, "ns2:removeSenderResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapServer.c */
