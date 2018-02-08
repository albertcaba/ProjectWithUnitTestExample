#ifndef MESSAGEMQTT_H
#define MESSAGEMQTT_H

#include <stdint.h>
#include <QVector>
#include <QString>

class MessageMQTT
{
   public:
      MessageMQTT(const QString& Command, const QString& ModuleDestination,
                  uint8_t mInstruction, const QByteArray& Data);

      QString mCommand;
      QString mModuleDestination;
      uint8_t mInstruction;
      QByteArray mData;
};

#endif // MESSAGEMQTT_H
