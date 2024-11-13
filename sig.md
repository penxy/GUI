[目前信号]

DialogGroup             [SigAddGroup]
DialogPerson            [SigAddPerson]
DialogSearch            [SigSearch]


[目前槽]

DialogSearch            [SlotSearch]

WidgetLeft              [SlotReFlushFriend]
                        [SlotReFlushGroup]
                        [SlotSetPage]

WidgetTalkMid           [SlotMessageAppend]


[已完成信号链]
WidgetTool::SigBtnClick     ->WidgetRight::SlotWidgetChange