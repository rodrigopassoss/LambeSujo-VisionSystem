#include "Communication.h"

communication::communication()
{
    this->serialPort = new QSerialPort; //instanciando porta serial
    QStringList portas; //Lista de Strings
    const auto serialPortInfos = QSerialPortInfo::availablePorts();//método estático
    int i =0;
    //Obtém informação das portas Seriais
    for (const QSerialPortInfo &serialPortInfo : serialPortInfos){
        //Listando as portas disponíveis
        portas.insert(i, serialPortInfo.portName());
        i++;

    }
    status = "Desconectado";
    button_status = "Conectar";
    baund_rate.clear();
}

void communication::connectToSerial()
{
    // Se Tiver conectado, desconecta
    if(this->serialPort->isOpen())
    {
        this->serialPort->close();
        status = "Desconectado";  //Atualiza status para desconectado
        button_status = "Conectar";
        baund_rate.clear();       //limpando dados do Baud Rate
        return;
    }
    // Parâmetros de Abertura da Porta Serial
    if(!list_port.empty())
    {
        this->serialPort->setPortName(current_port);
        this->serialPort->setBaudRate(QSerialPort::Baud115200);
        this->serialPort->setDataBits(QSerialPort::Data8);
        this->serialPort->setParity(QSerialPort::NoParity);
        this->serialPort->setStopBits(QSerialPort::OneStop);
        this->serialPort->setFlowControl(QSerialPort::NoFlowControl);

    }

    if(this->serialPort->open(QIODevice::ReadWrite)){ // Verificação se a porta realmente abriu
        status = "Conectado";
        baund_rate = "Communication Paramaters\n"
                     "Baudrate: 115200\n"
                     "Data bits: 8\n"
                     "Parity: None\n"
                     "Stop bits: 1\n"
                     "Flow control: None";
        button_status = "Desconectar";

        return;
    }
    status = "Falha ao tentar conectar";
    button_status = "Conectar";
    this->serialPort->close();

}

void communication::checkSerial()
{
    auto serialPortInfos = QSerialPortInfo::availablePorts();
    list_port.clear();
    int i =0;
    for (const QSerialPortInfo &serialPortInfo : serialPortInfos)
    {
        list_port.insert(i, serialPortInfo.portName());
        i++;
    }
}

void communication::closeSerialPort()
{
    if (this->serialPort->isOpen()){
        this->serialPort->close();
    }
}

void communication::writeData(const QByteArray &data)
{
    this->serialPort->write(data);

}

void communication::readData()
{
    const QByteArray datareceive = this->serialPort->readAll();

    int x[11] = {0,0,0,0,0,0,0,0,0,0,0};//só testando
    x[0] = datareceive.toInt();
    receive_data = datareceive;
}

void communication::def_port(QString port)
{
    current_port = port;
}
