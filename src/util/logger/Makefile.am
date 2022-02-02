include $(top_srcdir)/common.mk

lib_LTLIBRARIES = gzc/util/logger/libutil_logger.la

gzc_util_logger_libutil_logger_la_SOURCES = Logger.cpp

gzc_util_logger_libutil_logger_la_CPPFLAGS = $(BOOST_CPPFLAGS)
gzc_util_logger_libutil_logger_la_CPPFLAGS += -DBOOST_ALL_NO_LIB
gzc_util_logger_libutil_logger_la_CPPFLAGS += -DBOOST_ALL_DYN_LINK
gzc_util_logger_libutil_logger_la_CPPFLAGS += -DBOOST_LOG_DYN_LINK

gzc_util_logger_libutil_logger_la_LDFLAGS = -version-info $(GZC_UTIL_LOGGER_VERSION)
