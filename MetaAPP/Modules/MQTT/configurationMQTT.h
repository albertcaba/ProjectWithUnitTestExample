#ifndef CONFIGURATION_MQTT_H
#define CONFIGURATION_MQTT_H

#include <QSettings>
#include <QObject>
#include <QCoreApplication>
//#include <QApplication>

class ConfigurationMQTT : public QObject
{
      Q_OBJECT
   public:
      ConfigurationMQTT();
      bool IsThereAValidConfiguration();
      bool GetConfiguration(QString& HostName, QString& User, QString& Password, int& Port);

      //DATA:
      QString GetHostname() const;
      QString GetUser() const;
      QString GetPassword() const;
      int GetPort() const;

   public slots:
      bool SetConfigurationMQTT(const QString& HostName, const QString& User, const QString& Password,int Port);

   private:
      bool LoadConfiguration();
      bool SaveConfiguration();

      QString mHostname;
      QString mUser;
      QString mPassword;
      int mPort;
      //bool mIsThereValidConfiguration;
      QString m_sSettingsFile;
};

#endif // CONFIGURATION_H
