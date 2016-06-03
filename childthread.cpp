#include "childthread.h"

ChildThread::ChildThread(QObject *parent) :
        QThread(parent)
{
}

ChildThread::ChildThread(QTcpSocket *socket, QObject *parent) :
        m_socket(socket),QThread(parent) //ʹ�ó�ʼ���б��������ݳ�Ա���г�ʼ��������ʹ�ã�������������ʼ���б���ʽ�������ݳ�Ա���������������������ʹ�ã����Ÿ�����
{
        m_socket->setParent(0);//��Ҫ�Ķ���ת�Ƶ���һ���߳�
        m_socket->moveToThread(this);
}

//��run�Ĺ����У�����һ��socket����ʹ�ô��ݹ�����socketDescriptor��
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
