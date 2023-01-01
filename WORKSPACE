# load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
#
# http_archive(
#	name = "com_google_googletest",
#  	urls = ["https://github.com/google/googletest/archive/5ab508a01f9eb089207ee87fd547d290da39d015.zip"],
#  	strip_prefix = "googletest-5ab508a01f9eb089207ee87fd547d290da39d015",
#)

#local_repository (
#	name = "googletest",
#	path = "/home/amisra/Repositories/googletest",
#)

# https://stackoverflow.com/questions/45814669/c-project-with-bazel-and-gtest
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
	name = "googletest",
	remote = "https://github.com/google/googletest",
	branch = "v1.12.0",
)


local_repository (
	name = "abseil-cpp",
	path = "/home/amisra/Repositories/abseil-cpp",
)


