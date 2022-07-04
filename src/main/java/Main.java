import com.mindrex.ioext.FileSystem;
import com.mindrex.ioext.Pointer;

public final class Main {
    static {
        System.load(new java.io.File("libnative-lib.so").getAbsolutePath());
    }

    public static void main(String[] args) {
        final Pointer<Exception> err = new Pointer<>();
        FileSystem.stat("/", err);
        System.out.println(err);
    }
}