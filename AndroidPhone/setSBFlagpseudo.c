function setSBFlag {
    stack[2039] = arg0;
    stack[2040] = r4;
    stack[2041] = r5;
    stack[2042] = *0xaecc;
    stack[2043] = r7;
    stack[2044] = r8;
    stack[2045] = r10;
    stack[2046] = r11;
    stack[2047] = lr;
    sp = sp - 0x4 - 0x4 - 0x4 - 0x4 - 0x4 - 0x4 - 0x4 - 0x4 - 0x4 - 0x94;
    r10 = arg0;
    r7 = arg1;
    stack[2037] = **0xaecc;
    stack[2005] = 0x0;
    stack[2006] = 0x0;
    stack[2007] = 0x0;
    stack[2008] = 0x0;
    stack[2009] = 0x0;
    stack[2010] = 0x0;
    stack[2011] = 0x0;
    stack[2012] = 0x0;
    r0 = memcpy(sp, 0x8778, 0x4);
    r0 = memcpy(sp + 0x4, 0x877c, 0x4);
    r5 = sp + 0x4c;
    r0 = memcpy(sp + 0x8, 0x8780, 0x4);
    stack[2013] = 0x0;
    stack[2014] = 0x0;
    stack[2015] = 0x0;
    stack[2016] = 0x0;
    stack[2017] = 0x0;
    stack[2018] = 0x0;
    stack[2019] = 0x0;
    stack[2020] = 0x0;
    r0 = memset(r5, 0x0, 0x40);
    if (r10 > 0x1) goto loc_2b78;

loc_28bc:
    if (r7 > 0x1) goto loc_2b50;

loc_28c4:
    r8 = sp + 0xc;
    r0 = sub_2738(r8);
    if (r7 == 0x0) goto loc_2a18;

loc_28d8:
    r0 = 0x3;
    r4 = "SecurityManager";
    r2 = "READ SB flag with SEC_DATAIO...START";
    r1 = r4;
    r0 = __android_log_print();
    r0 = read_from_secBlock(r8, r5, 0x40, SAR(0x80000000, 0x80000000 / 0x100000));
    if (r0 < 0x0) goto loc_2ba0;

loc_2914:
    r0 = usleep(0x2710);
    r1 = r4;
    r0 = 0x3;
    r2 = "READ SB flag with SEC_DATAIO...SUCCESS";
    r0 = __android_log_print();
    r4 = 0x0 ^ 0xffffffff;
    goto loc_2938;

loc_2938:
    s0 = sp + 0x2c;
    if (getDataFromEnc(r5, s0, r2) < 0x0) goto loc_2c74;

loc_2950:
    if (memcmp(0x1f050, 0x1f060, 0x10) == 0x0) goto loc_2b08;

loc_296c:
    lr = stack[2021];
    stack[2013] = stack[2002];
    if (r10 == 0x1) {
            r3 = stack[2003];
    }
    if (CPU_FLAGS & NE) {
            r3 = stack[2004];
    }
    r12 = sp + 0x38;
    lr = lr | 0x11;
    stack[2014] = 0x1f050;
    r3 = 0x1f050;
    asm{ ldm        r3, {r0, r1, r2, r3} };
    asm{ stm        ip, {r0, r1, r2, r3} };
    stack[2021] = lr;
    if (getEncKeyFromRKey(s0, r5) < 0x0) goto loc_2c94;

loc_29b8:
    if (r7 != 0x0) goto loc_2a94;

loc_29c0:
    if (lseek(r4, SAR(0x80000000, 0x80000000 / 0x100000), 0x2) >= 0x0) {
            if (write(r4, r5, 0x40) < 0x0) {
                    r3 = strerror(*__errno());
                    r1 = "SecurityManager";
                    r2 = "Failed to write : %s\n";
                    r0 = 0x3;
                    r7 = 0x6a ^ 0xffffffff;
                    r0 = __android_log_print();
            }
    }
    else {
            r3 = strerror(*__errno());
            r1 = "SecurityManager";
            r2 = "Failed to seek : %s\n";
            r0 = 0x3;
            r7 = 0x69 ^ 0xffffffff;
            r0 = __android_log_print();
    }
    goto loc_29f4;

loc_29f4:
    if (r4 != 0x0) {
            r0 = close(r4);
    }
    goto loc_29fc;

loc_29fc:
    r0 = r7;
    if (stack[2037] == **0xaecc) {
            sp = sp + 0x94;
    }
    else {
            r0 = __stack_chk_fail();
    }
    return r0;

loc_2a94:
    r0 = 0x3;
    r7 = "SecurityManager";
    r2 = "WRITE SB flag with SEC_DATAIO...START";
    r1 = r7;
    r0 = __android_log_print();
    r0 = write_to_secBlock(r8, r5, 0x40, SAR(0x80000000, 0x80000000 / 0x100000));
    if (r0 < 0x0) goto loc_2c24;

loc_2ad0:
    r0 = usleep(0x2710);
    r1 = 0x0;
    r0 = 0x3;
    r2 = "WRITE SB flag with SEC_DATAIO...SUCCESS";
    r0 = __android_log_print();
    r7 = 0x0;
    if (r4 != 0x0) {
            r0 = close(r4);
    }
    goto loc_29fc;

loc_2c24:
    r1 = r7;
    r3 = r0;
    r2 = "Failed to write_to_secBlock. res : %d\n";
    r0 = 0x3;
    r0 = __android_log_print();
    r7 = 0x80 ^ 0xffffffff;
    goto loc_29f4;

loc_2c94:
    r0 = 0x3;
    r1 = "SecurityManager";
    r2 = "Failed to Encrypt rawData";
    r0 = __android_log_print();
    r7 = 0x6d ^ 0xffffffff;
    goto loc_29f4;

loc_2b08:
    r0 = 0x3;
    r11 = "SecurityManager";
    r2 = "rv generation start";
    r1 = r11;
    r0 = __android_log_print();
    r0 = sub_27b4();
    if (r0 < 0x10) goto loc_296c;

loc_2b30:
    r3 = r0;
    r1 = r11;
    r0 = 0x3;
    r2 = "rv generation failed. res = %d";
    r0 = __android_log_print();
    r7 = 0x6c ^ 0xffffffff;
    goto loc_29f4;

loc_2c74:
    r0 = 0x3;
    r1 = "SecurityManager";
    r2 = "Failed to Decrypt erawData";
    r0 = __android_log_print();
    r7 = 0x6e ^ 0xffffffff;
    goto loc_29f4;

loc_2ba0:
    r1 = r4;
    r3 = r0;
    r2 = "Failed to read_from_secBlock. res : %d\n";
    r0 = 0x3;
    r0 = __android_log_print();
    r4 = 0x0 ^ 0xffffffff;
    r7 = 0x7f ^ 0xffffffff;
    goto loc_2afc;

loc_2afc:
    r0 = close(r4);
    goto loc_29fc;

loc_2a18:
    r2 = 0x1b0;
    r0 = open(r8, "ntegrity_for_vpn" + 0x2);
    r4 = r0 - 0x0;
    COND = r4 < 0x0;
    if (COND) goto loc_2bc4;

loc_2a34:
    if (lseek(r0, SAR(0x80000000, 0x80000000 / 0x100000), 0x2) < 0x0) goto loc_2bf4;

loc_2a4c:
    r2 = 0x40;
    if (read(r4, r5, r2) >= 0x0) goto loc_2938;

loc_2a64:
    r3 = strerror(*__errno());
    r1 = "SecurityManager";
    r2 = "Failed to read : %s\n";
    r0 = 0x3;
    r7 = 0x6b ^ 0xffffffff;
    r0 = __android_log_print();
    goto loc_29f4;

loc_2bf4:
    r3 = strerror(*__errno());
    r1 = "SecurityManager";
    r2 = "Failed to seek : %s\n";
    r0 = 0x3;
    r7 = 0x69 ^ 0xffffffff;
    r0 = __android_log_print();
    goto loc_29f4;

loc_2bc4:
    r3 = strerror(*__errno());
    r1 = "SecurityManager";
    r2 = "Failed to open f : %s\n";
    r0 = 0x3;
    r7 = 0x68 ^ 0xffffffff;
    r0 = __android_log_print();
    goto loc_2afc;

loc_2b50:
    r3 = r7;
    r0 = 0x3;
    r1 = "SecurityManager";
    r2 = "sec_data_flag input parameter is invalid : %d\n";
    r4 = 0x0 ^ 0xffffffff;
    r0 = __android_log_print();
    r7 = r4;
    goto loc_2afc;

loc_2b78:
    r3 = r10;
    r0 = 0x3;
    r1 = "SecurityManager";
    r2 = "status input parameter is invalid : %d\n";
    r4 = 0x0 ^ 0xffffffff;
    r0 = __android_log_print();
    r7 = r4;
    goto loc_2afc;
}
