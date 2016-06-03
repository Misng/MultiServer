/**
 *��������TimeServer�̳���QTcpServer������ʵ���麯��incomingConnection����incomingConnection���½����̲߳���incomingConnection�Ĳ���sockDescription���뵽���߳��С�
 *���⣺���������׽�������������������ô�����߳��е��׽���ͨѶ�أ�
*/

#include "timeserver.h"

TimeServer::TimeServer(QObject *parent) :
        QTcpServer(parent)
{
}

void TimeServer::incomingConnection(int sockDescriptor)
{
        //�����ͻ��˵�socket
        QTcpSocket * socket = new QTcpSocket();
        if(socket->setSocketDescriptor(sockDescriptor)){
                qDebug() << socket->state() << socket->socketDescriptor();
        }else{
                qDebug() << socket->errorString();
        }

        ChildThread * thread = new ChildThread(socket);
        thread->start();
        connect(thread,SIGNAL(finished()),this,SLOT(threadFinshed()));
}

void TimeServer::threadFinshed()
{
        qDebug("thread Findshed");
}
