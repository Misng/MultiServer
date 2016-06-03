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
                 ChildThread(int socketDescriptor, QObject *parent,QString text);
        void run();
private:
        int m_socketDescriptor;
        QString m_text;
        bool quit;
signals:
        void error(QString errorString);
public slots:
        void recvFormMainThread(QString str);
        void recvFormClient(QByteArray block);
        
};

#endif // CHILDTHREAD_H
