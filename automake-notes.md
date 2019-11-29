# Automake notes

```


https://medium.com/@levioza/cross-compiling-c-c-native-external-libraries-for-android-e100d9b2d987
Here, I’m going to explain the process of building an external native library using the Android NDK Toolchain to be able to use it in your application.


on project structure in Android studio sample project

sdk location
/Users/oketo/Library/Android/sdk

ndk location
/Users/oketo/Library/Android/sdk/ndk-bundle

Grab the Android NDK and set an environmental variable to its location. 

export NDK_LOCATION="/Users/oketo/Library/Android/sdk"
export ANDROID_NDK_HOME="$NDK_LOCATION/ndk-bundle"

Install the toolchain.

${ANDROID_NDK_HOME}/build/tools/make-standalone-toolchain.sh --platform=android-16 --install-dir=${ANDROID_NDK_HOME}/android-toolchain


https://developer.android.com/ndk/guides/standalone_toolchain
Standalone Toolchains

https://medium.com/@levioza/cross-compiling-c-c-native-external-libraries-for-android-e100d9b2d987
Cross-Compiling C/C++ Native External Libraries for Android

https://github.com/levioza/android-c-cpp-libraries
Cross-Compiling C/C++ Native External Libraries for Android

https://dmerej.info/blog/post/chuck-norris-part-6-android-cross-compilation/
Let's Build Chuck Norris! - Part 6: Cross-compilation for Android

https://stackoverflow.com/questions/26409648/how-to-compile-a-c-program-with-make-on-mac-os-x-terminal
How to compile a C program with make on Mac OS X Terminal

https://www.cs.dartmouth.edu/~campbell/cs50/buildlib.html
CS 50: Software Design and Implementation

http://www.xappsoftware.com/wordpress/2012/12/20/how-to-create-a-shared-library-on-mac-os-x-using-gcc/
How to create a shared library on Mac OS X (using gcc)

http://www.eupcs.org/wiki/Introduction_To_Makefiles
Introduction To Makefiles

https://gist.github.com/xuhdev/1873316
Makefile template for shared library https://www.topbug.net/blog/2019/10/28/makefile-template-for-a-shared-library-in-c-with-explanations/

https://www.topbug.net/blog/2019/10/28/makefile-template-for-a-shared-library-in-c-with-explanations/
Makefile Template for a Shared Library in C (with Explanations)

https://thoughtbot.com/blog/the-magic-behind-configure-make-make-install
The magic behind configure, make, make install

#include <stdio.h>

int
main(int argc, char* argv[])
{
    printf("Hello world\n");
    return 0;
}

configure.ac
AC_INIT([helloworld], [0.1], [george@thoughtbot.com])
AM_INIT_AUTOMAKE
AC_PROG_CC
AC_CONFIG_FILES([Makefile])
AC_OUTPUT

Makefile.am
AUTOMAKE_OPTIONS = foreign
bin_PROGRAMS = helloworld
helloworld_SOURCES = main.c

brew install autoconf
sudo chown -R $(whoami) /usr/local/var/homebrew
sudo chown -R $(whoami) /usr/local/etc/bash_completion.d /usr/local/lib/python3.7/site-packages /usr/local/share/aclocal /usr/local/share/doc /usr/local/share/info /usr/local/share/locale /usr/local/share/man /usr/local/share/man/man1 /usr/local/share/man/man3 /usr/local/share/man/man5 /usr/local/share/man/man7 /usr/local/share/man/man8 /usr/local/share/zsh /usr/local/share/zsh/site-functions
brew install autoconf
error: could not lock config file .git/config: Permission denied
==> Downloading https://homebrew.bintray.com/bottles/autoconf-2.69.catalina.bottle.4.tar.gz
brew install autoconf
Warning: autoconf 2.69 is already installed and up-to-date
To reinstall 2.69, run `brew reinstall autoconf`
aclocal still not found

https://superuser.com/questions/383580/how-to-install-autoconf-automake-and-related-tools-on-mac-os-x-from-source
How to install Autoconf, Automake and related tools on Mac OS X from source?

brew install autoconf automake libtool
In order to prevent conflicts with Apple's own libtool we have prepended a "g"
so, you have instead: glibtool and glibtoolize.

oketo@lasalles-MBP makehowto % which autoconf
/usr/local/bin/autoconf
oketo@lasalles-MBP makehowto % which aclocal 
/usr/local/bin/aclocal
oketo@lasalles-MBP makehowto % which automake
/usr/local/bin/automake
oketo@lasalles-MBP makehowto % which m4      
/usr/bin/m4

oketo@lasalles-MBP makehowto % /usr/local/bin/aclocal
oketo@lasalles-MBP makehowto % ls -al
total 112
drwxr-xr-x  7 oketo  staff    224 Nov 29 02:31 .
drwxr-xr-x  6 oketo  staff    192 Nov 29 02:19 ..
-rw-r--r--  1 oketo  staff     81 Nov 29 02:21 Makefile.am
-rw-r--r--  1 oketo  staff  41888 Nov 29 02:31 aclocal.m4
drwxr-xr-x  5 oketo  staff    160 Nov 29 02:31 autom4te.cache
-rw-r--r--  1 oketo  staff    120 Nov 29 02:20 configure.ac
-rw-r--r--  1 oketo  staff    100 Nov 29 02:19 main.c

oketo@lasalles-MBP makehowto % /usr/local/bin/autoconf
oketo@lasalles-MBP makehowto % ls -al
total 392
drwxr-xr-x  8 oketo  staff     256 Nov 29 02:32 .
drwxr-xr-x  6 oketo  staff     192 Nov 29 02:19 ..
-rw-r--r--  1 oketo  staff      81 Nov 29 02:21 Makefile.am
-rw-r--r--  1 oketo  staff   41888 Nov 29 02:31 aclocal.m4
drwxr-xr-x  7 oketo  staff     224 Nov 29 02:32 autom4te.cache
-rwxr-xr-x  1 oketo  staff  141193 Nov 29 02:32 configure
-rw-r--r--  1 oketo  staff     120 Nov 29 02:20 configure.ac
-rw-r--r--  1 oketo  staff     100 Nov 29 02:19 main.c
oketo@lasalles-MBP makehowto % 

/usr/local/bin/automake --add-missing

oketo@lasalles-MBP makehowto % /usr/local/bin/automake --add-missing
configure.ac:3: installing './compile'
configure.ac:2: installing './install-sh'
configure.ac:2: installing './missing'
Makefile.am: installing './depcomp'
oketo@lasalles-MBP makehowto % ls -al
total 440
drwxr-xr-x  13 oketo  staff     416 Nov 29 02:33 .
drwxr-xr-x   6 oketo  staff     192 Nov 29 02:19 ..
-rw-r--r--   1 oketo  staff      81 Nov 29 02:21 Makefile.am
-rw-r--r--   1 oketo  staff   23688 Nov 29 02:33 Makefile.in
-rw-r--r--   1 oketo  staff   41888 Nov 29 02:31 aclocal.m4
drwxr-xr-x   7 oketo  staff     224 Nov 29 02:33 autom4te.cache
lrwxr-xr-x   1 oketo  staff      63 Nov 29 02:33 compile -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/compile
-rwxr-xr-x   1 oketo  staff  141193 Nov 29 02:32 configure
-rw-r--r--   1 oketo  staff     120 Nov 29 02:20 configure.ac
lrwxr-xr-x   1 oketo  staff      63 Nov 29 02:33 depcomp -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/depcomp
lrwxr-xr-x   1 oketo  staff      66 Nov 29 02:33 install-sh -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/install-sh
-rw-r--r--   1 oketo  staff     100 Nov 29 02:19 main.c
lrwxr-xr-x   1 oketo  staff      63 Nov 29 02:33 missing -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/missing
oketo@lasalles-MBP makehowto % ls -al


oketo@lasalles-MBP makehowto % ./configure
checking for a BSD-compatible install... /usr/bin/install -c
checking whether build environment is sane... yes
checking for a thread-safe mkdir -p... ./install-sh -c -d
checking for gawk... no
checking for mawk... no
checking for nawk... no
checking for awk... awk
checking whether make sets $(MAKE)... yes
checking whether make supports nested variables... yes
checking for gcc... gcc
checking whether the C compiler works... yes
checking for C compiler default output file name... a.out
checking for suffix of executables... 
checking whether we are cross compiling... no
checking for suffix of object files... o
checking whether we are using the GNU C compiler... yes
checking whether gcc accepts -g... yes
checking for gcc option to accept ISO C89... none needed
checking whether gcc understands -c and -o together... yes
checking whether make supports the include directive... yes (GNU style)
checking dependency style of gcc... gcc3
checking that generated files are newer than configure... done
configure: creating ./config.status
config.status: creating Makefile
config.status: executing depfiles commands
oketo@lasalles-MBP makehowto % ls -al
total 576
drwxr-xr-x  17 oketo  staff     544 Nov 29 02:34 .
drwxr-xr-x   6 oketo  staff     192 Nov 29 02:19 ..
drwxr-xr-x   3 oketo  staff      96 Nov 29 02:34 .deps
-rw-r--r--   1 oketo  staff   23780 Nov 29 02:34 Makefile
-rw-r--r--   1 oketo  staff      81 Nov 29 02:21 Makefile.am
-rw-r--r--   1 oketo  staff   23688 Nov 29 02:33 Makefile.in
-rw-r--r--   1 oketo  staff   41888 Nov 29 02:31 aclocal.m4
drwxr-xr-x   7 oketo  staff     224 Nov 29 02:33 autom4te.cache
lrwxr-xr-x   1 oketo  staff      63 Nov 29 02:33 compile -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/compile
-rw-r--r--   1 oketo  staff    9372 Nov 29 02:34 config.log
-rwxr-xr-x   1 oketo  staff   29026 Nov 29 02:34 config.status
-rwxr-xr-x   1 oketo  staff  141193 Nov 29 02:32 configure
-rw-r--r--   1 oketo  staff     120 Nov 29 02:20 configure.ac
lrwxr-xr-x   1 oketo  staff      63 Nov 29 02:33 depcomp -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/depcomp
lrwxr-xr-x   1 oketo  staff      66 Nov 29 02:33 install-sh -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/install-sh
-rw-r--r--   1 oketo  staff     100 Nov 29 02:19 main.c
lrwxr-xr-x   1 oketo  staff      63 Nov 29 02:33 missing -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/missing
oketo@lasalles-MBP makehowto % 


oketo@lasalles-MBP makehowto % make dist
/Library/Developer/CommandLineTools/usr/bin/make  dist-gzip am__post_remove_distdir='@:'
/Library/Developer/CommandLineTools/usr/bin/make  distdir-am
if test -d "helloworld-0.1"; then find "helloworld-0.1" -type d ! -perm -200 -exec chmod u+w {} ';' && rm -rf "helloworld-0.1" || { sleep 5 && rm -rf "helloworld-0.1"; }; else :; fi
test -d "helloworld-0.1" || mkdir "helloworld-0.1"
test -n "" \
	|| find "helloworld-0.1" -type d ! -perm -755 \
		-exec chmod u+rwx,go+rx {} \; -o \
	  ! -type d ! -perm -444 -links 1 -exec chmod a+r {} \; -o \
	  ! -type d ! -perm -400 -exec chmod a+r {} \; -o \
	  ! -type d ! -perm -444 -exec /bin/sh /Users/oketo/CLionProjects/makehowto/install-sh -c -m a+r {} {} \; \
	|| chmod -R a+r "helloworld-0.1"
tardir=helloworld-0.1 && ${TAR-tar} chof - "$tardir" | eval GZIP= gzip --best -c >helloworld-0.1.tar.gz
if test -d "helloworld-0.1"; then find "helloworld-0.1" -type d ! -perm -200 -exec chmod u+w {} ';' && rm -rf "helloworld-0.1" || { sleep 5 && rm -rf "helloworld-0.1"; }; else :; fi
oketo@lasalles-MBP makehowto % ls -al
total 728
drwxr-xr-x  18 oketo  staff     576 Nov 29 02:35 .
drwxr-xr-x   6 oketo  staff     192 Nov 29 02:19 ..
drwxr-xr-x   3 oketo  staff      96 Nov 29 02:34 .deps
-rw-r--r--   1 oketo  staff   23780 Nov 29 02:34 Makefile
-rw-r--r--   1 oketo  staff      81 Nov 29 02:21 Makefile.am
-rw-r--r--   1 oketo  staff   23688 Nov 29 02:33 Makefile.in
-rw-r--r--   1 oketo  staff   41888 Nov 29 02:31 aclocal.m4
drwxr-xr-x   7 oketo  staff     224 Nov 29 02:33 autom4te.cache
lrwxr-xr-x   1 oketo  staff      63 Nov 29 02:33 compile -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/compile
-rw-r--r--   1 oketo  staff    9372 Nov 29 02:34 config.log
-rwxr-xr-x   1 oketo  staff   29026 Nov 29 02:34 config.status
-rwxr-xr-x   1 oketo  staff  141193 Nov 29 02:32 configure
-rw-r--r--   1 oketo  staff     120 Nov 29 02:20 configure.ac
lrwxr-xr-x   1 oketo  staff      63 Nov 29 02:33 depcomp -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/depcomp
-rw-r--r--   1 oketo  staff   75246 Nov 29 02:35 helloworld-0.1.tar.gz
lrwxr-xr-x   1 oketo  staff      66 Nov 29 02:33 install-sh -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/install-sh
-rw-r--r--   1 oketo  staff     100 Nov 29 02:19 main.c
lrwxr-xr-x   1 oketo  staff      63 Nov 29 02:33 missing -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/missing
oketo@lasalles-MBP makehowto % 


oketo@lasalles-MBP makehowto % make distcheck
/Library/Developer/CommandLineTools/usr/bin/make  dist-gzip am__post_remove_distdir='@:'
/Library/Developer/CommandLineTools/usr/bin/make  distdir-am
if test -d "helloworld-0.1"; then find "helloworld-0.1" -type d ! -perm -200 -exec chmod u+w {} ';' && rm -rf "helloworld-0.1" || { sleep 5 && rm -rf "helloworld-0.1"; }; else :; fi
test -d "helloworld-0.1" || mkdir "helloworld-0.1"
test -n "" \
	|| find "helloworld-0.1" -type d ! -perm -755 \
		-exec chmod u+rwx,go+rx {} \; -o \
	  ! -type d ! -perm -444 -links 1 -exec chmod a+r {} \; -o \
	  ! -type d ! -perm -400 -exec chmod a+r {} \; -o \
	  ! -type d ! -perm -444 -exec /bin/sh /Users/oketo/CLionProjects/makehowto/install-sh -c -m a+r {} {} \; \
	|| chmod -R a+r "helloworld-0.1"
tardir=helloworld-0.1 && ${TAR-tar} chof - "$tardir" | eval GZIP= gzip --best -c >helloworld-0.1.tar.gz
if test -d "helloworld-0.1"; then find "helloworld-0.1" -type d ! -perm -200 -exec chmod u+w {} ';' && rm -rf "helloworld-0.1" || { sleep 5 && rm -rf "helloworld-0.1"; }; else :; fi
case 'helloworld-0.1.tar.gz' in \
	*.tar.gz*) \
	  eval GZIP= gzip --best -dc helloworld-0.1.tar.gz | ${TAR-tar} xf - ;;\
	*.tar.bz2*) \
	  bzip2 -dc helloworld-0.1.tar.bz2 | ${TAR-tar} xf - ;;\
	*.tar.lz*) \
	  lzip -dc helloworld-0.1.tar.lz | ${TAR-tar} xf - ;;\
	*.tar.xz*) \
	  xz -dc helloworld-0.1.tar.xz | ${TAR-tar} xf - ;;\
	*.tar.Z*) \
	  uncompress -c helloworld-0.1.tar.Z | ${TAR-tar} xf - ;;\
	*.shar.gz*) \
	  eval GZIP= gzip --best -dc helloworld-0.1.shar.gz | unshar ;;\
	*.zip*) \
	  unzip helloworld-0.1.zip ;;\
	esac
chmod -R a-w helloworld-0.1
chmod u+w helloworld-0.1
mkdir helloworld-0.1/_build helloworld-0.1/_build/sub helloworld-0.1/_inst
chmod a-w helloworld-0.1
test -d helloworld-0.1/_build || exit 0; \
	dc_install_base=`CDPATH="${ZSH_VERSION+.}:" && cd helloworld-0.1/_inst && pwd | sed -e 's,^[^:\\/]:[\\/],/,'` \
	  && dc_destdir="${TMPDIR-/tmp}/am-dc-$$/" \
	  && am__cwd=`pwd` \
	  && CDPATH="${ZSH_VERSION+.}:" && cd helloworld-0.1/_build/sub \
	  && ../../configure \
	     \
	     \
	    --srcdir=../.. --prefix="$dc_install_base" \
	  && /Library/Developer/CommandLineTools/usr/bin/make  \
	  && /Library/Developer/CommandLineTools/usr/bin/make  dvi \
	  && /Library/Developer/CommandLineTools/usr/bin/make  check \
	  && /Library/Developer/CommandLineTools/usr/bin/make  install \
	  && /Library/Developer/CommandLineTools/usr/bin/make  installcheck \
	  && /Library/Developer/CommandLineTools/usr/bin/make  uninstall \
	  && /Library/Developer/CommandLineTools/usr/bin/make  distuninstallcheck_dir="$dc_install_base" \
	        distuninstallcheck \
	  && chmod -R a-w "$dc_install_base" \
	  && ({ \
	       (cd ../.. && umask 077 && mkdir "$dc_destdir") \
	       && /Library/Developer/CommandLineTools/usr/bin/make  DESTDIR="$dc_destdir" install \
	       && /Library/Developer/CommandLineTools/usr/bin/make  DESTDIR="$dc_destdir" uninstall \
	       && /Library/Developer/CommandLineTools/usr/bin/make  DESTDIR="$dc_destdir" \
	            distuninstallcheck_dir="$dc_destdir" distuninstallcheck; \
	      } || { rm -rf "$dc_destdir"; exit 1; }) \
	  && rm -rf "$dc_destdir" \
	  && /Library/Developer/CommandLineTools/usr/bin/make  dist \
	  && rm -rf helloworld-0.1.tar.gz \
	  && /Library/Developer/CommandLineTools/usr/bin/make  distcleancheck \
	  && cd "$am__cwd" \
	  || exit 1
checking for a BSD-compatible install... /usr/bin/install -c
checking whether build environment is sane... yes
checking for a thread-safe mkdir -p... ../../install-sh -c -d
checking for gawk... no
checking for mawk... no
checking for nawk... no
checking for awk... awk
checking whether make sets $(MAKE)... yes
checking whether make supports nested variables... yes
checking for gcc... gcc
checking whether the C compiler works... yes
checking for C compiler default output file name... a.out
checking for suffix of executables... 
checking whether we are cross compiling... no
checking for suffix of object files... o
checking whether we are using the GNU C compiler... yes
checking whether gcc accepts -g... yes
checking for gcc option to accept ISO C89... none needed
checking whether gcc understands -c and -o together... yes
checking whether make supports the include directive... yes (GNU style)
checking dependency style of gcc... gcc3
checking that generated files are newer than configure... done
configure: creating ./config.status
config.status: creating Makefile
config.status: executing depfiles commands
gcc -DPACKAGE_NAME=\"helloworld\" -DPACKAGE_TARNAME=\"helloworld\" -DPACKAGE_VERSION=\"0.1\" -DPACKAGE_STRING=\"helloworld\ 0.1\" -DPACKAGE_BUGREPORT=\"george@thoughtbot.com\" -DPACKAGE_URL=\"\" -DPACKAGE=\"helloworld\" -DVERSION=\"0.1\" -I. -I../..     -g -O2 -MT main.o -MD -MP -MF .deps/main.Tpo -c -o main.o ../../main.c
mv -f .deps/main.Tpo .deps/main.Po
gcc  -g -O2   -o helloworld main.o  
make[1]: Nothing to be done for `dvi'.
make[1]: Nothing to be done for `check'.
 ../../install-sh -c -d '/Users/oketo/CLionProjects/makehowto/helloworld-0.1/_inst/bin'
  /usr/bin/install -c helloworld '/Users/oketo/CLionProjects/makehowto/helloworld-0.1/_inst/bin'
make[2]: Nothing to be done for `install-data-am'.
make[1]: Nothing to be done for `installcheck'.
 ( cd '/Users/oketo/CLionProjects/makehowto/helloworld-0.1/_inst/bin' && rm -f helloworld )
 ../../install-sh -c -d '/var/folders/ln/54kcb9c11xvflf0jb8kstr9r0000gp/T//am-dc-88983//Users/oketo/CLionProjects/makehowto/helloworld-0.1/_inst/bin'
  /usr/bin/install -c helloworld '/var/folders/ln/54kcb9c11xvflf0jb8kstr9r0000gp/T//am-dc-88983//Users/oketo/CLionProjects/makehowto/helloworld-0.1/_inst/bin'
make[2]: Nothing to be done for `install-data-am'.
 ( cd '/var/folders/ln/54kcb9c11xvflf0jb8kstr9r0000gp/T//am-dc-88983//Users/oketo/CLionProjects/makehowto/helloworld-0.1/_inst/bin' && rm -f helloworld )
