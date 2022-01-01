include $(top_srcdir)/common.mk

ACLOCAL_AMFLAGS = -I m4 --install

EXTRA_DIST = $(top_srcdir)/include

SUBDIRS = src

noinst_PROGRAMS = util

util_SOURCES = src/main.cpp

loggerincludedir = $(includedir)/gzc/logger
loggerinclude_HEADERS = include/gzc/logger/Logger.hpp
serializeincludedir = $(includedir)/gzc/serialize
serializeinclude_HEADERS = include/gzc/serialize/Serialize.hpp

util_CPPFLAGS = $(BOOST_CPPFLAGS)

util_LDADD = src/util/logger/gzc/logger/libutil_logger.la
util_LDADD += src/util/serialize/gzc/serialize/libutil_serialize.la
util_LDADD += $(BOOST_LDFLAGS)
util_LDADD += $(BOOST_DATE_TIME_LIB)
util_LDADD += $(BOOST_FILESYSTEM_LIB)
util_LDADD += $(BOOST_LOCALE_LIB)
util_LDADD += $(BOOST_LOG_LIB)
util_LDADD += $(BOOST_LOG_SETUP_LIB)
util_LDADD += $(BOOST_SYSTEM_LIB)
util_LDADD += $(BOOST_THREAD_LIB)
