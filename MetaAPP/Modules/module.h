#ifndef MODULE_H
#define MODULE_H

#include <QObject>
#include <QDateTime>
#include "app.h"

class Module
{
   public:
      Module();
      Module( const QString& ModuleName, App::AppType app, QDateTime TimeToSet);
      bool UpdateLastConnection(QDateTime TimeToSet);

#warning FER PRIVAT!
      QString   mName;
      QString   mAppName;
      QString   mLastConnection;
   private:
      App mApp;
      //QString mName;
      //AppType mApp;
};

#endif // MODULE_H