/Library/Developer/CommandLineTools/usr/bin/make  dist-gzip am__post_remove_distdir='@:'
/Library/Developer/CommandLineTools/usr/bin/make  distdir-am
if test -d "helloworld-0.1"; then find "helloworld-0.1" -type d ! -perm -200 -exec chmod u+w {} ';' && rm -rf "helloworld-0.1" || { sleep 5 && rm -rf "helloworld-0.1"; }; else :; fi
test -d "helloworld-0.1" || mkdir "helloworld-0.1"
test -n "" \
	|| find "helloworld-0.1" -type d ! -perm -755 \
		-exec chmod u+rwx,go+rx {} \; -o \
	  ! -type d ! -perm -444 -links 1 -exec chmod a+r {} \; -o \
	  ! -type d ! -perm -400 -exec chmod a+r {} \; -o \
	  ! -type d ! -perm -444 -exec /bin/sh /Users/oketo/CLionProjects/makehowto/helloworld-0.1/install-sh -c -m a+r {} {} \; \
	|| chmod -R a+r "helloworld-0.1"
tardir=helloworld-0.1 && ${TAR-tar} chof - "$tardir" | eval GZIP= gzip --best -c >helloworld-0.1.tar.gz
if test -d "helloworld-0.1"; then find "helloworld-0.1" -type d ! -perm -200 -exec chmod u+w {} ';' && rm -rf "helloworld-0.1" || { sleep 5 && rm -rf "helloworld-0.1"; }; else :; fi
test -z "helloworld" || rm -f helloworld
rm -f *.o
rm -f *.tab.c
test -z "" || rm -f 
test . = "../.." || test -z "" || rm -f 
rm -f TAGS ID GTAGS GRTAGS GSYMS GPATH tags
rm -f cscope.out cscope.in.out cscope.po.out cscope.files
rm -f config.status config.cache config.log configure.lineno config.status.lineno
rm -f ./.deps/main.Po
rm -f Makefile
if test -d "helloworld-0.1"; then find "helloworld-0.1" -type d ! -perm -200 -exec chmod u+w {} ';' && rm -rf "helloworld-0.1" || { sleep 5 && rm -rf "helloworld-0.1"; }; else :; fi
================================================
helloworld-0.1 archives ready for distribution: 
helloworld-0.1.tar.gz
================================================
oketo@lasalles-MBP makehowto % 

