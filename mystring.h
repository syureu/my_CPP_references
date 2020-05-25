#include<vector>
#include<string>

std::string _trim(std::string str) {
	int st_cut = 0, ed_cut = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
			st_cut = i;
			break;
		}
	}
	for (int i = str.size() - 1; i >= st_cut; --i) {
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
			ed_cut = i;
			break;
		}
	}
	ed_cut -= st_cut - 1;
	return str.substr(st_cut, ed_cut);
}

std::vector<std::string> _split_o(std::string str, std::string splitter) {
	std::vector<std::string> ret;
	int sub_st = 0, sub_ed = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == splitter[0]) {
			bool is_split = 1;
			for (int j = 0; j < splitter.size(); ++j) {
				if (str[i + j] != splitter[j]) {
					is_split = 0;
					break;
				}
			}
			if (is_split) {
				if (sub_ed > 0) {
					ret.push_back(str.substr(sub_st, sub_ed));
				}
				sub_st = i + splitter.size();
				i += splitter.size() - 1;
				sub_ed = 0;
				continue;
			}
		}
		sub_ed++;
	}
	if (sub_ed) {
		ret.push_back(str.substr(sub_st, sub_ed));
	}
	return ret;
}

std::vector<std::string> _split(std::string str, std::string splitter) {
	std::vector<std::string> ret;
	int sub_st = 0, sub_ed = 0;
	for (int i = 0; i < str.size(); ++i) {
		bool is_split = 0;
		for (int j = 0; j < splitter.size(); ++j) {
			if (str[i] == splitter[j]) {
				is_split = 1;
				break;
			}
		}
		if (is_split) {
			if (sub_ed > 0) ret.push_back(str.substr(sub_st, sub_ed));
			sub_st + i + 1;
			sub_ed = 0;
		}
		else {
			sub_ed++;
		}
	}
	if (sub_ed) {
		ret.push_back(str.substr(sub_st, sub_ed));
	}
	return ret;
}

std::vector<std::string> _split(std::string str) {
	return _split(str, " ");
}