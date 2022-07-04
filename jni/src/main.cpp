#include "stdns.h"
#include <jni.h>

extern "C" {

jstring tojstr(JNIEnv *env, string str) {
	const char* ch = str.c_str();
	const jstring jstr = env->NewStringUTF(ch);
	return jstr;
}

string tostr(JNIEnv *env, jstring jstr) {
	const char* ch = env->GetStringUTFChars(jstr, nullptr);
	const string str = ch;
	env->ReleaseStringUTFChars(jstr, ch);
	return str;
}

void threrr(JNIEnv *env, jobject err, error_code code) {
	if (err != nullptr && code.value() != 0) {
		const jstring msg = tojstr(env, code.message());
		const jclass ioexcls = env->FindClass("java/io/IOException");
		const jobject except = env->NewObject(ioexcls, env->GetMethodID(ioexcls, "<init>", "(Ljava/lang/String;)V"), msg);
		const jfieldID obj = env->GetFieldID(env->GetObjectClass(err), "obj", "Ljava/lang/Object;");
		env->SetObjectField(err, obj, except);
	}
}


jstring Java_com_mindrex_ioext_FileSystem_absolute(JNIEnv *env, jclass cls, jstring path, jobject err) {
	error_code code;
	string result = fs::absolute(tostr(env, path), code);
	threrr(env, err, code);
	return tojstr(env, result);
}

jstring Java_com_mindrex_ioext_FileSystem_canonical(JNIEnv *env, jclass cls, jstring path, jobject err) {
	error_code code;
	string result = fs::canonical(tostr(env, path), code);
	threrr(env, err, code);
	return tojstr(env, result);
}

void Java_com_mindrex_ioext_FileSystem_copy(JNIEnv *env, jclass cls, jstring src, jstring dest, jint options, jobject err) {
	error_code code;
	fs::copy(tostr(env, src), tostr(env, dest), (fs::copy_options) options, code);
	threrr(env, err, code);
}

void Java_com_mindrex_ioext_FileSystem_createDirectory(JNIEnv *env, jclass cls, jstring path, jobject err) {
	error_code code;
	fs::create_directories(tostr(env, path), code);
	threrr(env, err, code);
}

void Java_com_mindrex_ioext_FileSystem_createHardLink(JNIEnv *env, jclass cls, jstring src, jstring dest, jobject err) {
	error_code code;
	fs::create_hard_link(tostr(env, src), tostr(env, dest), code);
	threrr(env, err, code);
}

void Java_com_mindrex_ioext_FileSystem_createSymbolicLink(JNIEnv *env, jclass cls, jstring src, jstring dest, jobject err) {
	error_code code;
	fs::create_symlink(tostr(env, src), tostr(env, dest), code);
	threrr(env, err, code);
}

jstring Java_com_mindrex_ioext_FileSystem_currentPath(JNIEnv *env, jclass cls, jobject err) {
	error_code code;
	string result = fs::current_path(code);
	threrr(env, err, code);
	return tojstr(env, result);
}

jboolean Java_com_mindrex_ioext_FileSystem_exists(JNIEnv *env, jclass cls, jstring path, jobject err) {
	error_code code;
	jboolean result = fs::exists(tostr(env, path), code);
	threrr(env, err, code);
	return result;
}

jlong Java_com_mindrex_ioext_FileSystem_fileSize(JNIEnv *env, jclass cls, jstring path, jobject err) {
	error_code code;
	jlong result = fs::file_size(tostr(env, path), code);
	threrr(env, err, code);
	return result;
}

jint Java_com_mindrex_ioext_FileSystem_fileType(JNIEnv *env, jclass cls, jstring path, jobject err) {
	error_code code;
	jint result = (jint) fs::file_type(tostr(env, path), code);
	threrr(env, err, code);
	return result;
}

jlong Java_com_mindrex_ioext_FileSystem_lastWriteTime(JNIEnv *env, jclass cls, jstring path, jobject err) {
	error_code code;
	fs::file_time result = fs::last_write_time(tostr(env, path), code);
	threrr(env, err, code);
	return to_time_t(result) * 1000L; // java time
}

jint Java_com_mindrex_ioext_FileSystem_mode(JNIEnv *env, jclass cls, jstring path, jobject err) {
	error_code code;
	fs::perms result = fs::permissions(tostr(env, path), code);
	threrr(env, err, code);
	return (jint) result;
}

void Java_com_mindrex_ioext_FileSystem_setMode(JNIEnv *env, jclass cls, jstring path, jint mode, jobject err) {
	error_code code;
	fs::perms perm = (fs::perms) mode;
	fs::permissions(tostr(env, path), perm, code);
	threrr(env, err, code);
}

jstring Java_com_mindrex_ioext_FileSystem_relative(JNIEnv *env, jclass cls, jstring path, jobject err) {
	error_code code;
	string result = fs::relative(tostr(env, path), code);
	threrr(env, err, code);
	return tojstr(env, result);
}

void Java_com_mindrex_ioext_FileSystem_remove(JNIEnv *env, jclass cls, jstring path, jobject err) {
	error_code code;
	fs::remove_all(tostr(env, path), code);
	threrr(env, err, code);
}

void Java_com_mindrex_ioext_FileSystem_rename(JNIEnv *env, jclass cls, jstring src, jstring dest, jobject err) {
	error_code code;
	fs::rename(tostr(env, src), tostr(env, dest), code);
	threrr(env, err, code);
}

void Java_com_mindrex_ioext_FileSystem_resize(JNIEnv *env, jclass cls, jstring path, jlong size, jobject err) {
	error_code code;
	fs::resize_file(tostr(env, path), size, code);
	threrr(env, err, code);
}

void Java_com_mindrex_ioext_FileSystem_stat(JNIEnv *env, jclass cls, jstring path, jobject err) {
	exit(1);
}

jstring Java_com_mindrex_ioext_FileSystem_tempDirectoryPath(JNIEnv *env, jclass cls, jobject err) {
	error_code code;
	string result = fs::temp_directory_path(code);
	threrr(env, err, code);
	return tojstr(env, result);
}

}

int main(const int argc, const char** argv) {
	return 0;
}
