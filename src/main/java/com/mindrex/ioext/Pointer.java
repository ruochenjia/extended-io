package com.mindrex.ioext;

import java.lang.annotation.Native;
import java.util.Objects;

public final class Pointer<E> implements Cloneable {
    public E obj;

    @Native
    public E[] shadow;

    public Pointer() {
    }

    public Pointer(E obj) {
        this.obj = obj;
    }

    public final Pointer<E> clone() {
        try {
            //noinspection unchecked
            return (Pointer<E>) super.clone();
        } catch (Exception e) {
            return null;
        }
    }

    public final E getClonedObject() {
        return Objects.requireNonNull(clone()).obj;
    }

    @Override
    public final String toString() {
        return String.valueOf(obj);
    }
}