#include "02491-equal-skill.h"

#include <iostream>
#include <unordered_map>

long long Solution::dividePlayers(std::vector<int> skills) {
	std::unordered_multimap<int, int> skill_map;
	long long total_skill = 0;
	size_t index = 0;
	for (const auto skill: skills) {
		skill_map.emplace(skill, index++);
		total_skill += skill;
	}

	const long long N = skills.size()/2;
	if (total_skill % N != 0) {
		return -1;
	}

	const long long team_skill = total_skill/N;
	long long chemistry = 0;

	static constexpr int kInvalid = -1;
	size_t i = 0;
	for (i = 0; i < skills.size(); ++i) {
		const int skill = skills[i];
		if (skill != kInvalid) {
			const int partner_skill = team_skill - skill;
			auto itr = skill_map.find(partner_skill);
			if (itr == skill_map.end()) {
				break;
			}
			chemistry += (skill * partner_skill);
			std::cerr << "{" << skill <<  ", " << partner_skill << "}" << std::endl;

			skills[itr->second] = kInvalid;
			skill_map.erase(itr);
		}	
	}
	return i == skills.size() ? chemistry: -1;
}

