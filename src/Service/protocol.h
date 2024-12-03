#pragma once

#include <QObject>
#include <memory>

class QJsonObject;
class Core;
class NetCore;
class QTcpSocket;

/**
 * @class Protocol
 * @brief 生成json并发送，接收json并解析
 */
class Protocol : public QObject, public std::enable_shared_from_this<Protocol>{
    Q_OBJECT
public:
    Protocol(QObject *parent);
    ~Protocol();
public:
    void init(std::shared_ptr<Core>core, int account_id, const char *host, int port);
    void send(std::string &msg);                                    //由core调用
private:
    void createHead();
private slots:
    void onReadyRead();
private: 
    std::shared_ptr<Core> m_core;                                   //解析json后，调用Core的接口

    struct Hand{
        int m_index = 0;                                            //协议序号
        QString account_id;                                         //发送者id
        int index;                                                  //消息下标
        time_t time;                                                //发送时间
    }m_hand;

    QTcpSocket *m_socket = nullptr;
    QString recv_text;
    QJsonObject *m_json;
};