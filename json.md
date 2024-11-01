# SendSearch

{
    "type":"person",
    "id":"xxx",
}

# RecvSearch
## person
{
    "name":"xxx",
    "photo":"xxx",//base64
}

## group
{
    "name":"xxx",
    "photo":"xxx",//base64
    "members":[
        {
            "id":"xxx",
            "name":"xxx",
            "role":"xxx",
            "photo":"xxx",//base64
        },
        {
            "id":"xxx",
            "name":"xxx",
            "role":"xxx",
            "photo":"xxx",//base64
        },
    ]
}

# SendAddGroup/SendAddPerson
{
    "type":"add person/group",
    "id":"xxx",
    "msg":"xxx"
}