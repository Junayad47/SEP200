
//*
// Sep 200, Professor Mufleh Al-Shatnawi, Ph.D., P.Eng
// Workshop: 04
// Student Name: Junayad Bin Forhad
// Id  : 160158218
//*

#ifndef _UDPPACKETPARSER_H_
#define _UDPPACKETPARSER_H_

#include <iostream>
//#include "UdpPacketParser.cpp"
#define MAX_LEN 65535 // The maximum length of a UDP packet could be up to 65535 bytes
#define HEADER_LEN 8  // The length of the packet header

class UdpPacket
{
    unsigned int source_port;
    unsigned int dest_port;
    unsigned int length;
    unsigned int checksum;
    unsigned char data[MAX_LEN - HEADER_LEN];
};
#endif // _UDPPACKETPARSER_H_