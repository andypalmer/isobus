#include "CppUTest/TestHarness.h"

TEST_GROUP(JoiningTheParty) {
};

TEST(JoiningTheParty, tell_everyone_who_this_is ) {
  const unsigned int everyone = 0xff;
  const unsigned long iso_address_claim_pgn = 60928;

  unsigned int priority = 6;
  unsigned int extended_data_page = 0;
  unsigned int data_page = 0;
  unsigned long pgn = iso_address_claim_pgn;
  unsigned int destination_address = everyone;
  unsigned int my_address = 3;

  unsigned long canbus_id =
      priority << 26
    | extended_data_page << 25
    | data_page << 24
    | pgn << 8
    | destination_address << 8
    | my_address;

  LONGS_EQUAL(0x18eeff03, canbus_id);
}

TEST(JoiningTheParty, tell_everyone_to_tell_me ) {
  const unsigned int everyone = 0xff;
  const unsigned long iso_request_pgn = 59904;

  unsigned int priority = 6;
  unsigned int extended_data_page = 0;
  unsigned int data_page = 0;
  unsigned long pgn = iso_request_pgn;
  unsigned int destination_address = everyone;
  unsigned int my_address = 3;

  unsigned long canbus_id =
      priority << 26
    | extended_data_page << 25
    | data_page << 24
    | pgn << 8
    | destination_address << 8
    | my_address;

  LONGS_EQUAL(0x18eaff03, canbus_id);
}
