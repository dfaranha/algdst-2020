// Example of an Employee class
class Employee {
  public:
	const string& getName() const {
		return name;
	}

	bool operator==(const Employee & rhs) const {
		return getName() == rhs.getName();
	}

	bool operator!=(const Employee & rhs) const {
		return !(*this == rhs);
	}
 	// Additional public members not shown private:

  private:
	  string name;
	  double salary;
	  int seniority;
	  // Additional private members not shown
};

namespace std {
	template <>
	class hash<Employee> {
	  public:
		size_t operator()(const Employee& item) {
			static hash<string> hf;
			return hf(item.getName());
		}
	};
}
