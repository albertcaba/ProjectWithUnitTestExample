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
}


bool MQTT_Manager::Connect()
{
}

bool MQTT_Manager::IsConnected()
{
}
