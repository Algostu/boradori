namespace fastio {
      const int is = 1 << 17, os = 1 << 10;
      char ib[is], *ip = ib;
      char ob[os + 16], *op = ob;

      inline char read() {
            if(ib + is == ip) syscall(0, 0, ip = ib, is);
            return *ip;
      }

      inline int readInt() {
            int n = 0;
            while (read() <= ' ') ip++;
            while (read() >= '0') n = (n * 10) + (*ip++ & 15);
            return n;
      }

      inline void flush() {
          syscall(1, 1, op = ob, op - ob);
      }
      struct f {
          ~f() {
              flush();
          }
      } flusher;

      inline void writeInt(int n) {
            char temp[16], *t = temp;
            do *t++ = n % 10 | 48; while(n /= 10);
            do *op++ = *--t; while(t != temp);
            *op++ = '\n';
            if(op >= ob + os) flush();
      }
}