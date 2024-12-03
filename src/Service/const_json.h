#pragma once
#include <string>
#include <time.h>

/**
 * @namespace TypeJson
 * @brief     包含json的一切属性
 */
namespace TypeJson{
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

        FdAdd,
        FdDel,
        FdAccept,
        FdReject,
        FdText,

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
