#include "manager.h"

Manager::Manager():
   mMQTTManager(mConfigMQTT)
{
   //Connect needed signals:
   QObject::connect( &mMQTTManager, SIGNAL(ModuleInfoReceived(Module&)),
                     &mModulesManager, SLOT(ProcessModule(Module&)) );

   qDebug() << "Is Connected Before?" << mMQTTManager.IsConnected();
   mMQTTManager.Connect();
   qDebug() << "Is Connected After?" << mMQTTManager.IsConnected();

}

ConfigurationMQTT& Manager::GetConfigMQTT()
{
   return mConfigMQTT;
}

ModuleList &Manager::GetModuleList()
{
   return mModulesManager.GetListOfModules();
}
