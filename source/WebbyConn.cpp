
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// XSDK
// Copyright (c) 2015 Schneider Electric
//
// Use, modification, and distribution is subject to the Boost Software License,
// Version 1.0 (See accompanying file LICENSE).
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

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

