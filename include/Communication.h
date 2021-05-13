#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QStringList>
#include <string>


class communication
{
public:

    QSerialPort *serialPort;
    QStringList list_port;
    QString baund_rate;
    QString status;
    QString button_status;
    QString current_port;
    QString receive_data;



    //Construtor
    communication();


    void connectToSerial();
    void checkSerial();
    void closeSerialPort();
    void writeData(const QByteArray &data);
    void readData();
    void def_port(QString);
};

#endif // COMMUNICATION_H
