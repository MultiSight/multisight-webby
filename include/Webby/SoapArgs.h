
//=============================================================================
//Copyright (c) 2010 Pelco. All rights reserved.
//
// This file contains trade secrets of Pelco.  No part may be reproduced or
// transmitted in any form by any means or for any purpose without the express
// written permission of Pelco.
//
// $File: SoapArgs.h $
// $Revision:$
// $Date:$
// $Author: Tony Di Croce $
//=============================================================================

#ifndef Webby_SoapArgs_h
#define Webby_SoapArgs_h

#include <vector>
#include <map>

#include "XSDK/XHash.h"
#include "XSDK/XString.h"
#include "XSDK/XBaseObject.h"
#include "XSDK/XDomParserNode.h"

namespace WEBBY
{

class SoapArgs : public XSDK::XBaseObject
{
public:

    X_API SoapArgs();

    X_API virtual ~SoapArgs() throw();

    /// \brief Adds 'val' to arguments at position 'path'.
    ///
    /// 'path' specifies a position in a complex type. Components of path are separated by
    /// '.' (for example, 'foo.bar.alpha'). These components describe a heirarchy.
    X_API void AddArg( const XSDK::XString& path, const XSDK::XString& val );

    /// \brief Adds the attribute 'name' with value 'val' to the node at position 'path'.
    ///
    /// 'path' specifies a position in a complex type. Components of path are separated by
    /// '.' (for example, 'foo.bar.alpha'). These components describe a heirarchy.
    X_API void AddAttribute( const XSDK::XString& path, const XSDK::XString& name, const XSDK::XString& val );

    /// \brief Converts the arguments contained in this SoapArgs into XML.
    X_API XSDK::XString ToXML() const;

private:
    SoapArgs( const SoapArgs& obj );
    SoapArgs& operator = ( const SoapArgs& obj );

    XIRef<XSDK::XDomParserNode> _GetNode( const XSDK::XString& path, XIRef<XSDK::XDomParserNode> parent );

    XIRef<XSDK::XDomParserNode> _fakeRoot;
};

}

#endif
