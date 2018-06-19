# Variables set during configure phase:
# * build environment, paths
# * features (eg. convert, documentation)
export

CC = gcc
LN_S = ln -s
AR = ar
RM = /bin/rm
RMDIR = /bin/rmdir
INSTALL = /usr/bin/install -c
DISABLE_DOCUMENTATION = 0
DISABLE_BTRFSCONVERT = 0
BTRFSCONVERT_EXT2 = 1
#BTRFSCONVERT_REISERFS = @BTRFSCONVERT_REISERFS@
BTRFSRESTORE_ZSTD = 1

SUBST_CFLAGS = -g -O1 -Wall -D_FORTIFY_SOURCE=2
SUBST_LDFLAGS = 

LIBS_BASE = -luuid -lblkid -L. -pthread
LIBS_COMP = -lz -llzo2 -lzstd
STATIC_LIBS_BASE = -luuid -lblkid -luuid -L. -pthread
STATIC_LIBS_COMP = -lz -llzo2 -lzstd

prefix ?= /usr/local
exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin
libdir ?= ${exec_prefix}/lib
incdir = ${prefix}/include/btrfs
udevdir = /lib/udev
udevruledir = ${udevdir}/rules.d

# external libs required by various binaries; for btrfs-foo,
# specify btrfs_foo_libs = <list of libs>; see $($(subst...)) rules in Makefile
btrfs_convert_libs = -lext2fs -lcom_err 
#@REISERFS_LIBS@

MAKEFILE_INC_INCLUDED = yes
