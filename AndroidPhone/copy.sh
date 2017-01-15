#!/bin/sh
date +"%Y%m%d%H%M.%S"
#adb shell 'su 0 date -s 201612300921.39'

cd ~/AndroidPhone/AndroidPhone
adb push unlock /tmp/unlock
#./arm-eabi-readelf -s libSecurityManagerNative.so | grep CC
#adb push su /tmp/su

#adb shell /tmp/su
#adb shell /tmp/unlock
#adb shell logcat
adb shell

#adb shell stop
#adb shell setprop log.redirect-stdio true
#adb shell start

#adb push ~/AndroidPhone/AndroidPhone/libSecurityManagerNative.so /system/lib64/libSecurityManagerNative.so

#adb pull /system/lib/libSecurityManagerNative.DoNotUse.so ~/AndroidPhone/AndroidPhone/lib32.libSecurityManagerNative.so
#adb push ~/AndroidPhone/AndroidPhone/lib32.libSecurityManagerNative.so /system/lib/libSecurityManagerNative.so


#04-03 14:26:11.889  6689  6689 E FRIGATE_BIRD: Error : Connect Failed
#04-03 14:26:11.889  6689  6689 E FRIGATE_BIRD: Error : Socket fail : No such file or directory
#04-03 14:26:11.889  6689  6689 E FRIGATE_BIRD: Client Fail!
#04-03 14:26:11.889  6689  6689 E FRIGATE_BIRD: Error : Failed when executing command
#04-03 14:26:11.889  6689  6689 D SecurityManager: Failed to read_from_secBlock. res : -1

# ln -s /dev/block/mmcblk0 /dev/block/param
