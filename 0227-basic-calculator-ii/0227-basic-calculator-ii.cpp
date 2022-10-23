class Solution {
public:
    int calculate(string s) {
	list<string> l;
	string x;
	for (char c : s){
		if ( !x.empty() && (c == ' ' || ( isalnum(x[0]) && !isalnum(c) ) || (!isalnum(x[0]) && isalnum(c)) ) ){
			l.push_back(x);
			x.clear();
			if (c != ' ') x.push_back(c);
		}
		else if (c != ' ') x.push_back(c);
	}

	if (!x.empty()) l.push_back(x);

	auto it = l.begin();
	int a, b;
	while (it != l.end()){
		if (*it == "*" || *it == "/"){
			--it;
			a = std::stoi(*it);
			it = l.erase(it);
			it++;
			b = std::stoi(*it);
			it = l.erase(it);
			it--;
			if (*it == "*")(*it) = std::to_string(a * b);
			else (*it) = std::to_string(a / b);
		}
		++it;
	}

	it = l.begin();
	while (it != l.end()){
		if (*it == "+" || *it == "-"){
			--it;
			a = std::stoi(*it);
			it = l.erase(it);
			it++;
			b = std::stoi(*it);
			it = l.erase(it);
			it--;
			if (*it == "+")(*it) = std::to_string(a + b);
			else (*it) = std::to_string(a - b);
		}
		++it;
	}

	return std::stoi(l.front());
}
};