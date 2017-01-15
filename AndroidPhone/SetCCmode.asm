================ B E G I N N I N G   O F   P R O C E D U R E ================



             setCCModeFlag:
000030d4         ldr        r5, = 0x7de4                                        ; 0x352c,0x7de4
000030d8         ldr        r2, = 0x5678                                        ; 0x3530,0x5678
000030dc         sub        sp, sp, #0x8c
000030e0         ldr        r5, [pc, r5]                                        ; 0xaecc
000030e4         ldr        r3, [r5]
000030e8         add        r2, pc, r2                                          ; 0x8768
000030ec         mov        r6, r1
000030f0         mov        sb, r0
000030f4         add        r1, r2, #0x10                                       ; 0x8778, argument #2 for method memcpy@PLT
000030f8         mov        r0, sp                                              ; argument #1 for method memcpy@PLT
000030fc         mov        r2, #0x4                                            ; argument #3 for method memcpy@PLT
00003100         str        r3, [sp, #0xb0 + var_2C]
00003104         add        r4, sp, #0x44
00003108         bl         memcpy@PLT
0000310c         mov        ip, #0x0
00003110         mov        r1, ip                                              ; argument #2 for method memset@PLT
00003114         mov        r0, r4                                              ; argument #1 for method memset@PLT
00003118         mov        r2, #0x40                                           ; argument #3 for method memset@PLT
0000311c         str        ip, [sp, #0xb0 + var_AC]                            ; XREF=receive_reply+244, 0x5fe0
00003120         str        ip, [sp, #0xb0 + var_A8]
00003124         str        ip, [sp, #0xb0 + var_A4]
00003128         str        ip, [sp, #0xb0 + var_A0]
0000312c         str        ip, [sp, #0xb0 + var_9C]
00003130         str        ip, [sp, #0xb0 + var_98]
00003134         str        ip, [sp, #0xb0 + var_94]
00003138         str        ip, [sp, #0xb0 + var_90]
0000313c         bl         memset@PLT
00003140         cmp        r6, #0x1
00003144         bhi        0x3390

00003148         add        r8, sp, #0x24
0000314c         mov        r0, r8                                              ; argument #1 for method sub_2738
00003150         bl         sub_2738
00003154         cmp        r6, #0x0
00003158         beq        0x32a0                                              ; XREF=receive_reply+488, 0x5ffc

0000315c         mov        r3, #0x80000000
00003160         asr        r3, r3, #0x14                                       ; argument #4 for method read_from_secBlock
00003164         mov        r0, r8                                              ; argument #1 for method read_from_secBlock, XREF=receive_reply+436, 0x5ff4
00003168         mov        r1, r4                                              ; argument #2 for method read_from_secBlock
0000316c         mov        r2, #0x40                                           ; argument #3 for method read_from_secBlock
00003170         bl         read_from_secBlock
00003174         cmp        r0, #0x0
00003178         blt        0x3410

0000317c         mov        r0, #0x2700
00003180         add        r0, r0, #0x10                                       ; 0x2710
00003184         bl         usleep@PLT
00003188         ldr        r1, = 0x4c74                                        ; 0x3534,0x4c74
0000318c         ldr        r2, = 0x5020                                        ; 0x3538,0x5020
00003190         mov        r0, #0x3
00003194         add        r1, pc, r1                                          ; "SecurityManager"
00003198         add        r2, pc, r2                                          ; "READ CC flag with SEC_DATAIO...SUCCESS"
0000319c         bl         __android_log_print@PLT                             ; XREF=receive_reply+332, 0x5fec
000031a0         mvn        r7, #0x0

000031a4         add        sl, sp, #0x4                                        ; XREF=setCCModeFlag+536
000031a8         mov        r1, sl                                              ; argument #2 for method getDataFromEnc
000031ac         mov        r0, r4                                              ; argument #1 for method getDataFromEnc
000031b0         blx        getDataFromEnc
000031b4         cmp        r0, #0x0
000031b8         blt        0x34b8

000031bc         ldr        r0, = 0x1be84                                       ; 0x353c,0x1be84
000031c0         mov        r2, #0x10                                           ; argument #3 for method memcmp@PLT
000031c4         add        r0, pc, r0                                          ; 0x1f050, argument #1 for method memcmp@PLT
000031c8         add        r1, r0, r2                                          ; 0x1f060
000031cc         bl         memcmp@PLT
000031d0         cmp        r0, #0x0                                            ; XREF=receive_reply+256, 0x5fe4
000031d4         bne        0x3200

000031d8         ldr        fp, = 0x4c24                                        ; 0x3540,0x4c24
000031dc         ldr        r2, = 0x4ed8                                        ; 0x3544,0x4ed8
000031e0         mov        r0, #0x3
000031e4         add        fp, pc, fp                                          ; "SecurityManager"
000031e8         add        r2, pc, r2                                          ; "rv generation start"
000031ec         mov        r1, fp
000031f0         bl         __android_log_print@PLT
000031f4         bl         sub_27b4
000031f8         cmp        r0, #0x10
000031fc         bne        0x33c0

00003200         ldr        r3, = 0x1be38                                       ; 0x3548,0x1be38, XREF=setCCModeFlag+260
00003204         ldrb       fp, [sp, #0xb0 + var_8D]
00003208         ldr        lr, [sp, #0xb0 + var_B0]
0000320c         add        ip, sp, #0x10
00003210         add        r3, pc, r3                                          ; 0x1f050
00003214         ldm        r3, {r0, r1, r2, r3}
00003218         orr        fp, fp, #0x11
0000321c         stm        ip, {r0, r1, r2, r3}
00003220         mov        r0, sl                                              ; argument #1 for method getEncKeyFromRKey
00003224         mov        r1, r4                                              ; argument #2 for method getEncKeyFromRKey
00003228         str        sb, [sp, #0xb0 + var_A4]
0000322c         strb       fp, [sp, #0xb0 + var_8D]
00003230         str        lr, [sp, #0xb0 + var_AC]
00003234         blx        getEncKeyFromRKey
00003238         cmp        r0, #0x0
0000323c         blt        0x34d8

00003240         cmp        r6, #0x0
00003244         bne        0x331c

00003248         mov        r1, #0x80000000
0000324c         asr        r1, r1, #0x14                                       ; argument #2 for method lseek@PLT
00003250         mov        r0, r7                                              ; argument #1 for method lseek@PLT, XREF=send_request+88, 0x5dc4
00003254         mov        r2, #0x2
00003258         bl         lseek@PLT
0000325c         cmp        r0, #0x0
00003260         blt        0x3468

00003264         mov        r1, r4                                              ; argument #2 for method write@PLT
00003268         mov        r0, r7                                              ; argument #1 for method write@PLT
0000326c         mov        r2, #0x40
00003270         bl         write@PLT
00003274         cmp        r0, #0x0
00003278         blt        0x34f8

0000327c         cmp        r7, #0x0                                            ; XREF=setCCModeFlag+584, setCCModeFlag+780, setCCModeFlag+916, setCCModeFlag+964, setCCModeFlag+996, setCCModeFlag+1028, setCCModeFlag+1060, setCCModeFlag+1108
00003280         bne        0x3384

00003284         ldr        r2, [sp, #0xb0 + var_2C]                            ; XREF=setCCModeFlag+688, setCCModeFlag+700, setCCModeFlag+748
00003288         ldr        r3, [r5]
0000328c         mov        r0, r6
00003290         cmp        r2, r3
00003294         bne        0x3528

00003298         add        sp, sp, #0x8c
0000329c         pop        {r4, r5, r6, r7, r8, sb, sl, fp, pc}

000032a0         mov        r1, #0x1000                                         ; "ntegrity_for_vpn", XREF=setCCModeFlag+136
000032a4         add        r1, r1, #0x2                                        ; 0x1002, argument #2 for method open@PLT
000032a8         mov        r0, r8                                              ; argument #1 for method open@PLT
000032ac         mov        r2, #0x1b0
000032b0         bl         open@PLT
000032b4         subs       r7, r0, #0x0
000032b8         blt        0x33e0

000032bc         mov        r1, #0x80000000
000032c0         asr        r1, r1, #0x14                                       ; argument #2 for method lseek@PLT
000032c4         mov        r2, #0x2
000032c8         bl         lseek@PLT
000032cc         cmp        r0, #0x0
000032d0         blt        0x3438

000032d4         mov        r0, r7                                              ; argument #1 for method read@PLT
000032d8         mov        r1, r4                                              ; argument #2 for method read@PLT
000032dc         mov        r2, #0x40                                           ; XREF=send_request+100, 0x5dc8
000032e0         bl         read@PLT
000032e4         cmp        r0, #0x0
000032e8         bge        0x31a4

000032ec         bl         __errno@PLT
000032f0         ldr        r0, [r0]
000032f4         bl         strerror@PLT
000032f8         ldr        r1, = 0x4b04                                        ; 0x354c,0x4b04
000032fc         ldr        r2, = 0x4d08                                        ; 0x3550,0x4d08
00003300         mov        r3, r0
00003304         add        r1, pc, r1                                          ; "SecurityManager"
00003308         add        r2, pc, r2                                          ; "Failed to read : %s\\n"
0000330c         mov        r0, #0x3
00003310         mvn        r6, #0x6b
00003314         bl         __android_log_print@PLT
00003318         b          0x327c

0000331c         ldr        r6, = 0x4ae0                                        ; 0x3554,0x4ae0, XREF=setCCModeFlag+372
00003320         ldr        r2, = 0x4eb4                                        ; 0x3558,0x4eb4
00003324         mov        r0, #0x3                                            ; XREF=init_client+368, 0x5d2c
00003328         add        r6, pc, r6                                          ; "SecurityManager"
0000332c         add        r2, pc, r2                                          ; "WRITE CC flag with SEC_DATAIO...START"
00003330         mov        r1, r6
00003334         bl         __android_log_print@PLT
00003338         mov        r3, #0x80000000
0000333c         mov        r0, r8                                              ; argument #1 for method write_to_secBlock
00003340         mov        r1, r4                                              ; argument #2 for method write_to_secBlock
00003344         asr        r3, r3, #0x14                                       ; argument #4 for method write_to_secBlock
00003348         mov        r2, #0x40                                           ; argument #3 for method write_to_secBlock
0000334c         bl         write_to_secBlock
00003350         cmp        r0, #0x0
00003354         blt        0x3498

00003358         mov        r0, #0x2700
0000335c         add        r0, r0, #0x10                                       ; 0x2710, XREF=init_client+312, 0x5d24
00003360         bl         usleep@PLT
00003364         ldr        r2, = 0x4e98                                        ; 0x355c,0x4e98
00003368         mov        r1, r6
0000336c         mov        r0, #0x3
00003370         add        r2, pc, r2                                          ; "WRITE CC flag with SEC_DATAIO...SUCCESS"
00003374         bl         __android_log_print@PLT
00003378         cmp        r7, #0x0
0000337c         mov        r6, #0x0
00003380         beq        0x3284                                              ; XREF=init_client+380, 0x5d30

00003384         mov        r0, r7                                              ; XREF=setCCModeFlag+432, setCCModeFlag+828, setCCModeFlag+868
00003388         bl         close@PLT
0000338c         b          0x3284

00003390         ldr        r1, = 0x4a68                                        ; 0x3560,0x4a68, argument #2, XREF=setCCModeFlag+116
00003394         ldr        r2, = WAES_Decrypt                                  ; 0x3564,WAES_Decrypt, XREF=init_client+256, 0x5d1c
00003398         mov        r3, r6                                              ; XREF=init_client+324, 0x5d28
0000339c         mvn        r7, #0x0
000033a0         add        r1, pc, r1                                          ; "SecurityManager"
000033a4         add        r2, pc, r2                                          ; "sec_data_flag input parameter is invalid : %d\\n"
000033a8         mov        r0, #0x3
000033ac         bl         __android_log_print@PLT
000033b0         mov        r0, r7                                              ; argument #1 for method close@PLT
000033b4         mov        r6, r7
000033b8         bl         close@PLT                                           ; XREF=init_client+268, 0x5d20
000033bc         b          0x3284

000033c0         ldr        r2, = 0x4d08                                        ; 0x3568,0x4d08, XREF=setCCModeFlag+300
000033c4         mov        r3, r0
000033c8         mov        r1, fp
000033cc         mov        r0, #0x3
000033d0         add        r2, pc, r2                                          ; "rv generation failed. res = %d"
000033d4         bl         __android_log_print@PLT
000033d8         mvn        r6, #0x6c
000033dc         b          0x327c

000033e0         bl         __errno@PLT                                         ; XREF=setCCModeFlag+488
000033e4         ldr        r0, [r0]                                            ; XREF=init_client+176, 0x5d14
000033e8         bl         strerror@PLT                                        ; XREF=init_client+188, 0x5d18
000033ec         ldr        r1, = 0x4a10                                        ; 0x356c,0x4a10
000033f0         ldr        r2, = 0x4be4                                        ; 0x3570,0x4be4
000033f4         mov        r3, r0
000033f8         add        r1, pc, r1                                          ; "SecurityManager"
000033fc         add        r2, pc, r2                                          ; "Failed to open f : %s\\n"
00003400         mov        r0, #0x3
00003404         mvn        r6, #0x68
00003408         bl         __android_log_print@PLT
0000340c         b          0x3384

00003410         ldr        r1, = 0x49ec                                        ; 0x3574,0x49ec, XREF=setCCModeFlag+168
00003414         ldr        r2, = 0x4c2c                                        ; 0x3578,0x4c2c
00003418         mov        r3, r0
0000341c         add        r1, pc, r1                                          ; "SecurityManager"
00003420         mov        r0, #0x3
00003424         add        r2, pc, r2                                          ; "Failed to read_from_secBlock. res : %d\\n"
00003428         bl         __android_log_print@PLT
0000342c         mvn        r7, #0x0                                            ; XREF=init_client+80, 0x5d10
00003430         mvn        r6, #0x7f
00003434         b          0x3384

00003438         bl         __errno@PLT                                         ; XREF=setCCModeFlag+512
0000343c         ldr        r0, [r0]
00003440         bl         strerror@PLT
00003444         ldr        r1, = 0x49b8                                        ; 0x357c,0x49b8
00003448         ldr        r2, = 0x4ba4                                        ; 0x3580,0x4ba4
0000344c         mov        r3, r0
00003450         add        r1, pc, r1                                          ; "SecurityManager"
00003454         add        r2, pc, r2                                          ; "Failed to seek : %s\\n"
00003458         mov        r0, #0x3
0000345c         mvn        r6, #0x69
00003460         bl         __android_log_print@PLT                             ; XREF=control_secRPMB+436, 0x5b40
00003464         b          0x327c

00003468         bl         __errno@PLT                                         ; XREF=setCCModeFlag+400
0000346c         ldr        r0, [r0]
00003470         bl         strerror@PLT
00003474         ldr        r1, = 0x4988                                        ; 0x3584,0x4988
00003478         ldr        r2, = 0x4b74                                        ; 0x3588,0x4b74
0000347c         mov        r3, r0
00003480         add        r1, pc, r1                                          ; "SecurityManager"
00003484         add        r2, pc, r2                                          ; "Failed to seek : %s\\n"
00003488         mov        r0, #0x3
0000348c         mvn        r6, #0x69
00003490         bl         __android_log_print@PLT
00003494         b          0x327c

00003498         ldr        r2, = 0x4cb4                                        ; 0x358c,0x4cb4, XREF=setCCModeFlag+644
0000349c         mov        r1, r6
000034a0         mov        r3, r0
000034a4         add        r2, pc, r2                                          ; "Failed to write_to_secBlock. res : %d\\n", XREF=control_secRPMB+368, 0x5b38
000034a8         mov        r0, #0x3
000034ac         bl         __android_log_print@PLT
000034b0         mvn        r6, #0x80
000034b4         b          0x327c

000034b8         ldr        r1, = 0x4944                                        ; 0x3590,0x4944, XREF=setCCModeFlag+232
000034bc         ldr        r2, = 0x4bd8                                        ; 0x3594,0x4bd8
000034c0         mov        r0, #0x3
000034c4         add        r1, pc, r1                                          ; "SecurityManager"
000034c8         add        r2, pc, r2                                          ; "Failed to Decrypt erawData"
000034cc         bl         __android_log_print@PLT                             ; XREF=control_secRPMB+448, 0x5b44
000034d0         mvn        r6, #0x6e
000034d4         b          0x327c

000034d8         ldr        r1, = 0x4924                                        ; 0x3598,0x4924, XREF=setCCModeFlag+364
000034dc         ldr        r2, = 0x4c10                                        ; 0x359c,0x4c10
000034e0         mov        r0, #0x3
000034e4         add        r1, pc, r1                                          ; "SecurityManager"
000034e8         add        r2, pc, r2                                          ; "Failed to Encrypt rawData"
000034ec         bl         __android_log_print@PLT
000034f0         mvn        r6, #0x6d
000034f4         b          0x327c

000034f8         bl         __errno@PLT                                         ; XREF=setCCModeFlag+424
000034fc         ldr        r0, [r0]                                            ; XREF=control_secRPMB+280, 0x5b30
00003500         bl         strerror@PLT
00003504         ldr        r1, = 0x48f8                                        ; 0x35a0,0x48f8
00003508         ldr        r2, = 0x4c04                                        ; 0x35a4,0x4c04
0000350c         mov        r3, r0
00003510         add        r1, pc, r1                                          ; "SecurityManager"
00003514         add        r2, pc, r2                                          ; "Failed to write : %s\\n"
00003518         mov        r0, #0x3
0000351c         mvn        r6, #0x6a
00003520         bl         __android_log_print@PLT                             ; XREF=control_secRPMB+292, 0x5b34
00003524         b          0x327c

00003528         bl         __stack_chk_fail@PLT                                ; XREF=setCCModeFlag+452
                        ; endp
0000352c         dd         0x00007de4                                          ; XREF=setCCModeFlag+4
00003530         dd         0x00005678                                          ; XREF=setCCModeFlag+8
00003534         dd         0x00004c74                                          ; XREF=setCCModeFlag+184
00003538         dd         0x00005020                                          ; XREF=setCCModeFlag+188
0000353c         dd         0x0001be84                                          ; XREF=setCCModeFlag+236
00003540         dd         0x00004c24                                          ; XREF=setCCModeFlag+264
00003544         dd         0x00004ed8                                          ; XREF=setCCModeFlag+268
00003548         dd         0x0001be38                                          ; XREF=setCCModeFlag+304, control_secRPMB+380, 0x5b3c
0000354c         dd         0x00004b04                                          ; XREF=setCCModeFlag+552
00003550         dd         0x00004d08                                          ; XREF=setCCModeFlag+556
00003554         dd         0x00004ae0                                          ; XREF=setCCModeFlag+588
00003558         dd         0x00004eb4                                          ; XREF=setCCModeFlag+592
0000355c         dd         0x00004e98                                          ; XREF=setCCModeFlag+660
00003560         dd         0x00004a68                                          ; XREF=setCCModeFlag+704
00003564         dd         0x00004c0c                                          ; XREF=setCCModeFlag+708
00003568         dd         0x00004d08                                          ; XREF=setCCModeFlag+752
0000356c         dd         0x00004a10                                          ; XREF=setCCModeFlag+796
00003570         dd         0x00004be4                                          ; XREF=setCCModeFlag+800, control_secRPMB+164, 0x5b28
00003574         dd         0x000049ec                                          ; XREF=setCCModeFlag+832, control_secRPMB+176, 0x5b2c
00003578         dd         0x00004c2c                                          ; XREF=setCCModeFlag+836
0000357c         dd         0x000049b8                                          ; XREF=setCCModeFlag+884
00003580         dd         0x00004ba4                                          ; XREF=setCCModeFlag+888
00003584         dd         0x00004988                                          ; XREF=setCCModeFlag+932
00003588         dd         0x00004b74                                          ; XREF=setCCModeFlag+936
0000358c         dd         0x00004cb4                                          ; XREF=setCCModeFlag+968
00003590         dd         0x00004944                                          ; XREF=setCCModeFlag+1000
00003594         dd         0x00004bd8                                          ; XREF=setCCModeFlag+1004
00003598         dd         0x00004924                                          ; XREF=setCCModeFlag+1032
0000359c         dd         0x00004c10                                          ; XREF=setCCModeFlag+1036
000035a0         dd         0x000048f8                                          ; XREF=setCCModeFlag+1076
000035a4         dd         0x00004c04                                          ; XREF=setCCModeFlag+1080



