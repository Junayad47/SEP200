
//*
// Sep 200, Professor Mufleh Al-Shatnawi, Ph.D., P.Eng
// Workshop: 04
// Student Name: Junayad Bin Forhad
// Id  : 160158218
//*

#include <iostream>
#include "TcpPacketParser.h"

const char TcpPacket[] = {0x00, 0x05, 0x00, 0x06, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3d, 0x00, 0x00, 0x00, 0x29,
                          //                                                             data[]
                          0x54, 0x68, 0x65, 0x20, 0x72, 0x61, 0x69, 0x6e, 0x20, 0x69, 0x6e, 0x20, 0x53, 0x70, 0x61, 0x69,
                          0x6e, 0x20, 0x69, 0x73, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x6c, 0x79, 0x20, 0x6f, 0x6e, 0x20, 0x74,
                          0x68, 0x65, 0x20, 0x70, 0x6c, 0x61, 0x6e, 0x65, 0x2e};

system("cls"); // Clear the screen
printf("UDP Packet Analyzer\n\n");

// Fill this in
dataPtr = rawData; // point to the first element in the rawData array
//	dataPtr = &rawData[0];
packet.sourcePort = (*dataPtr) * 0x0100; // 0x04 * 0x0100 = 0x0400
++dataPtr;                               // advance the dataPtr to the second element in the rawData array
packet.sourcePort += *dataPtr;           // 0x89. We add 0x0400 to 0x89 = 0x0489

++dataPtr; // advance the dataPtr to the third element in the rawData array
packet.destPort = (*dataPtr) * 0x0100;
++dataPtr; // advance the dataPtr to the fourth element in the rawData array
packet.destPort += *dataPtr;

++dataPtr;
packet.length = (*dataPtr) * 0x0100;
++dataPtr;
packet.length += *dataPtr;

++dataPtr;
packet.checksum = (*dataPtr) * 0x0100;
++dataPtr;
packet.checksum += *dataPtr;

// So far, this is what we have
printf("source port:      %5u\n", packet.sourcePort);
printf("destination port: %5u\n", packet.destPort);
printf("length:           %5u\n", packet.length);
printf("checksum:         %5u\n\n", packet.checksum);

// Since we know the length of the packet, we can extract the length of the data portion as
// packet length minus header length. We can use this information in our for-next loop to extract all the data
unsigned int i;
// Fill this in
for (i = 0; i < packet.length - HEADER_LEN; ++i)
{
    ++dataPtr;
    packet.data[i] = *dataPtr;
}
// Have you seen memcpy()?

printf("The data is:\n");
for (i = 0; i < packet.length - HEADER_LEN; ++i)
{
    printf("0x%02X ", packet.data[i]); // two digits, zero as filler, hex, capital letters
    if (i % 16 == 15)
        printf("\n"); // Print 16 bytes per line
}
printf("\n\n");

printf("The data as text is:\n");
for (i = 0; i < packet.length - HEADER_LEN; ++i)
{
    printf("%c", packet.data[i]);
    if (i % 64 == 63)
        printf("\n"); // Print 64 characters per line
}