#ifndef MQTT_MANAGER_H
#define MQTT_MANAGER_H

#include <QObject>
#include <QTimer>
#include "configurationMQTT.h"
#include "../module.h"
#include <QtMqtt/QMqttClient>
#include <QDateTime>
#include "messagesapp.h"

class MQTT_Manager : public QObject
{
   Q_OBJECT
   public:
      MQTT_Manager(ConfigurationMQTT& configMQTT, QObject *parent = nullptr);
      bool Connect();
      bool IsConnected();

   signals:
      void ModuleInfoReceived(Module& ModuleInfo);
      void ModuleConfigReceived(const uint8_t * ptrToData, size_t DataSize);

   private:

   private slots:
      void TimerHandlerFunction(); //#TODO: Only for test. Deltet!

   private:
      ConfigurationMQTT& mConfigMQTT;
      QMqttClient mMQTTClient;
      QTimer m_timer; //#TODO: Only for test. Deltet!
};


#endif // MQTT_MANAGER_H
