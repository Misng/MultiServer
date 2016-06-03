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
        //构建客户端的socket
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
