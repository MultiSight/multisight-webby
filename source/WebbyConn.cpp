
//=============================================================================
//Copyright (c) 2010 Pelco. All rights reserved.
//
// This file contains trade secrets of Pelco.  No part may be reproduced or
// transmitted in any form by any means or for any purpose without the express
// written permission of Pelco.
//
// $File: WebbyConn.cpp $
// $Revision:$
// $Date:$
// $Author: Tony DiCroce $
//=============================================================================


#include "Webby/WebbyConn.h"

#include "XSDK/XString.h"
#include "Webby/ServerSideRequest.h"
#include "Webby/ServerSideResponse.h"
#include "Webby/URI.h"
#include "Webby/WebbyServer.h"

using namespace XSDK;
using namespace WEBBY;
using namespace std;

WebbyConn::WebbyConn()
    : _server(NULL)
{
}

XConnBase* WebbyConn::Clone() const
{
    return new WebbyConn;
}

void WebbyConn::ServiceClient()
{
    ServerSideRequest req;

    req.ReadRequest( _clientConn );

    const URI uri = req.GetURI();

    if( req.GetMethod() == "get" )
    {
        const XHash<XString> getArgs = uri.GetGetArgs();

    }
    else if( req.GetMethod() == "post" )
    {
    }


    ServerSideResponse response;

    try
    {
        response = _server->DoCallback(uri);
    }
    catch(XSDK::XException)
    {
        XString body = "<h1>There Was an Error.</h1><br><p>Just what you wanted to hear. I know.</p>";

        body.append("<br><p>Raw URL: ");
        body.append(uri.GetFullRawURI());
        body.append("</p><br><p>URL ResourcePath: ");
        body.append(uri.GetResourcePath());
        body.append("</p><br><p>URL Resource: ");
        body.append(uri.GetResource());
        body.append("</p>");

        response.SetBody(body);
    }


    response.WriteResponse( _clientConn );
}


void WebbyConn::SetServer( XSDK::XServer* server )
{
    _server = dynamic_cast<WebbyServer*>(server);

        X_ASSERT((_server)?true:false);
}

