#include "childthread.h"

ChildThread::ChildThread(QObject *parent) :
        QThread(parent)
{
}



ChildThread::ChildThread(int socketDescriptor, QObject *parent, QString text):
        QThread(parent),m_socketDescriptor(socketDescriptor),m_text(text)      //QThread(parent) 这个需要优先显示吗？
{
//        quit = false;
}

//在run的过程中，声明一个socket，并使用传递过来的socketDescriptor。
void ChildThread::run()
{
        //创建套接字
        QTcpSocket tcpSocket;
        if(!tcpSocket.setSocketDescriptor(m_socketDescriptor)){
                emit error(tcpSocket.errorString());
        }
//        connect()

        //准备发送数据
        QByteArray block;
        QDataStream out(&block,QIODevice::WriteOnly);//QDataStream提供一个序列化的二进制数据到一个QIODeivce中。
        out.setVersion(QDataStream::Qt_4_8);

        out << quint16(0);//将quint16(0)定向到out中。
        out << m_text;//同上
        out.device()->seek(0);//将设置到字节流的IO设备，定位当前的位置到开始部位。（也即是说，下一个要写入位置给从定向到了开头，为了替换原来在头部写的哪个quint16(0)）
        out << (quint16)(block.size() - sizeof(quint16));//替换头部的那个quint16(0)
        tcpSocket.write(block);

        if(!tcpSocket.waitForBytesWritten()){
                emit error(tcpSocket.errorString());
                return ;
        }
}

void ChildThread::recvFormMainThread(QString str)
{
        qDebug()<<str;
}

void ChildThread::recvFormClient(QByteArray block)
{
        //接受数据，将数据发送给timeServer
        //怎么回复数据
        //我要把数据保存到一个容器里面，如果这个容器中的数据发送改变，就给
}
