export CFLAGS="-UHAVE_UTIME_H -DHAVE_SOCKETPAIR=0 -DDISABLE_UTMP -DDISABLE_UTMPX -DDISABLE_WTMP -DDISABLE_WTMPX -DNO_UTC_OFFSET -I/home/stone/os/rux-openssh/openssh/libxcrypt/aarch64-libcrypt-install/include -g -O0"
export CC=aarch64-linux-musl-gcc
export AR=aarch64-linux-musl-ar
export RANLIB=aarch64-linux-musl-ranlib
export LDFLAGS="-static -L/home/stone/os/rux-openssh/openssh/libxcrypt/aarch64-libcrypt-install/lib -lcrypt"

make clean

./configure --host=aarch64-linux-gnu \
    --disable-lastlog \
    --disable-libutil \
    --without-openssl \
    --disable-strip \
    --without-pam \
    --without-shadow \
    --disable-pkcs11 \
    --disable-utmp \
    --disable-wtmp \
    --without-zlib

make -j$(nproc)

mv sshd ./output
mv sshd-auth ./output
mv sshd-session ./output
cp ./output/sshd /home/stone/fork/ruxos/apps/c/openssh/rootfs/bin
cp ./output/sshd-auth /home/stone/fork/ruxos/apps/c/openssh/rootfs/usr/local/libexec
cp ./output/sshd-session /home/stone/fork/ruxos/apps/c/openssh/rootfs/usr/local/libexec
