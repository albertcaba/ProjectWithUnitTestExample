#ifndef MANAGER_H
#define MANAGER_H

#include "MQTT/configurationMQTT.h"
#include "MQTT/mqtt_manager.h"
#include "modules_manager.h"
#include "module.h"

class Manager
{
   public:
      Manager();
      ConfigurationMQTT& GetConfigMQTT();
      ModuleList& GetModuleList();

   private:
      ConfigurationMQTT mConfigMQTT;
      Modules_Manager mModulesManager;
      MQTT_Manager mMQTTManager;
};

#endif // MANAGER_H
