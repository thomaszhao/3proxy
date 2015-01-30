
3proxy works as an Android JNI Thread.


About 3proxy:
----------------------

3Proxy tiny free proxy server is really tiny cross-platform (Win32/Win64&Unix) freeware proxy servers set. It includes HTTP proxy with HTTPS and FTP support, SOCKSv4/SOCKSv4.5/SOCKSv5 proxy (socks/socks.exe), POP3 proxy, SMTP proxy, AIM/ICQ proxy (icqpr/icqpr.exe), MSN messenger / Live messenger proxy (msnpr/msnpr.exe), FTP proxy, caching DNS proxy, TCP and UDP portmappers.

3proxy is forked from: http://www.3proxy.ru/download/ , 

**Fetch history**:

* 20150130, latest stable version: [3proxy-0.7.1.1.tgz](http://www.3proxy.ru/0.7.1.1/3proxy-0.7.1.1.tgz)


What did I do
-----------------------

I use it in an Android application, it works as a JNI thread.
So here is the JNI part code. 

The [**master branch**](https://github.com/thomaszhao/3proxy/tree/master) is the original code fetched from [3proxy official website](http://www.3proxy.ru/download/).

The [**thomas/android_jni branch**](https://github.com/thomaszhao/3proxy/tree/thomas/android_jni) is where I'm working in.



How to use it in your project?
----------------------------------

20150130: still in programming:

I hope it should work in this way:

1): fetch this code into your project as a git submodule:

    git submdule xxxxxxxxxxx TODO

2) then in your project's `jnb/Android.mk` file:

    include ../external/3proxy/Android.mk

3) then it can be compiled into `lib3proxy.so`.



