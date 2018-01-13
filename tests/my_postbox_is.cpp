#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "../include/message.hpp"


class PostOffice {
  public:
    PostOffice() {}
    void send(Message message) {
      mock("PostOffice").actualCall("send").withParameterOfType("message", "message", &message);
    }
};


class MessageComparator : public MockNamedValueComparator {
  public:
    virtual bool isEqual(const void* object1, const void* object2) {
      return *((Message*)object1) == *(Message*)object2;
    }

    virtual SimpleString valueToString(const void* object) {
      return StringFrom((char*)((Message*)object)->name());
    }
};

TEST_GROUP(ClaimingAPostbox) {
};

TEST(ClaimingAPostbox, claims_a_postbox_on_startup) {
  MessageComparator message_comparator;
  mock("PostOffice").installComparator("message", message_comparator);
  Message expected_message(3, (unsigned char*) "Andy");
  //Message* expected_message2 = new Message(3, (unsigned char*) "Andy");
  //if(*expected_message == *expected_message2) {}
  mock("PostOffice").expectOneCall("send").withParameterOfType("message", "message", &expected_message);
  PostOffice().send(Message(3,(unsigned char*) "Andy"));
  mock().checkExpectations();
  mock().clear();
}
/*
TEST(ClaimingAPostbox, claims_a_different_postbox_when_evicted) {
  mock().strictOrder();
  mock().expectOneCall("my_postbox_is").withParameter("postbox_number", 3);
  mock().expectOneCall("my_postbox_is").withParameter("postbox_number", 5);
  my_postbox_is(5);
  my_postbox_is(3);
  mock().checkExpectations();
  mock().clear();
}
*/
