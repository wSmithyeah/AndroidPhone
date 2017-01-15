function setCCModeFlag {
    stack[2039] = arg0;
    stack[2040] = r4;
    stack[2041] = *0xaecc;
    stack[2042] = r6;
    stack[2043] = r7;
    stack[2044] = r8;
    stack[2045] = r10;
    stack[2046] = r11;
    stack[2047] = lr;
    sp = sp - 0x4 - 0x4 - 0x4 - 0x4 - 0x4 - 0x4 - 0x4 - 0x4 - 0x4 - 0x8c;
    r6 = arg1;
    s0 = arg0;
    stack[2037] = **0xaecc;
    r4 = sp + 0x44;
    r0 = memcpy(sp, 0x8778, 0x4);
    stack[2005] = 0x0;
    stack[2006] = 0x0;
    stack[2007] = 0x0;
    stack[2008] = 0x0;
    stack[2009] = 0x0;
    stack[2010] = 0x0;
    stack[2011] = 0x0;
    stack[2012] = 0x0;
    r0 = memset(r4, 0x0, 0x40);
    if (r6 > 0x1) goto loc_3390;

loc_3148:
    r8 = sp + 0x24;
    r0 = sub_2738(r8);
    if (r6 == 0x0) goto loc_32a0;

loc_315c:
    r0 = read_from_secBlock(r8, r4, 0x40, SAR(0x80000000, 0x80000000 / 0x100000));
    if (r0 < 0x0) goto loc_3410;

loc_317c:
    r0 = usleep(0x2710);
    r0 = 0x3;
    r1 = "SecurityManager";
    r2 = "READ CC flag with SEC_DATAIO...SUCCESS";
    r0 = __android_log_print();
    r7 = 0x0 ^ 0xffffffff;
    goto loc_31a4;

loc_31a4:
    r10 = sp + 0x4;
    if (getDataFromEnc(r4, r10, r2) < 0x0) goto loc_34b8;

loc_31bc:
    if (memcmp(0x1f050, 0x1f060, 0x10) != 0x0) goto loc_3200;

loc_31d8:
    r0 = 0x3;
    r11 = "SecurityManager";
    r2 = "rv generation start";
    r1 = r11;
    r0 = __android_log_print();
    r0 = sub_27b4();
    if (r0 != 0x10) goto loc_33c0;

loc_3200:
    r11 = stack[2013];
    lr = stack[2004];
    r12 = sp + 0x10;
    r3 = 0x1f050;
    asm{ ldm        r3, {r0, r1, r2, r3} };
    r11 = r11 | 0x11;
    asm{ stm        ip, {r0, r1, r2, r3} };
    stack[2007] = s0;
    stack[2013] = r11;
    stack[2005] = lr;
    if (getEncKeyFromRKey(r10, r4) < 0x0) goto loc_34d8;

loc_3240:
    if (r6 != 0x0) goto loc_331c;

loc_3248:
    if (lseek(r7, SAR(0x80000000, 0x80000000 / 0x100000), 0x2) >= 0x0) {
            if (write(r7, r4, 0x40) < 0x0) {
                    r3 = strerror(*__errno());
                    r1 = "SecurityManager";
                    r2 = "Failed to write : %s\n";
                    r0 = 0x3;
                    r6 = 0x6a ^ 0xffffffff;
                    r0 = __android_log_print();
            }
    }
    else {
            r3 = strerror(*__errno());
            r1 = "SecurityManager";
            r2 = "Failed to seek : %s\n";
            r0 = 0x3;
            r6 = 0x69 ^ 0xffffffff;
            r0 = __android_log_print();
    }
    goto loc_327c;

loc_327c:
    if (r7 != 0x0) {
            r0 = close(r7);
    }
    goto loc_3284;

loc_3284:
    r0 = r6;
    if (stack[2037] == **0xaecc) {
            sp = sp + 0x8c;
    }
    else {
            r0 = __stack_chk_fail();
    }
    return r0;

loc_331c:
    r0 = 0x3;
    r6 = "SecurityManager";
    r2 = "WRITE CC flag with SEC_DATAIO...START";
    r1 = r6;
    r0 = __android_log_print();
    r0 = write_to_secBlock(r8, r4, 0x40, SAR(0x80000000, 0x80000000 / 0x100000));
    if (r0 < 0x0) goto loc_3498;

loc_3358:
    r0 = usleep(0x2710);
    r1 = 0x0;
    r0 = 0x3;
    r2 = "WRITE CC flag with SEC_DATAIO...SUCCESS";
    r0 = __android_log_print();
    r6 = 0x0;
    if (r7 != 0x0) {
            r0 = close(r7);
    }
    goto loc_3284;

loc_3498:
    r1 = r6;
    r3 = r0;
    r2 = "Failed to write_to_secBlock. res : %d\n";
    r0 = 0x3;
    r0 = __android_log_print();
    r6 = 0x80 ^ 0xffffffff;
    goto loc_327c;

loc_34d8:
    r0 = 0x3;
    r1 = "SecurityManager";
    r2 = "Failed to Encrypt rawData";
    r0 = __android_log_print();
    r6 = 0x6d ^ 0xffffffff;
    goto loc_327c;

loc_33c0:
    r3 = r0;
    r1 = r11;
    r0 = 0x3;
    r2 = "rv generation failed. res = %d";
    r0 = __android_log_print();
    r6 = 0x6c ^ 0xffffffff;
    goto loc_327c;

loc_34b8:
    r0 = 0x3;
    r1 = "SecurityManager";
    r2 = "Failed to Decrypt erawData";
    r0 = __android_log_print();
    r6 = 0x6e ^ 0xffffffff;
    goto loc_327c;

loc_3410:
    r3 = r0;
    r1 = "SecurityManager";
    r0 = 0x3;
    r2 = "Failed to read_from_secBlock. res : %d\n";
    r0 = __android_log_print();
    r7 = 0x0 ^ 0xffffffff;
    r6 = 0x7f ^ 0xffffffff;
    goto loc_3384;

loc_3384:
    r0 = close(r7);
    goto loc_3284;

loc_32a0:
    r2 = 0x1b0;
    r0 = open(r8, "ntegrity_for_vpn" + 0x2);
    r7 = r0 - 0x0;
    COND = r7 < 0x0;
    if (COND) goto loc_33e0;

loc_32bc:
    if (lseek(r0, SAR(0x80000000, 0x80000000 / 0x100000), 0x2) < 0x0) goto loc_3438;

loc_32d4:
    r2 = 0x40;
    if (read(r7, r4, r2) >= 0x0) goto loc_31a4;

loc_32ec:
    r3 = strerror(*__errno());
    r1 = "SecurityManager";
    r2 = "Failed to read : %s\n";
    r0 = 0x3;
    r6 = 0x6b ^ 0xffffffff;
    r0 = __android_log_print();
    goto loc_327c;

loc_3438:
    r3 = strerror(*__errno());
    r1 = "SecurityManager";
    r2 = "Failed to seek : %s\n";
    r0 = 0x3;
    r6 = 0x69 ^ 0xffffffff;
    r0 = __android_log_print();
    goto loc_327c;

loc_33e0:
    r3 = strerror(*__errno());
    r1 = "SecurityManager";
    r2 = "Failed to open f : %s\n";
    r0 = 0x3;
    r6 = 0x68 ^ 0xffffffff;
    r0 = __android_log_print();
    goto loc_3384;

loc_3390:
    r3 = r6;
    r1 = "SecurityManager";
    r2 = "sec_data_flag input parameter is invalid : %d\n";
    r0 = 0x3;
    r0 = __android_log_print();
    r6 = 0x0 ^ 0xffffffff;
    r0 = close(0x0 ^ 0xffffffff);
    goto loc_3284;
}
