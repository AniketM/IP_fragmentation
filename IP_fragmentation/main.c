//
//  main.c
//  IP_fragmentation
//
//  Created by Aniket Mitra on 01/11/14.
//  Copyright (c) 2014 Aniket Mitra. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct ip_fragment {
    int frag_no,bytes,id,offset,flag;
    }ip_fragment;

ip_fragment p[100];

int main(int argc, const char * argv[]) {
    float data_len,head_len,mtu,ip_payload;
    int i,mtu_val = 0,frag,id_no = 0;
    printf("\nEnter IP datagram length(in bytes)\n");
    scanf("%f",&data_len);
    printf("Enter header length of IP datagram(in bytes)\n");
    scanf("%f",&head_len);
    ip_payload = data_len-head_len;
    printf("Enter Maximum Transmission Unit(MTU) length(in bytes)\n");
    scanf("%f",&mtu);
    frag = (int)(ceil(ip_payload/mtu));
    mtu_val = (int)mtu-head_len;
    id_no = rand();
    p[1].offset = 0;
    for (i=1; i<frag; i++) {
        p[i].frag_no = i;
        
        while (mtu_val%8!=0) {
            mtu_val = mtu_val - 1;
        }
        p[i].bytes = mtu_val;
        p[i].id = id_no;
        p[i+1].offset = (i*(mtu_val/8));
        p[i].flag = 1;
        }
    p[frag].frag_no = frag;
    p[frag].id = id_no;
    p[frag].bytes = (int)(ip_payload - (frag-1) * mtu_val);
    p[frag].flag = 0;
    printf("\n------------------------------------------------------\n\n");
    printf("Fragment No.\tBytes\tID\t\tOffest\tFlag\n");
    for (i=1; i<=frag; i++) {
        printf("\n\t%d\t\t\t%d \t%d\t%d\t\t%d\n",p[i].frag_no,p[i].bytes,p[i].id,p[i].offset,p[i].flag);
    }
    printf("\n------------------------------------------------------\n");
    printf("\nIP datagram length - %d\n",(int)head_len);
    
    return 0;
    }
