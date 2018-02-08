#ifndef GUICONTROLLER_H
#define GUICONTROLLER_H

#include <QQmlApplicationEngine>
//Module List Tab:
#include "../Models/modulelist.h"
#include "../Models/modulelistmodel.h"
#include "../Modules/MQTT/configurationMQTT.h"

class GUIController
{
   public:
      //GUIController(QQmlApplicationEngine& engine);
      GUIController(ConfigurationMQTT& ConfigMQTT, ModuleList& ModuleListToSet);
      bool Init();

   private:
      bool InitModuleListTab();
      bool InitConfigTab();

   private:
      QQmlApplicationEngine mEngine;
      //ModuleList moduleList;
      ModuleList& moduleList;
      ConfigurationMQTT& mConfigMQTT;
};

#endif // GUICONTROLLER_H
