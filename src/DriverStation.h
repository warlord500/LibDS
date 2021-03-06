/*
 * Copyright (c) 2016 Alex Spataru <alex_spataru@outlook.com>
 *
 * This file is part of the LibDS, which is released under the MIT license.
 * For more information, please read the LICENSE file in the root directory
 * of this project.
 */

#ifndef _LIB_DS_DRIVERSTATION_H
#define _LIB_DS_DRIVERSTATION_H

#include <Core/DS_Base.h>

class Sockets;
class Watchdog;
class Protocol;
class DS_Config;
class NetConsole;

/**
 * \brief Exposes the functionality of the LibDS to the application
 *
 * The \c DriverStation class exposes the \c LibDS library to the application,
 * and implements functions that allow the safe operation of robots, protocol
 * switching/lodaing and joystick management.
 *
 * The \c DriverStation class provides several reduntant functions in order to
 * be more user-friendly and giving application developers more flexibility
 * regarding the use of LibDS types.
 */
class DriverStation : public DS_Base {
    Q_OBJECT
    Q_ENUMS (ProtocolType)
    Q_ENUMS (TeamStation)

  signals:
    void resetted();
    void initialized();
    void logFileChanged();
    void protocolChanged();
    void joystickCountChanged (int count);
    void newMessage (const QString& message);

  public:
    static DriverStation* getInstance();
    static void logger (QtMsgType type,
                        const QMessageLogContext& context,
                        const QString& data);

    enum ProtocolType {
        kFRC2016 = 0,
        kFRC2015 = 1,
        kFRC2014 = 2,
    };

    enum TeamStation {
        kRed1  = 0,
        kRed2  = 1,
        kRed3  = 2,
        kBlue1 = 3,
        kBlue2 = 4,
        kBlue3 = 5,
    };

    Q_INVOKABLE bool canBeEnabled();
    Q_INVOKABLE bool running() const;
    Q_INVOKABLE bool isInTest() const;
    Q_INVOKABLE bool isEnabled() const;
    Q_INVOKABLE bool isSimulated() const;
    Q_INVOKABLE bool isInAutonomous() const;
    Q_INVOKABLE bool isInTeleoperated() const;
    Q_INVOKABLE bool isConnectedToFMS() const;
    Q_INVOKABLE bool isVoltageBrownout() const;
    Q_INVOKABLE bool isEmergencyStopped() const;
    Q_INVOKABLE bool isConnectedToRobot() const;
    Q_INVOKABLE bool isConnectedToRadio() const;
    Q_INVOKABLE bool isRobotCodeRunning() const;

    Q_INVOKABLE QString logsPath() const;
    Q_INVOKABLE QVariant logVariant() const;
    Q_INVOKABLE QStringList availableLogs() const;
    Q_INVOKABLE QJsonDocument logDocument() const;

    Q_INVOKABLE qreal maxBatteryVoltage() const;
    Q_INVOKABLE qreal currentBatteryVoltage() const;
    Q_INVOKABLE qreal nominalBatteryAmperage() const;

    Q_INVOKABLE int team() const;
    Q_INVOKABLE int cpuUsage() const;
    Q_INVOKABLE int ramUsage() const;
    Q_INVOKABLE int diskUsage() const;
    Q_INVOKABLE int packetLoss() const;
    Q_INVOKABLE int maxPOVCount() const;
    Q_INVOKABLE int maxAxisCount() const;
    Q_INVOKABLE int maxButtonCount() const;
    Q_INVOKABLE int maxJoystickCount() const;

    Q_INVOKABLE int getNumAxes (int joystick);
    Q_INVOKABLE int getNumPOVs (int joystick);
    Q_INVOKABLE int getNumButtons (int joystick);
    Q_INVOKABLE int getRealNumAxes (int joystick);
    Q_INVOKABLE int getRealNumPOVs (int joystick);
    Q_INVOKABLE int getRealNumButtons (int joystick);

