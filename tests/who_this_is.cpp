#include "CppUTest/TestHarness.h"

TEST_GROUP(JoiningTheParty) {
};

TEST(JoiningTheParty, an_announcement ) {
  unsigned int priority = 6;
  unsigned int extended_data_page = 0;
  unsigned int data_page = 0;
  unsigned long iso_address_claim_pgn = 60928;
  unsigned int destination_address = 0xff;
  unsigned int my_address = 3;

  unsigned long canbus_id =
      priority << 26
    | extended_data_page << 25
    | data_page << 24
    | iso_address_claim_pgn << 8
    | destination_address << 8
    | my_address;

  LONGS_EQUAL(0x18eeff03, canbus_id);
}
