cc_library (
	name = "leetcode",
	hdrs = [
		"02488-remove-nodes.h",
	],
	srcs = [
		"02488-remove-nodes.cpp",
	],
)

cc_test (
	name = "all_tests",
	srcs = [
		"02488-remove-nodes_test.cpp",
	],
	deps = [
		":leetcode",
		"@googletest//:gtest_main",
	]
)

cc_test (
	name = "current_test",
	srcs = [
		"02488-remove-nodes_test.cpp",
	],
	deps = [
		":leetcode",
		"@googletest//:gtest_main",
	]
)

