#include <iostream>
#include <vector>
#include <fstream>

std::vector<int> load(std::istream& input) {

	std::vector<int> v;
	int value;
	while(input >> value)
		v.push_back(value);
	return v;
}

void store(const std::vector<int>& v , std::ostream& output) {

	for (int value : v)
		output << value << " ";

}



std::vector<int> drop_duplicates(const std::vector<int>& v) {

	unsigned n = v.size();

	std::vector<int> result;
	for (int i = 0; i < n; i++) {
		
		bool add = true;
		for (int j = 0; j < i; j++) {
			if (v[i] == v[j]) {
				add = false;
				break;
			}
		}
		if (add)
			result.push_back(v[i]);
	}

	return result;
}

unsigned nduplicates(const std::vector<int>& v) {
	
	auto v_unq = drop_duplicates(v);
	return v.size() - v_unq.size();
}

int main () {
	
	//auto v = load(std::cin);
	std::ifstream input("input.txt");
	auto v = load(input);
	
	std::cout << nduplicates(v) << std::endl;
	v = drop_duplicates(v);

	std::ofstream output("output.txt");
	store(v,output);
	// samom sam dodao prazan komentar u mainu 
	return 0;
}
