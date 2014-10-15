
//=============================================================================
//Copyright (c) 2010 Pelco. All rights reserved.
//
// This file contains trade secrets of Pelco.  No part may be reproduced or
// transmitted in any form by any means or for any purpose without the express
// written permission of Pelco.
//
// $File: WebbyServer.h $
// $Revision:$
// $Date:$
// $Author: Tony DiCroce $
//=============================================================================


#ifndef _Webby_WebbyServer_h
#define _Webby_WebbyServer_h

#include "XSDK/XServer.h"
#include "XSDK/XBaseObject.h"
#include "XSDK/XString.h"
#include "Webby/RCManager.h"

namespace WEBBY
{

class WebbyServer : public XSDK::XBaseObject, public XSDK::XServer
{
 public:

    X_API WebbyServer() :
        _rcManager()
    {}

    X_API virtual ~WebbyServer() throw()
    {}

    X_API ServerSideResponse DoCallback( const URI& uri );

    X_API ServerSideResponse DoCallback( const XSDK::XString& resourcePath,
                                         const XSDK::XString& resource,
                                         const XSDK::XHash<XSDK::XString>& args );

    X_API void RegisterResourceCallback( const XSDK::XString& resourcePath,
                                         const XSDK::XString& resource,
                                         ServerSideResponse (*pFunc)( const XSDK::XHash<XSDK::XString>& args, void* pContext ),
                                         void* pContext );

    X_API void UnregisterResourceCallback( const XSDK::XString& resourcePath,
                                           const XSDK::XString& resource );

    X_API void UnregisterAllResourceCallbacks();


 private:
    WebbyServer(const WebbyServer& other);
    WebbyServer& operator =(const WebbyServer& other);

    RCManager _rcManager;
};

}

#endif
