
#include "RCManagerTest.h"

#include "XSDK/XHash.h"
#include "XSDK/XString.h"
#include "Webby/RCManager.h"
#include "Webby/WebbyException.h"

using namespace std;
using namespace XSDK;
using namespace WEBBY;

void RCManagerTest::TestConstructor()
{
    RCManager rcManager;

    UT_ASSERT(rcManager._resourceCallbacks.Empty());
}


void RCManagerTest::TestRegisterResourceCallbackFuncs()
{
    RCManager rcManager;
    XString str1;
    XString str2 = "string";
    XString str3 = "cheese";

    rcManager.RegisterResourceCallback("hello", "world", &resourceFunc, &str1);
    UT_ASSERT(rcManager._resourceCallbacks.GetElemCount() == 1);

    RCManager::ResourceCallback* rc1 = rcManager._resourceCallbacks.Find("/hello/world");
    UT_ASSERT(rc1->_func == &resourceFunc);
    UT_ASSERT(rc1->_context == &str1);

    UT_ASSERT_THROWS_MESSAGE("expected exception not thrown", rcManager.RegisterResourceCallback("hello", "george", &resourceFunc, &str2), WebbyException);

    rcManager.RegisterResourceCallback("goodbye", "world", &resourceFunc, &str2);
    UT_ASSERT(rcManager._resourceCallbacks.GetElemCount() == 2);

    RCManager::ResourceCallback* rc2 = rcManager._resourceCallbacks.Find("/goodbye/world");
    UT_ASSERT(rc2->_func == &resourceFunc);
    UT_ASSERT(rc2->_context == &str2);

    rcManager.UnregisterResourceCallback("hello", "world");
    UT_ASSERT(rcManager._resourceCallbacks.GetElemCount() == 1);

    RCManager::ResourceCallback* rc3 = rcManager._resourceCallbacks.Find("/hello/world");
    UT_ASSERT(rc3 == NULL);

    rcManager.RegisterResourceCallback("silly", "dog", &resourceFunc, &str3);
    UT_ASSERT(rcManager._resourceCallbacks.GetElemCount() == 2);

    RCManager::ResourceCallback* rc4 = rcManager._resourceCallbacks.Find("/silly/dog");
    UT_ASSERT(rc4->_func == &resourceFunc);
    UT_ASSERT(rc4->_context == &str3);

    rcManager.UnregisterAllResourceCallbacks();
    UT_ASSERT(rcManager._resourceCallbacks.Empty());

    //Verify that it dosen't go boom with nothing in it.
    rcManager.UnregisterAllResourceCallbacks();
    UT_ASSERT(rcManager._resourceCallbacks.Empty());
}


void RCManagerTest::TestDoCallback()
{
    RCManager rcManager;
    XString str;
    XHash<XString> args;

    rcManager.RegisterResourceCallback("hello", "world", &resourceFunc, &str);

    rcManager.DoCallback("hello", "world", args);
    UT_ASSERT(str == "No Args");

    args.Add("No Way Jose", "San or otherwise");
    rcManager.DoCallback("hello", "world", args);
    UT_ASSERT(str == "No Way Jose");

    UT_ASSERT_THROWS_MESSAGE("expected exception not thrown", rcManager.DoCallback("hello", "george", args), WebbyException);
}

