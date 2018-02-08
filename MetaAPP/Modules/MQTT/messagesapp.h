#ifndef MESSAGESAPP_H
#define MESSAGESAPP_H

#warning DELETE THIS FILE IN THE FUTURE!
#include <stdint.h>
#include <QString>

namespace Instruction_Wifi
{
   const uint8_t DLE = 0x10; //STX
   const uint8_t StartOfFrame = 0x02; //STX
   const uint8_t EndOfFrame = 0x03;// ETX

   enum DataArray_Positions
   {
      Position_DLE_SOF =0,
      Position_SOF =1,
      Position_Instruction,
      Position_DataSize,
      Position_Data,
   };
}

namespace Instruction_ModuleAlive
{
   const QString PublishTo = "/last_connection/";
   const uint8_t Instruction_Alive = 0x00;

   enum Position
   {
      Position_Hora = 4,
      Position_Minut,
      Position_Dia,
      Position_Mes,
      Position_Any,
      Position_AppRunning,
      Position_FW_Version,
      Position_DLE_EOF
   };

}

namespace Instruction_AppToRun
{
   const uint8_t Instruction_AppToRun_WithoutConfig = 0x00;
   const uint8_t Instruction_AppToRun_WithConfig = 0x01;

   const uint8_t APP_Invalid = 0xFF;
   const uint8_t APP_Leds = 0x00;
   const uint8_t APP_Irrigation = 0x01;
   const uint8_t APP_Alarm = 0x02;
   const uint8_t APP_Security = 0x03;
   const uint8_t APP_Servo = 0x04;
   const uint8_t APP_SecurityLeds = 0x05;

   const uint8_t APP_LastValidAPP = APP_SecurityLeds;
}

namespace Instruction_ExecuteOrder
{
   const uint8_t Restart = 0;
}

namespace Instruction_APP_Leds
{
   const uint8_t Request_Off = 0x00;
   const uint8_t Request_ColorBeat = Request_Off+1;
   const uint8_t Request_Wave = Request_Off + 2;
   const uint8_t Request_FullColor= Request_Off + 3;
   const uint8_t Request_Christmas = Request_Off + 4;
   const uint8_t Request_FCB = Request_Off + 5;
   const uint8_t Request_Rainbow = Request_Off + 6;
   const uint8_t Request_ColorWipe = Request_Off + 7;
}


namespace Instruction_APP_Irrigation
{
      const uint8_t Request_Humidity = 0x01;
      const uint8_t Request_Status = 0x02;
      const uint8_t Request_Last_Irrigation = 0x03;
      const uint8_t Request_Change_Config = 0x04;
      const uint8_t Request_Alive = 0x05;
      const uint8_t Request_SndMsgIrrigation = 0x06;

      const uint8_t ACK_InstructionReceived = 0xAA;

      const uint8_t Answer_Humidity = 0x81;
      const uint8_t Answer_Status = 0x82;
      const uint8_t Answer_LastIrrigation = 0x83;
      const uint8_t Answer_Change_Config = 0x84;
      const uint8_t Answer_Alive = 0x85;
      const uint8_t Answer_SndMsgIrrigation = 0x86;

      enum Position
      {
         Position_Hora = 4,
         Position_Minut,
         Position_Dia,
         Position_Mes,
         Position_Any,
         Position_AppRunning,
         Position_DLE_EOF
      };
}

namespace Instruction_APP_Alarm
{
   const uint8_t Request_StopAlarm = 0x00;
   const uint8_t Request_Off = 0x01;
   const uint8_t Request_StartAlarm = 0x02;
}

namespace Instruction_APP_Security
{
   // Enabling/Disabling messages:
   const uint8_t Request_ArmSecurity = 0x00;
   const uint8_t Request_ArmSecurity_NightMode = 0x0A;
   const uint8_t Request_DisarmSecurity = 0x01;

   // Alarm Triggered messages:
   const uint8_t Alarm_Warning = 0x02;
   const uint8_t Alarm_Notification = 0x03;
   const uint8_t Alarm_Disabled = 0x04;

   //Configuration Positions
   namespace Configuration_Position
   {
      const uint8_t Position_NumberLeds = 0;
      const uint8_t Position_TriggerLeds = 1;
      const uint8_t Position_PIR = 2;
      const uint8_t Position_RemoteControl = 3;
      const uint8_t Position_DeepSleep = 4;
      const uint8_t Position_RFID = 5;
      const uint8_t Position_ArmedAtNight = 6;
      const uint8_t Position_SizeLinkedGroup = 7;
      const uint8_t Position_LinkedGroup = 8;
   }
}

namespace Instruction_APP_Servo
{
   //Set/Get predefined positions:
   const uint8_t Request_Idle = 0x00;
   const uint8_t Request_Toggle_1 = 0x01;
   const uint8_t Request_Toggle_2 = 0x02;
   const uint8_t Answer_Idle = 0x03;
   const uint8_t Answer_Toggle_1 = 0x04;
   const uint8_t Answer_Toggle_2 = 0x05;

   // Specific position:
   const uint8_t Request_GetPosition = 0x06;
   const uint8_t Answer_GetPosition = 0x07;
   const uint8_t Request_SetPosition = 0x08;
   const uint8_t Answer_SetPosition = 0x09;

   //Config predefined positions:
   const uint8_t Request_SetPosition_Idle = 10;
   const uint8_t Request_SetPosition_Toggle_1 = 11;
   const uint8_t Request_SetPosition_Toggle_2 = 12;
   const uint8_t Answer_SetPosition_Idle = 13;
   const uint8_t Answer_SetPosition_Toggle_1 = 14;
   const uint8_t Answer_SetPosition_Toggle_2 = 15;

   const uint8_t Request_GetPosition_Idle = 16;
   const uint8_t Request_GetPosition_Toggle_1 = 17;
   const uint8_t Request_GetPosition_Toggle_2 = 18;
   const uint8_t Answer_GetPosition_Idle = 19;
   const uint8_t Answer_GetPosition_Toggle_1 = 20;
   const uint8_t Answer_GetPosition_Toggle_2 = 21;
}

#endif // MESSAGESAPP_H
