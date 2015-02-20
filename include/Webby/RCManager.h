
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// XSDK
// Copyright (c) 2015 Schneider Electric
//
// Use, modification, and distribution is subject to the Boost Software License,
// Version 1.0 (See accompanying file LICENSE).
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#ifndef _Webby_RCManager_h
#define _Webby_RCManager_h

#include "Webby/ServerSideResponse.h"
#include "Webby/URI.h"
#include "XSDK/XBaseObject.h"
#include "XSDK/XHash.h"
#include "XSDK/XString.h"

namespace WEBBY
{

class RCManager : public XSDK::XBaseObject
{
    friend class RCManagerTest;

public:
    X_API RCManager() :
        _resourceCallbacks()
    {}

    X_API RCManager( const RCManager& other ) :
        _resourceCallbacks( other._resourceCallbacks )
    {}

    X_API ~RCManager() throw()
    {}

    X_API RCManager& operator=( const RCManager& other )
    {
        this->_resourceCallbacks = other._resourceCallbacks;

        return *this;
    }

public:

    X_API ServerSideResponse DoCallback( const URI& uri );

    X_API ServerSideResponse DoCallback( const XSDK::XString& resourcePath,
                                         const XSDK::XString& resource,
                                         const XSDK::XHash<XSDK::XString>& args );


    X_API void RegisterResourceCallback( const XSDK::XString& resourcePath,
                                         const XSDK::XString& resource,
                                         ServerSideResponse (*func)( const XSDK::XHash<XSDK::XString>& args, void* context ),
                                         void* context );

    X_API void UnregisterResourceCallback( const XSDK::XString& resourcePath,
                                           const XSDK::XString& resource );

    X_API void UnregisterAllResourceCallbacks();


 private:

    class ResourceCallback;

    XSDK::XHash<ResourceCallback> _resourceCallbacks;

    class ResourceCallback
    {
    public:
        ResourceCallback( ServerSideResponse (*func)( const XSDK::XHash<XSDK::XString>& args, void* context ) = NULL,
                          void* context = NULL ) :
            _func(func),
            _context(context)
        {}

        ServerSideResponse (*_func)( const XSDK::XHash<XSDK::XString>& args, void* context );

        void* _context;
    };
};

}

#endif

