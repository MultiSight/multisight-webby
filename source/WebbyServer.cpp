
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// XSDK
// Copyright (c) 2015 Schneider Electric
//
// Use, modification, and distribution is subject to the Boost Software License,
// Version 1.0 (See accompanying file LICENSE).
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#include "Webby/WebbyServer.h"

using namespace XSDK;
using namespace WEBBY;
using namespace std;

//------------------------------------------------------------------------------
// Member Functions
//------------------------------------------------------------------------------

ServerSideResponse WebbyServer::DoCallback(const URI& uri)
{
    return _rcManager.DoCallback(uri);
}


ServerSideResponse WebbyServer::DoCallback(const XString& resourcePath,
                                           const XString& resource,
                                           const XHash<XString>& args)
{
    return _rcManager.DoCallback(resourcePath, resource, args);
}


void WebbyServer::RegisterResourceCallback(const XString& resourcePath,
                                           const XString& resource,
                                           ServerSideResponse (*pFunc)(const XHash<XString>& args, void* pContext),
                                           void* pContext)
{
    _rcManager.RegisterResourceCallback(resourcePath, resource, pFunc, pContext);
}

void WebbyServer::UnregisterResourceCallback(const XString& resourcePath,
                                             const XString& resource)
{
    _rcManager.UnregisterResourceCallback(resourcePath, resource);
}


void WebbyServer::UnregisterAllResourceCallbacks()

{
    _rcManager.UnregisterAllResourceCallbacks();
}

