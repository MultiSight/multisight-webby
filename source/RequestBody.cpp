
//=============================================================================
//Copyright (c) 2010 Pelco. All rights reserved.
//
// This file contains trade secrets of Pelco.  No part may be reproduced or
// transmitted in any form by any means or for any purpose without the express
// written permission of Pelco.
//
// $File: RequestBody.cpp $
// $Revision:$
// $Date:$
// $Author: Tony DiCroce $
//=============================================================================


#include "Webby/RequestBody.h"

using namespace WEBBY;
using namespace XSDK;

RequestBody::RequestBody( ServerSideRequest& request, XRef<XStreamIO> clientSok )
{
}

RequestBody::RequestBody( const RequestBody& obj )
{
}

RequestBody::~RequestBody() throw()
{
}

RequestBody& RequestBody::operator = ( const RequestBody& obj )
{
    return *this;
}
