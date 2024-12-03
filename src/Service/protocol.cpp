#include "protocol.h"
#include "Core/core.h"
#include "const_json.h"

#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonArray>

Protocol::Protocol(QObject *parent) : QObject(parent){}
Protocol::~Protocol(){
    if(m_socket == nullptr)return;
    delete m_socket;
}
/**
 * @def init
 * @param[in] core 核心
 * @param[in] account_id 账号id
 * @param[in] host 服务器地址
 * @param[in] port 服务器端口
 * @brief 初始化网络
 */
void Protocol::init(std::shared_ptr<Core>core, int account_id, const char *host, int port){
    m_core = core;
    m_hand.account_id = account_id;
    m_json = new QJsonObject();

    m_socket = new QTcpSocket(this);
    m_socket->connectToHost(QString::fromStdString(host), port);
    connect(m_socket, &QTcpSocket::readyRead, this, &Protocol::onReadyRead);
}

void Protocol::send(std::string& msg){
    if(msg.empty())return;
    if(!m_socket->isValid())return;
    const QByteArray send_data = QString::fromStdString(msg).toUtf8();
    m_socket->write(send_data);
}

void Protocol::onReadyRead(){
    if(m_socket->bytesAvailable() <= 0) return;
    QString recv_text = QString::fromUtf8(m_socket->readAll());
    //...操作m_core;
}