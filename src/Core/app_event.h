// #pragma once
// #include "utils/single_model.h"
// #include "Card/card.h"
// #include "ChatBar/chat_page.h"
// #include "ListBar/list_page.h"
// #include "Search/find_page.h"
// #include "ToolBar/tool_page.h"

// #include "normal/widget.h"
// /**
//  * @brief connect all sig and slot from different class, only use AppEvent::get_inst()->init()
//  */
// class AppEvent : public Singleton<AppEvent> {
//     friend class Singleton<AppEvent>;
// public:
//     AppEvent (const AppEvent&) = delete;
//     AppEvent& operator = (const AppEvent&) = delete;
// protected:
//     AppEvent() = default;
// public:
//     void init(){
//         //Card SigAdd();
//     }
// };