#ifndef PROTO_H__
#define PROTO_H__

#include <site_type.h>
#define DEFAULT_MGROUP  "224.2.2.2"
#define DEFAULT_RCVPORT  "1989"

#define CHNNR  	100

#define LISTCHNID   0    //0号频道发送节目单编号，索引

#define MINCHNID   	1
#define MAXCHNID    (MINCHNID+CHNNR-1)

#define MSG_CHANNEL_MAX  	(60000-20-8)  //ip包头和udp包包头长度
#define MAX_DATA		(MSG_CHANNEL_MAX-sizeof(chnid_t))

#define MSG_LIST_MAX    (65536-20-8) 
#define MAX_ENTRY		(MSG_LIST_MAX-sizeof(chnid_t));   //entry：条目

struct msg_channel_st   //数据频道包
{
	chnid_t chnid;
	uint8_t data[1];   //变长数组,最长MAX_DATA		
}__attribute__((packed));

/*
1:music:xxxxxxxxxxxx
2:sport:xxxxxxxxxx
3:xxxxx:xxxxxx
*/
struct msg_listentry_st
{
	chnid_t chnid;
	uint16_t len;
	char desc[1];
}__attribute__((packed));

struct msg_list_st		//节目单频道
{
	chnid_t chnid;	
	struct msg_listentry_st entry[1];   	
}__attribute__((packed));
#endif






