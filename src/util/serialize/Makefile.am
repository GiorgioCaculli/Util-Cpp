include $(top_srcdir)/common.mk

lib_LTLIBRARIES = gzc/util/serialize/libutil_serialize.la

gzc_util_serialize_libutil_serialize_la_SOURCES = Serialize.cpp

gzc_util_serialize_libutil_serialize_la_CPPFLAGS = $(BOOST_CPPFLAGS)
gzc_util_serialize_libutil_serialize_la_CPPFLAGS += -DBOOST_ALL_NO_LIB
gzc_util_serialize_libutil_serialize_la_CPPFLAGS += -DBOOST_ALL_DYN_LINK
gzc_util_serialize_libutil_serialize_la_CPPFLAGS += -DBOOST_LOG_DYN_LINK

gzc_util_serialize_libutil_serialize_la_LDFLAGS = -version-info $(GZC_UTIL_SERIALIZE_VERSION)
