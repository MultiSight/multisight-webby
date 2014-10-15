#ifndef RCManagerTest_h
#define RCManagerTest_h

#include "framework.h"
#include <XSDK/XHash.h>
#include <Webby/ServerSideResponse.h>


//It's in the WEBBY namespace because it's a friend to RCManager which is
//in the WEBBY namespace.
namespace WEBBY
{
class RCManagerTest : public test_fixture
{
public:
    TEST_SUITE(RCManagerTest);
        TEST(RCManagerTest::TestConstructor);
        TEST(RCManagerTest::TestRegisterResourceCallbackFuncs);
        TEST(RCManagerTest::TestDoCallback);
    TEST_SUITE_END();

    void setup();
    void teardown();

    void TestConstructor();
    void TestDoCallback();
    void TestRegisterResourceCallbackFuncs();
};
}


WEBBY::ServerSideResponse resourceFunc(const XSDK::XHash<XSDK::XString>& args, void* pContext)
{
    XSDK::XString* str = (XSDK::XString*)pContext;

    if(args.Empty())
        *str = "No Args";
    else
        *str = *args.Find(args.GetIterator().IterKey());

    WEBBY::ServerSideResponse response;

    response.SetBody("Goodbye World.");

    return response;
}

#endif
