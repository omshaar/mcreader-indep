# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := MCRindep
LOCAL_SRC_FILES := MCRindep.cpp DisplayMatcher.cpp generic.c heap.c host.c Image.cpp imop.c kdtree.c mathop_sse2.c mathop.c random.c sift.c siftmatcher.cpp 

LOCAL_CPPFLAGS += -fexceptions

include $(BUILD_SHARED_LIBRARY)
