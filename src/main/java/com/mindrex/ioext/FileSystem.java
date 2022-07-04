package com.mindrex.ioext;

import androidx.annotation.NonNull;

public final class FileSystem {
    private static class Fs {
        private Fs() {
        }
    }

    public static final Fs fs = new Fs();

    public @interface Mode {
        int none = 0, owner_read = 0400, owner_write = 0200, owner_exec = 0100, owner_all = 0700, group_read = 040, group_write = 020, group_exec = 010, group_all = 070, others_read = 04, others_write = 02, others_exec = 01, others_all = 07, all = 0777, set_uid = 04000, set_gid = 02000, sticky_bit = 01000, mask = 07777, unknown = 0xFFFF;
    }

    public @interface FileType {
        int none = 0, not_found = -1, regular = 1, directory = 2, symlink = 3, block = 4, character = 5, fifo = 6, socket = 7, unknown = 8;
    }

    public @interface CopyOptions {
        int none = 0, skip_existing = 1, overwrite_existing = 2, update_existing = 4, recursive = 8, copy_symlinks = 16, skip_symlinks = 32, directories_only = 64, create_symlinks = 128, create_hard_links = 256;
    }

    @NonNull
    public static native String absolute(String path, Pointer<Exception> err);

    @NonNull
    public static native String canonical(String path, Pointer<Exception> err);

    public static native void copy(String src, String dest, @CopyOptions int copyOptions, Pointer<Exception> err);

    public static native void createDirectory(String path, Pointer<Exception> err);

    public static native void createHardLink(String src, String dest, Pointer<Exception> err);

    public static native void createSymbolicLink(String src, String dest, Pointer<Exception> err);

    @NonNull
    public static native String currentPath(Pointer<Exception> err);

    public static native boolean exists(String path, Pointer<Exception> err);

    public static native long fileSize(String path, Pointer<Exception> err);

    @FileType
    public static native int fileType(String path, Pointer<Exception> err);

    public static native long lastWriteTime(String path, Pointer<Exception> err);

    @Mode
    public static native int mode(String path, Pointer<Exception> err);

    public static native void setMode(String path, @Mode int mode, Pointer<Exception> err);

    @NonNull
    public static native String relative(String path, Pointer<Exception> err);

    public static native void remove(String path, Pointer<Exception> err);

    public static native void rename(String src, String dest, Pointer<Exception> err);

    public static native void resize(String path, long size, Pointer<Exception> err);

    public static native void stat(String path, Pointer<Exception> err);

    @NonNull
    public static native String tempDirectoryPath(Pointer<Exception> err);
}