
//=============================================================================
//Copyright (c) 2010 Pelco. All rights reserved.
//
// This file contains trade secrets of Pelco.  No part may be reproduced or
// transmitted in any form by any means or for any purpose without the express
// written permission of Pelco.
//
// $File: RequestBody.h $
// $Revision:$
// $Date:$
// $Author: Tony DiCroce $
//=============================================================================

#ifndef Webby_RequestBody_h
#define Webby_RequestBody_h

#include "XSDK/XStreamIO.h"
#include "XSDK/XBaseObject.h"

#include "Webby/ServerSideRequest.h"

namespace WEBBY
{

class RequestBody : public XSDK::XBaseObject
{
 public:
    X_API RequestBody( WEBBY::ServerSideRequest& request, XRef<XSDK::XStreamIO> clientSok );

    X_API RequestBody( const RequestBody& obj );

    X_API virtual ~RequestBody() throw();

    X_API RequestBody& operator = ( const RequestBody& obj );
};

};

#endif
