/*
 *
 *
 */

#include <jni.h>
#include <string.h>
#include <unistd.h>
#include "jni_common.h"

typedef unsigned short char16_t;

class String8 {
public:
	String8() {
		mString = 0;
	}

	~String8() {
		if (mString) {
			free(mString);
		}
	}

	void set(const char16_t* o, size_t numChars) {
		if (mString) {
			free(mString);
		}
		mString = (char*) malloc(numChars + 1);
		if (!mString) {
			return;
		}
		for (size_t i = 0; i < numChars; i++) {
			mString[i] = (char) o[i];
		}
		mString[numChars] = '\0';
	}

	const char* string() {
		return mString;
	}
private:
	char* mString;
};




extern "C" {

extern int run_3proxy_main(int argc, char* args[]);
extern void mysigusr1(int sig);
extern void mysigterm_nonblock(int sig);



jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	return JNI_VERSION_1_4;
}

void JNI_OnUnload(JavaVM* vm, void* reserved)
{
	return;
}


// Wrapper for main()
jint JNI_FUNC_NAME(RunThreeProxy)(JNIEnv *env,
		jobject thiz, jobjectArray argv) {

	int argc = argv ? env->GetArrayLength(argv) : 0;
	char **args = NULL;
	String8 tmp_8;

	if (argc > 0) {
		args = (char **) malloc((argc + 1) * sizeof(char *));
		for (int i = 0; i < argc; ++i) {
			jstring arg = reinterpret_cast<jstring>(env->GetObjectArrayElement(
					argv, i));
			const jchar *str = env->GetStringCritical(arg, 0);
			tmp_8.set((const char16_t*) str,
					(size_t) env->GetStringLength(arg));
			env->ReleaseStringCritical(arg, str);
			args[i] = strdup(tmp_8.string());
		}
		args[argc] = NULL;

		int ret = run_3proxy_main(argc, args);

		if (args != NULL)
			free(args);

		return ret;

	}

	return 0;
}


void JNI_FUNC_NAME(Reload)(JNIEnv *env,
		jobject thiz) {

	mysigusr1(10);
}

void JNI_FUNC_NAME(Terminate)(JNIEnv *env,
		jobject thiz) {
	mysigterm_nonblock(15);
}

} // end of extern "C"
