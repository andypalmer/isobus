#include <stdint.h>

class Message {
  public:
    Message(uint8_t from_address, unsigned char* name);
    ~Message();
    bool operator==(const Message& other) const;
    unsigned char* name() const;
  private:
    uint8_t _from_address;
    unsigned char* _name;
};
