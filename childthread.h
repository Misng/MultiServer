#ifndef CHILDTHREAD_H
#define CHILDTHREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDateTime>

class ChildThread : public QThread
{
        Q_OBJECT
public:
        explicit ChildThread(QObject *parent = 0);
                 ChildThread(QTcpSocket *socket,QObject *paren=0);
        void run();
private:
        QTcpSocket* m_socket;
signals:
//        void error(QTcpSocket::SocketError socketError);
public slots:
        
};

#endif // CHILDTHREAD_H
