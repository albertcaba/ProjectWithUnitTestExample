#include "mqttmessageparser.h"
#include <QLoggingCategory>

MessageMQTT* MQTTMessageParser::ParseMessage(const QMqttMessage &MessageToParse)
{

   //Check if message is valid first:
   bool IsTopicValid = (MessageToParse.topic().isValid() && MessageToParse.topic().levelCount() > 1);
   bool IsMessageHeaderValid = ( (MessageToParse.payload().at(Position_DLE_SOF) == DLE) &&
                                 (MessageToParse.payload().at(Position_SOF) == StartOfFrame) );

   uint8_t DataSize = MessageToParse.payload().at(Position_DataSize) ;
   bool IsMessageTailValid = (MessageToParse.payload().at(Position_DataSize+DataSize+1) == DLE &&
                              (MessageToParse.payload().at(Position_DataSize+DataSize+2) == EndOfFrame) );

   if (IsTopicValid && IsMessageHeaderValid && IsMessageTailValid)
   {
      qDebug() << "Message Invalid!";
      QStringList Topic = MessageToParse.topic().levels();
      QString Command = Topic.at(0);
      QString ModuleDestination = Topic.at(1);
      int Instruction = MessageToParse.payload().at(Position_Instruction);

      QByteArray Data = MessageToParse.payload().mid(Position_Data,DataSize);

      return new MessageMQTT(Command,ModuleDestination,Instruction,Data);
   }
   else
   {
      qDebug() << "ERROR IN MQTTMessageParser::ParseMessage";
      return nullptr;
   }

}
