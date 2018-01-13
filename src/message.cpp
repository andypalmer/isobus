#include <iostream>
#include "../include/message.hpp"

Message::Message(uint8_t from_address, unsigned char* name) : _from_address(from_address), _name(name) {
  std::cout << "Constructor " << (int) _from_address << 8 << std::endl;
}

Message::~Message() {
  std::cout << "Destructor" << std::endl;
}

bool Message::operator==(const Message& other) const {
  if(_name) {};
  std::cout << _name << " = " << other._name << memcmp(_name, other._name, 4) << std::endl;
  std::cout << _from_address << " = " << other._from_address << std::endl;
  return memcmp(_name, other._name, 4) == 0;
}

unsigned char* Message::name() const {
  return _name;
}
