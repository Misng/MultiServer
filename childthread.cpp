#include "childthread.h"

ChildThread::ChildThread(QObject *parent) :
        QThread(parent)
{
}

ChildThread::ChildThread(QTcpSocket *socket, QObject *parent) :
        m_socket(socket),QThread(parent) //使用初始化列表来对数据成员进行初始化操作。使用：符号来引出初始化列表，格式：类数据成员（函数参数）。多个参数使用，符号隔开。
{
        m_socket->setParent(0);//必要的对象转移到另一个线程
        m_socket->moveToThread(this);
}

//在run的过程中，声明一个socket，并使用传递过来的socketDescriptor。
void ChildThread::run()
{
      QByteArray block;
      QDataStream in(&block,QIODevice::ReadWrite);
      in.setVersion(QDataStream::Qt_4_8);
      int result =  m_socket->write("hello tcp",qstrlen("hello tcp"));
      qDebug("%d,%d,%d",(int)m_socket->size(),result,(int)qstrlen("hello tcp"));



//      uint time2u = QDateTime::currentDateTime().toTime_t();
//      in >> time2u;
//      m_socket->write(block);

//      qDebug("%d,%d,%d",m_socket->size(),block.size(),time2u);

}
