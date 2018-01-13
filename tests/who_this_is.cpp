#include "CppUTest/TestHarness.h"

TEST_GROUP(PhraseBook_JoiningTheParty) {
};

unsigned long canbus_id_for(unsigned long);
unsigned long canbus_id_for(unsigned long pgn) {
  const unsigned int everyone = 0xff;

  unsigned int priority = 6;
  unsigned int extended_data_page = 0;
  unsigned int data_page = 0;
  unsigned int destination_address = everyone;
  unsigned int my_address = 3;

  unsigned long canbus_id =
      priority << 26
    | extended_data_page << 25
    | data_page << 24
    | pgn << 8
    | destination_address << 8
    | my_address;

  return canbus_id;
}

/*
 * When I join the party, I say...
 * When someone else says X, I say Y
 *
 * My name is Andy and I respond to: 3
 * Appellation, nickname, sobriquet, designation
 *
 * actor.named("Andy");
 * actor.nicknamed(3);
 * hear(antony, say(my_nickname_is(3)));
 * respond(my_nickname_is(3));
 *
 * assert_that(the_party, was_told(my_nickname_is(3), by(andy));
 *
 * actor.named("Antony")
 * actor.nicknamed(3);
 * hear(andy, say(my_nickname_is(3)));
 * respond(my_nickname_is(something_else));
 *
 * assert_that(the_party, was_told(my_nickname_is_anything_but(3), by(antony));
 *
 * party.tell_everyone(message);
 * party.tell(everyone, message);
 * party.tell(someone_specific, message);
 *
 */


/*
 * I can say something. When do I say it?
 * I say "Who I am" when I am switched on
 *   + <0x18eeff01> [8] 05 a0 be 1c 00 a0 a0 c0
 * I say "who I am" when someone else claims the same address
 *   - when I win, I claim the same address
 *     + <0x18eeff03> [8] 05 a0 be 1c 00 a0 a0 c0
 *   - when they win, I use a different address
 *     + <0x18eeff01> [8] 05 a0 be 1c 00 a0 a0 c0
 * I say "who I am" when I'm asked who I am (59904: 60928) ** <0x18eaff01> [3] 00 ee 00
 *   + <0x18eeff01> [8] 05 a0 be 1c 00 a0 a0 c0
 *
 * For the purposes of a simple test, if two devices have the same NAME (ie. the data of 60928), then the first one on the bus will choose a new address
 * This is because he doesn't beat the name of the new device
 * In practice, no two devices should have the same name because that could lead to odd behaviour.
 * For example, something monitoring the bus and recording historical usage would (without warning) swap recording from the old device to the new device
 * This simplification lets us get something working with real devices sooner rather than later, without having to implement serial numbering.
 *
 * We might want to have a set of rules for passing messages onto the logic. E.g.
 * I am interested in this message if it's for everybody
 * I am interested in this message if it's specifically for me
 * I am interested in this message if it's claiming my current address
 */


TEST(PhraseBook_JoiningTheParty, how_to_tell_everyone_who_this_is ) {
  const unsigned long iso_address_claim_pgn = 60928;

  LONGS_EQUAL(0x18eeff03, canbus_id_for(iso_address_claim_pgn));
}

TEST(PhraseBook_JoiningTheParty, how_to_tell_everyone_to_tell_me_something ) {
  const unsigned long iso_request_pgn = 59904;

  LONGS_EQUAL(0x18eaff03, canbus_id_for(iso_request_pgn));
}

// INT8U sendMsgBuf(INT32U id, INT8U len, INT8U *buf);
#ifndef INT32U
#define INT32U uint32_t
#endif

#ifndef INT8U
#define INT8U uint8_t
#endif

class MCP_CAN {
  public:
    MCP_CAN();
    void sendMsgBuf(INT32U, INT8U, INT8U);
    void should_have_received(INT32U);
};

TEST(PhraseBook_JoiningTheParty, how_to_tell_everyone_who_this_is_2 ) {
  /*
  INT32U tell_everyone_who_this_is = 0x18eeff03;
  INT8U data = 0;
  INT8U length_of_data = 0;
  MCP_CAN bus = MCP_CAN();
  bus.sendMsgBuf(tell_everyone_who_this_is, length_of_data, data);
  bus.should_have_received(tell_everyone_who_this_is);
  */

  /*
  party = something_like_canbus;
  actor.joins(party);
  actor.can_respond_to(who_i_am, i_want_to_know, the_fuel_level_is...);
  actor.announce(what_i_want_to_say);
  actor.hears(who_i_am); // does he need to respond?
  */
}

// I claim an address, nobody else claims that address
// Somebody tries to claim my address, I win and reclaim the address
// Somebody tries to claim my address, they win, I claim a new address
