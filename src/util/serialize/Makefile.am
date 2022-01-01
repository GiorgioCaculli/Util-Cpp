include $(top_srcdir)/common.mk

lib_LTLIBRARIES = gzc/serialize/libutil_serialize.la

gzc_serialize_libutil_serialize_la_SOURCES = Serialize.cpp

gzc_serialize_libutil_serialize_la_CPPFLAGS = $(BOOST_CPPFLAGS)
gzc_serialize_libutil_serialize_la_CPPFLAGS += -DBOOST_ALL_NO_LIB
gzc_serialize_libutil_serialize_la_CPPFLAGS += -DBOOST_ALL_DYN_LINK
gzc_serialize_libutil_serialize_la_CPPFLAGS += -DBOOST_LOG_DYN_LINK

gzc_serialize_libutil_serialize_la_LDFLAGS = -version-info 1:1:0
