
3proxy is a tiny proxy server.

I use its `http proxy` feature in an Android application, it works in a JNI thread.
Here is the JNI part code.


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
So here is the JNI part code:

* Branch [**master**](https://github.com/thomaszhao/3proxy/tree/master) is the original code fetched from [3proxy official website](http://www.3proxy.ru/download/).
* Branch [**thomas/android_jni **](https://github.com/thomaszhao/3proxy/tree/thomas/android_jni) is where I'm working in.


**Features List:**

* Http Proxy runs in a JNI thread.
* Works well with Android VpnService.


**TODO List:**

* nothing.


How to use it in your project?
----------------------------------

### How to Compile?

I hope it should work in this way:

1): fetch this code into your project as a git submodule:

    git submodule add  -b thomas/android_jni   -- "git@github.com:thomaszhao/3proxy.git"  "<your project>/jni"

2) then in your project's `jni/Android.mk` file:

    LOCAL_PATH := $(call my-dir)
    include ../external/3proxy/Android.mk

3) Wrapper your java like this:

```
public class ThreeProxy {
	static {
		java.lang.System.loadLibrary("3proxy");
	}

	// 3proxy's main() function
	public static native int RunThreeProxy(String[] cmd);

	// 3proxy's reload signal
	public static native void Reload();

	// 3proxy's terminate signal
	public static native void Terminate();
}

```


4) Modify `JNI_CLASS_PREFIX` macro to match yours in 3proxy/Android.mk

5) then it can be compiled into `lib3proxy.so`.

### How to tune?

* Macro `THREE_PROXY_JNI`: this macro wraps all the modification aims to work as `JNI thread`.
* Macro `THREE_PROXY_JNI_VPNSERVICE`: this macro wraps codes for working with Android [VpnService](http://developer.android.com/reference/android/net/VpnService.Builder.html).
* Macro `JNI_CLASS_PREFIX` must match your java code path.


###  A full usage:


    TODO


