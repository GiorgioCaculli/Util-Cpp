include $(top_srcdir)/common.mk

AM_LDFLAGS = $(BOOST_LDFLAGS)

noinst_LIBRARIES = libutil_serialize.a

libutil_serialize_a_SOURCES = Serialize.cpp

libutil_serialize_a_CPPFLAGS = $(BOOST_CPPFLAGS)
libutil_serialize_a_CPPFLAGS += -DBOOST_ALL_NO_LIB
libutil_serialize_a_CPPFLAGS += -DBOOST_ALL_DYN_LINK
libutil_serialize_a_CPPFLAGS += -DBOOST_LOG_DYN_LINK