oketo@lasalles-MBP makehowto % ./configure
checking for a BSD-compatible install... /usr/bin/install -c
checking whether build environment is sane... yes
checking for a thread-safe mkdir -p... ./install-sh -c -d
checking for gawk... no
checking for mawk... no
checking for nawk... no
checking for awk... awk
checking whether make sets $(MAKE)... yes
checking whether make supports nested variables... yes
checking for gcc... gcc
checking whether the C compiler works... yes
checking for C compiler default output file name... a.out
checking for suffix of executables... 
checking whether we are cross compiling... no
checking for suffix of object files... o
checking whether we are using the GNU C compiler... yes
checking whether gcc accepts -g... yes
checking for gcc option to accept ISO C89... none needed
checking whether gcc understands -c and -o together... yes
checking whether make supports the include directive... yes (GNU style)
checking dependency style of gcc... gcc3
checking that generated files are newer than configure... done
configure: creating ./config.status
config.status: creating Makefile
config.status: executing depfiles commands
oketo@lasalles-MBP makehowto % make
gcc -DPACKAGE_NAME=\"helloworld\" -DPACKAGE_TARNAME=\"helloworld\" -DPACKAGE_VERSION=\"0.1\" -DPACKAGE_STRING=\"helloworld\ 0.1\" -DPACKAGE_BUGREPORT=\"george@thoughtbot.com\" -DPACKAGE_URL=\"\" -DPACKAGE=\"helloworld\" -DVERSION=\"0.1\" -I.     -g -O2 -MT main.o -MD -MP -MF .deps/main.Tpo -c -o main.o main.c
mv -f .deps/main.Tpo .deps/main.Po
gcc  -g -O2   -o helloworld main.o  
oketo@lasalles-MBP makehowto % ls -al
total 872
drwxr-xr-x  20 oketo  staff     640 Nov 29 02:37 .
drwxr-xr-x   6 oketo  staff     192 Nov 29 02:19 ..
drwxr-xr-x   3 oketo  staff      96 Nov 29 02:37 .deps
-rw-r--r--   1 oketo  staff   23780 Nov 29 02:37 Makefile
-rw-r--r--   1 oketo  staff      81 Nov 29 02:21 Makefile.am
-rw-r--r--   1 oketo  staff   23688 Nov 29 02:33 Makefile.in
-rw-r--r--   1 oketo  staff   41888 Nov 29 02:31 aclocal.m4
drwxr-xr-x   7 oketo  staff     224 Nov 29 02:33 autom4te.cache
lrwxr-xr-x   1 oketo  staff      63 Nov 29 02:33 compile -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/compile
-rw-r--r--   1 oketo  staff    9417 Nov 29 02:37 config.log
-rwxr-xr-x   1 oketo  staff   29026 Nov 29 02:37 config.status
-rwxr-xr-x   1 oketo  staff  141193 Nov 29 02:32 configure
-rw-r--r--   1 oketo  staff     120 Nov 29 02:20 configure.ac
lrwxr-xr-x   1 oketo  staff      63 Nov 29 02:33 depcomp -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/depcomp
-rwxr-xr-x   1 oketo  staff   12780 Nov 29 02:37 helloworld
-rw-r--r--   1 oketo  staff   75244 Nov 29 02:35 helloworld-0.1.tar.gz
lrwxr-xr-x   1 oketo  staff      66 Nov 29 02:33 install-sh -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/install-sh
-rw-r--r--   1 oketo  staff     100 Nov 29 02:19 main.c
-rw-r--r--   1 oketo  staff    2496 Nov 29 02:37 main.o
lrwxr-xr-x   1 oketo  staff      63 Nov 29 02:33 missing -> /usr/local/Cellar/automake/1.16.1_1/share/automake-1.16/missing
oketo@lasalles-MBP makehowto % make install
 ./install-sh -c -d '/usr/local/bin'
  /usr/bin/install -c helloworld '/usr/local/bin'
