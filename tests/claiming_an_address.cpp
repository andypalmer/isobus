#include "CppUTest/TestHarness.h"

TEST_GROUP(Claiming_An_Address) {
};

/*
 * I can say something. When do I say it? Who/what do I say it to?
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
 *
 * Non-trivial conversation with address contention
 * I'm Andy and my address is 3
 * I'm Antony and my address is 5
 * I'm Angela and my address is 3
 * I'm Andy and my address is 3
 * I'm Angela and my address is 5
 * I'm Antony and my address is 7
 */

TEST(Claiming_An_Address, when_theres_nobody_else ) {
  // party = new Party();
  // andy = new Attendee(name: Andy, preferred_address: 3);
  // andy.join(party);
  // assertThat(party.messages.latest, is(equalTo("My name is Andy and my address is 3")));
}
