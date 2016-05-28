/*
 * Copyright (c) 2016 Alex Spataru <alex_spataru@outlook.com>
 *
 * This file is part of the LibDS, which is released under the MIT license.
 * For more information, please read the LICENSE file in the root directory
 * of this project.
 */

#ifndef _LIB_DS_PRIVATE_CONFIG_H
#define _LIB_DS_PRIVATE_CONFIG_H

#include <Core/DS_Base.h>

/**
 * This class updates the variables of the \c DriverStation class without
 * exposing potentionally dangerous/private functions to the client.
 *
 * This class is meant to be used only by protocols, we could define these
 * functions directly with each protocol, but this could increase memory usage
 * and - if not managed correctly - cause a lot of issues with the event system
 * of Qt.
 */
class DS_Config : public DS_Base
{
    Q_OBJECT

public:
    static DS_Config* getInstance();

    int team() const;
    float voltage() const;
    bool isEnabled() const;
    Alliance alliance() const;
    Position position() const;
    bool isFMSAttached() const;
    QString libVersion() const;
    QString pcmVersion() const;
    QString pdpVersion() const;
    bool isEmergencyStopped() const;
    bool isRobotCodeRunning() const;
    bool isConnectedToRadio() const;
    bool isConnectedToRobot() const;
    ControlMode controlMode() const;
    CommStatus fmsCommStatus() const;
    EnableStatus enableStatus() const;
    CommStatus radioCommStatus() const;
    CommStatus robotCommStatus() const;
    CodeStatus robotCodeStatus() const;
    VoltageStatus voltageStatus() const;
    OperationStatus operationStatus() const;

public slots:
    void updateTeam (const int& team);
    void setRobotCode (const bool& code);
    void setEnabled (const bool& enabled);
    void updateCpuUsage (const int& usage);
    void setBrownout (const bool& brownout);
    void setEmergencyStop (const bool& estop);
    void updateVoltage (const float& voltage);
    void updateAlliance (const Alliance& alliance);
    void updatePosition (const Position& position);
    void updateLibVersion (const QString& version);
    void updatePcmVersion (const QString& version);
    void updatePdpVersion (const QString& version);
    void updateControlMode (const ControlMode& mode);
    void updateEnabled (const EnableStatus& statusChanged);
    void updateRamUsage (const int& usage, const int& total);
    void updateDiskUsage (const int& usage, const int& total);
    void updateFMSCommStatus (const CommStatus& statusChanged);
    void updateRadioCommStatus (const CommStatus& statusChanged);
    void updateRobotCommStatus (const CommStatus& statusChanged);
    void updateRobotCodeStatus (const CodeStatus& statusChanged);
    void updateVoltageStatus (const VoltageStatus& statusChanged);
    void updateOperationStatus (const OperationStatus& statusChanged);

protected:
    DS_Config();

private:
    int m_team;
    float m_voltage;
    Alliance m_alliance;
    Position m_position;
    QString m_libVersion;
    QString m_pcmVersion;
    QString m_pdpVersion;
    CodeStatus m_codeStatus;
    ControlMode m_controlMode;
    CommStatus m_fmsCommStatus;
    EnableStatus m_enableStatus;
    CommStatus m_radioCommStatus;
    CommStatus m_robotCommStatus;
    VoltageStatus m_voltageStatus;
    OperationStatus m_operationStatus;
};

#endif
