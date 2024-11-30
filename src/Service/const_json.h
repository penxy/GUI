#pragma once
#include <string>
#include <time.h>

/**
 * @namespace TypeJson
 * @brief     包含json的一切属性
 */
namespace TypeJson{
    /**
     * @struct Hand
     * @brief 消息头部, Protocol::createHead要用到
     */
    struct Hand{
        bool is_request;            //请求/响应包
        std::string account_id;     //发送者id
        int index;                  //消息下标
        time_t time;                //发送时间
        Hand() = default;
        Hand(std::string account_id, int index, time_t time){
            this->account_id = account_id;
            this->index = index;
            this->time = time;
        }
    };

    /**
     * @enum Leval
     * @brief 优先级
     */
    enum class Leval{
        Low = 0,
        Normal,
        High
    };
    /**
     * @enum Send
     * @brief 发送的类型
     */
    enum class Send{
        Regiest,
        CreateGroup,

        FdFind,
        FdAdd,
        FdDel,
        FdAccept,
        FdReject,
        FdText,

        GpFind,
        GpAdd,
        GpDel,
        GpAccept,
        GpReject,
        GpText,
        GpName,
        GpPix,

        ChangeName,
        ChangePix,
        ChangeStatus,
        ChangePass
    };
    /**
     * @enum Recv
     * @brief 接收的类型
     */
    enum class Recv{
        FdFind,
        FdAdd,
        FdDel,
        FdAccept,
        FdReject,
        FdStatus,
        FdName,
        FdPix,

        GpFind,
        GpAdd,
        GpDel,
        GpAccept,
        GpReject,
        GpName,
        GpPix,
    };
};
