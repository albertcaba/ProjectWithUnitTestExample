#include "messagemqtt.h"

MessageMQTT::MessageMQTT(const QString &Command, const QString &ModuleDestination, uint8_t Instruction, const QByteArray &Data)
   :mCommand(Command), mModuleDestination(ModuleDestination), mInstruction(Instruction), mData(Data)
{

}
