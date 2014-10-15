//=============================================================================
//Copyright (c) 2012 Pelco. All rights reserved.
//
// This file contains trade secrets of Pelco.  No part may be reproduced or
// transmitted in any form by any means or for any purpose without the express
// written permission of Pelco.
//
// $File: WebbyUtils.h $
// $Revision:$
// $Date:$
// $Author: Jonathan M Davis $
//=============================================================================

#ifndef WEBBY_WebbyUtils_h
#define WEBBY_WebbyUtils_h

#include "XSDK/XString.h"

namespace WEBBY
{

    /// \brief Verifies that the name of a header name-value pair doesn't contain
    ///        any invalid characters. It also lowers the name, since header names
    ///        are case-insensitive.
    X_API XSDK::XString AdjustHeaderName(const XSDK::XString& value);

    /// \brief Adjusts the value of a header name-value pair so that it's correct
    ///        with regards to leading and trailing whitespace.
    X_API XSDK::XString AdjustHeaderValue(const XSDK::XString& value);
}

#endif
