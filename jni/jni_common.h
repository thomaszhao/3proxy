#ifndef MAIN_JNI_H
#define MAIN_JNI_H

#include <android/log.h>

#ifndef TAG
#error "You must define TAG as a string in Makefile"
#endif

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)


/*
 * concatenate Java_com_xxx_pkgname_ with function name.
 *
 * Refer to:
 * C99_TC3
 * 6.10.3.1 Argument substitution 
 * After the arguments for the invocation of a function-like macro have been 
 * identified, argument substitution takes place. Aparameter in the replacement 
 * list, unless preceded by a # or ## preprocessing token or followed by a ## 
 * preprocessing token (see below), is replaced by the corresponding argument 
 * after all macros contained therein have been expanded. Before being substituted, 
 * each argument's preprocessing tokens are completely macro replaced as if they 
 * formed the rest of the preprocessing file; no other preprocessing tokens 
 * are available.
 
 */

#ifndef JNI_CLASS_PREFIX
#error "You must define JNI_CLASS_PREFIX in your Makefile."
#endif

#define JNI_CONCAT2(pre, post)  pre ## post
#define JNI_CONCAT(pre, post)   JNI_CONCAT2(pre, post)
#define JNI_FUNC_NAME(func)     JNI_CONCAT(JNI_CLASS_PREFIX, func)



#endif

