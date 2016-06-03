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
        ChildThread * thread = new ChildThread(sockDescriptor,this,"HelloTCP");
        thread->start();
        connect(thread,SIGNAL(finished()),this,SLOT(threadFinshed()));
        connect(thread,SIGNAL(error(QString)),
                this,SLOT(displayError(QString)));
        connect(this,SIGNAL(sendDataToThread(QString)),
                thread,SLOT(recvFormMainThread(QString)));
}

void TimeServer::threadFinshed()
{
        qDebug("thread Findshed");
}

void TimeServer::displayError(QString errorString)
{
        qDebug() << errorString;
}
