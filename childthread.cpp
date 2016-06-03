#include "childthread.h"

ChildThread::ChildThread(QObject *parent) :
        QThread(parent)
{
}



ChildThread::ChildThread(int socketDescriptor, QObject *parent, QString text):
        QThread(parent),m_socketDescriptor(socketDescriptor),m_text(text)      //QThread(parent) �����Ҫ������ʾ��
{
//        quit = false;
}

//��run�Ĺ����У�����һ��socket����ʹ�ô��ݹ�����socketDescriptor��
void ChildThread::run()
{
        //�����׽���
        QTcpSocket tcpSocket;
        if(!tcpSocket.setSocketDescriptor(m_socketDescriptor)){
                emit error(tcpSocket.errorString());
        }
//        connect()

        //׼����������
        QByteArray block;
        QDataStream out(&block,QIODevice::WriteOnly);//QDataStream�ṩһ�����л��Ķ��������ݵ�һ��QIODeivce�С�
        out.setVersion(QDataStream::Qt_4_8);

        out << quint16(0);//��quint16(0)����out�С�
        out << m_text;//ͬ��
        out.device()->seek(0);//�����õ��ֽ�����IO�豸����λ��ǰ��λ�õ���ʼ��λ����Ҳ����˵����һ��Ҫд��λ�ø��Ӷ����˿�ͷ��Ϊ���滻ԭ����ͷ��д���ĸ�quint16(0)��
        out << (quint16)(block.size() - sizeof(quint16));//�滻ͷ�����Ǹ�quint16(0)
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
        //�������ݣ������ݷ��͸�timeServer
        //��ô�ظ�����
        //��Ҫ�����ݱ��浽һ���������棬�����������е����ݷ��͸ı䣬�͸�
}
