include $(top_srcdir)/common.mk

lib_LTLIBRARIES = gzc/logger/libutil_logger.la

gzc_logger_libutil_logger_la_SOURCES = Logger.cpp

gzc_logger_libutil_logger_la_CPPFLAGS = $(BOOST_CPPFLAGS)
gzc_logger_libutil_logger_la_CPPFLAGS += -DBOOST_ALL_NO_LIB
gzc_logger_libutil_logger_la_CPPFLAGS += -DBOOST_ALL_DYN_LINK
gzc_logger_libutil_logger_la_CPPFLAGS += -DBOOST_LOG_DYN_LINK

gzc_logger_libutil_logger_la_LDFLAGS = -version-info 1:1:0
