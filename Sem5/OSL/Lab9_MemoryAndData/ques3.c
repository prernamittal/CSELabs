#include <stdio.h>
#include <stdlib.h>

struct SegmentEntry {
    int base;
    int limit;
};

struct SegmentEntry segmentTable[5];

void initializeSegmentTable() {
    // Segment 0: Base 0, Limit 255
    segmentTable[0].base = 0;
    segmentTable[0].limit = 255;

    // Segment 1: Base 256, Limit 511
    segmentTable[1].base = 256;
    segmentTable[1].limit = 511;

    // Segment 2: Base 512, Limit 767
    segmentTable[2].base = 512;
    segmentTable[2].limit = 767;

    // Segment 3: Base 768, Limit 1023
    segmentTable[3].base = 768;
    segmentTable[3].limit = 1023;

    // Segment 4: Base 1024, Limit 1279
    segmentTable[4].base = 1024;
    segmentTable[4].limit = 1279;
}

int getPhysicalAddress(int segment, int offset) {
    if (segment < 0 || segment > 4 || offset < 0) {
        return -1; 
    }

    if (offset > segmentTable[segment].limit) {
        return -1; 
    }

    int physicalAddress = segmentTable[segment].base + offset;

    return physicalAddress;
}

int main() {
    initializeSegmentTable();

    // Computing the physical address for 53 bytes of segment 2
    int logicalAddress1 = 53;
    int segment1 = 2;
    int physicalAddress1 = getPhysicalAddress(segment1, logicalAddress1);
    if (physicalAddress1 != -1) {
        printf("Physical address for %d bytes of segment %d: %d\n", logicalAddress1, segment1, physicalAddress1);
    } else {
        printf("Invalid logical address or segment.\n");
    }

    // Computing the physical address for 852 bytes of segment 3
    int logicalAddress2 = 852;
    int segment2 = 3;
    int physicalAddress2 = getPhysicalAddress(segment2, logicalAddress2);
    if (physicalAddress2 != -1) {
        printf("Physical address for %d bytes of segment %d: %d\n", logicalAddress2, segment2, physicalAddress2);
    } else {
        printf("Invalid logical address or segment.\n");
    }

    // Computing the physical address for 1222 bytes of segment 0
    int logicalAddress3 = 1222;
    int segment3 = 0;
    int physicalAddress3 = getPhysicalAddress(segment3, logicalAddress3);
    if (physicalAddress3 != -1) {
        printf("Physical address for %d bytes of segment %d: %d\n", logicalAddress3, segment3, physicalAddress3);
    } else {
        printf("Invalid logical address or segment.\n");
    }

    return 0;
}