//=============================================================================
//Copyright (c) 2012 Pelco. All rights reserved.
//
// This file contains trade secrets of Pelco.  No part may be reproduced or
// transmitted in any form by any means or for any purpose without the express
// written permission of Pelco.
//
// $File: WebbyUtils.cpp $
// $Revision:$
// $Date:$
// $Author: Jonathan M Davis $
//=============================================================================

#include "Webby/WebbyUtils.h"

#include "Webby/URI.h"
#include "Webby/WebbyException.h"

using namespace XSDK;
using namespace std;
using namespace WEBBY;


XString WEBBY::AdjustHeaderName(const XString& name)
{
    for(size_t i = 0, e = name.size(); i < e; ++i)
    {
        const char c = name[i];
        if(c < 33 || c > 126 || c == ':')
            X_STHROW(WebbyException, ("Invalid character in header value: [%c]", c));
    }

    return name.ToLower();
}


XString WEBBY::AdjustHeaderValue(const XString& value)
{
    const size_t left = value.find_first_not_of(" \t");
    const size_t right = value.find_last_not_of(" \t");

    if(left == string::npos)
        return "";

    return value.substr(left, right - left + 1);
}
