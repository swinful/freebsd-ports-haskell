--- third_party/angle/src/common/system_utils_posix.cpp.orig	2022-03-25 21:59:56 UTC
+++ third_party/angle/src/common/system_utils_posix.cpp
@@ -197,7 +197,9 @@ void *OpenSystemLibraryWithExtensionAndGetError(const 
     int extraFlags = 0;
     if (searchType == SearchType::AlreadyLoaded)
     {
+#if !defined(__OpenBSD__)
         extraFlags = RTLD_NOLOAD;
+#endif
     }
 
     std::string fullPath = directory + libraryName;
