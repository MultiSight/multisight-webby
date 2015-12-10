
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// Webby
// Copyright (c) 2015 Schneider Electric
//
// Use, modification, and distribution is subject to the Boost Software License,
// Version 1.0 (See accompanying file LICENSE).
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

#include "Webby/WebbyException.h"

using namespace WEBBY;
using namespace XSDK;

WebbyException::WebbyException()
    : XException()
{}

WebbyException::WebbyException(const char* msg, ...)
    : XException()
{
    va_list args;
    va_start(args, msg);
    SetMsg(XString::Format(msg, args));
    va_end(args);
}

WebbyException::WebbyException(const XString& msg)
    : XException(msg)
{}


HTTPException::HTTPException(int statusCode)
    : WebbyException(),
      _statusCode(statusCode)
{}

HTTPException::HTTPException(int statusCode, const char* msg, ...)
    : WebbyException(),
      _statusCode(statusCode)
{
    va_list args;
    va_start(args, msg);
    SetMsg(XString::Format(msg, args));
    va_end(args);
}

HTTPException::HTTPException(int statusCode, const XString& msg)
    : WebbyException(msg),
      _statusCode(statusCode)
{}


HTTP400Exception::HTTP400Exception()
    : HTTPException(400)
{}

HTTP400Exception::HTTP400Exception(const char* msg, ...)
    : HTTPException(400)
{
    va_list args;
    va_start(args, msg);
    SetMsg(XString::Format(msg, args));
    va_end(args);
}

HTTP400Exception::HTTP400Exception(const XString& msg)
    : HTTPException(400, msg)
{}


HTTP401Exception::HTTP401Exception()
    : HTTPException(401)
{}

HTTP401Exception::HTTP401Exception(const char* msg, ...)
    : HTTPException(401)
{
    va_list args;
    va_start(args, msg);
    SetMsg(XString::Format(msg, args));
    va_end(args);
}

HTTP401Exception::HTTP401Exception(const XString& msg)
    : HTTPException(401, msg)
{}


HTTP403Exception::HTTP403Exception()
    : HTTPException(403)
{}

HTTP403Exception::HTTP403Exception(const char* msg, ...)
    : HTTPException(403)
{
    va_list args;
    va_start(args, msg);
    SetMsg(XString::Format(msg, args));
    va_end(args);
}

HTTP403Exception::HTTP403Exception(const XString& msg)
    : HTTPException(403, msg)
{}


HTTP404Exception::HTTP404Exception()
    : HTTPException(404)
{}

HTTP404Exception::HTTP404Exception(const char* msg, ...)
    : HTTPException(404)
{
    va_list args;
    va_start(args, msg);
    SetMsg(XString::Format(msg, args));
    va_end(args);
}

HTTP404Exception::HTTP404Exception(const XString& msg)
    : HTTPException(404, msg)
{}


HTTP415Exception::HTTP415Exception()
    : HTTPException(415)
{}

HTTP415Exception::HTTP415Exception(const char* msg, ...)
    : HTTPException(415)
{
    va_list args;
    va_start(args, msg);
    SetMsg(XString::Format(msg, args));
    va_end(args);
}

HTTP415Exception::HTTP415Exception(const XString& msg)
    : HTTPException(415, msg)
{}


HTTP453Exception::HTTP453Exception()
    : HTTPException(453)
{}

HTTP453Exception::HTTP453Exception(const char* msg, ...)
    : HTTPException(453)
{
    va_list args;
    va_start(args, msg);
    SetMsg(XString::Format(msg, args));
    va_end(args);
}

HTTP453Exception::HTTP453Exception(const XString& msg)
    : HTTPException(453, msg)
{}


HTTP500Exception::HTTP500Exception()
    : HTTPException(500)
{}

HTTP500Exception::HTTP500Exception(const char* msg, ...)
    : HTTPException(500)
{
    va_list args;
    va_start(args, msg);
    SetMsg(XString::Format(msg, args));
    va_end(args);
}

HTTP500Exception::HTTP500Exception(const XString& msg)
    : HTTPException(500, msg)
{}

HTTP501Exception::HTTP501Exception()
    : HTTPException(501)
{}

HTTP501Exception::HTTP501Exception(const char* msg, ...)
    : HTTPException(501)
{
    va_list args;
    va_start(args, msg);
    SetMsg(XString::Format(msg, args));
    va_end(args);
}

HTTP501Exception::HTTP501Exception(const XString& msg)
    : HTTPException(501, msg)
{}
