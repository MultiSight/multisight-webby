
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// XSDK
// Copyright (c) 2015 Schneider Electric
//
// Use, modification, and distribution is subject to the Boost Software License,
// Version 1.0 (See accompanying file LICENSE).
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#ifndef _Webby_WebbyConn_h
#define _Webby_WebbyConn_h

#include "XSDK/XConnBase.h"
#include "XSDK/XBaseObject.h"
#include "XSDK/XIWeakRef.h"
#include "XSDK/XSocket.h"

namespace WEBBY
{

class WebbyServer;

class WebbyConn : public XSDK::XBaseObject, public XSDK::XConnBase
{
 public:
    X_API WebbyConn();

    X_API ~WebbyConn() throw() { _clientConn->Shutdown( SOCKET_SHUT_FLAGS ); }

    X_API virtual XConnBase* Clone() const;

    X_API virtual void ServiceClient();

    X_API virtual void SetServer( XSDK::XServer* server );

 private:
    WebbyConn( const WebbyConn& obj );
    WebbyConn& operator = ( const WebbyConn& obj );

    WebbyServer* _server;
};

}

#endif
