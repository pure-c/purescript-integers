default: main
.PHONY: default

ifndef PUREC_DIR
$(error 'PUREC_DIR not set')
endif

export PATH := $(PUREC_DIR)/node_modules/.bin:$(PATH)
include $(PUREC_DIR)/mk/target.mk

SHELL := /bin/bash
srcs := src test
deps := bower_components/purescript-*/src
$(eval $(call purs_mk_target,main,Test.Main,$(srcs),$(deps)))
