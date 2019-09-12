# User-configurable options

SHELL ::= /bin/sh

net-test-WARNINGS ::= -Wchar-subscripts -Wcomment -Wformat=2 -Winit-self -Wimplicit \
-Wignored-qualifiers -Wmain -Wmissing-braces -Wmissing-include-dirs \
-Wparentheses -Wsequence-point -Wreturn-type -Wswitch -Wtrigraphs -Wunused \
-Wuninitialized -Wstrict-aliasing -Warray-bounds -Wfloat-equal -Wundef \
-Wno-endif-labels -Wpointer-arith -Wtype-limits -Wconversion -Wenum-compare \
-Wsign-conversion -Waddress -Wmissing-field-initializers \
-Wvolatile-register-var -Wno-write-strings -Wsign-promo

net-test-CPP ::= clang++
net-test-CFLAGS ::= $(net-test-WARNINGS) -Werror -pipe
net-test-LFLAGS ::=

net-test-header-install-dir ::= /usr/local/include
net-test-binary-install-dir ::= /usr/local/bin
net-test-library-install-dir ::= /usr/local/lib

# Boilerplate that should not be touched

ifndef net-test-base-dir
	net-test-base-dir ::= $(realpath ..)
	net-test-previously-included ::=
else
	net-test-target-prefix ::= net-test-
endif

net-test-src-dir ::= $(net-test-base-dir)/src
net-test-inc-dir ::= $(net-test-base-dir)/inc
net-test-bin-dir ::= $(net-test-base-dir)/bin
net-test-ref-dir ::= $(net-test-base-dir)/ref
net-test-build-dir ::= $(net-test-base-dir)/build

include $(net-test-build-dir)/.makefile-includes

net-test-module-cleans = $(net-test-modules:%=%-clean)
net-test-module-installs = $(net-test-modules:%=%-install)
net-test-module-uninstalls = $(net-test-modules:%=%-uninstall)

.DEFAULT_GOAL := all

.PHONY : all
$(net-test-target-prefix)all : $(net-test-modules)

.PHONY : clean
$(net-test-target-prefix)clean : $(net-test-module-cleans)
	rm -rf $(net-test-inc-dir)/*
	rm -rf $(net-test-bin-dir)/*

.PHONE : install
$(net-test-target-prefix)install : $(net-test-module-installs)

.PHONY : uninstall
$(net-test-target-prefix)uninstall : $(net-test-module-uninstalls)