make[1]: Nothing to be done for `install-data-am'.
oketo@lasalles-MBP makehowto % 


Now we know where this incantation comes from and how it works!

On the maintainer’s system:

aclocal # Set up an m4 environment
autoconf # Generate configure from configure.ac
automake --add-missing # Generate Makefile.in from Makefile.am
./configure # Generate Makefile from Makefile.in
make distcheck # Use Makefile to build and test a tarball to distribute
On the end-user’s system:

./configure # Generate Makefile from Makefile.in
make # Use Makefile to build the program
make install # Use Makefile to install the program

oketo@lasalles-MBP makehowto % which helloworld
/usr/local/bin/helloworld

oketo@lasalles-MBP makehowto % /usr/local/bin/helloworld
Hello world

oketo@lasalles-MBP makehowto % make uninstall
 ( cd '/usr/local/bin' && rm -f helloworld )
oketo@lasalles-MBP makehowto % which helloworld
helloworld not found


https://gnu.huihoo.org/automake-1.4/html_chapter/automake_7.html
Building Programs and Libraries

https://stackoverflow.com/questions/8916425/how-to-create-a-shared-library-so-in-an-automake-script
How to create a shared library (.so) in an automake script?

https://digitalleaves.com/blog/2017/12/build-cross-platform-c-project-autotools/
How To Build a Cross-Platform C++ Project With Autotools

configure.ac

AC_INIT([helloworld], [0.1], [george@thoughtbot.com])
AM_INIT_AUTOMAKE
AC_PROG_CC
AC_CONFIG_FILES([Makefile])
AC_OUTPUT



AC_INIT([helloWorld], [1.0], [contact@digitalleaves.com])
AM_INIT_AUTOMAKE

AC_CONFIG_SRCDIR([src/main.cpp])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
LT_INIT
AC_ENABLE_SHARED
AC_DISABLE_STATIC
AC_PROG_LIBTOOL(libtool)

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T

# Output Makefile files.
AC_CONFIG_FILES([Makefile src/Makefile doc/Makefile examples/Makefile man/Makefile scripts/Makefile])
AC_OUTPUT

Good for understanding automake
https://thoughtbot.com/blog/the-magic-behind-configure-make-make-install
The magic behind configure, make, make install

Good for getting/showing working example
https://digitalleaves.com/blog/2017/12/build-cross-platform-c-project-autotools/
How To Build a Cross-Platform C++ Project With Autotools


https://stackoverflow.com/questions/8916425/how-to-create-a-shared-library-so-in-an-automake-script
How to create a shared library (.so) in an automake script?


/usr/local/lib/libHelloWorld.0.dylib
/Users/oketo/CLionProjects/bolib/cmake-build-debug/libbolib.dylib




------------------


https://medium.com/@StueyGK/static-libraries-vs-dynamic-libraries-af78f0b5f1e4

Static libraries, while reusable in multiple programs, are locked into a program at compile time. Dynamic, or shared libraries on the other hand, exist as separate files outside of the executable file. ... In contrast, a dynamic library can be modified without a need to re-compile.

https://stackoverflow.com/questions/17511496/how-to-create-a-shared-library-with-cmake
How to create a shared library with cmake?

https://www.electronicdesign.com/automotive/software-tools-target-adass-and-self-driving-cars
https://www.electronicdesign.com/dev-tools/what-s-difference-between-c-now-and-then
c11 vs c99

C11 is the latest ANSI C specification, ISO/IEC 9899:2011. C11 looked to address the issues of C99 and to more closely match the C++ standard, C++11. It changes some C99 features required to optional. Some of the features include variable length arrays and complex numbers. This makes it easier for compiler vendors to meet C11’s required function set.

C99, ANSI C
The ISO/IEC 9899:1999 standard, also known as C99, was released in 1999 and adopted in 2000.


clion
/Users/oketo/CLionProjects/bolib
c99 and shared

ls -al /Library/Developer/CommandLineTools/usr/bin/ar
-rwxr-xr-x  1 root  wheel  42144 Sep  5 22:51 /Library/Developer/CommandLineTools/usr/bin/ar

How to CMake Good - 1b - Adding a Library
https://www.youtube.com/watch?v=abuCXC3t6eQ


https://stackoverflow.com/questions/8774593/cmake-link-to-external-library

this works

cmake_minimum_required(VERSION 3.15)
project(pointers C)

set(CMAKE_C_STANDARD 99)

add_executable(pointers main.c)

add_library( bolib SHARED IMPORTED )

set_target_properties( bolib PROPERTIES IMPORTED_LOCATION /Users/oketo/CLionProjects/bolib/cmake-build-debug/libbolib.dylib)

target_link_libraries(
        # Specifies the target library.
        pointers

        # Links the target library
        bolib)



```
