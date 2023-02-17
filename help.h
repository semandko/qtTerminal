#ifndef HELP_H
#define HELP_H





#if 0
int main(int argc, char *argv[])
{
    QByteArray msg,test;
    msg[0] = 0x01;
    msg[1] = 0x04;
    msg[2] = 0x00;
    msg[3] = 0x0b;

    msg[4] = 0x00;
    msg[5] = 0x01;
    msg[6] = 0x40;
    msg[7] = 0x08;
 QCoreApplication a(argc, argv);

 QSerialPort serial;
 serial.setPortName("ttyUSB0");
 serial.setBaudRate(QSerialPort::Baud19200);
 serial.setDataBits(QSerialPort::Data8);
 serial.setParity(QSerialPort::NoParity);
 serial.setStopBits(QSerialPort::OneStop);
 serial.setFlowControl(QSerialPort::NoFlowControl);
 serial.open(QIODevice::ReadWrite);
 serial.write(msg, msg.length());
 serial.flush();
 qDebug() << "Tx: "<<msg.toHex();
 qDebug() << "bufferSize: " << serial.readBufferSize();
 test = serial.readAll();
 qDebug() << "Rx: "<< test;
 serial.close();
return a.exec();
}

#endif

#if 0
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSerialPort serial;
    QTimer *timer = new QTimer;


    serial.setPortName("com4");
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::EvenParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    serial.open(QIODevice::ReadWrite);

   // 3E 56 00 56 00


    qDebug()<<serial.write("3E 56 00 56 00",5);
    timer->start(50);

    qDebug()<<serial.readAll();

}
#endif

#if 0
Протокол ISIS-II, в основном, знаменит тем, что значение каждого байта передается в HEX-коде.
 А в начале каждого пакета передается код двоеточия - 0x3A.
Затем следует байт количества передаваемых байтов.
 После него байт типа пакета: - команда, данные и т.п.
 Далее, в стандартном протоколе передается адрес загрузки первого байта пакета.
 Потом передаются байты данных.
 После них байт дополнения контрольной суммы - ДКС.
 ДКС - это сумма всех переданных байтов без учета переноса (кроме двоеточия) с обратным знаком.
 На принимающей стороне для контроля, просто суммируются все байты, и, если нет ошибок, то в сумматоре должен оказаться нуль.
 После ДКС, обычно добавляют символы "Возврат каретки" (0x0D) и "Перевод строки" (0x0A).
 Это для того, чтобы можно было удобно читать передаваемую информацию с помощью текстового редактора.

#endif


#if 0
        0x3A - начало пакета;
        0x3A - flash;
        0x01 - U_DAC;
        0x02 -
        0x03 -
        0x04 -
        0x05 - I_DAC;
        0x06 -
        0x07 -
        0x08 -
        0x09 -


#endif







#endif // HELP_H
