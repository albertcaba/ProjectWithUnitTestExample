#include "guicontroller.h"
#include <QtQml/QQmlContext>
#include <QLoggingCategory>
GUIController::GUIController(ConfigurationMQTT& ConfigMQTT, ModuleList& ModuleListToSet):
   mConfigMQTT(ConfigMQTT), moduleList(ModuleListToSet)
{
   //qDebug() << __FUNCTION__;
}

bool GUIController::Init()
{
   QQmlApplicationEngine mEngine;

   return InitModuleListTab() && InitConfigTab();
}

bool GUIController::InitModuleListTab()
{
   bool result = false;
   qDebug() << __FUNCTION__;

   qmlRegisterType<ModuleListModel>("ModuleModelNameToImportToQML", 1, 0, "ModuleListModel");
   qmlRegisterUncreatableType<ModuleList>("ModuleModelNameToImportToQML", 1, 0, "ModuleList",
                                          QStringLiteral("Module should not be created in QML"));

   mEngine.rootContext()->setContextProperty(QStringLiteral("moduleList"), &moduleList);

   mEngine.load(QUrl(QLatin1String("qrc:/main.qml")));

   if (mEngine.rootObjects().isEmpty())
   {
      result = false;
   }
   else
   {
      result = true;
   }

   //qDebug() << result;
   return result;
}

bool GUIController::InitConfigTab()
{
   //qDebug() << __FUNCTION__;
   //mEngine.rootContext()->setContextProperty(QStringLiteral("configMQTT"), &mConfigMQTT);

   QObject *rootObject = mEngine.rootObjects().first();
   QObject *qmlConfigurationTab = rootObject->findChild<QObject*>("ConfigurationTab");

   if (qmlConfigurationTab)
   {
      //qDebug() << "FOUND qmlConfigurationTab";
      QObject::connect(qmlConfigurationTab, SIGNAL(submitConfiguration(QString,QString,QString,int)),
                       &mConfigMQTT, SLOT(SetConfigurationMQTT(QString,QString,QString,int)));

      if (mConfigMQTT.IsThereAValidConfiguration())
      {
         //qDebug() << "There is a valid MQTT Config";

         QObject *qmlHostnameInput = rootObject->findChild<QObject*>("textInput_hostname");
         QObject *qmlUserInput = rootObject->findChild<QObject*>("textInput_user");
         QObject *qmlPasswordInput = rootObject->findChild<QObject*>("textInput_password");
         QObject *qmlPortInput = rootObject->findChild<QObject*>("textInput_port");

         if (qmlHostnameInput != nullptr) qmlHostnameInput->setProperty("text", mConfigMQTT.GetHostname());
         if (qmlUserInput != nullptr) qmlUserInput->setProperty("text", mConfigMQTT.GetUser());
         if (qmlPasswordInput != nullptr) qmlPasswordInput->setProperty("text", mConfigMQTT.GetPassword());
         if (qmlPortInput != nullptr) qmlPortInput->setProperty("text", mConfigMQTT.GetPort());
      }
   }

   return true;
}