    Q_INVOKABLE int joystickCount();
    Q_INVOKABLE DS_Joysticks* joysticks();

    Q_INVOKABLE Alliance alliance() const;
    Q_INVOKABLE Position position() const;
    Q_INVOKABLE ControlMode controlMode() const;
    Q_INVOKABLE CommStatus fmsCommStatus() const;
    Q_INVOKABLE EnableStatus enableStatus() const;
    Q_INVOKABLE CommStatus radioCommStatus() const;
    Q_INVOKABLE CommStatus robotCommStatus() const;
    Q_INVOKABLE CodeStatus robotCodeStatus() const;
    Q_INVOKABLE VoltageStatus voltageStatus() const;

    Q_INVOKABLE QString fmsAddress() const;
    Q_INVOKABLE QString radioAddress() const;
    Q_INVOKABLE QString robotAddress() const;
    Q_INVOKABLE QString generalStatus() const;
    Q_INVOKABLE QString customFMSAddress() const;
    Q_INVOKABLE QString customRadioAddress() const;
    Q_INVOKABLE QString customRobotAddress() const;
    Q_INVOKABLE QString defaultFMSAddress() const;
    Q_INVOKABLE QString defaultRadioAddress() const;
    Q_INVOKABLE QString defaultRobotAddress() const;
    Q_INVOKABLE OperationStatus operationStatus() const;

    Q_INVOKABLE QStringList protocols() const;
    Q_INVOKABLE QStringList teamStations() const;

    Q_INVOKABLE bool registerJoystick (int axes, int buttons, int povs);

  public slots:
    void init();
    void browseLogs();
    void rebootRobot();
    void enableRobot();
    void openLogsPath();
    void disableRobot();
    void resetJoysticks();
    void setTeam (int team);
    void restartRobotCode();
    void switchToTestMode();
    void switchToAutonomous();
    void switchToTeleoperated();
    void triggerEmergencyStop();
    void reconfigureJoysticks();
    void removeJoystick (int id);
    void setEnabled (bool enabled);
    void setTeamStation (int station);
    void openLog (const QString& file);
    void setProtocolType (int protocol);
    void setAlliance (Alliance alliance);
    void setPosition (Position position);
    void setProtocol (Protocol* protocol);
    void setControlMode (ControlMode mode);
    void updatePOV (int id, int pov, int angle);
    void setEnabled (EnableStatus statusChanged);
    void updateAxis (int id, int axis, qreal value);
    void updateButton (int id, int button, bool state);
    void setCustomFMSAddress   (const QString& address);
    void setCustomRadioAddress (const QString& address);
    void setCustomRobotAddress (const QString& address);
    void setOperationStatus (OperationStatus statusChanged);

  private slots:
    void stop();
    void start();
    void resetFMS();
    void resetRadio();
    void resetRobot();
    void finishInit();
    void sendFMSPacket();
    void updateAddresses();
    void sendRadioPacket();
    void sendRobotPacket();
    void updatePacketLoss();
    void updateAddresses (int unused);
    void updateLogs (const QString& file);
    void readFMSPacket (const QByteArray& data);
    void readRadioPacket (const QByteArray& data);
    void readRobotPacket (const QByteArray& data);

  protected:
    explicit DriverStation();
    ~DriverStation();

  private:
    bool m_init;
    bool m_running;

    int m_packetLoss;
    int m_fmsInterval;
    int m_radioInterval;
    int m_robotInterval;

    QString m_logDocumentPath;

    DS_Joysticks m_joysticks;
    QString m_customFMSAddress;
    QJsonDocument m_logDocument;
    QString m_customRadioAddress;
    QString m_customRobotAddress;

    Sockets* m_sockets;
    Protocol* m_protocol;
    NetConsole* m_console;

    Watchdog* m_fmsWatchdog;
    Watchdog* m_radioWatchdog;
    Watchdog* m_robotWatchdog;

    DS_Config* config() const;
    Protocol* protocol() const;
};

#endif
