
3proxy is a proxy server.
I use its `http proxy functions` in an Android application, it works as a JNI thread.
So here is the JNI part code.

**Still in Programming, 20150130, Thomas**


About 3proxy:
----------------------

3Proxy tiny free proxy server is really tiny cross-platform (Win32/Win64&Unix) freeware proxy servers set. It includes HTTP proxy with HTTPS and FTP support, SOCKSv4/SOCKSv4.5/SOCKSv5 proxy (socks/socks.exe), POP3 proxy, SMTP proxy, AIM/ICQ proxy (icqpr/icqpr.exe), MSN messenger / Live messenger proxy (msnpr/msnpr.exe), FTP proxy, caching DNS proxy, TCP and UDP portmappers.

3proxy is forked from: http://www.3proxy.ru/download/ ,

**Fetch history**:

* 20150130, latest stable version: [3proxy-0.7.1.1.tgz](http://www.3proxy.ru/0.7.1.1/3proxy-0.7.1.1.tgz)


What did I do
-----------------------

I'm Thomas Zhao<http://www.thomaszhao.cn>.

I use it in an Android application, it works as a JNI thread.
So here is the JNI part code.

The [**master branch**](https://github.com/thomaszhao/3proxy/tree/master) is the original code fetched from [3proxy official website](http://www.3proxy.ru/download/).

The [**thomas/android_jni branch**](https://github.com/thomaszhao/3proxy/tree/thomas/android_jni) is where I'm working in.


**Features List:**

* Http Proxy runs in a JNI thread.
* Works will with Android VpnService.


**TODO List:**

* all things~


How to use it in your project?
----------------------------------

20150130: still in programming:

### How to Compile?

I hope it should work in this way:

1): fetch this code into your project as a git submodule:

    git submdule xxxxxxxxxxx TODO

2) then in your project's `jnb/Android.mk` file:

    include ../external/3proxy/Android.mk

3) then it can be compiled into `lib3proxy.so`.

### How to tune?

* Macro `THREE_PROXY_JNI`: this macro wraps all the modification aims to work as `JNI thread`.
* Macro `THREE_PROXY_JNI_VPNSERVICE`: this macro wraps codes for working with Android [VpnService](http://developer.android.com/reference/android/net/VpnService.Builder.html).


###  A full usage:


    TODO


