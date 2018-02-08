#include "module.h"

/*
Module::Module()
{
#warning DELETE
   mName = "DEFAULT";
   mAppName = "DEFUALT";
}
*/

Module::Module()
   : mApp(App::AppType::LAST_INVALID_VALUE)
{
   mName = "DEFAULT";
   mAppName = mApp.getAppName();
   //mAppName = "DEFUALT";
}

Module::Module(const QString &ModuleName, App::AppType app, QDateTime TimeToSet):
   mName(ModuleName), mApp(app) /*, mApp(App)*/
{
   //mApp = AppTypeToString(App);
   UpdateLastConnection(TimeToSet);
   mAppName = mApp.getAppName();
}

bool Module::UpdateLastConnection(QDateTime TimeToSet)
{
   mLastConnection = TimeToSet.toString();
}

