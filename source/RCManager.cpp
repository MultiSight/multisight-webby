
//=============================================================================
//Copyright (c) 2010 Pelco. All rights reserved.
//
// This file contains trade secrets of Pelco.  No part may be reproduced or
// transmitted in any form by any means or for any purpose without the express
// written permission of Pelco.
//
// $File: RCManager.cpp $
// $Revision:$
// $Date:$
// $Author: Jonathan M Davis $
//=============================================================================


#include "Webby/RCManager.h"

#include "XSDK/XHash.h"
#include "Webby/URI.h"
#include "Webby/WebbyException.h"

using namespace std;
using namespace XSDK;
using namespace WEBBY;

//------------------------------------------------------------------------------
// Member Functions
//------------------------------------------------------------------------------

ServerSideResponse RCManager::DoCallback(const URI& uri)
{
    ResourceCallback* pRC = _resourceCallbacks.Find(uri.GetFullResourcePath());

    if(!pRC)
        X_STHROW(WebbyException, ("Unregistered resource callback."));

    return pRC->_func(uri.GetGetArgs(), pRC->_context);
}

ServerSideResponse RCManager::DoCallback(const XString& resourcePath,
                               const XString& resource,
                               const XHash<XString>& args)
{
    URI uri = URI::ConstructURI(resourcePath, resource);

    uri.SetGetArgs(args);

    return DoCallback(uri);
}


void RCManager::RegisterResourceCallback(const XString& resourcePath,
                                         const XString& resource,
                                         ServerSideResponse (*func)(const XHash<XString>& args, void* context),
                                         void* context)
{
    const URI callbackURI = URI::ConstructURI(resourcePath, resource);
    XString fullResourcePath = callbackURI.GetResourcePath();
    fullResourcePath.append(callbackURI.GetResource());

    const ResourceCallback callback(func, context);

    _resourceCallbacks.Add(fullResourcePath.c_str(), callback);
}

void RCManager::UnregisterResourceCallback(const XString& resourcePath,
                                           const XString& resource)
{
    const URI callbackURI = URI::ConstructURI(resourcePath, resource);
    XString fullResourcePath = callbackURI.GetResourcePath();
    fullResourcePath.append(callbackURI.GetResource());

    _resourceCallbacks.Remove(fullResourcePath);
}


void RCManager::UnregisterAllResourceCallbacks()

{
    _resourceCallbacks.Clear();
}

