
LOCAL_PATH := $(call my-dir)

###################################################
##   3proxy
###################################################

include $(CLEAR_VARS)
LOCAL_CFLAGS := -Wall -g -O2 -c -pthread -DGETHOSTBYNAME_R -D_THREAD_SAFE -D_REENTRANT -DNOODBC -DWITH_STD_MALLOC -DFD_SETSIZE=4096 -DWITH_POLL -DMODULEMAINFUNC=mainfunc 
LOCAL_CFLAGS += -DTHREE_POROXY_JNI -DTAG=\"3proxy\" -DANONYMOUS
# JNI_CLASS_PREFIX should match your java packet-class.
LOCAL_CFLAGS += -DJNI_CLASS_PREFIX=Java_com_chinacache_mop_jni_ThreeProxy_

LOCAL_LDFLAGS :=  -ldl  -Wall -O2 -pthread -llog

LOCAL_C_INCLUDES := $(LOCAL_PATH)/src/ $(LOCAL_PATH)/jni/

PROXY_FILES := 3proxy.c \
		proxymain.c \
		proxy.c     \
		pop3p.c    \
		smtpp.c    \
		ftppr.c    \
		socks.c    \
		tcppm.c    \
		icqpr.c    \
		msnpr.c    \
		udppm.c    \
		sockmap.c  \
		sockgetchar.c   \
		myalloc.c  \
		common.c   \
		auth.c     \
		datatypes.c   \
		libs/md4.c   \
		libs/md5.c  \
		mycrypt.c  \
		base64.c   \
		ftp.c      \
		libs/smbdes.c   \
		ntlm.c     \
		stringtable.c   \
		webadmin.c   \
		dnspr.c   \
		plugins.c

LOCAL_SRC_FILES := $(addprefix src/, $(PROXY_FILES))   \
		jni/3proxy_jni.cpp

LOCAL_MODULE    := 3proxy

include $(BUILD_SHARED_LIBRARY)



