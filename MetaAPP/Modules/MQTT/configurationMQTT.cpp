#include "configurationMQTT.h"
#include <QLoggingCategory>
#include <QDir>

ConfigurationMQTT::ConfigurationMQTT()
{
   m_sSettingsFile = QDir::homePath() + "/ConfigMQTT.ini"; //QApplication::applicationDirPath()+ "/ConfigMQTT.ini";
   qDebug() << " Config :"<< m_sSettingsFile;
   LoadConfiguration();
}

bool ConfigurationMQTT::IsThereAValidConfiguration()
{
   if ( !mHostname.isEmpty() )
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool ConfigurationMQTT::GetConfiguration(QString &HostName, QString &User, QString &Password, int &Port)
{
   HostName = mHostname;
   User = mUser;
   Password = mPassword;
   Port = mPort;

   return IsThereAValidConfiguration();
}

bool ConfigurationMQTT::SetConfigurationMQTT(const QString &HostName, const QString &User, const QString &Password, int Port)
{
   qDebug() << __FUNCTION__;
   mHostname = HostName;
   mUser = User;
   mPassword = Password;
   mPort = Port;

   return IsThereAValidConfiguration() && SaveConfiguration();
}

bool ConfigurationMQTT::LoadConfiguration()
{
   qDebug() << __FUNCTION__;
   QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
   mHostname = settings.value("HostName", "").toString();
   mUser = settings.value("User", "").toString();
   mPassword = settings.value("Password", "").toString();
   mPort = settings.value("Port", "").toInt();

   qDebug() << "mHostname:" << mHostname;
}

bool ConfigurationMQTT::SaveConfiguration()
{
   qDebug() << __FUNCTION__;
   qDebug() << "mHostname:" << mHostname;
   QSettings settings(m_sSettingsFile, QSettings::NativeFormat);
   settings.setValue("HostName",mHostname);
   settings.setValue("User",mUser);
   settings.setValue("Password",mPassword);
   settings.setValue("Port",mPort);
}

QString ConfigurationMQTT::GetHostname() const
{
   return mHostname;
}

QString ConfigurationMQTT::GetUser() const
{
   return mUser;
}

QString ConfigurationMQTT::GetPassword() const
{
   return mPassword;
}

int ConfigurationMQTT::GetPort() const
{
   return mPort;
}


