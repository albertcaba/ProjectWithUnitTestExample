#ifndef APPMESSAGEPARSER_H
#define APPMESSAGEPARSER_H

#include <stdint.h>
#include <cstddef>
class AppMessageParser
{
   public:
      bool ParseConfiguration(const uint8_t * ptrToData, std::size_t DataSize);
      //AppMessageParser();
};

#endif // APPMESSAGEPARSER_H
