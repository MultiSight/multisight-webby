
//=============================================================================
//Copyright (c) 2010 Pelco. All rights reserved.
//
// This file contains trade secrets of Pelco.  No part may be reproduced or
// transmitted in any form by any means or for any purpose without the express
// written permission of Pelco.
//
// $File: WebbyConn.h $
// $Revision:$
// $Date:$
// $Author: Tony DiCroce $
//=============================================================================

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
