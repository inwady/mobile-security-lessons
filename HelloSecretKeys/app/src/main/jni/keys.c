#include <jni.h>

jstring hideFunc(JNIEnv *env, jobject instance);

static JNINativeMethod methods[] = {
        {"getNativeKey1", "()Ljava/lang/String;", (void *)&hideFunc},
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    jint res;

    JNIEnv* env;
    if ((*vm)->GetEnv(vm, (void**)&env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    jclass clz = (*env)->FindClass(env, "com/tyagiabhinav/hellosecretkeys/MainActivity");
    res = (*env)->RegisterNatives(env, clz, methods, sizeof(methods) / sizeof(methods[0]));
    if (res != JNI_OK) {
        return JNI_ERR;
    }

    return JNI_VERSION_1_6;
}

jstring hideFunc(JNIEnv *env, jobject instance) {
    return (*env)->NewStringUTF(env, "TmF0aXZlNWVjcmV0UEBzc3cwcmQx");
}

JNIEXPORT jstring JNICALL
Java_com_tyagiabhinav_hellosecretkeys_MainActivity_getNativeKey2(JNIEnv *env, jobject instance) {
    return (*env)->NewStringUTF(env, "TmF0aXZlNWVjcmV0UEBzc3cwcmQy");
}
