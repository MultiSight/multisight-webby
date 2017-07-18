
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// Webby
// Copyright (c) 2015 Schneider Electric
//
// Use, modification, and distribution is subject to the Boost Software License,
// Version 1.0 (See accompanying file LICENSE).
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#ifndef _Webby_WebbyException_h
#define _Webby_WebbyException_h

#include "XSDK/XException.h"
#include "XSDK/XString.h"

namespace WEBBY
{
    /// General exception type for Webby.
    class WebbyException : public XSDK::XException
    {
    public:
        X_API WebbyException();

        X_API virtual ~WebbyException() throw() {}

        X_API WebbyException(const char* msg, ...);

        X_API WebbyException(const XSDK::XString& msg);
    };


    class HTTPException : public WebbyException
    {
    public:
        X_API HTTPException(int statusCode);

        X_API virtual ~HTTPException() throw() {}

        X_API HTTPException(int statusCode, const char* msg, ...);

        X_API HTTPException(int statusCode, const XSDK::XString& msg);

        int GetStatus() const { return _statusCode; }

    private:

        int _statusCode;
    };


    class HTTP400Exception : public HTTPException
    {
    public:
        X_API HTTP400Exception();

        X_API virtual ~HTTP400Exception() throw() {}

        X_API HTTP400Exception(const char* msg, ...);

        X_API HTTP400Exception(const XSDK::XString& msg);
    };


    class HTTP401Exception : public HTTPException
    {
    public:
        X_API HTTP401Exception();

        X_API virtual ~HTTP401Exception() throw() {}

        X_API HTTP401Exception(const char* msg, ...);

        X_API HTTP401Exception(const XSDK::XString& msg);
    };


    class HTTP403Exception : public HTTPException
    {
    public:
        X_API HTTP403Exception();

        X_API virtual ~HTTP403Exception() throw() {}

        X_API HTTP403Exception(const char* msg, ...);

        X_API HTTP403Exception(const XSDK::XString& msg);
    };


    class HTTP404Exception : public HTTPException
    {
    public:
        X_API HTTP404Exception();

        X_API virtual ~HTTP404Exception() throw() {}

        X_API HTTP404Exception(const char* msg, ...);

        X_API HTTP404Exception(const XSDK::XString& msg);
    };


    class HTTP415Exception : public HTTPException
    {
    public:
        X_API HTTP415Exception();

        X_API virtual ~HTTP415Exception() throw() {}

        X_API HTTP415Exception(const char* msg, ...);

        X_API HTTP415Exception(const XSDK::XString& msg);
    };


    class HTTP453Exception : public HTTPException
    {
    public:
        X_API HTTP453Exception();

        X_API virtual ~HTTP453Exception() throw() {}

        X_API HTTP453Exception(const char* msg, ...);

        X_API HTTP453Exception(const XSDK::XString& msg);
    };


    class HTTP500Exception : public HTTPException
    {
    public:
        X_API HTTP500Exception();

        X_API virtual ~HTTP500Exception() throw() {}

        X_API HTTP500Exception(const char* msg, ...);

        X_API HTTP500Exception(const XSDK::XString& msg);
    };

    class HTTP501Exception : public HTTPException
    {
    public:
        X_API HTTP501Exception();

        X_API virtual ~HTTP501Exception() throw() {}

        X_API HTTP501Exception(const char* msg, ...);

        X_API HTTP501Exception(const XSDK::XString& msg);
    };

#define CATCH_TRANSLATE_HTTP_EXCEPTIONS(a) \
    catch( WEBBY::HTTP400Exception& ex )   \
    { \
        X_LOG_XSDK_EXCEPTION(ex); \
        a.SetStatusCode( WEBBY::ServerSideResponse::SC_400_Bad_Request ); \
    } \
    catch( WEBBY::HTTP401Exception& ex ) \
    { \
        X_LOG_XSDK_EXCEPTION(ex);       \
        a.SetStatusCode( WEBBY::ServerSideResponse::SC_401_Unauthorized ); \
    } \
    catch( WEBBY::HTTP403Exception& ex ) \
    { \
        X_LOG_XSDK_EXCEPTION(ex);       \
        a.SetStatusCode( WEBBY::ServerSideResponse::SC_403_Forbidden ); \
    } \
    catch( WEBBY::HTTP404Exception& ex ) \
    { \
        X_LOG_NOTICE_XSDK_EXCEPTION(ex);       \
        a.SetStatusCode( WEBBY::ServerSideResponse::SC_404_Not_Found ); \
    } \
    catch( WEBBY::HTTP500Exception& ex ) \
    { \
        X_LOG_XSDK_EXCEPTION(ex);       \
        a.SetStatusCode( WEBBY::ServerSideResponse::SC_500_Internal_Server_Error ); \
    } \
    catch( WEBBY::HTTP501Exception& ex ) \
    { \
        X_LOG_XSDK_EXCEPTION(ex);       \
        a.SetStatusCode( WEBBY::ServerSideResponse::SC_501_Not_Implemented ); \
    } \
    catch( XSDK::XException& ex )               \
    { \
        X_LOG_XSDK_EXCEPTION(ex);        \
        a.SetStatusCode( WEBBY::ServerSideResponse::SC_500_Internal_Server_Error ); \
    } \
    catch( std::exception& ex )                 \
    { \
        X_LOG_STD_EXCEPTION(ex); \
        a.SetStatusCode( WEBBY::ServerSideResponse::SC_500_Internal_Server_Error ); \
    }
}

#endif
