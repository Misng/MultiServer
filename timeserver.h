#ifndef TIMESERVER_H
#define TIMESERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include "childthread.h"

class TimeServer : public QTcpServer
{
        Q_OBJECT
public:
        explicit TimeServer(QObject *parent = 0);
        
protected:
        void incomingConnection(int sockDescriptor);
signals:
        
public slots:
        void threadFinshed();
};

#endif // TIMESERVER_H
