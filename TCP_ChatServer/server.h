#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <Qlist>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

    int count();
    void close();

    QString Message() const;
    void setMessage(const QString &message);

signals:
    void changed();

public slots:

    void disconnected();
    void readyRead();


    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle);

private:
    QString m_message;
    QList<QTcpSocket*> m_list;
    QMap<QTcpSocket*, QByteArray> m_buffers;
};

#endif // SERVER_H
