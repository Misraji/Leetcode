cc_library (
	name = "leetcode",
	hdrs = [
		"02488-remove-nodes.h",
		"02491-equal-skill.h",
		"02517-candy-basket.h",
		"00033-search-rotated-array.h",
	],
	srcs = [
		"02488-remove-nodes.cpp",
		"02491-equal-skill.cpp",
		"02517-candy-basket.cpp",
		"00033-search-rotated-array.cpp",
	],
	],
)

cc_test (
	name = "all_tests",
	srcs = [
		"02488-remove-nodes_test.cpp",
		"02491-equal-skill_test.cpp",
		"02517-candy-basket_test.cpp",
		"00033-search-rotated-array_test.cpp",
	],
	],
	deps = [
		":leetcode",
		"@googletest//:gtest_main",
	]
)

cc_test (
	name = "current_test",
	srcs = [
		"02517-candy-basket_test.cpp",
	],
	deps = [
		":leetcode",
		"@googletest//:gtest_main",
	]
)

