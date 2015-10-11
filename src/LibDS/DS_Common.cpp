/*
 * Copyright (c) 2015 WinT 3794 <http://wint3794.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "LibDS/DS_Common.h"

#include <QDateTime>
#include <QTimeZone>

int DS_PingData::generatePingData (int index) {
    index += 1;

    if (index > 0xffff)
        index = 0;

    byte1 = index / 0xff;
    byte2 = index % 0xff;

    return index;
}

short DS_PingData::getPingIndex() {
    return byte1 * 0xff + byte2;
}

QString DS_GetStaticIp (int team, int host) {
    QString string = QString ("%1").arg (team);

    switch (string.length()) {
    case 1:
        string = "00.0" + string;
        break;
    case 2:
        string = "00." + string;
        break;
    case 3:
        string = QString ("0%1.%2%3").arg (string.at (0),
                                           string.at (1),
                                           string.at (2));
        break;
    case 4:
        string = QString ("%1%2.%3%4").arg (string.at (0),
                                            string.at (1),
                                            string.at (2),
                                            string.at (3));
        break;
    }

    return QString ("10.%1.%2").arg (string, QString::number (host));
}

QString DS_GetTimezone() {
    return QString::fromUtf8 (QTimeZone::systemTimeZone().id());
}

QString DS_GetControlModeString (DS_ControlMode mode) {
    switch (mode) {
    case DS_ControlTest:
        return QString ("Test");
        break;
    case DS_ControlTeleOp:
        return QString ("Teleoperated");
        break;
    case DS_ControlDisabled:
        return QString ("Disabled");
        break;
    case DS_ControlAutonomous:
        return QString ("Autonomous");
        break;
    case DS_ControlEmergencyStop:
        return QString ("Emergency Stop");
        break;
    case DS_ControlNoCommunication:
        return QString ("No Robot Communication");
        break;
    }

    return QString ("");
}