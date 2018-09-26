# Makefile
# Copyright 2018 Lukas Friedrichsen, Philipp Stenkamp
# License: Apache License Version 2.0
#
# 2018-04-20
#
# Description: Basic Makefile for building the OPC UA-server

##################
# Configuration: #
##################

# Name of the output directory (relative to the project's path)
BUILD_BASE		= main/build

# Name for the target project
TARGET			= opcua

# Which modules (subdirectories) of the project to include in compiling
MODULES			= main main/utility ../model
EXTRA_INCDIR	= main/utility/include ../model

# Libraries used in this project
BASE_LIBS		= mbedtls mbedx509 mbedcrypto

# Compiler flags to use during compilation of the source files
CFLAGS			= -O2 -Wall -std=c99 -g

# Linker flags used to generate the main object file
LDFLAGS			=

# Select compiler, librarian and linker
CC				:= /usr/bin/gcc
AR				:= /usr/bin/gcc-ar
LD				:= /usr/bin/gcc

##########
# Build: #
##########

SRC_DIR			:= $(MODULES)
BUILD_DIR		:= $(addprefix $(BUILD_BASE)/,$(MODULES))

SRC				:= $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.c))
OBJ				:= $(patsubst %.c,$(BUILD_BASE)/%.o,$(SRC))

INCDIR			:= $(addprefix -I,$(foreach sdir,$(SRC_DIR),$(addsuffix include,$(sdir)/)))
EXTRA_INCDIR	:= $(addprefix -I,$(EXTRA_INCDIR))

BASE_LIBS		:= $(addprefix -l,$(BASE_LIBS))

APP_AR			:= $(addprefix $(BUILD_BASE)/,$(TARGET).a)
TARGET_OUT		:= $(addprefix $(BUILD_BASE)/,$(TARGET).out)

V ?= $(VERBOSE)
ifeq ("$(V)","1")
Q :=
vecho := @true
else
Q := @
vecho := @echo
endif

vpath %.c $(SRC_DIR)

define compile-objects
$1/%.o: %.c
	$(vecho) "CC $$<"
	$(Q) $(CC) $(INCDIR) $(EXTRA_INCDIR) $(CFLAGS) -c $$< -o $$@
endef

.PHONY: all checkdirs clean

all: checkdirs $(TARGET_OUT)

$(TARGET_OUT): $(APP_AR)
	$(vecho) "LD $@"
	$(Q) $(LD) $(LDFLAGS) -Wl,--start-group  $(APP_AR) $(BASE_LIBS) -Wl,--end-group -o $@

$(APP_AR): $(OBJ)
	$(vecho) "AR $@"
	$(Q) $(AR) crD $@ $^

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	$(Q) mkdir -p $@

clean:
	$(Q) rm -rf $(BUILD_BASE)

$(foreach bdir,$(BUILD_DIR),$(eval $(call compile-objects,$(bdir))))
