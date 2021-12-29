include $(top_srcdir)/common.mk

AM_LDFLAGS = $(BOOST_LDFLAGS)

noinst_LIBRARIES = libutil_logger.a

libutil_logger_a_SOURCES = Logger.cpp

libutil_logger_a_CPPFLAGS = $(BOOST_CPPFLAGS)
libutil_logger_a_CPPFLAGS += -DBOOST_ALL_NO_LIB
libutil_logger_a_CPPFLAGS += -DBOOST_ALL_DYN_LINK
libutil_logger_a_CPPFLAGS += -DBOOST_LOG_DYN_LINK
