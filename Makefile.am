include $(top_srcdir)/common.mk

ACLOCAL_AMFLAGS = -I m4 --install

SUBDIRS = src

bin_PROGRAMS = util

util_SOURCES = src/main.cpp

util_CPPFLAGS = $(BOOST_CPPFLAGS)

util_LDADD = src/util/logger/libutil_logger.a
util_LDADD += src/util/serialize/libutil_serialize.a
util_LDADD += $(BOOST_LDFLAGS)
util_LDADD += $(BOOST_DATE_TIME_LIB)
util_LDADD += $(BOOST_FILESYSTEM_LIB)
util_LDADD += $(BOOST_LOCALE_LIB)
util_LDADD += $(BOOST_LOG_LIB)
util_LDADD += $(BOOST_LOG_SETUP_LIB)
util_LDADD += $(BOOST_SYSTEM_LIB)
util_LDADD += $(BOOST_THREAD_LIB)
