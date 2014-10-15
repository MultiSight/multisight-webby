
//=============================================================================
//Copyright (c) 2010 Pelco. All rights reserved.
//
// This file contains trade secrets of Pelco.  No part may be reproduced or
// transmitted in any form by any means or for any purpose without the express
// written permission of Pelco.
//
// $File: WebbyServer.cpp $
// $Revision:$
// $Date:$
// $Author: Tony DiCroce $
//=============================================================================


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

