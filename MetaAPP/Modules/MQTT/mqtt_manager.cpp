#include "mqtt_manager.h"
#include <QLoggingCategory>
#include <QThread>

MQTT_Manager::MQTT_Manager(ConfigurationMQTT &configMQTT, QObject *parent):
   QObject(parent), mConfigMQTT(configMQTT)
{
   qDebug() << __FUNCTION__;
   connect(&m_timer, SIGNAL(timeout()), this, SLOT(TimerHandlerFunction()));
   m_timer.start(2000);

}

void MQTT_Manager::TimerHandlerFunction()
{
   qDebug() << __FUNCTION__;
   static int counter = 0;

    QString ModuleName = "CACA";
    ModuleName.append(counter);
    Module modulefound(ModuleName,App::AppType::SECURITY_LEDS,QDateTime::currentDateTime());

    qDebug() << " ModuleFound:" << ModuleName << QThread::currentThreadId();
    emit ModuleInfoReceived(modulefound);

    counter++;
}


bool MQTT_Manager::Connect()
{
   mMQTTClient.setUsername(mConfigMQTT.GetUser());
   mMQTTClient.setHostname(mConfigMQTT.GetHostname());
   mMQTTClient.setPassword(mConfigMQTT.GetPassword());
   mMQTTClient.setPort(mConfigMQTT.GetPort());
   mMQTTClient.connectToHost();
}

bool MQTT_Manager::IsConnected()
{
   if (mMQTTClient.state() == QMqttClient::Connected)
   {
      return true;
   }
   else
   {
      return false;
   }
}
