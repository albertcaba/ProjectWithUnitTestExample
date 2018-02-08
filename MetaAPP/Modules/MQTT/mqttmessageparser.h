#ifndef MQTTMESSAGEPARSER_H
#define MQTTMESSAGEPARSER_H

#include <QString>
#include <stdint.h>
#include <QMqttMessage>
#include "messagemqtt.h"

class MQTTMessageParser
{
   //public:
   //MQTTMessageParser();

   static MessageMQTT* ParseMessage(const QMqttMessage& MessageToParse);
   private:
      const static uint8_t DLE = 0x10; //STX
      const static uint8_t StartOfFrame = 0x02; //STX
      const static uint8_t EndOfFrame = 0x03;// ETX

      enum DataArray_Positions
      {
         Position_DLE_SOF =0,
         Position_SOF =1,
         Position_Instruction,
         Position_DataSize,
         Position_Data,
      };
};

#endif // MQTTMESSAGEPARSER_H
