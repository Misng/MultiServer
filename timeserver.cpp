/**
 *类描述：TimeServer继承与QTcpServer，重新实现虚函数incomingConnection，在incomingConnection中新建子线程并将incomingConnection的参数sockDescription传入到子线程中。
 *问题：现在有了套接字描述符，服务器怎么和子线程中的套接字通讯呢？
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
