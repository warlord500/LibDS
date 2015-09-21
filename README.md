# DriverStation Library

[![License](https://img.shields.io/github/license/WinT-3794/LibDS.svg)](https://github.com/WinT-3794/LibDS/blob/master/LICENSE)
[![BitCoin donate button](https://img.shields.io/badge/bitcoin-donate-yellow.svg)](https://blockchain.info/address/1K85yLxjuqUmhkjP839R7C23XFhSxrefMx "Donate once-off to this project using BitCoin")

The DriverStation library allows any Qt-based project to manage an FRC robot easily and without getting involved in the application loops and network operations needed to manage the roboRIO.

The library has been written by analyzing the following sites and projects:

- [https://github.com/raystubbs/RobotDS](https://github.com/raystubbs/RobotDS)
- [https://github.com/gluxon/node-driverstation15](https://github.com/gluxon/node-driverstation15)
- [https://github.com/gluxon/node-driverstation15/wiki/2015-Protocol](https://github.com/gluxon/node-driverstation15/wiki/2015-Protocol)

Buy them a beer if you feel that this library or the [QDriverStation](http://github.com/wint-3794/qdriverstation) helped you. Of course, you are welcome to buy us a beer too! (the situation in Mexico for FRC teams is not very good...)

### Wiki

We are also in the process of creating a [wiki](https://github.com/WinT-3794/QDriverStation/wiki) for this project. The idea behind this is for programmers and users alike to understand how our application and the FRC Communication protocol work.

To visit the wiki, please [click here](https://github.com/WinT-3794/QDriverStation/wiki).

### Progress

There is still a lot of work to be done in order to get a fully-working DriverStation library. Check the following:

- [x] Discover if robot radio exists (by pinging 10.XX.YY.1)
- [x] Discover if roboRIO exists (by pinging roboRIO-XXYY.local or using an user-provided address)
- [x] Get robot information such as its library, PDP and PCM (by downloading and reading some files in the FTP server of the roboRIO)
- [ ] Discover if the robot code is loaded
- [x] Generate and send control packets to the robot, which contain its control mode (Disabled, TeleOp, Auto, etc), alliance and position - **will be tested soon**.
- [x] Read robot battery voltage
- [x] Built-in NetConsole for logging and finding issues in the robot
- [ ] Get CAN information (we need to do some more "Wiresharking" for that)

[Check this wiki](https://github.com/gluxon/node-driverstation15/wiki/2015-Protocol) to see how the definitions and data on each packet type.

### Credits

This library was created by FRC team 3794 "WinT" from Metepec, Mexico. We sincerely hope that you enjoy our application and we would love some feedback from your team about it.

### Contact

To contact us, you can send us an e-mail at [team3794@outlook.com](mailto:team3794@outlook). If you would like to report an issue, or a bug, please use the [Issues](https://github.com/wint-3794/qdriverstation/issues) page.

### License

This project is licensed under the MIT license. See the LICENSE file for more information.
